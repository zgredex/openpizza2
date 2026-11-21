/* Profiler_StopTimer (0x4037d0): closes a profiler interval and updates the
   per-slot total/maximum counters. */
extern "C" __declspec(dllimport) unsigned long __stdcall timeGetTime(void);

extern int DAT_0057b558;
extern unsigned int DAT_00579cd8[];
extern unsigned int DAT_0057b31c[];
extern unsigned int DAT_00579e68[];
extern unsigned int DAT_00579b48[];
extern unsigned int DAT_0057a18c[];

void __cdecl Profiler_StopTimer(int param_1)
{
    unsigned long now;
    unsigned int elapsed;

    if (DAT_0057b558 != 0) {
        if (param_1 < 0) {
            param_1 = 0;
        } else if (99 < param_1) {
            param_1 = 99;
        }
        now = timeGetTime();
        elapsed = now - DAT_00579cd8[param_1];
        if (elapsed > DAT_0057b31c[param_1]) {
            DAT_0057b31c[param_1] = elapsed;
            DAT_00579e68[param_1] = DAT_00579b48[param_1];
        }
        DAT_00579b48[param_1] = DAT_00579b48[param_1] + 1;
        DAT_0057a18c[param_1] = DAT_0057a18c[param_1] + elapsed;
    }
}
