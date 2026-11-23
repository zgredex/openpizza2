extern "C" unsigned int __cdecl strlen(const char *text);
extern "C" char *__cdecl strcpy(char *dest, const char *source);
extern "C" void *__cdecl memcpy(void *dest, const void *source, unsigned int count);

/* NamePool_AddName: appends a name to one of three fixed-size pools
   (0x402f10). */
struct NamePool {
    char pad[4];
    void *pool1;
    void *pool0;
    void *pool2;
    unsigned short count1;
    unsigned short count0;
    unsigned short count2;
    void AddName(char *name, int type);
};

void NamePool::AddName(char *name, int type)
{
    void **pool;
    unsigned short *count;

    switch (type) {
    case 0:
        pool = (void **)((char *)this + 8);
        count = (unsigned short *)((char *)this + 0x12);
        break;
    case 1:
        pool = (void **)((char *)this + 4);
        count = (unsigned short *)((char *)this + 0x10);
        break;
    case 2:
        pool = (void **)((char *)this + 0xc);
        count = (unsigned short *)((char *)this + 0x14);
        break;
    default:
        return;
    }

    if (strlen(name) > 0xf) {
        name[0xf] = '\0';
    }
    if ((*count & 0x3f) == 0) {
        char *buffer = new char[((short)*count + 0x40) * 0x10];

        if (*pool != 0) {
            memcpy(buffer, *pool, (short)*count * 0x10);
            delete (char *)*pool;
        }
        *pool = buffer;
    }
    strcpy((char *)*pool + (short)*count * 0x10, name);
    ++*count;
}
