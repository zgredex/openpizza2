// rea decompile_all
// name: SchoolMenu_UpdatePage
// address: 0x4bf4d0
// body: available
// range: 0x4bf4d0-0x4bf5b4 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl SchoolMenu_UpdatePage(void *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int local_120 [8];
  int local_100 [64];
  
  iVar4 = *(int *)(DAT_0057c670 + 0x218);
  piVar3 = local_120;
                    /* Refreshes the school page and competitor matrix. */
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar3 = 0;
    piVar3 = piVar3 + 1;
  }
  FUN_0052f9b0(param_1,0x43b,*(undefined4 *)(&DAT_005840d4 + *(int *)(iVar4 + 4) * 4));
  iVar2 = FUN_004d2fd0(iVar4);
  if (iVar2 == 0) {
    FUN_00531740(param_1,0x1f42);
    FUN_00531740(param_1,0x1f43);
  }
  FUN_004bf120(param_1,*(int *)(iVar4 + 0x20),1,0x1f4c,-1,iVar4);
  FUN_004bf400(param_1);
  FUN_004bf5c0(local_100);
  piVar3 = local_120;
  piVar1 = local_100;
  iVar4 = 8;
  do {
    iVar2 = 8;
    do {
      if (*piVar3 < *piVar1) {
        *piVar3 = *piVar1;
      }
      piVar1 = piVar1 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    piVar3 = piVar3 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  iVar4 = 0;
  piVar3 = local_120;
  do {
    Rating_UpdateBarByKey(param_1,0x1fd4,iVar4,*piVar3,DAT_005822d4);
    iVar4 = iVar4 + 1;
    piVar3 = piVar3 + 1;
  } while (iVar4 < 8);
  return;
}

