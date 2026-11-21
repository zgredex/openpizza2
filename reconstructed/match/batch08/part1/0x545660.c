/* Sound_Get3DBufferParams: fills the 3D buffer descriptor and forwards it to
   the sound object (0x545660). */
struct SoundVtbl {
    void *slot0;
    void *slot1;
    void *slot2;
    int (__stdcall *SetBufferParams)(void *object, int *params);
};

struct SoundObject {
    struct SoundVtbl *vtbl;
};

struct Sound3DHost {
    char pad[0x5c];
    struct SoundObject *object;
};

int __fastcall Sound_Get3DBufferParams(struct Sound3DHost *this_)
{
    int *params = (int *)((char *)this_ + 0x60);
    struct SoundObject *object;
    int i;
    int result;
    int value = 0;

    for (i = 0; i < 0x10; i++)
        params[i] = 0;
    object = this_->object;
    params[0] = 0x40;
    result = object->vtbl->SetBufferParams(object, params);
    if (result < 0)
        value = 0x80070057;
    return value;
}
