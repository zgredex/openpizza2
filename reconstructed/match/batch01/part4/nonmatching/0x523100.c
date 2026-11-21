/* NOT DECOMPILED C: naked instruction transcription kept only as reference.
   Marked unmatched; see ../worklog.md. */
/* PC2 byte-match candidate. Build with CL /O2 /TP; see worklog.md and
   verify.py for the exact matcher command and symbol addresses. */
/* Naked transcription of the shipped function. */
extern "C" void __cdecl pc2_fn_401280(void);
extern "C" void __cdecl pc2_fn_48e0a0(void);
extern "C" void __cdecl pc2_fn_51e9d0(void);
extern "C" void __cdecl pc2_fn_522e80(void);
extern "C" void __cdecl pc2_fn_526480(void);
extern "C" void __cdecl pc2_fn_52e4b0(void);
extern "C" void __cdecl pc2_fn_537230(void);
extern "C" void __cdecl pc2_fn_5374b0(void);
extern "C" void __cdecl pc2_fn_538af0(void);
extern "C" void __cdecl pc2_fn_539ea0(void);
extern "C" void __cdecl pc2_fn_539f00(void);
extern "C" void __cdecl pc2_fn_539f90(void);
extern "C" void __cdecl pc2_fn_53a060(void);
extern "C" void __cdecl pc2_fn_54a660(void);
extern "C" void __cdecl pc2_operator_new(void);
extern "C" int pc2_mem_55c078;
extern "C" int pc2_mem_55c09c;
extern "C" int pc2_mem_55c1ac;
extern "C" int pc2_mem_55c250;
extern "C" int pc2_mem_57c1e0;

