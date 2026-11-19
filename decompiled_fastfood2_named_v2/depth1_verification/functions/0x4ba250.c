// rea decompile_all
// name: Game_AdvanceCurrentRecord
// address: 0x4ba250
// body: available
// range: 0x4ba250-0x4ba33b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void Game_AdvanceCurrentRecord(void)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_8;
  
                    /* Depth-1 proposal batch 3/4. */
  iVar7 = *(int *)(DAT_0057d6e8 + 0x30);
  bVar3 = false;
  iVar4 = FUN_00488be0(DAT_0057c670,iVar7);
  local_8 = 0;
  iVar1 = *(int *)(iVar4 + 0x15c);
  if (iVar1 < 1) {
    return;
  }
  do {
    iVar5 = FUN_004017f0((void *)(iVar4 + 0x148),local_8,(int *)0x0);
    if (iVar5 == DAT_0057d6e8) {
      iVar4 = FUN_004017f0((void *)(iVar4 + 0x148),local_8 + 1,(int *)0x0);
      if (iVar4 != 0) {
        DAT_0057d6e8 = iVar4;
        return;
      }
      iVar5 = 0;
      while( true ) {
        iVar5 = iVar5 + 1;
        iVar7 = iVar7 + 1;
        if (5 < iVar7) {
          iVar7 = 0;
        }
        iVar4 = FUN_00488be0(DAT_0057c670,iVar7);
        if (((iVar4 != 0) &&
            (iVar2 = *(int *)(iVar4 + 0x48), iVar6 = FUN_00482820((int)DAT_0057c670), iVar2 != iVar6
            )) && (0 < *(int *)(iVar4 + 0x15c))) break;
        if ((bVar3) || (6 < iVar5)) goto LAB_004ba316;
      }
      DAT_0057d6e8 = FUN_004017f0((void *)(iVar4 + 0x148),0,(int *)0x0);
      bVar3 = true;
    }
LAB_004ba316:
    local_8 = local_8 + 1;
    if (iVar1 <= local_8) {
      return;
    }
  } while( true );
}

