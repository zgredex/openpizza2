// rea decompile_all
// name: FUN_00529280
// address: 0x529280
// body: available
// range: 0x529280-0x529368 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_00529280(undefined4 *param_1)

{
  void *this;
  byte *pbVar1;
  int iVar2;
  int local_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0055a868;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_0055c78c;
  local_4 = 0;
  pbVar1 = (byte *)(param_1 + 0x6b);
  iVar2 = 3;
  this = *(void **)(param_1[2] + 0x134);
  do {
    if (*(int *)(pbVar1 + 0x40) != 0) {
      FUN_005277d0(this,pbVar1);
    }
    if (*(int *)(pbVar1 + -0x8c) != 0) {
      FUN_005277d0(this,pbVar1 + -0xcc);
    }
    pbVar1 = pbVar1 + 0x44;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  pbVar1 = (byte *)(param_1 + 0xd2);
  local_14 = 2;
  do {
    iVar2 = 3;
    do {
      if (*(int *)(pbVar1 + 0x40) != 0) {
        FUN_005277d0(this,pbVar1);
      }
      pbVar1 = pbVar1 + 0x44;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    local_14 = local_14 + -1;
  } while (local_14 != 0);
  if ((undefined4 *)param_1[0xd1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0xd1])(1);
  }
  if ((LPVOID)param_1[0x2f] != (LPVOID)0x0) {
    FUN_0054dd78((LPVOID)param_1[0x2f]);
  }
  local_4 = 0xffffffff;
  FUN_00520b10(param_1);
  ExceptionList = pvStack_c;
  return;
}

