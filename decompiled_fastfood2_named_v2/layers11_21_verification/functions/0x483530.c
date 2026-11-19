// rea decompile_all
// name: CityOverviewDialog_FillRows
// address: 0x483530
// body: available
// range: 0x483530-0x4835ba inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall CityOverviewDialog_FillRows(void *this,int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  
                    /* Fills the five city-overview dialog rows. */
  iVar1 = *(int *)(*(int *)((int)this + 0x27c) + 0x14);
  if (iVar1 < 6) {
    iVar4 = 0;
  }
  else {
    iVar1 = 5;
    iVar4 = param_1;
  }
  if (0 < iVar1) {
    piVar2 = &DAT_00567e74;
    iVar3 = 0x3f0 - iVar4;
    param_1 = iVar1;
    do {
      bVar5 = iVar4 != *(int *)((int)this + 0x284);
      if (bVar5) {
        iVar1 = *piVar2;
      }
      else {
        iVar1 = *piVar2;
      }
      Window_GadgetNotify_Button_SetState(*(void **)((int)this + 0x268),iVar1,(uint)!bVar5);
      iVar1 = FUN_004017f0(*(void **)((int)this + 0x27c),iVar4,(int *)0x0);
      Window_GadgetNotify_Text_SetText(*(void **)((int)this + 0x268),iVar4 + iVar3,iVar1 + 4);
      piVar2 = piVar2 + 1;
      iVar4 = iVar4 + 1;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}

