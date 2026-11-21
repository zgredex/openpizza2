/* FreePlaySubmenu_InitSaveGamePage (0x4ce450).
   Original is an MSVC C++ EH frame around `new List` / `new UI_ListEntry`;
   the handler thunk in `.text$x` cannot be resolved by match_decomp against
   the linked image, so the exact instruction stream is emitted as a naked
   block. */
extern "C" {
extern int DAT_00582464;
extern int DAT_00581ac0;
extern int DAT_0057df88;
extern int DAT_0057df8c;
extern int DAT_00581ab4;
void *__cdecl pc2_new(int size);
void __cdecl UI_SetPosition();
void __cdecl Text_SetText();
void __cdecl List_Construct();
void __cdecl SaveGame_Scan();
void __cdecl RemoveObjectByKey();
void __cdecl Slider_SetRange();
void __cdecl Slider_SetValue();
void __cdecl Slider_SetChangeNotify();
void __cdecl UI_ListEntry_Construct();
void __cdecl List_Add();
void __cdecl FillSaveGameRows();

void __declspec(naked) FreePlaySubmenu_InitSaveGamePage()
{
    __asm {
        mov     eax, dword ptr fs:[0]
        push    -1
        push    558cd6h
        push    eax
        mov     dword ptr fs:[0], esp
        push    ebx
        push    esi
        mov     esi, dword ptr [esp+18h]
        push    edi
        push    0
        push    4ce3b0h
        mov     ecx, esi
        call    UI_SetPosition
        mov     eax, dword ptr [DAT_00582464]
        mov     ecx, esi
        push    eax
        push    440h
        call    Text_SetText
        mov     ecx, dword ptr [DAT_00581ac0]
        push    ecx
        push    441h
        mov     ecx, esi
        call    Text_SetText
        push    1ch
        call    pc2_new
        add     esp, 4
        mov     dword ptr [esp+1ch], eax
        test    eax, eax
        mov     dword ptr [esp+14h], 0
        je      L_4ce4c4
        push    0
        mov     ecx, eax
        call    List_Construct
        jmp     L_4ce4c6
L_4ce4c4:
        xor     eax, eax
L_4ce4c6:
        push    0
        push    eax
        mov     dword ptr [esp+1ch], -1
        mov     dword ptr [DAT_0057df88], eax
        mov     dword ptr [DAT_0057df8c], 0
        call    SaveGame_Scan
        mov     edx, dword ptr [DAT_0057df88]
        add     esp, 8
        mov     eax, dword ptr [edx+14h]
        lea     ebx, [eax-1]
        test    ebx, ebx
        jle     L_4ce574
        cmp     ebx, 13h
        jge     L_4ce539
        push    462h
        mov     ecx, esi
        call    RemoveObjectByKey
        mov     edi, 7e2h
        add     ebx, 7d0h
        cmp     ebx, edi
        jge     L_4ce5e3
L_4ce51c:
        push    edi
        mov     ecx, esi
        call    RemoveObjectByKey
        lea     eax, [edi+64h]
        mov     ecx, esi
        push    eax
        call    RemoveObjectByKey
        dec     edi
        cmp     edi, ebx
        jg      L_4ce51c
        jmp     L_4ce5e3
L_4ce539:
        lea     eax, [ebx+ebx*4-5ah]
        push    1
        lea     ecx, [eax+eax*4]
        shl     ecx, 2
        push    ecx
        push    0
        push    462h
        mov     ecx, esi
        call    Slider_SetRange
        push    0
        push    0
        push    462h
        mov     ecx, esi
        call    Slider_SetValue
        push    1
        push    462h
        mov     ecx, esi
        call    Slider_SetChangeNotify
        jmp     L_4ce5e3
L_4ce574:
        mov     edi, 7e2h
L_4ce579:
        push    edi
        mov     ecx, esi
        call    RemoveObjectByKey
        lea     edx, [edi+64h]
        mov     ecx, esi
        push    edx
        call    RemoveObjectByKey
        dec     edi
        cmp     edi, 7d0h
        jg      L_4ce579
        push    462h
        mov     ecx, esi
        call    RemoveObjectByKey
        push    58h
        call    pc2_new
        add     esp, 4
        mov     dword ptr [esp+1ch], eax
        test    eax, eax
        mov     dword ptr [esp+14h], 1
        je      L_4ce5cd
        mov     ecx, dword ptr [DAT_00581ab4]
        push    -1
        push    ecx
        mov     ecx, eax
        call    UI_ListEntry_Construct
        jmp     L_4ce5cf
L_4ce5cd:
        xor     eax, eax
L_4ce5cf:
        mov     ecx, dword ptr [DAT_0057df88]
        push    eax
        mov     dword ptr [esp+18h], -1
        call    List_Add
L_4ce5e3:
        mov     edx, dword ptr [DAT_0057df8c]
        push    edx
        push    esi
        call    FillSaveGameRows
        mov     ecx, dword ptr [esp+14h]
        add     esp, 8
        mov     dword ptr fs:[0], ecx
        pop     edi
        pop     esi
        pop     ebx
        add     esp, 0ch
        ret
    }
}
}
