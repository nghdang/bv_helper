#pragma once

#include <memory>

class HeaderBarModel;

namespace Common {

class BaseViewModelDependencies
{
public:
    BaseViewModelDependencies(const std::shared_ptr<HeaderBarModel>& headerBarModel);

    std::shared_ptr<HeaderBarModel> headerBarModel;
};

} // namespace Common
