/* Sound_QueryBufferFlag (0x542ad0, 48 bytes).  Build: /O2 /TP.
   Queries the audio buffer status and returns its low flag bit. */
struct AudioVtbl {
    void (__stdcall *slot_0)();
    void (__stdcall *slot_1)();
    void (__stdcall *slot_2)();
    void (__stdcall *slot_3)();
    void (__stdcall *slot_4)();
    void (__stdcall *slot_5)();
    void (__stdcall *slot_6)();
    void (__stdcall *slot_7)();
    void (__stdcall *slot_8)();
    int (__stdcall *QueryStatus)(void *self, int *status);
};

struct Audio {
    AudioVtbl *vtbl;
};

extern "C" char __fastcall Sound_QueryBufferFlag(int sound)
{
    int status;
    Audio *audio = *(Audio **)(sound + 0x48);

    if (audio == 0)
        return 0;
    status = 0;
    if (audio->vtbl->QueryStatus(audio, &status) < 0)
        return 0;
    return status & 1;
}
