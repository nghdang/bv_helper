#pragma once

#include "Application/Domain/SettingsManagement/SettingId.hpp"

namespace Application {
namespace Gui {
namespace SettingIds {

// Contexts
static const Domain::SettingsManagement::MenuUuid _MM_USER_PROFILE{"UserProfile"};
static const Domain::SettingsManagement::MenuUuid _MM_TEAM_PROFILE{"TeamProfile"};

// Groups
static const Domain::SettingsManagement::MenuUuid _SM_PERSONAL{"Personal"};
static const Domain::SettingsManagement::MenuUuid _SM_CONTACT{"Contact"};
static const Domain::SettingsManagement::MenuUuid _SM_PROJECT{"Project"};
static const Domain::SettingsManagement::MenuUuid _SM_LEADER{"Project"};
static const Domain::SettingsManagement::MenuUuid _SM_REPORTER{"Project"};
static const Domain::SettingsManagement::MenuUuid _SM_COORDINATOR{"Project"};
static const Domain::SettingsManagement::MenuUuid _SM_MANAGER{"Project"};

// Settings
static const Domain::SettingsManagement::MenuUuid _S_ROLE{"Role"};
static const Domain::SettingsManagement::MenuUuid _S_FIRST_NAME{"First Name"};
static const Domain::SettingsManagement::MenuUuid _S_LAST_NAME{"Last Name"};
static const Domain::SettingsManagement::MenuUuid _S_BSH_EMAIL{"BSH Email"};
static const Domain::SettingsManagement::MenuUuid _S_BSH_USERNAME{"BSH Username"};
static const Domain::SettingsManagement::MenuUuid _S_BOSCH_EMAIL{"Bosch Email"};
static const Domain::SettingsManagement::MenuUuid _S_BV_EMAIL{"BV Email"};
static const Domain::SettingsManagement::MenuUuid _S_FULL_NAME{"Full Name"};
static const Domain::SettingsManagement::MenuUuid _S_SHORT_NAME{"Short Name"};

static const Domain::SettingsManagement::SettingId SID_USER_PERSONAL_ROLE{_MM_USER_PROFILE, _SM_PERSONAL, _S_ROLE};
static const Domain::SettingsManagement::SettingId SID_USER_PERSONAL_FIRST_NAME{_MM_USER_PROFILE, _SM_PERSONAL,
                                                                                _S_FIRST_NAME};
static const Domain::SettingsManagement::SettingId SID_USER_PERSONAL_LAST_NAME{_MM_USER_PROFILE, _SM_PERSONAL,
                                                                               _S_LAST_NAME};
static const Domain::SettingsManagement::SettingId SID_USER_CONTACT_BSH_EMAIL{_MM_USER_PROFILE, _SM_CONTACT,
                                                                              _S_BSH_EMAIL};
static const Domain::SettingsManagement::SettingId SID_USER_CONTACT_BSH_USERNAME{_MM_USER_PROFILE, _SM_CONTACT,
                                                                                 _S_BSH_USERNAME};
static const Domain::SettingsManagement::SettingId SID_USER_PROJECT_FULL_NAME{_MM_USER_PROFILE, _SM_PROJECT,
                                                                              _S_FULL_NAME};
static const Domain::SettingsManagement::SettingId SID_USER_PROJECT_SHORT_NAME{_MM_USER_PROFILE, _SM_PROJECT,
                                                                               _S_SHORT_NAME};
static const Domain::SettingsManagement::SettingId SID_TEAM_LEADER_FIRST_NAME{_MM_TEAM_PROFILE, _SM_LEADER,
                                                                              _S_FIRST_NAME};
static const Domain::SettingsManagement::SettingId SID_TEAM_LEADER_LAST_NAME{_MM_TEAM_PROFILE, _SM_LEADER,
                                                                             _S_LAST_NAME};
static const Domain::SettingsManagement::SettingId SID_TEAM_LEADER_BSH_EMAIL{_MM_TEAM_PROFILE, _SM_LEADER,
                                                                             _S_BSH_EMAIL};
static const Domain::SettingsManagement::SettingId SID_TEAM_REPORTER_FIRST_NAME{_MM_TEAM_PROFILE, _SM_REPORTER,
                                                                                _S_FIRST_NAME};
static const Domain::SettingsManagement::SettingId SID_TEAM_REPORTER_LAST_NAME{_MM_TEAM_PROFILE, _SM_REPORTER,
                                                                               _S_LAST_NAME};
static const Domain::SettingsManagement::SettingId SID_TEAM_REPORTER_BOSCH_EMAIL{_MM_TEAM_PROFILE, _SM_REPORTER,
                                                                                 _S_BOSCH_EMAIL};
static const Domain::SettingsManagement::SettingId SID_TEAM_COORDINATOR_FIRST_NAME{_MM_TEAM_PROFILE, _SM_COORDINATOR,
                                                                                   _S_FIRST_NAME};
static const Domain::SettingsManagement::SettingId SID_TEAM_COORDINATOR_LAST_NAME{_MM_TEAM_PROFILE, _SM_COORDINATOR,
                                                                                  _S_LAST_NAME};
static const Domain::SettingsManagement::SettingId SID_TEAM_COORDINATOR_BV_EMAIL{_MM_TEAM_PROFILE, _SM_COORDINATOR,
                                                                                 _S_BV_EMAIL};
static const Domain::SettingsManagement::SettingId SID_TEAM_MANAGER_FIRST_NAME{_MM_TEAM_PROFILE, _SM_MANAGER,
                                                                               _S_FIRST_NAME};
static const Domain::SettingsManagement::SettingId SID_TEAM_MANAGER_LAST_NAME{_MM_TEAM_PROFILE, _SM_MANAGER,
                                                                              _S_LAST_NAME};
static const Domain::SettingsManagement::SettingId SID_TEAM_MANAGER_BV_EMAIL{_MM_TEAM_PROFILE, _SM_MANAGER,
                                                                             _S_BV_EMAIL};
} // namespace SettingIds
} // namespace Gui
} // namespace Application
