extern char DAT_00579af0;
extern "C" void *__cdecl memmove(void *dest, const void *source, unsigned int count);

/* IDMap_RemoveRecursive: removes one entry by id and recursively removes large
   index values (0x4016b0). */
struct CS {
    void Enter();
    void Leave();
};

struct IDMap {
    int RemoveRecursive(int id);
};

int IDMap::RemoveRecursive(int id)
{
    if (id >= 100000) {
        int i;

        ((CS *)&DAT_00579af0)->Enter();
        i = 0;
        if (0 < *(int *)((char *)this + 0xc)) {
            int *entry = *(int **)((char *)this + 8);

            do {
                if (*entry == id) {
                    RemoveRecursive(i);
                    ((CS *)&DAT_00579af0)->Leave();
                    return 1;
                }
                i = i + 1;
                entry = entry + 1;
            } while (i < *(int *)((char *)this + 0xc));
        }
        ((CS *)&DAT_00579af0)->Leave();
        return 0;
    }
    if (id < 0 || *(int *)((char *)this + 0x10) <= id) {
        return 0;
    }
    ((CS *)&DAT_00579af0)->Enter();
    *(int *)((char *)this + 0x14) = *(int *)((char *)this + 0x14) - 1;
    *(int *)((char *)this + 0xc) = *(int *)((char *)this + 0xc) - 1;
    {
        int n = (*(int *)((char *)this + 0x10) - id) - 1;

        if (0 < n) {
            unsigned int size = n * 4;

            memmove((void *)(*(int *)((char *)this + 8) + id * 4),
                    (void *)(*(int *)((char *)this + 8) + 4 + id * 4), size);
            memmove((void *)(*(int *)((char *)this + 4) + id * 4),
                    (void *)(*(int *)((char *)this + 4) + 4 + id * 4), size);
        }
    }
    ((CS *)&DAT_00579af0)->Leave();
    return 1;
}
