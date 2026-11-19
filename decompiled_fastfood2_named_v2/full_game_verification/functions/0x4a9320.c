// rea decompile_all
// name: Game_SelectBuilding
// address: 0x4a9320
// body: available
// range: 0x4a9320-0x4a968e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl Game_SelectBuilding(int param_1,int param_2)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  undefined4 uVar4;
  
                    /* Selects a clicked building and opens the matching view. */
  if (*(int *)(param_1 + 4) == 0x19) {
    if (*(int *)((int)DAT_0057c670 + 0x2e4) != 0xc) {
      *(int *)((int)DAT_0057c670 + 0x218) = param_1;
      Game_CenterViewOnObject(param_1);
      *(undefined4 *)((int)DAT_0057c670 + 0x2e4) = 0xc;
      pvVar2 = DAT_0057c670;
      *(undefined4 *)((int)DAT_0057c670 + 0x2c4) = *(undefined4 *)((int)DAT_0057c670 + 0x2a4);
      *(undefined4 *)((int)pvVar2 + 0x2a4) = 0xc;
      Game_SetViewMode(DAT_0057c670,3,0);
      iVar3 = *(int *)(*(int *)((int)DAT_0057c670 + 0x224) + 0xac);
      if ((*(int *)(iVar3 + 0xd0) == 0) && (*(int *)(iVar3 + 0xd4) == 2)) {
        *(undefined4 *)(iVar3 + 0xd4) = 3;
        Mission_ShowObjectiveDialog(DAT_0057c670,'\0');
        return;
      }
    }
  }
  else {
    if ((*(int *)(param_1 + 4) == 0x1c) &&
       (iVar3 = *(int *)(param_1 + 8), iVar1 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670),
       iVar3 == iVar1)) {
      if (*(int *)((int)DAT_0057c670 + 0x2e4) == 10) {
        return;
      }
      *(int *)((int)DAT_0057c670 + 0x218) = param_1;
      pvVar2 = DAT_0057c670;
      *(undefined4 *)((int)DAT_0057c670 + 0x21c) = 0;
      *(undefined4 *)((int)pvVar2 + 0x2da8) = 1;
      Game_CenterViewOnObject(param_1);
      if ((char)param_2 == '\0') {
        *(undefined4 *)((int)DAT_0057c670 + 0x2e4) = 10;
        pvVar2 = DAT_0057c670;
        *(undefined4 *)((int)DAT_0057c670 + 0x2c0) = *(undefined4 *)((int)DAT_0057c670 + 0x2a0);
        *(undefined4 *)((int)pvVar2 + 0x2a0) = 10;
        Game_SetViewMode(DAT_0057c670,2,0);
        return;
      }
      *(undefined4 *)((int)DAT_0057c670 + 0x2e4) = 8;
      pvVar2 = DAT_0057c670;
      *(undefined4 *)((int)DAT_0057c670 + 0x2c0) = *(undefined4 *)((int)DAT_0057c670 + 0x2a0);
      *(undefined4 *)((int)pvVar2 + 0x2a0) = 8;
      Game_SetViewMode(DAT_0057c670,2,0);
      return;
    }
    if ((*(int *)(param_1 + 0x4c) != 0) && (*(int *)(param_1 + 8) == -1)) {
      *(int *)((int)DAT_0057c670 + 0x218) = param_1;
      pvVar2 = DAT_0057c670;
      *(undefined4 *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x290) * 4 + 0x2b8) =
           *(undefined4 *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x290) * 4 + 0x298);
      *(undefined4 *)((int)pvVar2 + *(int *)((int)pvVar2 + 0x290) * 4 + 0x298) = 0xb;
      UI_QueueControlCommand(*(void **)((int)DAT_0057c670 + 0x260),-0x18621,0x23,0);
      *(undefined4 *)((int)DAT_0057c670 + 0x2e4) = 0;
      Game_DestroyRootWindow((int)DAT_0057c670);
      pvVar2 = SubMenu_BuildSelectedPage(DAT_0057c670,(int *)0x1);
      Window_ShowWindowById(DAT_0057c5e0,(int)pvVar2);
      return;
    }
    if (*(int *)(param_1 + 4) == 0x17) {
      iVar3 = IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                           (int *)0x0);
      iVar1 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670);
      if (*(int *)(iVar3 + 0xc20 + iVar1 * 4) < 3) {
        uVar4 = DAT_005829b4;
        goto LAB_004a95b1;
      }
    }
    if ((*(int *)(param_1 + 4) == 0x1b) && (*(int *)(param_1 + 8) == -1)) {
      iVar3 = Game_GetPlayerFieldC20
                        (*(int *)((int)DAT_0057c670 +
                                 *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200));
      if (iVar3 < 2) {
        uVar4 = DAT_005829b0;
LAB_004a95b1:
        Game_ShowConfirmationDialog(DAT_0057c670,0xfffe79af,DAT_005825a4,uVar4,0);
        return;
      }
      if (*(int *)(*(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200) +
                  0x15c) == 0) {
        Game_ShowConfirmationDialog(DAT_0057c670,0xfffe79af,DAT_005825a4,DAT_0058191c,0);
        return;
      }
    }
    iVar3 = SubMenu_SetSelection(DAT_0057c670,param_1,0,0,0);
    if (iVar3 == 0xf) {
      iVar3 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(param_1 + 8));
      iVar1 = 0;
      if (0 < *(int *)(iVar3 + 0x15c)) {
        do {
          param_2 = IDMap_Lookup((void *)(iVar3 + 0x148),iVar1,(int *)0x0);
          if (*(int *)(param_2 + 0x16f0) == param_1) break;
          iVar1 = iVar1 + 1;
        } while (iVar1 < *(int *)(iVar3 + 0x15c));
      }
      *(int *)((int)DAT_0057c670 + 0x9c) = param_2;
      Sound_SelectCurrentTrack(DAT_0057ba0c);
      Game_SetViewMode(DAT_0057c670,4,0);
    }
  }
  return;
}

