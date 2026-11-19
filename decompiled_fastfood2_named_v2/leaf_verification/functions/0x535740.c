// rea decompile_all
// name: FUN_00535740
// address: 0x535740
// body: available
// range: 0x535740-0x5357fd inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00535740(void *this,void *param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  while( true ) {
    bVar1 = *(byte *)(iVar4 + param_2);
    iVar3 = iVar4;
    while (0x1f < bVar1) {
      iVar2 = iVar3 + 1;
      iVar3 = iVar3 + 1;
      bVar1 = *(byte *)(iVar2 + param_2);
    }
    if (*(int *)((int)this + 0x9c4) != 0) {
      if (*(int *)((int)this + 0x9c4) == 2) {
        iVar2 = Font_MeasureRange(this,param_2,iVar4,iVar3);
        iVar2 = iVar2 >> 1;
      }
      else {
        iVar2 = Font_MeasureRange(this,param_2,iVar4,iVar3);
      }
      *(int *)((int)this + 0x9a0) = *(int *)((int)this + 0x9a0) - iVar2;
    }
    *(undefined4 *)((int)this + 0x9bc) = *(undefined4 *)((int)this + 0x9a0);
    *(undefined4 *)((int)this + 0x9c0) = *(undefined4 *)((int)this + 0x9a4);
    for (iVar2 = iVar4; iVar2 < iVar3; iVar2 = iVar2 + 1) {
      FUN_00535800(this,param_1,*(char *)(iVar2 + param_2));
    }
    if (*(char *)(iVar2 + param_2) == '\0') break;
    iVar3 = *(int *)((int)this + 0x9ac) + *(int *)((int)this + 0x9b0);
    *(undefined4 *)((int)this + 0x9a0) = *(undefined4 *)((int)this + 0x9a8);
    iVar4 = iVar2 + 1;
    *(int *)((int)this + 0x9ac) = iVar3;
    *(int *)((int)this + 0x9a4) = iVar3;
    if (*(char *)(iVar4 + param_2) == '\n') {
      iVar4 = iVar2 + 2;
    }
    if (*(char *)(iVar4 + param_2) == '\0') {
      return;
    }
  }
  return;
}

