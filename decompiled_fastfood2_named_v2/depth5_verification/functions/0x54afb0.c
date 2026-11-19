// rea decompile_all
// name: UI_RemoveAllById
// address: 0x54afb0
// body: available
// range: 0x54afb0-0x54b06b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall UI_RemoveAllById(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
                    /* Removes all UI entries matching an id. */
  iVar4 = 0;
  if ((param_1 == 0) || (*(int *)((int)this + 0x34) == 0)) {
    iVar3 = *(int *)((int)this + 0x18);
    if (0 < iVar3) {
      do {
        iVar1 = FUN_004017f0((void *)((int)this + 4),iVar4,(int *)0x0);
        if (iVar1 != 0) {
          *(undefined4 *)(iVar1 + 8) = 0xffffffff;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar3);
      *(undefined4 *)((int)this + 0x30) = 0;
      *(undefined4 *)((int)this + 0x34) = 0;
      return;
    }
  }
  else {
    iVar4 = *(int *)((int)this + 0x18);
    iVar3 = 0;
    if (0 < iVar4) {
      do {
        iVar1 = FUN_004017f0((void *)((int)this + 4),iVar3,(int *)0x0);
        if (*(int *)(iVar1 + 8) != -1) {
          iVar2 = FUN_0052ff20(*(void **)((int)this + 0x34),*(int *)(iVar1 + 8));
          if (iVar2 != 0) {
            FUN_005311a0(*(void **)((int)this + 0x34),*(int *)(iVar1 + 8));
            *(undefined4 *)(iVar1 + 8) = 0xffffffff;
            *(undefined4 *)(iVar1 + 0x1c) = 0xbf800000;
          }
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar4);
      *(undefined4 *)((int)this + 0x30) = 0;
      *(undefined4 *)((int)this + 0x34) = 0;
      return;
    }
  }
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined4 *)((int)this + 0x34) = 0;
  return;
}

