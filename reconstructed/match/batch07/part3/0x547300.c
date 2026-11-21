/* Sound_SetParam: forwards a parameter to the two device callbacks when a
   sound buffer is active (0x547300). */
struct SoundDevice;

struct SoundDeviceVtbl {
    char pad[0x5c];
    void (__stdcall *setExtra)(SoundDevice *device, int value, int extra);
    char pad2[0x1c];
    void (__stdcall *setBuffer)(SoundDevice *device, int value, int buffer);
};

struct SoundDevice {
    SoundDeviceVtbl *vtable;
};

struct Sound {
    char pad[8];
    SoundDevice *device;
    char pad2[0x1c4];
    int buffer;
    void SetParam(int value, int extra);
};

void Sound::SetParam(int value, int extra)
{
    if (buffer != 0) {
        device->vtable->setBuffer(device, value, buffer);
        device->vtable->setExtra(device, value, extra);
    }
}
