#pragma once

#include "Application/Gui/Common/BaseViewModel.hpp"

namespace Application {
namespace Gui {
namespace GithubActivities {

class GithubActivitiesViewModel : public Common::BaseViewModel
{
    Q_OBJECT
public:
    explicit GithubActivitiesViewModel(
      const std::shared_ptr<Common::BaseViewModelDependencies>& baseViewModelDependencies, QObject* parent = nullptr);

    void activating() override;
    void activated() override;
    void deactivating() override;
    void deactivated() override;

signals:

public slots:
    void enterBack();
};

} // namespace GithubActivities
} // namespace Gui
} // namespace Application

Q_DECLARE_METATYPE(Application::Gui::GithubActivities::GithubActivitiesViewModel*)
