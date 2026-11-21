/* Object_SetFieldA4Locked: stores field 0xa4 under the global critical
   section (0x50e850). */
struct CS {
    void Enter();
    void Leave();
};

struct Object {
    char pad[0xa4];
    int fieldA4;
    void SetFieldA4Locked(int value);
};

extern char *DAT_0057c670;

void Object::SetFieldA4Locked(int value)
{
    ((CS *)*(void **)(DAT_0057c670 + 0x240))->Enter();
    fieldA4 = value;
    ((CS *)*(void **)(DAT_0057c670 + 0x240))->Leave();
}
