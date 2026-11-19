// rea decompile_all
// name: FUN_00477aa0
// address: 0x477aa0
// body: available
// range: 0x477aa0-0x477b7c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_00477aa0(int param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 unaff_EDI;
  int iVar7;
  int local_8;
  
  local_8 = 0;
  iVar4 = param_1;
  iVar7 = param_1;
  do {
    uVar2 = FUN_004034d0(0,0x45);
    bVar1 = false;
    iVar6 = 0;
    do {
      iVar3 = FUN_00488be0(DAT_0057c670,iVar6);
      if (iVar3 != 0) {
        iVar4 = FUN_00488be0(DAT_0057c670,iVar6);
        iVar4 = *(int *)(iVar4 + 0x15c);
        iVar7 = 0;
        if (0 < iVar4) {
          do {
            iVar3 = FUN_00488be0(DAT_0057c670,iVar6);
            iVar3 = FUN_004017f0((void *)(iVar3 + 0x148),iVar7,(int *)0x0);
            if ((iVar3 != 0) &&
               (uVar5 = FUN_005570c0(*(void **)(&DAT_00583078 + uVar2 * 4),(byte *)(iVar3 + 4),
                                     *(void **)(&DAT_00583078 + uVar2 * 4)), uVar5 == 0)) {
              bVar1 = true;
              goto LAB_00477b43;
            }
            iVar7 = iVar7 + 1;
          } while (iVar7 < iVar4);
        }
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 6);
LAB_00477b43:
    if (((iVar7 == iVar4) || (!bVar1)) || (local_8 = local_8 + 1, 0x1d < local_8)) {
      FUN_0054dd83((undefined1 *)(param_1 + 4),*(byte **)(&DAT_00583078 + uVar2 * 4),unaff_EDI);
      return;
    }
  } while( true );
}

