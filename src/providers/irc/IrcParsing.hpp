#pragma once

#include <QStringList>
#include <QVariantMap>

namespace chatterino {

QStringList parseTagList(const QVariantMap &tags, const QString &key);

}  // namespace chatterino
