/* Object_StartOrderAction9 (0x50be00, 46 bytes).  Build: /O2 /TP.
   Sets the object's work animation and starts order action 9. */
struct UI {
    void SetChildState(int state);
};

struct Object {
    void SetFieldA4Locked(int value);
    void SetChildField2C(int value);
    void SetDestinationAndTarget(int action, int target);
    void StartOrderAction9(int target);
};

void Object::StartOrderAction9(int target)
{
    SetFieldA4Locked(0x1d);
    ((UI *)this)->SetChildState(0x22);
    SetChildField2C(0x10);
    SetDestinationAndTarget(9, target);
}
