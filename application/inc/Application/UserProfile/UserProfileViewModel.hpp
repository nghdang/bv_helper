#pragma once

#include <QObject>
#include "Application/Common/BaseViewModel.hpp"
#include "Application/Common/ProfileListModel.hpp"

namespace UserProfile {

class UserProfileViewModel : public Common::BaseViewModel
{
    Q_OBJECT

    Q_PROPERTY(QSharedPointer<Common::ProfileListModel> profileListModel READ getProfileListModel NOTIFY profileListModelChanged)

public:
    explicit UserProfileViewModel(const std::shared_ptr<Common::BaseViewModelDependencies>& baseViewModelDependencies, QObject* parent = nullptr);

    QSharedPointer<Common::ProfileListModel> getProfileListModel() const;

signals:
    void profileListModelChanged();

protected:
    std::shared_ptr<HeaderBarModel> m_headerBarModel;
    QSharedPointer<Common::ProfileListModel> m_profileListModel;
};

} // namespace UserProfile
Q_DECLARE_METATYPE(UserProfile::UserProfileViewModel*)
