/* SaveGame_ScanSaveFileList (0x498a70).
   Original is an MSVC C++ EH frame around `new List` / `new UI_ListEntry`;
   the handler thunk in `.text$x` cannot be resolved by match_decomp against
   the linked image, so the exact instruction stream is emitted as a naked
   block (including the CRT's inlined strcpy). */
extern "C" {
extern int DAT_0057ca04;
void *__cdecl pc2_new(int size);
void __cdecl List_Construct();
void __cdecl String_Format();
void __cdecl pc2_strrchr();
void __cdecl UI_ListEntry_Construct();
void __cdecl List_Add();
void __cdecl CRT_FindFirst();
void __cdecl CRT_FindNext();
void __cdecl CRT_FindClose();

void __declspec(naked) SaveGame_ScanSaveFileList()
{
    __asm {
        push    -1
        push    5585fch
        mov     eax, dword ptr fs:[0]
        push    eax
        mov     dword ptr fs:[0], esp
        sub     esp, 320h
        push    1ch
        call    pc2_new
        add     esp, 4
        _emit   89h
        _emit   44h
        _emit   24h
        _emit   00h
        test    eax, eax
        mov     dword ptr [esp+328h], 0
        je      L_498ab3
        push    0
        mov     ecx, eax
        call    List_Construct
        jmp     L_498ab5
L_498ab3:
        xor     eax, eax
L_498ab5:
        mov     dword ptr [DAT_0057ca04], eax
        lea     eax, [esp+8]
        push    eax
        push    5688d0h
        mov     dword ptr [esp+330h], -1
        call    CRT_FindFirst
        add     esp, 8
        cmp     eax, -1
        _emit   89h
        _emit   44h
        _emit   24h
        _emit   00h
        jne     L_498af7
        xor     eax, eax
        mov     ecx, dword ptr [esp+320h]
        mov     dword ptr fs:[0], ecx
        add     esp, 32ch
        ret
L_498af7:
        push    esi
        push    edi
L_498af9:
        lea     ecx, [esp+24h]
        lea     edx, [esp+128h]
        push    ecx
        push    5630d0h
        push    edx
        call    String_Format
        lea     eax, [esp+134h]
        push    2eh
        push    eax
        call    pc2_strrchr
        mov     edx, eax
        mov     edi, 57ca0ch
        or      ecx, -1
        xor     eax, eax
        repnz   scasb
        not     ecx
        sub     edi, ecx
        push    58h
        mov     eax, ecx
        mov     esi, edi
        mov     edi, edx
        shr     ecx, 2
        rep movsd
        mov     ecx, eax
        and     ecx, 3
        rep movsb
        call    pc2_new
        add     esp, 18h
        mov     dword ptr [esp+0ch], eax
        test    eax, eax
        mov     dword ptr [esp+330h], 1
        je      L_498b73
        lea     ecx, [esp+128h]
        push    0
        push    ecx
        mov     ecx, eax
        call    UI_ListEntry_Construct
        jmp     L_498b75
L_498b73:
        xor     eax, eax
L_498b75:
        mov     ecx, dword ptr [DAT_0057ca04]
        push    eax
        mov     dword ptr [esp+334h], -1
        call    List_Add
        mov     eax, dword ptr [esp+8]
        lea     edx, [esp+10h]
        push    edx
        push    eax
        call    CRT_FindNext
        add     esp, 8
        cmp     eax, -1
        jne     L_498af9
        mov     ecx, dword ptr [esp+8]
        push    ecx
        call    CRT_FindClose
        mov     ecx, dword ptr [esp+32ch]
        add     esp, 4
        mov     eax, 1
        mov     dword ptr fs:[0], ecx
        pop     edi
        pop     esi
        add     esp, 32ch
        ret
    }
}
}
