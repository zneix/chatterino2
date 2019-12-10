#include "providers/irc/IrcParsing.hpp"

#include <gtest/gtest.h>
#include <QVariantMap>

namespace {

struct IrcParsingTest {
    // const QString message;
    const QVariantMap tags;

    // expected tag lists
    const std::vector<std::pair<QString, QStringList>> expectedTagLists;
};

std::vector<IrcParsingTest> tests = {
    {{ // @badge-info=founder/47;badges=moderator/1,founder/0,premium/1;color=#00FF80;display-name=gempir;emotes=;flags=;id=d4514490-202e-43cb-b429-ef01a9d9c2fe;mod=1;room-id=11148817;subscriber=0;tmi-sent-ts=1575198233854;turbo=0;user-id=77829817;user-type=mod :gempir!gempir@gempir.tmi.twitch.tv PRIVMSG #pajlada :offline chat gachiBASS
         {"badge-info", "founder/47"},
         {"badges", "moderator/1,founder/0,premium/1"},
         {"color", "#00FF80"},
     },
    {
        {"badge-info", {"founder/47"}},
        {"badges", {"moderator/1", "founder/0", "premium/1"}},
        {"color", {"#00FF80"}},
    }},
};

}

TEST(IrcParsing, parseTagList)
{
    for (const auto &test : tests) {
        foreach (auto pair, test.expectedTagLists) {
            auto resultList = chatterino::parseTagList(test.tags, pair.first);

            EXPECT_EQ(pair.second, resultList);
        }
    }
}
