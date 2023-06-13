#pragma once

#include <QObject>
#include <memory>
#include "Application/Appliance/HeaderBarModel.hpp"
#include "Application/Common/BaseViewModelDependencies.hpp"

namespace Application {
namespace Common {

class BaseViewModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(HeaderBarModel* headerBarModel READ getHeaderBarModel NOTIFY headerBarModelChanged)

public:
    explicit BaseViewModel(const std::shared_ptr<Common::BaseViewModelDependencies>& baseViewModelDependencies, QObject* parent = nullptr);

    HeaderBarModel* getHeaderBarModel() const;

signals:
    void headerBarModelChanged();

protected:
    std::shared_ptr<HeaderBarModel> m_headerBarModel;
};

} // namespace Common
} // namespace Application
