// rea decompile_all
// name: FUN_004dfe40
// address: 0x4dfe40
// body: available
// range: 0x4dfe40-0x4e000e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004dfe40(void *this,int *param_1)

{
  int iVar1;
  void *this_00;
  int iVar2;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_2c;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_8;
  int local_4;
  
  iVar1 = *(int *)((int)this + 0x15c);
  iVar3 = 0;
  iVar4 = 0;
  local_8 = 0;
  local_4 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_2c = 0;
  iVar5 = 0;
  iVar2 = 0;
  if (0 < iVar1) {
    do {
      this_00 = (void *)FUN_004017f0((void *)((int)this + 0x148),local_2c,(int *)0x0);
      iVar5 = 0;
      do {
        iVar2 = FUN_004787f0(this_00,iVar5);
        if (local_20 < iVar2) {
          local_20 = iVar2;
        }
        iVar2 = FUN_00478be0(this_00,extraout_EDX,iVar5);
        if (local_1c < iVar2) {
          local_1c = iVar2;
        }
        iVar2 = FUN_00478320(this_00,iVar5);
        if (local_18 < iVar2) {
          local_18 = iVar2;
        }
        iVar2 = FUN_0047a3b0(this_00,iVar5,0);
        if (local_14 < iVar2) {
          local_14 = iVar2;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < 8);
      iVar5 = FUN_004787f0(this_00,-1);
      iVar3 = iVar3 + iVar5;
      iVar5 = FUN_00478be0(this_00,extraout_EDX_00,-1);
      iVar4 = iVar4 + iVar5;
      iVar5 = FUN_00478320(this_00,-1);
      local_8 = local_8 + iVar5;
      iVar5 = FUN_0047a3b0(this_00,-1,0);
      local_4 = local_4 + iVar5;
      local_2c = local_2c + 1;
    } while (local_2c < iVar1);
    if (0 < iVar1) {
      iVar3 = iVar3 / iVar1;
      iVar4 = iVar4 / iVar1;
      local_8 = local_8 / iVar1;
      local_4 = local_4 / iVar1;
    }
    iVar5 = local_8;
    iVar2 = local_4;
  }
  *(int *)(*param_1 + 0xdc) = iVar3;
  *(int *)(*param_1 + 0xe0) = local_20;
  *(int *)(*param_1 + 0xe4) = iVar4;
  *(int *)(*param_1 + 0xe8) = local_1c;
  *(int *)(*param_1 + 0xec) = iVar5;
  *(int *)(*param_1 + 0xf0) = local_18;
  *(int *)(*param_1 + 0xf4) = iVar2;
  *(int *)(*param_1 + 0xf8) = local_14;
  *(int *)(*param_1 + 0x150) = iVar3 * 200;
  *(int *)(*param_1 + 0x154) = iVar4 * 200;
  *(int *)(*param_1 + 0x158) = iVar5 * 200;
  *(int *)(*param_1 + 0x15c) = iVar2 * 200;
  return;
}

