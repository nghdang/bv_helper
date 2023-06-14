#pragma once

#include "Application/Common/BaseViewModel.hpp"

namespace Application {
namespace GithubActivities {

class GithubActivitiesViewModel : public Common::BaseViewModel
{
    Q_OBJECT
public:
    explicit GithubActivitiesViewModel(const std::shared_ptr<Common::BaseViewModelDependencies>& baseViewModelDependencies, QObject* parent = nullptr);

signals:

public slots:
    void enterBack();
};

} // namespace GithubActivities
} // namespace Application

Q_DECLARE_METATYPE(Application::GithubActivities::GithubActivitiesViewModel*)
