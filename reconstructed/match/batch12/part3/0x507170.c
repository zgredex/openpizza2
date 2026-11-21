/* Person_DebugPrintLocation (0x507170). */

extern void *DAT_0057c670;
extern void *DAT_0057c1e0;
extern char STR_00572f10[];
extern char STR_00572f1c[];
extern char DAT_005840d4[];

void DebugConsole_Printf(void *console, int code, const char *format, ...);

void __fastcall Person_DebugPrintLocation(void *person)
{
    if (*(int *)((char *)DAT_0057c670 + 0x21c) == (int)person) {
        if (*(int *)((char *)person + 0xfc) == 0) {
            DebugConsole_Printf(DAT_0057c1e0,
                                *(int *)((char *)person + 0xfc),
                                STR_00572f1c,
                                *(unsigned char *)((char *)person + 0x104));
            return;
        }
        DebugConsole_Printf(DAT_0057c1e0, 0, STR_00572f10,
                            *(unsigned char *)((char *)person + 0x104),
                            ((char **)DAT_005840d4)[
                                *(int *)(*(int *)((char *)person + 0xfc) + 4)]);
    }
}
