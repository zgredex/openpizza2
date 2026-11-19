#include "personnel_state.h"

#include <assert.h>
#include <stdio.h>

static void test_staff_lifecycle(void) {
    PersonnelState state;
    personnel_state_init(&state);
    assert(state.count == 0);
    assert(state.selected == -1);
    assert(state.page == PERSONNEL_PAGE_OVERVIEW);

    assert(personnel_add(&state, 1, STAFF_COOK, 70, 60, 80, 90, 100, 13694) == 0);
    assert(personnel_add(&state, 2, STAFF_SERVER, 60, 70, 75, 85, 80, 13694) == 1);
    assert(personnel_add(&state, 3, STAFF_ERRAND_BOY, 50, 90, 65, 95, 60, 13694) == 2);
    assert(state.count == 3);
    assert(personnel_total_wage(&state) == 240);
    assert(personnel_average_skill(&state) == 60);

    StaffMember *cook = personnel_find(&state, 1);
    assert(cook != NULL);
    assert(cook->profession == STAFF_COOK);
    assert(cook->branch_id == 13694);

    personnel_set_skill(&state, 1, 88);
    personnel_set_speed(&state, 1, 77);
    personnel_set_motivation(&state, 1, 66);
    personnel_set_health(&state, 1, 55);
    assert(cook->skill == 88);
    assert(cook->speed == 77);
    assert(cook->motivation == 66);
    assert(cook->health == 55);

    personnel_select(&state, 2);
    assert(state.selected == 2);
    personnel_set_page(&state, PERSONNEL_PAGE_PLAN);
    assert(state.page == PERSONNEL_PAGE_PLAN);

    assert(personnel_remove(&state, 2));
    assert(state.count == 2);
    assert(state.selected == 1);
    assert(personnel_find(&state, 2) == NULL);
    assert(!personnel_remove(&state, 99));
}

static void test_branch_assignment_and_training(void) {
    PersonnelState state;
    personnel_state_init(&state);
    personnel_add(&state, 7, STAFF_MANAGER, 80, 50, 70, 80, 150, 0);
    personnel_set_branch(&state, 7, 20001);
    assert(personnel_find(&state, 7)->branch_id == 20001);

    assert(personnel_training_level(0) == 0);
    assert(personnel_training_level(2) == 3);
    assert(personnel_training_level(4) == 5);
}

int main(void) {
    test_staff_lifecycle();
    test_branch_assignment_and_training();
    puts("personnel state reconstruction: OK");
    return 0;
}
