/* Sound_UpdateBufferFade (0x542630). */

struct Sound {
    unsigned SetBufferVolume(unsigned volume);
};

struct SoundState {
    char pad0[0x28];
    Sound *buffer;              /* 0x28 */
    char pad1[0x0c];
    void *lock;                 /* 0x38 */
    char pad2[0x17];
    char enabled;               /* 0x53 */
    char pad3[0x24];
    unsigned max;               /* 0x78 */
    char pad4[0x10];
    int state;                  /* 0x8c */
    unsigned last;              /* 0x90 */
    unsigned current;           /* 0x94 */
    unsigned duration;          /* 0x98 */
    unsigned volume;            /* 0x9c */
};

extern "C" __declspec(dllimport) unsigned long __stdcall timeGetTime();
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void *section);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void *section);

extern "C" int __fastcall Sound_UpdateBufferFade(SoundState *self)
{
    unsigned last;
    unsigned now;
    unsigned elapsed;
    unsigned percent;
    unsigned value;
    unsigned result;

    if (self->state == 0)
        return 1;
    last = self->last;
    now = timeGetTime();
    self->current = now;
    if (now >= last)
        elapsed = now - last;
    else
        elapsed = now - last - 1;
    if (elapsed < self->duration)
        return 1;

    percent = (elapsed * 100) / self->duration;

    switch (self->state) {
    case 2:
        if (percent > self->volume) {
            self->state = 0;
            self->volume = 0;
        } else {
            value = self->volume - percent;
            self->volume = value;
        }
        break;
    case 1:
        value = self->volume + percent;
        if (value >= self->max) {
            self->state = 0;
            self->volume = self->max;
        } else
            self->volume = value;
        break;
    }
updated:
    now = timeGetTime();
    self->last = now;
    self->current = now;
    if (self->enabled != 0) {
        EnterCriticalSection(self->lock);
        result = self->buffer->SetBufferVolume(self->volume);
        LeaveCriticalSection(self->lock);
        return result;
    }
    return 1;
}
