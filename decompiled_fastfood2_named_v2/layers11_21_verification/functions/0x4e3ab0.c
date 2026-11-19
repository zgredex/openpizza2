// rea decompile_all
// name: FUN_004e3ab0
// address: 0x4e3ab0
// body: available
// range: 0x4e3ab0-0x4e3b67 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004e3ab0(void *this,undefined4 *param_1,int param_2)

{
  int iVar1;
  void *this_00;
  void *pvVar2;
  
  if (param_1[1] != 0) {
    this_00 = (void *)FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),
                                   (int *)0x0);
    if (param_1[2] == 3) {
      pvVar2 = (void *)FUN_004d7600(this_00,param_1[0xb]);
      iVar1 = *(int *)((int)pvVar2 + 0x74);
      *(undefined4 *)(iVar1 + 0x10) = 0;
      *(undefined4 *)(iVar1 + 0x18) = 0;
      *(undefined4 *)(iVar1 + 8) = 0;
      *(undefined4 *)(iVar1 + 0x14) = 0;
      FUN_004dc720(this_00,pvVar2,-1);
      FUN_004dc540(this_00,0,(int)pvVar2,(int)this);
    }
    if (param_1[2] == 2) {
      FUN_004d5580(*(int *)(DAT_0057c670 + 0x9c));
    }
    GamePlan_SetActiveEffect(param_1,0,*(int *)((int)this + 0x48));
  }
  if ((param_2 != 0) || (param_1[2] == 3)) {
    FUN_00401790((void *)((int)this + 300),(int)param_1);
    if (param_1 != (undefined4 *)0x0) {
      (**(code **)*param_1)(1);
    }
  }
  return;
}

