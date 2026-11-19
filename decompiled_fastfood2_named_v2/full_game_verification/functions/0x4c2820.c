// rea decompile_all
// name: ExclusiveImport_UpdatePage
// address: 0x4c2820
// body: available
// range: 0x4c2820-0x4c2944 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl ExclusiveImport_UpdatePage(int *param_1)

{
  void *pvVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  undefined4 uVar6;
  
                    /* Refreshes the exclusive-import supplier page. */
  pvVar1 = (void *)IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                                (int *)0x0);
  piVar2 = (int *)Array_GetStride60(pvVar1,DAT_0057d730);
  Gadget_SetText(param_1,0x23b3,piVar2 + 0x11);
  Window_GadgetNotify_Slider_SetValue(param_1,0x549,*piVar2 / 10,0);
  Window_GadgetNotify_Slider_SetValue(param_1,0x54b,piVar2[1],0);
  uVar6 = 0;
  lVar5 = __ftol();
  Window_GadgetNotify_Slider_SetValue(param_1,0x54d,(int)lVar5,uVar6);
  uVar6 = 0;
  lVar5 = __ftol();
  Window_GadgetNotify_Slider_SetValue(param_1,0x54f,(int)lVar5,uVar6);
  SupplierMenu_FillClientRows(param_1);
  pvVar1 = (void *)IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                                (int *)0x0);
  iVar3 = Game_FindRecordByField24(pvVar1,piVar2[4]);
  Game_CenterViewOnObject(iVar3);
  iVar3 = 0;
  do {
    iVar4 = Game_GetRatingPercent(DAT_0057c670,iVar3,*piVar2 / 10);
    Rating_UpdateBarByKey(param_1,0x23af,iVar3,iVar4,DAT_00581048);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 8);
  return;
}

