#include "Application/Gui/MainWindow/MainWindowViewModel.hpp"

#include <iostream>

namespace Application {
namespace Gui {
namespace MainWindow {

MainWindowViewModel::MainWindowViewModel(
  const std::shared_ptr<Common::BaseViewModelDependencies>& baseViewModelDependencies, QObject* parent)
    : Common::BaseViewModel(baseViewModelDependencies, parent)
{
}

} // namespace MainWindow
} // namespace Gui
} // namespace Application
