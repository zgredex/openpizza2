/* Object_EnsureInit: sends the initialisation command once (0x520cd0). */
struct Object {
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void SendCommand(int command, int a, int b);
    char pad[0x18];
    int initialised;
};

void __fastcall Object_EnsureInit(Object *object)
{
    if (object->initialised == 0) {
        object->initialised = 1;
        object->SendCommand(0x34, 0, 0);
    }
}
