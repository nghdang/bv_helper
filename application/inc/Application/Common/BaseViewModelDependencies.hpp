#pragma once

#include <memory>
#include "Application/Appliance/HeaderBarModel.hpp"

namespace Application {
namespace ViewManagement {
class ViewManager;
} // namespace ViewManagement
} // namespace Application

class HeaderBarModel;

namespace Application {
namespace Common {

class BaseViewModelDependencies
{
public:
    BaseViewModelDependencies(const std::shared_ptr<ViewManagement::ViewManager>& viewManager);

    std::shared_ptr<ViewManagement::ViewManager> viewManager;

    std::shared_ptr<HeaderBarModel> headerBarModel;
};

} // namespace Common
} // namespace Application
