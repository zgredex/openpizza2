// rea decompile_all
// name: EndResults_FillSyndicatePage
// address: 0x4ca310
// body: available
// range: 0x4ca310-0x4ca5db inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl EndResults_FillSyndicatePage(void *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
                    /* Fills the syndicate tab of the end-of-game results table. */
  Window_GadgetNotify_Text_SetText(param_1,0x4d1,DAT_00581a5c);
  Window_GadgetNotify_Text_SetText(param_1,0x4d2,DAT_005829d4);
  Window_GadgetNotify_Text_SetText(param_1,0x4d3,DAT_005824ac);
  Window_GadgetNotify_Text_SetText(param_1,0x4d4,DAT_005827d0);
  Window_GadgetNotify_Text_SetText(param_1,0x4d5,DAT_00581e00);
  iVar3 = 0;
  piVar2 = &DAT_0057de18;
  iVar4 = 0x4fa;
  do {
    iVar1 = FUN_00488be0(DAT_0057c670,iVar3);
    if (iVar1 != 0) {
      Window_GadgetNotify_Text_SetText(param_1,iVar4 + -0x24,DAT_005812fc);
      Window_GadgetNotify_Text_SetText(param_1,iVar4,DAT_005812fc);
      Window_GadgetNotify_Text_SetText(param_1,iVar4 + 0x24,DAT_005812fc);
      Window_GadgetNotify_Text_SetText(param_1,iVar4 + 0x48,DAT_00582f10);
      Gadget_SetTextf(param_1,iVar4 + -0x1f,&DAT_005686f4,*(undefined4 *)(*piVar2 + 0xbc));
      Gadget_SetTextf(param_1,iVar4 + 5,&DAT_005686f4,*(undefined4 *)(*piVar2 + 0xc4));
      Gadget_SetTextf(param_1,iVar4 + 0x29,&DAT_005686f4,*(undefined4 *)(*piVar2 + 0xcc));
      Gadget_SetTextf(param_1,iVar4 + 0x4d,&DAT_005686f4,*(undefined4 *)(*piVar2 + 0xd4));
      Window_GadgetNotify_Text_SetText(param_1,iVar4 + -0x23,DAT_00582eb0);
      Window_GadgetNotify_Text_SetText(param_1,iVar4 + 1,DAT_00582eb0);
      Window_GadgetNotify_Text_SetText(param_1,iVar4 + 0x25,DAT_00582eb0);
      Window_GadgetNotify_Text_SetText(param_1,iVar4 + 0x49,DAT_00580ca8);
      if (*(int *)(*piVar2 + 0xc0) == 1) {
        uVar5 = DAT_00582a0c;
      }
      else {
        uVar5 = DAT_005817a4;
      }
      Window_GadgetNotify_Text_SetText(param_1,iVar4 + -0x20,uVar5);
      if (*(int *)(*piVar2 + 200) == 1) {
        uVar5 = DAT_00582a0c;
      }
      else {
        uVar5 = DAT_005817a4;
      }
      Window_GadgetNotify_Text_SetText(param_1,iVar4 + 4,uVar5);
      if (*(int *)(*piVar2 + 0xd0) == 1) {
        uVar5 = DAT_00582a0c;
      }
      else {
        uVar5 = DAT_005817a4;
      }
      Window_GadgetNotify_Text_SetText(param_1,iVar4 + 0x28,uVar5);
      Gadget_SetTextf(param_1,iVar4 + 0x4c,&DAT_005686f4,*(undefined4 *)(*piVar2 + 0xd8));
      Window_GadgetNotify_Text_SetText(param_1,iVar4 + -0x22,DAT_00581c74);
      Window_GadgetNotify_Text_SetText(param_1,iVar4 + 2,DAT_00581c74);
      Window_GadgetNotify_Text_SetText(param_1,iVar4 + 0x26,DAT_00581c74);
      Window_GadgetNotify_Text_SetText(param_1,iVar4 + 0x4a,DAT_00581c74);
      Gadget_SetTextf(param_1,iVar4 + -0x21,&DAT_005686f4,*(undefined4 *)(*piVar2 + 0x180));
      Gadget_SetTextf(param_1,iVar4 + 3,&DAT_005686f4,*(undefined4 *)(*piVar2 + 0x184));
      Gadget_SetTextf(param_1,iVar4 + 0x27,&DAT_005686f4,*(undefined4 *)(*piVar2 + 0x188));
      Gadget_SetTextf(param_1,iVar4 + 0x4b,&DAT_005686f4,*(undefined4 *)(*piVar2 + 0x18c));
    }
    piVar2 = piVar2 + 1;
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + 6;
  } while ((int)piVar2 < 0x57de30);
  return;
}

