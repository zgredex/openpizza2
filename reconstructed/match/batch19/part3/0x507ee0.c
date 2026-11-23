/* Person_SelectRouteStopForTimeSlot (0x507ee0). */

extern char *DAT_0057c1e0;
extern char *DAT_0057c670;
extern int DAT_005840d4[];

extern "C" void DebugConsole_Printf(char *log, int level, char *text, ...);

struct Object {
    void SetDestinationAndTarget(int code, int target);
    void SetState(int state);
};

struct Person {
    char pad0[0x38];
    int state;                  /* 0x38 */
    int current;                /* 0x3c */
    char pad1[0x90];
    int selected;               /* 0xd0 */
    int stops[1];               /* 0xd4 */
    char pad2[0x30];
    int mode;                   /* 0x108 */

    int SelectRouteStopForTimeSlot(int slot);
};

int Person::SelectRouteStopForTimeSlot(int slot)
{
    if (state == 0x1a)
        return 0;
    if (mode == 10)
        return 0;
    if (slot == current)
        return 0;
    if (*(Person **)(DAT_0057c670 + 0x21c) == this)
        DebugConsole_Printf(DAT_0057c1e0, 0, (char *)0x57300c);

    int target = *(int *)((char *)this + slot * 4 + 0xd4);
    if (target != *(int *)((char *)this + current * 4 + 0xd4)) {
        selected = target;
        ((Object *)this)->SetDestinationAndTarget(6, *(int *)((char *)this + slot * 4 + 0xd4));
        ((Object *)this)->SetState(2);
        current = slot;
        if (*(Person **)(DAT_0057c670 + 0x21c) == this)
            DebugConsole_Printf(DAT_0057c1e0, 0, (char *)0x572ffc,
                                DAT_005840d4[*(int *)(target + 4)]);
        return 1;
    }
    if (*(Person **)(DAT_0057c670 + 0x21c) == this)
        DebugConsole_Printf(DAT_0057c1e0, 0, (char *)0x572fec);
    current = slot;
    return 0;
}
