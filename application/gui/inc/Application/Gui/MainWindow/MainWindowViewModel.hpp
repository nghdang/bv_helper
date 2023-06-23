#pragma once

#include <QObject>
#include <QVariantMap>
#include "Application/Gui/Common/BaseViewModel.hpp"

namespace Application {
namespace Gui {
namespace Window {

class MainWindowViewModel : public Common::BaseViewModel
{
    Q_OBJECT

public:
    explicit MainWindowViewModel(const std::shared_ptr<Common::BaseViewModelDependencies>& baseViewModelDependencies,
                                 QObject* parent = nullptr);

    Q_INVOKABLE bool isFirstUse() const;

    Q_INVOKABLE bool isLeader() const;

signals:

protected:
};

} // namespace Window
} // namespace Gui
} // namespace Application
