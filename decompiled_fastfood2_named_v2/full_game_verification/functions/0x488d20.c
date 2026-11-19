// rea decompile_all
// name: Game_ResumeSimulation
// address: 0x488d20
// body: available
// range: 0x488d20-0x488d89 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall Game_ResumeSimulation(void *param_1)

{
  DWORD DVar1;
  DWORD DVar2;
  
  if (*(int *)((int)param_1 + 0x1508) != 0) {
    DVar1 = *(DWORD *)(*(int *)((int)param_1 + 0x90) + 0x10);
    DVar2 = GetCurrentThreadId();
    if ((DVar2 != DVar1) && (*(int *)((int)param_1 + 0x90) != 0)) {
      Thread_Init(*(int *)((int)param_1 + 0x90));
    }
    if (*(int *)((int)param_1 + 0x94) != 0) {
      ThreadSync_Signal(*(int *)((int)param_1 + 0x94));
    }
    Game_HideAllLinkedElements(DAT_0057c5cc);
    *(undefined4 *)((int)param_1 + 0x1508) = 0;
    *(undefined4 *)((int)param_1 + 0x150c) = 1;
    Game_UpdateDateLabels(param_1,(void *)0x0);
  }
  return;
}

