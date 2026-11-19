// rea decompile_all
// name: FUN_004f6fb0
// address: 0x4f6fb0
// body: available
// range: 0x4f6fb0-0x4f7015 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_004f6fb0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  
  iVar3 = 0;
  iVar5 = 0x224;
  puVar4 = (undefined4 *)(param_1 + 0x114);
  do {
    iVar1 = *(int *)(iVar5 + (int)DAT_0057c670);
    if (iVar1 == 0) {
      puVar4[1] = 0;
      *puVar4 = 0;
    }
    else {
      puVar4[-0x2a] = iVar1;
      uVar2 = FUN_00488be0(DAT_0057c670,*(int *)(iVar1 + 8));
      puVar4[-0x29] = uVar2;
      uVar2 = FUN_00482840(DAT_0057c670,iVar3);
      puVar4[-0x35] = uVar2;
    }
    iVar5 = iVar5 + 4;
    iVar3 = iVar3 + 1;
    puVar4 = puVar4 + 0x5a;
  } while (iVar5 < 0x23c);
  return;
}

