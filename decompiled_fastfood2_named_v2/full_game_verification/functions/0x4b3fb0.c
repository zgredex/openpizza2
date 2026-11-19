// rea decompile_all
// name: CompanyOverview_InitWindow
// address: 0x4b3fb0
// body: available
// range: 0x4b3fb0-0x4b427e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl CompanyOverview_InitWindow(void *param_1,char param_2)

{
  int iVar1;
  void *extraout_ECX;
  void *this;
  int iVar2;
  uint uVar3;
  undefined4 unaff_EDI;
  int *piVar4;
  undefined1 local_20 [32];
  
                    /* Initializes the company-overview page, rows, slider, and chart. */
  UI_SetPosition(param_1,&LAB_004b3d20,0);
  if (DAT_0057d698 != 0) {
    UI_ReleaseRefCount(DAT_0057c5e0,DAT_0057d698);
  }
  DAT_0057d698 = UI_LoadFontByName(DAT_0057c5e0,s_VERDANA10_fnt_00563e64);
  if (param_2 != '\0') {
    UI_Group_Create(param_1,0,3,0x3f8);
  }
  Window_GadgetNotify_Button_SetState(param_1,DAT_0057d69c + 0x3f8,1);
  iVar2 = 0;
  piVar4 = &DAT_0056a7b0;
  do {
    Window_GadgetNotify_Button_SetState(param_1,iVar2 + 0x3fb,(uint)(byte)(&DAT_0056a734)[*piVar4]);
    piVar4 = piVar4 + 1;
    iVar2 = iVar2 + 1;
  } while ((int)piVar4 < 0x56a7d4);
  _param_2 = Game_CountActiveCompanies
                       (*(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4));
  if (DAT_0056a7d4 != -1) {
    iVar2 = *(int *)(DAT_0057c670 + 0x9c);
    if (iVar2 != 0) {
      DAT_0056a7d4 = *(int *)(iVar2 + 0x3c);
      Gadget_SetText(param_1,0x3f6,iVar2 + 4);
      if (*(int *)(iVar2 + 0x14dc) != 0) {
        _param_2 = _param_2 + 1;
      }
      goto LAB_004b40e1;
    }
    DAT_0056a7d4 = -1;
  }
  Gadget_SetText(param_1,0x3f6,DAT_00581004);
LAB_004b40e1:
  String_Format(local_20,DAT_00582e4c,unaff_EDI);
  Window_GadgetNotify_Text_SetText(param_1,0x41e,local_20);
  Window_GadgetNotify_Text_SetText(param_1,0x41f,local_20);
  uVar3 = (uint)(_param_2 != 0);
  UI_SetChildVisibleByID(param_1,0x3f2,uVar3);
  DAT_0057d694 = 0;
  piVar4 = &DAT_0056a740;
  iVar2 = 0x3ea;
  do {
    UI_SetChildVisibleByID(param_1,iVar2 + 0x23,uVar3);
    UI_SetChildVisibleByID(param_1,iVar2,uVar3);
    UI_SetChildVisibleByID(param_1,*piVar4,uVar3);
    UI_SetChildVisibleByID(param_1,iVar2 + 6999,uVar3);
    piVar4 = piVar4 + 1;
    iVar1 = iVar2 + -0x3e9;
    iVar2 = iVar2 + 1;
  } while (iVar1 < 8);
  this = (void *)0x0;
  if (DAT_0057d6a4 != (undefined4 *)0x0) {
    (**(code **)*DAT_0057d6a4)(1);
    DAT_0057d6a4 = (undefined4 *)0x0;
    this = extraout_ECX;
  }
  if (0 < _param_2) {
    CompanyOverview_BuildCompanyList(this,param_1);
    if (_param_2 < 9) {
      UI_RemoveObjectByKey(param_1,0x3f2);
      _param_2 = 8 - _param_2;
      if (0 < _param_2) {
        iVar2 = 0x414;
        piVar4 = &DAT_0056a75c;
        do {
          UI_RemoveObjectByKey(param_1,iVar2 + -0x23);
          UI_RemoveObjectByKey(param_1,iVar2);
          UI_RemoveObjectByKey(param_1,*piVar4);
          UI_RemoveObjectByKey(param_1,iVar2 + 0x1b34);
          piVar4 = piVar4 + -1;
          iVar2 = iVar2 + -1;
          _param_2 = _param_2 + -1;
        } while (_param_2 != 0);
      }
    }
    else {
      DAT_0057d694 = 0;
      if (_param_2 < 8) {
        DAT_0057d694 = _param_2 + -8;
      }
      Window_GadgetNotify_Slider_SetRange(param_1,0x3f2,0,(_param_2 * 5 + -0x28) * 0x14,0);
      Window_GadgetNotify_Slider_SetValue(param_1,0x3f2,DAT_0057d694 * 100,0);
      Window_GadgetNotify_Slider_SetChangeNotify(param_1,0x3f2,1);
    }
    CompanyOverview_UpdateCompanyRows(param_1,DAT_0057d694);
  }
  CompanyOverview_DrawQuarterChart(param_1);
  return;
}

