#include "personnel_state.h"

#include <string.h>

void personnel_state_init(PersonnelState *state) {
    if (state == NULL) {
        return;
    }
    memset(state, 0, sizeof(*state));
    state->selected = -1;
    state->page = PERSONNEL_PAGE_OVERVIEW;
}

int personnel_add(PersonnelState *state, uint32_t id, StaffProfession profession,
                  int32_t skill, int32_t speed, int32_t motivation, int32_t health,
                  int32_t wage, uint32_t branch_id) {
    if (state == NULL || state->count >= PERSONNEL_MAX_STAFF) {
        return -1;
    }
    StaffMember *member = &state->staff[state->count];
    *member = (StaffMember){
        .id = id,
        .profession = profession,
        .skill = skill,
        .speed = speed,
        .motivation = motivation,
        .health = health,
        .wage = wage,
        .branch_id = branch_id,
        .training_level = 0,
    };
    state->count += 1;
    return state->count - 1;
}

bool personnel_remove(PersonnelState *state, uint32_t id) {
    if (state == NULL) {
        return false;
    }
    for (int index = 0; index < state->count; index++) {
        if (state->staff[index].id != id) {
            continue;
        }
        for (int move = index; move + 1 < state->count; move++) {
            state->staff[move] = state->staff[move + 1];
        }
        state->count -= 1;
        if (state->selected >= state->count) {
            state->selected = state->count - 1;
        }
        return true;
    }
    return false;
}

StaffMember *personnel_find(PersonnelState *state, uint32_t id) {
    if (state == NULL) {
        return NULL;
    }
    for (int index = 0; index < state->count; index++) {
        if (state->staff[index].id == id) {
            return &state->staff[index];
        }
    }
    return NULL;
}

void personnel_set_branch(PersonnelState *state, uint32_t id, uint32_t branch_id) {
    StaffMember *member = personnel_find(state, id);
    if (member != NULL) {
        member->branch_id = branch_id;
    }
}

void personnel_set_skill(PersonnelState *state, uint32_t id, int32_t value) {
    StaffMember *member = personnel_find(state, id);
    if (member != NULL) {
        member->skill = value;
    }
}

void personnel_set_speed(PersonnelState *state, uint32_t id, int32_t value) {
    StaffMember *member = personnel_find(state, id);
    if (member != NULL) {
        member->speed = value;
    }
}

void personnel_set_motivation(PersonnelState *state, uint32_t id, int32_t value) {
    StaffMember *member = personnel_find(state, id);
    if (member != NULL) {
        member->motivation = value;
    }
}

void personnel_set_health(PersonnelState *state, uint32_t id, int32_t value) {
    StaffMember *member = personnel_find(state, id);
    if (member != NULL) {
        member->health = value;
    }
}

int32_t personnel_training_level(int32_t table_value) {
    return table_value == 0 ? 0 : table_value + 1;
}

int32_t personnel_total_wage(const PersonnelState *state) {
    if (state == NULL) {
        return 0;
    }
    int32_t total = 0;
    for (int index = 0; index < state->count; index++) {
        total += state->staff[index].wage;
    }
    return total;
}

int32_t personnel_average_skill(const PersonnelState *state) {
    if (state == NULL || state->count == 0) {
        return 0;
    }
    int32_t total = 0;
    for (int index = 0; index < state->count; index++) {
        total += state->staff[index].skill;
    }
    return total / state->count;
}

void personnel_set_page(PersonnelState *state, PersonnelPage page) {
    if (state != NULL) {
        state->page = page;
    }
}

void personnel_select(PersonnelState *state, int index) {
    if (state != NULL && index >= 0 && index < state->count) {
        state->selected = index;
    }
}
