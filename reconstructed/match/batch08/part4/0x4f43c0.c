/* List_AppendQuad: copies a quad and appends it to the list (0x4f43c0). */
struct Quad {
    int value[4];
};

struct List {
    void Add(void *item);
};

extern "C" void * __cdecl operator_new(unsigned int size);

struct Object {
    void AppendQuad(Quad *value);
};

void Object::AppendQuad(Quad *value)
{
    Quad *copy = (Quad *)operator_new(0x10);

    *copy = *value;
    ((List *)((char *)this + 0x140))->Add(copy);
}
