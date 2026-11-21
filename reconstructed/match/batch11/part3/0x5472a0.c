/* Sound_SetPosition: updates the sound object's position and volume through
   its virtual interface (0x5472a0). */
struct SoundObject;

struct SoundVtable {
    char pad[0x58];
    void (__stdcall *setVolume)(struct SoundObject *self, int a, int b);
    char pad2[0x7c - 0x5c];
    void (__stdcall *setPosition)(struct SoundObject *self, int a, int b);
};

struct SoundObject {
    struct SoundVtable *vtable;
};

struct Sound {
    char pad[8];
    struct SoundObject *object;
    char pad2[0x1d0 - 0xc];
    unsigned int handle;

    void SetPosition(int a, int b, float scale);
};

void Sound::SetPosition(int a, int b, float scale)
{
    if (handle != 0) {
        int value = (int)((double)handle * scale);

        object->vtable->setPosition(object, a, value);
        object->vtable->setVolume(object, a, b);
    }
}
