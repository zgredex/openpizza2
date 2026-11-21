/* Person_WalkToCellOrAbort: advances a person's route, aborting the order
   when no path exists (0x50e6b0). */
struct Person {
    int AdvanceRoute(int target);
    void ProcessMoveEvent();
    int WalkToCellOrAbort(int target);
};

struct Object {
    void SetState(int state);
};

int Person::WalkToCellOrAbort(int target)
{
    int result = AdvanceRoute(target);

    if (result == 0) {
        ((Object *)this)->SetState(6);
        *(char *)((char *)this + 0x81) = 1;
        ProcessMoveEvent();
    } else {
        ((Object *)this)->SetState(8);
    }
    return result;
}
