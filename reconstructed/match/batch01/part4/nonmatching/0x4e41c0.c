/* NOT DECOMPILED C: naked instruction transcription kept only as reference.
   Marked unmatched; see ../worklog.md. */
/* PC2 byte-match candidate. Build with CL /O2 /TP; see worklog.md and
   verify.py for the exact matcher command and symbol addresses. */
/* Naked transcription of the shipped function. */
extern "C" void __cdecl pc2_fn_4014b0(void);
extern "C" void __cdecl pc2_fn_48e0a0(void);
extern "C" void __cdecl pc2_fn_4e3fb0(void);
extern "C" void __cdecl pc2_string_format(void);
extern "C" void __cdecl pc2_operator_new(void);
extern "C" int pc2_mem_56d160;

extern "C" __declspec(naked) void __cdecl UI_FurnitureType_InitTable(void)
{
    __asm {
        sub    esp,10h
        mov    DWORD PTR [esp+0ch],ecx
        push   edi
        mov    ecx,9c4h
        xor    eax,eax
        mov    edi,57dfdch
        rep stosd
        cmp    DWORD PTR pc2_mem_56d160,0ch
        je L_4e42af
        push   ebx
        push   ebp
        push   esi
        mov    esi,56d160h
        mov    DWORD PTR [esp+10h],esi
        mov    edi,583770h
        jmp L_4e41fa
L_4e41f6:
        mov    edi,DWORD PTR [esp+18h]
L_4e41fa:
        push   0e8h
        call pc2_operator_new
        add    esp,4h
        test   eax,eax
        je L_4e4216
        mov    ecx,eax
        call pc2_fn_4e3fb0
        mov    ebp,eax
        jmp L_4e4218
L_4e4216:
        xor    ebp,ebp
L_4e4218:
        mov    eax,DWORD PTR [esp+10h]
        mov    ecx,DWORD PTR [edi]
        push   ecx
        lea    ebx,[eax+70h]
        lea    edx,[ebx-60h]
        push   edx
        call pc2_string_format
        add    esp,8h
        add    edi,4h
        mov    DWORD PTR [esp+18h],edi
        lea    edi,[ebp+8h]
        mov    ecx,38h
        mov    DWORD PTR [esp+14h],8h
        rep movsd
L_4e4247:
        mov    edi,6h
L_4e424c:
        movsx  esi,WORD PTR [ebx]
        cmp    esi,0ffffffffh
        je L_4e4277
        mov    eax,DWORD PTR [esi*4+57dfdch]
        test   eax,eax
        je L_4e4270
        cmp    eax,ebp
        je L_4e4270
        push   570c00h
        call pc2_fn_48e0a0
        add    esp,4h
L_4e4270:
        mov    DWORD PTR [esi*4+57dfdch],ebp
L_4e4277:
        add    ebx,2h
        dec    edi
        jne L_4e424c
        mov    eax,DWORD PTR [esp+14h]
        dec    eax
        mov    DWORD PTR [esp+14h],eax
        jne L_4e4247
        mov    eax,DWORD PTR [esp+1ch]
        push   ebp
        lea    ecx,[eax+74h]
        call pc2_fn_4014b0
        mov    esi,DWORD PTR [esp+10h]
        add    esi,0e0h
        mov    DWORD PTR [esp+10h],esi
        cmp    DWORD PTR [esi],0ch
        jne L_4e41f6
        pop    esi
        pop    ebp
        pop    ebx
L_4e42af:
        pop    edi
        add    esp,10h
        ret
    }
}
