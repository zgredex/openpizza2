/* NOT DECOMPILED C: naked instruction transcription kept only as reference.
   Marked unmatched; see ../worklog.md. */
/* PC2 byte-match candidate. Build with CL /O2 /TP; see worklog.md and
   verify.py for the exact matcher command and symbol addresses. */
/* Naked transcription of the shipped function. */
extern "C" void __cdecl pc2_fn_4017f0(void);
extern "C" void __cdecl pc2_fn_4d3930(void);
extern "C" void __cdecl pc2_fn_4d3f90(void);
extern "C" void __cdecl pc2_fn_4d3fc0(void);
extern "C" void __cdecl pc2_fn_4d3fe0(void);
extern "C" void __cdecl pc2_fn_4d4000(void);
extern "C" void __cdecl pc2_fn_4d42f0(void);
extern "C" void __cdecl pc2_fn_52f9b0(void);
extern "C" void __cdecl pc2_fn_52fd00(void);
extern "C" void __cdecl pc2_fn_52fd70(void);
extern "C" void __cdecl pc2_fn_52ff50(void);
extern "C" void __cdecl pc2_fn_531470(void);
extern "C" void __cdecl pc2_fn_5316b0(void);
extern "C" void __cdecl pc2_fn_531740(void);
extern "C" void __cdecl pc2_fn_54bb00(void);
extern "C" void __cdecl pc2_string_format(void);
extern "C" int pc2_mem_57c5ec;
extern "C" int pc2_mem_57c670;

