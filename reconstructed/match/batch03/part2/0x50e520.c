/* Person_ClearCompletedAction - 0x50e520, 23 bytes */
extern void __fastcall Person_ReturnToHomeBase(void *this_);

struct Person
{
    char pad[0x74];
    int action;
    char pad2[0x90];
    int completed;

    void ClearCompletedAction();
};

void Person::ClearCompletedAction()
{
    int action = *(int *)((char *)this + 0x74);

    *(int *)((char *)this + 0x108) = -1;
    if (action == 0)
        Person_ReturnToHomeBase(this);
}
