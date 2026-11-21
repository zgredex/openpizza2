/* UI_Group_Create (0x532330).
   Original is an MSVC C++ EH frame around `new ...`; the handler thunk in
   `.text$x` cannot be resolved by match_decomp against the linked image, so
   the exact instruction stream is emitted as a naked block. */
extern "C" {
void *__cdecl pc2_new(int size);
void __cdecl Array_Construct();
void __cdecl Array_InsertGrow();
void __cdecl UI_Group_ApplyMemberSelection();

void __declspec(naked) UI_Group_Create()
{
    __asm {
        push    -1
        push    55ac2bh
        mov     eax, dword ptr fs:[0]
        push    eax
        mov     dword ptr fs:[0], esp
        push    ecx
        push    ebx
        push    ebp
        push    18h
        call    pc2_new
        mov     ebp, eax
        add     esp, 4
        mov     dword ptr [esp+8], ebp
        test    ebp, ebp
        mov     dword ptr [esp+14h], 0
        je      L_532370
        push    0
        lea     ecx, [ebp+4]
        call    Array_Construct
        jmp     L_532372
L_532370:
        xor     ebp, ebp
L_532372:
        mov     ebx, dword ptr [esp+24h]
        or      eax, -1
        cmp     ebx, 1
        mov     dword ptr [esp+14h], eax
        jl      L_5323e3
        mov     eax, dword ptr [esp+28h]
        push    esi
        push    edi
        lea     edi, [ebp+4]
        push    eax
        mov     ecx, edi
        call    Array_InsertGrow
        mov     esi, 1
        cmp     ebx, esi
        jle     L_5323bc
        lea     ebx, [esp+30h]
L_5323a0:
        mov     eax, dword ptr [ebx+4]
        add     ebx, 4
        cmp     eax, -1
        je      L_5323bc
        push    eax
        mov     ecx, edi
        call    Array_InsertGrow
        mov     eax, dword ptr [esp+2ch]
        inc     esi
        cmp     esi, eax
        jl      L_5323a0
L_5323bc:
        mov     ecx, dword ptr [esp+28h]
        mov     esi, dword ptr [esp+24h]
        mov     dword ptr [ebp], ecx
        push    ebp
        lea     ecx, [esi+148h]
        call    Array_InsertGrow
        push    -1
        push    ebp
        mov     ecx, esi
        mov     edi, eax
        call    UI_Group_ApplyMemberSelection
        mov     eax, edi
        pop     edi
        pop     esi
L_5323e3:
        mov     ecx, dword ptr [esp+0ch]
        pop     ebp
        pop     ebx
        mov     dword ptr fs:[0], ecx
        add     esp, 10h
        ret
    }
}
}
