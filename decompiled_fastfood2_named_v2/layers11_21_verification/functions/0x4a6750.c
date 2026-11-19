// rea decompile_all
// name: UI_DrawAwardMedals
// address: 0x4a6750
// body: available
// range: 0x4a6750-0x4a698b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl UI_DrawAwardMedals(void *param_1,int param_2,int param_3,int param_4)

{
  void *this;
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  void *this_00;
  int iVar4;
  longlong lVar5;
  int local_164;
  int local_15c;
  int local_158;
  int local_154;
  int local_150;
  undefined4 local_14c;
  int local_148;
  int local_144;
  byte local_140 [64];
  char local_100 [256];
  
                    /* Draws award medals and their counts for one category. */
  this = (void *)UI_GetWindowObject(param_1,param_2);
  if (this != (void *)0x0) {
    FUN_00521ae0(this,&local_15c,&local_148);
    FUN_005314a0(param_1,param_2,&local_14c,&local_150);
    FUN_00531570(param_1,param_2,&local_144,&local_154);
    local_158 = (local_154 + -0x12 >> 1) + local_150;
    iVar4 = (param_4 * 5 + 2000) * 100;
    if ((param_3 != 0) &&
       (FUN_0054dd83(local_140,&DAT_005630d0,s_Medallien_filiale_spr_00569088 + param_4 * 0x40),
       0 < param_3)) {
      local_164 = param_3;
      do {
        iVar1 = FUN_0052ff20(param_1,iVar4);
        if (iVar1 == 0) {
          pbVar2 = local_140;
          iVar1 = local_158;
          lVar5 = __ftol();
          FUN_00531850(param_1,iVar4,(int)lVar5,iVar1,(char *)pbVar2);
          FUN_0054dd83(local_100,(byte *)s__d__s_00568324,param_3);
LAB_004a6946:
          FUN_00531f50(param_1,iVar4,local_100);
        }
        else {
          iVar1 = local_158;
          lVar5 = __ftol();
          FUN_00531400(param_1,iVar4,(int)lVar5,iVar1);
          pbVar2 = (byte *)UI_GetButtonSpriteRecord(param_1,iVar4);
          uVar3 = FUN_005570c0(this_00,pbVar2,local_140);
          if (uVar3 != 0) {
            UI_SetButtonSpriteByName(param_1,iVar4,(char *)local_140);
            FUN_0054dd83(local_100,(byte *)s__d__s_00568324,param_3);
            goto LAB_004a6946;
          }
        }
        iVar4 = iVar4 + 1;
        local_164 = local_164 + -1;
      } while (local_164 != 0);
    }
    while (iVar1 = FUN_0052ff20(param_1,iVar4), iVar1 != 0) {
      FUN_005311a0(param_1,iVar4);
      iVar4 = iVar4 + 1;
    }
  }
  return;
}

