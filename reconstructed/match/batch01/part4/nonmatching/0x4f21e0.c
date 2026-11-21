/* NOT DECOMPILED C: naked instruction transcription kept only as reference.
   Marked unmatched; see ../worklog.md. */
/* PC2 byte-match candidate. Build with CL /O2 /TP; see worklog.md and
   verify.py for the exact matcher command and symbol addresses. */
/* Naked transcription of the shipped function. */
extern "C" void __cdecl pc2_fn_4f1b60(void);
extern "C" void __cdecl pc2_fn_4f1d90(void);
extern "C" void __cdecl pc2_fn_4f1e10(void);
extern "C" void __cdecl pc2_fn_4f1f70(void);
extern "C" void __cdecl pc2_fn_4f2020(void);
extern "C" void __cdecl pc2_fn_4f5c70(void);
extern "C" void __cdecl pc2_fn_5335b0(void);
extern "C" void __cdecl pc2_fn_533a70(void);
extern "C" void __cdecl pc2_fn_533aa0(void);
extern "C" void __cdecl pc2_fn_5341c0(void);
extern "C" void __cdecl pc2_fn_534250(void);
extern "C" void __cdecl pc2_fn_5342e0(void);
extern "C" void __cdecl pc2_fn_534c90(void);
extern "C" void __cdecl pc2_fn_534e20(void);
extern "C" void __cdecl pc2_fn_54b440(void);
extern "C" void __cdecl pc2_fn_54f140(void);
extern "C" int pc2_mem_58072c;
extern "C" int pc2_mem_580a58;

