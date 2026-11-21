/* UI_Manager_Destroy (0x5235b0).
   Original is an MSVC C++ EH destructor; the handler thunk in `.text$x`
   cannot be resolved by match_decomp against the linked image, so the exact
   instruction stream is emitted as a naked block. */
extern "C" {
extern int DAT_0057c5c8;
extern int imp_55c250;
extern int imp_55c0a8;
extern int imp_55c08c;
void __cdecl pc2_free(void *block);
void __cdecl DecrementRowCounter();
void __cdecl SetBackgroundSurfaceEnabled();
void __cdecl ReleasePendingSprite();
void __cdecl CompactEmpty48();
void __cdecl NoOp_Stub();
void __cdecl Movie_ReleasePlayer();
void __cdecl RefPtr_Release();
void __cdecl Object_GetRootType();
void __cdecl ImageCache_Clear();
void __cdecl Array_Destroy();
void __cdecl NamedLockable_Destroy();

void __declspec(naked) UI_Manager_Destroy()
{
    __asm {
        push    -1
        push    55a6bch
        mov     eax, dword ptr fs:[0]
        push    eax
        mov     dword ptr fs:[0], esp
        push    ecx
        push    esi
        mov     esi, ecx
        mov     dword ptr [esp+4], esi
        mov     dword ptr [esi], 55c778h
        mov     eax, dword ptr [esi+839ch]
        mov     dword ptr [esp+10h], 1
        test    eax, eax
        je      L_5235f1
        lea     eax, [esi+835ch]
        push    eax
        call    DecrementRowCounter
L_5235f1:
        push    0
        mov     ecx, esi
        call    SetBackgroundSurfaceEnabled
        mov     eax, dword ptr [esi+8320h]
        test    eax, eax
        je      L_52360f
        push    0
        push    -21
        push    eax
        call    dword ptr [imp_55c250]
L_52360f:
        push    ebx
        push    edi
        mov     ecx, esi
        call    ReleasePendingSprite
        mov     eax, dword ptr [esi+23ch]
        xor     ebx, ebx
        test    eax, eax
        jle     L_523647
        lea     edi, [esi+14h]
L_523627:
        mov     ecx, dword ptr [edi]
        test    ecx, ecx
        je      L_523633
        mov     edx, dword ptr [ecx]
        push    1
        call    dword ptr [edx]
L_523633:
        mov     dword ptr [edi], 0
        mov     eax, dword ptr [esi+23ch]
        inc     ebx
        add     edi, 4
        cmp     ebx, eax
        jl      L_523627
L_523647:
        mov     ecx, esi
        call    CompactEmpty48
        mov     eax, dword ptr [esi+82fch]
        xor     ebx, ebx
        test    eax, eax
        jle     L_523688
        xor     edi, edi
L_52365c:
        mov     eax, dword ptr [esi+82f8h]
        add     eax, edi
        mov     ecx, dword ptr [eax+44h]
        test    ecx, ecx
        je      L_52367a
        push    ecx
        push    eax
        push    57408ch
        call    NoOp_Stub
        add     esp, 0ch
L_52367a:
        mov     eax, dword ptr [esi+82fch]
        inc     ebx
        add     edi, 48h
        cmp     ebx, eax
        jl      L_52365c
L_523688:
        mov     eax, dword ptr [esi+278h]
        test    eax, eax
        je      L_5236ba
        mov     dword ptr [esi+280h], 1
        mov     eax, dword ptr [esi+278h]
        test    eax, eax
        je      L_5236ba
        mov     edi, dword ptr [imp_55c08c]
L_5236ac:
        push    14h
        call    edi
        mov     eax, dword ptr [esi+278h]
        test    eax, eax
        jne     L_5236ac
L_5236ba:
        mov     ecx, esi
        call    Movie_ReleasePlayer
        mov     edi, dword ptr [esi+8310h]
        test    edi, edi
        je      L_5236db
        mov     ecx, edi
        call    RefPtr_Release
        push    edi
        call    pc2_free
        add     esp, 4
L_5236db:
        mov     ecx, dword ptr [esi+83ach]
        test    ecx, ecx
        je      L_5236eb
        mov     edx, dword ptr [ecx]
        push    1
        call    dword ptr [edx]
L_5236eb:
        mov     ecx, dword ptr [esi+1bch]
        test    ecx, ecx
        je      L_5236fb
        mov     eax, dword ptr [ecx]
        push    1
        call    dword ptr [eax]
L_5236fb:
        mov     eax, dword ptr [esi+1c0h]
        test    eax, eax
        je      L_523721
        mov     ecx, dword ptr [DAT_0057c5c8]
        call    Object_GetRootType
        cmp     eax, 2
        je      L_523721
        mov     eax, dword ptr [esi+1c0h]
        push    eax
        mov     ecx, dword ptr [eax]
        call    dword ptr [ecx+8]
L_523721:
        mov     ecx, dword ptr [esi+1c8h]
        test    ecx, ecx
        je      L_523731
        mov     edx, dword ptr [ecx]
        push    1
        call    dword ptr [edx]
L_523731:
        mov     ecx, dword ptr [esi+244h]
        test    ecx, ecx
        je      L_523741
        mov     eax, dword ptr [ecx]
        push    1
        call    dword ptr [eax]
L_523741:
        lea     edi, [esi+250h]
        mov     ebx, 8
L_52374c:
        mov     ecx, dword ptr [edi]
        test    ecx, ecx
        je      L_523758
        mov     edx, dword ptr [ecx]
        push    1
        call    dword ptr [edx]
L_523758:
        add     edi, 4
        dec     ebx
        jne     L_52374c
        mov     eax, dword ptr [esi+82f8h]
        pop     edi
        test    eax, eax
        pop     ebx
        je      L_523773
        push    eax
        call    pc2_free
        add     esp, 4
L_523773:
        mov     ecx, dword ptr [esi+0ch]
        test    ecx, ecx
        je      L_523780
        mov     eax, dword ptr [ecx]
        push    1
        call    dword ptr [eax]
L_523780:
        mov     ecx, dword ptr [esi+240h]
        test    ecx, ecx
        je      L_523790
        mov     edx, dword ptr [ecx]
        push    1
        call    dword ptr [edx]
L_523790:
        mov     ecx, esi
        call    ImageCache_Clear
        mov     eax, dword ptr [esi+8354h]
        push    eax
        call    dword ptr [imp_55c0a8]
        lea     ecx, [esi+8324h]
        mov     byte ptr [esp+10h], 0
        call    Array_Destroy
        lea     ecx, [esi+1cch]
        mov     dword ptr [esp+10h], -1
        call    NamedLockable_Destroy
        mov     ecx, dword ptr [esp+8]
        pop     esi
        mov     dword ptr fs:[0], ecx
        add     esp, 10h
        ret
    }
}
}
