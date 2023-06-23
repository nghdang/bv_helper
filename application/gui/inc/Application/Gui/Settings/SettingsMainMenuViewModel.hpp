#pragma once

#include "Application/Gui/Common/BaseViewModel.hpp"

namespace Application {
namespace Gui {

namespace Settings {

class SettingsMainMenuViewModel : public Common::BaseViewModel
{
    Q_OBJECT

public:
    explicit SettingsMainMenuViewModel(
      const std::shared_ptr<Common::BaseViewModelDependencies>& baseViewModelDependencies, QObject* parent = nullptr);
};

} // namespace Settings
} // namespace Gui
} // namespace Application
