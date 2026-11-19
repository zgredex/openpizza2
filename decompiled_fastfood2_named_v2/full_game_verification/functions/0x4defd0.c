// rea decompile_all
// name: Company_FillStatisticsBlock
// address: 0x4defd0
// body: available
// range: 0x4defd0-0x4df1f5 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Company_FillStatisticsBlock(void *this,int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  int iVar6;
  int local_c;
  int local_8;
  
  piVar1 = param_1;
  local_8 = 0;
  iVar2 = Game_GetPlayerCity((int)this);
  iVar4 = *(int *)(iVar2 + 0xa0);
  iVar3 = *(int *)(iVar2 + 0x68) + *(int *)(iVar2 + 100) + *(int *)(iVar2 + 0x60) +
          *(int *)(iVar2 + 0x5c) + *(int *)(iVar2 + 0x58) + *(int *)(iVar2 + 0x54);
  *(int *)(*param_1 + 0x20) = iVar3;
  *(int *)(*param_1 + 0x24) = iVar4;
  *(int *)(*param_1 + 0x130) = (iVar4 + iVar3 * 10) * 100;
  *(undefined4 *)(*param_1 + 0x134) = 0;
  iVar4 = IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                       (int *)0x0);
  iVar4 = Game_GetMostAdvancedCompany(iVar4);
  if (iVar4 == *(int *)((int)this + 0x48)) {
    *(undefined4 *)(*param_1 + 0x134) = 10000;
    *(undefined4 *)(*param_1 + 0x28) = 1;
  }
  else {
    *(undefined4 *)(*param_1 + 0x28) = 0;
  }
  local_c = 0;
  param_1 = (int *)0x0;
  do {
    pvVar5 = (void *)Game_GetPlayerBySlot(DAT_0057c670,(int)param_1);
    if (pvVar5 != (void *)0x0) {
      iVar4 = *(int *)((int)pvVar5 + 0x48);
      iVar3 = IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                           (int *)0x0);
      local_c = local_c + *(int *)(iVar3 + 0xdac + iVar4 * 4);
      if (pvVar5 == this) {
        iVar4 = *(int *)((int)pvVar5 + 0x48);
        iVar3 = IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                             (int *)0x0);
        local_8 = *(int *)(iVar3 + 0xdac + iVar4 * 4);
      }
    }
    param_1 = (int *)((int)param_1 + 1);
  } while ((int)param_1 < 6);
  *(int *)(*piVar1 + 0x2c) = local_8;
  if (local_c != 0) {
    *(int *)(*piVar1 + 0x134) = *(int *)(*piVar1 + 0x134) + ((local_8 * 100) / local_c) * 100;
  }
  iVar6 = 0;
  iVar4 = *(int *)((int)this + 0xfc);
  iVar3 = *(int *)((int)this + 0x100);
  *(int *)(*piVar1 + 0x30) = iVar4;
  *(int *)(*piVar1 + 0x34) = iVar3;
  iVar4 = (iVar4 * 2 - iVar3) * 500;
  if (iVar4 < 0) {
    iVar4 = 0;
  }
  *(int *)(*piVar1 + 0x138) = iVar4;
  iVar4 = *(int *)(iVar2 + 0xac);
  *(undefined4 *)(*piVar1 + 0x38) = 0;
  *(undefined4 *)(*piVar1 + 0x3c) = 0;
  *(undefined4 *)(*piVar1 + 0x13c) = 0;
  if (iVar4 != 0) {
    iVar2 = 0;
    do {
      if (*(char *)(iVar4 + 0xc4 + iVar2) != '\0') {
        iVar6 = iVar6 + 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 3);
    if (1 < iVar6) {
      *(undefined4 *)(*piVar1 + 0x38) = 1;
      *(undefined4 *)(*piVar1 + 0x3c) = 1;
      if (iVar6 == 2) {
        *(undefined4 *)(*piVar1 + 0x13c) = 15000;
        return;
      }
      *(undefined4 *)(*piVar1 + 0x13c) = 30000;
      return;
    }
    if (iVar6 == 1) {
      *(undefined4 *)(*piVar1 + 0x38) = 1;
      *(undefined4 *)(*piVar1 + 0x13c) = 5000;
    }
  }
  return;
}

