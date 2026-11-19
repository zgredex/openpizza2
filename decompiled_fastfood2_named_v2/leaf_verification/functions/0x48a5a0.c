// rea decompile_all
// name: FUN_0048a5a0
// address: 0x48a5a0
// body: available
// range: 0x48a5a0-0x48a965 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_0048a5a0(void *param_1,int param_2,int param_3,int *param_4)

{
  void *this;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  char *pcVar6;
  int *local_c4;
  int local_c0;
  int local_b8;
  int local_b0;
  int *local_ac;
  int local_a8;
  int *local_a4;
  int local_a0;
  int local_9c;
  void *local_98;
  int local_94;
  undefined4 local_90;
  int *local_8c;
  int local_88;
  int local_84;
  char local_80 [64];
  char local_40 [64];
  
  this = (void *)FUN_00531980(param_1,param_2);
  if (this == (void *)0x0) {
    return 0;
  }
  Sprite_GetSize(this,&local_84,&local_88);
  local_94 = local_88 >> 3;
  FUN_005314a0(param_1,param_2,&local_90,&local_9c);
  local_c0 = local_9c;
  local_a8 = 210000;
  local_a4 = param_4;
  local_ac = param_4 + param_3;
  local_a0 = (param_3 * 5 + 0x41a) * 200;
  local_b0 = 0;
  do {
    iVar3 = 8;
    local_8c = local_a4;
    do {
      local_8c = local_8c + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    iVar3 = *local_ac;
    FUN_0054dd83(local_80,(byte *)s__s_spr_005680ec,
                 *(undefined4 *)((int)&PTR_s_M_KIDS_00567e94 + local_b0));
    FUN_0054dd83(local_40,(byte *)s__d__s_00568324,iVar3);
    iVar4 = local_a0;
    if (0 < iVar3) {
      do {
        iVar1 = FUN_0052ff20(param_1,iVar4);
        if (iVar1 == 0) {
          pcVar6 = local_80;
          iVar1 = local_c0 + -3;
          lVar5 = __ftol();
          FUN_00531850(param_1,iVar4,(int)lVar5,iVar1,pcVar6);
        }
        else {
          iVar1 = local_c0 + -3;
          lVar5 = __ftol();
          FUN_00531400(param_1,iVar4,(int)lVar5,iVar1);
        }
        FUN_00531f50(param_1,iVar4,local_40);
        iVar4 = iVar4 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    iVar3 = FUN_0052ff20(param_1,iVar4);
    while (iVar3 != 0) {
      FUN_005311a0(param_1,iVar4);
      iVar4 = iVar4 + 1;
      iVar3 = FUN_0052ff20(param_1,iVar4);
    }
    local_b8 = 0;
    local_c4 = local_a4;
    iVar3 = local_a8;
    do {
      if (param_3 != local_b8) {
        iVar4 = *local_c4;
        iVar1 = iVar3;
        if (iVar4 != 0) {
          iVar2 = Game_GetPlayerBySlot(local_98,local_b8);
          if (iVar2 == 0) {
            iVar2 = 1;
          }
          else {
            iVar2 = Game_FindCityIndex(iVar2);
            iVar2 = iVar2 + 1;
          }
          FUN_0054dd83(local_80,(byte *)s_SP_RING_02d_spr_00568314,iVar2);
          FUN_0054dd83(local_40,(byte *)s__d__s__s__s_00568304,iVar4);
          if (0 < iVar4) {
            do {
              iVar2 = FUN_0052ff20(param_1,iVar1);
              if (iVar2 == 0) {
                pcVar6 = local_80;
                iVar2 = local_c0;
                lVar5 = __ftol();
                FUN_00531850(param_1,iVar1,(int)lVar5,iVar2,pcVar6);
              }
              else {
                iVar2 = local_c0;
                lVar5 = __ftol();
                FUN_00531400(param_1,iVar1,(int)lVar5,iVar2);
              }
              FUN_00531f50(param_1,iVar1,local_40);
              iVar1 = iVar1 + 1;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
        }
        iVar4 = FUN_0052ff20(param_1,iVar1);
        while (iVar4 != 0) {
          FUN_005311a0(param_1,iVar1);
          iVar1 = iVar1 + 1;
          iVar4 = FUN_0052ff20(param_1,iVar1);
        }
      }
      local_b8 = local_b8 + 1;
      iVar3 = iVar3 + 1000;
      local_c4 = local_c4 + 1;
    } while (local_b8 < 8);
    local_c0 = local_c0 + local_94;
    local_a8 = local_a8 + 10000;
    local_a0 = local_a0 + 10000;
    local_ac = local_ac + 8;
    local_b0 = local_b0 + 4;
    local_a4 = local_8c;
  } while (local_a8 < 290000);
  return 1;
}

