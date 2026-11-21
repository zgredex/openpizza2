/* Person_SendToBranchWithCarryMode: send a person to a branch. */
struct UI {
    void SetChildState(int state);
};

struct Object {
    void SetChildField2C(int value);
    void SetDestinationAndTarget(int mode, int target);
    void SetFieldA4Locked(int value);
};

struct Person {
    void SendToBranchWithCarryMode(int branch, int mode);
};

void Person::SendToBranchWithCarryMode(int branch, int mode)
{
    Object *object = (Object *)this;

    object->SetChildField2C(0x10);
    object->SetDestinationAndTarget(1, *(int *)(branch + 0x16f0));
    object->SetFieldA4Locked(mode);
    if (*(int *)((char *)this + 0xa4) == 0x11)
        ((UI *)this)->SetChildState(0x22);
    else
        ((UI *)this)->SetChildState(0x15);
}
