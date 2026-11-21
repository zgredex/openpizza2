/* Window_ReleaseResources: releases the window's UI reference and its
   allocation (0x528760). */
void Mem_Free(void *block);

struct UI {
    void ReleaseRefCount(int index);
};

void __fastcall Window_ReleaseResources(int this_)
{
    *(int *)(this_ + 0x44) = 0;
    (*(struct UI **)(*(int *)(this_ + 0x58) + 0x134))
        ->ReleaseRefCount(*(int *)(this_ + 0x4c));
    if (*(void **)(this_ + 0x68) != 0) {
        Mem_Free(*(void **)(this_ + 0x68));
        *(int *)(this_ + 0x68) = 0;
    }
}
