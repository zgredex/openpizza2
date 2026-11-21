/* Renderer_ConstructChild (0x537d80): initialises a renderer child from a
   parent renderer and links it into the parent list. */
extern "C" void *__cdecl operator_new(unsigned int size);
extern char DAT_0055c818;

struct Renderer;

struct List {
    void PushFront(void *item);
};

struct Renderer {
    char pad[0x30];
    unsigned char ready;       /* 0x30 */
    char pad2[0x40 - 0x31];
    int *child;                /* 0x40 */
    char pad3[0x4c - 0x44];
    int mode;                  /* 0x4c */
    int field50;               /* 0x50 */
    void *parent;              /* 0x54 */
    char pad4[0x78 - 0x58];
    int field78;               /* 0x78 */
    int field7c;               /* 0x7c */
    int field80;               /* 0x80 */
    void InitOrCopyState(Renderer *source);
    Renderer *ConstructChild(Renderer *source);
};

Renderer *Renderer::ConstructChild(Renderer *source)
{
    int *child;
    int index;

    *(void **)this = &DAT_0055c818;
    child = (int *)operator_new(0x14);
    *(int **)((char *)this + 0x40) = child;
    for (index = 0; index < 5; index++) child[index] = 0;
    *(unsigned char *)((char *)this + 0x30) = 0;
    *(int *)((char *)this + 0x78) = 0;
    *(int *)((char *)this + 0x7c) = 0;
    *(int *)((char *)this + 0x14) = 0;
    *(void **)((char *)this + 0x54) = source;
    *(int *)((char *)this + 0x4c) = 3;
    *(int *)((char *)this + 0x50) = 0;
    *(int *)((char *)this + 0x80) = 1;
    InitOrCopyState(source);
    if (*(void **)((char *)this + 0x54) != 0) {
        ((List *)source)->PushFront(this);
    }
    *(unsigned char *)((char *)this + 0x30) = 1;
    return this;
}
