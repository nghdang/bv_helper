#pragma once

#include <QSharedPointer>
#include <QString>

#include "Application/Common/ProfileCategoryListModel.hpp"

namespace Common {

struct ProfileItem
{
    QString category;

    QSharedPointer<Common::ProfileCategoryListModel> categoryListModel;
};

} // namespace Common
