// rea decompile_all
// name: SchoolMenu_FillLocalStructure
// address: 0x4bf400
// body: available
// range: 0x4bf400-0x4bf4c1 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl SchoolMenu_FillLocalStructure(void *param_1)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int local_190 [36];
  int local_100 [64];
  
  pvVar1 = *(void **)((int)DAT_0057c670 + 0x218);
  if (*(int *)((int)pvVar1 + 4) == 0xb) {
    pvVar1 = (void *)IDMap_Lookup((void *)((int)DAT_0057c670 + 4),
                                  *(int *)((int)DAT_0057c670 + 0x2f4),(int *)0x0);
    pvVar1 = (void *)Map_GetRandomBuildingOfType(pvVar1,0xb,0,'\0');
  }
  iVar3 = 0;
  piVar4 = local_190;
  for (iVar2 = 0x24; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar4 = 0;
    piVar4 = piVar4 + 1;
  }
  piVar4 = local_100;
  for (iVar2 = 0x40; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar4 = 0;
    piVar4 = piVar4 + 1;
  }
  piVar4 = local_190;
  do {
    iVar2 = Game_CountFreeBuildingsByType(pvVar1,iVar3);
    *piVar4 = iVar2;
    iVar3 = iVar3 + 1;
    piVar4 = piVar4 + 1;
  } while (iVar3 < 0x24);
  Chart_DrawCustomerPortraits(param_1,0x429,local_190);
  Game_CountProductUsageByCategory(DAT_0057c670,(int)pvVar1,local_100);
  CustomerGroups_DrawProductSalesGrid(param_1,0x1f45,local_100);
  return;
}

