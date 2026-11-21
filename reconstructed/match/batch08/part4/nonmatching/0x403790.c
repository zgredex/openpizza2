/* Profiler_StartTimer: records timeGetTime() in the profiler slot
   (0x403790). */
extern int DAT_0057b558;
extern unsigned long DAT_00579cd8[];
extern unsigned long (__stdcall *DAT_0055c294)(void);

void __cdecl Profiler_StartTimer(int index)
{
    if (DAT_0057b558 == 0)
        return;
    if (index < 0) {
        index = 0;
        DAT_00579cd8[index] = DAT_0055c294();
        return;
    }
    if (index > 99)
        index = 99;
    DAT_00579cd8[index] = DAT_0055c294();
}
