#pragma once

#include "Application/Common/BaseViewModel.hpp"
#include "Application/Common/ProfileListModel.hpp"

namespace Application {
namespace UserProfile {

class UserProfileViewModel : public Common::BaseViewModel
{
    Q_OBJECT

    Q_PROPERTY(QSharedPointer<Common::ProfileListModel> profileListModel READ getProfileListModel NOTIFY profileListModelChanged)

public:
    explicit UserProfileViewModel(const std::shared_ptr<Common::BaseViewModelDependencies>& baseViewModelDependencies, QObject* parent = nullptr);
    virtual ~UserProfileViewModel();

    void activated() override;
    void activating() override;
    void deactivated() override;
    void deactivating() override;

    QSharedPointer<Common::ProfileListModel> getProfileListModel() const;

signals:
    void profileListModelChanged();

public slots:
    void enterTeamProfile();

protected:
    std::shared_ptr<HeaderBarModel> m_headerBarModel;
    QSharedPointer<Common::ProfileListModel> m_profileListModel;
};

} // namespace UserProfile
} // namespace Application

Q_DECLARE_METATYPE(Application::UserProfile::UserProfileViewModel*)
