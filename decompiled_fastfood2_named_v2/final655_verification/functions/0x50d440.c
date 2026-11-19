// rea decompile_all
// name: FUN_0050d440
// address: 0x50d440
// body: available
// range: 0x50d440-0x50d4c4 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_0050d440(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00488be0(DAT_0057c670,*(int *)(param_1 + 0x110));
  switch(*(undefined4 *)(param_1 + 0x30)) {
  case 0xd:
    iVar1 = FUN_0050e810(param_1);
    break;
  default:
    goto switchD_0050d468_caseD_e;
  case 0x17:
    iVar1 = *(int *)(iVar1 + 100);
    break;
  case 0x1d:
    iVar1 = *(int *)(iVar1 + 0x6c);
    break;
  case 0x1e:
    FUN_005482e0(DAT_0057ba0c,0x28);
    return;
  }
  if (iVar1 == 1) {
    FUN_00548300(DAT_0057ba0c,0x29);
  }
  else {
    if (iVar1 == 2) {
      FUN_00548300(DAT_0057ba0c,0x20);
      return;
    }
    if (iVar1 == 3) {
      FUN_00548300(DAT_0057ba0c,0x23);
      return;
    }
  }
switchD_0050d468_caseD_e:
  return;
}

