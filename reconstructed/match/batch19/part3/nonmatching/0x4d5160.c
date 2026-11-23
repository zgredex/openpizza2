/* City_CreateExplosionEffect (0x4d5160). */

extern char *DAT_0057c670;
extern char DAT_0056cd20[];
extern "C" char *strcpy(char *dst, const char *src);

void *__cdecl operator new(unsigned int size);

struct Object {
    void *Construct(int type, int city, int a, int b, int c);
    void PlaceSpriteAtCenter(int a, int x, int y);
    void SetState(int state);
};

struct Game {
    void AddObjectToRegistry(void *object);
};

struct Record;

struct UI {
    void GetCenteredRectForRecord(int *x, int *y);
};

struct City {
    char pad0[0xc1c];
    int cityId;                 /* 0xc1c */

    void *CreateExplosionEffect(int param_1, int param_2, Record *record);
};

void *City::CreateExplosionEffect(int param_1, int param_2, Record *record)
{
    Object *object =
        (Object *)operator new(0x16c);

    if (object != 0)
        object = (Object *)object->Construct(0x2e, cityId, 0, 0, -1);
    strcpy((char *)object + 4, DAT_0056cd20);
    ((Game *)DAT_0057c670)->AddObjectToRegistry(object);
    int x;
    int y;

    ((UI *)record)->GetCenteredRectForRecord(&x, &y);
    object->PlaceSpriteAtCenter(0, x, y);
    object->SetState(0x18);
    *(Record **)((char *)object + 0xcc) = record;
    *(char *)((char *)object + 0x98) = 6;
    *(char *)((char *)object + 0x99) = 0;
    *(char *)((char *)object + 0x9a) = 0;
    *(char *)((char *)object + 0x9b) = 0;
    *(int *)((char *)object + 0x8c) = param_1;
    return object;
}
