#include "Framework/ViewManagement/ViewModel.hpp"

namespace Framework {
namespace ViewManagement {

ViewModel::ViewModel(QObject* parent)
    : QObject{parent}
{
}

void ViewModel::activated() {}

void ViewModel::activating() {}

void ViewModel::deactivated() {}

void ViewModel::deactivating() {}

} // namespace ViewManagement
} // namespace Framework
