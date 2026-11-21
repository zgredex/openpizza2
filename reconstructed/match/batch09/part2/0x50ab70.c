/* Object_Deactivate: detaches the object from its list and clears its active
   flag (0x50ab70). */
struct Game {
    void RemoveObjectFromList(void *object, int flags);
};

struct Object {
    void SetFlag104(int value);
    void SetFieldFC(int value);
    void Deactivate(void *list);
};

void Object::Deactivate(void *list)
{
    if (*(char *)((char *)this + 0x104) != 0) {
        if (list != 0)
            ((struct Game *)list)->RemoveObjectFromList(this, 0);
        SetFlag104(0);
        SetFieldFC(0);
        if (*(int *)((char *)this + 0xc8) != 0)
            *(unsigned char *)(*(int *)((char *)this + 0xc8) + 0x10) &= 0xfe;
    }
}
