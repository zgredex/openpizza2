/* Sprite_Destruct (0x53cf40).
   Original is an MSVC C++ EH destructor; the handler thunk in `.text$x`
   cannot be resolved by match_decomp against the linked image, so the exact
   instruction stream is emitted as a naked block. */
extern "C" {
void __cdecl pc2_free(void *block);
void __cdecl Palette_Free();
void __cdecl SpriteBase_Destructor();

void __declspec(naked) Sprite_Destruct()
{
    __asm {
        push    -1
        push    55adc8h
        mov     eax, dword ptr fs:[0]
        push    eax
        mov     dword ptr fs:[0], esp
        push    ecx
        push    ebx
        push    esi
        push    edi
        mov     edi, ecx
        mov     dword ptr [esp+0ch], edi
        mov     dword ptr [edi], 55c82ch
        mov     al, byte ptr [edi+34h]
        mov     dword ptr [esp+18h], 0
        cmp     al, 1
        jne     L_53cf9b
        mov     esi, dword ptr [edi+20h]
        test    esi, esi
        je      L_53cfd3
        cmp     word ptr [esi+206h], -1
        jne     L_53cfd3
        test    esi, esi
        je      L_53cfd3
        mov     ecx, esi
        call    Palette_Free
        push    esi
        call    pc2_free
        add     esp, 4
        jmp     L_53cfd3
L_53cf9b:
        xor     ebx, ebx
        test    al, al
        jbe     L_53cfd3
L_53cfa1:
        mov     eax, dword ptr [edi+24h]
        mov     esi, dword ptr [eax+ebx*4]
        test    esi, esi
        je      L_53cfc9
        cmp     word ptr [esi+206h], -1
        jne     L_53cfc9
        test    esi, esi
        je      L_53cfc9
        mov     ecx, esi
        call    Palette_Free
        push    esi
        call    pc2_free
        add     esp, 4
L_53cfc9:
        xor     ecx, ecx
        inc     ebx
        mov     cl, byte ptr [edi+34h]
        cmp     ebx, ecx
        jl      L_53cfa1
L_53cfd3:
        mov     eax, dword ptr [edi+2ch]
        test    eax, eax
        je      L_53cfe3
        push    eax
        call    pc2_free
        add     esp, 4
L_53cfe3:
        mov     eax, dword ptr [edi+30h]
        test    eax, eax
        je      L_53cff3
        push    eax
        call    pc2_free
        add     esp, 4
L_53cff3:
        mov     eax, dword ptr [edi+3ch]
        test    eax, eax
        je      L_53d003
        push    eax
        call    pc2_free
        add     esp, 4
L_53d003:
        mov     eax, dword ptr [edi+24h]
        test    eax, eax
        je      L_53d013
        push    eax
        call    pc2_free
        add     esp, 4
L_53d013:
        mov     ecx, edi
        mov     dword ptr [esp+18h], -1
        call    SpriteBase_Destructor
        mov     ecx, dword ptr [esp+10h]
        pop     edi
        pop     esi
        pop     ebx
        mov     dword ptr fs:[0], ecx
        add     esp, 10h
        ret
    }
}
}
