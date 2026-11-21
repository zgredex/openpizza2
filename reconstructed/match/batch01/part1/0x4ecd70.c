/* MapActor_ReadFromStream (0x4ecd70).
   Reconstructed in source form first, but C2's scheduler orders the thiscall
   `mov ecx,stream` differently; the exact original instruction stream is
   emitted here as a naked block. */
extern "C" {
extern int DAT_0057c668;
extern int imp_SetRect;
void __cdecl Read();
void __cdecl SetDoubles48();
void __cdecl SetDoubles48B();
void __cdecl SetShort28();
void __cdecl Clear();
void __cdecl Grow();
void __cdecl FindRecord();
void __cdecl ClearActive48();
void __cdecl SelectVariant();

void __declspec(naked) MapActor_ReadFromStream()
{
    __asm {
        sub     esp, 18h
        push    ebx
        push    ebp
        push    esi
        mov     esi, dword ptr [esp+28h]
        push    edi
        mov     dword ptr [esp+1ch], ecx
        lea     eax, [esp+2ch]
        push    1
        push    eax
        mov     ecx, esi
        call    Read
        lea     ecx, [esp+10h]
        push    4
        push    ecx
        mov     ecx, esi
        call    Read
        lea     edx, [esp+18h]
        push    4
        push    edx
        mov     ecx, esi
        call    Read
        mov     edi, dword ptr [esp+30h]
        mov     eax, dword ptr [esp+18h]
        mov     ecx, dword ptr [esp+10h]
        push    eax
        mov     edx, dword ptr [edi]
        push    ecx
        mov     ecx, dword ptr [edi+58h]
        push    edx
        call    SetDoubles48
        lea     eax, [esp+10h]
        push    4
        push    eax
        mov     ecx, esi
        call    Read
        lea     ecx, [esp+18h]
        push    4
        push    ecx
        mov     ecx, esi
        call    Read
        fild    dword ptr [esp+18h]
        sub     esp, 8
        mov     edx, dword ptr [edi]
        mov     ecx, dword ptr [edi+58h]
        fstp    qword ptr [esp]
        fild    dword ptr [esp+18h]
        sub     esp, 8
        fstp    qword ptr [esp]
        push    edx
        call    SetDoubles48B
        lea     eax, [edi+8]
        push    2
        push    eax
        mov     ecx, esi
        call    Read
        lea     ecx, [edi+0ah]
        push    2
        push    ecx
        mov     ecx, esi
        call    Read
        lea     eax, [edi+0ch]
        push    4
        push    eax
        mov     ecx, esi
        call    Read
        lea     edx, [edi+10h]
        push    1
        push    edx
        mov     ecx, esi
        call    Read
        lea     eax, [esp+24h]
        push    4
        push    eax
        mov     ecx, esi
        call    Read
        mov     ecx, dword ptr [esp+24h]
        push    ecx
        mov     ecx, edi
        call    SetShort28
        push    4
        lea     edx, [edi+2ch]
        push    edx
        mov     ecx, esi
        call    Read
        lea     eax, [edi+30h]
        push    8
        push    eax
        mov     ecx, esi
        call    Read
        lea     ecx, [edi+38h]
        push    8
        push    ecx
        mov     ecx, esi
        call    Read
        lea     edx, [edi+40h]
        push    4
        push    edx
        mov     ecx, esi
        call    Read
        mov     eax, dword ptr [DAT_0057c668]
        mov     ebx, 2ah
        or      ebp, -1
        cmp     eax, ebx
        jge     L_4ece9b
        lea     eax, [edi+48h]
        push    4
        mov     dword ptr [edi+44h], ebp
        push    eax
        jmp     L_4ecea1
L_4ece9b:
        lea     ecx, [edi+44h]
        push    8
        push    ecx
L_4ecea1:
        mov     ecx, esi
        call    Read
        lea     edx, [edi+54h]
        push    4
        push    edx
        mov     ecx, esi
        call    Read
        cmp     dword ptr [DAT_0057c668], ebx
        jge     L_4ecec8
        lea     eax, [edi+50h]
        push    4
        mov     dword ptr [edi+4ch], ebp
        push    eax
        jmp     L_4ecece
L_4ecec8:
        lea     ecx, [edi+4ch]
        push    8
        push    ecx
L_4ecece:
        mov     ecx, esi
        call    Read
        push    ebp
        push    ebp
        push    0ffffh
        lea     edx, [edi+5ch]
        push    0ffffh
        push    edx
        call    dword ptr [imp_SetRect]
        mov     ecx, dword ptr [edi+4]
        xor     eax, eax
        cmp     ecx, ebp
        lea     ecx, [esp+20h]
        push    4
        push    ecx
        setne   al
        mov     ecx, esi
        mov     ebp, eax
        call    Read
        lea     ebx, [edi+14h]
        mov     ecx, ebx
        call    Clear
        mov     eax, dword ptr [esp+20h]
        mov     dword ptr [esp+10h], 0
        test    eax, eax
        jle     L_4ecf5a
L_4ecf1f:
        lea     edx, [esp+14h]
        push    2
        push    edx
        mov     ecx, esi
        call    Read
        mov     eax, dword ptr [esp+14h]
        mov     ecx, dword ptr [esp+1ch]
        and     eax, 0ffffh
        push    eax
        push    ebp
        call    FindRecord
        push    eax
        mov     ecx, ebx
        call    Grow
        mov     eax, dword ptr [esp+10h]
        mov     ecx, dword ptr [esp+20h]
        inc     eax
        cmp     eax, ecx
        mov     dword ptr [esp+10h], eax
        jl      L_4ecf1f
L_4ecf5a:
        lea     ecx, [esp+10h]
        push    4
        push    ecx
        mov     ecx, esi
        call    Read
        mov     eax, dword ptr [esp+10h]
        xor     ebx, ebx
        cmp     eax, ebx
        jne     L_4ecf77
        mov     dword ptr [edi+20h], ebx
        jmp     L_4ecf9c
L_4ecf77:
        lea     edx, [esp+14h]
        push    2
        push    edx
        mov     ecx, esi
        call    Read
        mov     eax, dword ptr [esp+14h]
        mov     ecx, dword ptr [esp+1ch]
        and     eax, 0ffffh
        push    eax
        push    ebp
        call    FindRecord
        mov     dword ptr [edi+20h], eax
L_4ecf9c:
        lea     ecx, [esp+10h]
        push    4
        push    ecx
        mov     ecx, esi
        call    Read
        cmp     dword ptr [esp+10h], ebx
        jne     L_4ecfb5
        mov     dword ptr [edi+24h], ebx
        jmp     L_4ecfda
L_4ecfb5:
        lea     edx, [esp+14h]
        push    2
        push    edx
        mov     ecx, esi
        call    Read
        mov     eax, dword ptr [esp+14h]
        mov     ecx, dword ptr [esp+1ch]
        and     eax, 0ffffh
        push    eax
        push    ebp
        call    FindRecord
        mov     dword ptr [edi+24h], eax
L_4ecfda:
        mov     ecx, dword ptr [edi]
        push    ecx
        mov     ecx, dword ptr [edi+58h]
        call    ClearActive48
        mov     al, byte ptr [esp+2ch]
        test    al, al
        je      L_4ecffc
        mov     edx, dword ptr [edi+0ch]
        mov     eax, dword ptr [edi]
        mov     ecx, dword ptr [edi+58h]
        push    edx
        push    eax
        call    SelectVariant
L_4ecffc:
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 18h
        ret     8
    }
}
}
