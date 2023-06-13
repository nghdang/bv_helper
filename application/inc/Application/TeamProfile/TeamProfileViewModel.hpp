#pragma once

#include <QObject>
#include "Application/Common/ProfileListModel.hpp"

namespace TeamProfile {

class TeamProfileViewModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString headerText READ getHeaderText CONSTANT)

    Q_PROPERTY(QSharedPointer<Common::ProfileListModel> profileListModel READ getProfileListModel NOTIFY profileListModelChanged)

public:
    explicit TeamProfileViewModel(QObject* parent = nullptr);

    QString getHeaderText() const;
    QSharedPointer<Common::ProfileListModel> getProfileListModel() const;

signals:
    void profileListModelChanged();

protected:
    QSharedPointer<Common::ProfileListModel> m_profileListModel;
};

} // namespace TeamProfile
Q_DECLARE_METATYPE(TeamProfile::TeamProfileViewModel*)
