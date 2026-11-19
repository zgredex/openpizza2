// rea decompile_all
// name: StatisticsBalance_UpdateBranchList
// address: 0x4aa740
// body: available
// range: 0x4aa740-0x4aa961 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl StatisticsBalance_UpdateBranchList(void *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_3c;
  int local_38;
  float *local_34;
  int local_30;
  undefined1 local_28 [36];
  
                    /* Fills the balance screen's branch rows and selected period data. */
  iVar1 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  local_30 = *(int *)(iVar1 + 0x15c);
  if (local_30 < 9) {
    param_2 = 0;
  }
  else {
    local_30 = 8;
  }
  if (DAT_0057d5c8 == 0) {
    local_3c = (DAT_00569354 - DAT_0057dfbc) * 4 + 4;
  }
  else {
    local_3c = DAT_0057d5c8 + -1 + (DAT_00569354 - DAT_0057dfbc) * 4;
  }
  if ((-1 < DAT_00569358) &&
     (iVar2 = FUN_004017f0((void *)(iVar1 + 0x148),DAT_00569358,(int *)0x0),
     local_3c < *(int *)(iVar2 + 0x40))) {
    DAT_00569358 = -1;
  }
  FUN_0052ff50(param_1,0x3e9,(uint)(DAT_00569358 == -1));
  FUN_0052f9b0(param_1,0x3f8,DAT_005819f8);
  FUN_0054dd83(local_28,(byte *)s__0_2f___005688b0,SUB84((double)DAT_0057d574,0));
  FUN_0052f9b0(param_1,0x3fb,local_28);
  UI_SetChildVisibleByID(param_1,0x4b2,(uint)(DAT_00569358 != -1));
  iVar2 = 0;
  if (0 < local_30) {
    local_38 = param_2;
    local_34 = (float *)(&DAT_0057d578 + param_2);
    do {
      if (local_38 != DAT_00569358) {
        iVar3 = (&DAT_0056935c)[iVar2];
      }
      else {
        iVar3 = (&DAT_0056935c)[iVar2];
      }
      FUN_0052ff50(param_1,iVar3,(uint)(local_38 == DAT_00569358));
      iVar3 = FUN_004017f0((void *)(iVar1 + 0x148),local_38,(int *)0x0);
      FUN_0052f9b0(param_1,(&DAT_0056937c)[iVar2],iVar3 + 4);
      FUN_0054dd83(local_28,(byte *)s__0_2f___005688b0,SUB84((double)*local_34,0));
      FUN_0052f9b0(param_1,(&DAT_0056939c)[iVar2],local_28);
      if (local_3c < *(int *)(iVar3 + 0x40)) {
        FUN_00531740(param_1,(&DAT_0056935c)[iVar2]);
        FUN_0052f9b0(param_1,(&DAT_0056939c)[iVar2],DAT_00582e4c);
      }
      else {
        UI_ShowChildByID(param_1,(&DAT_0056935c)[iVar2]);
      }
      iVar2 = iVar2 + 1;
      local_38 = local_38 + 1;
      local_34 = local_34 + 1;
    } while (iVar2 < local_30);
  }
  return;
}

