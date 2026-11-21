/* Renderer_Destroy (0x538a80). */

struct Renderer;

struct Object {
    void ClearField54();
};

struct List {
    void RemoveByValue(void *value);
};

void Mem_Free(void *block);

struct Renderer {
    void Destroy();
    void ReleaseTargets();
};

void Renderer::Destroy()
{
    void **node = *(void ***)((char *)this + 0x50);

    *(void **)this = (void *)0x55c818;
    *(char *)((char *)this + 0x30) = 0;
    while (node != 0) {
        void **next;

        ((struct Object *)node[0])->ClearField54();
        next = (void **)node[1];
        Mem_Free(node);
        node = next;
    }
    *(void **)((char *)this + 0x50) = 0;
    ReleaseTargets();
    if (*(void **)((char *)this + 0x54) != 0) {
        ((struct List *)*(void **)((char *)this + 0x54))->RemoveByValue(this);
    }
    Mem_Free(*(void **)((char *)this + 0x40));
    *(void **)((char *)this + 0x40) = 0;
}
