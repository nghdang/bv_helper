#include "Framework/ViewManagement/ViewModel.hpp"

namespace Framework {
namespace ViewManagement {

ViewModel::ViewModel(QObject* parent)
    : QObject{parent}
{
}

void ViewModel::activating() {}

void ViewModel::activated() {}

void ViewModel::deactivating() {}

void ViewModel::deactivated() {}

} // namespace ViewManagement
} // namespace Framework
