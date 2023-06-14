#pragma once

#include <QUrl>
#include <memory>

namespace Framework {
namespace ViewManagement {

class ViewModel;

class WindowConfiguration
{
public:
    WindowConfiguration();

    QUrl getQmlUrl() const;
    void setQmlUrl(const QUrl& newQmlUrl);

    QString getStackViewObjectName() const;
    void setStackViewObjectName(const QString& newStackViewObjectName);

    QString getViewModelName() const;
    void setViewModelName(const QString& newViewModelName);

    std::function<std::unique_ptr<ViewModel>()> getViewModelInstantiator() const;
    void setViewModelInstantiator(const std::function<std::unique_ptr<ViewModel>()>& newViewModelInstantiator);

protected:
    QUrl m_qmlUrl;

    QString m_stackViewObjectName;

    QString m_viewModelName;

    std::function<std::unique_ptr<ViewModel>()> m_viewModelInstantiator;
};

} // namespace ViewManagement
} // namespace Framework
