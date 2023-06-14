#pragma once

#include "Application/Common/BaseViewModelDependencies.hpp"
#include "Application/ViewManagement/ViewManager.hpp"

namespace Application {
namespace ViewManagement {

class ViewContext
{
public:
    ViewContext(const std::shared_ptr<ViewManager>& viewManager);

protected:
    std::shared_ptr<Common::BaseViewModelDependencies> m_baseViewModelDependencies;
};

} // namespace ViewManagement
} // namespace Application
