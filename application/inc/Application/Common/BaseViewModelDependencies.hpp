#pragma once

#include <memory>
#include "Application/Appliance/HeaderBarModel.hpp"

class HeaderBarModel;

namespace Application {
namespace Common {

class BaseViewModelDependencies
{
public:
    BaseViewModelDependencies();

    std::shared_ptr<HeaderBarModel> headerBarModel;
};

} // namespace Common
} // namespace Application
