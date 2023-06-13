#pragma once

#include <QAbstractListModel>
#include <QVector>
#include "Application/Common/ProfileItem.hpp"

namespace Common {

class ProfileListModel : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(QVector<Common::ProfileItem> profileItems READ getProfileItems WRITE setProfileItems NOTIFY profileItemsChanged)

public:
    enum
    {
        CategoryRole,
        CategoryListModelRole
    };

    explicit ProfileListModel(QObject* parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    QHash<int, QByteArray> roleNames() const override;

    QVector<Common::ProfileItem> getProfileItems() const;
    void setProfileItems(const QVector<Common::ProfileItem>& profileItems);

signals:
    void profileItemsChanged();

protected:
    QVector<Common::ProfileItem> m_profileItems;
};

} // namespace Common
