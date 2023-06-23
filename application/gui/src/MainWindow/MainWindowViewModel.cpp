#include "Application/Gui/MainWindow/MainWindowViewModel.hpp"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTextStream>
#include <iostream>
#include "Application/Domain/SettingsManagement/SettingsManager.hpp"
#include "Application/Gui/Helper/SettingIds.hpp"
#include "Application/Gui/Helper/SharedConstants.hpp"

namespace Application {
namespace Gui {
namespace MainWindow {

MainWindowViewModel::MainWindowViewModel(
  const std::shared_ptr<Common::BaseViewModelDependencies>& baseViewModelDependencies, QObject* parent)
    : Common::BaseViewModel(baseViewModelDependencies, parent)
{
}

bool MainWindowViewModel::isFirstUse() const
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    return not QFile::exists(QString::fromStdString(SharedConstants::SETTINGS_PATH));
}

bool MainWindowViewModel::isLeader() const
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    auto settingValue = m_settingsManager->getValue(SettingIds::SID_USER_PERSONAL_ROLE);
    return settingValue == std::string("Leader");
}

} // namespace MainWindow
} // namespace Gui
} // namespace Application
