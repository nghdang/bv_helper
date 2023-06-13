#include "Application/Common/BaseViewModelDependencies.hpp"

namespace Application {
namespace Common {

BaseViewModelDependencies::BaseViewModelDependencies()
{
    headerBarModel = std::make_shared<HeaderBarModel>();
}

} // namespace Common
} // namespace Application
