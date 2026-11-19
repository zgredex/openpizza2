// rea decompile_all
// name: FUN_00547ba0
// address: 0x547ba0
// body: available
// range: 0x547ba0-0x547c55 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00547ba0(void *this,int param_1)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = FUN_00547ac0(this,*(int *)((int)this + 0x104),param_1);
  if (!bVar2) {
    return;
  }
  if (*(char *)((int)this + 0xfc) == '\0') {
    return;
  }
  iVar1 = *(int *)((int)this + 0x104);
  if (iVar1 == 1) {
    (**(code **)(**(int **)((int)this + 8) + 0x7c))
              (*(int **)((int)this + 8),*(undefined4 *)((int)this + 0x80),
               *(undefined4 *)((int)this + 0x1d0));
    if (*(int *)((int)this + 0xc) != 0) {
      (**(code **)(**(int **)((int)this + 8) + 0x80))
                (*(int **)((int)this + 8),*(int *)((int)this + 0xc),
                 *(undefined4 *)((int)this + 0x1d4));
    }
    iVar1 = *(int *)((int)this + 0x20);
  }
  else {
    if (iVar1 == 2) {
      if (*(int *)((int)this + 0xc) == 0) {
        return;
      }
      (**(code **)(**(int **)((int)this + 8) + 0x80))
                (*(int **)((int)this + 8),*(int *)((int)this + 0xc),
                 *(undefined4 *)((int)this + 0x1d4));
      return;
    }
    if (iVar1 != 3) {
      return;
    }
    iVar1 = *(int *)((int)this + 0x20);
  }
  if (iVar1 != 0) {
    (**(code **)(**(int **)((int)this + 8) + 0x80))
              (*(int **)((int)this + 8),iVar1,*(undefined4 *)((int)this + 0x1d8));
  }
  return;
}

