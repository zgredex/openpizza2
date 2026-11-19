// rea decompile_all
// name: ResourceManager_Destruct
// address: 0x401a20
// body: available
// range: 0x401a20-0x401aeb inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall ResourceManager_Destruct(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* Destroys a resource manager, its archives, and its lock. */
  local_c = ExceptionList;
  puStack_8 = &LAB_00557c2e;
  ExceptionList = &local_c;
  *param_1 = &PTR_ResourceManager_ScalarDeletingDestructor_0055c2f0;
  iVar1 = param_1[0x5a1];
  local_4 = 0;
  while (0 < iVar1) {
    iVar2 = iVar1 + -1;
    param_1[0x5a1] = iVar2;
    if (param_1[(iVar1 + 8 + iVar2 * 8) * 8] != 0) {
      FUN_0054dee4((FILE *)param_1[iVar2 * 0x48 + 1]);
    }
    FUN_0054dd78((LPVOID)param_1[param_1[0x5a1] * 0x48 + 2]);
    iVar1 = param_1[0x5a1];
  }
  iVar1 = param_1[0x6ad];
  while (iVar1 != 0) {
    iVar1 = *(int *)((int)param_1[0x6ad] + 0x50);
    FUN_0054dd78((LPVOID)param_1[0x6ad]);
    param_1[0x6ad] = iVar1;
  }
  local_4 = 0xffffffff;
  NamedLockable_Destroy(param_1 + 0x5a2);
  ExceptionList = local_c;
  return;
}

