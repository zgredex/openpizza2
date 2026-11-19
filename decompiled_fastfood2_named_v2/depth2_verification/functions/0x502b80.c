// rea decompile_all
// name: FUN_00502b80
// address: 0x502b80
// body: available
// range: 0x502b80-0x502c26 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __fastcall FUN_00502b80(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  switch(*(undefined4 *)(param_1 + 0x40)) {
  case 1:
    uVar2 = AI_SelectExpansionAction(param_1);
    return uVar2;
  case 2:
    uVar2 = FUN_00502a90(param_1);
    return uVar2;
  case 3:
    uVar1 = FUN_004034d0(0,100);
    if ((int)uVar1 < 0x32) {
      uVar2 = FUN_005024f0(param_1);
      return uVar2;
    }
    break;
  case 4:
    uVar1 = FUN_004034d0(0,100);
    if (0x31 < (int)uVar1) {
LAB_00502c1c:
      uVar2 = FUN_00502a90(param_1);
      return uVar2;
    }
    break;
  case 5:
    uVar1 = FUN_004034d0(0,100);
    if ((int)uVar1 < 0x32) {
      uVar2 = FUN_00502a90(param_1);
      return uVar2;
    }
    goto LAB_00502c0c;
  case 6:
    uVar1 = FUN_004034d0(0,300);
    if (99 < (int)uVar1) {
      if (200 < (int)uVar1) goto LAB_00502c1c;
      break;
    }
  case 0:
LAB_00502c0c:
    uVar2 = FUN_005024f0(param_1);
    return uVar2;
  default:
    return 0;
  }
  uVar2 = AI_SelectExpansionAction(param_1);
  return uVar2;
}

