// rea decompile_all
// name: FUN_0048bdd0
// address: 0x48bdd0
// body: available
// range: 0x48bdd0-0x48bee7 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_0048bdd0(void *this,void *param_1)

{
  void *this_00;
  int iVar1;
  
  iVar1 = *(int *)((int)param_1 + 0x30);
  if ((((iVar1 == 0x1d) || (iVar1 == 0x1e)) || (iVar1 == 0x1f)) &&
     (*(int *)((int)param_1 + 0x110) == -1)) {
    this_00 = (void *)FUN_004017f0((void *)((int)this + 4),*(int *)((int)this + 0x2f4),(int *)0x0);
    iVar1 = FUN_004d74c0(this_00,0x17,0,'\0');
    FUN_004a9320(iVar1,0);
    return;
  }
  if (iVar1 == 0xc) {
    FUN_00483fd0(this,*(int *)((int)param_1 + 0xcc),0,0,0);
    FUN_00508070(param_1);
    *(void **)((int)this + 0x21c) = param_1;
    *(undefined4 *)((int)this + 0x2da8) = 1;
    FUN_005499f0(DAT_0057ba0c,*(int *)((int)param_1 + 0x30),0,*(int *)((int)param_1 + 0x24) == 0);
    return;
  }
  if ((iVar1 == 0x10) &&
     (*(int *)(*(int *)((int)this + *(int *)((int)this + 0x2ec) * 4 + 0x200) + 0x15c) == 0)) {
    FUN_00482b70(this,0xfffe79af,DAT_005825a4,DAT_0058191c,0);
    return;
  }
  if (*(int *)((int)param_1 + 0x108) == 1) {
    FUN_00482b70(this,0xfffe79af,DAT_005825a4,DAT_00580e84,0);
    return;
  }
  FUN_00483fd0(this,0,(int)param_1,0,0);
  return;
}

