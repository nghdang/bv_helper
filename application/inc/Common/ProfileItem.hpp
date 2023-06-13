#pragma once

#include <QSharedPointer>
#include <QString>

#include "Common/ProfileCategoryListModel.hpp"

namespace Common {

struct ProfileItem
{
    QString category;

    QSharedPointer<Common::ProfileCategoryListModel> categoryListModel;
};

} // namespace Common
