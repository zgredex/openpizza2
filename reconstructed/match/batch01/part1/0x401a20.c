/* ResourceManager_Destruct (0x401a20). */
struct Entry {
    int valid;
    int file;
    int buffer;
    char rest[0x114];
};

struct Lock {
    ~Lock();
};

struct ResourceManager {
    virtual ~ResourceManager();
    char pad0[0x1680];
    int count;
    Lock lock;
    char pad2[0x1ab4 - 0x1688 - 1];
    int list;
};

extern "C" int fclose(void *stream);
void Mem_Free(void *block);

ResourceManager::~ResourceManager()
{
    Entry *e = (Entry *)this;

    while (0 < count) {
        --count;
        if (e[count + 1].valid != 0)
            fclose((void *)e[count].file);
        {
            int buffer = e[count].buffer;
            Mem_Free((void *)buffer);
        }
    }
    while (list != 0) {
        int next = *(int *)(list + 0x50);
        Mem_Free((void *)list);
        list = next;
    }
}
