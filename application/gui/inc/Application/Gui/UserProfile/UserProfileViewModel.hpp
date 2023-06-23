#pragma once

#include "Application/Gui/Common/BaseViewModel.hpp"
#include "Application/Gui/Common/ProfileListModel.hpp"

namespace Application {
namespace Gui {
namespace UserProfile {

class UserProfileViewModel : public Common::BaseViewModel
{
    Q_OBJECT

    Q_PROPERTY(
      QSharedPointer<Common::ProfileListModel> profileListModel READ getProfileListModel NOTIFY profileListModelChanged)

public:
    explicit UserProfileViewModel(const std::shared_ptr<Common::BaseViewModelDependencies>& baseViewModelDependencies,
                                  QObject* parent = nullptr);

    void activating() override;
    void activated() override;
    void deactivating() override;
    void deactivated() override;

    QSharedPointer<Common::ProfileListModel> getProfileListModel() const;

signals:
    void profileListModelChanged();

public slots:
    void enterTeamProfile();

protected:
    QSharedPointer<Common::ProfileListModel> m_profileListModel;
};

} // namespace UserProfile
} // namespace Gui
} // namespace Application

Q_DECLARE_METATYPE(Application::Gui::UserProfile::UserProfileViewModel*)
