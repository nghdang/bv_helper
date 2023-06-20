#include "Application/MainWindow/MainWindowViewModel.hpp"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTextStream>
#include <iostream>
#include "Application/Helper/SettingIds.hpp"
#include "Application/Helper/SharedConstants.hpp"
#include "Application/SettingsManagement/SettingsManager.hpp"

namespace Application {
namespace Window {

MainWindowViewModel::MainWindowViewModel(const std::shared_ptr<Common::BaseViewModelDependencies>& baseViewModelDependencies, QObject* parent)
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
    auto settingValue = m_settingsManager->getSetting(SettingIds::SID_ROLE);
    return settingValue == std::string("Leader");
}

} // namespace Window
} // namespace Application
