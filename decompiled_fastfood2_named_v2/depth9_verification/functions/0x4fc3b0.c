// rea decompile_all
// name: FUN_004fc3b0
// address: 0x4fc3b0
// body: available
// range: 0x4fc3b0-0x4fc466 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_004fc3b0(void *this,int param_1)

{
  void *this_00;
  int iVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  
  this_00 = *(void **)((int)this + param_1 * 0x168 + 0x70);
  iVar1 = *(int *)((int)this_00 + 0x124);
  if (iVar1 == 0) {
    return 1;
  }
  iVar5 = 0;
  if (0 < iVar1) {
    do {
      iVar2 = FUN_004017f0((void *)((int)this_00 + 0x110),iVar5,(int *)0x0);
      Recipe_SetOnMenu(this_00,iVar2,0);
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar1);
  }
  iVar5 = 0;
  do {
    pvVar3 = FUN_004e3e80(this_00,iVar5);
    if (pvVar3 != (void *)0x0) {
      Recipe_SetOnMenu(this_00,(int)pvVar3,1);
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 7);
  iVar5 = FUN_004ddde0((int)this_00);
  iVar5 = 8 - iVar5;
  if ((0 < iVar5) && (iVar2 = 0, 0 < iVar1)) {
    do {
      iVar4 = FUN_004017f0((void *)((int)this_00 + 0x110),iVar2,(int *)0x0);
      if (*(char *)(iVar4 + 0x1dc) == '\0') {
        Recipe_SetOnMenu(this_00,iVar4,1);
        iVar5 = iVar5 + -1;
        if (iVar5 == 0) {
          return 1;
        }
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  return 1;
}

