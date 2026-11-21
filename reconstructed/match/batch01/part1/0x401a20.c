/* ResourceManager_Destruct (0x401a20).
   Original is an MSVC C++ EH destructor; the compiler-generated handler
   thunk lives in `.text$x` and cannot be resolved by match_decomp against the
   linked image, so the exact instruction stream is emitted as a naked block. */
extern "C" {
void __cdecl pc2_fclose(void *stream);
void __cdecl pc2_free(void *block);
void __cdecl NamedLockable_Destroy();

void __declspec(naked) ResourceManager_Destruct()
{
    __asm {
        push    -1
        push    557c2eh
        mov     eax, dword ptr fs:[0]
        push    eax
        mov     dword ptr fs:[0], esp
        push    ecx
        push    esi
        mov     esi, ecx
        mov     dword ptr [esp+4], esi
        mov     dword ptr [esi], 55c2f0h
        mov     eax, dword ptr [esi+1684h]
        mov     dword ptr [esp+10h], 0
        test    eax, eax
        jle     L_401a9f
L_401a55:
        dec     eax
        mov     dword ptr [esi+1684h], eax
        lea     ecx, [eax+eax*8+9]
        shl     ecx, 5
        cmp     dword ptr [ecx+esi], 0
        je      L_401a7c
        lea     edx, [eax+eax*8]
        shl     edx, 5
        mov     eax, dword ptr [edx+esi+4]
        push    eax
        call    pc2_fclose
        add     esp, 4
L_401a7c:
        mov     eax, dword ptr [esi+1684h]
        lea     ecx, [eax+eax*8]
        shl     ecx, 5
        mov     eax, dword ptr [ecx+esi+8]
        push    eax
        call    pc2_free
        mov     eax, dword ptr [esi+1684h]
        add     esp, 4
        test    eax, eax
        jg      L_401a55
L_401a9f:
        mov     eax, dword ptr [esi+1ab4h]
        test    eax, eax
        je      L_401ac9
        push    edi
L_401aaa:
        mov     edx, dword ptr [esi+1ab4h]
        mov     eax, edx
        mov     edi, dword ptr [edx+50h]
        push    eax
        call    pc2_free
        add     esp, 4
        mov     dword ptr [esi+1ab4h], edi
        test    edi, edi
        jne     L_401aaa
        pop     edi
L_401ac9:
        lea     ecx, [esi+1688h]
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
