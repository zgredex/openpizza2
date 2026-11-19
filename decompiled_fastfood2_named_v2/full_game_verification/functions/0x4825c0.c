// rea decompile_all
// name: Map_BuildPixelCoordIndex
// address: 0x4825c0
// body: available
// range: 0x4825c0-0x482707 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall Map_BuildPixelCoordIndex(int param_1)

{
  byte bVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005581fb;
  local_c = ExceptionList;
  puVar2 = (undefined4 *)(param_1 + 0x388);
  ExceptionList = &local_c;
  for (iVar3 = 0x460; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  local_10 = operator_new(0x11c);
  local_4 = 0;
  if (local_10 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = FullscreenImage_Load
                       (local_10,s_KI_PCX_005680b4,DAT_0057c5c8,DAT_0057c5d8,&local_14,
                        (undefined *)0x0);
  }
  local_4 = 0xffffffff;
  if (local_14 != 0) {
    NoOp_Stub();
  }
  iVar3 = puVar2[6];
  local_14 = 0;
  do {
    bVar1 = *(byte *)(iVar3 + local_14);
    if (bVar1 != 0) {
      iVar4 = (uint)bVar1 * 0x140;
      iVar5 = *(int *)(iVar4 + 0x388 + param_1) + 1;
      *(int *)(iVar4 + 0x388 + param_1) = iVar5;
      iVar5 = iVar5 + (uint)bVar1 * 0x28;
      *(int *)(param_1 + 0x388 + iVar5 * 8) = local_14 % 800;
      *(int *)(param_1 + 0x38c + iVar5 * 8) = local_14 / 800;
      *(int *)(param_1 + 0x408 + iVar5 * 8) = 0x214 - *(int *)(param_1 + 0x388 + iVar5 * 8);
      *(int *)(param_1 + 0x40c + iVar5 * 8) = 0x224 - local_14 / 800;
    }
    local_14 = local_14 + 1;
  } while (local_14 < 480000);
  if (puVar2 != (undefined4 *)0x0) {
    (**(code **)*puVar2)(1);
  }
  ExceptionList = local_c;
  return;
}

