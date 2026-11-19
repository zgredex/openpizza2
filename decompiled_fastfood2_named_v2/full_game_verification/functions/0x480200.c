// rea decompile_all
// name: Branch_InitCityObjects
// address: 0x480200
// body: available
// range: 0x480200-0x4803b8 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Branch_InitCityObjects(void *this,undefined2 param_1)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  void *this_00;
  int *piVar5;
  undefined4 unaff_EDI;
  int local_8;
  
  uVar2 = 0;
  iVar4 = *(int *)((int)this + 0x30);
  iVar1 = *(int *)(*(int *)((int)this + 0x16f0) + 0x8c);
  iVar3 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670);
  if (iVar3 == iVar4) {
    iVar4 = Game_HasKeyedRecordEntry(DAT_0057c670,7,*(int *)((int)this + 0x16f0));
    if (iVar4 == 0) {
      iVar4 = UI_Briefing_Printf((int)DAT_0057c670,3,4,4,1,*(int *)((int)this + 0x16f0),DAT_005828a8
                                 ,DAT_005819e8,unaff_EDI);
      Game_SetMessageField34(DAT_0057c670,iVar4,7);
    }
  }
  if (0 < iVar1) {
    local_8 = 0;
    do {
      this_00 = (void *)Game_MapRecordToGlobal(*(void **)((int)this + 0x16f0),local_8);
      iVar4 = State_Is2DOr2E((int)this_00);
      if (((((iVar4 == 0) && (*(int *)((int)this_00 + 0x74) != 0)) &&
           (iVar4 = *(int *)((int)this_00 + 0x30), iVar4 != 0x1d)) &&
          (((iVar4 != 0x1e && (iVar4 != 0x1f)) &&
           ((iVar4 != 0x17 && ((iVar4 != 0x16 && (iVar4 != 0xd)))))))) &&
         ((iVar4 != 0x2b &&
          (((((iVar4 != 0x2c && (iVar4 != 0x2d)) && (iVar4 != 0x2f)) &&
            ((iVar4 != 0x1a && (iVar4 != 0x1b)))) &&
           ((iVar4 != 0x1c && (*(char *)((int)this_00 + 0x81) == '\0')))))))) {
        *(undefined1 *)((int)this_00 + 0x81) = 1;
        if (*(short *)((int)this_00 + 0x40) == 9) {
          piVar5 = (int *)Game_ApplyObjectEvent((int)this_00);
          if (piVar5 != (int *)0x0) {
            UI_DrawCenteredSelectionRect(*(void **)((int)this + 0x14e0),piVar5);
          }
        }
        UI_SetChildState(this_00,param_1);
        Object_SyncChildState(this_00,(int)this,0);
        uVar2 = 1;
        *(undefined4 *)((int)this_00 + *(int *)((int)this + 0x30) * 4 + 0xac) = 0;
      }
      local_8 = local_8 + 1;
    } while (local_8 < iVar1);
    if (uVar2 != 0) {
      Sound_HandleEvent(DAT_0057ba0c,(int)this,0x25);
      if (9 < uVar2) {
        uVar2 = 10;
      }
      Game_AdjustPlayerObjectPercent
                (*(void **)((int)DAT_0057c670 + 0x90),*(int *)((int)this + 0x30),uVar2);
    }
  }
  return;
}

