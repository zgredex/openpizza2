// rea decompile_all
// name: UI_DrawTextControl
// address: 0x52c320
// body: available
// range: 0x52c320-0x52c3f3 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall UI_DrawTextControl(void *param_1)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  
  if (*(int *)((int)param_1 + 0x7c) != 0) {
    iVar4 = UI_ProcessDialogInput(param_1,(void *)0x0,*(void **)((int)param_1 + 0x74));
    *(int *)((int)param_1 + 0x5c) = iVar4;
    return;
  }
  if ((*(short *)((int)param_1 + 100) != 0) && (*(short *)((int)param_1 + 0x66) != 0)) {
    Font_WrapText(*(void **)((int)param_1 + 0x54),*(char **)((int)param_1 + 0x74),
                  (int)*(short *)((int)param_1 + 100));
    *(undefined4 *)((int)param_1 + 0x5c) = 0xffffffff;
  }
  if (*(int *)((int)param_1 + 0x5c) == -1) {
    pcVar5 = *(char **)((int)param_1 + 0x74);
    *(undefined4 *)((int)param_1 + 0x5c) = 1;
    cVar2 = *pcVar5;
    while (cVar2 != '\0') {
      if ((cVar2 == '\n') || (cVar2 == '\r')) {
        *(int *)((int)param_1 + 0x5c) = *(int *)((int)param_1 + 0x5c) + 1;
      }
      pcVar1 = pcVar5 + 1;
      pcVar5 = pcVar5 + 1;
      cVar2 = *pcVar1;
    }
  }
  if (*(short *)((int)param_1 + 100) < 1) {
    iVar6 = UI_MeasureTextMaxWidth((int)param_1);
    iVar4 = *(int *)((int)param_1 + 0x38);
    iVar3 = *(int *)((int)param_1 + 0x6c);
    *(int *)((int)param_1 + 0x28) = iVar4;
    if (iVar3 != 0) {
      if (iVar3 == 2) {
        iVar4 = iVar4 - iVar6 / 2;
      }
      else {
        if (iVar3 != 1) goto LAB_0052c3c7;
        iVar4 = iVar4 - iVar6;
      }
    }
    *(int *)((int)param_1 + 0x28) = iVar4;
  }
  else {
    iVar6 = (int)*(short *)((int)param_1 + 100);
  }
LAB_0052c3c7:
  if (*(short *)((int)param_1 + 0x66) < 1) {
    UI_SetAbsolutePosition(param_1,iVar6,*(int *)(*(int *)((int)param_1 + 0x54) + 0x9b0));
    return;
  }
  UI_SetAbsolutePosition(param_1,iVar6,(int)*(short *)((int)param_1 + 0x66));
  return;
}

