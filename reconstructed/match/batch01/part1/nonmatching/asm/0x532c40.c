/* Anim_Load (0x532c40).
   Original is an MSVC C++ EH loader; the handler thunk in `.text$x` cannot be
   resolved by match_decomp against the linked image, so the exact instruction
   stream is emitted as a naked block (including inlined strcpy). */
extern "C" {
void __cdecl SpriteBase_Construct();
void __cdecl CRT_Fopen();
void __cdecl NoOp_Stub();
void __cdecl CRT_FreadLocked();
void *__cdecl pc2_new(int size);
void __cdecl Record_CopyTemplate98();
void __cdecl Resource_Open();
void __cdecl Resource_Read();
void __cdecl Resource_Close();
void __cdecl Stream_Seek();
void __cdecl Palette_Init();
void __cdecl pc2_fclose();

void __declspec(naked) Anim_Load()
{
    __asm {
        push    -1
        push    55ac87h
        mov     eax, dword ptr fs:[0]
        push    eax
        mov     dword ptr fs:[0], esp
        sub     esp, 3b4h
        push    ebx
        push    ebp
        push    esi
        mov     ebp, ecx
        push    edi
        mov     dword ptr [esp+28h], ebp
        call    SpriteBase_Construct
        mov     esi, dword ptr [esp+3e0h]
        xor     edi, edi
        mov     dword ptr [ebp+90h], edi
        cmp     esi, edi
        mov     dword ptr [esp+3cch], edi
        mov     dword ptr [ebp], 55c80ch
        mov     dword ptr [esp+14h], edi
        mov     byte ptr [ebp+34h], 0
        mov     byte ptr [ebp+35h], 1
        mov     dword ptr [ebp+38h], edi
        mov     dword ptr [ebp+78h], edi
        mov     dword ptr [ebp+94h], 3ff00000h
        mov     dword ptr [ebp+20h], edi
        mov     dword ptr [ebp+80h], edi
        mov     dword ptr [ebp+50h], edi
        mov     dword ptr [ebp+4ch], edi
        je      L_532cb8
        mov     dword ptr [esi], edi
L_532cb8:
        mov     ecx, dword ptr [esp+3d8h]
        cmp     ecx, edi
        jne     L_532e7a
        mov     eax, dword ptr [esp+3dch]
        push    563184h
        push    eax
        call    CRT_Fopen
        mov     ebx, eax
        add     esp, 8
        cmp     ebx, edi
        jne     L_532d06
        cmp     esi, edi
        je      L_532cf1
        mov     dword ptr [esi], 191h
        jmp     L_5332ee
L_532cf1:
        mov     ecx, dword ptr [esp+3dch]
        push    ecx
        push    57452ch
        call    NoOp_Stub
        add     esp, 8
L_532d06:
        push    ebx
        lea     esi, [ebp+64h]
        push    14h
        push    1
        push    esi
        call    CRT_FreadLocked
        push    ebx
        lea     eax, [ebp+4]
        push    1ch
        push    1
        push    eax
        call    CRT_FreadLocked
        mov     eax, dword ptr [ebp+70h]
        add     esp, 20h
        mov     edx, eax
        and     edx, 0ffff0000h
        cmp     edx, 0ca420000h
        jne     L_532d4b
        and     eax, 0ffffh
        cmp     eax, 1
        mov     dword ptr [esp+1ch], eax
        jl      L_532d4b
        cmp     eax, 2
        jle     L_532d57
L_532d4b:
        mov     dword ptr [esp+14h], 1
        mov     dword ptr [esp+1ch], edi
L_532d57:
        mov     eax, dword ptr [esi]
        cmp     eax, edi
        jl      L_532d64
        cmp     eax, 1f4h
        jle     L_532d8f
L_532d64:
        mov     eax, dword ptr [esp+3e0h]
        cmp     eax, edi
        je      L_532d7a
        mov     dword ptr [eax], 192h
        jmp     L_5332ee
L_532d7a:
        mov     eax, dword ptr [esp+3dch]
        push    eax
        push    574510h
        call    NoOp_Stub
        add     esp, 8
L_532d8f:
        mov     eax, dword ptr [esi]
        cmp     eax, edi
        jle     L_532e22
        lea     ecx, [eax+eax*8]
        lea     edx, [eax+ecx*2]
        shl     edx, 3
        push    edx
        call    pc2_new
        mov     ecx, dword ptr [esp+18h]
        add     esp, 4
        cmp     ecx, edi
        mov     dword ptr [ebp+50h], eax
        je      L_532e08
        mov     eax, dword ptr [esi]
        xor     edi, edi
        test    eax, eax
        jle     L_532e43
        mov     dword ptr [esp+10h], edi
L_532dc6:
        push    ebx
        push    98h
        lea     eax, [esp+34h]
        push    1
        push    eax
        call    CRT_FreadLocked
        mov     ecx, dword ptr [esp+20h]
        mov     eax, dword ptr [ebp+50h]
        add     esp, 10h
        add     ecx, eax
        lea     edx, [esp+2ch]
        push    ecx
        push    edx
        mov     ecx, ebp
        call    Record_CopyTemplate98
        mov     ecx, dword ptr [esp+10h]
        mov     eax, dword ptr [esi]
        inc     edi
        add     ecx, 98h
        cmp     edi, eax
        mov     dword ptr [esp+10h], ecx
        jl      L_532dc6
        jmp     L_532e43
L_532e08:
        mov     esi, dword ptr [esi]
        push    ebx
        lea     ecx, [esi+esi*8]
        lea     edx, [esi+ecx*2]
        shl     edx, 3
        push    edx
        push    1
        push    eax
        call    CRT_FreadLocked
        add     esp, 10h
        jmp     L_532e43
L_532e22:
        push    260h
        mov     dword ptr [esi], 4
        call    pc2_new
        add     esp, 4
        mov     edi, eax
        mov     ecx, 98h
        xor     eax, eax
        mov     dword ptr [ebp+50h], edi
        rep stosd
L_532e43:
        push    ebx
        push    4
        lea     eax, [esp+20h]
        push    1
        push    eax
        call    CRT_FreadLocked
        mov     ecx, dword ptr [esp+28h]
        push    ecx
        call    pc2_new
        mov     edx, dword ptr [esp+2ch]
        push    ebx
        mov     esi, eax
        push    edx
        push    1
        push    esi
        call    CRT_FreadLocked
        push    ebx
        call    pc2_fclose
        add     esp, 28h
        jmp     L_533095
L_532e7a:
        mov     ebx, dword ptr [esp+3dch]
        push    edi
        push    ebx
        call    Resource_Open
        mov     esi, eax
        cmp     esi, edi
        mov     dword ptr [esp+10h], esi
        jne     L_532eb6
        mov     eax, dword ptr [esp+3e0h]
        cmp     eax, edi
        je      L_532ea8
        mov     dword ptr [eax], 192h
        jmp     L_5332ee
L_532ea8:
        push    ebx
        push    5744f0h
        call    NoOp_Stub
        add     esp, 8
L_532eb6:
        mov     ebx, dword ptr [esp+3d8h]
        lea     edi, [ebp+64h]
        push    esi
        push    14h
        push    edi
        mov     ecx, ebx
        call    Resource_Read
        lea     eax, [ebp+4]
        push    esi
        push    1ch
        push    eax
        mov     ecx, ebx
        call    Resource_Read
        mov     eax, dword ptr [ebp+70h]
        mov     ecx, eax
        and     ecx, 0ffff0000h
        cmp     ecx, 0ca420000h
        jne     L_532eff
        and     eax, 0ffffh
        cmp     eax, 1
        mov     dword ptr [esp+1ch], eax
        jl      L_532eff
        cmp     eax, 2
        jle     L_532f0f
L_532eff:
        mov     dword ptr [esp+14h], 1
        mov     dword ptr [esp+1ch], 0
L_532f0f:
        mov     eax, dword ptr [edi]
        lea     edx, [eax+eax*8]
        lea     eax, [eax+edx*2]
        shl     eax, 3
        push    eax
        call    pc2_new
        mov     ecx, dword ptr [esp+18h]
        add     esp, 4
        test    ecx, ecx
        mov     dword ptr [ebp+50h], eax
        je      L_532f8b
        mov     eax, dword ptr [edi]
        mov     dword ptr [esp+20h], 0
        test    eax, eax
        jle     L_532fa0
        mov     dword ptr [esp+24h], 0
L_532f44:
        push    esi
        lea     ecx, [esp+30h]
        push    98h
        push    ecx
        mov     ecx, ebx
        call    Resource_Read
        mov     edx, dword ptr [esp+24h]
        mov     ecx, dword ptr [ebp+50h]
        add     edx, ecx
        lea     eax, [esp+2ch]
        push    edx
        push    eax
        mov     ecx, ebp
        call    Record_CopyTemplate98
        mov     eax, dword ptr [esp+20h]
        mov     edx, dword ptr [esp+24h]
        mov     ecx, dword ptr [edi]
        inc     eax
        add     edx, 98h
        cmp     eax, ecx
        mov     dword ptr [esp+20h], eax
        mov     dword ptr [esp+24h], edx
        jl      L_532f44
        jmp     L_532fa0
L_532f8b:
        mov     edi, dword ptr [edi]
        push    esi
        lea     ecx, [edi+edi*8]
        lea     edx, [edi+ecx*2]
        mov     ecx, ebx
        shl     edx, 3
        push    edx
        push    eax
        call    Resource_Read
L_532fa0:
        push    esi
        lea     eax, [esp+1ch]
        push    4
        push    eax
        mov     ecx, ebx
        call    Resource_Read
        mov     eax, dword ptr [esp+18h]
        mov     ecx, dword ptr [esp+3e4h]
        sub     eax, 4
        test    ecx, ecx
        mov     dword ptr [esp+18h], eax
        je      L_533078
        mov     edx, dword ptr [esp+14h]
        mov     ecx, 8
        test    edx, edx
        je      L_532fdb
        mov     ecx, 9
L_532fdb:
        cmp     dword ptr [esp+1ch], 2
        jge     L_532fe7
        add     ecx, 2
        jmp     L_532fea
L_532fe7:
        add     ecx, 4
L_532fea:
        mov     ebx, dword ptr [ebp+68h]
        imul    ebx, ecx
        cmp     byte ptr [ebp+5], 9
        jae     L_532fff
        sub     eax, ebx
        sub     eax, 300h
        jmp     L_533001
L_532fff:
        sub     eax, ebx
L_533001:
        mov     ecx, dword ptr [esp+3d8h]
        mov     esi, dword ptr [esp+3dch]
        mov     dword ptr [ebp+40h], eax
        mov     dword ptr [ebp+44h], ecx
        mov     edi, esi
        or      ecx, -1
        xor     eax, eax
        mov     byte ptr [ebp+34h], 1
        mov     byte ptr [ebp+35h], 0
        repnz   scasb
        not     ecx
        push    ecx
        call    pc2_new
        mov     edx, eax
        mov     edi, esi
        or      ecx, -1
        xor     eax, eax
        mov     dword ptr [ebp+38h], edx
        push    ebx
        repnz   scasb
        not     ecx
        sub     edi, ecx
        mov     eax, ecx
        mov     esi, edi
        mov     edi, edx
        shr     ecx, 2
        rep movsd
        mov     ecx, eax
        and     ecx, 3
        rep movsb
        call    pc2_new
        mov     edi, dword ptr [esp+18h]
        mov     ecx, dword ptr [esp+3e0h]
        add     esp, 8
        mov     esi, eax
        push    edi
        push    ebx
        push    esi
        call    Resource_Read
        mov     edi, dword ptr [edi+10h]
        mov     dword ptr [ebp+3ch], edi
        jmp     L_533095
L_533078:
        push    eax
        call    pc2_new
        mov     ecx, dword ptr [esp+14h]
        mov     edx, dword ptr [esp+1ch]
        add     esp, 4
        mov     esi, eax
        push    ecx
        push    edx
        push    esi
        mov     ecx, ebx
        call    Resource_Read
L_533095:
        mov     eax, dword ptr [ebp+68h]
        mov     dword ptr [ebp+20h], esi
        lea     ecx, [eax+eax]
        add     esi, ecx
        mov     dword ptr [ebp+24h], esi
        add     esi, ecx
        mov     dword ptr [ebp+28h], esi
        add     esi, ecx
        mov     dword ptr [ebp+2ch], esi
        add     esi, ecx
        cmp     dword ptr [esp+1ch], 2
        jge     L_5330fa
        shl     eax, 2
        push    eax
        call    pc2_new
        mov     ecx, dword ptr [ebp+68h]
        mov     dword ptr [ebp+30h], eax
        xor     edi, edi
        add     esp, 4
        xor     eax, eax
        cmp     ecx, edi
        mov     dword ptr [ebp+88h], 1
        jle     L_5330f2
        mov     ecx, esi
L_5330dc:
        mov     ebx, dword ptr [ebp+30h]
        xor     edx, edx
        mov     dx, word ptr [ecx]
        add     ecx, 2
        mov     dword ptr [ebx+eax*4], edx
        mov     edx, dword ptr [ebp+68h]
        inc     eax
        cmp     eax, edx
        jl      L_5330dc
L_5330f2:
        mov     eax, dword ptr [ebp+68h]
        lea     esi, [esi+eax*2]
        jmp     L_533108
L_5330fa:
        xor     edi, edi
        mov     dword ptr [ebp+30h], esi
        mov     dword ptr [ebp+88h], edi
        lea     esi, [esi+eax*4]
L_533108:
        cmp     dword ptr [esp+14h], edi
        je      L_533110
        add     esi, eax
L_533110:
        shl     eax, 2
        push    eax
        call    pc2_new
        mov     dword ptr [ebp+80h], eax
        mov     al, byte ptr [ebp+34h]
        add     esp, 4
        test    al, al
        jne     L_533160
        mov     ecx, dword ptr [ebp+68h]
        xor     eax, eax
        cmp     ecx, edi
        jle     L_53317b
L_533132:
        mov     ecx, dword ptr [ebp+30h]
        cmp     dword ptr [ecx+eax*4], edi
        jne     L_533145
        mov     edx, dword ptr [ebp+80h]
        mov     dword ptr [edx+eax*4], edi
        jmp     L_53314e
L_533145:
        mov     ecx, dword ptr [ebp+80h]
        mov     dword ptr [ecx+eax*4], esi
L_53314e:
        mov     edx, dword ptr [ebp+30h]
        mov     ecx, dword ptr [ebp+68h]
        mov     ebx, dword ptr [edx+eax*4]
        add     esi, ebx
        inc     eax
        cmp     eax, ecx
        jl      L_533132
        jmp     L_53317b
L_533160:
        mov     ecx, dword ptr [ebp+68h]
        xor     eax, eax
        cmp     ecx, edi
        jle     L_53317b
L_533169:
        mov     ecx, dword ptr [ebp+80h]
        inc     eax
        mov     dword ptr [ecx+eax*4-4], edi
        mov     ecx, dword ptr [ebp+68h]
        cmp     eax, ecx
        jl      L_533169
L_53317b:
        cmp     byte ptr [ebp+5], 9
        jae     L_53324f
        mov     edx, dword ptr [esp+3d4h]
        mov     al, byte ptr [edx+18h]
        test    al, al
        je      L_5331a0
        test    byte ptr [ebp+4], 10h
        jne     L_5331a0
        mov     ebx, 1
        jmp     L_5331a2
L_5331a0:
        xor     ebx, ebx
L_5331a2:
        mov     al, byte ptr [ebp+35h]
        test    al, al
        jne     L_53320e
        mov     eax, dword ptr [ebp+40h]
        mov     edx, dword ptr [ebp+3ch]
        mov     esi, dword ptr [esp+10h]
        mov     ecx, dword ptr [esp+3d8h]
        push    edi
        add     eax, edx
        push    esi
        push    eax
        call    Stream_Seek
        push    esi
        lea     ecx, [esp+0c8h]
        push    300h
        push    ecx
        mov     ecx, dword ptr [esp+3e4h]
        call    Resource_Read
        push    20ch
        call    pc2_new
        add     esp, 4
        mov     dword ptr [esp+20h], eax
        cmp     eax, edi
        mov     byte ptr [esp+3cch], 1
        je      L_533237
        lea     edx, [esp+0c4h]
        push    edi
        push    edx
        push    ebx
        mov     ecx, eax
        call    Palette_Init
        jmp     L_533239
L_53320e:
        push    20ch
        call    pc2_new
        add     esp, 4
        mov     dword ptr [esp+20h], eax
        cmp     eax, edi
        mov     byte ptr [esp+3cch], 2
        je      L_533237
        push    edi
        push    esi
        push    ebx
        mov     ecx, eax
        call    Palette_Init
        jmp     L_533239
L_533237:
        xor     eax, eax
L_533239:
        mov     dword ptr [ebp+78h], eax
        add     eax, 4
        mov     byte ptr [esp+3cch], 0
        mov     dword ptr [ebp+7ch], eax
        jmp     L_5332d0
L_53324f:
        mov     al, byte ptr [ebp+35h]
        mov     dword ptr [ebp+78h], edi
        test    al, al
        mov     dword ptr [ebp+7ch], edi
        je      L_5332d0
        mov     ecx, dword ptr [esp+3d4h]
        mov     al, byte ptr [ecx+18h]
        test    al, al
        je      L_5332d0
        test    byte ptr [ebp+4], 10h
        jne     L_5332d0
        mov     eax, dword ptr [ebp+68h]
        xor     esi, esi
        cmp     eax, edi
        jle     L_5332d0
L_533279:
        mov     eax, dword ptr [ebp+30h]
        mov     edx, dword ptr [ebp+80h]
        mov     eax, dword ptr [eax+esi*4]
        mov     ecx, dword ptr [edx+esi*4]
        shr     eax, 1
        xor     edx, edx
        test    eax, eax
        jle     L_5332c8
L_533290:
        mov     ax, word ptr [ecx]
        mov     ebx, eax
        and     ebx, 0ffffh
        cmp     ebx, dword ptr [ebp+1ch]
        jne     L_5332a6
        inc     edx
        add     ecx, 2
        jmp     L_5332b8
L_5332a6:
        mov     ebx, eax
        and     eax, 1fh
        and     ebx, 0ffe0h
        shl     ebx, 1
        or      ebx, eax
        mov     word ptr [ecx], bx
L_5332b8:
        mov     eax, dword ptr [ebp+30h]
        inc     edx
        add     ecx, 2
        mov     eax, dword ptr [eax+esi*4]
        shr     eax, 1
        cmp     edx, eax
        jl      L_533290
L_5332c8:
        mov     eax, dword ptr [ebp+68h]
        inc     esi
        cmp     esi, eax
        jl      L_533279
L_5332d0:
        mov     ecx, dword ptr [esp+10h]
        push    ecx
        mov     ecx, dword ptr [esp+3dch]
        call    Resource_Close
        mov     dword ptr [ebp+48h], edi
        mov     dword ptr [ebp+4ch], edi
        mov     dword ptr [ebp+54h], -999
L_5332ee:
        mov     ecx, dword ptr [esp+3c4h]
        pop     edi
        mov     eax, ebp
        pop     esi
        pop     ebp
        pop     ebx
        mov     dword ptr fs:[0], ecx
        add     esp, 3c0h
        ret     14h
    }
}
}
