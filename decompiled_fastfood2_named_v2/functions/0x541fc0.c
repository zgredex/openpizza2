// rea decompile_all
// name: FUN_00541fc0
// address: 0x541fc0
// body: available
// range: 0x541fc0-0x5420c4 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined1 __thiscall FUN_00541fc0(void *this,uint *param_1)

{
  int *piVar1;
  int iVar2;
  undefined1 uVar3;
  bool bVar4;
  longlong lVar5;
  uint local_c;
  int local_8 [2];
  
  *param_1 = 0;
  if (*(char *)((int)this + 0x54) == '\0') {
    return 0;
  }
  if (*(char *)((int)this + 0x53) == '\0') {
    return 0;
  }
  EnterCriticalSection(*(LPCRITICAL_SECTION *)((int)this + 0x38));
  piVar1 = *(int **)(*(int *)((int)this + 0x28) + 0x48);
  if (piVar1 == (int *)0x0) {
    local_c = 0;
  }
  else {
    iVar2 = (**(code **)(*piVar1 + 0x10))(piVar1,&local_c,local_8);
    local_c = (iVar2 < 0) - 1 & local_c;
  }
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)((int)this + 0x38));
  iVar2 = *(int *)((int)this + 0x28);
  uVar3 = 1;
  bVar4 = local_c < *(uint *)(iVar2 + 0x10) >> 1;
  if (*(char *)((int)this + 0x55) == '\0') {
    if (!bVar4) {
      uVar3 = 0;
      goto LAB_0054209f;
    }
  }
  else if (bVar4) {
    uVar3 = 0;
    goto LAB_0054209f;
  }
  local_8[0] = (uint)*(ushort *)(iVar2 + 0x24) * *(int *)(iVar2 + 0x14);
  local_8[1] = 0;
  lVar5 = __ftol();
  *param_1 = (uint)lVar5;
LAB_0054209f:
  if ((*(int *)((int)this + 0x8c) != 0) && (*(uint *)((int)this + 0x98) < *param_1)) {
    *param_1 = *(uint *)((int)this + 0x98);
  }
  return uVar3;
}

