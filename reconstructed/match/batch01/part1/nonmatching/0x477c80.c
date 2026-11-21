struct Game { int GetCurrentPlayerCompanyName(); void *GetPlayerBySlot(int); int GetTimeSegment(); };
struct CommandTarget { void AppendCommandIfActive(int a,int b); void HandleEvent(int a,int b,int c); };
struct Player { void ResetDebtHours(); };
struct SoundObject { void UpdateListener(__int64 d,int f); };
struct UIObject { void QueueControlCommand(int a,int b,int c); };
struct StatsObject { void *FindRecordByType(int t); void AddRecordValue(int a, float b, int c); };
extern "C" {
extern int DAT_0057c670;
extern double k_max_stat;
extern double k_zero_stat;
void __cdecl UI_Briefing_Printf(int a,int b,int c,int d,int e,int f,char *g,char *h,int *i);
}
void StatsObject::AddRecordValue(int param_1, float param_2, int param_3)
{
    void *record; double dVar1; int iVar4; int value; int index;
    record = FindRecordByType(param_3);
    if (((Game *)DAT_0057c670)->GetCurrentPlayerCompanyName() == *(int *)((char *)this + 0x30)) {
        (*(CommandTarget **)(*(int *)(DAT_0057c670 + 0x224) + 0xa8))->AppendCommandIfActive(0x14, -1);
        (*(CommandTarget **)(*(int *)(DAT_0057c670 + 0x224) + 0xa8))->AppendCommandIfActive(0x17, -1);
        value = (int)param_2;
        (*(CommandTarget **)(*(int *)(DAT_0057c670 + 0x224) + 0xa8))->HandleEvent(0x14, value, -1);
        (*(CommandTarget **)(*(int *)(DAT_0057c670 + 0x224) + 0xa8))->HandleEvent(0x17, value, -1);
    }
    if (record != 0) {
        *(float *)((char *)record + 0x10 + param_1 * 4) = param_2 + *(float *)((char *)record + 0x10 + param_1 * 4);
        iVar4 = (int)((Game *)DAT_0057c670)->GetPlayerBySlot(*(int *)((char *)this + 0x30));
        dVar1 = *(double *)(iVar4 + 0x108) + (double)param_2;
        if (dVar1 > k_max_stat) dVar1 = k_max_stat;
        *(double *)(iVar4 + 0x108) = dVar1;
        if (k_zero_stat <= dVar1) ((Player *)iVar4)->ResetDebtHours();
    }
    if (param_1 < 9) {
        index = ((Game *)DAT_0057c670)->GetTimeSegment() + param_1 * 9;
        *(float *)((char *)this + index * 4 + 0x2cc) = param_2 + *(float *)((char *)this + index * 4 + 0x2cc);
    }
    if (*(int *)(DAT_0057c670 + 0x258) == 0) {
        if (((Game *)DAT_0057c670)->GetCurrentPlayerCompanyName() == *(int *)((char *)this + 0x30)) {
            SoundObject *sound = *(SoundObject **)(DAT_0057c670 + 0x2d9c);
            if (sound != 0) {
                sound->UpdateListener((__int64)(dVar1 - param_2), 0);
                sound->UpdateListener(*(__int64 *)((char *)sound + 0x1b0) + (__int64)param_2, 1);
            }
        }
        if (*(void **)(DAT_0057c670 + 0x264) != 0)
            ((UIObject *)*(int *)(DAT_0057c670 + 0x264))->QueueControlCommand(-0x18648, 0x23, 0);
    }
}
