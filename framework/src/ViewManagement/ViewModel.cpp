#include "Framework/ViewManagement/ViewModel.hpp"

namespace Framework {
namespace ViewManagement {

ViewModel::ViewModel(QObject* parent)
    : QObject{parent}
{
}

void ViewModel::activated()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void ViewModel::activating()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void ViewModel::deactivated()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void ViewModel::deactivating()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

} // namespace ViewManagement
} // namespace Framework
