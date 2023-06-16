#pragma once

#include <QObject>
#include "Application/Common/BaseViewModel.hpp"
#include "Application/Common/ProfileListModel.hpp"

namespace Application {
namespace TeamProfile {

class TeamProfileViewModel : public Common::BaseViewModel
{
    Q_OBJECT

    Q_PROPERTY(QString headerText READ getHeaderText CONSTANT)

    Q_PROPERTY(QSharedPointer<Common::ProfileListModel> profileListModel READ getProfileListModel NOTIFY profileListModelChanged)

public:
    TeamProfileViewModel(const std::shared_ptr<Common::BaseViewModelDependencies>& baseViewModelDependencies, QObject* parent = nullptr);
    virtual ~TeamProfileViewModel();

    void activated() override;
    void activating() override;
    void deactivated() override;
    void deactivating() override;

    QString getHeaderText() const;
    QSharedPointer<Common::ProfileListModel> getProfileListModel() const;

signals:
    void profileListModelChanged();

public slots:
    void enterBack();
    void enterGitHubActivities();

protected:
    QSharedPointer<Common::ProfileListModel> m_profileListModel;
};

} // namespace TeamProfile
} // namespace Application
Q_DECLARE_METATYPE(Application::TeamProfile::TeamProfileViewModel*)
