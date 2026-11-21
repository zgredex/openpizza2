/* Company_ConstructDefault (0x4dd6b0).
   Original is an MSVC C++ EH constructor/factory; the handler thunk in
   `.text$x` cannot be resolved by match_decomp against the linked image, so
   the exact instruction stream is emitted as a naked block. */
extern "C" {
extern int DAT_0057c670;
void *__cdecl pc2_new(int size);
void __cdecl List_Construct();
void __cdecl List_Add();
void __cdecl Stats_Report_Construct();
void __cdecl GamePlan_Construct();
void __cdecl Game_SetDifficulty();

void __declspec(naked) Company_ConstructDefault()
{
    __asm {
        push    -1
        push    5592f8h
        mov     eax, dword ptr fs:[0]
        push    eax
        mov     dword ptr fs:[0], esp
        push    ecx
        push    ebx
        push    ebp
        push    esi
        mov     esi, ecx
        xor     ebp, ebp
        push    edi
        push    ebp
        lea     ecx, [esi+110h]
        mov     dword ptr [esp+14h], esi
        call    List_Construct
        lea     ecx, [esi+12ch]
        push    ebp
        mov     dword ptr [esp+20h], ebp
        call    List_Construct
        push    ebp
        lea     ecx, [esi+148h]
        mov     byte ptr [esp+20h], 1
        call    List_Construct
        lea     ebx, [esi+164h]
        push    ebp
        mov     ecx, ebx
        mov     byte ptr [esp+20h], 2
        call    List_Construct
        push    ebp
        lea     ecx, [esi+180h]
        mov     byte ptr [esp+20h], 3
        call    List_Construct
        push    ebp
        lea     ecx, [esi+19ch]
        mov     byte ptr [esp+20h], 4
        call    List_Construct
        push    ebp
        lea     ecx, [esi+1b8h]
        mov     byte ptr [esp+20h], 5
        call    List_Construct
        mov     ecx, dword ptr [esp+24h]
        or      eax, -1
        mov     dword ptr [esi+48h], eax
        mov     dword ptr [esi+50h], eax
        mov     eax, 1
        mov     dword ptr [esi+4ch], ecx
        mov     dword ptr [esi+1e4h], eax
        mov     dword ptr [esi+64h], eax
        mov     dword ptr [esi+68h], eax
        mov     dword ptr [esi+6ch], eax
        mov     eax, 64h
        mov     dword ptr [esi+108h], ebp
        mov     dword ptr [esi+0f0h], eax
        mov     dword ptr [esi+0f4h], eax
        mov     dword ptr [esi+0f8h], eax
        mov     ecx, 9
        xor     eax, eax
        lea     edi, [esi+70h]
        mov     dword ptr [esi], 55c568h
        mov     word ptr [esi+5ch], bp
        mov     dword ptr [esi+1d4h], ebp
        mov     dword ptr [esi+54h], ebp
        mov     dword ptr [esi+10ch], ebp
        mov     dword ptr [esi+1e0h], ebp
        mov     dword ptr [esi+1d8h], ebp
        mov     dword ptr [esi+60h], ebp
        mov     dword ptr [esi+1e8h], ebp
        mov     dword ptr [esi+58h], ebp
        mov     dword ptr [esi+0fch], ebp
        mov     dword ptr [esi+100h], ebp
        rep stosd
        mov     ecx, 6
        lea     edi, [esi+94h]
        rep stosd
        lea     eax, [esi+0ach]
        xor     edx, edx
        mov     byte ptr [esp+1ch], 6
        mov     dword ptr [eax], edx
        mov     word ptr [eax+4], dx
        mov     ecx, 6
        xor     eax, eax
        lea     edi, [esi+0cch]
        lea     edx, [esi+0e4h]
        rep stosd
        mov     ecx, 6
        lea     edi, [esi+0b4h]
        rep stosd
        xor     ecx, ecx
        push    35ch
        mov     dword ptr [edx], ecx
        mov     dword ptr [edx+4], ecx
        mov     word ptr [edx+8], cx
        call    pc2_new
        add     esp, 4
        mov     dword ptr [esp+24h], eax
        cmp     eax, ebp
        mov     byte ptr [esp+1ch], 7
        je      L_4dd862
        mov     ecx, dword ptr [DAT_0057c670]
        push    esi
        mov     ecx, dword ptr [ecx+94h]
        mov     dx, word ptr [ecx+4]
        mov     di, word ptr [ecx+0ah]
        and     edx, 0ffffh
        and     edi, 0ffffh
        push    edx
        push    edi
        mov     ecx, eax
        call    Stats_Report_Construct
        jmp     L_4dd864
L_4dd862:
        xor     eax, eax
L_4dd864:
        push    eax
        mov     ecx, ebx
        mov     byte ptr [esp+20h], 6
        call    List_Add
        push    30h
        call    pc2_new
        add     esp, 4
        mov     dword ptr [esp+24h], eax
        cmp     eax, ebp
        mov     byte ptr [esp+1ch], 8
        je      L_4dd891
        mov     ecx, eax
        call    GamePlan_Construct
        mov     ebp, eax
L_4dd891:
        push    1
        mov     ecx, ebp
        mov     byte ptr [esp+20h], 6
        call    Game_SetDifficulty
        push    ebp
        lea     ecx, [esi+12ch]
        call    List_Add
        mov     ecx, dword ptr [esp+14h]
        mov     eax, esi
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        mov     dword ptr fs:[0], ecx
        add     esp, 10h
        ret     4
    }
}
}
