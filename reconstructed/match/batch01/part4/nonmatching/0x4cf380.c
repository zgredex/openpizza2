/* NOT DECOMPILED C: naked instruction transcription kept only as reference.
   Marked unmatched; see ../worklog.md. */
/* PC2 byte-match candidate. Build with CL /O2 /TP; see worklog.md and
   verify.py for the exact matcher command and symbol addresses. */
/* Naked transcription of the shipped function. */
extern "C" void __cdecl pc2_fn_4017f0(void);
extern "C" void __cdecl pc2_fn_482820(void);
extern "C" void __cdecl pc2_fn_4d5b90(void);
extern "C" void __cdecl pc2_fn_4d5c40(void);
extern "C" void __cdecl pc2_fn_4e2280(void);
extern "C" void __cdecl pc2_fn_52ff50(void);
extern "C" void __cdecl pc2_fn_531620(void);
extern "C" void __cdecl pc2_fn_5316f0(void);
extern "C" void __cdecl pc2_fn_531740(void);
extern "C" void __cdecl pc2_fn_532330(void);
extern "C" void __cdecl pc2_fn_532520(void);
extern "C" int pc2_mem_57c670;

extern "C" __declspec(naked) void __cdecl UI_CityAdminPanel_UpdateTabButtons(void)
{
    __asm {
        push   ecx
        mov    eax,pc2_mem_57c670
        push   ebx
        push   esi
        push   edi
        mov    ecx,DWORD PTR [eax+290h]
        mov    edx,DWORD PTR [eax+2f4h]
        push   0h
        push   edx
        mov    edi,DWORD PTR [eax+ecx*4+298h]
        lea    ecx,[eax+4h]
        call pc2_fn_4017f0
        mov    ecx,DWORD PTR pc2_mem_57c670
        mov    esi,eax
        call pc2_fn_482820
        mov    eax,DWORD PTR [esi+eax*4+0c20h]
        mov    esi,DWORD PTR [esp+14h]
        mov    ecx,esi
        mov    DWORD PTR [esp+0ch],eax
        call pc2_fn_532520
        push   3fdh
        push   403h
        push   402h
        push   3f9h
        push   3f8h
        push   401h
        push   404h
        push   3feh
        push   3f4h
        push   9h
        push   0h
        push   esi
        call pc2_fn_532330
        add    esp,30h
        xor    ebx,ebx
        cmp    edi,1h
        mov    ecx,esi
        sete   bl
        push   ebx
        push   3f4h
        call pc2_fn_52ff50
        push   ebx
        push   3f4h
        mov    ecx,esi
        call pc2_fn_531620
        xor    ebx,ebx
        cmp    edi,2h
        sete   bl
        push   ebx
        push   3feh
        mov    ecx,esi
        call pc2_fn_52ff50
        push   ebx
        push   3feh
        mov    ecx,esi
        call pc2_fn_531620
        mov    eax,pc2_mem_57c670
        push   0h
        mov    ecx,DWORD PTR [eax+2f4h]
        push   ecx
        lea    ecx,[eax+4h]
        call pc2_fn_4017f0
        mov    ecx,eax
        call pc2_fn_4d5b90
        mov    ebx,DWORD PTR [eax+14h]
        test   eax,eax
        je L_4cf474
        mov    edx,DWORD PTR [eax]
        push   1h
        mov    ecx,eax
        call   DWORD PTR [edx]
L_4cf474:
        mov    eax,pc2_mem_57c670
        push   0h
        mov    ecx,DWORD PTR [eax+2f4h]
        push   ecx
        lea    ecx,[eax+4h]
        call pc2_fn_4017f0
        mov    ecx,eax
        call pc2_fn_4d5c40
        add    ebx,DWORD PTR [eax+14h]
        test   eax,eax
        je L_4cf4a0
        mov    edx,DWORD PTR [eax]
        push   1h
        mov    ecx,eax
        call   DWORD PTR [edx]
L_4cf4a0:
        xor    eax,eax
        cmp    edi,0bh
        sete   al
        push   ebp
        mov    ebp,eax
        push   ebp
        push   404h
        mov    ecx,esi
        call pc2_fn_52ff50
        push   ebp
        push   404h
        mov    ecx,esi
        call pc2_fn_531620
        xor    ecx,ecx
        test   ebx,ebx
        setg   cl
        push   ecx
        push   404h
        mov    ecx,esi
        call pc2_fn_5316f0
        xor    ebx,ebx
        cmp    edi,4h
        sete   bl
        push   ebx
        push   401h
        mov    ecx,esi
        call pc2_fn_52ff50
        push   ebx
        push   401h
        mov    ecx,esi
        call pc2_fn_531620
        xor    ebx,ebx
        cmp    edi,5h
        sete   bl
        push   ebx
        push   3f8h
        mov    ecx,esi
        call pc2_fn_52ff50
        push   ebx
        push   3f8h
        mov    ecx,esi
        call pc2_fn_531620
        mov    eax,DWORD PTR [esp+10h]
        xor    ebx,ebx
        test   eax,eax
        setg   bl
        push   ebx
        push   3f8h
        mov    ecx,esi
        call pc2_fn_5316f0
        mov    eax,pc2_mem_57c670
        mov    edx,DWORD PTR [eax+2ech]
        mov    ecx,DWORD PTR [eax+edx*4+200h]
        call pc2_fn_4e2280
        cmp    eax,3h
        jl L_4cf584
        xor    eax,eax
        cmp    edi,6h
        sete   al
        mov    ebp,eax
        mov    ecx,esi
        push   ebp
        push   3f9h
        call pc2_fn_52ff50
        push   ebp
        push   3f9h
        mov    ecx,esi
        call pc2_fn_531620
        push   ebx
        push   3f9h
        mov    ecx,esi
        call pc2_fn_5316f0
        jmp L_4cf59e
L_4cf584:
        push   0h
        push   3f9h
        mov    ecx,esi
        call pc2_fn_52ff50
        push   3f9h
        mov    ecx,esi
        call pc2_fn_531740
L_4cf59e:
        mov    ecx,DWORD PTR pc2_mem_57c670
        pop    ebp
        mov    eax,DWORD PTR [ecx+218h]
        test   eax,eax
        je L_4cf5b5
        cmp    DWORD PTR [eax+4h],19h
        je L_4cf5e4
L_4cf5b5:
        push   0h
        push   402h
        mov    ecx,esi
        call pc2_fn_5316f0
        push   0h
        push   403h
        mov    ecx,esi
        call pc2_fn_5316f0
        push   0h
        push   3fdh
        mov    ecx,esi
        call pc2_fn_5316f0
        pop    edi
        pop    esi
        pop    ebx
        pop    ecx
        ret
L_4cf5e4:
        xor    ebx,ebx
        cmp    edi,8h
        sete   bl
        push   ebx
        push   402h
        mov    ecx,esi
        call pc2_fn_52ff50
        push   ebx
        push   402h
        mov    ecx,esi
        call pc2_fn_531620
        mov    eax,pc2_mem_57c670
        push   0h
        mov    edx,DWORD PTR [eax+2f4h]
        lea    ecx,[eax+4h]
        push   edx
        call pc2_fn_4017f0
        mov    ecx,DWORD PTR [eax+10c4h]
        test   ecx,ecx
        jle L_4cf635
        mov    edx,DWORD PTR [esp+0ch]
        xor    eax,eax
        cmp    edx,1h
        setg   al
        push   eax
        jmp L_4cf637
L_4cf635:
        push   0h
L_4cf637:
        push   402h
        mov    ecx,esi
        call pc2_fn_5316f0
        xor    ebx,ebx
        cmp    edi,9h
        sete   bl
        push   ebx
        push   403h
        mov    ecx,esi
        call pc2_fn_52ff50
        push   ebx
        push   403h
        mov    ecx,esi
        call pc2_fn_531620
        xor    ecx,ecx
        cmp    edi,0ch
        sete   cl
        push   ecx
        push   3fdh
        mov    ecx,esi
        call pc2_fn_52ff50
        push   1h
        push   3fdh
        mov    ecx,esi
        call pc2_fn_5316f0
        pop    edi
        pop    esi
        pop    ebx
        pop    ecx
        ret
    }
}
