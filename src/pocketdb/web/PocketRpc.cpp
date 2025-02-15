// Copyright (c) 2018-2022 The Pocketnet developers
// Distributed under the Apache 2.0 software license, see the accompanying
// https://www.apache.org/licenses/LICENSE-2.0

#include "pocketdb/web/PocketRpc.h"
#include "rpc/util.h"

RPCHelpMan gettemplate()
{
    return RPCHelpMan{
            // TODO (team): update name and all description
            "getrawtransactionwithmessagebyid",
            "\nReturn Pocketnet posts.\n",
            {

            },
            {

            },
            RPCExamples{
                ""
            },
    [&](const RPCHelpMan& self, const JSONRPCRequest& request) -> UniValue
{
    UniValue aResult(UniValue::VARR);
    return aResult;
},
    };
}

// @formatter:off
static const CRPCCommand commands[] =
{
    // Old methods
    {"artifacts", "getrecommendedposts",              &gettemplate,                       {"address", "count", "height", "lang", "contenttypes"}},
    {"artifacts", "getusercontents",                  &gettemplate,                       {"address", "height", "start_txid", "count", "lang", "tags", "contenttypes"}},
    {"artifacts", "getrecomendedsubscriptionsforuser",&gettemplate,                       {"address", "count"}},

    {"hidden",       "generatepocketnettransaction",        &GenerateTransaction,           {"address", "privkeys", "outcount", "type", "payload", "fee", "contentaddress", "confirmations"}},
    {"hidden",       "generatetransaction",                 &GenerateTransaction,           {"address", "privkeys", "outcount", "type", "payload", "fee", "contentaddress", "confirmations"}},
    {"hidden",       "generateaddress",                     &GenerateAddress,               {}},

    // Search
    {"search",          "search",                           &Search,                        {"keyword", "type", "topBlock", "pageStart", "pageSize", "address"}},
    {"search",          "searchlinks",                      &SearchLinks,                   {"links", "contenttypes", "height", "count"}},
    {"search",          "searchusers",                      &SearchUsers,                   {"keyword", "fieldtypes", "orderbyrank"}},

    // Recomendations
    {"search",          "getrecommendedcontentbyaddress",   &GetRecommendedContentByAddress,   {"address", "addressExclude", "contenttypes", "lang", "countRec", "countOthers", "countSubs"}},
    {"search",          "getrecommendedaccountbyaddress",   &GetRecommendedAccountByAddress,   {"address", "addressExclude", "contenttypes", "lang", "count"}},

    // WebSocket
    {"websocket",       "getmissedinfo",                    &GetMissedInfo,                 {"address", "blocknumber"}},

    // Contents
    {"contents",        "gethotposts",                      &GetHotPosts,                   {"count", "depth", "height", "lang", "contenttypes", "address"}},
    {"contents",        "gethistoricalfeed",                &GetHistoricalFeed,             {"topHeight","topContentHash","countOut","lang","tags","contentTypes","txIdsExcluded","adrsExcluded","tagsExcluded","address"}},
    {"contents",        "gethistoricalstrip",               &GetHistoricalFeed,             {"topHeight","topContentHash","countOut","lang","tags","contentTypes","txIdsExcluded","adrsExcluded","tagsExcluded","address"}},
    {"contents",        "gethierarchicalfeed",              &GetHierarchicalFeed,           {"topHeight","topContentHash","countOut","lang","tags","contentTypes","txIdsExcluded","adrsExcluded","tagsExcluded","address"}},
    {"contents",        "gethierarchicalstrip",             &GetHierarchicalFeed,           {"topHeight","topContentHash","countOut","lang","tags","contentTypes","txIdsExcluded","adrsExcluded","tagsExcluded","address"}},
    {"contents",        "getboostfeed",                     &GetBoostFeed,                  {"topHeight","topContentHash","countOut","lang","tags","contentTypes","txIdsExcluded","adrsExcluded","tagsExcluded","address"}},
    {"contents",        "gettopfeed",                       &GetTopFeed,                    {"topHeight","topContentHash","countOut","lang","tags","contentTypes","txIdsExcluded","adrsExcluded","tagsExcluded","address","depth"}},
    {"contents",        "getmostcommentedfeed",             &GetMostCommentedFeed,          {"topHeight","topContentHash","countOut","lang","tags","contentTypes","txIdsExcluded","adrsExcluded","tagsExcluded","address","depth"}},
    {"contents",        "getprofilefeed",                   &GetProfileFeed,                {"topHeight","topContentHash","countOut","lang","tags","contentTypes","txIdsExcluded","adrsExcluded","tagsExcluded","address","address_feed", "keyword"}},
    {"contents",        "getprofilecollections",            &GetProfileCollections,         {"topHeight","topContentHash","countOut","lang","tags","contentTypes","txIdsExcluded","adrsExcluded","tagsExcluded","address","address_feed", "keyword"}},
    {"contents",        "getsubscribesfeed",                &GetSubscribesFeed,             {"topHeight","topContentHash","countOut","lang","tags","contentTypes","txIdsExcluded","adrsExcluded","tagsExcluded","address","address_feed"}},
    {"contents",        "getrawtransactionwithmessagebyid", &GetContent,                    {"ids", "address"}},
    {"contents",        "getcontent",                       &GetContent,                    {"ids", "address"}},
    {"contents",        "getcontentsstatistic",             &GetContentsStatistic,          {"addresses", "contentTypes", "height", "depth"}},
    {"contents",        "getcontents",                      &GetContents,                   {"address"}},
    {"contents",        "getrandomcontents",                &GetRandomContents,             {}},
    {"contents",        "getcontentactions",                &GetContentActions,             {"contentHash"}},
    {"contents",        "getevents",                        &GetEvents,                     {"address", "height", "blockNum", "filters"}},
    {"contents",        "getactivities",                    &GetActivities,                 {"address", "height", "blockNum", "filters"}},
    {"contents",        "getnotifications",                 &GetNotifications,              {"height", "filters"}},
    {"contents",        "getnotificationssummary",          &GetNotificationsSummary,       {"addresses", "height", "filters"}},
    {"contents",        "getsubsciptionsgroupedbyauthors",  &GetsubsciptionsGroupedByAuthors, {"address", "addressPagination", "nHeight", "countOutOfUsers", "countOutOfcontents"}},

    // Tags
//    {"artifacts", "searchtags",                       &gettemplate,                       {"search_string", "count"}},
    {"tags",           "gettags",                          &GetTags,                        {"address", "count", "height", "lang"}},

    // Comments
    {"comments",        "getcomments",                      &GetCommentsByPost,             {"postid", "parentid", "address", "ids"}},
    {"comments",        "getlastcomments",                  &GetLastComments,               {"count", "address"}},

    // Accounts
    {"accounts",        "getuserprofile",                   &GetAccountProfiles,             {"addresses", "short"}},
    {"accounts",        "getuseraddress",                   &GetAccountAddress,              {"name"}},
    {"accounts",        "getaddressregistration",           &GetAccountRegistration,         {"addresses"}},
    {"accounts",        "getuserstate",                     &GetAccountState,                {"address"}},
    {"accounts",        "txunspent",                        &GetAccountUnspents,             {"addresses", "minconf", "maxconf", "include_unsafe", "query_options"}},
    {"accounts",        "getaddressid",                     &GetAccountId,                   {"address_or_id"}},
    {"accounts",        "getaccountsetting",                &GetAccountSetting,              {"address"}},
    {"accounts",        "getuserstatistic",                 &GetAccountStatistic,            {"address", "height", "depth"}},
    {"accounts",        "getusersubscribes",                &GetAccountSubscribes,           {"address", "types", "orderby", "orderdesc", "offset", "limit"}},
    {"accounts",        "getusersubscribers",               &GetAccountSubscribers,          {"address", "types", "orderby", "orderdesc", "offset", "limit"}},
    {"accounts",        "getuserblockings",                 &GetAccountBlockings,            {"address"}},
    {"accounts",        "getuserblockers",                  &GetAccountBlockers,             {"address"}},
    {"accounts",        "gettopaccounts",                   &GetTopAccounts,                 {"topHeight","countOut","lang","tags","contentTypes","adrsExcluded","tagsExcluded","depth"}},

    // Scores
    {"scores",          "getaddressscores",                 &GetAddressScores,              {"address", "txs"}},
    {"scores",          "getpostscores",                    &GetPostScores,                 {"txHash"}},
    {"scores",          "getpagescores",                    &GetPagesScores,                {"postIds", "address", "cmntIds"}},
    {"scores",          "getaccountraters",                 &GetAccountRaters,              {"address"}},

    // Explorer
    {"explorer",       "getstatistictransactions",         &GetStatisticTransactions,       {"topTime", "depth", "period"}},
    {"explorer",       "getstatisticbyhours",              &GetStatisticByHours,            {"topHeight", "depth"}},
    {"explorer",       "getstatisticbydays",               &GetStatisticByDays,             {"topHeight", "depth"}},
    {"explorer",       "getstatisticcontentbyhours",       &GetStatisticContentByHours,     {"topHeight", "depth"}},
    {"explorer",       "getstatisticcontentbydays",        &GetStatisticContentByDays,      {"topHeight", "depth"}},
    {"explorer",       "getaddressinfo",                   &GetAddressInfo,                 {"address"}},
    {"explorer",       "getcompactblock",                  &GetCompactBlock,                {"blockHash"}},
    {"explorer",       "getlastblocks",                    &GetLastBlocks,                  {"count", "lastHeight", "verbose"}},
    {"explorer",       "searchbyhash",                     &SearchByHash,                   {"value"}},
    {"explorer",       "gettransactions",                  &GetTransactions,                {"transactions"}},
    {"explorer",       "getaddresstransactions",           &GetAddressTransactions,         {"address", "pageStart", "pageSize"}},
    {"explorer",       "getblocktransactions",             &GetBlockTransactions,           {"blockHash", "pageStart", "pageSize"}},
    {"explorer",       "getbalancehistory",                &GetBalanceHistory,              {"address", "topHeight", "count"}},

    // System
    {"system",         "getpeerinfo",                      &GetPeerInfo,                    {}},
    {"system",         "getnodeinfo",                      &GetNodeInfo,                    {}},
    {"system",         "gettime",                          &GetTime,                        {}},
    {"system",         "getcoininfo",                      &GetCoinInfo,                    {"height"}},

    // Transactions
    {"transaction",    "getrawtransaction",                &GetTransaction,                 {"transactions"}},
    {"transaction",    "estimatesmartfee",                 &EstimateSmartFee,               {"conf_target", "estimate_mode"} },

    // Moderation
    {"moderation",     "getalljury",                       &GetAllJury,                     {}},
    {"moderation",     "getjury",                          &GetJury,                        {"juryid"}},
    {"moderation",     "getjuryassigned",                  &GetJuryAssigned,                {"address", "topHeight", "pageStart", "pageSize", "orderBy", "desc"}},
    {"moderation",     "getjurymoderators",                &GetJuryModerators,              {"juryid"}},
    {"moderation",     "getbans",                          &GetBans,                        {"address"}},
    
    
};
// @formatter:on

// @formatter:off
static const CRPCCommand commands_post[] =
{
    {"transaction",    "sendrawtransactionwithmessage",    &AddTransaction,                 {"hexstring", "message"}},
    {"transaction",    "addtransaction",                   &AddTransaction,                 {"hexstring", "message"}},
    {"transaction",    "sendrawtransaction",               &AddTransaction,                 {"hexstring", "message"}},
};
// @formatter:on

void RegisterPocketnetWebRPCCommands(CRPCTable &tableRPC, CRPCTable &tablePostRPC)
{
    for (const auto& command : commands)
        tableRPC.appendCommand(command.name, &command);

    for (const auto& command : commands_post)
        tablePostRPC.appendCommand(command.name, &command);
}
