// rea decompile_all
// name: FUN_004f9a20
// address: 0x4f9a20
// body: available
// range: 0x4f9a20-0x4f9c0e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_004f9a20(uint param_1,int param_2,int param_3,int *param_4,uint *param_5,int param_6,
                int param_7)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  int local_90;
  void *local_8c;
  int local_88;
  void **local_84;
  int local_80;
  uint local_7c;
  void *local_78 [30];
  
  uVar3 = 0;
  local_7c = *(uint *)(param_3 + 0x14);
  local_8c = (void *)0x0;
  local_90 = 0;
  if (*(int *)(DAT_0057c670 + 0x88) < 1) {
    return -1;
  }
  local_84 = local_78;
  do {
    if (0x1d < (int)uVar3) break;
    pvVar1 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 0x74),local_90,(int *)0x0);
    if ((*(uint *)((int)pvVar1 + 0xc) == (param_1 & 0xff)) &&
       (((param_2 == 4 || (*(int *)((int)pvVar1 + 0x10) == 4)) ||
        (*(int *)((int)pvVar1 + 0x10) == param_2)))) {
      FUN_004e4160(pvVar1,&local_88,&local_80);
      if (param_6 == -1) {
        if ((param_7 != -1) && (iVar2 = local_80, param_7 != local_88)) {
joined_r0x004f9afe:
          if (param_7 != iVar2) goto LAB_004f9b31;
        }
      }
      else if (((param_7 != -1) || ((param_6 != local_88 && (param_6 != local_80)))) &&
              ((param_6 != local_88 || (param_7 != local_80)))) {
        iVar2 = local_88;
        if (param_6 == local_80) goto joined_r0x004f9afe;
        goto LAB_004f9b31;
      }
      if (local_8c == (void *)0x0) {
        local_8c = pvVar1;
      }
      if (((local_7c == 0xffffffff) || (*(byte *)((int)pvVar1 + 0x14) == 4)) ||
         (*(byte *)((int)pvVar1 + 0x14) == local_7c)) {
        uVar3 = uVar3 + 1;
        *local_84 = pvVar1;
        local_84 = local_84 + 1;
      }
    }
LAB_004f9b31:
    local_90 = local_90 + 1;
  } while (local_90 < *(int *)(DAT_0057c670 + 0x88));
  if (uVar3 == 0) {
    if (local_8c == (void *)0x0) {
      return -1;
    }
    local_78[0] = local_8c;
    uVar3 = 1;
  }
  uVar3 = FUN_004034b0(uVar3);
  pvVar1 = local_78[uVar3];
  iVar2 = FUN_00401900((void *)(DAT_0057c670 + 0x74),(int)pvVar1);
  *param_4 = iVar2;
  uVar3 = FUN_004e4180((int)pvVar1);
  *param_5 = uVar3;
  if (*(int *)(param_3 + 0x1c) == 0) {
    iVar2 = *(int *)(param_3 + 0x20);
    if (iVar2 == -1) {
      uVar3 = FUN_004034b0(uVar3);
    }
    else if (iVar2 < (int)uVar3) {
      return (int)*(short *)((int)pvVar1 + (iVar2 * 3 + 0x1e) * 4);
    }
  }
  else if (7 < (int)uVar3) {
    return (int)*(short *)((int)pvVar1 + 0xcc);
  }
  return (int)*(short *)((int)pvVar1 + (uVar3 * 3 + 0x1e) * 4);
}

