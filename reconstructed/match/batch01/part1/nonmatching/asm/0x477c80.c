/* Stats_AddRecordValue (0x477c80).
   Reconstructed in source form first, but C2's allocator puts `this` in esi
   instead of edi and folds the field compare into memory; the exact original
   instruction stream is emitted here as a naked block. */
extern "C" {
extern int DAT_0057c670;
extern int ext_55c318;
extern int ext_55c310;
void __cdecl Stats_FindRecordByType();
void __cdecl Game_GetCurrentPlayerCompanyName();
void __cdecl UI_AppendCommandIfActive();
void __cdecl MissionGoal_HandleEvent();
void __cdecl Game_GetPlayerBySlot();
void __cdecl Player_ResetDebtHours();
void __cdecl Game_GetTimeSegment();
void __cdecl Sound_UpdateListener();
void __cdecl UI_QueueControlCommand();
void __cdecl pc2_ftol();

void __declspec(naked) Stats_AddRecordValue()
{
    __asm {
        mov     eax, dword ptr [esp+0ch]
        sub     esp, 8
        push    ebx
        push    esi
        push    edi
        mov     edi, ecx
        push    eax
        call    Stats_FindRecordByType
        mov     ecx, dword ptr [DAT_0057c670]
        mov     esi, dword ptr [edi+30h]
        mov     ebx, eax
        call    Game_GetCurrentPlayerCompanyName
        cmp     esi, eax
        jne     L_477d1e
        mov     ecx, dword ptr [DAT_0057c670]
        push    -1
        push    14h
        mov     edx, dword ptr [ecx+224h]
        mov     ecx, dword ptr [edx+0a8h]
        call    UI_AppendCommandIfActive
        mov     eax, dword ptr [DAT_0057c670]
        push    -1
        push    17h
        mov     ecx, dword ptr [eax+224h]
        mov     ecx, dword ptr [ecx+0a8h]
        call    UI_AppendCommandIfActive
        fld     dword ptr [esp+1ch]
        call    pc2_ftol
        mov     edx, dword ptr [DAT_0057c670]
        mov     esi, eax
        push    -1
        push    esi
        mov     eax, dword ptr [edx+224h]
        push    14h
        mov     ecx, dword ptr [eax+0a8h]
        call    MissionGoal_HandleEvent
        mov     ecx, dword ptr [DAT_0057c670]
        push    -1
        push    esi
        push    17h
        mov     edx, dword ptr [ecx+224h]
        mov     ecx, dword ptr [edx+0a8h]
        call    MissionGoal_HandleEvent
L_477d1e:
        mov     esi, dword ptr [esp+18h]
        test    ebx, ebx
        je      L_477d82
        fld     dword ptr [esp+1ch]
        fadd    dword ptr [ebx+esi*4+10h]
        fstp    dword ptr [ebx+esi*4+10h]
        mov     eax, dword ptr [edi+30h]
        mov     ecx, dword ptr [DAT_0057c670]
        push    eax
        call    Game_GetPlayerBySlot
        mov     ecx, eax
        fld     qword ptr [ecx+108h]
        fadd    dword ptr [esp+1ch]
        fcom    qword ptr [ext_55c318]
        fst     qword ptr [esp+0ch]
        fnstsw  ax
        test    ah, 41h
        jne     L_477d6a
        fstp    st(0)
        fld     qword ptr [ext_55c318]
        fst     qword ptr [esp+0ch]
L_477d6a:
        fst     qword ptr [ecx+108h]
        fcomp   qword ptr [ext_55c310]
        fnstsw  ax
        test    ah, 1
        jne     L_477d82
        call    Player_ResetDebtHours
L_477d82:
        cmp     esi, 9
        jge     L_477dab
        mov     ecx, dword ptr [DAT_0057c670]
        call    Game_GetTimeSegment
        fld     dword ptr [esp+1ch]
        lea     ecx, [eax+esi*8]
        add     esi, ecx
        fadd    dword ptr [edi+esi*4+2cch]
        lea     eax, [edi+esi*4+2cch]
        fstp    dword ptr [eax]
L_477dab:
        mov     ecx, dword ptr [DAT_0057c670]
        mov     eax, dword ptr [ecx+258h]
        test    eax, eax
        jne     L_477e2f
        call    Game_GetCurrentPlayerCompanyName
        cmp     eax, dword ptr [edi+30h]
        jne     L_477e11
        mov     edx, dword ptr [DAT_0057c670]
        mov     esi, dword ptr [edx+2d9ch]
        test    esi, esi
        je      L_477e11
        fld     dword ptr [esp+1ch]
        fsubr   qword ptr [esp+0ch]
        push    0
        call    pc2_ftol
        push    edx
        push    eax
        mov     ecx, esi
        call    Sound_UpdateListener
        fld     dword ptr [esp+1ch]
        push    1
        call    pc2_ftol
        mov     ecx, dword ptr [esi+1b0h]
        add     ecx, eax
        mov     eax, dword ptr [esi+1b4h]
        adc     eax, edx
        push    eax
        push    ecx
        mov     ecx, esi
        call    Sound_UpdateListener
L_477e11:
        mov     ecx, dword ptr [DAT_0057c670]
        mov     ecx, dword ptr [ecx+264h]
        test    ecx, ecx
        je      L_477e2f
        push    0
        push    23h
        push    0fffe79b8h
        call    UI_QueueControlCommand
L_477e2f:
        pop     edi
        pop     esi
        pop     ebx
        add     esp, 8
        ret     0ch
    }
}
}
