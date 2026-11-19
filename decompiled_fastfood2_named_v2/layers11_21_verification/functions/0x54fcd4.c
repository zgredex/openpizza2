// rea decompile_all
// name: entry
// address: 0x54fcd4
// body: available
// range: 0x54fcd4-0x54fdd0 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void entry(void)

{
  DWORD DVar1;
  int iVar2;
  byte *pbVar3;
  HMODULE pHVar4;
  UINT UVar5;
  undefined4 uVar6;
  undefined1 auStack_6a [10];
  _STARTUPINFOA local_60;
  undefined1 *local_1c;
  _EXCEPTION_POINTERS *local_18;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_0055cd08;
  puStack_10 = &LAB_00553be0;
  pvStack_14 = ExceptionList;
  local_1c = auStack_6a + -0xe;
  ExceptionList = &pvStack_14;
  DVar1 = GetVersion();
  _DAT_00585620 = DVar1 >> 8 & 0xff;
  _DAT_0058561c = DVar1 & 0xff;
  _DAT_00585618 = _DAT_0058561c * 0x100 + _DAT_00585620;
  _DAT_00585614 = DVar1 >> 0x10;
  iVar2 = FUN_005541c7(1);
  if (iVar2 == 0) {
    FUN_0054fe01(0x1c);
  }
  iVar2 = FUN_00552331();
  if (iVar2 == 0) {
    FUN_0054fe01(0x10);
  }
  local_8 = 0;
  FUN_00550471();
  DAT_00586d24 = GetCommandLineA();
  DAT_00585654 = FUN_00554095();
  FUN_00553e48();
  FUN_00553d8f();
  FUN_0054f2b0();
  local_60.dwFlags = 0;
  GetStartupInfoA(&local_60);
  pbVar3 = FUN_00553d37();
  uVar6 = 0;
  pHVar4 = GetModuleHandleA((LPCSTR)0x0);
  UVar5 = FUN_00403d90(pHVar4,uVar6,(int)pbVar3);
  CRT_Exit(UVar5);
  FUN_00553a60(local_18->ExceptionRecord->ExceptionCode,local_18);
  return;
}

