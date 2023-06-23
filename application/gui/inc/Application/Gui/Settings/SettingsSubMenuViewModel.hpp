#pragma once

#include "Application/Gui/Common/BaseViewModel.hpp"

namespace Application {
namespace Gui {
namespace Settings {

class SettingsSubMenuViewModel : public Common::BaseViewModel
{
    Q_OBJECT

public:
    explicit SettingsSubMenuViewModel(
      const std::shared_ptr<Common::BaseViewModelDependencies>& baseViewModelDependencies, QObject* parent = nullptr);
};

} // namespace Settings
} // namespace Gui
} // namespace Application
