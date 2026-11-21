/* UI_ReleaseRefCount: releases an image reference by data pointer, freeing
   the image data and the reference node (0x5271d0). */
struct Ref {
    char pad[0x104];
    void *data;
    int count;
    Ref *next;
};

struct Image {
    void FreePixelData();
};

struct UI {
    char pad[0x82c4];
    Ref *refs;

    void ReleaseRefCount(int id);
};

extern "C" void Mem_Free(void *pointer);

void UI::ReleaseRefCount(int id)
{
    Ref *previous = 0;
    Ref *ref = refs;

    while (ref != 0) {
        if (ref->data == (void *)id) {
            goto found;
        }
        previous = ref;
        ref = ref->next;
    }
    return;
found:
    if (--ref->count != 0) {
        return;
    }
    if (previous == 0) {
        refs = ref->next;
    } else {
        previous->next = ref->next;
    }
    if (ref->data != 0) {
        void *data = ref->data;

        ((Image *)data)->FreePixelData();
        Mem_Free(data);
    }
    Mem_Free(ref);
}
