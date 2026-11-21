/* Sound_QueryFormatType (0x543e90, 46 bytes).  Build: /O2 /TP.
   Queries the audio format and returns the compressed/format flags. */
struct AudioVtbl {
    void (__stdcall *slot_0)();
    void (__stdcall *slot_1)();
    void (__stdcall *slot_2)();
    int (__stdcall *GetFormat)(void *self, int *format);
};

struct Audio {
    AudioVtbl *vtbl;
};

struct Sound {
    int QueryFormatType(void);
};

int Sound::QueryFormatType(void)
{
    int format[5];
    Audio *audio = *(Audio **)((char *)this + 0x48);

    format[0] = 0x14;
    if (audio->vtbl->GetFormat(audio, format) < 0)
        return 0;
    return format[1] & 0xc;
}
