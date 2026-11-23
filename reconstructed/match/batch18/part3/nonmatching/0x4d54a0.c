extern char *DAT_0057c670;
extern char *DAT_00580b40;

/* City_SpawnFlyerBoy: spawns a flyer-boy agent on the city map (0x4d54a0). */
struct Object {
    void AttachToParent(void *parent, int flag);
    void SetState(int state);
    void WanderToLinkedCell();
};

struct Game {
    Object *Construct(int type, int a, int b, int c, int d);
    void AddObjectToRegistry(Object *object);
};

extern "C" void __cdecl City_SpawnFlyerBoy(void *city)
{
    char *object = 0;
    void *memory = operator new(0x16c);

    if (memory != 0) {
        object = (char *)((Game *)city)->Construct(0x22, *(int *)((char *)city + 0xc1c), 0, 0, -1);
    }
    {
        char *source = DAT_00580b40;
        char *dest = object;

        while (*source != '\0') {
            *dest = *source;
            dest = dest + 1;
            source = source + 1;
        }
        *dest = '\0';
    }
    ((Game *)DAT_0057c670)->AddObjectToRegistry((Object *)object);
    ((Object *)object)->AttachToParent(*(void **)((char *)city + 0x16f0), 0);
    *(int *)(object + 0xcc) = *(int *)((char *)city + 0x16f0);
    ((Object *)object)->SetState(8);
    ((Object *)object)->WanderToLinkedCell();
}
