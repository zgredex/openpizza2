// rea decompile_all
// name: MapSprite_InitializeRecord
// address: 0x4d32f0
// body: available
// range: 0x4d32f0-0x4d344b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall MapSprite_InitializeRecord(int param_1)

{
  void *pvVar1;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* Depth-2 proposal batch 5. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558d8b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(0x7c);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)0x0;
  }
  else {
    FUN_0054b390((undefined4 *)((int)pvVar1 + 0x14));
  }
  *(void **)(param_1 + 8) = pvVar1;
  local_4 = 0xffffffff;
  *(undefined4 *)((int)pvVar1 + 0x58) =
       *(undefined4 *)(DAT_0057c5cc + 0x2c0cc + *(int *)(param_1 + 0xc) * 4);
  pvVar1 = *(void **)(*(int *)(param_1 + 8) + 0x58);
  if (pvVar1 != (void *)0x0) {
    iVar2 = FUN_005338c0(pvVar1,-1);
    **(int **)(param_1 + 8) = iVar2;
  }
  pvVar1 = *(void **)(DAT_0057c5cc + 0x2c180 + *(int *)(param_1 + 0xc) * 4);
  if (pvVar1 == (void *)0x0) {
    *(undefined4 *)(param_1 + 0x10) = 0xffffffff;
  }
  else {
    iVar2 = FUN_005338c0(pvVar1,-1);
    *(int *)(param_1 + 0x10) = iVar2;
  }
  *(undefined4 *)(*(int *)(param_1 + 8) + 4) = 0xffffffff;
  *(undefined2 *)(*(int *)(param_1 + 8) + 8) = 0xffff;
  *(undefined2 *)(*(int *)(param_1 + 8) + 10) = 0xffff;
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x6c) = 0;
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x70) = 0;
  FUN_004f5c70(*(void **)(param_1 + 8),0xffff);
  *(undefined4 *)(*(int *)(param_1 + 8) + 0xc) = 0;
  *(undefined1 *)(*(int *)(param_1 + 8) + 0x10) = 0;
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x20) = 0;
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x24) = 0;
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x2c) = 0;
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x30) = 0xffffffff;
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x34) = 0xffffffff;
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x38) = 0xffffffff;
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x3c) = 0xffffffff;
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x40) = 0xffffffff;
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x44) = 0xffffffff;
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x48) = 0xffffffff;
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x4c) = 0xffffffff;
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x50) = 0xffffffff;
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x54) = 0xffffffff;
  FUN_004f1370(*(void **)(param_1 + 4),*(int *)(param_1 + 8));
  SetRect((LPRECT)(*(int *)(param_1 + 8) + 0x5c),0xffff,0xffff,-1,-1);
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x74) = 0;
  *(int *)(*(int *)(param_1 + 8) + 0x78) = param_1;
  ExceptionList = local_c;
  return;
}

