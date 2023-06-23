#pragma once

#include "Application/Gui/Common/BaseViewModel.hpp"

namespace Application {
namespace Gui {
namespace Welcome {

class WelcomeViewModel : public Common::BaseViewModel
{
    Q_OBJECT

public:
    explicit WelcomeViewModel(const std::shared_ptr<Common::BaseViewModelDependencies>& baseViewModelDependencies,
                              QObject* parent = nullptr);
};

} // namespace Welcome
} // namespace Gui
} // namespace Application
