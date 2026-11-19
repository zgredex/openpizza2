// rea decompile_all
// name: FUN_004949a0
// address: 0x4949a0
// body: available
// range: 0x4949a0-0x494c08 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004949a0(void *param_1)

{
  int iVar1;
  
  iVar1 = 0x46a;
  if (DAT_0057c6d8 != 4) {
    do {
      FUN_005316b0(param_1,iVar1);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x46e);
    iVar1 = 0x488;
    do {
      FUN_005316b0(param_1,iVar1);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x48c);
    iVar1 = 0x5c9;
    do {
      FUN_005316b0(param_1,iVar1);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x5cd);
    iVar1 = 0x1f48;
    do {
      FUN_005316b0(param_1,iVar1);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x1f52);
    iVar1 = 0x1f53;
    do {
      FUN_005316b0(param_1,iVar1);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x1f57);
    FUN_005316b0(param_1,0x465);
    FUN_005316b0(param_1,0x466);
    FUN_005316b0(param_1,0x468);
    FUN_005316b0(param_1,0x469);
    FUN_005316b0(param_1,0x48e);
    FUN_005316b0(param_1,0x5c0);
    FUN_005316b0(param_1,0x5c3);
    FUN_005316b0(param_1,0x5c5);
    FUN_005316b0(param_1,0x5c7);
    FUN_005316b0(param_1,0x1f43);
    iVar1 = 0x1f67;
    do {
      FUN_00531740(param_1,iVar1);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x1f73);
    FUN_00531740(param_1,0x1f63);
    FUN_00531740(param_1,0x1f64);
    return;
  }
  do {
    FUN_00531740(param_1,iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x46e);
  iVar1 = 0x488;
  do {
    FUN_00531740(param_1,iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x48c);
  iVar1 = 0x5c9;
  do {
    FUN_00531740(param_1,iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x5cd);
  iVar1 = 0x1f48;
  do {
    FUN_00531740(param_1,iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x1f52);
  iVar1 = 0x1f53;
  do {
    FUN_00531740(param_1,iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x1f57);
  FUN_00531740(param_1,0x465);
  FUN_00531740(param_1,0x466);
  FUN_00531740(param_1,0x468);
  FUN_00531740(param_1,0x469);
  FUN_00531740(param_1,0x48e);
  FUN_00531740(param_1,0x5c0);
  FUN_00531740(param_1,0x5c3);
  FUN_00531740(param_1,0x5c5);
  FUN_00531740(param_1,0x5c7);
  FUN_00531740(param_1,0x1f43);
  iVar1 = 0x1f53;
  do {
    FUN_00531740(param_1,iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x1f57);
  iVar1 = 0x1f5b;
  do {
    FUN_00531740(param_1,iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x1f63);
  iVar1 = 0x1f67;
  do {
    FUN_005316b0(param_1,iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x1f73);
  FUN_005316b0(param_1,0x1f63);
  FUN_005316b0(param_1,0x1f64);
  return;
}

