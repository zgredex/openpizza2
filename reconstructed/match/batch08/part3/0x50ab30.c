/* Object_Activate: marks the object active and adds it to the map
   (0x50ab30). */
struct Game {
    void AddObjectToList(void *object);
};

struct Object {
    void SetFlag104(int value);
    void Activate(void *game);
};

struct Child {
    char pad[0x10];
    unsigned char flags;       /* 0x10 */
};

void Object::Activate(void *game)
{
    if (*(char *)((char *)this + 0x104) == 0) {
        SetFlag104(1);
        if (game != 0)
            ((Game *)game)->AddObjectToList(this);
        if (*(int *)((char *)this + 0xc4) != 0) {
            *(unsigned char *)(*(int *)((char *)this + 0xc8) + 0x10) |= 1;
        }
    }
}
