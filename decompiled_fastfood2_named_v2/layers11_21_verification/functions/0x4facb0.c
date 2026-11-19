// rea decompile_all
// name: CityMap_PlaceHouseBlocks
// address: 0x4facb0
// body: available
// range: 0x4facb0-0x4fad5d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int CityMap_PlaceHouseBlocks(int *param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int local_8;
  int local_4;
  
  uVar4 = param_2;
                    /* Places 2x2 house blocks into the city-map raster. */
  piVar1 = param_1;
  iVar5 = 0;
  if (param_2 == 0) {
    return 0;
  }
  iVar2 = FUN_004f9a20(6,*(int *)(*param_1 + 0x24),(int)param_1,(int *)&param_1,&param_2,-1,-1);
  if (iVar2 == -1) {
    return 0;
  }
  piVar7 = &local_4;
  piVar6 = &local_8;
  uVar3 = FUN_004034b0(param_2);
  FUN_004897c0(DAT_0057c670,(int)param_1,uVar3,piVar6,piVar7);
  if (0 < (int)uVar4) {
    do {
      iVar2 = CityMap_StampObjectPattern(piVar1,4,4,(int *)s_aa_aa_00571f40,(int)&local_8,1,1,' ');
      if (iVar2 != 0) {
        iVar5 = iVar5 + 1;
      }
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  return iVar5;
}

