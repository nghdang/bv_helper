#pragma once

#include <QObject>
#include "Common/ProfileListModel.hpp"

namespace UserProfile {

class UserProfileViewModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString headerText READ getHeaderText CONSTANT)

    Q_PROPERTY(QSharedPointer<Common::ProfileListModel> profileListModel READ getProfileListModel NOTIFY profileListModelChanged)

public:
    explicit UserProfileViewModel(QObject* parent = nullptr);

    QString getHeaderText() const;
    QSharedPointer<Common::ProfileListModel> getProfileListModel() const;

signals:
    void profileListModelChanged();

protected:
    QSharedPointer<Common::ProfileListModel> m_profileListModel;
};

} // namespace UserProfile
Q_DECLARE_METATYPE(UserProfile::UserProfileViewModel*)
