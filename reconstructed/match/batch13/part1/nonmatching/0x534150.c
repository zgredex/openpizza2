/* RecordList_TickFrame (0x534150). */
extern "C" __declspec(dllimport) unsigned long __stdcall timeGetTime(void);

struct CS {
    void Enter();
    void Leave();
};
struct Record {
    int frame;              /* 0x00 */
    char pad0[4];
    double a;               /* 0x08 */
    double b;               /* 0x10 */
    char pad1[0x30];
};
struct RecordList {
    char pad0[0x48];
    int count;              /* 0x48 */
    Record *records;        /* 0x4c */

    int TickFrame(int index);
    int AdvanceFrameSequence(int index, unsigned long time, double *a,
                             double *b, void *extra);
};
extern CS DAT_005842a0;

int RecordList::TickFrame(int index)
{
    int result;

    if (index < 0 || index >= count)
        return 0;
    if (*(int *)((char *)records + index * 0x48) == -1)
        return 0;
    DAT_005842a0.Enter();
    {
        char *base = (char *)records + index * 0x48;

        result = AdvanceFrameSequence(index, timeGetTime(),
                                      (double *)(base + 8),
                                      (double *)(base + 0x10), 0);
    }
    DAT_005842a0.Leave();
    return result;
}
