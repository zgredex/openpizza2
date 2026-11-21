/* RecipeMenu_BuildOnMenuList - 0x49b4e0, 261 bytes
 *
 * Carries an MSVC C++ EH registration frame with handler thunk 0x5586b6.
 * The frame and body are reproduced at the instruction level so the absolute
 * handler reference resolves to the original image address.
 */
extern "C" void FUN_005586b6(void);
extern "C" void *__cdecl FUN_0054e221(unsigned int size);
extern "C" void *List_Construct();
extern "C" void *IDMap_Lookup();
extern "C" void *UI_ListEntry_Construct();
extern "C" void List_Add();

extern void *DAT_0057c670;
extern void *DAT_0057ca8c;

int __declspec(naked) __cdecl RecipeMenu_BuildOnMenuList(void)
{
    __asm
    {
        push    -1
        push    offset FUN_005586b6
        mov     eax, fs:[0]
        push    eax
        mov     fs:[0], esp
        sub     esp, 0xc
        mov     eax, dword ptr DAT_0057c670
        push    ebx
        push    ebp
        push    esi
        mov     ecx, [eax+0x2ec]
        push    edi
        xor     ebp, ebp
        push    0x1c
        mov     esi, [eax+ecx*4+0x200]
        xor     edi, edi
        mov     [esp+0x14], ebp
        mov     ebx, [esi+0x124]
        mov     [esp+0x18], ebx
        call    FUN_0054e221
        add     esp, 4
        mov     [esp+0x18], eax
        cmp     eax, edi
        mov     [esp+0x24], edi
        je      construct_failed
        push    edi
        mov     ecx, eax
        call    List_Construct
        jmp     construct_done
    construct_failed:
        xor     eax, eax
    construct_done:
        cmp     ebx, edi
        mov     dword ptr [esp+0x24], -1
        mov     dword ptr DAT_0057ca8c, eax
        jle     empty_list
        lea     ebp, [esi+0x110]
        mov     ebx, 1
    scan_loop:
        push    0
        push    edi
        mov     ecx, ebp
        call    IDMap_Lookup
        mov     esi, eax
        cmp     byte ptr [esi+0x1dc], bl
        jne     next_entry
        push    0x58
        call    FUN_0054e221
        add     esp, 4
        mov     [esp+0x18], eax
        test    eax, eax
        mov     [esp+0x24], ebx
        je      entry_failed
        add     esi, 4
        push    edi
        push    esi
        mov     ecx, eax
        call    UI_ListEntry_Construct
        jmp     entry_done
    entry_failed:
        xor     eax, eax
    entry_done:
        mov     ecx, dword ptr DAT_0057ca8c
        push    eax
        mov     dword ptr [esp+0x28], -1
        call    List_Add
        inc     dword ptr [esp+0x10]
    next_entry:
        mov     eax, [esp+0x14]
        inc     edi
        cmp     edi, eax
        jl      scan_loop
        mov     eax, [esp+0x10]
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        mov     ecx, [esp+0xc]
        mov     fs:[0], ecx
        add     esp, 0x18
        ret
    empty_list:
        mov     ecx, [esp+0x1c]
        pop     edi
        mov     eax, ebp
        pop     esi
        pop     ebp
        pop     ebx
        mov     fs:[0], ecx
        add     esp, 0x18
        ret
    }
}
