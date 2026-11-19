#ifndef PC2_RECONSTRUCTED_PERSONNEL_STATE_H
#define PC2_RECONSTRUCTED_PERSONNEL_STATE_H

#include <stdbool.h>
#include <stdint.h>

#define PERSONNEL_MAX_STAFF 32

typedef enum StaffProfession {
    STAFF_COOK = 0,
    STAFF_SERVER = 1,
    STAFF_ERRAND_BOY = 2,
    STAFF_MANAGER = 3,
    STAFF_GUARD = 4,
} StaffProfession;

typedef enum PersonnelPage {
    PERSONNEL_PAGE_OVERVIEW = 0,
    PERSONNEL_PAGE_RECORD = 1,
    PERSONNEL_PAGE_PLAN = 2,
} PersonnelPage;

typedef struct StaffMember {
    uint32_t id;
    StaffProfession profession;
    int32_t skill;
    int32_t speed;
    int32_t motivation;
    int32_t health;
    int32_t wage;
    uint32_t branch_id;
    int32_t training_level;
} StaffMember;

typedef struct PersonnelState {
    StaffMember staff[PERSONNEL_MAX_STAFF];
    int count;
    int selected;
    PersonnelPage page;
} PersonnelState;

/*
 * Host-side personnel state reconstructed from the staff setters and pages:
 * Person_SetSkill 0x4D4130, Person_SetSpeed 0x4D4140,
 * Person_SetMotivation 0x4D4120, Person_SetHealth 0x4D4150,
 * Personnel_GetTrainingLevel 0x4A8450, Branch_RemoveAllStaff 0x4F7B50,
 * Screen_PersonnelOverview 0x415620 and Screen_PersonnelRecord 0x4632C0.
 */
void personnel_state_init(PersonnelState *state);
int personnel_add(PersonnelState *state, uint32_t id, StaffProfession profession,
                  int32_t skill, int32_t speed, int32_t motivation, int32_t health,
                  int32_t wage, uint32_t branch_id);
bool personnel_remove(PersonnelState *state, uint32_t id);
StaffMember *personnel_find(PersonnelState *state, uint32_t id);
void personnel_set_branch(PersonnelState *state, uint32_t id, uint32_t branch_id);
void personnel_set_skill(PersonnelState *state, uint32_t id, int32_t value);
void personnel_set_speed(PersonnelState *state, uint32_t id, int32_t value);
void personnel_set_motivation(PersonnelState *state, uint32_t id, int32_t value);
void personnel_set_health(PersonnelState *state, uint32_t id, int32_t value);
int32_t personnel_training_level(int32_t table_value);
int32_t personnel_total_wage(const PersonnelState *state);
int32_t personnel_average_skill(const PersonnelState *state);
void personnel_set_page(PersonnelState *state, PersonnelPage page);
void personnel_select(PersonnelState *state, int index);

#endif
