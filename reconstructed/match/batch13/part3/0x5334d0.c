/* List_ReleaseSharedBuffers (0x5334d0). */
struct CS {
    void Enter();
    void Leave();
};
extern "C" char DAT_00584248;
extern "C" void Mem_Free(void *pointer);

struct List {
    char pad00[0x34];
    unsigned char active34;
    unsigned char buffers35;
    char pad36[0x32];
    int count68;
    char pad6c[0x14];
    void **items80;

    void ReleaseSharedBuffers();
};

void List::ReleaseSharedBuffers()
{
    bool freed = false;

    if (active34 != 0) {
        ((struct CS *)&DAT_00584248)->Enter();
        if (buffers35 != 0) {
            int index = 0;
            if (count68 > 0) {
                do {
                    if (!freed) {
                        void *pointer = items80[index];
                        if (pointer != 0) {
                            freed = true;
                            Mem_Free(pointer);
                        }
                    }
                    index = index + 1;
                    items80[index - 1] = 0;
                } while (index < count68);
            }
            buffers35 = 0;
        }
        ((struct CS *)&DAT_00584248)->Leave();
    }
}
