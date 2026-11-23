extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void *);
extern "C" void __fastcall CS_Delete(void *self)
{
    DeleteCriticalSection(self);
}
