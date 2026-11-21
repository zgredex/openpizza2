/* Object_ActivateAndSetState: activates the object and switches it to state 2 (0x50ab10). */
struct Object {
    char pad[0xfc];
    void *fieldFC;
    void Activate(void *target);
    void SetState(int state);
    void ActivateAndSetState();
};

void Object::ActivateAndSetState()
{
    Activate(fieldFC);
    SetState(2);
}
