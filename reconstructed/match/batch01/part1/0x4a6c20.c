/* SubMenu_UpdateMenuPlanPage (0x4a6c20).
   Reconstructed in source form first, but C2's register allocation differs;
   the exact original instruction stream is emitted here as a naked block. */
extern "C" {
extern int DAT_0057c670;
extern int ext_55c4b8;
extern int DAT_0056938c;
extern int DAT_005691a4;
extern int DAT_005691bc;
extern int DAT_005691d4;
extern int DAT_00583544;
extern int DAT_005822c8;
extern int DAT_0058235c;
extern int DAT_00582344;
extern int DAT_00582334;
extern int DAT_00582318;
extern int DAT_00582488;
extern int DAT_00582480;
extern int DAT_00582478;
void __cdecl IDMap_Lookup();
void __cdecl CountObjectsByState();
void __cdecl String_Format();
void __cdecl TextSetText();
void __cdecl Slider_SetValue();
void __cdecl RemoveObjectByKey();
void __cdecl ShowChildByID();
void __cdecl GetWindowObject();
void __cdecl GetPairByKey();
void __cdecl AddSprite();
void __cdecl SetObjectTextByKey();
void __cdecl CollectVacantLots();
void __cdecl Gadget_SetTextf();
void __cdecl pc2_ftol();

void __declspec(naked) SubMenu_UpdateMenuPlanPage()
{
    __asm {
        sub     esp, 130h
        mov     eax, dword ptr [DAT_0057c670]
        push    ebx
        push    ebp
        push    esi
        mov     ecx, dword ptr [eax+2f4h]
        push    edi
        push    0
        push    ecx
        lea     ecx, [eax+4]
        call    IDMap_Lookup
        xor     ebp, ebp
        mov     dword ptr [esp+10h], eax
        xor     esi, esi
        lea     edi, [esp+20h]
L_4a6c4c:
        mov     ecx, dword ptr [DAT_0057c670]
        push    esi
        call    CountObjectsByState
        add     ebp, eax
        mov     dword ptr [edi], eax
        inc     esi
        add     edi, 4
        cmp     esi, 8
        jl      L_4a6c4c
        mov     esi, dword ptr [esp+144h]
        xor     edi, edi
        lea     ebx, [esp+20h]
L_4a6c72:
        mov     eax, dword ptr [ebx]
        lea     eax, [eax+eax*4]
        lea     eax, [eax+eax*4]
        shl     eax, 2
        cdq
        idiv    ebp
        lea     edx, [esp+40h]
        push    eax
        push    5686f4h
        push    edx
        call    String_Format
        add     esp, 0ch
        lea     eax, [esp+40h]
        lea     ecx, [edi+452h]
        push    eax
        push    ecx
        mov     ecx, esi
        call    TextSetText
        inc     edi
        add     ebx, 4
        cmp     edi, 8
        jl      L_4a6c72
        mov     ebp, dword ptr [esp+10h]
        push    0
        fld     dword ptr [ebp+8ch]
        fmul    dword ptr [ext_55c4b8]
        call    pc2_ftol
        push    eax
        push    432h
        mov     ecx, esi
        call    Slider_SetValue
        fld     dword ptr [ebp+94h]
        fmul    dword ptr [ext_55c4b8]
        push    0
        call    pc2_ftol
        push    eax
        push    431h
        mov     ecx, esi
        call    Slider_SetValue
        fld     dword ptr [ebp+9ch]
        fmul    dword ptr [ext_55c4b8]
        push    0
        call    pc2_ftol
        push    eax
        push    42fh
        mov     ecx, esi
        call    Slider_SetValue
        fld     dword ptr [ebp+90h]
        fmul    dword ptr [ext_55c4b8]
        push    0
        call    pc2_ftol
        push    eax
        push    435h
        mov     ecx, esi
        call    Slider_SetValue
        fld     dword ptr [ebp+98h]
        fmul    dword ptr [ext_55c4b8]
        push    0
        call    pc2_ftol
        push    eax
        push    434h
        mov     ecx, esi
        call    Slider_SetValue
        fld     dword ptr [ebp+0a0h]
        fmul    dword ptr [ext_55c4b8]
        push    0
        call    pc2_ftol
        push    eax
        push    433h
        mov     ecx, esi
        call    Slider_SetValue
        mov     edi, 437h
L_4a6d78:
        push    edi
        mov     ecx, esi
        call    RemoveObjectByKey
        inc     edi
        cmp     edi, 449h
        jl      L_4a6d78
        lea     ebx, [ebp+0c8h]
        xor     edi, edi
L_4a6d91:
        mov     eax, dword ptr [ebx]
        test    eax, eax
        jne     L_4a6da0
        mov     edx, dword ptr [edi+DAT_0056938c]
        push    edx
        jmp     L_4a6db5
L_4a6da0:
        cmp     eax, 1
        jne     L_4a6dae
        mov     eax, dword ptr [edi+DAT_005691a4]
        push    eax
        jmp     L_4a6db5
L_4a6dae:
        mov     ecx, dword ptr [edi+DAT_005691bc]
        push    ecx
L_4a6db5:
        mov     ecx, esi
        call    ShowChildByID
        add     edi, 4
        add     ebx, 4
        cmp     edi, 18h
        jl      L_4a6d91
        mov     ebx, offset DAT_005691d4
        mov     dword ptr [esp+14h], 30d40h
        mov     dword ptr [esp+10h], ebx
        lea     edi, [ebp+0fe4h]
        jmp     L_4a6de4
L_4a6de0:
        mov     ebx, dword ptr [esp+10h]
L_4a6de4:
        mov     edx, dword ptr [ebx]
        mov     ecx, esi
        push    edx
        call    GetWindowObject
        mov     edx, dword ptr [ebx]
        lea     eax, [esp+18h]
        lea     ecx, [esp+1ch]
        push    eax
        push    ecx
        push    edx
        mov     ecx, esi
        call    GetPairByKey
        mov     ebx, dword ptr [esp+14h]
        xor     ebp, ebp
        mov     eax, ebx
        add     eax, 6
        mov     dword ptr [esp+14h], eax
L_4a6e11:
        mov     eax, dword ptr [edi]
        lea     ecx, [esp+40h]
        inc     eax
        push    eax
        push    5691f4h
        push    ecx
        call    String_Format
        mov     ecx, dword ptr [esp+28h]
        mov     eax, dword ptr [esp+24h]
        add     esp, 0ch
        lea     edx, [esp+40h]
        push    edx
        lea     edx, [ecx+ebp]
        push    eax
        push    edx
        push    ebx
        mov     ecx, esi
        call    AddSprite
        mov     eax, dword ptr [edi]
        mov     ecx, dword ptr [eax*4+DAT_00583544]
        push    ecx
        push    ebx
        mov     ecx, esi
        call    SetObjectTextByKey
        add     ebp, 15h
        inc     ebx
        add     edi, 4
        cmp     ebp, 7eh
        jl      L_4a6e11
        mov     eax, dword ptr [esp+10h]
        add     eax, 4
        cmp     eax, 5691f4h
        mov     dword ptr [esp+10h], eax
        jl      L_4a6de0
        mov     ecx, dword ptr [DAT_0057c670]
        call    CollectVacantLots
        mov     edi, eax
        mov     edx, dword ptr [edi+14h]
        push    edx
        push    5686f4h
        push    1f4bh
        push    esi
        call    Gadget_SetTextf
        add     esp, 10h
        test    edi, edi
        je      L_4a6ea5
        mov     eax, dword ptr [edi]
        push    1
        mov     ecx, edi
        call    dword ptr [eax]
L_4a6ea5:
        mov     ecx, dword ptr [DAT_005822c8]
        push    ecx
        push    1f4dh
        mov     ecx, esi
        call    SetObjectTextByKey
        mov     edx, dword ptr [DAT_0058235c]
        mov     ecx, esi
        push    edx
        push    1f50h
        call    SetObjectTextByKey
        mov     eax, dword ptr [DAT_00582344]
        mov     ecx, esi
        push    eax
        push    1f4fh
        call    SetObjectTextByKey
        mov     ecx, dword ptr [DAT_00582334]
        push    ecx
        push    1f4eh
        mov     ecx, esi
        call    SetObjectTextByKey
        mov     edx, dword ptr [DAT_00582318]
        mov     ecx, esi
        push    edx
        push    1f52h
        call    SetObjectTextByKey
        mov     eax, dword ptr [DAT_00582488]
        mov     ecx, esi
        push    eax
        push    1f4ch
        call    SetObjectTextByKey
        mov     ecx, dword ptr [DAT_00582480]
        push    ecx
        push    1f53h
        mov     ecx, esi
        call    SetObjectTextByKey
        mov     edx, dword ptr [DAT_00582478]
        mov     ecx, esi
        push    edx
        push    1f51h
        call    SetObjectTextByKey
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 130h
        ret
    }
}
}
