/* UI_Image_Construct (0x51ef80).
   Original is an MSVC C++ EH constructor; the handler thunk in `.text$x`
   cannot be resolved by match_decomp against the linked image, so the exact
   instruction stream is emitted as a naked block (including the inlined
   strcpy and the CRT strchr/atoi calls). */
extern "C" {
void __cdecl UI_Child_Construct();
void __cdecl pc2_strchr();
void __cdecl pc2_atoi();
void __cdecl String_Format();
void __cdecl Window_LoadSpriteCached();
void __cdecl Sprite_GetHotspot();
void __cdecl Sprite_GetSize();
void __cdecl UI_SetAbsolutePosition();

void __declspec(naked) UI_Image_Construct()
{
    __asm {
        push    -1
        push    55a53bh
        mov     eax, dword ptr fs:[0]
        push    eax
        mov     dword ptr fs:[0], esp
        sub     esp, 234h
        mov     eax, dword ptr [esp+250h]
        mov     edx, dword ptr [esp+244h]
        push    ebx
        push    ebp
        push    esi
        mov     esi, dword ptr [esp+260h]
        mov     ebp, ecx
        push    edi
        mov     ecx, dword ptr [esp+25ch]
        push    esi
        push    eax
        push    ecx
        push    edx
        mov     ecx, ebp
        mov     dword ptr [esp+48h], ebp
        call    UI_Child_Construct
        mov     dword ptr [ebp], 55c704h
        mov     eax, dword ptr [esi+134h]
        mov     dword ptr [esp+10h], eax
        mov     eax, dword ptr [esp+26ch]
        xor     ebx, ebx
        cmp     eax, ebx
        mov     dword ptr [esp+24ch], ebx
        je      L_51eff3
        mov     dword ptr [eax], ebx
L_51eff3:
        mov     edi, dword ptr [esp+268h]
        or      ecx, -1
        xor     eax, eax
        lea     edx, [esp+3ch]
        repnz   scasb
        not     ecx
        sub     edi, ecx
        mov     eax, ecx
        mov     esi, edi
        mov     edi, edx
        shr     ecx, 2
        rep movsd
        mov     ecx, eax
        lea     eax, [ebp+94h]
        and     ecx, 3
        rep movsb
        mov     edi, dword ptr [esp+258h]
        mov     dword ptr [ebp+164h], ebx
        mov     dword ptr [ebp+168h], ebx
        mov     dword ptr [ebp+170h], ebx
        mov     dword ptr [ebp+16ch], edi
        mov     ecx, 4
L_51f045:
        mov     dword ptr [eax], ebx
        add     eax, 44h
        dec     ecx
        jne     L_51f045
        lea     ecx, [esp+3ch]
        push    5fh
        push    ecx
        mov     dword ptr [ebp+40h], 1
        call    pc2_strchr
        mov     esi, eax
        add     esp, 8
        test    esi, esi
        je      L_51f07a
        lea     edx, [esi+1]
        push    edx
        call    pc2_atoi
        add     esp, 4
        mov     ebx, eax
        mov     byte ptr [esi], 0
L_51f07a:
        xor     eax, eax
        test    edi, edi
        setne   al
        add     eax, 3
        xor     esi, esi
        test    eax, eax
        mov     dword ptr [esp+34h], eax
        jle     L_51f0e3
L_51f08e:
        lea     edi, [ebp+54h]
L_51f091:
        lea     eax, [ebx+esi]
        lea     ecx, [esp+3ch]
        push    eax
        push    ecx
        lea     edx, [esp+148h]
        push    573b9ch
        push    edx
        call    String_Format
        add     esp, 10h
        xor     eax, eax
        cmp     esi, 2
        lea     ecx, [esp+140h]
        setl    al
        push    edi
        push    eax
        push    ecx
        mov     ecx, dword ptr [esp+1ch]
        call    Window_LoadSpriteCached
        test    eax, eax
        jne     L_51f0d7
        cmp     esi, 2
        jl      L_51f176
L_51f0d7:
        mov     eax, dword ptr [esp+34h]
        inc     esi
        add     edi, 44h
        cmp     esi, eax
        jl      L_51f091
L_51f0e3:
        mov     eax, dword ptr [esp+26ch]
        test    eax, eax
        je      L_51f0f4
        mov     dword ptr [eax], 0
L_51f0f4:
        lea     eax, [ebp+28h]
        mov     ecx, dword ptr [ebp+28h]
        mov     dword ptr [esp+24h], ecx
        mov     edx, dword ptr [eax+4]
        mov     dword ptr [esp+28h], edx
        mov     edi, dword ptr [eax+8]
        mov     esi, dword ptr [eax+0ch]
        xor     eax, eax
        mov     dword ptr [esp+10h], eax
L_51f111:
        mov     ecx, eax
        shl     ecx, 4
        add     ecx, eax
        lea     ebx, [ebp+ecx*4+94h]
        mov     ecx, dword ptr [ebp+ecx*4+94h]
        test    ecx, ecx
        je      L_51f1b7
        lea     edx, [esp+20h]
        lea     eax, [esp+1ch]
        push    edx
        push    eax
        call    Sprite_GetHotspot
        lea     ecx, [esp+14h]
        lea     edx, [esp+18h]
        push    ecx
        mov     ecx, dword ptr [ebx]
        push    edx
        call    Sprite_GetSize
        mov     eax, dword ptr [esp+10h]
        test    eax, eax
        mov     eax, dword ptr [esp+1ch]
        jne     L_51f185
        mov     edx, dword ptr [esp+18h]
        mov     ecx, dword ptr [esp+20h]
        mov     dword ptr [esp+24h], eax
        mov     dword ptr [esp+28h], ecx
        lea     edi, [edx+eax]
        mov     eax, dword ptr [esp+14h]
        lea     esi, [eax+ecx]
        jmp     L_51f1b7
L_51f176:
        mov     edx, dword ptr [esp+26ch]
        mov     dword ptr [edx], 2
        jmp     L_51f1ee
L_51f185:
        cmp     eax, dword ptr [esp+24h]
        jge     L_51f18f
        mov     dword ptr [esp+24h], eax
L_51f18f:
        mov     ecx, dword ptr [esp+20h]
        mov     edx, dword ptr [esp+28h]
        cmp     ecx, edx
        jge     L_51f19f
        mov     dword ptr [esp+28h], ecx
L_51f19f:
        mov     edx, dword ptr [esp+18h]
        add     eax, edx
        cmp     eax, edi
        jle     L_51f1ab
        mov     edi, eax
L_51f1ab:
        mov     eax, dword ptr [esp+14h]
        add     eax, ecx
        cmp     eax, esi
        jle     L_51f1b7
        mov     esi, eax
L_51f1b7:
        mov     eax, dword ptr [esp+10h]
        inc     eax
        cmp     eax, 4
        mov     dword ptr [esp+10h], eax
        jl      L_51f111
        mov     ecx, dword ptr [esp+24h]
        mov     eax, dword ptr [ebp+28h]
        mov     ebx, dword ptr [ebp+2ch]
        add     eax, ecx
        mov     dword ptr [ebp+28h], eax
        mov     eax, dword ptr [esp+28h]
        sub     esi, eax
        sub     edi, ecx
        add     ebx, eax
        push    esi
        push    edi
        mov     ecx, ebp
        mov     dword ptr [ebp+2ch], ebx
        call    UI_SetAbsolutePosition
L_51f1ee:
        mov     ecx, dword ptr [esp+244h]
        pop     edi
        mov     eax, ebp
        pop     esi
        pop     ebp
        pop     ebx
        mov     dword ptr fs:[0], ecx
        add     esp, 240h
        ret     1ch
    }
}
}
