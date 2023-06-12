#include "UserProfile/UserProfileViewModel.hpp"

#include <map>
#include <vector>

namespace UserProfile {

UserProfileViewModel::UserProfileViewModel(QObject* parent)
    : QObject{parent}
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

QString UserProfileViewModel::getHeaderText() const
{
    return QString("User Profile");
}

QSharedPointer<Common::ProfileListModel> UserProfileViewModel::getProfileListModel() const
{
    return m_profileListModel;
}

} // namespace UserProfile
