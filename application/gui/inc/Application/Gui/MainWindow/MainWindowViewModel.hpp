#pragma once

#include <QObject>
#include <QVariantMap>
#include "Application/Gui/Common/BaseViewModel.hpp"

namespace Application {
namespace Gui {
namespace MainWindow {

class MainWindowViewModel : public Common::BaseViewModel
{
    Q_OBJECT

public:
    explicit MainWindowViewModel(const std::shared_ptr<Common::BaseViewModelDependencies>& baseViewModelDependencies,
                                 QObject* parent = nullptr);
};

} // namespace MainWindow
} // namespace Gui
} // namespace Application