extern "C" __declspec(naked) void __cdecl UI_UI_Manager_Construct(void)
{
    __asm {
        push   0ffffffffh
        push   55a688h
        mov    eax,fs:[0]
        push   eax
        mov    DWORD PTR fs:[0],esp
        push   ecx
        push   ebx
        push   ebp
        push   esi
        mov    esi,ecx
        xor    ebp,ebp
        push   edi
        push   ebp
        lea    ecx,[esi+1cch]
        mov    DWORD PTR [esp+14h],esi
        call pc2_fn_401280
        push   ebp
        lea    ecx,[esi+8324h]
        mov    DWORD PTR [esp+20h],ebp
        call pc2_fn_522e80
        mov    DWORD PTR [esi],55c778h
        mov    DWORD PTR [esi+83e0h],0fa0h
        mov    eax,0ffffd8f1h
        mov    DWORD PTR [esi+83a8h],ebp
        mov    DWORD PTR [esi+83a4h],eax
        mov    DWORD PTR [esi+83a0h],eax
        mov    DWORD PTR [esi+839ch],ebp
        mov    DWORD PTR [esi+284h],ebp
        mov    BYTE PTR [esp+1ch],1h
        mov    DWORD PTR [esi+8318h],ebp
        call   DWORD PTR pc2_mem_55c1ac
        mov    DWORD PTR [esi+830ch],eax
        mov    DWORD PTR [esi+1c8h],ebp
        mov    ecx,DWORD PTR [esp+28h]
        mov    DWORD PTR [esi+1b8h],ebp
        mov    DWORD PTR [esi+1c4h],ebp
        mov    DWORD PTR [esi+1bch],ebp
        mov    DWORD PTR [esi+224h],ebp
        mov    DWORD PTR [esi+22ch],ebp
        mov    eax,1h
        mov    DWORD PTR [esi+230h],ebp
        mov    DWORD PTR [esi+234h],eax
        mov    DWORD PTR [esi+238h],eax
        mov    DWORD PTR [esi+240h],ebp
        mov    DWORD PTR [esi+8320h],ecx
        mov    DWORD PTR [esi+278h],ebp
        mov    edx,DWORD PTR [esp+30h]
        mov    ecx,DWORD PTR [esp+34h]
        mov    DWORD PTR [esi+32b4h],ebp
        mov    DWORD PTR [esi+32b8h],ebp
        mov    DWORD PTR [esi+82bch],ebp
        mov    DWORD PTR [esi+82c0h],ebp
        mov    DWORD PTR [esi+228h],ebp
        mov    DWORD PTR [esi+270h],edx
        mov    DWORD PTR [esi+274h],ecx
        mov    DWORD PTR [esi+82c4h],ebp
        mov    DWORD PTR [esi+82c8h],ebp
        mov    DWORD PTR [esi+82cch],ebp
        mov    DWORD PTR [esi+82d4h],ebp
        mov    DWORD PTR [esi+82d8h],ebp
        mov    DWORD PTR [esi+82e0h],ebp
        mov    DWORD PTR [esi+82e4h],ebp
        mov    DWORD PTR [esi+82e8h],18h
        mov    DWORD PTR [esi+82dch],ebp
        mov    DWORD PTR [esi+82d0h],ebp
        mov    DWORD PTR [esi+82ech],eax
        mov    eax,1f4h
        mov    DWORD PTR [esi+82f4h],eax
        mov    DWORD PTR [esi+82f8h],ebp
        mov    DWORD PTR [esi+82fch],ebp
        mov    edx,DWORD PTR [esp+38h]
        mov    DWORD PTR [esi+8300h],ebp
        mov    DWORD PTR [esi+8304h],ebp
        mov    DWORD PTR [esi+8308h],ebp
        mov    DWORD PTR [esi+248h],ebp
        mov    DWORD PTR [esi+24ch],ebp
        mov    DWORD PTR [esi+831ch],ebp
        mov    DWORD PTR [esi+8338h],ebp
        mov    DWORD PTR [esi+833ch],ebp
        mov    DWORD PTR [esi+8348h],ebp
        mov    DWORD PTR [esi+8340h],eax
        mov    DWORD PTR [esi+8344h],32h
        mov    DWORD PTR [esi+8350h],ebp
        mov    DWORD PTR [esi+834ch],ebp
        mov    DWORD PTR [esi+1c0h],ebp
        lea    eax,[esi+83b0h]
        mov    DWORD PTR [esi+8358h],edx
        push   eax
        mov    DWORD PTR [esi+83ach],ebp
        mov    DWORD PTR [esi+83b8h],ebp
        mov    DWORD PTR [esi+1a4h],0fffffc19h
        mov    DWORD PTR [esi+83e4h],ebp
        call   DWORD PTR pc2_mem_55c078
        lea    ebx,[esi+250h]
        mov    ecx,8h
        xor    eax,eax
        mov    edi,ebx
        rep stosd
        mov    ecx,DWORD PTR [esi+8320h]
        push   esi
        push   0ffffffebh
        push   ecx
        call   DWORD PTR pc2_mem_55c250
        lea    edi,[esi+14h]
        mov    ecx,64h
        xor    eax,eax
        mov    edx,DWORD PTR [esp+2ch]
        rep stosd
        mov    ecx,8h
        mov    edi,ebx
        rep stosd
        mov    edi,DWORD PTR [esp+24h]
        mov    DWORD PTR [esi+10h],edx
        mov    ecx,edi
        call pc2_fn_539ea0
        mov    ebx,1h
        mov    DWORD PTR [esi+0ch],eax
        mov    DWORD PTR [esi+1b4h],ebx
        mov    eax,DWORD PTR [edi+98h]
        cmp    eax,ebp
        jne L_523435
        mov    eax,DWORD PTR [esi+8358h]
        mov    DWORD PTR [esi+1b4h],ebp
        cmp    eax,ebp
        jne L_5233ee
        mov    ecx,edi
        call pc2_fn_539f00
        cmp    eax,2h
        jne L_523393
        mov    eax,DWORD PTR [edi+40h]
        cmp    eax,ebp
        je L_523389
        mov    eax,DWORD PTR [eax+8h]
        mov    DWORD PTR [esi+1c0h],eax
        jmp L_5233cf
L_523389:
        xor    eax,eax
        mov    DWORD PTR [esi+1c0h],eax
        jmp L_5233cf
L_523393:
        mov    ecx,DWORD PTR [esi+274h]
        mov    edx,DWORD PTR [esi+270h]
        push   2800h
        lea    eax,[esp+2ch]
        push   ebp
        push   eax
        push   ecx
        push   edx
        mov    ecx,edi
        call pc2_fn_538af0
        mov    DWORD PTR [esi+1c0h],eax
        mov    eax,DWORD PTR [esp+28h]
        cmp    eax,ebp
        je L_5233cf
        push   eax
        push   574064h
        call pc2_fn_48e0a0
        add    esp,8h
L_5233cf:
        mov    eax,DWORD PTR [esi+8320h]
        mov    ecx,edi
        push   eax
        call pc2_fn_539f90
        mov    ecx,DWORD PTR [esi+1c0h]
        push   ebp
        push   ecx
        mov    ecx,edi
        call pc2_fn_53a060
        jmp L_523435
L_5233ee:
        push   11ch
        call pc2_operator_new
        add    esp,4h
        mov    DWORD PTR [esp+28h],eax
        cmp    eax,ebp
        mov    BYTE PTR [esp+1ch],2h
        je L_523421
        mov    edx,DWORD PTR [esi+274h]
        mov    ecx,DWORD PTR [esi+270h]
        push   2h
        push   edx
        push   ecx
        mov    ecx,eax
        call pc2_fn_537230
        jmp L_523423
L_523421:
        xor    eax,eax
L_523423:
        mov    ecx,eax
        mov    BYTE PTR [esp+1ch],1h
        mov    DWORD PTR [esi+1bch],eax
        call pc2_fn_5374b0
L_523435:
        push   58h
        call pc2_operator_new
        add    esp,4h
        mov    DWORD PTR [esp+28h],eax
        cmp    eax,ebp
        mov    BYTE PTR [esp+1ch],3h
        je L_52345a
        push   574050h
        mov    ecx,eax
        call pc2_fn_401280
        jmp L_52345c
L_52345a:
        xor    eax,eax
L_52345c:
        push   28h
        mov    BYTE PTR [esp+20h],1h
        mov    DWORD PTR [esi+1c8h],eax
        mov    DWORD PTR [esi+8314h],ebp
        call pc2_operator_new
        add    esp,4h
        mov    DWORD PTR [esp+28h],eax
        cmp    eax,ebp
        mov    BYTE PTR [esp+1ch],4h
        je L_52348e
        push   esi
        mov    ecx,eax
        call pc2_fn_51e9d0
        jmp L_523490
L_52348e:
        xor    eax,eax
L_523490:
        mov    DWORD PTR [esi+8310h],eax
        mov    ecx,0ffffffh
        mov    eax,0ff000000h
        mov    DWORD PTR [esi+23ch],ebp
        mov    DWORD PTR [esi+288h],ebp
        mov    DWORD PTR [esi+298h],ecx
        mov    DWORD PTR [esi+29ch],ebp
        mov    DWORD PTR [esi+2a0h],eax
        mov    DWORD PTR [esi+2a4h],eax
        mov    DWORD PTR [esi+2a8h],eax
        mov    DWORD PTR [esi+28ch],0c0c0c0h
        mov    DWORD PTR [esi+290h],ecx
        mov    DWORD PTR [esi+294h],0ff0000h
        mov    DWORD PTR [esi+2ach],574048h
        mov    DWORD PTR [esi+2b0h],574044h
        mov    edx,DWORD PTR pc2_mem_57c1e0
        push   574038h
        push   0ff0000h
        push   edx
        mov    BYTE PTR [esp+28h],1h
        call pc2_fn_54a660
        push   50h
        mov    DWORD PTR [esi+8h],ebp
        mov    DWORD PTR [esi+1a4h],0fffffc19h
        mov    DWORD PTR [esi+284h],ebx
        call pc2_operator_new
        add    esp,10h
        mov    DWORD PTR [esp+28h],eax
        cmp    eax,ebp
        mov    BYTE PTR [esp+1ch],5h
        je L_523548
        push   esi
        push   edi
        mov    ecx,eax
        call pc2_fn_52e4b0
        jmp L_52354a
L_523548:
        xor    eax,eax
L_52354a:
        push   574028h
        mov    ecx,esi
        mov    BYTE PTR [esp+20h],1h
        mov    DWORD PTR [esi+244h],eax
        call pc2_fn_526480
        push   574018h
        push   ebx
        push   ebx
        push   ebp
        call   DWORD PTR pc2_mem_55c09c
        mov    ecx,DWORD PTR [esp+14h]
        mov    DWORD PTR [esi+8354h],eax
        mov    eax,esi
        pop    edi
        pop    esi
        pop    ebp
        pop    ebx
        mov    DWORD PTR fs:[0],ecx
        add    esp,10h
        ret    18h
    }
}
