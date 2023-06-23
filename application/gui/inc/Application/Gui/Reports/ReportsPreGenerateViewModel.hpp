#pragma once

#include "Application/Gui/Common/BaseViewModel.hpp"

namespace Application {
namespace Gui {
namespace Reports {

class ReportsPreGenerateViewModel : public Common::BaseViewModel
{
    Q_OBJECT

public:
    explicit ReportsPreGenerateViewModel(
      const std::shared_ptr<Common::BaseViewModelDependencies>& baseViewModelDependencies, QObject* parent = nullptr);
};

} // namespace Reports
} // namespace Gui
} // namespace Application
