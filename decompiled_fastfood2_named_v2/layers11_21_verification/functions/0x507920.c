// rea decompile_all
// name: FUN_00507920
// address: 0x507920
// body: available
// range: 0x507920-0x507a78 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __fastcall FUN_00507920(int param_1)

{
  undefined4 *this;
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  DWORD DVar7;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a2bb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar2 = operator_new(0x7c);
  local_4 = 0;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = (LPVOID)0x0;
  }
  else {
    FUN_0054b390((undefined4 *)((int)pvVar2 + 0x14));
  }
  local_4 = 0xffffffff;
  uVar3 = FUN_0054b440((void *)(*(int *)(param_1 + 200) + 0x14),
                       (int)*(short *)(*(int *)(param_1 + 200) + 0x28));
  uVar4 = FUN_0054b440((void *)(*(int *)(param_1 + 200) + 0x14),
                       *(short *)(*(int *)(param_1 + 200) + 0x28) + 1);
  iVar5 = FUN_004f1750();
  if (iVar5 == 0) {
    FUN_0048e0a0();
  }
  FUN_0054b3c0(*(int *)(param_1 + 200) + 0x14);
  FUN_0054b3d0((void *)(*(int *)(param_1 + 200) + 0x14),uVar3);
  FUN_0054b3d0((void *)(*(int *)(param_1 + 200) + 0x14),uVar4);
  this = (undefined4 *)((int)pvVar2 + 0x14);
  iVar6 = FUN_0054b440(this,1);
  iVar1 = 1;
  while (iVar6 != 0) {
    uVar3 = FUN_0054b440(this,iVar1);
    FUN_0054b3d0((void *)(*(int *)(param_1 + 200) + 0x14),uVar3);
    iVar6 = FUN_0054b440(this,iVar1 + 1);
    iVar1 = iVar1 + 1;
  }
  FUN_004f5c70(*(void **)(param_1 + 200),0);
  if (pvVar2 != (LPVOID)0x0) {
    FUN_00535e10(this);
    FUN_0054dd78(pvVar2);
  }
  DVar7 = timeGetTime();
  FUN_004f21e0(*(void **)(param_1 + 0xc4),*(uint **)(param_1 + 200),DVar7);
  ExceptionList = local_c;
  return iVar5;
}

