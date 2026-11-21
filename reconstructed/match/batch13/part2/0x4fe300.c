/* Company_DispatchWorkerToBranch (0x4fe300). */
struct MapList {
    char pad0[0x8c];
    int count;              /* 0x8c */

    void *MapRecordToGlobal(int index);
};
struct Worker {
    char pad0[0x30];
    int type;               /* 0x30 */
    char pad1[0xd8];        /* to 0x10c */
    int field10c;           /* 0x10c */

    void SetFieldA4Locked(int value);
    void SetDestinationAndTarget(int value, int target);
};
struct Branch {
    char pad0[0x3c];
    int field3c;            /* 0x3c */
    char pad1[0x16f0 - 0x40];
    int field16f0;          /* 0x16f0 */
};
struct Company {
    char pad0[0x1d8];
    MapList *list;          /* 0x1d8 */
};

int __stdcall Company_DispatchWorkerToBranch(Company *company, Branch *branch)
{
    MapList *list = company->list;
    int count = list->count;
    int index;

    for (index = 0; index < count; index++) {
        Worker *worker = (Worker *)list->MapRecordToGlobal(index);

        if (worker->type == 0x17) {
            worker->SetFieldA4Locked(0x12);
            worker->SetDestinationAndTarget(1, branch->field16f0);
            worker->field10c = branch->field3c;
            return 1;
        }
    }
    return 0;
}
