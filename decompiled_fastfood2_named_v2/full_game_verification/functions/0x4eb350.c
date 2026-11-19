// rea decompile_all
// name: IsoMap_Destroy
// address: 0x4eb350
// body: available
// range: 0x4eb350-0x4eb4e5 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall IsoMap_Destroy(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00559f7c;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_IsoMap_Delete_0055c5d4;
  iVar2 = 0;
  local_4 = 1;
  if (0 < (int)(param_1[7] * param_1[8])) {
    iVar3 = 0;
    do {
      iVar1 = *(int *)(iVar3 + 8 + param_1[0x13]);
      if (iVar1 != 0) {
        Buffer_FreeLockedGlobal(iVar1 + 4);
        Buffer_FreeLockedGlobal(*(int *)(iVar3 + 8 + param_1[0x13]) + 0x10);
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0xc;
    } while (iVar2 < (int)(param_1[7] * param_1[8]));
  }
  Mem_Free((LPVOID)param_1[0x4e]);
  Mem_Free((LPVOID)param_1[0x13]);
  Mem_Free((LPVOID)param_1[0x14]);
  Mem_Free((LPVOID)param_1[0x15]);
  Mem_Free((LPVOID)param_1[0x19]);
  Mem_Free((LPVOID)param_1[0x2c]);
  if ((undefined4 *)param_1[0x1c] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x1c])(1);
  }
  if ((undefined4 *)param_1[0x1d] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x1d])(1);
  }
  if ((undefined4 *)param_1[0x1e] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x1e])(1);
  }
  if ((LPVOID)param_1[0x27] != (LPVOID)0x0) {
    Mem_Free((LPVOID)param_1[0x27]);
  }
  if ((LPVOID)param_1[0x28] != (LPVOID)0x0) {
    Mem_Free((LPVOID)param_1[0x28]);
  }
  IDMap_RemoveByKey((void *)(param_1[1] + 0x2c3f8),(int)param_1);
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  if ((undefined4 *)param_1[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[2])(1);
  }
  if ((LPVOID)param_1[0x44] != (LPVOID)0x0) {
    Mem_Free((LPVOID)param_1[0x44]);
  }
  if ((LPVOID)param_1[0x45] != (LPVOID)0x0) {
    Mem_Free((LPVOID)param_1[0x45]);
  }
  if ((LPVOID)param_1[0x46] != (LPVOID)0x0) {
    Mem_Free((LPVOID)param_1[0x46]);
  }
  local_4 = local_4 & 0xffffff00;
  List_Node_Destroy(param_1 + 0x50);
  local_4 = 0xffffffff;
  List_Node_Destroy(param_1 + 0x47);
  ExceptionList = pvStack_c;
  return;
}

