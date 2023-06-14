#include "Application/TeamProfile/TeamProfileViewModel.hpp"

#include <map>
#include <vector>

namespace Application {
namespace TeamProfile {

TeamProfileViewModel::TeamProfileViewModel(const std::shared_ptr<Common::BaseViewModelDependencies>& baseViewModelDependencies, QObject* parent)
    : Common::BaseViewModel(baseViewModelDependencies, parent)
{
    const std::map<QString, std::vector<QString>> categories{{"Leader", {"First Name", "Last Name", "BSH Email"}},
                                                             {"Reporter", {"First Name", "Last Name", "Bosch Email"}},
                                                             {"Coordinator", {"First Name", "Last Name", "BV Email"}},
                                                             {"Manager", {"First Name", "Last Name", "BV Email"}}};

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

QString TeamProfileViewModel::getHeaderText() const
{
    return QString("Team Profile");
}

QSharedPointer<Common::ProfileListModel> TeamProfileViewModel::getProfileListModel() const
{
    return m_profileListModel;
}

void TeamProfileViewModel::enterBack()
{
    submitFsmEvent(FSM_EV_BACK);
}

void TeamProfileViewModel::enterGitHubActivities()
{
    submitFsmEvent(FSM_EV_ENTER_USER_PROFILE);
}

} // namespace TeamProfile
} // namespace Application
