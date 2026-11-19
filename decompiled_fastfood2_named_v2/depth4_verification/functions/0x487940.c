// rea decompile_all
// name: FUN_00487940
// address: 0x487940
// body: available
// range: 0x487940-0x487a2f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00487940(void *this,void *param_1)

{
  void *this_00;
  int iVar1;
  void *this_01;
  int iVar2;
  undefined4 local_c;
  undefined4 local_8;
  void *local_4;
  
  this_01 = param_1;
  this_00 = *(void **)(DAT_0057c5cc + 0x2c3d4);
  iVar2 = 0x2c41c;
  local_4 = this;
  do {
    iVar1 = *(int *)(DAT_0057c5cc + iVar2);
    if (((iVar1 < 0) || (*(int *)((int)this_00 + 0x48) <= iVar1)) ||
       (*(char *)(*(int *)((int)this_00 + 0x4c) + 0x3e + iVar1 * 0x48) == '\0')) {
      param_1 = (void *)0x0;
    }
    else {
      param_1 = (void *)0x1;
      FUN_0054cc2b(this_01,&param_1,4);
      FUN_00534370(this_00,iVar1,&local_c,&local_8);
      FUN_0054cc2b(this_01,&local_c,4);
      FUN_0054cc2b(this_01,&local_8,4);
      param_1 = (void *)FUN_00534a80(this_00,iVar1);
      FUN_0054cc2b(this_01,&param_1,4);
      param_1 = *(void **)((int)local_4 + iVar2 + -0x2c0b0);
    }
    FUN_0054cc2b(this_01,&param_1,4);
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x2c434);
  return;
}

