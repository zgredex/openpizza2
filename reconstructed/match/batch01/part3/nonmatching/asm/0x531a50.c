/* UI_CreateAnimationWindow - 0x531a50, 256 bytes
 *
 * The original carries an MSVC C++ EH registration frame whose handler thunk
 * (0x55abd6) and unwind metadata are fixed by the image layout, so the frame
 * and body are reproduced at the instruction level.
 */
extern "C" void FUN_0055abd6(void);
extern "C" void *__cdecl FUN_0054e221(unsigned int size);
extern "C" void *Anim_Load();
extern "C" void *MovieWindow_Construct();
extern "C" void UI_EnsureObjectArray();

void __declspec(naked) __cdecl UI_CreateAnimationWindow(void)
{
    __asm
    {
        push    -1
        push    offset FUN_0055abd6
        mov     eax, fs:[0]
        push    eax
        mov     fs:[0], esp
        sub     esp, 8
        push    ebp
        push    esi
        mov     esi, ecx
        push    edi
        push    0x98
        mov     eax, [esi+0x134]
        mov     edi, [eax+0x10]
        call    FUN_0054e221
        add     esp, 4
        mov     [esp+0x10], eax
        mov     ebp, [esp+0x30]
        mov     dword ptr [esp+0x1c], 0
        test    eax, eax
        je      load_failed
        mov     edx, [esi+0xdc]
        lea     ecx, [esp+0xc]
        push    0
        push    ecx
        push    ebp
        push    edi
        push    edx
        mov     ecx, eax
        call    Anim_Load
        mov     edi, eax
        jmp     loaded
    load_failed:
        xor     edi, edi
    loaded:
        mov     eax, [esp+0xc]
        mov     dword ptr [esp+0x1c], -1
        test    eax, eax
        je      create_window
        test    edi, edi
        je      return_zero
        mov     eax, [edi]
        push    1
        mov     ecx, edi
        call    dword ptr [eax]
    return_zero:
        pop     edi
        pop     esi
        xor     eax, eax
        pop     ebp
        mov     ecx, [esp+8]
        mov     fs:[0], ecx
        add     esp, 0x14
        ret     0x10
    create_window:
        push    ebx
        push    0xbc
        call    FUN_0054e221
        add     esp, 4
        mov     [esp+0x34], eax
        mov     ebx, [esp+0x28]
        mov     dword ptr [esp+0x20], 1
        test    eax, eax
        je      window_failed
        mov     ecx, [esp+0x30]
        mov     edx, [esp+0x2c]
        push    esi
        push    1
        push    ebp
        push    edi
        push    1
        push    ecx
        push    edx
        push    ebx
        mov     ecx, eax
        call    MovieWindow_Construct
        jmp     window_ready
    window_failed:
        xor     eax, eax
    window_ready:
        push    ebx
        push    eax
        mov     ecx, esi
        mov     dword ptr [esp+0x28], -1
        call    UI_EnsureObjectArray
        mov     ecx, [esp+0x18]
        pop     ebx
        pop     edi
        pop     esi
        mov     eax, 1
        pop     ebp
        mov     fs:[0], ecx
        add     esp, 0x14
        ret     0x10
    }
}
