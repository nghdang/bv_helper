#pragma once

#include <QObject>
#include <memory>
#include "Application/Appliance/HeaderBarModel.hpp"
#include "Application/Common/BaseViewModelDependencies.hpp"
#include "Framework/ViewManagement/ViewModel.hpp"

static auto FSM_EVENT_ENTER_USER_PROFILE = QStringLiteral("evEnterUserProfile");
static auto FSM_EVENT_ENTER_TEAM_PROFILE = QStringLiteral("evEnterTeamProfile");
static auto FSM_EVENT_ENTER_GITHUB_ACTIVITIES = QStringLiteral("evEnterGithubActivities");
static auto FSM_EVENT_BACK = QStringLiteral("evBack");

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
    std::shared_ptr<ViewManagement::ViewManager> m_viewManager;

    std::shared_ptr<HeaderBarModel> m_headerBarModel;
};

} // namespace Common
} // namespace Application
