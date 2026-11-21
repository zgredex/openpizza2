/* City_GenerateRatingNews - 0x4d9780, 652 bytes
 *
 * Carries an MSVC C++ EH registration frame (handler thunk 0x5591f6); the
 * frame and body are reproduced at the instruction level so the absolute
 * handler reference resolves to the original image address.
 */
extern "C" void FUN_005591f6(void);
extern "C" void *__cdecl FUN_0054e221(unsigned int size);
extern "C" void *Game_FindBestCompositeRatedBranch();
extern "C" int Branch_GetCustomerGroupRating();
extern "C" void *Game_GetPlayerBySlot();
extern "C" void *Player_Event_StreamConstruct();
extern "C" void List_Add();
extern "C" int Game_GetCurrentPlayerCompanyName();
extern "C" void MissionGoal_HandleEvent();
extern "C" void UI_Briefing_AddMessage();
extern "C" void *Game_FindBestQualityBuilding();
extern "C" int Branch_ComputeBuildingRating();

extern void *DAT_0057c670;
extern int DAT_005824e8;
extern int DAT_00581128;

void __declspec(naked) __cdecl City_GenerateRatingNews(void)
{
    __asm
    {
        mov     eax, fs:[0]
        push    -1
        push    offset FUN_005591f6
        push    eax
        mov     fs:[0], esp
        sub     esp, 8
        push    ebx
        push    ebp
        push    esi
        push    edi
        mov     ebx, ecx
        push    -1
        call    Game_FindBestCompositeRatedBranch
        mov     esi, eax
        test    esi, esi
        je      best_quality
        mov     eax, [esi+0x30]
        push    1
        push    -1
        mov     ecx, [ebx+eax*4+0xcc8]
        mov     eax, 0x3c
        sub     eax, ecx
        mov     ecx, esi
        cdq
        and     edx, 7
        add     eax, edx
        mov     edi, eax
        sar     edi, 3
        add     edi, 0x32
        call    Branch_GetCustomerGroupRating
        cmp     eax, edi
        jle     best_quality
        mov     eax, [esi+0x30]
        mov     ecx, dword ptr DAT_0057c670
        push    eax
        call    Game_GetPlayerBySlot
        mov     ecx, dword ptr DAT_0057c670
        mov     edi, eax
        push    0xc
        mov     eax, [edi+0x4c]
        mov     ebp, [ecx+eax*4+0x224]
        call    FUN_0054e221
        add     esp, 4
        mov     [esp+0x14], eax
        test    eax, eax
        mov     dword ptr [esp+0x20], 0
        je      stream1_failed
        push    0
        mov     ecx, eax
        call    Player_Event_StreamConstruct
        jmp     stream1_done
    stream1_failed:
        xor     eax, eax
    stream1_done:
        push    eax
        lea     ecx, [ebp+0x8c]
        mov     dword ptr [esp+0x24], -1
        mov     dword ptr [eax+4], 1
        call    List_Add
        mov     edx, [esi+0x30]
        mov     ecx, dword ptr DAT_0057c670
        mov     [esp+0x10], edx
        call    Game_GetCurrentPlayerCompanyName
        cmp     [esp+0x10], eax
        jne     after_goal
        mov     eax, dword ptr DAT_0057c670
        push    -1
        push    -1
        push    0x13
        mov     ecx, [eax+0x224]
        mov     ecx, [ecx+0xa8]
        call    MissionGoal_HandleEvent
    after_goal:
        mov     edi, [edi+0x48]
        mov     ecx, [ebx+edi*4+0xcf8]
        inc     ecx
        mov     [ebx+edi*4+0xcf8], ecx
        mov     eax, [ebp+0x88]
        test    eax, eax
        je      best_quality
        mov     edx, dword ptr DAT_0057c670
        mov     ecx, dword ptr DAT_005824e8
        mov     esi, [esi+0x16f0]
        push    ecx
        lea     eax, [edx+0x304]
        mov     edx, dword ptr DAT_00581128
        push    edx
        push    esi
        push    1
        push    4
        push    0
        push    0x11
        push    eax
        call    UI_Briefing_AddMessage
        add     esp, 0x20
    best_quality:
        mov     ecx, ebx
        call    Game_FindBestQualityBuilding
        mov     edi, eax
        test    edi, edi
        je      finish
        mov     eax, [edi+0x30]
        push    -1
        mov     ecx, [ebx+eax*4+0xcc8]
        mov     eax, 0x3c
        sub     eax, ecx
        mov     ecx, edi
        cdq
        and     edx, 7
        add     eax, edx
        mov     esi, eax
        sar     esi, 3
        add     esi, 0x32
        call    Branch_ComputeBuildingRating
        cmp     eax, esi
        jle     finish
        mov     eax, [edi+0x30]
        mov     ecx, dword ptr DAT_0057c670
        push    eax
        call    Game_GetPlayerBySlot
        mov     ecx, dword ptr DAT_0057c670
        mov     esi, eax
        push    0xc
        mov     eax, [esi+0x4c]
        mov     ebp, [ecx+eax*4+0x224]
        call    FUN_0054e221
        add     esp, 4
        mov     [esp+0x14], eax
        test    eax, eax
        mov     dword ptr [esp+0x20], 1
        je      stream2_failed
        push    0
        mov     ecx, eax
        call    Player_Event_StreamConstruct
        mov     [esp+0x10], eax
        jmp     stream2_done
    stream2_failed:
        mov     dword ptr [esp+0x10], 0
    stream2_done:
        mov     edx, [edi+0x30]
        mov     ecx, dword ptr DAT_0057c670
        mov     dword ptr [esp+0x20], -1
        mov     [esp+0x14], edx
        call    Game_GetCurrentPlayerCompanyName
        cmp     [esp+0x14], eax
        jne     after_goal2
        mov     eax, dword ptr DAT_0057c670
        push    -1
        push    -1
        push    0x13
        mov     ecx, [eax+0x224]
        mov     ecx, [ecx+0xa8]
        call    MissionGoal_HandleEvent
    after_goal2:
        mov     eax, [esp+0x10]
        lea     ecx, [ebp+0x8c]
        push    eax
        mov     dword ptr [eax+4], 2
        call    List_Add
        mov     edx, [esi+0x48]
        mov     ecx, [ebx+edx*4+0xd10]
        lea     ebx, [ebx+edx*4+0xd10]
        inc     ecx
        mov     [ebx], ecx
        mov     eax, [ebp+0x88]
        test    eax, eax
        je      finish
        mov     eax, dword ptr DAT_005824e8
        mov     ecx, dword ptr DAT_00581128
        mov     edx, [edi+0x16f0]
        push    eax
        mov     eax, dword ptr DAT_0057c670
        push    ecx
        push    edx
        push    1
        push    4
        push    0
        add     eax, 0x304
        push    0x12
        push    eax
        call    UI_Briefing_AddMessage
        add     esp, 0x20
    finish:
        mov     ecx, [esp+0x18]
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        mov     fs:[0], ecx
        add     esp, 0x14
        ret
    }
}
