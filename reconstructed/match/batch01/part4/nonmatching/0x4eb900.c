/* NOT DECOMPILED C: naked instruction transcription kept only as reference.
   Marked unmatched; see ../worklog.md. */
/* PC2 byte-match candidate. Build with CL /O2 /TP; see worklog.md and
   verify.py for the exact matcher command and symbol addresses. */
/* Naked transcription of the shipped function. */
extern "C" void __cdecl pc2_fn_48e0a0(void);
extern "C" void __cdecl pc2_fn_4eaa10(void);
extern "C" void __cdecl pc2_fn_4eab80(void);
extern "C" void __cdecl pc2_fn_4eb8e0(void);
extern "C" void __cdecl pc2_fn_4ed010(void);
extern "C" void __cdecl pc2_fn_4ed040(void);
extern "C" void __cdecl pc2_fn_4eef40(void);
extern "C" void __cdecl pc2_fn_4f37d0(void);
extern "C" void __cdecl pc2_fn_4f3b70(void);
extern "C" void __cdecl pc2_fn_535fc0(void);
extern "C" void __cdecl pc2_fn_53c7f0(void);
extern "C" void __cdecl pc2_fn_54cbc1(void);
extern "C" void __cdecl pc2_string_format(void);
extern "C" void __cdecl pc2_operator_new(void);
extern "C" void __cdecl pc2_fn_54efd0(void);
extern "C" int pc2_mem_55c174;
extern "C" int pc2_mem_55c280;
extern "C" int pc2_mem_57c5c8;

