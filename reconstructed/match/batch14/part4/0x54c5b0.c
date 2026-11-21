/* Sound_DestroyObject (0x54c5b0): releases every owned resource object and
   clears the cache maps. */
struct Resource {
    virtual void Release(int flag);
};

struct SoundObject {
    void *FreeEntryMaps();
    void DestroyObject();

    char pad[4];
    Resource *field4;
    Resource *field8;
    Resource *fieldc;
    Resource *field10;
    Resource *field14;
    char pad2[0x28 - 0x18];
    Resource *field28;
    Resource *field2c;
};

void SoundObject::DestroyObject()
{
    FreeEntryMaps();
    if (field2c != 0) {
        field2c->Release(1);
        field2c = 0;
    }
    if (field4 != 0) {
        field4->Release(1);
        field4 = 0;
    }
    if (fieldc != 0) {
        fieldc->Release(1);
        fieldc = 0;
    }
    if (field10 != 0) {
        field10->Release(1);
        field10 = 0;
    }
    if (field14 != 0) {
        field14->Release(1);
        field14 = 0;
    }
    if (field8 != 0) {
        field8->Release(1);
        field8 = 0;
    }
    if (field28 != 0) {
        field28->Release(1);
        field28 = 0;
    }
}
