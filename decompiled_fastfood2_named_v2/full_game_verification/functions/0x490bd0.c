// rea decompile_all
// name: FurnitureMenu_ShowItemDetails
// address: 0x490bd0
// body: available
// range: 0x490bd0-0x490e8f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FurnitureMenu_ShowItemDetails(void *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  float10 fVar5;
  undefined1 local_20 [32];
  
  if (param_2 == -1) {
    Window_GadgetNotify_Text_SetText(param_1,0x5a2,DAT_00582e4c);
    Window_GadgetNotify_Text_SetText(param_1,0x5a3,DAT_00582e4c);
    Window_GadgetNotify_Text_SetText(param_1,0x5a5,DAT_00582e4c);
    Window_GadgetNotify_Text_SetText(param_1,0x5a4,DAT_00582e4c);
    return;
  }
  iVar3 = param_2 / 3;
  uVar4 = param_2 % 3;
  uVar1 = DAT_00582638;
  if (DAT_0057c6a8 == 4) {
    if (uVar4 == 0) {
      param_2 = 100;
    }
    else {
      if (uVar4 != 1) {
        if (uVar4 != 2) goto LAB_00490d59;
        param_2 = 6;
        goto LAB_00490d62;
      }
      param_2 = 200;
LAB_00490c9b:
      uVar1 = DAT_00582010;
    }
LAB_00490ca0:
    String_Format(local_20,&DAT_005630d0,uVar1);
    Window_GadgetNotify_Text_SetText(param_1,0x5a2,local_20);
    String_Format(local_20,&DAT_005630d0,DAT_00582850);
    Window_GadgetNotify_Text_SetText(param_1,0x5a5,local_20);
    String_Format(local_20,&DAT_005630d0,(&DAT_0058319c)[iVar3]);
    Window_GadgetNotify_Text_SetText(param_1,0x5a3,local_20);
    if ((float)param_2 == 100.0) {
      fVar5 = Building_GetAreaByLevel(iVar3);
    }
    else {
      fVar5 = Stats_GetAmountByType(iVar3);
    }
    String_Format(local_20,(byte *)s__0_2f_005685f4,SUB84((double)fVar5,0));
    Window_GadgetNotify_Text_SetText(param_1,0x5a4,local_20);
  }
  else {
    if (DAT_0057c6a8 == 5) {
      param_2 = 5;
    }
    else {
      param_2 = DAT_0057c6a8 + 1;
LAB_00490d59:
      if (99 < param_2) {
        if (param_2 != 100) goto LAB_00490c9b;
        goto LAB_00490ca0;
      }
    }
LAB_00490d62:
    iVar2 = Game_FindRecordByTripleKey(DAT_0057c670,param_2,iVar3,uVar4,(int *)0x0);
    if (iVar2 != 0) {
      String_Format(local_20,&DAT_005630d0,iVar2 + 0x18);
      Window_GadgetNotify_Text_SetText(param_1,0x5a2,local_20);
      String_Format(local_20,&DAT_005630d0,DAT_00582850);
      Window_GadgetNotify_Text_SetText(param_1,0x5a5,local_20);
      String_Format(local_20,&DAT_005630d0,(&DAT_0058319c)[iVar3]);
      Window_GadgetNotify_Text_SetText(param_1,0x5a3,local_20);
      iVar3 = Game_GetPlayerCity(*(int *)((int)DAT_0057c670 +
                                         *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200));
      fVar5 = Game_ComputePrice(iVar2,iVar3);
      String_Format(local_20,(byte *)s__0_2f_005685f4,SUB84((double)fVar5,0));
      Window_GadgetNotify_Text_SetText(param_1,0x5a4,local_20);
      return;
    }
  }
  return;
}

