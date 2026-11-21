/* Sound_StopAmbientBuffers: stops the ambient sound buffers (0x5484b0). */
typedef void (__stdcall *SoundMethod68)(void *object, int value);
typedef void (__stdcall *SoundMethodA8)(void *object, int value);

extern "C" void __fastcall Sound_StopAmbientBuffers(void *sound)
{
    void *object;
    void *vtbl;

    if (!*(char *)((char *)sound + 0xfc) ||
        !*(char *)((char *)sound + 0x16a)) {
        return;
    }
    *(char *)((char *)sound + 0x16a) = 0;
    if (*(unsigned int *)((char *)sound + 0x1d0) > 0) {
        object = *(void **)((char *)sound + 8);
        vtbl = *(void **)object;
        (*(SoundMethod68 *)((char *)vtbl + 0x68))(
            object, *(int *)((char *)sound + 0x88));
        object = *(void **)((char *)sound + 8);
        vtbl = *(void **)object;
        (*(SoundMethod68 *)((char *)vtbl + 0x68))(
            object, *(int *)((char *)sound + 0x8c));
        object = *(void **)((char *)sound + 8);
        vtbl = *(void **)object;
        (*(SoundMethodA8 *)((char *)vtbl + 0xa8))(
            object, *(int *)((char *)sound + 0xf4));
    }
}
