// rea decompile_all
// name: FUN_004ac800
// address: 0x4ac800
// body: available
// range: 0x4ac800-0x4aca78 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004ac800(void *param_1)

{
  int iVar1;
  void *this;
  void *pvVar2;
  int iVar3;
  uint extraout_EDX;
  uint extraout_EDX_00;
  int iVar4;
  longlong lVar5;
  int iVar6;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  this = param_1;
  iVar6 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  iVar4 = 0;
  iVar1 = *(int *)(iVar6 + 0x15c);
  if (iVar1 == 0) {
    FUN_0052f9b0(param_1,0x861,DAT_00581328);
    FUN_00531740(param_1,0x4bd);
    FUN_0052fd70(param_1,0x4be,0,0);
    FUN_0052fd70(param_1,0x4bf,0,0);
    FUN_0052fd70(param_1,0x4c0,0,0);
    FUN_0052fd70(param_1,0x4c1,0,0);
    FUN_0052fd70(param_1,0x4c3,0,0);
    FUN_0052fd70(param_1,0x4c2,0,0);
    return;
  }
  if (DAT_0056951c == -1) {
    FUN_005316b0(param_1,0x4bd);
    FUN_0052f9b0(param_1,0x861,DAT_00581004);
    local_c = 0;
    local_10 = 0;
    param_1 = (void *)0x0;
    local_14 = 0;
    local_8 = 0;
    if (0 < iVar1) {
      do {
        pvVar2 = (void *)FUN_004017f0((void *)(iVar6 + 0x148),iVar4,(int *)0x0);
        iVar3 = FUN_00478140(pvVar2);
        local_c = local_c + iVar3;
        iVar3 = FUN_004781b0((int)pvVar2);
        local_10 = local_10 + iVar3;
        lVar5 = thunk_FUN_00479db0((int)pvVar2,extraout_EDX_00);
        param_1 = (void *)((int)param_1 + (int)lVar5);
        iVar3 = FUN_004781e0((int)pvVar2);
        local_14 = local_14 + iVar3;
        iVar3 = FUN_00478250((int)pvVar2);
        local_8 = local_8 + iVar3;
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar1);
    }
    local_c = local_c / iVar1;
    local_10 = local_10 / iVar1;
    param_1 = (void *)((int)param_1 / iVar1);
    local_14 = local_14 / iVar1;
    local_8 = local_8 / iVar1;
  }
  else {
    pvVar2 = (void *)FUN_004017f0((void *)(iVar6 + 0x148),DAT_0056951c,(int *)0x0);
    FUN_0052f9b0(param_1,0x861,(int)pvVar2 + 4);
    local_c = FUN_00478140(pvVar2);
    local_10 = FUN_004781b0((int)pvVar2);
    lVar5 = thunk_FUN_00479db0((int)pvVar2,extraout_EDX);
    param_1 = (void *)lVar5;
    local_14 = FUN_004781e0((int)pvVar2);
    local_8 = FUN_00478250((int)pvVar2);
  }
  if (local_c < 0x14) {
    FUN_0052fd70(this,0x4be,(local_c * 5 + -0x32) * 2,0);
    iVar6 = 0;
  }
  else {
    FUN_0052fd70(this,0x4be,0,0);
    iVar6 = (local_c * 5 + -100) * 2;
  }
  FUN_0052fd70(this,0x4bf,iVar6,0);
  FUN_0052fd70(this,0x4c0,local_10,0);
  FUN_0052fd70(this,0x4c1,param_1,0);
  FUN_0052fd70(this,0x4c3,local_14,0);
  FUN_0052fd70(this,0x4c2,local_8,0);
  return;
}

