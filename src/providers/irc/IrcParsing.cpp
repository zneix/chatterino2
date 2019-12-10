#include "providers/irc/IrcParsing.hpp"

namespace chatterino {

QStringList parseTagList(const QVariantMap &tags, const QString &key)
{
    auto iterator = tags.find(key);
    if (iterator == tags.end())
        return QStringList{};

    return iterator.value().toString().split(
        ',', QString::SplitBehavior::SkipEmptyParts);
}

}  // namespace chatterino
