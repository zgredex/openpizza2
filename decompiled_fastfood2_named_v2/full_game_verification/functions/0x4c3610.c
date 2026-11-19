// rea decompile_all
// name: FurnitureMenu_InitOvenPage
// address: 0x4c3610
// body: available
// range: 0x4c3610-0x4c36e1 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FurnitureMenu_InitOvenPage(void *param_1)

{
  int iVar1;
  int iVar2;
  char local_100 [256];
  
                    /* Initializes the oven/furniture submenu page. */
  DAT_0057d738 = 0;
  DAT_0057d734 = *(int *)(DAT_0057c670 + 0x220);
  DAT_0057d73c = Branch_CollectOrdersByCategory(*(void **)(DAT_0057c670 + 0x9c),5);
  iVar2 = 0;
  if (0 < (int)DAT_0057d73c[5]) {
    do {
      iVar1 = IDMap_Lookup(DAT_0057d73c,iVar2,(int *)0x0);
      if (iVar1 == DAT_0057d734) {
        DAT_0057d738 = iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)DAT_0057d73c[5]);
  }
  UI_SetPosition(param_1,&LAB_004c32f0,0);
  if (DAT_0057d734 != 0) {
    OvenPage_FillStatistics(param_1);
    iVar2 = IDMap_Lookup((void *)(DAT_0057c670 + 0x74),*(int *)(DAT_0057d734 + 4),(int *)0x0);
    String_Format(local_100,(byte *)s_moebel__s_spr_0056ae18,iVar2 + 0x40);
    UI_SetButtonSpriteByName(param_1,0x1f41,local_100);
  }
  return;
}

