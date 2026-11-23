extern char *DAT_0057c670;

/* Branch_ExpelCustomers: makes the first matching customer of a branch leave
   (0x4d5580). */
struct CriticalSection {
    void Enter();
    void Leave();
};

struct IDMap {
    void *Lookup(int index, int *unused);
};

struct Person {
    int CanContinuePath();
    void DetachChildRecord();
    void SetDestinationAndTarget(int mode, int target);
    void SetState(int state);
};

struct Game {
    char pad[0x240];
    CriticalSection *lock;
    char rest[];
    int CountObjectsByState(int state);
};

extern "C" void __stdcall Branch_ExpelCustomers(int param_1)
{
    int i = 0;
    int n;

    ((Game *)DAT_0057c670)->lock->Enter();
    n = ((Game *)DAT_0057c670)->CountObjectsByState(-1);
    if (0 < n) {
        do {
            Person *p = (Person *)((IDMap *)(DAT_0057c670 + 0x3c))->Lookup(i, 0);

            if (*(int *)((char *)p + 0x30) == 0x22 &&
                *(int *)((char *)p + 0x108) != 0xb &&
                *(int *)((char *)p + 0xcc) == *(int *)(param_1 + 0x16f0)) {
                if (p->CanContinuePath() == 0) {
                    p->DetachChildRecord();
                }
                p->SetDestinationAndTarget(3, *(int *)((char *)p + 0xcc));
                p->SetState(4);
                *(int *)((char *)p + 0x108) = 0xb;
                ((Game *)DAT_0057c670)->lock->Leave();
                return;
            }
            i = i + 1;
            n = ((Game *)DAT_0057c670)->CountObjectsByState(-1);
        } while (i < n);
    }
    ((Game *)DAT_0057c670)->lock->Leave();
}
