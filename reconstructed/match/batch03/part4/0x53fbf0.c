/* PC2 byte-match candidate: DirectSoundBuffer_Destructor (0x53fbf0, 20 bytes).
   Build: /O2 /TP.  Installs the DirectSoundBuffer vtable and releases the
   embedded buffer wrapper through its third vtable slot. */
struct DirectSoundBuffer;
extern "C" char DAT_0055c860;

void __fastcall DirectSoundBuffer_Destructor(int *object)
{
    int *buffer;

    *object = (int)&DAT_0055c860;
    buffer = (int *)object[1];
    if (buffer != 0)
        (*(void (__stdcall **)(int *))(*(int *)buffer + 8))(buffer);
}
