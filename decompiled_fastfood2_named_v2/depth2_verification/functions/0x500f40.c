// rea decompile_all
// name: Company_PushRecentEntry
// address: 0x500f40
// body: available
// range: 0x500f40-0x500fc6 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Company_PushRecentEntry(void *this,int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
                    /* Depth-2 proposal batch 3. */
  if (param_4 == -1) {
    param_4 = 5;
  }
  iVar3 = 0;
  piVar1 = (int *)((int)this + param_1 * 0x168 + 0x74);
  piVar2 = piVar1;
  while ((piVar2[3] != param_2 || (*piVar2 != param_3))) {
    iVar3 = iVar3 + 1;
    piVar2 = piVar2 + 4;
    if (9 < iVar3) {
LAB_00500f95:
      FUN_0054e230((undefined4 *)((int)this + param_1 * 0x168 + 0x84),piVar1,0x90);
      *(int *)((int)this + param_1 * 0x168 + 0x80) = param_2;
      *piVar1 = param_3;
      *(undefined2 *)((int)this + param_1 * 0x168 + 0x7e) = (undefined2)param_4;
      return;
    }
  }
  FUN_00500fd0(this,param_1,iVar3);
  goto LAB_00500f95;
}

