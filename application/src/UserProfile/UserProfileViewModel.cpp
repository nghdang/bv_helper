#include "Application/UserProfile/UserProfileViewModel.hpp"

#include <map>
#include <vector>

namespace Application {
namespace UserProfile {

UserProfileViewModel::UserProfileViewModel(const std::shared_ptr<Common::BaseViewModelDependencies>& baseViewModelDependencies,
                                           QObject* parent)
    : Common::BaseViewModel(baseViewModelDependencies, parent)
{
    const std::map<QString, std::vector<QString>> categories{{"Personal", {"Role", "First Name", "Last Name"}},
                                                             {"Contact", {"BSH Username", "BSH Email"}},
                                                             {"Project", {"Project full name", "Project short name"}}};

    QVector<Common::ProfileItem> profileItems;
    for (const auto& it : categories)
    {
        Common::ProfileItem profileItem;
        profileItem.category = it.first;

        QVector<Common::ProfileCategory> profileCategories;
        for (const auto& jt : it.second)
        {
            profileCategories.push_back({jt, QString("")});
        }
        profileItem.categoryListModel = QSharedPointer<Common::ProfileCategoryListModel>::create();
        profileItem.categoryListModel->setProfileCategories(profileCategories);
        profileItems.push_back(profileItem);
    }

    m_profileListModel = QSharedPointer<Common::ProfileListModel>::create();
    m_profileListModel->setProfileItems(profileItems);
}

QSharedPointer<Common::ProfileListModel> UserProfileViewModel::getProfileListModel() const
{
    return m_profileListModel;
}

} // namespace UserProfile
} // namespace Application
