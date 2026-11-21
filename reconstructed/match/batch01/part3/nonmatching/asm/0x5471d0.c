/* SoundSystem_Destruct - 0x5471d0, 85 bytes
 *
 * This function's body is dominated by the MSVC C++ exception frame
 * (handler thunk 0x55b89e / FuncInfo 0x5614f8) and unwind funclet
 * 0x55b890, whose addresses are fixed by the original image layout.
 * The sequence is reproduced directly so the absolute frame references
 * resolve to the original locations.
 */
extern "C" void __cdecl NamedLockable_Destroy(void *lock);
extern "C" void __cdecl handler_55b89e(void);

void __declspec(naked) __cdecl SoundSystem_Destruct(void)
{
    __asm
    {
        push    -1
        push    offset handler_55b89e
        mov     eax, fs:[0]
        push    eax
        mov     fs:[0], esp
        push    ecx
        push    esi
        mov     esi, ecx
        mov     [esp+4], esi
        mov     eax, [esi+8]
        mov     dword ptr [esp+0x10], 0
        test    eax, eax
        je      skip_release
        mov     ecx, [eax]
        push    eax
        call    dword ptr [ecx+4]
    skip_release:
        lea     ecx, [esi+0x178]
        mov     dword ptr [esp+0x10], -1
        call    NamedLockable_Destroy
        mov     ecx, [esp+8]
        pop     esi
        mov     fs:[0], ecx
        add     esp, 0x10
        ret
    }
}
