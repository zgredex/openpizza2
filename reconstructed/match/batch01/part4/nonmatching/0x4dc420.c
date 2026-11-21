/* NOT DECOMPILED C: naked instruction transcription kept only as reference.
   Marked unmatched; see ../worklog.md. */
/* PC2 byte-match candidate. Build with CL /O2 /TP; see worklog.md and
   verify.py for the exact matcher command and symbol addresses. */
/* Naked transcription of the shipped function. */
extern "C" void __cdecl pc2_fn_401320(void);
extern "C" void __cdecl pc2_fn_401340(void);
extern "C" void __cdecl pc2_fn_4e2250(void);
extern "C" void __cdecl pc2_fn_533a70(void);
extern "C" void __cdecl pc2_fn_533aa0(void);
extern "C" void __cdecl pc2_strstr(void);
extern "C" int pc2_mem_57c670;

extern "C" __declspec(naked) void __cdecl UI_Object_SetSignAndLogoVariant(void)
{
    __asm {
        push   ecx
        mov    eax,pc2_mem_57c670
        push   ebx
        push   esi
        mov    esi,ecx
        mov    ecx,DWORD PTR [eax+248h]
        push   edi
        call pc2_fn_401320
        mov    edx,DWORD PTR [esp+18h]
        mov    ecx,DWORD PTR [esi+0fa8h]
        mov    esi,DWORD PTR [esp+1ch]
        mov    eax,DWORD PTR [edx+24h]
        mov    ecx,DWORD PTR [ecx+4ch]
        lea    eax,[eax+eax*2]
        lea    ebx,[ecx+eax*4]
        mov    ecx,esi
        call pc2_fn_4e2250
        mov    edx,DWORD PTR [esi+1e0h]
        mov    DWORD PTR [esp+1ch],eax
        mov    eax,DWORD PTR [ebx+8h]
        xor    edi,edi
        mov    DWORD PTR [esp+0ch],edx
        mov    DWORD PTR [esp+18h],edi
        cmp    DWORD PTR [eax+14h],edi
        jle L_4dc528
        push   ebp
L_4dc478:
        mov    eax,DWORD PTR [eax+18h]
        add    eax,edi
        mov    esi,DWORD PTR [eax+8h]
        mov    ebp,DWORD PTR [eax]
        cmp    BYTE PTR [esi],2h
        jne L_4dc50d
        lea    eax,[esi+4h]
        push   56d04ch
        push   eax
        call pc2_strstr
        add    esp,8h
        test   eax,eax
        je L_4dc4cc
        mov    ecx,DWORD PTR [ebx+8h]
        mov    eax,DWORD PTR [esp+18h]
        test   eax,eax
        mov    edx,DWORD PTR [ecx+18h]
        mov    DWORD PTR [edx+edi*1+4h],eax
        je L_4dc4c3
        mov    eax,DWORD PTR [esp+20h]
        mov    ecx,DWORD PTR [esi+48h]
        inc    eax
        push   eax
        push   ebp
        call pc2_fn_533aa0
        jmp L_4dc4cc
L_4dc4c3:
        mov    ecx,DWORD PTR [esi+48h]
        push   ebp
        call pc2_fn_533a70
L_4dc4cc:
        lea    eax,[esi+4h]
        push   56d044h
        push   eax
        call pc2_strstr
        add    esp,8h
        test   eax,eax
        je L_4dc50d
        mov    ecx,DWORD PTR [ebx+8h]
        mov    eax,DWORD PTR [esp+18h]
        test   eax,eax
        mov    edx,DWORD PTR [ecx+18h]
        mov    DWORD PTR [edx+edi*1+4h],eax
        je L_4dc504
        mov    eax,DWORD PTR [esp+10h]
        mov    ecx,DWORD PTR [esi+48h]
        inc    eax
        push   eax
        push   ebp
        call pc2_fn_533aa0
        jmp L_4dc50d
L_4dc504:
        mov    ecx,DWORD PTR [esi+48h]
        push   ebp
        call pc2_fn_533a70
L_4dc50d:
        mov    eax,DWORD PTR [ebx+8h]
        mov    ecx,DWORD PTR [esp+1ch]
        inc    ecx
        add    edi,0ch
        mov    edx,DWORD PTR [eax+14h]
        mov    DWORD PTR [esp+1ch],ecx
        cmp    ecx,edx
        jl L_4dc478
        pop    ebp
L_4dc528:
        mov    ecx,DWORD PTR pc2_mem_57c670
        mov    ecx,DWORD PTR [ecx+248h]
        call pc2_fn_401340
        pop    edi
        pop    esi
        pop    ebx
        pop    ecx
        ret    0ch
    }
}
