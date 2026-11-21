/* NamedLockable_Destroy: sets the deleting-destructor vtable and destroys the
   wrapped critical section (0x401300). */
struct NamedLockable {
    void *vtable;
    char critical_section[24];
};

__declspec(dllimport) void __stdcall DeleteCriticalSection(void *section);
extern char NamedLockable_Delete_vtable[];

void __fastcall NamedLockable_Destroy(struct NamedLockable *this_)
{
    this_->vtable = NamedLockable_Delete_vtable;
    DeleteCriticalSection(this_->critical_section);
}
