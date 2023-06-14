#include "Application/Common/BaseViewModelDependencies.hpp"

namespace Application {
namespace Common {

BaseViewModelDependencies::BaseViewModelDependencies(const std::shared_ptr<ViewManagement::ViewManager>& viewManager)
    : viewManager(viewManager)
{
    headerBarModel = std::make_shared<HeaderBarModel>();
}

} // namespace Common
} // namespace Application
