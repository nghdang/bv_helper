#pragma once

#include <QAbstractListModel>
#include <QVector>
#include "Application/Common/ProfileCategory.hpp"

namespace Common {

class ProfileCategoryListModel : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(QVector<Common::ProfileCategory> profileCategories READ getProfileCategories WRITE setProfileCategories NOTIFY profileCategoriesChanged)

public:
    enum
    {
        KeyRole,
        ValueRole
    };
    explicit ProfileCategoryListModel(QObject* parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    QHash<int, QByteArray> roleNames() const override;

    // Editable:
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    QVector<Common::ProfileCategory> getProfileCategories() const;
    void setProfileCategories(const QVector<Common::ProfileCategory>& profileCategories);

signals:
    void profileCategoriesChanged();

protected:
    QVector<Common::ProfileCategory> m_profileCategories;
};

} // namespace Common
