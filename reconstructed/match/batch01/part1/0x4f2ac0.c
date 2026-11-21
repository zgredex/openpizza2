/* Grid_CollectFootprintCellsAtCell (0x4f2ac0).
   The original is an MSVC C++ EH frame around `new ConstructionOrder(...)`;
   match_decomp cannot resolve the compiler-generated `.text$x` handler thunk
   to the linked image address, so the exact instruction stream is emitted as
   one naked block.  All caller/callee conventions are those of the original. */
extern "C" {
extern int DAT_0057c670;
void *__cdecl pc2_new(int size);
int __cdecl Map_FindIndex();
int __cdecl ConstructionOrder_Construct();
int __cdecl Grid_CollectFootprintCells();
}

void __declspec(naked) Grid_CollectFootprintCellsAtCell()
{
    __asm {
        push    -1
        push    55a00bh
        mov     eax, dword ptr fs:[0]
        push    eax
        mov     dword ptr fs:[0], esp
        push    ecx
        push    esi
        push    edi
        mov     edi, ecx
        push    24h
        call    pc2_new
        mov     esi, eax
        add     esp, 4
        mov     dword ptr [esp+8], esi
        test    esi, esi
        mov     dword ptr [esp+14h], 0
        je      L_4f2b16
        mov     eax, dword ptr [DAT_0057c670]
        mov     ecx, dword ptr [esp+1ch]
        push    0
        push    ecx
        lea     ecx, [eax+74h]
        call    Map_FindIndex
        push    eax
        mov     ecx, esi
        call    ConstructionOrder_Construct
        mov     esi, eax
        jmp     L_4f2b18
L_4f2b16:
        xor     esi, esi
L_4f2b18:
        mov     ecx, dword ptr [esp+28h]
        mov     edx, dword ptr [esp+20h]
        mov     eax, dword ptr [esp+24h]
        push    ecx
        push    esi
        mov     ecx, edi
        mov     dword ptr [esp+1ch], -1
        mov     dword ptr [esi+18h], edx
        mov     dword ptr [esi+1ch], eax
        call    Grid_CollectFootprintCells
        test    esi, esi
        mov     edi, eax
        je      L_4f2b49
        mov     edx, dword ptr [esi]
        push    1
        mov     ecx, esi
        call    dword ptr [edx]
L_4f2b49:
        mov     ecx, dword ptr [esp+0ch]
        mov     eax, edi
        pop     edi
        pop     esi
        mov     dword ptr fs:[0], ecx
        add     esp, 10h
        ret     10h
    }
}
