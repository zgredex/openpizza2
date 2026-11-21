/* Object_SetWorkState: sets state 0x2e and locks work state 1 (0x50a920). */
struct Object {
    void SetState(int state);
    void SetFlag104(int value);
    void SetWorkState();
};

extern char *DAT_0057c670;

void Object::SetWorkState()
{
    SetState(0x2e);
    *(int *)(DAT_0057c670 + 0x368) = 1;
    SetFlag104(1);
}
