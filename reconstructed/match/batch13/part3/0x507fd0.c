/* Person_ReturnToHomeBase (0x507fd0). */
struct Object {
    void SetState(int state);
    void SetDestinationAndTarget(int mode, int target);
};
struct Person {
    char pad00[0x3c];
    int field3c;
    char pad40[0x60];
    int fieldA0;
    char padA4[0x28];
    int fieldCC;
    int fieldD0;
    int arrayD4[8];

    void ReturnToHomeBase();
};
extern "C" char *DAT_0057c670;
extern "C" char *DAT_0057c1e0;
extern "C" char DAT_0057301c;
extern "C" void __cdecl DebugConsole_Printf(char *console, int level,
                                             const char *text);

void Person::ReturnToHomeBase()
{
    if (*(void **)(DAT_0057c670 + 0x21c) == this) {
        DebugConsole_Printf(DAT_0057c1e0, 0, &DAT_0057301c);
    }
    ((struct Object *)this)->SetState(2);
    if (fieldA0 != 0) {
        fieldD0 = arrayD4[field3c];
    } else {
        fieldD0 = fieldCC;
    }
    ((struct Object *)this)->SetDestinationAndTarget(6, arrayD4[field3c]);
}
