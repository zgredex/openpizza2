extern char *DAT_0057c670;
extern char *DAT_0057c5c8;

/* Sprite_LoadIntoSlot78: reloads the sprite stored in slot 0x78 (0x4f5660). */
struct CS {
    void Enter();
    void Leave();
};

struct Sprite {
    void *Load(void *renderer, void *resource, int id, int *error, void *a, void *b, int c);
};

struct Object {
    char pad[0x74];
    void *sprite;
    char rest[0xf4 - 0x7c];
    int fieldf4;
    void LoadIntoSlot78(int id);
};

void Object::LoadIntoSlot78(int id)
{
    int error = 0;
    void *sprite;
    CS *lock = *(CS **)(DAT_0057c670 + 0x240);

    lock->Enter();
    if (*(void **)((char *)this + 0x78) != 0) {
        (*(void (__stdcall **)(int))**(void ***)((char *)this + 0x78))(1);
    }
    {
        void *memory = operator new(0x50);

        if (memory == 0) {
            sprite = 0;
        } else {
            sprite = ((Sprite *)memory)->Load(DAT_0057c5c8,
                *(void **)(*(int *)((char *)this + 4) + 0x2bf44), id, &error, 0, 0, 0);
        }
    }
    *(void **)((char *)this + 0x78) = sprite;
    if (error != 0) {
        if (sprite != 0) {
            (*(void (__stdcall **)(int))*(void ***)sprite)(1);
        }
        *(void **)((char *)this + 0x78) = 0;
    }
    *(int *)((char *)this + 0xf4) = 1;
    lock->Leave();
}
