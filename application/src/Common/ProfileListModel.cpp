#include "Application/Common/ProfileListModel.hpp"

namespace Application {
namespace Common {

ProfileListModel::ProfileListModel(QObject* parent)
    : QAbstractListModel(parent)
{
}

int ProfileListModel::rowCount(const QModelIndex& parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
    return m_profileItems.size();
}

QVariant ProfileListModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
        return QVariant();

    auto item = m_profileItems.at(index.row());
    switch (role)
    {
        case CategoryRole:
            return QVariant::fromValue(item.category);
        case CategoryListModelRole:
            return QVariant::fromValue(item.categoryListModel);
        default:
            break;
    }

    // FIXME: Implement me!
    return QVariant();
}

QHash<int, QByteArray> ProfileListModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[CategoryRole] = "category";
    roles[CategoryListModelRole] = "categoryListModel";

    return roles;
}

QVector<ProfileItem> ProfileListModel::getProfileItems() const
{
    return m_profileItems;
}

void ProfileListModel::setProfileItems(const QVector<ProfileItem>& profileItems)
{
    beginResetModel();
    m_profileItems = profileItems;
    endResetModel();
}

} // namespace Common
} // namespace Application
