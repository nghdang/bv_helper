#include "Common/BaseViewModel.hpp"

namespace Common {

BaseViewModel::BaseViewModel(const std::shared_ptr<BaseViewModelDependencies>& baseViewModelDependencies, QObject* parent)
    : m_headerBarModel{baseViewModelDependencies->headerBarModel}
    , QObject{parent}
{
}

HeaderBarModel* BaseViewModel::getHeaderBarModel() const
{
    return m_headerBarModel.get();
}

} // namespace Common
