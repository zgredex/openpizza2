// rea decompile_all
// name: ListDialog_FillRows
// address: 0x4cb520
// body: available
// range: 0x4cb520-0x4cb59c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl ListDialog_FillRows(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
                    /* Fills the generic selection dialog's rows and selection marker. */
  iVar1 = *(int *)((int)DAT_0057de68 + 0x14);
  if (iVar1 < 0x14) {
    param_1 = 0;
  }
  else {
    iVar1 = 0x13;
  }
  if (0 < iVar1) {
    iVar4 = 2000 - param_1;
    iVar3 = 3000 - param_1;
    do {
      Window_GadgetNotify_Button_SetState
                (DAT_0057de30,iVar4 + param_1,(uint)(param_1 == DAT_0057de54));
      iVar2 = FUN_004017f0(DAT_0057de68,param_1,(int *)0x0);
      Window_GadgetNotify_Text_SetText(DAT_0057de30,iVar3 + param_1,iVar2 + 4);
      param_1 = param_1 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}

