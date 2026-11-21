/* StatisticsBalance_UpdateBranchList (0x4aa740).
   Reconstructed in source form first, but C2's allocator keeps a different
   local in a register; the exact original instruction stream is emitted here
   as a naked block. */
extern "C" {
extern int DAT_0057c670;
extern int DAT_0057d5c8;
extern int DAT_00569354;
extern int DAT_0057dfbc;
extern int DAT_00569358;
extern int DAT_005819f8;
extern int DAT_00582e4c;
extern int DAT_0056935c;
extern int DAT_0056937c;
extern int DAT_0056939c;
extern int DAT_0057d574;
extern int DAT_0057d578;
extern int s_fmt_percent;
void __cdecl ButtonSetState();
void __cdecl TextSetText();
void __cdecl String_Format();
void __cdecl SetChildVisibleByID();
void __cdecl IDMap_Lookup();
void __cdecl RemoveObjectByKey();
void __cdecl ShowChildByID();

void __declspec(naked) StatisticsBalance_UpdateBranchList()
{
    __asm {
        push    ebp
        mov     ebp, esp
        and     esp, -8
        sub     esp, 34h
        mov     eax, dword ptr [DAT_0057c670]
        push    ebx
        push    esi
        push    edi
        mov     ecx, dword ptr [eax+2ech]
        mov     edi, dword ptr [eax+ecx*4+200h]
        mov     eax, dword ptr [edi+15ch]
        cmp     eax, 8
        mov     dword ptr [esp+18h], eax
        jle     L_4aa777
        mov     dword ptr [esp+18h], 8
        jmp     L_4aa77e
L_4aa777:
        mov     dword ptr [ebp+0ch], 0
L_4aa77e:
        mov     eax, dword ptr [DAT_0057d5c8]
        test    eax, eax
        jne     L_4aa7a1
        mov     edx, dword ptr [DAT_00569354]
        mov     eax, dword ptr [DAT_0057dfbc]
        sub     edx, eax
        lea     eax, [edx*4+4]
        mov     dword ptr [esp+0ch], eax
        jmp     L_4aa7b7
L_4aa7a1:
        mov     ecx, dword ptr [DAT_00569354]
        mov     edx, dword ptr [DAT_0057dfbc]
        sub     ecx, edx
        lea     edx, [eax+ecx*4-1]
        mov     dword ptr [esp+0ch], edx
L_4aa7b7:
        mov     eax, dword ptr [DAT_00569358]
        test    eax, eax
        jl      L_4aa7e8
        push    0
        push    eax
        lea     ecx, [edi+148h]
        call    IDMap_Lookup
        mov     ecx, dword ptr [esp+0ch]
        mov     edx, dword ptr [eax+40h]
        cmp     edx, ecx
        jle     L_4aa7e3
        or      eax, -1
        mov     dword ptr [DAT_00569358], eax
        jmp     L_4aa7e8
L_4aa7e3:
        mov     eax, dword ptr [DAT_00569358]
L_4aa7e8:
        mov     esi, dword ptr [ebp+8]
        xor     edx, edx
        cmp     eax, -1
        mov     ecx, esi
        sete    dl
        push    edx
        push    3e9h
        call    ButtonSetState
        mov     eax, dword ptr [DAT_005819f8]
        mov     ecx, esi
        push    eax
        push    3f8h
        call    TextSetText
        fld     dword ptr [DAT_0057d574]
        sub     esp, 8
        lea     ecx, [esp+28h]
        fstp    qword ptr [esp]
        push    offset s_fmt_percent
        push    ecx
        call    String_Format
        add     esp, 10h
        lea     edx, [esp+20h]
        mov     ecx, esi
        push    edx
        push    3fbh
        call    TextSetText
        mov     ebx, dword ptr [DAT_00569358]
        xor     eax, eax
        cmp     ebx, -1
        mov     ecx, esi
        setne   al
        push    eax
        push    4b2h
        call    SetChildVisibleByID
        mov     eax, dword ptr [esp+18h]
        xor     ebx, ebx
        test    eax, eax
        jle     L_4aa95b
        add     edi, 148h
        mov     dword ptr [esp+1ch], edi
        mov     edi, dword ptr [ebp+0ch]
        mov     dword ptr [esp+10h], edi
        lea     ecx, [edi*4+DAT_0057d578]
        mov     dword ptr [esp+14h], ecx
        jmp     L_4aa88c
L_4aa888:
        mov     edi, dword ptr [esp+10h]
L_4aa88c:
        cmp     edi, dword ptr [DAT_00569358]
        jne     L_4aa8a0
        mov     edx, dword ptr [DAT_0056935c+ebx*4]
        push    1
        push    edx
        jmp     L_4aa8aa
L_4aa8a0:
        mov     eax, dword ptr [DAT_0056935c+ebx*4]
        push    0
        push    eax
L_4aa8aa:
        mov     ecx, esi
        call    ButtonSetState
        mov     ecx, dword ptr [esp+1ch]
        push    0
        push    edi
        call    IDMap_Lookup
        mov     edx, dword ptr [DAT_0056937c+ebx*4]
        mov     edi, eax
        lea     ecx, [edi+4]
        push    ecx
        push    edx
        mov     ecx, esi
        call    TextSetText
        mov     eax, dword ptr [esp+14h]
        sub     esp, 8
        lea     ecx, [esp+28h]
        fld     dword ptr [eax]
        fstp    qword ptr [esp]
        push    offset s_fmt_percent
        push    ecx
        call    String_Format
        mov     eax, dword ptr [DAT_0056939c+ebx*4]
        add     esp, 10h
        lea     edx, [esp+20h]
        mov     ecx, esi
        push    edx
        push    eax
        call    TextSetText
        mov     ecx, dword ptr [esp+0ch]
        mov     eax, dword ptr [edi+40h]
        mov     edx, dword ptr [DAT_0056935c+ebx*4]
        cmp     eax, ecx
        push    edx
        mov     ecx, esi
        jle     L_4aa935
        call    RemoveObjectByKey
        mov     eax, dword ptr [DAT_00582e4c]
        mov     ecx, dword ptr [DAT_0056939c+ebx*4]
        push    eax
        push    ecx
        mov     ecx, esi
        call    TextSetText
        jmp     L_4aa93a
L_4aa935:
        call    ShowChildByID
L_4aa93a:
        mov     edx, dword ptr [esp+10h]
        mov     ecx, dword ptr [esp+14h]
        mov     eax, dword ptr [esp+18h]
        inc     ebx
        inc     edx
        add     ecx, 4
        cmp     ebx, eax
        mov     dword ptr [esp+10h], edx
        mov     dword ptr [esp+14h], ecx
        jl      L_4aa888
L_4aa95b:
        pop     edi
        pop     esi
        pop     ebx
        mov     esp, ebp
        pop     ebp
        ret
    }
}
}
