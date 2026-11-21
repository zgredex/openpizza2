/* City_SettleAdvertisingCampaign - 0x4dce70, 470 bytes
 *
 * Carries an MSVC C++ EH registration frame (handler thunk 0x55924e); the
 * frame and body are reproduced at the instruction level so the absolute
 * handler reference resolves to the original image address.
 */
extern "C" void FUN_0055924e(void);
extern "C" void *__cdecl FUN_0054e221(unsigned int size);
extern "C" void *Game_GetPlayerBySlot();
extern "C" void Recipe_RecomputeAllStats();
extern "C" int Game_MapInputIndex();
extern "C" void Company_AddLedgerAmount();
extern "C" void *Game_GetPlayerCity();
extern "C" void UI_AppendCommandIfActive();
extern "C" void MissionGoal_HandleEvent();
extern "C" void *Player_Event_StreamConstruct();
extern "C" void List_Add();
extern "C" void String_Format();
extern "C" void UI_Briefing_Printf();

extern void *DAT_0057c670;
extern void *DAT_005828b0;
extern int DAT_00581744;

void __declspec(naked) __cdecl City_SettleAdvertisingCampaign(void)
{
    __asm
    {
        push    -1
        push    offset FUN_0055924e
        mov     eax, fs:[0]
        push    eax
        mov     fs:[0], esp
        sub     esp, 0x104
        push    ebx
        push    ebp
        push    esi
        push    edi
        xor     edi, edi
        mov     ebx, ecx
        mov     [esp+0x10], edi
        xor     ebp, ebp
    search_loop:
        mov     ecx, dword ptr DAT_0057c670
        push    edi
        call    Game_GetPlayerBySlot
        mov     esi, eax
        test    esi, esi
        je      next_player
        mov     eax, [esi+0x50]
        test    eax, eax
        mov     eax, dword ptr DAT_0057c670
        je      check_active
        mov     ecx, [eax+0x2ec]
        cmp     esi, [eax+ecx*4+0x200]
        jne     next_player
    check_active:
        mov     ecx, [esi+0x1d4]
        test    ecx, ecx
        je      no_recipe
        mov     eax, [esi+0x48]
        push    eax
        call    Recipe_RecomputeAllStats
        mov     edx, [ebx+0x1148]
        mov     ecx, [esi+0x1d4]
        push    edx
        call    Game_MapInputIndex
        jmp     compared
    no_recipe:
        xor     eax, eax
    compared:
        cmp     eax, [esp+0x10]
        jle     next_player
        mov     ebp, [esi+0x48]
        mov     [esp+0x10], eax
    next_player:
        inc     edi
        cmp     edi, 6
        jl      search_loop

        mov     ecx, dword ptr DAT_0057c670
        push    ebp
        call    Game_GetPlayerBySlot
        mov     esi, eax
        or      ebp, 0xffffffff
        push    0
        push    ebp
        mov     eax, [esi+0x54]
        push    ecx
        inc     eax
        mov     ecx, esi
        mov     [esi+0x54], eax
        fild    dword ptr [ebx+0x1150]
        fstp    dword ptr [esp]
        push    0x18
        call    Company_AddLedgerAmount
        mov     ecx, esi
        call    Game_GetPlayerCity
        mov     edi, eax
        mov     eax, dword ptr DAT_0057c670
        add     edi, 0x8c
        mov     ecx, [eax+0x2ec]
        cmp     esi, [eax+ecx*4+0x200]
        jne     skip_command
        mov     edx, [eax+0x224]
        push    ebp
        push    0x13
        mov     ecx, [edx+0xa8]
        call    UI_AppendCommandIfActive
        mov     eax, dword ptr DAT_0057c670
        push    ebp
        push    ebp
        push    0x13
        mov     ecx, [eax+0x224]
        mov     ecx, [ecx+0xa8]
        call    MissionGoal_HandleEvent
    skip_command:
        push    0xc
        call    FUN_0054e221
        add     esp, 4
        mov     [esp+0x10], eax
        test    eax, eax
        mov     dword ptr [esp+0x11c], 0
        je      stream_failed
        push    0
        mov     ecx, eax
        call    Player_Event_StreamConstruct
        jmp     stream_done
    stream_failed:
        xor     eax, eax
    stream_done:
        push    eax
        mov     ecx, edi
        mov     [esp+0x120], ebp
        mov     dword ptr [eax+4], 0
        call    List_Add
        mov     edx, dword ptr DAT_005828b0
        add     esi, 8
        push    esi
        lea     eax, [esp+0x18]
        push    edx
        push    eax
        call    String_Format
        mov     edx, dword ptr DAT_00581744
        mov     eax, dword ptr DAT_0057c670
        lea     ecx, [esp+0x20]
        xor     edi, edi
        push    ecx
        push    edx
        push    edi
        push    2
        push    1
        push    3
        push    ebp
        push    eax
        call    UI_Briefing_Printf
        add     esp, 0x2c
        mov     [ebx+0x1148], edi
        mov     [ebx+0x114c], edi
        mov     [ebx+0x1150], edi
        mov     [ebx+0x1154], edi
        xor     esi, esi
    clear_loop:
        mov     ecx, dword ptr DAT_0057c670
        push    esi
        call    Game_GetPlayerBySlot
        cmp     eax, edi
        je      next_clear
        mov     [eax+0x50], ebp
    next_clear:
        inc     esi
        cmp     esi, 6
        jl      clear_loop
        mov     ecx, [esp+0x114]
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        mov     fs:[0], ecx
        add     esp, 0x110
        ret
    }
}
