/* Sound_SetState: switches the active sound state and notifies the driver
   when the state change is rejected (0x548070). */
struct ISoundVtbl {
    char pad[0xf4];
    void (__stdcall *SetState)(void *self, int state, char *changed);
};

struct ISound {
    ISoundVtbl *vtbl;
};

struct Sound {
    void TriggerSoundById(int id);
    void SetState(int state);
};

void Sound::SetState(int state)
{
    char *self = (char *)this;
    ISound *device;

    if (*(char *)(self + 0xfc) != 0 && state != 7) {
        device = *(ISound **)(self + 8);
        *(char *)&state = 0;
        device->vtbl->SetState(device, *(int *)(self + 0x7c), (char *)&state);
        if (*(char *)&state == 0)
            TriggerSoundById(0x16);
    }
}
