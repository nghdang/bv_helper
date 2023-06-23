#pragma once

#include <QObject>
#include <memory>
#include "Application/Gui/Core/HeaderBarModel.hpp"
#include "Framework/ViewManagement/ViewModel.hpp"

static auto FSM_EVENT_ENTER_SETTINGS = QStringLiteral("evEnterSettings");
static auto FSM_EVENT_ENTER_MAIN = QStringLiteral("evEnterMain");
static auto FSM_EVENT_ENTER_NEXT = QStringLiteral("evNext");
static auto FSM_EVENT_ENTER_BACK = QStringLiteral("evBack");

namespace Application {
namespace Gui {
namespace Common {
class BaseViewModelDependencies;
} // namespace Common
} // namespace Gui
} // namespace Application

namespace Application {
namespace Gui {
namespace ViewManagement {
class ViewManager;
} // namespace ViewManagement
} // namespace Gui
} // namespace Application

namespace Application {
namespace Domain {
namespace SettingsManagement {
class SettingsManager;
} // namespace SettingsManagement
} // namespace Domain
} // namespace Application

namespace Application {
namespace Gui {
namespace Common {

class BaseViewModel : public Framework::ViewManagement::ViewModel
{
    Q_OBJECT

    Q_PROPERTY(HeaderBarModel* headerBarModel READ getHeaderBarModel NOTIFY headerBarModelChanged)

public:
    explicit BaseViewModel(const std::shared_ptr<Common::BaseViewModelDependencies>& baseViewModelDependencies,
                           QObject* parent = nullptr);

    void submitFsmEvent(const QString& fsmEvent);

    HeaderBarModel* getHeaderBarModel() const;

signals:
    void headerBarModelChanged();

protected:
    std::shared_ptr<Domain::SettingsManagement::SettingsManager> m_settingsManager;

    std::shared_ptr<ViewManagement::ViewManager> m_viewManager;

    std::shared_ptr<HeaderBarModel> m_headerBarModel;
};

} // namespace Common
} // namespace Gui
} // namespace Application
