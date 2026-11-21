/* UI_ClearPendingCommand: clears the pending flag and sends command 0x35 (0x520cf0). */
struct Object {
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void SendCommand(int command, int a, int b);
    char pad[0x18];
    int pending;
};

void __fastcall UI_ClearPendingCommand(Object *object)
{
    if (object->pending != 0) {
        object->pending = 0;
        object->SendCommand(0x35, 0, 0);
    }
}
