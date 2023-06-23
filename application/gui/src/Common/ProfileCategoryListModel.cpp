#include "Application/Gui/Common/ProfileCategoryListModel.hpp"

#include <iostream>

namespace Application {
namespace Gui {
namespace Common {

ProfileCategoryListModel::ProfileCategoryListModel(QObject* parent)
    : QAbstractListModel(parent)
{
}

int ProfileCategoryListModel::rowCount(const QModelIndex& parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
    return m_profileCategories.size();
}

QVariant ProfileCategoryListModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
        return QVariant();

    auto item = m_profileCategories.at(index.row());
    switch (role)
    {
        case KeyRole:
            return QVariant(item.key);
        case ValueRole:
            return QVariant(item.value);
        default:
            break;
    }

    // FIXME: Implement me!
    return QVariant();
}

QHash<int, QByteArray> ProfileCategoryListModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[KeyRole] = "key";
    roles[ValueRole] = "value";

    return roles;
}

bool ProfileCategoryListModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if (data(index, role) != value)
    {
        // FIXME: Implement me!
        auto& item = m_profileCategories[index.row()];
        switch (role)
        {
            case KeyRole:
                break;
            case ValueRole:
                item.value = value.toString();
            default:
                break;
        }
        emit dataChanged(index, index, {role});
        return true;
    }
    return false;
}

Qt::ItemFlags ProfileCategoryListModel::flags(const QModelIndex& index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable; // FIXME: Implement me!
}

QVector<ProfileCategory> ProfileCategoryListModel::getProfileCategories() const
{
    return m_profileCategories;
}

void ProfileCategoryListModel::setProfileCategories(const QVector<ProfileCategory>& profileCategories)
{
    beginResetModel();
    m_profileCategories = profileCategories;
    endResetModel();
}

} // namespace Common
} // namespace Gui
} // namespace Application
