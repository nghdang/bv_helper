#pragma once

#include <QSharedPointer>
#include <QString>

#include "Application/Gui/Common/ProfileCategoryListModel.hpp"

namespace Application {
namespace Gui {
namespace Common {

struct ProfileItem
{
    QString category;

    QSharedPointer<Common::ProfileCategoryListModel> categoryListModel;
};

} // namespace Common
} // namespace Gui
} // namespace Application
