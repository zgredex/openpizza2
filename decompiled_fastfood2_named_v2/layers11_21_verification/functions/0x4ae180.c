// rea decompile_all
// name: Glossary_ShowCompanyBuildingDetail
// address: 0x4ae180
// body: available
// range: 0x4ae180-0x4aea82 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl Glossary_ShowCompanyBuildingDetail(void *param_1)

{
  int iVar1;
  longlong lVar2;
  int local_88;
  int local_84;
  char local_80 [128];
  
                    /* Shows a company-building glossary entry and its movie. */
  iVar1 = 0x3e9;
  do {
    Window_GadgetNotify_Button_SetState(param_1,iVar1,(uint)(iVar1 + -0x3e9 == DAT_0057d63c));
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x3f6);
  FUN_005314a0(param_1,0x3fb,&local_84,&local_88);
  FUN_0054dd83(local_80,(byte *)s__s_bik_00569bfc,s_stat_pizz_a_00569680 + DAT_0057d63c * 0x6c);
  FUN_005311a0(param_1,0x3fb);
  FUN_00531bb0(param_1,0x3fb,local_84,local_88,local_80,(undefined4 *)0x0);
  UI_StartButtonMovie(param_1,0x3fb,1);
  FUN_0054a490(DAT_0057ba0c,DAT_0057d63c);
  Window_GadgetNotify_Text_SetText
            (param_1,0x3fd,(&DAT_00583fd4)[*(int *)(&DAT_005696c0 + DAT_0057d63c * 0x6c)]);
  Window_GadgetNotify_Text_SetText
            (param_1,0x3fe,
             *(undefined4 *)(&DAT_00584008 + *(int *)(&DAT_005696c4 + DAT_0057d63c * 0x6c) * 4));
  Window_GadgetNotify_Text_SetText
            (param_1,0x1f44,
             *(undefined4 *)(&DAT_00584018 + *(int *)(&DAT_005696e8 + DAT_0057d63c * 0x6c) * 4));
  FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  switch(DAT_0057d63c) {
  case 0:
    lVar2 = __ftol();
    Gadget_SetTextf(param_1,0x40a,&DAT_005683a4,(int)lVar2);
    lVar2 = __ftol();
    Gadget_SetTextf(param_1,0x40b,&DAT_005683a4,(int)lVar2);
    Gadget_SetTextf(param_1,0x40c,(byte *)s__d__s_00568324,
                    *(undefined4 *)(&DAT_005696d0 + DAT_0057d63c * 0x6c));
    lVar2 = __ftol();
    Gadget_SetTextf(param_1,0x40d,&DAT_005683a4,(int)lVar2);
    Window_GadgetNotify_Text_SetText(param_1,0x40e,DAT_00582adc);
    Window_GadgetNotify_Text_SetText(param_1,0x40f,DAT_00582adc);
    Gadget_SetTextf(param_1,0x410,(byte *)s__d__s_00568324,
                    *(undefined4 *)(&DAT_005696e0 + DAT_0057d63c * 0x6c));
    Gadget_SetTextf(param_1,0x411,(byte *)s__d__s_00568324,
                    (*(int *)(&DAT_005696e4 + DAT_0057d63c * 0x6c) * 200000) / 1000);
    return;
  case 1:
  case 2:
    lVar2 = __ftol();
    Gadget_SetTextf(param_1,0x40a,&DAT_005683a4,(int)lVar2);
    Window_GadgetNotify_Text_SetText(param_1,0x40b,DAT_00582adc);
    Window_GadgetNotify_Text_SetText(param_1,0x40c,DAT_00582adc);
    lVar2 = __ftol();
    Gadget_SetTextf(param_1,0x40d,&DAT_005683a4,(int)lVar2);
    Gadget_SetTextf(param_1,0x40e,&DAT_005683a4,*(undefined4 *)(&DAT_005696d8 + DAT_0057d63c * 0x6c)
                   );
    Gadget_SetTextf(param_1,0x40f,(byte *)s__d__s_00568324,
                    *(undefined4 *)(&DAT_005696dc + DAT_0057d63c * 0x6c));
    Gadget_SetTextf(param_1,0x410,(byte *)s__d__s_00568324,
                    *(undefined4 *)(&DAT_005696e0 + DAT_0057d63c * 0x6c));
    iVar1 = *(int *)(&DAT_005696e4 + DAT_0057d63c * 0x6c);
    goto LAB_004ae66b;
  case 3:
    lVar2 = __ftol();
    Gadget_SetTextf(param_1,0x40a,&DAT_005683a4,(int)lVar2);
    lVar2 = __ftol();
    Gadget_SetTextf(param_1,0x40b,&DAT_005683a4,(int)lVar2);
    Gadget_SetTextf(param_1,0x40c,(byte *)s__d__s_00568324,
                    *(undefined4 *)(&DAT_005696d0 + DAT_0057d63c * 0x6c));
    lVar2 = __ftol();
    Gadget_SetTextf(param_1,0x40d,&DAT_005683a4,(int)lVar2);
    Window_GadgetNotify_Text_SetText(param_1,0x40e,DAT_00582adc);
    Window_GadgetNotify_Text_SetText(param_1,0x40f,DAT_00582adc);
    Window_GadgetNotify_Text_SetText(param_1,0x410,DAT_00582720);
    iVar1 = *(int *)(&DAT_005696e4 + DAT_0057d63c * 0x6c);
LAB_004ae66b:
    Gadget_SetTextf(param_1,0x411,(byte *)s__d__s_00568324,(iVar1 * 200000) / 1000);
    return;
  case 4:
  case 5:
    lVar2 = __ftol();
    Gadget_SetTextf(param_1,0x40a,&DAT_005683a4,(int)lVar2);
    Window_GadgetNotify_Text_SetText(param_1,0x40b,DAT_00582adc);
    Window_GadgetNotify_Text_SetText(param_1,0x40c,DAT_00582adc);
    lVar2 = __ftol();
    Gadget_SetTextf(param_1,0x40d,&DAT_005683a4,(int)lVar2);
    Gadget_SetTextf(param_1,0x40e,&DAT_005683a4,*(undefined4 *)(&DAT_005696d8 + DAT_0057d63c * 0x6c)
                   );
    Gadget_SetTextf(param_1,0x40f,(byte *)s__d__s_00568324,
                    *(undefined4 *)(&DAT_005696dc + DAT_0057d63c * 0x6c));
    Window_GadgetNotify_Text_SetText(param_1,0x410,DAT_00582720);
    Gadget_SetTextf(param_1,0x411,(byte *)s__d__s_00568324,
                    (*(int *)(&DAT_005696e4 + DAT_0057d63c * 0x6c) * 200000) / 1000);
    return;
  case 6:
    Window_GadgetNotify_Text_SetText(param_1,0x40a,DAT_00582adc);
    lVar2 = __ftol();
    Gadget_SetTextf(param_1,0x40b,&DAT_005683a4,(int)lVar2);
    Gadget_SetTextf(param_1,0x40c,(byte *)s__d__s_00568324,
                    *(undefined4 *)(&DAT_005696d0 + DAT_0057d63c * 0x6c));
    lVar2 = __ftol();
    Gadget_SetTextf(param_1,0x40d,&DAT_005683a4,(int)lVar2);
    Window_GadgetNotify_Text_SetText(param_1,0x40e,DAT_00582adc);
    Window_GadgetNotify_Text_SetText(param_1,0x40f,DAT_00582adc);
    Window_GadgetNotify_Text_SetText(param_1,0x410,DAT_00582720);
    break;
  case 7:
  case 8:
  case 9:
  case 10:
  case 0xb:
    Window_GadgetNotify_Text_SetText(param_1,0x40a,DAT_00582adc);
    Window_GadgetNotify_Text_SetText(param_1,0x40b,DAT_00582adc);
    Window_GadgetNotify_Text_SetText(param_1,0x40c,DAT_00582adc);
    lVar2 = __ftol();
    Gadget_SetTextf(param_1,0x40d,&DAT_005683a4,(int)lVar2);
    Gadget_SetTextf(param_1,0x40e,&DAT_005683a4,*(undefined4 *)(&DAT_005696d8 + DAT_0057d63c * 0x6c)
                   );
    Gadget_SetTextf(param_1,0x40f,(byte *)s__d__s_00568324,
                    *(undefined4 *)(&DAT_005696dc + DAT_0057d63c * 0x6c));
    Window_GadgetNotify_Text_SetText(param_1,0x410,DAT_00582720);
    break;
  case 0xc:
    Window_GadgetNotify_Text_SetText(param_1,0x40a,DAT_00582adc);
    lVar2 = __ftol();
    Gadget_SetTextf(param_1,0x40b,&DAT_005683a4,(int)lVar2);
    Gadget_SetTextf(param_1,0x40c,(byte *)s__d__s_00568324,
                    *(undefined4 *)(&DAT_005696d0 + DAT_0057d63c * 0x6c));
    Gadget_SetTextf(param_1,0x40d,&DAT_005683a4,*(undefined4 *)(&DAT_005696d4 + DAT_0057d63c * 0x6c)
                   );
    Window_GadgetNotify_Text_SetText(param_1,0x40e,DAT_00582adc);
    Window_GadgetNotify_Text_SetText(param_1,0x40f,DAT_00582adc);
    Window_GadgetNotify_Text_SetText(param_1,0x410,DAT_00582720);
    break;
  default:
    goto switchD_004ae2fd_default;
  }
  Window_GadgetNotify_Text_SetText(param_1,0x411,DAT_00582720);
switchD_004ae2fd_default:
  return;
}

