#pragma once

#include "Application/Gui/Common/BaseViewModel.hpp"

namespace Application {
namespace Gui {
namespace Activities {

class ActivitiesJiraViewModel : public Common::BaseViewModel
{
    Q_OBJECT

public:
    explicit ActivitiesJiraViewModel(
      const std::shared_ptr<Common::BaseViewModelDependencies>& baseViewModelDependencies, QObject* parent = nullptr);
};

} // namespace Activities
} // namespace Gui
} // namespace Application
