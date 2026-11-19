// rea decompile_all
// name: Window_UpdateTooltip
// address: 0x526100
// body: available
// range: 0x526100-0x5261fa inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall Window_UpdateTooltip(void *param_1)

{
  int iVar1;
  DWORD DVar2;
  char *pcVar3;
  int *piVar4;
  int iVar5;
  
                    /* Shows the deferred tooltip and redraws the frame if needed. */
  iVar5 = -1;
  if ((*(int *)((int)param_1 + 0x82dc) != 0) && (*(int *)((int)param_1 + 0x82f0) == 0)) {
    DVar2 = timeGetTime();
    if ((*(uint *)((int)param_1 + 0x82e0) < DVar2) &&
       (*(int *)(*(int *)((int)param_1 + 0x244) + 0x14) == 0)) {
      pcVar3 = (char *)FUN_00520e20(*(int *)((int)param_1 + 0x82dc));
      if (pcVar3 != (char *)0x0) {
        FUN_005272f0(param_1,pcVar3,-999,-999);
      }
      *(undefined4 *)((int)param_1 + 0x82e0) = 0xffffffff;
      *(undefined4 *)((int)param_1 + 0x82f0) = 1;
    }
  }
  if ((*(int *)((int)param_1 + 0x83ac) != 0) && (*(int *)(*(int *)((int)param_1 + 0x83ac) + 8) != 0)
     ) {
    *(undefined4 *)((int)param_1 + 0x234) = 1;
  }
  FUN_00401320(*(int *)((int)param_1 + 0x1c8));
  if ((*(int *)((int)param_1 + 0x234) == 0) && (*(int *)((int)param_1 + 0x1a4) == -999)) {
    iVar5 = 0;
    if (0 < *(int *)((int)param_1 + 0x23c)) {
      piVar4 = (int *)((int)param_1 + 0x14);
      do {
        iVar1 = *piVar4;
        if (((iVar1 != 0) && (*(int *)(iVar1 + 0x4c) != 0)) &&
           ((*(int *)(iVar1 + 0xe0) != 0 || (*(int *)(iVar1 + 0x38) != -999)))) break;
        iVar5 = iVar5 + 1;
        piVar4 = piVar4 + 1;
      } while (iVar5 < *(int *)((int)param_1 + 0x23c));
    }
  }
  if (iVar5 < *(int *)((int)param_1 + 0x23c)) {
    Window_RenderFrame(param_1);
  }
  FUN_00401340(*(int *)((int)param_1 + 0x1c8));
  return;
}

