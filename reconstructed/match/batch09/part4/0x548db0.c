/* Sound_StopCurrentBuffer: stops the current DirectSound buffer under the
   sound lock (0x548db0). */
struct ISoundVtbl {
    char pad[0x54];
    void (__stdcall *StopBuffer)(void *self, int buffer);
};

struct ISound {
    ISoundVtbl *vtbl;
};

void __fastcall CS_Enter(void *section);
void __fastcall CS_Leave(void *section);

struct Sound {
    void StopCurrentBuffer();
};

void Sound::StopCurrentBuffer()
{
    char *self = (char *)this;
    ISound *device;

    if (*(char *)(self + 0xfc) != 0) {
        CS_Enter(self + 0x178);
        if (*(int *)(self + 0x10) != 0) {
            device = *(ISound **)(self + 8);
            device->vtbl->StopBuffer(device, *(int *)(self + 0x10));
            *(int *)(self + 0x10) = 0;
            *(int *)(self + 0x14) = 0;
        }
        CS_Leave(self + 0x178);
    }
}
