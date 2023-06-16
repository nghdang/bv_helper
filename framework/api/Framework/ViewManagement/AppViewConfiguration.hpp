#pragma once

#include <QUrl>
#include <memory>

namespace Framework {
namespace ViewManagement {

using ViewId = int;

class ViewModel;

class AppViewConfiguration
{
public:
    QUrl getQmlUrl() const;
    void setQmlUrl(const QUrl& newQmlUrl);

    QString getViewName() const;
    void setViewName(const QString& newViewName);

    ViewId getViewId() const;
    void setViewId(ViewId newViewId);

    QString getFsmStateName() const;
    void setFsmStateName(const QString& newFsmStateName);

    QString getViewModelName() const;
    void setViewModelName(const QString& newViewModelName);

    std::function<std::shared_ptr<ViewModel>()> getViewModelInstantiator() const;
    void setViewModelInstantiator(const std::function<std::shared_ptr<ViewModel>()>& newViewModelInstantiator);

    QString getStackViewObjectName() const;
    void setStackViewObjectName(const QString& newStackViewObjectName);

protected:
    QUrl m_qmlUrl;

    QString m_viewName;

    ViewId m_viewId;

    QString m_fsmStateName;

    QString m_viewModelName;

    std::function<std::shared_ptr<ViewModel>()> m_viewModelInstantiator;

    QString m_stackViewObjectName;
};

} // namespace ViewManagement
} // namespace Framework