extern "C" __declspec(naked) void __cdecl UI_IsoMap_DeserializeGrid(void)
{
    __asm {
        push   0ffffffffh
        push   559fech
        mov    eax,fs:[0]
        push   eax
        mov    DWORD PTR fs:[0],esp
        sub    esp,238h
        push   ebx
        push   ebp
        push   esi
        mov    esi,DWORD PTR [esp+254h]
        push   edi
        mov    ebp,ecx
        lea    eax,[esp+40h]
        push   4h
        push   eax
        mov    ecx,esi
        call pc2_fn_54cbc1
        lea    ecx,[esp+3ch]
        push   4h
        push   ecx
        mov    ecx,esi
        call pc2_fn_54cbc1
        lea    eax,[ebp+0ch]
        push   4h
        push   eax
        mov    ecx,esi
        call pc2_fn_54cbc1
        lea    eax,[ebp+10h]
        push   4h
        push   eax
        mov    ecx,esi
        call pc2_fn_54cbc1
        lea    edx,[ebp+14h]
        push   4h
        push   edx
        mov    ecx,esi
        call pc2_fn_54cbc1
        lea    eax,[ebp+18h]
        push   4h
        push   eax
        mov    ecx,esi
        call pc2_fn_54cbc1
        lea    edi,[ebp+1ch]
        push   4h
        push   edi
        mov    ecx,esi
        call pc2_fn_54cbc1
        lea    eax,[ebp+20h]
        push   4h
        push   eax
        mov    ecx,esi
        call pc2_fn_54cbc1
        lea    ebx,[ebp+24h]
        push   4h
        push   ebx
        mov    ecx,esi
        call pc2_fn_54cbc1
        lea    eax,[ebp+28h]
        push   4h
        push   eax
        mov    ecx,esi
        call pc2_fn_54cbc1
        mov    ecx,DWORD PTR [ebx]
        lea    eax,[ebp+2ch]
        mov    DWORD PTR [ebp+0e8h],ecx
        mov    edx,DWORD PTR [ebp+28h]
        push   4h
        push   eax
        mov    ecx,esi
        mov    DWORD PTR [ebp+0ech],edx
        call pc2_fn_54cbc1
        lea    ecx,[ebp+30h]
        push   4h
        push   ecx
        mov    ecx,esi
        call pc2_fn_54cbc1
        lea    edx,[ebp+34h]
        push   4h
        push   edx
        mov    ecx,esi
        call pc2_fn_54cbc1
        lea    eax,[ebp+38h]
        push   4h
        push   eax
        mov    ecx,esi
        call pc2_fn_54cbc1
        lea    ebx,[ebp+3ch]
        push   10h
        push   ebx
        mov    ecx,esi
        call pc2_fn_54cbc1
        mov    DWORD PTR [ebx],1h
        xor    ebx,ebx
        lea    eax,[ebp+60h]
        mov    DWORD PTR [ebp+40h],1h
        push   4h
        mov    DWORD PTR [ebp+44h],ebx
        push   eax
        mov    ecx,esi
        mov    DWORD PTR [ebp+48h],ebx
        call pc2_fn_54cbc1
        lea    eax,[ebp+6ch]
        push   4h
        push   eax
        mov    ecx,esi
        mov    DWORD PTR [ebp+60h],ebx
        call pc2_fn_54cbc1
        lea    eax,[ebp+7ch]
        push   1eh
        push   eax
        mov    ecx,esi
        call pc2_fn_54cbc1
        lea    ecx,[ebp+0bah]
        push   2h
        push   ecx
        mov    ecx,esi
        call pc2_fn_54cbc1
        lea    edx,[ebp+0f0h]
        push   4h
        push   edx
        mov    ecx,esi
        call pc2_fn_54cbc1
        mov    eax,DWORD PTR [ebp+20h]
        imul   eax,DWORD PTR [edi]
        lea    eax,[eax+eax*2]
        shl    eax,2h
        push   eax
        call pc2_operator_new
        push   0ch
        mov    DWORD PTR [ebp+4ch],eax
        call pc2_operator_new
        push   3ch
        mov    DWORD PTR [ebp+64h],eax
        call pc2_operator_new
        mov    ecx,DWORD PTR [ebp+64h]
        mov    DWORD PTR [ecx+8h],eax
        mov    eax,DWORD PTR [ebp+20h]
        imul   eax,DWORD PTR [edi]
        mov    DWORD PTR [ebp+13ch],eax
        lea    eax,[eax+eax*2]
        lea    edx,[eax+eax*4]
        shl    edx,2h
        push   edx
        call pc2_operator_new
        mov    DWORD PTR [ebp+138h],eax
        or     eax,0ffffffffh
        mov    DWORD PTR [ebp+58h],eax
        mov    DWORD PTR [ebp+5ch],eax
        mov    eax,DWORD PTR [ebp+0ch]
        add    esp,10h
        cmp    eax,40h
        lea    eax,[ebp+0c0h]
        push   eax
        mov    DWORD PTR [esp+24h],ebx
        mov    DWORD PTR [ebp+50h],ebx
        mov    DWORD PTR [ebp+54h],ebx
        mov    DWORD PTR [ebp+68h],ebx
        mov    DWORD PTR [ebp+0ach],0ffffh
        mov    BYTE PTR [ebp+0b8h],bl
        mov    DWORD PTR [ebp+0bch],ebx
        mov    DWORD PTR [ebp+0f4h],1h
        mov    DWORD PTR [ebp+0f8h],0a0h
        mov    DWORD PTR [ebp+0fch],0d0h
        call   DWORD PTR pc2_mem_55c174
        mov    ecx,ebp
        call pc2_fn_4ed010
        mov    ecx,ebp
        call pc2_fn_4ed040
        push   28h
        mov    DWORD PTR [ebp+9ch],ebx
        mov    DWORD PTR [ebp+0a0h],ebx
        call pc2_operator_new
        add    esp,4h
        lea    edi,[ebp+0a4h]
        mov    ecx,esi
        mov    DWORD PTR [ebp+0b0h],eax
        push   4h
        push   edi
        mov    DWORD PTR [ebp+0b4h],ebx
        call pc2_fn_54cbc1
        lea    eax,[ebp+0a8h]
        push   4h
        push   eax
        mov    ecx,esi
        call pc2_fn_54cbc1
        mov    eax,DWORD PTR [edi]
        cmp    eax,ebx
        jle L_4ebb75
        lea    ecx,[eax+eax*4]
        shl    ecx,3h
        push   ecx
        call pc2_operator_new
        add    esp,4h
        mov    DWORD PTR [ebp+9ch],eax
L_4ebb75:
        mov    eax,DWORD PTR [ebp+0a8h]
        cmp    eax,ebx
        jle L_4ebb94
        lea    edx,[eax+eax*4]
        shl    edx,3h
        push   edx
        call pc2_operator_new
        add    esp,4h
        mov    DWORD PTR [ebp+0a0h],eax
L_4ebb94:
        mov    eax,DWORD PTR [edi]
        mov    DWORD PTR [esp+18h],ebx
        cmp    eax,ebx
        jle L_4ebc84
        xor    edi,edi
L_4ebba4:
        mov    eax,DWORD PTR [ebp+9ch]
        push   1h
        add    eax,edi
        mov    ecx,esi
        push   eax
        call pc2_fn_54cbc1
        mov    ecx,DWORD PTR [ebp+9ch]
        push   2h
        lea    edx,[ecx+edi*1+2h]
        mov    ecx,esi
        push   edx
        call pc2_fn_54cbc1
        mov    eax,DWORD PTR [ebp+9ch]
        mov    cx,WORD PTR [esp+18h]
        push   1h
        mov    WORD PTR [eax+edi*1+4h],cx
        mov    edx,DWORD PTR [ebp+9ch]
        mov    ecx,esi
        lea    eax,[edx+edi*1+6h]
        push   eax
        call pc2_fn_54cbc1
        lea    ecx,[esp+2bh]
        push   1h
        push   ecx
        mov    ecx,esi
        call pc2_fn_54cbc1
        mov    edx,DWORD PTR [ebp+9ch]
        push   4h
        mov    ecx,esi
        lea    eax,[edx+edi*1+8h]
        push   eax
        call pc2_fn_54cbc1
        mov    ecx,DWORD PTR [ebp+9ch]
        push   4h
        lea    edx,[ecx+edi*1+0ch]
        mov    ecx,esi
        push   edx
        call pc2_fn_54cbc1
        mov    eax,DWORD PTR [ebp+9ch]
        push   4h
        lea    ecx,[eax+edi*1+10h]
        push   ecx
        mov    ecx,esi
        call pc2_fn_54cbc1
        mov    edx,DWORD PTR [ebp+9ch]
        push   10h
        mov    ecx,esi
        lea    eax,[edx+edi*1+14h]
        push   eax
        call pc2_fn_54cbc1
        mov    ecx,DWORD PTR [ebp+9ch]
        push   1h
        lea    edx,[ecx+edi*1+24h]
        mov    ecx,esi
        push   edx
        call pc2_fn_54cbc1
        mov    eax,DWORD PTR [ebp+9ch]
        add    edi,28h
        mov    BYTE PTR [eax+edi*1-28h],bl
        mov    eax,DWORD PTR [esp+18h]
        mov    ecx,DWORD PTR [ebp+0a4h]
        inc    eax
        cmp    eax,ecx
        mov    DWORD PTR [esp+18h],eax
        jl L_4ebba4
L_4ebc84:
        mov    eax,DWORD PTR [ebp+0a8h]
        mov    DWORD PTR [esp+18h],ebx
        cmp    eax,ebx
        jle L_4ebd79
        xor    edi,edi
L_4ebc98:
        mov    edx,DWORD PTR [ebp+0a0h]
        mov    ecx,edi
        add    ecx,edx
        push   1h
        push   ecx
        mov    ecx,esi
        call pc2_fn_54cbc1
        mov    edx,DWORD PTR [ebp+0a0h]
        push   2h
        mov    ecx,esi
        lea    eax,[edi+edx*1+2h]
        push   eax
        call pc2_fn_54cbc1
        mov    ecx,DWORD PTR [ebp+0a0h]
        mov    dx,WORD PTR [esp+18h]
        push   1h
        mov    WORD PTR [edi+ecx*1+4h],dx
        mov    eax,DWORD PTR [ebp+0a0h]
        lea    ecx,[edi+eax*1+6h]
        push   ecx
        mov    ecx,esi
        call pc2_fn_54cbc1
        lea    edx,[esp+2bh]
        push   1h
        push   edx
        mov    ecx,esi
        call pc2_fn_54cbc1
        mov    eax,DWORD PTR [ebp+0a0h]
        push   4h
        lea    ecx,[edi+eax*1+8h]
        push   ecx
        mov    ecx,esi
        call pc2_fn_54cbc1
        mov    edx,DWORD PTR [ebp+0a0h]
        push   4h
        mov    ecx,esi
        lea    eax,[edi+edx*1+0ch]
        push   eax
        call pc2_fn_54cbc1
        mov    ecx,DWORD PTR [ebp+0a0h]
        push   4h
        lea    edx,[edi+ecx*1+10h]
        mov    ecx,esi
        push   edx
        call pc2_fn_54cbc1
        mov    eax,DWORD PTR [ebp+0a0h]
        push   10h
        lea    ecx,[edi+eax*1+14h]
        push   ecx
        mov    ecx,esi
        call pc2_fn_54cbc1
        mov    edx,DWORD PTR [ebp+0a0h]
        push   1h
        mov    ecx,esi
        lea    eax,[edi+edx*1+24h]
        push   eax
        call pc2_fn_54cbc1
        mov    ecx,DWORD PTR [ebp+0a0h]
        mov    eax,DWORD PTR [esp+18h]
        inc    eax
        mov    BYTE PTR [edi+ecx*1],bl
        mov    ecx,DWORD PTR [ebp+0a8h]
        add    edi,28h
        cmp    eax,ecx
        mov    DWORD PTR [esp+18h],eax
        jl L_4ebc98
L_4ebd79:
        mov    ecx,DWORD PTR [ebp+20h]
        xor    eax,eax
        xor    edi,edi
        cmp    ecx,ebx
        mov    DWORD PTR [esp+14h],eax
        mov    DWORD PTR [esp+30h],edi
        jle L_4ebf8b
L_4ebd90:
        sub    ecx,edi
        mov    edx,DWORD PTR [ebp+1ch]
        imul   ecx,DWORD PTR [ebp+0ch]
        sar    ecx,1
        mov    DWORD PTR [esp+18h],ecx
        mov    ecx,DWORD PTR [ebp+10h]
        imul   ecx,edi
        sar    ecx,1
        cmp    edx,ebx
        mov    DWORD PTR [esp+38h],ebx
        jle L_4ebf7b
        mov    edx,DWORD PTR [esp+20h]
        lea    edx,[edx+edx*2]
        lea    edx,[edx+edx*4]
        shl    edx,2h
        mov    DWORD PTR [esp+24h],edx
        jmp L_4ebdca
L_4ebdc6:
        mov    edx,DWORD PTR [esp+24h]
L_4ebdca:
        mov    edi,DWORD PTR [ebp+138h]
        add    edi,edx
        lea    edx,[eax+eax*2]
        mov    eax,DWORD PTR [ebp+4ch]
        mov    DWORD PTR [eax+edx*4+8h],edi
        mov    eax,DWORD PTR [esp+20h]
        mov    edi,DWORD PTR [esp+24h]
        inc    eax
        mov    DWORD PTR [esp+20h],eax
        mov    eax,DWORD PTR [esp+14h]
        add    edi,3ch
        lea    edx,[eax+eax*2]
        mov    eax,DWORD PTR [ebp+4ch]
        mov    DWORD PTR [esp+24h],edi
        mov    edi,DWORD PTR [esp+18h]
        mov    DWORD PTR [eax+edx*4],edi
        mov    eax,DWORD PTR [esp+14h]
        lea    edx,[eax+eax*2]
        mov    eax,DWORD PTR [ebp+4ch]
        mov    DWORD PTR [eax+edx*4+4h],ecx
        mov    eax,DWORD PTR [esp+14h]
        mov    edi,DWORD PTR [ebp+4ch]
        lea    edx,[eax+eax*2]
        mov    edx,DWORD PTR [edi+edx*4+8h]
        mov    DWORD PTR [edx],eax
        mov    eax,DWORD PTR [esp+14h]
        mov    edx,DWORD PTR [ebp+4ch]
        lea    eax,[eax+eax*2]
        mov    eax,DWORD PTR [edx+eax*4+8h]
        mov    DWORD PTR [eax+20h],ebx
        mov    eax,DWORD PTR [esp+14h]
        lea    edx,[eax+eax*2]
        mov    eax,DWORD PTR [ebp+4ch]
        mov    eax,DWORD PTR [eax+edx*4+8h]
        or     edx,0ffffffffh
        mov    WORD PTR [eax+24h],dx
        mov    eax,DWORD PTR [esp+14h]
        mov    edi,DWORD PTR [ebp+4ch]
        lea    eax,[eax+eax*2]
        mov    eax,DWORD PTR [edi+eax*4+8h]
        mov    DWORD PTR [eax+28h],ebx
        mov    eax,DWORD PTR [esp+14h]
        mov    edi,DWORD PTR [ebp+4ch]
        lea    eax,[eax+eax*2]
        mov    eax,DWORD PTR [edi+eax*4+8h]
        mov    BYTE PTR [eax+2ch],bl
        mov    eax,DWORD PTR [esp+14h]
        mov    edi,DWORD PTR [ebp+4ch]
        lea    eax,[eax+eax*2]
        mov    eax,DWORD PTR [edi+eax*4+8h]
        mov    BYTE PTR [eax+2dh],bl
        mov    eax,DWORD PTR [esp+14h]
        mov    edi,DWORD PTR [ebp+4ch]
        lea    eax,[eax+eax*2]
        mov    eax,DWORD PTR [edi+eax*4+8h]
        mov    BYTE PTR [eax+2eh],bl
        mov    eax,DWORD PTR [esp+14h]
        mov    edi,DWORD PTR [ebp+4ch]
        lea    eax,[eax+eax*2]
        mov    eax,DWORD PTR [edi+eax*4+8h]
        mov    BYTE PTR [eax+2fh],bl
        mov    eax,DWORD PTR [esp+14h]
        mov    edi,DWORD PTR [ebp+4ch]
        lea    eax,[eax+eax*2]
        mov    eax,DWORD PTR [edi+eax*4+8h]
        mov    DWORD PTR [eax+30h],edx
        mov    eax,DWORD PTR [esp+14h]
        mov    edi,DWORD PTR [ebp+4ch]
        lea    eax,[eax+eax*2]
        mov    eax,DWORD PTR [edi+eax*4+8h]
        mov    DWORD PTR [eax+34h],ebx
        mov    eax,DWORD PTR [esp+14h]
        mov    edi,DWORD PTR [ebp+4ch]
        lea    eax,[eax+eax*2]
        mov    eax,DWORD PTR [edi+eax*4+8h]
        mov    DWORD PTR [eax+38h],ebx
        mov    eax,DWORD PTR [esp+14h]
        mov    edi,DWORD PTR [ebp+4ch]
        lea    eax,[eax+eax*2]
        mov    eax,DWORD PTR [edi+eax*4+8h]
        mov    DWORD PTR [eax+0ch],ebx
        mov    eax,DWORD PTR [esp+14h]
        mov    edi,DWORD PTR [ebp+4ch]
        lea    eax,[eax+eax*2]
        mov    eax,DWORD PTR [edi+eax*4+8h]
        mov    DWORD PTR [eax+18h],ebx
        mov    eax,DWORD PTR [esp+14h]
        mov    edi,DWORD PTR [ebp+4ch]
        lea    eax,[eax+eax*2]
        mov    eax,DWORD PTR [edi+eax*4+8h]
        mov    DWORD PTR [eax+8h],ebx
        mov    eax,DWORD PTR [esp+14h]
        mov    edi,DWORD PTR [ebp+4ch]
        lea    eax,[eax+eax*2]
        mov    eax,DWORD PTR [edi+eax*4+8h]
        mov    DWORD PTR [eax+14h],ebx
        mov    eax,DWORD PTR [esp+14h]
        mov    edi,DWORD PTR [ebp+4ch]
        lea    eax,[eax+eax*2]
        mov    eax,DWORD PTR [edi+eax*4+8h]
        mov    DWORD PTR [eax+4h],edx
        mov    eax,DWORD PTR [esp+14h]
        mov    edi,DWORD PTR [ebp+4ch]
        lea    eax,[eax+eax*2]
        mov    eax,DWORD PTR [edi+eax*4+8h]
        mov    DWORD PTR [eax+10h],edx
        mov    eax,DWORD PTR [esp+14h]
        mov    edi,DWORD PTR [ebp+4ch]
        lea    eax,[eax+eax*2]
        mov    eax,DWORD PTR [edi+eax*4+8h]
        mov    edi,DWORD PTR [esp+18h]
        mov    DWORD PTR [eax+1ch],edx
        mov    edx,DWORD PTR [ebp+0ch]
        mov    eax,DWORD PTR [esp+14h]
        sar    edx,1
        add    edi,edx
        mov    edx,DWORD PTR [ebp+10h]
        sar    edx,1
        add    ecx,edx
        mov    edx,DWORD PTR [esp+38h]
        inc    eax
        mov    DWORD PTR [esp+18h],edi
        mov    edi,DWORD PTR [ebp+1ch]
        inc    edx
        cmp    edx,edi
        mov    DWORD PTR [esp+14h],eax
        mov    DWORD PTR [esp+38h],edx
        jl L_4ebdc6
        mov    edi,DWORD PTR [esp+30h]
L_4ebf7b:
        mov    ecx,DWORD PTR [ebp+20h]
        inc    edi
        cmp    edi,ecx
        mov    DWORD PTR [esp+30h],edi
        jl L_4ebd90
L_4ebf8b:
        mov    eax,DWORD PTR [ebp+20h]
        xor    edi,edi
        imul   eax,DWORD PTR [ebp+1ch]
        test   eax,eax
        mov    DWORD PTR [esp+18h],edi
        jle L_4ec2cb
L_4ebfa0:
        lea    ecx,[esp+2ch]
        push   4h
        push   ecx
        mov    ecx,esi
        call pc2_fn_54cbc1
        cmp    DWORD PTR [esp+2ch],1h
        jne L_4ebfd0
        lea    edx,[esp+14h]
        push   4h
        push   edx
        mov    ecx,esi
        call pc2_fn_54cbc1
        add    edi,DWORD PTR [esp+14h]
        mov    DWORD PTR [esp+18h],edi
        jmp L_4ec2bc
L_4ebfd0:
        mov    eax,DWORD PTR [ebp+4ch]
        lea    edi,[edi+edi*2]
        shl    edi,2h
        push   4h
        mov    ecx,DWORD PTR [edi+eax*1+8h]
        push   ecx
        mov    ecx,esi
        call pc2_fn_54cbc1
        mov    edx,DWORD PTR [ebp+4ch]
        push   2h
        mov    ecx,esi
        mov    eax,DWORD PTR [edi+edx*1+8h]
        add    eax,24h
        push   eax
        call pc2_fn_54cbc1
        mov    ecx,DWORD PTR [ebp+4ch]
        push   4h
        mov    edx,DWORD PTR [edi+ecx*1+8h]
        mov    ecx,esi
        add    edx,30h
        push   edx
        call pc2_fn_54cbc1
        mov    eax,DWORD PTR [ebp+4ch]
        push   4h
        mov    ecx,DWORD PTR [edi+eax*1+8h]
        add    ecx,34h
        push   ecx
        mov    ecx,esi
        call pc2_fn_54cbc1
        mov    edx,DWORD PTR [ebp+4ch]
        push   4h
        mov    ecx,esi
        mov    eax,DWORD PTR [edi+edx*1+8h]
        add    eax,38h
        push   eax
        call pc2_fn_54cbc1
        mov    ecx,DWORD PTR [ebp+4ch]
        xor    edx,edx
        push   4h
        mov    eax,DWORD PTR [edi+ecx*1+8h]
        cmp    DWORD PTR [eax+38h],1h
        sete   dl
        mov    DWORD PTR [eax+38h],edx
        mov    eax,DWORD PTR [ebp+4ch]
        mov    ecx,DWORD PTR [edi+eax*1+8h]
        add    ecx,28h
        push   ecx
        mov    ecx,esi
        call pc2_fn_54cbc1
        mov    edx,DWORD PTR [ebp+4ch]
        push   4h
        mov    ecx,esi
        mov    eax,DWORD PTR [edi+edx*1+8h]
        add    eax,1ch
        push   eax
        call pc2_fn_54cbc1
        mov    ecx,DWORD PTR [ebp+4ch]
        push   1h
        mov    edx,DWORD PTR [edi+ecx*1+8h]
        mov    ecx,esi
        add    edx,2ch
        push   edx
        call pc2_fn_54cbc1
        mov    eax,DWORD PTR [ebp+4ch]
        push   1h
        mov    ecx,DWORD PTR [edi+eax*1+8h]
        add    ecx,2dh
        push   ecx
        mov    ecx,esi
        call pc2_fn_54cbc1
        mov    edx,DWORD PTR [ebp+4ch]
        push   1h
        mov    ecx,esi
        mov    eax,DWORD PTR [edi+edx*1+8h]
        add    eax,2eh
        push   eax
        call pc2_fn_54cbc1
        mov    ecx,DWORD PTR [ebp+4ch]
        push   1h
        mov    edx,DWORD PTR [edi+ecx*1+8h]
        add    edx,2fh
        mov    ecx,esi
        push   edx
        call pc2_fn_54cbc1
        lea    eax,[esp+1ch]
        push   4h
        push   eax
        mov    ecx,esi
        call pc2_fn_54cbc1
        mov    ecx,DWORD PTR [esp+1ch]
        push   ecx
        mov    ecx,DWORD PTR [ebp+4h]
        call pc2_fn_4eaa10
        mov    ecx,DWORD PTR [esp+3ch]
        mov    DWORD PTR [esp+1ch],eax
        cmp    ecx,ebx
        jne L_4ec1a2
        cmp    eax,ebx
        jl L_4ec1a2
        lea    edx,[esp+44h]
        push   32h
        push   edx
        mov    ecx,esi
        call pc2_fn_54cbc1
        mov    eax,DWORD PTR [esp+1ch]
        mov    ecx,DWORD PTR [ebp+4h]
        lea    edx,[eax+eax*8]
        lea    ecx,[ecx+edx*8+25h]
        lea    edx,[esp+44h]
        mov    DWORD PTR [esp+20h],ecx
        mov    DWORD PTR [esp+24h],edx
L_4ec11d:
        mov    ecx,DWORD PTR [esp+24h]
        mov    dl,BYTE PTR [ecx]
        mov    ecx,DWORD PTR [esp+20h]
        mov    BYTE PTR [esp+13h],dl
        cmp    dl,BYTE PTR [ecx]
        jne L_4ec16e
        mov    cl,dl
        cmp    cl,bl
        je L_4ec16a
        mov    edx,DWORD PTR [esp+24h]
        mov    cl,BYTE PTR [edx+1h]
        mov    edx,DWORD PTR [esp+20h]
        mov    BYTE PTR [esp+13h],cl
        cmp    cl,BYTE PTR [edx+1h]
        jne L_4ec16e
        mov    edx,DWORD PTR [esp+24h]
        mov    ecx,2h
        add    edx,ecx
        mov    DWORD PTR [esp+24h],edx
        mov    edx,DWORD PTR [esp+20h]
        add    edx,ecx
        mov    cl,BYTE PTR [esp+13h]
        cmp    cl,bl
        mov    DWORD PTR [esp+20h],edx
        jne L_4ec11d
L_4ec16a:
        xor    ecx,ecx
        jmp L_4ec173
L_4ec16e:
        sbb    ecx,ecx
        sbb    ecx,0ffffffffh
L_4ec173:
        cmp    ecx,ebx
        je L_4ec1a2
        mov    ecx,DWORD PTR [ebp+4h]
        lea    eax,[esp+44h]
        push   eax
        call pc2_fn_4eab80
        movsx  eax,ax
        cmp    eax,0ffffffffh
        mov    DWORD PTR [esp+1ch],eax
        jne L_4ec1a2
        lea    ecx,[esp+44h]
        push   ecx
        push   eax
        call pc2_fn_4eb8e0
        add    esp,8h
        mov    DWORD PTR [esp+1ch],eax
L_4ec1a2:
        mov    edx,DWORD PTR [ebp+4ch]
        mov    ecx,DWORD PTR [edi+edx*1+8h]
        mov    DWORD PTR [ecx+4h],eax
        mov    edx,DWORD PTR [ebp+4ch]
        mov    ecx,DWORD PTR [esp+1ch]
        mov    eax,DWORD PTR [edi+edx*1+8h]
        add    eax,4h
        push   eax
        push   ecx
        mov    ecx,ebp
        call pc2_fn_4eef40
        lea    edx,[esp+1ch]
        push   4h
        push   edx
        mov    ecx,esi
        call pc2_fn_54cbc1
        mov    eax,DWORD PTR [esp+1ch]
        mov    ecx,DWORD PTR [ebp+4h]
        push   eax
        call pc2_fn_4eaa10
        mov    ecx,DWORD PTR [esp+3ch]
        mov    DWORD PTR [esp+1ch],eax
        cmp    ecx,ebx
        jne L_4ec290
        cmp    eax,ebx
        jl L_4ec290
        lea    ecx,[esp+44h]
        push   32h
        push   ecx
        mov    ecx,esi
        call pc2_fn_54cbc1
        mov    eax,DWORD PTR [esp+1ch]
        mov    ecx,DWORD PTR [ebp+4h]
        lea    edx,[eax+eax*8]
        lea    eax,[ecx+edx*8+25h]
        lea    edx,[esp+44h]
        mov    DWORD PTR [esp+20h],eax
L_4ec21a:
        mov    cl,BYTE PTR [edx]
        mov    eax,DWORD PTR [esp+20h]
        mov    BYTE PTR [esp+13h],cl
        cmp    cl,BYTE PTR [eax]
        jne L_4ec256
        mov    al,cl
        cmp    al,bl
        je L_4ec252
        mov    cl,BYTE PTR [edx+1h]
        mov    eax,DWORD PTR [esp+20h]
        mov    BYTE PTR [esp+13h],cl
        cmp    cl,BYTE PTR [eax+1h]
        jne L_4ec256
        mov    ecx,eax
        mov    al,BYTE PTR [esp+13h]
        add    edx,2h
        add    ecx,2h
        cmp    al,bl
        mov    DWORD PTR [esp+20h],ecx
        jne L_4ec21a
L_4ec252:
        xor    eax,eax
        jmp L_4ec25b
L_4ec256:
        sbb    eax,eax
        sbb    eax,0ffffffffh
L_4ec25b:
        cmp    eax,ebx
        je L_4ec28c
        lea    ecx,[esp+44h]
        push   ecx
        mov    ecx,DWORD PTR [ebp+4h]
        call pc2_fn_4eab80
        movsx  eax,ax
        cmp    eax,0ffffffffh
        mov    DWORD PTR [esp+1ch],eax
        jne L_4ec290
        lea    edx,[esp+44h]
        push   edx
        push   eax
        call pc2_fn_4eb8e0
        add    esp,8h
        mov    DWORD PTR [esp+1ch],eax
        jmp L_4ec290
L_4ec28c:
        mov    eax,DWORD PTR [esp+1ch]
L_4ec290:
        mov    ecx,DWORD PTR [ebp+4ch]
        mov    edx,DWORD PTR [edi+ecx*1+8h]
        mov    DWORD PTR [edx+10h],eax
        mov    eax,DWORD PTR [ebp+4ch]
        mov    edx,DWORD PTR [esp+1ch]
        mov    ecx,DWORD PTR [edi+eax*1+8h]
        add    ecx,10h
        push   ecx
        push   edx
        mov    ecx,ebp
        call pc2_fn_4eef40
        mov    eax,DWORD PTR [esp+18h]
        inc    eax
        mov    DWORD PTR [esp+18h],eax
        mov    edi,eax
L_4ec2bc:
        mov    eax,DWORD PTR [ebp+20h]
        imul   eax,DWORD PTR [ebp+1ch]
        cmp    edi,eax
        jl L_4ebfa0
L_4ec2cb:
        lea    ecx,[esp+2ch]
        push   4h
        push   ecx
        mov    ecx,esi
        mov    DWORD PTR [ebp+118h],ebx
        call pc2_fn_54cbc1
        cmp    DWORD PTR [esp+2ch],1h
        jne L_4ec336
        lea    edx,[esp+2ch]
        push   4h
        push   edx
        mov    ecx,esi
        call pc2_fn_54cbc1
        mov    eax,DWORD PTR [esp+2ch]
        lea    ecx,[eax*4+4h]
        push   ecx
        call pc2_operator_new
        mov    edx,DWORD PTR [esp+30h]
        add    esp,4h
        xor    edi,edi
        inc    edx
        test   edx,edx
        mov    DWORD PTR [ebp+118h],eax
        jle L_4ec336
L_4ec319:
        mov    eax,DWORD PTR [ebp+118h]
        push   4h
        lea    ecx,[eax+edi*4]
        push   ecx
        mov    ecx,esi
        call pc2_fn_54cbc1
        mov    edx,DWORD PTR [esp+2ch]
        inc    edi
        inc    edx
        cmp    edi,edx
        jl L_4ec319
L_4ec336:
        cmp    DWORD PTR [ebp+6ch],ebx
        je L_4ec482
        cmp    DWORD PTR [ebp+0ch],10h
        jne L_4ec3f8
        lea    eax,[ebp+7ch]
        push   2eh
        push   eax
        call pc2_fn_54efd0
        add    esp,8h
        cmp    eax,ebx
        je L_4ec35d
        mov    BYTE PTR [eax],bl
L_4ec35d:
        mov    edi,5719f8h
        or     ecx,0ffffffffh
        xor    eax,eax
        push   50h
        repne scasb
        not    ecx
        sub    edi,ecx
        mov    esi,edi
        mov    edx,ecx
        lea    edi,[ebp+7ch]
        or     ecx,0ffffffffh
        repne scasb
        mov    ecx,edx
        dec    edi
        shr    ecx,2h
        rep movsd
        mov    ecx,edx
        and    ecx,3h
        rep movsb
        call pc2_operator_new
        add    esp,4h
        mov    DWORD PTR [esp+30h],eax
        cmp    eax,ebx
        mov    DWORD PTR [esp+250h],ebx
        je L_4ec3c7
        mov    ecx,DWORD PTR [ebp+4h]
        push   ebx
        push   ebx
        lea    edx,[esp+3ch]
        mov    ecx,DWORD PTR [ecx+2bf44h]
        push   ebx
        push   edx
        lea    edx,[ebp+7ch]
        push   edx
        push   ecx
        mov    ecx,DWORD PTR pc2_mem_57c5c8
        push   ecx
        mov    ecx,eax
        call pc2_fn_53c7f0
        jmp L_4ec3c9
L_4ec3c7:
        xor    eax,eax
L_4ec3c9:
        mov    DWORD PTR [ebp+74h],eax
        mov    eax,DWORD PTR [esp+34h]
        cmp    eax,ebx
        mov    DWORD PTR [esp+250h],0ffffffffh
        je L_4ec3f0
        lea    eax,[ebp+7ch]
        push   eax
        push   571a70h
        call pc2_fn_48e0a0
        add    esp,8h
L_4ec3f0:
        mov    DWORD PTR [ebp+78h],ebx
        jmp L_4ec485
L_4ec3f8:
        push   57bb44h
        lea    edx,[esp+14ch]
        push   571b10h
        push   edx
        call pc2_string_format
        push   11ch
        call pc2_operator_new
        add    esp,10h
        mov    DWORD PTR [esp+30h],eax
        cmp    eax,ebx
        mov    DWORD PTR [esp+250h],1h
        je L_4ec457
        mov    ecx,DWORD PTR [ebp+4h]
        lea    edx,[esp+34h]
        push   ebx
        push   edx
        mov    ecx,DWORD PTR [ecx+2bf44h]
        lea    edx,[esp+150h]
        push   ecx
        mov    ecx,DWORD PTR pc2_mem_57c5c8
        push   ecx
        push   edx
        mov    ecx,eax
        call pc2_fn_535fc0
        jmp L_4ec459
L_4ec457:
        xor    eax,eax
L_4ec459:
        mov    DWORD PTR [ebp+70h],eax
        mov    eax,DWORD PTR [esp+34h]
        cmp    eax,ebx
        mov    DWORD PTR [esp+250h],0ffffffffh
        je L_4ec485
        lea    eax,[ebp+7ch]
        push   eax
        push   571a70h
        call pc2_fn_48e0a0
        add    esp,8h
        jmp L_4ec485
L_4ec482:
        mov    DWORD PTR [ebp+70h],ebx
L_4ec485:
        cmp    DWORD PTR [ebp+0ch],10h
        jne L_4ec494
        mov    ecx,ebp
        call pc2_fn_4f3b70
        jmp L_4ec4a5
L_4ec494:
        push   ebx
        push   ebx
        push   ebx
        lea    eax,[ebp+100h]
        push   ebx
        push   eax
        call   DWORD PTR pc2_mem_55c280
L_4ec4a5:
        mov    esi,DWORD PTR [ebp+118h]
        xor    ecx,ecx
        cmp    esi,ebx
        push   1h
        sete   cl
        push   ecx
        push   1h
        mov    ecx,ebp
        mov    DWORD PTR [ebp+110h],ebx
        mov    DWORD PTR [ebp+114h],ebx
        call pc2_fn_4f37d0
        mov    ecx,DWORD PTR [esp+248h]
        pop    edi
        pop    esi
        pop    ebp
        pop    ebx
        mov    DWORD PTR fs:[0],ecx
        add    esp,244h
        ret    4h
    }
}
