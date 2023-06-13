#pragma once

#include <QUrl>

namespace Framework {
namespace ViewManagement {

class ViewManagerConfiguration
{
public:
    ViewManagerConfiguration();

    QUrl getStateMachineUrl() const;
    void setStateMachineUrl(const QUrl& newStateMachineUrl);

protected:
    QUrl m_stateMachineUrl;
};

} // namespace ViewManagement
} // namespace Framework
