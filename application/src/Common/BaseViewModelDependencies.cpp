#include "Application/Common/BaseViewModelDependencies.hpp"

namespace Common {

BaseViewModelDependencies::BaseViewModelDependencies(const std::shared_ptr<HeaderBarModel>& headerBarModel)
    : headerBarModel{headerBarModel}
{
}

} // namespace Common
