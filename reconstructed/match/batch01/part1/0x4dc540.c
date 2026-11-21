/* Object_SetFacadeAndLogoVariant (0x4dc540).
   Reconstructed in source form first, but C2's scheduler refuses the original
   load/branch order for the two variant stores; the exact original instruction
   stream is emitted here as a naked block. */
extern "C" {
extern int DAT_0057c670;
void __cdecl CS_Enter();
void __cdecl CS_Leave();
void __cdecl Game_FindCityIndex();
void __cdecl String_Find();
void __cdecl Record_SelectVariant();
void __cdecl Record_ClearFlags48();

void __declspec(naked) Object_SetFacadeAndLogoVariant()
{
    __asm {
        push    ecx
        mov     eax, dword ptr [DAT_0057c670]
        push    ebx
        push    esi
        mov     esi, ecx
        mov     ecx, dword ptr [eax+248h]
        push    edi
        call    CS_Enter
        mov     edx, dword ptr [esp+18h]
        mov     ecx, dword ptr [esi+0fa8h]
        mov     esi, dword ptr [esp+1ch]
        mov     eax, dword ptr [edx+24h]
        mov     ecx, dword ptr [ecx+4ch]
        lea     eax, [eax+eax*2]
        lea     ebx, [ecx+eax*4]
        mov     ecx, esi
        call    Game_FindCityIndex
        mov     edx, dword ptr [esi+1e0h]
        mov     dword ptr [esp+1ch], eax
        mov     eax, dword ptr [ebx+8]
        xor     edi, edi
        mov     dword ptr [esp+0ch], edx
        mov     dword ptr [esp+18h], edi
        cmp     dword ptr [eax+14h], edi
        jle     L_4dc646
        push    ebp
L_4dc598:
        mov     eax, dword ptr [eax+18h]
        add     eax, edi
        mov     esi, dword ptr [eax+8]
        mov     ebp, dword ptr [eax]
        cmp     byte ptr [esi], 2
        jne     L_4dc62b
        lea     eax, [esi+4]
        push    56d05ch
        push    eax
        call    String_Find
        add     esp, 8
        test    eax, eax
        je      L_4dc5eb
        mov     ecx, dword ptr [ebx+8]
        mov     eax, dword ptr [esp+18h]
        test    eax, eax
        mov     edx, dword ptr [ecx+18h]
        mov     dword ptr [edx+edi+4], eax
        je      L_4dc5e2
        mov     eax, dword ptr [esp+20h]
        mov     ecx, dword ptr [esi+48h]
        push    eax
        push    ebp
        call    Record_SelectVariant
        jmp     L_4dc5eb
L_4dc5e2:
        mov     ecx, dword ptr [esi+48h]
        push    ebp
        call    Record_ClearFlags48
L_4dc5eb:
        lea     eax, [esi+4]
        push    56d054h
        push    eax
        call    String_Find
        add     esp, 8
        test    eax, eax
        je      L_4dc62b
        mov     ecx, dword ptr [ebx+8]
        mov     eax, dword ptr [esp+18h]
        test    eax, eax
        mov     edx, dword ptr [ecx+18h]
        mov     dword ptr [edx+edi+4], eax
        je      L_4dc622
        mov     eax, dword ptr [esp+10h]
        mov     ecx, dword ptr [esi+48h]
        push    eax
        push    ebp
        call    Record_SelectVariant
        jmp     L_4dc62b
L_4dc622:
        mov     ecx, dword ptr [esi+48h]
        push    ebp
        call    Record_ClearFlags48
L_4dc62b:
        mov     eax, dword ptr [ebx+8]
        mov     ecx, dword ptr [esp+1ch]
        inc     ecx
        add     edi, 0ch
        mov     edx, dword ptr [eax+14h]
        mov     dword ptr [esp+1ch], ecx
        cmp     ecx, edx
        jl      L_4dc598
        pop     ebp
L_4dc646:
        mov     ecx, dword ptr [DAT_0057c670]
        mov     ecx, dword ptr [ecx+248h]
        call    CS_Leave
        pop     edi
        pop     esi
        pop     ebx
        pop     ecx
        ret     0ch
    }
}
}