extern "C" __declspec(naked) void __cdecl UI_PersonnelPlan_UpdateEmployeeDetail(void)
{
    __asm {
        sub    esp,34h
        mov    eax,DWORD PTR [esp+40h]
        mov    ecx,DWORD PTR [esp+3ch]
        push   ebx
        push   ebp
        push   esi
        push   edi
        push   0h
        push   eax
        add    ecx,148h
        call pc2_fn_4017f0
        mov    edx,DWORD PTR [esp+58h]
        push   0h
        push   edx
        lea    ecx,[eax+1500h]
        mov    DWORD PTR [esp+28h],eax
        call pc2_fn_4017f0
        mov    bl,BYTE PTR [esp+54h]
        mov    esi,DWORD PTR [esp+48h]
        mov    edi,eax
        test   bl,bl
        mov    DWORD PTR [esp+50h],edi
        jne L_4b1b48
        mov    ecx,DWORD PTR [edi]
        call pc2_fn_4d3930
        push   eax
        push   52bh
        mov    ecx,esi
        call pc2_fn_52f9b0
        mov    eax,DWORD PTR [edi]
        lea    edx,[esp+24h]
        mov    ecx,DWORD PTR [eax+38h]
        push   ecx
        push   5686f4h
        push   edx
        call pc2_string_format
        add    esp,0ch
        lea    eax,[esp+24h]
        mov    ecx,esi
        push   eax
        push   52eh
        call pc2_fn_52f9b0
        mov    ecx,DWORD PTR [edi]
        xor    edx,edx
        mov    dl,BYTE PTR [ecx+824h]
        mov    ecx,esi
        mov    eax,DWORD PTR [edx*4+5832a8h]
        push   eax
        push   52dh
        call pc2_fn_52f9b0
        mov    ecx,DWORD PTR [edi]
        call pc2_fn_4d4000
        push   eax
        lea    ecx,[esp+28h]
        push   5686f4h
        push   ecx
        call pc2_string_format
        add    esp,0ch
        lea    edx,[esp+24h]
        mov    ecx,esi
        push   edx
        push   52ah
        call pc2_fn_52f9b0
        mov    eax,DWORD PTR [edi]
        lea    edx,[esp+24h]
        mov    ecx,DWORD PTR [eax+3ch]
        push   ecx
        push   5686f4h
        push   edx
        call pc2_string_format
        add    esp,0ch
        lea    eax,[esp+24h]
        mov    ecx,esi
        push   eax
        push   529h
        call pc2_fn_52f9b0
L_4b1b48:
        mov    ecx,DWORD PTR [edi]
        xor    edx,edx
        mov    dl,BYTE PTR [ecx+824h]
        mov    ecx,esi
        mov    eax,DWORD PTR [edx*4+5832d4h]
        push   eax
        push   472h
        call pc2_fn_52f9b0
        test   bl,bl
        je L_4b1b88
        mov    ecx,DWORD PTR [edi]
        xor    edx,edx
        mov    dl,BYTE PTR [ecx+824h]
        mov    ecx,esi
        mov    eax,DWORD PTR [edx*4+5832d4h]
        push   eax
        push   578h
        call pc2_fn_52f9b0
L_4b1b88:
        mov    ecx,DWORD PTR [edi]
        push   480h
        mov    al,BYTE PTR [ecx+824h]
        mov    ecx,esi
        cmp    al,3h
        jne L_4b1bd7
        call pc2_fn_531740
        mov    edx,DWORD PTR [edi]
        xor    eax,eax
        mov    cl,BYTE PTR [edx+825h]
        cmp    cl,1h
        mov    ecx,esi
        sete   al
        push   eax
        push   1388h
        call pc2_fn_52ff50
        push   1388h
        mov    ecx,esi
        call pc2_fn_5316b0
        push   1389h
        mov    ecx,esi
        call pc2_fn_5316b0
        jmp L_4b1bf4
L_4b1bd7:
        call pc2_fn_5316b0
        push   1388h
        mov    ecx,esi
        call pc2_fn_531740
        push   1389h
        mov    ecx,esi
        call pc2_fn_531740
L_4b1bf4:
        dec    bl
        push   0h
        neg    bl
        sbb    ebx,ebx
        push   64h
        and    ebx,1ed6h
        push   0h
        mov    edi,ebx
        mov    ecx,esi
        lea    ebp,[edi+453h]
        push   ebp
        call pc2_fn_52fd00
        push   0h
        lea    ebx,[edi+455h]
        push   64h
        push   0h
        push   ebx
        mov    ecx,esi
        call pc2_fn_52fd00
        push   0h
        lea    eax,[edi+457h]
        push   64h
        push   0h
        push   eax
        mov    ecx,esi
        mov    DWORD PTR [esp+68h],eax
        call pc2_fn_52fd00
        push   0h
        lea    eax,[edi+459h]
        push   64h
        push   0h
        push   eax
        mov    ecx,esi
        mov    DWORD PTR [esp+58h],eax
        call pc2_fn_52fd00
        push   0h
        lea    eax,[edi+452h]
        push   64h
        push   0h
        push   eax
        mov    ecx,esi
        mov    DWORD PTR [esp+20h],eax
        call pc2_fn_52fd00
        push   0h
        lea    eax,[edi+454h]
        push   64h
        push   0h
        push   eax
        mov    ecx,esi
        mov    DWORD PTR [esp+24h],eax
        call pc2_fn_52fd00
        push   0h
        lea    eax,[edi+456h]
        push   64h
        push   0h
        push   eax
        mov    ecx,esi
        mov    DWORD PTR [esp+28h],eax
        call pc2_fn_52fd00
        push   0h
        add    edi,458h
        push   64h
        push   0h
        push   edi
        mov    ecx,esi
        mov    DWORD PTR [esp+2ch],edi
        call pc2_fn_52fd00
        mov    ecx,DWORD PTR [esp+50h]
        push   0h
        mov    edi,DWORD PTR [ecx]
        mov    ecx,edi
        call pc2_fn_4d3f90
        push   eax
        push   ebp
        mov    ecx,esi
        call pc2_fn_52fd70
        push   0h
        mov    ecx,edi
        call pc2_fn_4d3fc0
        push   eax
        push   ebx
        mov    ecx,esi
        call pc2_fn_52fd70
        mov    edx,DWORD PTR [edi+0ch]
        mov    eax,DWORD PTR [esp+58h]
        push   0h
        push   edx
        push   eax
        mov    ecx,esi
        call pc2_fn_52fd70
        push   0h
        mov    ecx,edi
        call pc2_fn_4d3fe0
        mov    ecx,DWORD PTR [esp+4ch]
        push   eax
        push   ecx
        mov    ecx,esi
        call pc2_fn_52fd70
        mov    ebx,DWORD PTR [edi+14h]
        push   0h
        mov    ecx,edi
        call pc2_fn_4d3f90
        mov    edx,DWORD PTR [esp+14h]
        add    eax,ebx
        push   eax
        push   edx
        mov    ecx,esi
        call pc2_fn_52fd70
        mov    ebx,DWORD PTR [edi+18h]
        push   0h
        mov    ecx,edi
        call pc2_fn_4d3fc0
        add    eax,ebx
        mov    ecx,esi
        push   eax
        mov    eax,DWORD PTR [esp+1ch]
        push   eax
        call pc2_fn_52fd70
        mov    ecx,DWORD PTR [edi+1ch]
        mov    ebx,DWORD PTR [edi+0ch]
        mov    edx,DWORD PTR [esp+18h]
        add    ecx,ebx
        push   0h
        push   ecx
        push   edx
        mov    ecx,esi
        call pc2_fn_52fd70
        mov    ebx,DWORD PTR [edi+20h]
        push   0h
        mov    ecx,edi
        call pc2_fn_4d3fe0
        add    eax,ebx
        mov    ecx,esi
        push   eax
        mov    eax,DWORD PTR [esp+24h]
        push   eax
        call pc2_fn_52fd70
        mov    al,BYTE PTR [esp+54h]
        push   edi
        test   al,al
        je L_4b1d97
        mov    ecx,DWORD PTR pc2_mem_57c5ec
        push   1f53h
        push   esi
        call pc2_fn_54bb00
        push   1h
        push   1f53h
        jmp L_4b1daf
L_4b1d97:
        mov    ecx,DWORD PTR pc2_mem_57c5ec
        push   2332h
        push   esi
        call pc2_fn_54bb00
        push   1h
        push   2332h
L_4b1daf:
        mov    ecx,esi
        call pc2_fn_531470
        mov    edi,DWORD PTR [esp+50h]
        mov    ecx,DWORD PTR [edi]
        call pc2_fn_4d42f0
        test   al,al
        jne L_4b1deb
        push   480h
        mov    ecx,esi
        call pc2_fn_531740
        push   483h
        mov    ecx,esi
        call pc2_fn_531740
        push   485h
        mov    ecx,esi
        call pc2_fn_531740
        jmp L_4b1e1a
L_4b1deb:
        mov    ecx,DWORD PTR [edi]
        cmp    BYTE PTR [ecx+824h],3h
        je L_4b1e02
        push   480h
        mov    ecx,esi
        call pc2_fn_5316b0
L_4b1e02:
        push   483h
        mov    ecx,esi
        call pc2_fn_5316b0
        push   485h
        mov    ecx,esi
        call pc2_fn_5316b0
L_4b1e1a:
        mov    eax,DWORD PTR [esp+20h]
        mov    edx,DWORD PTR [esp+4ch]
        mov    ecx,DWORD PTR pc2_mem_57c670
        push   0h
        mov    eax,DWORD PTR [eax+34h]
        mov    edi,DWORD PTR [edx+48h]
        push   eax
        add    ecx,4h
        call pc2_fn_4017f0
        cmp    DWORD PTR [eax+edi*4+0c20h],1h
        jg L_4b1e73
        push   480h
        mov    ecx,esi
        call pc2_fn_531740
        push   483h
        mov    ecx,esi
        call pc2_fn_531740
        push   484h
        mov    ecx,esi
        call pc2_fn_531740
        push   485h
        mov    ecx,esi
        call pc2_fn_531740
L_4b1e73:
        pop    edi
        pop    esi
        pop    ebp
        pop    ebx
        add    esp,34h
        ret
    }
}
