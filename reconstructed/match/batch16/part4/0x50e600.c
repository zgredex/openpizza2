/* Person_ChooseWanderTarget: chooses the next wander target of a person
   (0x50e600). */
struct Game {
    int CountGoalTargets(int target);
};

struct Branch {
    int PickRandomActiveCounter();
};

struct RecordMap {
    int Lookup1998(int key);
};

struct AI {
    int StepToNeighborCell(int cell);
    int ComputePath(int a, int b, int c);
};

struct Object {
    void AbortOrderAndReturnHome();
    void SetState(int state);
};

class Person {
public:
    void ChooseWanderTarget(void *param_1);
    int AdvanceRoute(int route);
};

void Person::ChooseWanderTarget(void *param_1)
{
    int iVar1;

    iVar1 = ((Game *)param_1)->CountGoalTargets(*(int *)((char *)this + 0xa4));
    if (iVar1 == 0) {
        iVar1 = ((Branch *)param_1)->PickRandomActiveCounter();
        *(int *)((char *)this + 0x8c) = iVar1;
        iVar1 = ((RecordMap *)param_1)->Lookup1998(iVar1);
        iVar1 = ((AI *)param_1)->StepToNeighborCell(iVar1);
        if (iVar1 == 0) {
            ((Object *)this)->AbortOrderAndReturnHome();
            ((Object *)this)->SetState(6);
            return;
        }
        iVar1 = AdvanceRoute(iVar1);
        if (iVar1 == 0) {
            ((Object *)this)->SetState(6);
            return;
        }
    } else {
        iVar1 = ((AI *)*(void **)((char *)this + 0xc4))->ComputePath(0, 0, 0);
        if (iVar1 == 0) {
            ((Object *)this)->AbortOrderAndReturnHome();
            ((Object *)this)->SetState(6);
            return;
        }
        AdvanceRoute(iVar1);
    }
    ((Object *)this)->SetState(8);
}