extern "C" __declspec(naked) void __cdecl UI_Object_UpdateWalkStep(void)
{
    __asm {
        push   ebp
        mov    ebp,esp
        and    esp,0fffffff8h
        sub    esp,2ch
        push   ebx
        push   esi
        mov    esi,DWORD PTR [ebp+8h]
        or     eax,0ffffffffh
        mov    DWORD PTR pc2_mem_580a58,1h
        push   edi
        cmp    WORD PTR [esi+28h],ax
        mov    DWORD PTR [esp+14h],ecx
        jne L_4f222e
        mov    edx,DWORD PTR [esi]
        lea    eax,[esp+28h]
        lea    ecx,[esp+30h]
        push   eax
        push   ecx
        mov    ecx,DWORD PTR [esi+58h]
        push   edx
        call pc2_fn_5341c0
        mov    DWORD PTR pc2_mem_580a58,0h
        pop    edi
        pop    esi
        pop    ebx
        mov    esp,ebp
        pop    ebp
        ret    8h
L_4f222e:
        cmp    DWORD PTR [esi+40h],eax
        je L_4f2241
        push   esi
        call pc2_fn_4f1b60
        test   eax,eax
        jne L_4f26d2
L_4f2241:
        mov    edi,DWORD PTR [esp+20h]
L_4f2245:
        mov    eax,DWORD PTR [esi]
        mov    ecx,DWORD PTR [esi+58h]
        test   eax,eax
        mov    DWORD PTR [esp+20h],0h
        jl L_4f2335
        cmp    eax,DWORD PTR [ecx+48h]
        jge L_4f2335
        mov    ecx,DWORD PTR [ecx+4ch]
        lea    edx,[eax+eax*8]
        xor    ebx,ebx
        mov    bl,BYTE PTR [ecx+edx*8+3eh]
        mov    ecx,ebx
        test   ecx,ecx
        je L_4f2335
        lea    edx,[esp+24h]
        lea    ecx,[esp+28h]
        push   edx
        push   ecx
        mov    ecx,DWORD PTR [ebp+0ch]
        lea    edx,[esp+38h]
        push   edx
        push   ecx
        mov    ecx,DWORD PTR [esi+58h]
        push   eax
        call pc2_fn_534c90
        fld    QWORD PTR [esp+30h]
        call pc2_fn_54f140
        fld    QWORD PTR [esp+28h]
        mov    ebx,eax
        call pc2_fn_54f140
        mov    ecx,DWORD PTR [esp+14h]
        push   eax
        push   ebx
        push   esi
        mov    DWORD PTR [esp+28h],eax
        call pc2_fn_4f1e10
        test   eax,eax
        jne L_4f26b0
        lea    edx,[esp+20h]
        lea    eax,[esp+28h]
        push   edx
        mov    edx,DWORD PTR [ebp+0ch]
        lea    ecx,[esp+34h]
        push   eax
        mov    eax,DWORD PTR [esi]
        push   ecx
        mov    ecx,DWORD PTR [esi+58h]
        push   edx
        push   eax
        call pc2_fn_534250
        mov    ecx,DWORD PTR [esp+1ch]
        push   ecx
        mov    ecx,DWORD PTR [esp+18h]
        push   ebx
        push   esi
        call pc2_fn_4f2020
        mov    eax,DWORD PTR [esp+20h]
        test   eax,eax
        je L_4f26d2
        movsx  edx,WORD PTR [esi+28h]
        inc    edx
        mov    ecx,esi
        push   edx
        call pc2_fn_4f5c70
        movsx  ecx,WORD PTR [esi+28h]
        mov    eax,DWORD PTR [esi+20h]
        lea    ebx,[esi+14h]
        push   ecx
        mov    ecx,ebx
        mov    DWORD PTR [esi+24h],eax
        call pc2_fn_54b440
        movsx  edx,WORD PTR [esi+28h]
        inc    edx
        mov    ecx,ebx
        push   edx
        mov    DWORD PTR [esi+20h],eax
        call pc2_fn_54b440
        test   eax,eax
        je L_4f267e
L_4f2335:
        movsx  eax,WORD PTR [esi+28h]
        lea    ebx,[esi+14h]
        push   eax
        mov    ecx,ebx
        call pc2_fn_54b440
        test   eax,eax
        je L_4f26d2
        mov    ecx,DWORD PTR [eax+0ch]
        mov    edx,DWORD PTR [eax+10h]
        movsx  eax,WORD PTR [esi+28h]
        inc    eax
        mov    DWORD PTR [esp+18h],ecx
        push   eax
        mov    ecx,ebx
        mov    DWORD PTR [esp+10h],edx
        call pc2_fn_54b440
        test   eax,eax
        je L_4f26d2
        mov    ecx,DWORD PTR [eax+0ch]
        mov    edx,DWORD PTR [eax+10h]
        movsx  eax,WORD PTR [esi+28h]
        mov    DWORD PTR [esp+10h],ecx
        push   eax
        mov    ecx,ebx
        mov    DWORD PTR [esp+20h],edx
        call pc2_fn_54b440
        cmp    BYTE PTR [eax+6h],2h
        jne L_4f24a3
        movsx  ecx,WORD PTR [esi+28h]
        inc    ecx
        push   ecx
        mov    ecx,ebx
        call pc2_fn_54b440
        cmp    BYTE PTR [eax+6h],2h
        jne L_4f24a3
        mov    ecx,DWORD PTR [esp+14h]
        push   esi
        call pc2_fn_4f1f70
        mov    edx,DWORD PTR [esi]
        mov    ecx,DWORD PTR [esi+58h]
        push   edx
        call pc2_fn_533a70
        movsx  eax,WORD PTR [esi+28h]
        inc    eax
        mov    ecx,esi
        push   eax
        call pc2_fn_4f5c70
        movsx  ecx,WORD PTR [esi+28h]
        push   ecx
        mov    ecx,ebx
        call pc2_fn_54b440
        movsx  edx,WORD PTR [esi+28h]
        push   edx
        mov    ecx,ebx
        mov    DWORD PTR [esi+24h],eax
        call pc2_fn_54b440
        mov    ecx,DWORD PTR [esp+14h]
        mov    DWORD PTR [esi+20h],eax
        mov    eax,DWORD PTR [esp+1ch]
        mov    edx,DWORD PTR [ecx+0fch]
        sub    eax,edx
        mov    edx,DWORD PTR [ecx+0f8h]
        push   eax
        mov    eax,DWORD PTR [esp+14h]
        mov    ecx,DWORD PTR [esi+58h]
        sub    eax,edx
        push   eax
        mov    eax,DWORD PTR [esi]
        push   eax
        call pc2_fn_5342e0
        movsx  ecx,WORD PTR [esi+28h]
        push   ecx
        mov    ecx,ebx
        call pc2_fn_54b440
        mov    edx,DWORD PTR [eax+0ch]
        mov    ecx,ebx
        movsx  eax,WORD PTR [esi+28h]
        push   eax
        mov    DWORD PTR [esp+1ch],edx
        call pc2_fn_54b440
        mov    ecx,DWORD PTR [eax+10h]
        lea    eax,[esi+5ch]
        mov    DWORD PTR [esp+0ch],ecx
        mov    ecx,DWORD PTR [esp+14h]
        push   eax
        mov    edx,DWORD PTR [ecx+24h]
        sub    DWORD PTR [eax],edx
        mov    edx,DWORD PTR [ecx+24h]
        sub    DWORD PTR [esi+64h],edx
        mov    edx,DWORD PTR [ecx+28h]
        sub    DWORD PTR [esi+60h],edx
        mov    ecx,DWORD PTR [ecx+28h]
        mov    edx,DWORD PTR [esi+68h]
        sub    edx,ecx
        mov    DWORD PTR [esi+68h],edx
        mov    ecx,DWORD PTR pc2_mem_58072c
        call pc2_fn_534e20
        movsx  edx,WORD PTR [esi+28h]
        inc    edx
        mov    ecx,ebx
        push   edx
        call pc2_fn_54b440
        test   eax,eax
        je L_4f2693
        movsx  eax,WORD PTR [esi+28h]
        inc    eax
        mov    ecx,ebx
        push   eax
        call pc2_fn_54b440
        movsx  edx,WORD PTR [esi+28h]
        mov    ecx,DWORD PTR [eax+0ch]
        inc    edx
        mov    DWORD PTR [esp+10h],ecx
        push   edx
        mov    ecx,ebx
        call pc2_fn_54b440
        mov    ebx,DWORD PTR [eax+10h]
        jmp L_4f24a7
L_4f24a3:
        mov    ebx,DWORD PTR [esp+1ch]
L_4f24a7:
        cmp    DWORD PTR [esi+4h],0ffffffffh
        jne L_4f25b1
        mov    edx,DWORD PTR [esp+18h]
        mov    eax,0a0h
        sub    ebx,0d0h
        sub    edx,eax
        mov    ecx,DWORD PTR [esp+0ch]
        mov    DWORD PTR [esp+1ch],ebx
        fild   DWORD PTR [esp+1ch]
        mov    DWORD PTR [esp+18h],edx
        mov    edx,DWORD PTR [esp+10h]
        sub    esp,8h
        sub    edx,eax
        mov    eax,DWORD PTR [esi]
        mov    DWORD PTR [esp+18h],edx
        fstp   QWORD PTR [esp]
        fild   DWORD PTR [esp+18h]
        sub    esp,8h
        sub    ecx,0d0h
        mov    DWORD PTR [esp+1ch],ecx
        mov    ecx,DWORD PTR [esi+58h]
        fstp   QWORD PTR [esp]
        push   eax
        call pc2_fn_5335b0
        mov    eax,DWORD PTR [esp+18h]
        mov    ecx,DWORD PTR [esp+10h]
        cmp    eax,ecx
        jle L_4f252f
        jmp L_4f2610
L_4f2512:
        jl L_4f266a
        mov    edx,DWORD PTR [esi]
        mov    ecx,DWORD PTR [esi+58h]
        add    edi,7h
        push   edi
        push   edx
        mov    DWORD PTR [esi+0ch],edi
        call pc2_fn_533aa0
        jmp L_4f2245
L_4f252f:
        jge L_4f2583
        mov    eax,DWORD PTR [esp+0ch]
        mov    edi,DWORD PTR [esi+2ch]
        cmp    eax,ebx
        jle L_4f2553
        mov    edx,DWORD PTR [esi]
        mov    ecx,DWORD PTR [esi+58h]
        add    edi,4h
        push   edi
        push   edx
        mov    DWORD PTR [esi+0ch],edi
        call pc2_fn_533aa0
        jmp L_4f2245
L_4f2553:
        jge L_4f256c
L_4f2555:
        mov    edx,DWORD PTR [esi]
        mov    ecx,DWORD PTR [esi+58h]
        add    edi,2h
        push   edi
        push   edx
        mov    DWORD PTR [esi+0ch],edi
        call pc2_fn_533aa0
        jmp L_4f2245
L_4f256c:
        mov    edx,DWORD PTR [esi]
        mov    ecx,DWORD PTR [esi+58h]
        add    edi,3h
        push   edi
        push   edx
        mov    DWORD PTR [esi+0ch],edi
        call pc2_fn_533aa0
        jmp L_4f2245
L_4f2583:
        cmp    eax,ecx
        jne L_4f266a
        mov    eax,DWORD PTR [esp+0ch]
        mov    edi,DWORD PTR [esi+2ch]
        cmp    eax,ebx
        jle L_4f2669
        mov    edx,DWORD PTR [esi]
        mov    ecx,DWORD PTR [esi+58h]
        add    edi,5h
        push   edi
        push   edx
        mov    DWORD PTR [esi+0ch],edi
        call pc2_fn_533aa0
        jmp L_4f2245
L_4f25b1:
        mov    ecx,DWORD PTR [esp+14h]
        mov    edx,DWORD PTR [esp+18h]
        sub    esp,8h
        mov    eax,DWORD PTR [ecx+0f8h]
        mov    ecx,DWORD PTR [ecx+0fch]
        sub    edx,eax
        sub    ebx,ecx
        mov    DWORD PTR [esp+20h],edx
        mov    edx,DWORD PTR [esp+14h]
        sub    edx,ecx
        mov    DWORD PTR [esp+24h],ebx
        fild   DWORD PTR [esp+24h]
        mov    DWORD PTR [esp+14h],edx
        mov    edx,DWORD PTR [esp+18h]
        mov    ecx,DWORD PTR [esi]
        sub    edx,eax
        fstp   QWORD PTR [esp]
        mov    DWORD PTR [esp+18h],edx
        sub    esp,8h
        fild   DWORD PTR [esp+20h]
        fstp   QWORD PTR [esp]
        push   ecx
        mov    ecx,DWORD PTR [esi+58h]
        call pc2_fn_5335b0
        mov    eax,DWORD PTR [esp+18h]
        mov    ecx,DWORD PTR [esp+10h]
        cmp    eax,ecx
        jle L_4f2636
L_4f2610:
        mov    eax,DWORD PTR [esp+0ch]
        mov    edi,DWORD PTR [esi+2ch]
        cmp    eax,ebx
        jle L_4f2512
        mov    edx,DWORD PTR [esi]
        mov    ecx,DWORD PTR [esi+58h]
        add    edi,6h
        push   edi
        push   edx
        mov    DWORD PTR [esi+0ch],edi
        call pc2_fn_533aa0
        jmp L_4f2245
L_4f2636:
        jge L_4f2583
        mov    eax,DWORD PTR [esp+0ch]
        mov    edi,DWORD PTR [esi+2ch]
        cmp    eax,ebx
        jle L_4f265e
        mov    edx,DWORD PTR [esi]
        mov    ecx,DWORD PTR [esi+58h]
        add    edi,4h
        push   edi
        push   edx
        mov    DWORD PTR [esi+0ch],edi
        call pc2_fn_533aa0
        jmp L_4f2245
L_4f265e:
        jge L_4f256c
        jmp L_4f2555
L_4f2669:
        inc    edi
L_4f266a:
        mov    edx,DWORD PTR [esi]
        mov    ecx,DWORD PTR [esi+58h]
        push   edi
        push   edx
        mov    DWORD PTR [esi+0ch],edi
        call pc2_fn_533aa0
        jmp L_4f2245
L_4f267e:
        mov    ecx,DWORD PTR [esp+14h]
        push   esi
        call pc2_fn_4f1f70
        mov    eax,DWORD PTR [esi]
        mov    ecx,DWORD PTR [esi+58h]
        push   eax
        call pc2_fn_533a70
L_4f2693:
        xor    edi,edi
        push   0ffffffffh
        mov    ecx,esi
        mov    DWORD PTR [esi+0ch],edi
        call pc2_fn_4f5c70
        mov    DWORD PTR pc2_mem_580a58,edi
        pop    edi
        pop    esi
        pop    ebx
        mov    esp,ebp
        pop    ebp
        ret    8h
L_4f26b0:
        mov    edi,DWORD PTR [esp+14h]
        push   esi
        mov    ecx,edi
        call pc2_fn_4f1d90
        push   esi
        mov    ecx,edi
        mov    DWORD PTR [esi+40h],eax
        call pc2_fn_4f1f70
        mov    ecx,DWORD PTR [esi]
        push   ecx
        mov    ecx,DWORD PTR [esi+58h]
        call pc2_fn_533a70
L_4f26d2:
        pop    edi
        pop    esi
        mov    DWORD PTR pc2_mem_580a58,0h
        pop    ebx
        mov    esp,ebp
        pop    ebp
        ret    8h
    }
}
