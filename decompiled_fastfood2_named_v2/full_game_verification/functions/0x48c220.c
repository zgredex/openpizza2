// rea decompile_all
// name: Game_AbortOrdersTargetingObject
// address: 0x48c220
// body: available
// range: 0x48c220-0x48c297 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void Game_AbortOrdersTargetingObject(int param_1,int param_2,void *param_3)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  
                    /* Aborts orders of every object targeting a removed object. */
  iVar3 = 0;
  iVar1 = Game_CountObjectsByState(DAT_0057c670,-1);
  if (0 < iVar1) {
    do {
      pvVar2 = (void *)IDMap_Lookup((void *)((int)DAT_0057c670 + 0x3c),iVar3,(int *)0x0);
      if (pvVar2 != param_3) {
        switch(*(undefined4 *)((int)pvVar2 + 0x30)) {
        case 0xd:
        case 0x16:
        case 0x17:
        case 0x1f:
          if (param_2 != 0) goto switchD_0048c26a_caseD_1d;
          break;
        case 0x1d:
        case 0x1e:
switchD_0048c26a_caseD_1d:
          Object_AbortOrderForTarget(pvVar2,param_1,param_2);
        }
      }
      iVar3 = iVar3 + 1;
      iVar1 = Game_CountObjectsByState(DAT_0057c670,-1);
    } while (iVar3 < iVar1);
  }
  return;
}

