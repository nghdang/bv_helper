#include "Application/Common/BaseViewModelDependencies.hpp"

#include "Application/Core/HeaderBarModel.hpp"

namespace Application {
namespace Common {

BaseViewModelDependencies::BaseViewModelDependencies(const std::shared_ptr<ViewManagement::ViewManager>& viewManager,
                                                     const std::shared_ptr<Services::SettingsManager>& settingsManager)
    : viewManager{viewManager}
    , settingsManager{settingsManager}
{
    headerBarModel = std::make_shared<HeaderBarModel>();
}

} // namespace Common
} // namespace Application
