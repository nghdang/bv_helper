#pragma once

#include <QObject>
#include "Application/Gui/Common/BaseViewModel.hpp"
#include "Application/Gui/Common/ProfileListModel.hpp"

namespace Application {
namespace Gui {
namespace TeamProfile {

class TeamProfileViewModel : public Common::BaseViewModel
{
    Q_OBJECT

    Q_PROPERTY(
      QSharedPointer<Common::ProfileListModel> profileListModel READ getProfileListModel NOTIFY profileListModelChanged)

public:
    TeamProfileViewModel(const std::shared_ptr<Common::BaseViewModelDependencies>& baseViewModelDependencies,
                         QObject* parent = nullptr);

    void activating() override;
    void activated() override;
    void deactivating() override;
    void deactivated() override;

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
} // namespace Gui
} // namespace Application

Q_DECLARE_METATYPE(Application::Gui::TeamProfile::TeamProfileViewModel*)
