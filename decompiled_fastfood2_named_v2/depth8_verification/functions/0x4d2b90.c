// rea decompile_all
// name: FUN_004d2b90
// address: 0x4d2b90
// body: available
// range: 0x4d2b90-0x4d2c7a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_004d2b90(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  
  bVar1 = FUN_004d3080(param_1);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    switch(*(undefined4 *)(param_1 + 4)) {
    case 0:
    case 7:
    case 0x23:
      *(undefined4 *)(param_1 + 0x50) = 1;
      *(undefined4 *)(param_1 + 0x3c) = 1000;
      return;
    case 1:
      *(undefined4 *)(param_1 + 0x50) = 1;
      *(undefined4 *)(param_1 + 0x3c) = 45000;
      return;
    case 2:
      *(undefined4 *)(param_1 + 0x50) = 1;
      *(undefined4 *)(param_1 + 0x3c) = 30000;
      return;
    case 3:
    case 5:
    case 6:
    case 0xb:
    case 0xf:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x17:
    case 0x18:
    case 0x19:
    case 0x1a:
    case 0x1b:
    case 0x1c:
    case 0x20:
    case 0x22:
      break;
    case 4:
      *(undefined4 *)(param_1 + 0x50) = 1;
      *(undefined4 *)(param_1 + 0x3c) = 35000;
      return;
    case 8:
      *(undefined4 *)(param_1 + 0x50) = 1;
      *(undefined4 *)(param_1 + 0x3c) = 7000;
      return;
    case 9:
      *(undefined4 *)(param_1 + 0x50) = 1;
      *(undefined4 *)(param_1 + 0x3c) = 40000;
      return;
    case 10:
      *(undefined4 *)(param_1 + 0x50) = 1;
      *(undefined4 *)(param_1 + 0x3c) = 10000;
      return;
    case 0xc:
      *(undefined4 *)(param_1 + 0x50) = 1;
      *(undefined4 *)(param_1 + 0x3c) = 25000;
      return;
    case 0xd:
      *(undefined4 *)(param_1 + 0x50) = 1;
      *(undefined4 *)(param_1 + 0x3c) = 50000;
      return;
    case 0xe:
      *(undefined4 *)(param_1 + 0x50) = 1;
      *(undefined4 *)(param_1 + 0x3c) = 20000;
      return;
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x1d:
    case 0x1e:
    case 0x1f:
      *(undefined4 *)(param_1 + 0x4c) = 1;
      return;
    case 0x21:
      *(undefined4 *)(param_1 + 0x50) = 1;
      *(undefined4 *)(param_1 + 0x3c) = 60000;
      return;
    default:
      FUN_0048e0a0();
    }
  }
  return;
}

