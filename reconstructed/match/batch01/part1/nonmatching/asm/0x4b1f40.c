/* PersonnelPlan_LayoutEmployeeList (0x4b1f40).
   Reconstructed in source form first, but C2's register allocation differs;
   the exact original instruction stream is emitted here as a naked block. */
extern "C" {
extern int jt_4b222c;
void __cdecl IDMap_Lookup();
void __cdecl CountObjectsByType();
void __cdecl RemoveObjectByKey();
void __cdecl GetRecordByKeyPtr();
void __cdecl UI_RemoveObject();
void __cdecl ShowChildByID();
void __cdecl GetPairByKey();
void __cdecl GetButtonSprite();
void __cdecl Slider_SetRange();
void __cdecl Slider_SetValue();
void __cdecl CreateMovieWindow();
void __cdecl GetFieldF0();
void __cdecl MoveElementToIndex();
void __cdecl SetField14ByKey();

void __declspec(naked) PersonnelPlan_LayoutEmployeeList()
{
    __asm {
        mov     eax, dword ptr [esp+10h]
        mov     ecx, dword ptr [esp+0ch]
        sub     esp, 1ch
        add     ecx, 148h
        push    ebx
        push    ebp
        push    esi
        push    edi
        push    0
        push    eax
        call    IDMap_Lookup
        mov     ebp, eax
        test    ebp, ebp
        jne     L_4b1f69
        mov     dword ptr [esp+18h], eax
        jmp     L_4b1f76
L_4b1f69:
        push    -1
        mov     ecx, ebp
        call    CountObjectsByType
        mov     dword ptr [esp+18h], eax
L_4b1f76:
        mov     esi, dword ptr [esp+30h]
        mov     edi, 1770h
L_4b1f7f:
        push    edi
        mov     ecx, esi
        call    RemoveObjectByKey
        inc     edi
        cmp     edi, 178ch
        jl      L_4b1f7f
        mov     edi, 0c738h
L_4b1f95:
        lea     ebx, [edi-3e8h]
        mov     ecx, esi
        push    ebx
        call    GetRecordByKeyPtr
        test    eax, eax
        je      L_4b1faf
        push    ebx
        mov     ecx, esi
        call    UI_RemoveObject
L_4b1faf:
        push    edi
        mov     ecx, esi
        call    GetRecordByKeyPtr
        test    eax, eax
        je      L_4b1fc3
        push    edi
        mov     ecx, esi
        call    UI_RemoveObject
L_4b1fc3:
        inc     edi
        lea     edx, [edi-0c738h]
        cmp     edx, 7
        jl      L_4b1f95
        mov     ecx, dword ptr [esp+18h]
        mov     eax, 7
        cmp     ecx, eax
        jle     L_4b1fe2
        mov     dword ptr [esp+18h], eax
        jmp     L_4b1fea
L_4b1fe2:
        mov     dword ptr [esp+34h], 0
L_4b1fea:
        mov     eax, dword ptr [esp+18h]
        test    eax, eax
        jle     L_4b2221
        mov     ecx, dword ptr [esp+34h]
        mov     eax, 1794h
        add     ebp, 1500h
        sub     eax, ecx
        mov     dword ptr [esp+28h], ebp
        mov     ebp, 0c350h
        mov     dword ptr [esp+20h], 0
        mov     dword ptr [esp+30h], 1770h
        mov     dword ptr [esp+24h], eax
        jmp     L_4b202a
L_4b2026:
        mov     eax, dword ptr [esp+24h]
L_4b202a:
        mov     ecx, dword ptr [esp+34h]
        lea     edi, [ecx+ebp-0c350h]
        mov     ecx, dword ptr [esp+40h]
        cmp     edi, ecx
        jne     L_4b204a
        lea     edx, [edi+eax]
        mov     ecx, esi
        push    edx
        call    ShowChildByID
        jmp     L_4b2054
L_4b204a:
        add     eax, edi
        mov     ecx, esi
        push    eax
        call    RemoveObjectByKey
L_4b2054:
        mov     ecx, dword ptr [esp+28h]
        push    0
        push    edi
        call    IDMap_Lookup
        mov     ebx, eax
        lea     ecx, [esp+3ch]
        lea     edx, [esp+38h]
        push    ecx
        mov     edi, dword ptr [ebx+4]
        push    edx
        inc     edi
        push    45ah
        mov     ecx, esi
        and     edi, 7
        call    GetPairByKey
        mov     eax, dword ptr [esp+3ch]
        mov     ecx, dword ptr [esp+20h]
        lea     edx, [eax+ecx+1]
        mov     ecx, dword ptr [esp+38h]
        lea     eax, [edi+edi*4]
        mov     dword ptr [esp+3ch], edx
        lea     edx, [ecx+eax*4+1]
        xor     ecx, ecx
        mov     dword ptr [esp+38h], edx
        mov     eax, dword ptr [ebx]
        mov     cl, byte ptr [eax+824h]
        mov     eax, ecx
        cmp     eax, 3
        ja      L_4b2146
        jmp     dword ptr [jt_4b222c+eax*4]
        mov     edx, dword ptr [esp+30h]
        push    1792h
        add     edx, 2
        mov     ecx, esi
        mov     dword ptr [esp+20h], edx
        call    GetButtonSprite
        mov     dword ptr [esp+10h], eax
        push    1793h
        jmp     L_4b213b
        mov     eax, dword ptr [esp+30h]
        push    178ch
        mov     ecx, esi
        mov     dword ptr [esp+20h], eax
        call    GetButtonSprite
        mov     dword ptr [esp+10h], eax
        push    178dh
        jmp     L_4b213b
        mov     ecx, dword ptr [esp+30h]
        push    1790h
        inc     ecx
        mov     dword ptr [esp+20h], ecx
        mov     ecx, esi
        call    GetButtonSprite
        mov     dword ptr [esp+10h], eax
        push    1791h
        jmp     L_4b213b
        mov     edx, dword ptr [esp+30h]
        push    178eh
        add     edx, 3
        mov     ecx, esi
        mov     dword ptr [esp+20h], edx
        call    GetButtonSprite
        mov     dword ptr [esp+10h], eax
        push    178fh
L_4b213b:
        mov     ecx, esi
        call    GetButtonSprite
        mov     dword ptr [esp+14h], eax
L_4b2146:
        mov     ebx, dword ptr [esp+1ch]
        mov     ecx, esi
        push    ebx
        call    ShowChildByID
        push    0
        push    7
        push    0
        push    ebx
        mov     ecx, esi
        call    Slider_SetRange
        push    0
        push    edi
        push    ebx
        mov     ecx, esi
        call    Slider_SetValue
        mov     eax, dword ptr [esp+10h]
        mov     ecx, dword ptr [esp+3ch]
        mov     edx, dword ptr [esp+38h]
        push    0
        test    edi, edi
        push    eax
        push    ecx
        jle     L_4b2184
        add     edx, -14h
        jmp     L_4b218a
L_4b2184:
        add     edx, 8ch
L_4b218a:
        push    edx
        push    ebp
        mov     ecx, esi
        call    CreateMovieWindow
        mov     eax, dword ptr [esp+14h]
        mov     ecx, dword ptr [esp+3ch]
        mov     edx, dword ptr [esp+38h]
        push    0
        cmp     edi, 7
        push    eax
        lea     edi, [ebp+3e8h]
        push    ecx
        jge     L_4b21b3
        add     edx, 14h
        jmp     L_4b21b9
L_4b21b3:
        add     edx, -8ch
L_4b21b9:
        push    edx
        push    edi
        mov     ecx, esi
        call    CreateMovieWindow
        mov     ecx, esi
        call    GetFieldF0
        dec     eax
        mov     ecx, esi
        push    eax
        push    ebp
        call    MoveElementToIndex
        mov     ecx, esi
        call    GetFieldF0
        dec     eax
        mov     ecx, esi
        push    eax
        push    edi
        call    MoveElementToIndex
        push    0
        push    ebp
        mov     ecx, esi
        call    SetField14ByKey
        push    0
        push    edi
        mov     ecx, esi
        call    SetField14ByKey
        mov     ebx, dword ptr [esp+20h]
        mov     edi, dword ptr [esp+30h]
        mov     ecx, dword ptr [esp+18h]
        add     ebx, 0ah
        add     edi, 4
        inc     ebp
        mov     dword ptr [esp+20h], ebx
        mov     dword ptr [esp+30h], edi
        lea     eax, [ebp-0c350h]
        cmp     eax, ecx
        jl      L_4b2026
L_4b2221:
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 1ch
        ret
    }
}
}
