// rea decompile_all
// name: FUN_004a48b0
// address: 0x4a48b0
// body: available
// range: 0x4a48b0-0x4a4a5b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004a48b0(void *param_1)

{
  int iVar1;
  int iVar2;
  
  CompanyOverview_UpdateCityInfo(param_1);
  FUN_004a4520(param_1);
  iVar1 = 0;
  iVar2 = *(int *)(*(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4) + 0x15c);
  do {
    FUN_005316b0(param_1,*(int *)((int)&DAT_00568f90 + iVar1));
    FUN_005316b0(param_1,*(int *)((int)&DAT_00568fb0 + iVar1));
    FUN_005316b0(param_1,*(int *)((int)&DAT_00568fd0 + iVar1));
    FUN_005316b0(param_1,*(int *)((int)&DAT_00568ff0 + iVar1));
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0x20);
  FUN_005316b0(param_1,0x1fa9);
  if (iVar2 == 0) {
    iVar2 = 0;
    do {
      FUN_00531740(param_1,*(int *)((int)&DAT_00568f90 + iVar2));
      FUN_00531740(param_1,*(int *)((int)&DAT_00568fb0 + iVar2));
      FUN_00531740(param_1,*(int *)((int)&DAT_00568fd0 + iVar2));
      FUN_00531740(param_1,*(int *)((int)&DAT_00568ff0 + iVar2));
      iVar2 = iVar2 + 4;
    } while (iVar2 < 0x20);
    FUN_00531740(param_1,0x1fa9);
    return;
  }
  if (iVar2 < 9) {
    FUN_00531740(param_1,0x1fa9);
    iVar2 = 8 - iVar2;
    if (0 < iVar2) {
      iVar1 = 0;
      do {
        FUN_00531740(param_1,*(int *)((int)&DAT_00568fac + iVar1));
        FUN_00531740(param_1,*(int *)((int)&DAT_00568fcc + iVar1));
        FUN_00531740(param_1,*(int *)((int)&DAT_00568fec + iVar1));
        FUN_00531740(param_1,*(int *)((int)&DAT_0056900c + iVar1));
        iVar1 = iVar1 + -4;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      CompanyOverview_UpdateBuildingRows(param_1,DAT_0057d264);
      return;
    }
  }
  else {
    DAT_0057d264 = 0;
    Window_GadgetNotify_Slider_SetRange(param_1,0x1fa9,0,(iVar2 * 5 + -0x28) * 0x14,0);
    Window_GadgetNotify_Slider_SetValue(param_1,0x1fa9,DAT_0057d264 * 100,0);
    Window_GadgetNotify_Slider_SetChangeNotify(param_1,0x1fa9,1);
  }
  CompanyOverview_UpdateBuildingRows(param_1,DAT_0057d264);
  return;
}

