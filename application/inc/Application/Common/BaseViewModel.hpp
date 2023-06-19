#pragma once

#include <QObject>
#include <memory>
#include "Application/Core/HeaderBarModel.hpp"
#include "Framework/ViewManagement/ViewModel.hpp"

static auto FSM_EVENT_ENTER_USER_PROFILE = QStringLiteral("evEnterUserProfile");
static auto FSM_EVENT_ENTER_TEAM_PROFILE = QStringLiteral("evEnterTeamProfile");
static auto FSM_EVENT_ENTER_GITHUB_ACTIVITIES = QStringLiteral("evEnterGithubActivities");
static auto FSM_EVENT_ENTER_BACK = QStringLiteral("evEnterBack");

namespace Application {
namespace Common {
class BaseViewModelDependencies;
} // namespace Common
} // namespace Application

namespace Application {
namespace ViewManagement {
class ViewManager;
} // namespace ViewManagement
} // namespace Application

namespace Application {
namespace Services {
class SettingsManager;
} // namespace Services
} // namespace Application

namespace Application {
namespace Common {

class BaseViewModel : public Framework::ViewManagement::ViewModel
{
    Q_OBJECT

    Q_PROPERTY(HeaderBarModel* headerBarModel READ getHeaderBarModel NOTIFY headerBarModelChanged)

public:
    explicit BaseViewModel(const std::shared_ptr<Common::BaseViewModelDependencies>& baseViewModelDependencies, QObject* parent = nullptr);

    void submitFsmEvent(const QString& fsmEvent);

    HeaderBarModel* getHeaderBarModel() const;

signals:
    void headerBarModelChanged();

protected:
    std::shared_ptr<Services::SettingsManager> m_settingsManager;

    std::shared_ptr<ViewManagement::ViewManager> m_viewManager;

    std::shared_ptr<HeaderBarModel> m_headerBarModel;
};

} // namespace Common
} // namespace Application
