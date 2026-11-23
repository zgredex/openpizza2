extern char *DAT_0057c670;

/* Building_PruneStaleListRow: removes the first stale building list row and
   refreshes the path (0x509c10). */
struct CS {
    void Enter();
    void Leave();
};

struct Game {
    char pad[0x240];
    CS *lock;
};

struct Object {
    int IsVisibleThisFrame();
};

struct Array {
    void *GetPtr4(int index);
};

struct UI {
    int RemoveLastChild();
};

struct Person {
    void RecomputePathStep(int child);
};

struct Building {
    void PruneStaleListRow();
};

void Building::PruneStaleListRow()
{
    if (*(int *)((char *)this + 0xc8) != 0) {
        ((Game *)DAT_0057c670)->lock->Enter();
        if (((Object *)this)->IsVisibleThisFrame() == 0) {
            ((Game *)DAT_0057c670)->lock->Leave();
            return;
        }
        {
            int i = *(short *)(*(int *)((char *)this + 0xc8) + 0x28);

            if (i != -1) {
                while (((Array *)(*(int *)((char *)this + 0xc8) + 0x14))->GetPtr4(i) != 0) {
                    void *p = ((Array *)(*(int *)((char *)this + 0xc8) + 0x14))->GetPtr4(i);

                    if (*(int *)(*(int *)(*(int *)(*(int *)((char *)this + 0xc4) + 0x4c) + 8 +
                                         *(int *)((char *)p + 8) * 0xc) + 0x28) == 0) {
                        ((Person *)this)->RecomputePathStep(((UI *)this)->RemoveLastChild());
                        ((Game *)DAT_0057c670)->lock->Leave();
                        return;
                    }
                    i = i + 1;
                }
            }
        }
        ((Game *)DAT_0057c670)->lock->Leave();
    }
}
