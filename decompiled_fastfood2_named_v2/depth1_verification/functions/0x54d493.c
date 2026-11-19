// rea decompile_all
// name: FUN_0054d493
// address: 0x54d493
// body: available
// range: 0x54d493-0x54d573 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_0054d493(void *this,int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (*(int *)((int)this + *(int *)(*(int *)this + 4) + 0x34) < 0) {
    FUN_0054d35c((LPCRITICAL_SECTION)((int)this + *(int *)(*(int *)this + 4) + 0x38));
  }
  if (param_1 != 0) {
    *(undefined4 *)((int)this + 8) = 0;
  }
  iVar2 = *(int *)(*(int *)this + 4);
  uVar1 = *(uint *)(iVar2 + 8 + (int)this);
  if (uVar1 == 0) {
    if (*(int *)((int)this + iVar2 + 0x20) != 0) {
      if (param_1 != 0) {
        iVar2 = FUN_0054cf82(*(int *)((int)this + iVar2 + 4));
        if (param_1 <= iVar2) goto LAB_0054d4f5;
      }
      Stream_AdvanceIterator(*(int **)(*(int *)(*(int *)this + 4) + 0x20 + (int)this));
    }
LAB_0054d4f5:
    iVar2 = *(int *)(*(int *)(*(int *)this + 4) + 4 + (int)this);
    if (*(int *)(iVar2 + 0x30) < 0) {
      FUN_0054d35c((LPCRITICAL_SECTION)(iVar2 + 0x34));
    }
    if ((param_1 == 0) && ((*(byte *)(*(int *)(*(int *)this + 4) + 0x24 + (int)this) & 1) != 0)) {
      FUN_0054d599(this);
      uVar1 = *(uint *)(*(int *)(*(int *)this + 4) + 8 + (int)this);
      if (uVar1 != 0) {
        *(uint *)(*(int *)(*(int *)this + 4) + 8 + (int)this) = uVar1 | 2;
        iVar2 = *(int *)(*(int *)(*(int *)this + 4) + 4 + (int)this);
        if (*(int *)(iVar2 + 0x30) < 0) {
          FUN_0054d367((LPCRITICAL_SECTION)(iVar2 + 0x34));
        }
        goto LAB_0054d551;
      }
    }
    uVar3 = 1;
  }
  else {
    *(uint *)((int)this + iVar2 + 8) = uVar1 | 2;
LAB_0054d551:
    if (*(int *)((int)this + *(int *)(*(int *)this + 4) + 0x34) < 0) {
      FUN_0054d367((LPCRITICAL_SECTION)((int)this + *(int *)(*(int *)this + 4) + 0x38));
    }
    uVar3 = 0;
  }
  return uVar3;
}

