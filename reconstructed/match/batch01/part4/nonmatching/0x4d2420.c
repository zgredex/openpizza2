/* NOT DECOMPILED C: naked instruction transcription kept only as reference.
   Marked unmatched; see ../worklog.md. */
/* PC2 byte-match candidate. Build with CL /O2 /TP; see worklog.md and
   verify.py for the exact matcher command and symbol addresses. */
/* Naked transcription of the shipped function. */
extern "C" void __cdecl pc2_fn_401320(void);
extern "C" void __cdecl pc2_fn_401340(void);
extern "C" void __cdecl pc2_fn_4017f0(void);
extern "C" void __cdecl pc2_fn_488be0(void);
extern "C" void __cdecl pc2_fn_4d2600(void);
extern "C" void __cdecl pc2_fn_4d2d80(void);
extern "C" void __cdecl pc2_fn_4dc420(void);
extern "C" void __cdecl pc2_fn_4ed780(void);
extern "C" void __cdecl pc2_fn_4ed880(void);
extern "C" void __cdecl pc2_fn_4eeef0(void);
extern "C" void __cdecl pc2_fn_4eef40(void);
extern "C" void __cdecl pc2_fn_4f43c0(void);
extern "C" void __cdecl pc2_fn_4f5990(void);
extern "C" int pc2_mem_55c280;
extern "C" int pc2_mem_57c670;

extern "C" __declspec(naked) void __cdecl UI_MapObject_SetTypeAndSprite(void)
{
    __asm {
        sub    esp,20h
        push   esi
        push   edi
        mov    edi,ecx
        push   0h
        mov    ecx,DWORD PTR pc2_mem_57c670
        mov    eax,DWORD PTR [edi+28h]
        add    ecx,4h
        push   eax
        call pc2_fn_4017f0
        mov    esi,DWORD PTR [eax+0fa8h]
        test   esi,esi
        je L_4d25ea
        mov    eax,DWORD PTR [edi+4h]
        push   ebx
        mov    ebx,DWORD PTR [esp+30h]
        cmp    eax,0fh
        push   ebp
        jne L_4d2492
        cmp    ebx,0fh
        je L_4d2492
        mov    eax,DWORD PTR [edi+8h]
        mov    ecx,DWORD PTR pc2_mem_57c670
        push   eax
        call pc2_fn_488be0
        mov    ebp,eax
        test   ebp,ebp
        je L_4d2492
        mov    eax,pc2_mem_57c670
        push   0h
        mov    ecx,DWORD PTR [eax+2f4h]
        push   ecx
        lea    ecx,[eax+4h]
        call pc2_fn_4017f0
        push   ebp
        push   edi
        push   0h
        mov    ecx,eax
        call pc2_fn_4dc420
L_4d2492:
        push   0ffffffffh
        push   esi
        mov    ecx,edi
        call pc2_fn_4d2d80
        mov    eax,DWORD PTR [edi+24h]
        mov    ebp,DWORD PTR [esp+38h]
        mov    DWORD PTR [edi+20h],ebp
        mov    DWORD PTR [edi+4h],ebx
        lea    edx,[eax+eax*2]
        mov    eax,DWORD PTR [esi+4ch]
        lea    ebx,[eax+edx*4]
        test   ebx,ebx
        je L_4d25e1
        mov    ecx,DWORD PTR pc2_mem_57c670
        mov    ecx,DWORD PTR [ecx+240h]
        call pc2_fn_401320
        mov    edx,DWORD PTR [ebx+8h]
        mov    ecx,esi
        add    edx,10h
        push   edx
        call pc2_fn_4eeef0
        lea    eax,[esp+20h]
        mov    ecx,esi
        push   eax
        push   ebx
        call pc2_fn_4f5990
        mov    ecx,DWORD PTR [esi+24h]
        mov    edx,DWORD PTR [esp+20h]
        mov    eax,DWORD PTR [esp+28h]
        add    edx,ecx
        mov    ecx,DWORD PTR [esp+24h]
        mov    DWORD PTR [esp+20h],edx
        mov    edx,DWORD PTR [esi+24h]
        add    eax,edx
        mov    edx,DWORD PTR [esp+2ch]
        mov    DWORD PTR [esp+28h],eax
        mov    eax,DWORD PTR [esi+28h]
        add    ecx,eax
        lea    eax,[esp+20h]
        mov    DWORD PTR [esp+24h],ecx
        mov    ecx,DWORD PTR [esi+28h]
        add    edx,ecx
        push   eax
        mov    DWORD PTR [esp+30h],edx
        mov    edx,DWORD PTR [ebx+8h]
        mov    ecx,esi
        mov    DWORD PTR [edx+10h],ebp
        call pc2_fn_4f43c0
        mov    ecx,DWORD PTR [ebx+8h]
        add    ecx,10h
        push   ecx
        push   ebp
        mov    ecx,esi
        call pc2_fn_4eef40
        cmp    DWORD PTR [edi+4h],0fh
        jne L_4d2577
        mov    eax,DWORD PTR [edi+8h]
        mov    ecx,DWORD PTR pc2_mem_57c670
        push   eax
        call pc2_fn_488be0
        mov    ebp,eax
        test   ebp,ebp
        je L_4d2577
        mov    eax,pc2_mem_57c670
        push   0h
        mov    edx,DWORD PTR [eax+2f4h]
        lea    ecx,[eax+4h]
        push   edx
        call pc2_fn_4017f0
        push   ebp
        push   edi
        push   1h
        mov    ecx,eax
        call pc2_fn_4dc420
L_4d2577:
        lea    eax,[esp+18h]
        lea    ecx,[esp+1ch]
        push   eax
        push   ecx
        push   ebx
        mov    ecx,esi
        call pc2_fn_4ed880
        lea    edx,[esp+14h]
        lea    ecx,[esp+10h]
        push   edx
        push   ecx
        push   eax
        push   ebx
        mov    ecx,esi
        call pc2_fn_4ed780
        mov    eax,DWORD PTR [esp+10h]
        mov    ebx,DWORD PTR [esi+24h]
        mov    ecx,DWORD PTR [esp+14h]
        add    eax,ebx
        mov    DWORD PTR [esp+10h],eax
        mov    edx,DWORD PTR [esi+28h]
        add    ecx,edx
        mov    edx,DWORD PTR [esp+18h]
        add    edx,ecx
        mov    DWORD PTR [esp+14h],ecx
        push   edx
        mov    edx,DWORD PTR [esp+20h]
        add    edx,eax
        push   edx
        push   ecx
        push   eax
        lea    eax,[edi+10h]
        push   eax
        call   DWORD PTR pc2_mem_55c280
        mov    ecx,DWORD PTR pc2_mem_57c670
        mov    ecx,DWORD PTR [ecx+240h]
        call pc2_fn_401340
L_4d25e1:
        mov    ecx,edi
        call pc2_fn_4d2600
        pop    ebp
        pop    ebx
L_4d25ea:
        pop    edi
        pop    esi
        add    esp,20h
        ret    8h
    }
}
