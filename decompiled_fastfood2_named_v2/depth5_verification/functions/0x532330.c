// rea decompile_all
// name: FUN_00532330
// address: 0x532330
// body: available
// range: 0x532330-0x5323f3 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __cdecl FUN_00532330(void *param_1,int param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055ac2b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  piVar2 = operator_new(0x18);
  local_4 = 0;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    FUN_00522e80(piVar2 + 1,0);
  }
  iVar3 = -1;
  local_4 = 0xffffffff;
  if (0 < param_3) {
    FUN_00522f40(piVar2 + 1,param_4);
    iVar3 = 1;
    if (1 < param_3) {
      puVar4 = &param_4;
      do {
        piVar1 = puVar4 + 1;
        puVar4 = puVar4 + 1;
        if (*piVar1 == -1) break;
        FUN_00522f40(piVar2 + 1,*piVar1);
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_3);
    }
    *piVar2 = param_2;
    iVar3 = FUN_00522f40((void *)((int)param_1 + 0x148),piVar2);
    FUN_00532620(param_1,piVar2,-1);
  }
  ExceptionList = local_c;
  return iVar3;
}

