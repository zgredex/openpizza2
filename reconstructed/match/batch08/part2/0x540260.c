/* SoundStream_Close: closes a stream file under its critical section
   (0x540260). */
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void *section);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void *section);
void __cdecl CRT_Fclose(void *file);

struct SoundStream {
    char pad[0x23c];
    char lock[1];
    void Close(int handle);
};

void SoundStream::Close(int handle)
{
    EnterCriticalSection((char *)this + 0x23c);
    if (*(int *)(handle + 0x1c) == 1)
        CRT_Fclose(*(void **)(handle + 0x18));
    *(int *)(handle + 0x14) = 0;
    LeaveCriticalSection((char *)this + 0x23c);
}
