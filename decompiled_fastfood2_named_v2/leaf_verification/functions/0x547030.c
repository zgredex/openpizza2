// rea decompile_all
// name: FUN_00547030
// address: 0x547030
// body: available
// range: 0x547030-0x5471c0 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __fastcall FUN_00547030(undefined4 *param_1)

{
  DWORD DVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b87e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  DVar1 = GetCurrentThreadId();
  param_1[1] = DVar1;
  DVar1 = timeGetTime();
  FUN_0054f0d5(DVar1);
  FUN_00401280(param_1 + 0x5e,(char *)0x0);
  *(undefined1 *)(param_1 + 0x3f) = 0;
  param_1[6] = 1000;
  param_1[7] = 1000;
  *(undefined1 *)((int)param_1 + 0xfd) = 0;
  param_1[0x42] = 0xffffffff;
  param_1[0x58] = 0xffffffff;
  param_1[0x59] = 0xffffffff;
  *(undefined1 *)((int)param_1 + 0xfe) = 0;
  *(undefined1 *)((int)param_1 + 0xff) = 0;
  local_4 = 0;
  *(undefined1 *)(param_1 + 0x40) = 0;
  *param_1 = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[0x3d] = 0;
  param_1[0x3e] = 0;
  param_1[5] = 0;
  param_1[8] = 0;
  param_1[0x41] = 0;
  param_1[0x51] = 0;
  param_1[0x53] = 0;
  param_1[0x52] = 0x3f800000;
  *(undefined1 *)(param_1 + 0x5a) = 0;
  *(undefined1 *)((int)param_1 + 0x169) = 0;
  *(undefined1 *)((int)param_1 + 0x16a) = 0;
  *(undefined1 *)(param_1 + 0x50) = 0;
  param_1[0x5b] = 0;
  param_1[0x5c] = 0x3f800000;
  param_1[0x54] = 0;
  param_1[0x55] = 0;
  param_1[0x56] = 0;
  param_1[0x57] = 0;
  param_1[0x4f] = 0;
  Sound_ClampGlobalLimits();
  param_1[0x74] = DAT_00575094;
  uVar2 = FUN_00547a00(DAT_00575098);
  param_1[0x75] = uVar2;
  uVar2 = FUN_00547a00(DAT_0057509c);
  param_1[0x76] = uVar2;
  puVar4 = param_1 + 9;
  for (iVar3 = 0x34; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  puVar4 = param_1 + 0x91;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  puVar4 = param_1 + 0x43;
  for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  param_1[0x5d] = 0;
  puVar4 = param_1 + 0x77;
  for (iVar3 = 0x1a; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 1;
    puVar4 = puVar4 + 1;
  }
  ExceptionList = local_c;
  return param_1;
}

