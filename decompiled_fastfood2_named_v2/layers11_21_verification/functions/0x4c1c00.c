// rea decompile_all
// name: FUN_004c1c00
// address: 0x4c1c00
// body: available
// range: 0x4c1c00-0x4c1e87 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004c1c00(void *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  void *this;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  longlong lVar7;
  
  iVar2 = FUN_00513fc0(DAT_0057d724);
  Gadget_SetText(param_1,0x1fed,iVar2);
  puVar1 = *(undefined4 **)
            (*(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200) + 0x15c);
  FUN_004c1e90(puVar1);
  iVar2 = 0x4b0;
  do {
    FUN_005316b0(param_1,iVar2 + -0x7a);
    FUN_005316b0(param_1,iVar2);
    FUN_005316b0(param_1,iVar2 + 100);
    iVar3 = iVar2 + -0x4af;
    iVar2 = iVar2 + 1;
  } while (iVar3 < 8);
  FUN_005316b0(param_1,0x435);
  if (puVar1 == (undefined4 *)0x0) {
    iVar2 = 0x4b0;
    do {
      FUN_00531740(param_1,iVar2 + -0x7a);
      FUN_00531740(param_1,iVar2);
      FUN_00531740(param_1,iVar2 + 100);
      iVar3 = iVar2 + -0x4af;
      iVar2 = iVar2 + 1;
    } while (iVar3 < 8);
    FUN_00531740(param_1,0x435);
  }
  else {
    if ((int)puVar1 < 9) {
      FUN_00531740(param_1,0x435);
      iVar2 = 8 - (int)puVar1;
      if (0 < iVar2) {
        iVar3 = 0x4b7;
        do {
          FUN_00531740(param_1,iVar3 + 100);
          FUN_00531740(param_1,iVar3);
          FUN_00531740(param_1,iVar3 + -0x7a);
          iVar3 = iVar3 + -1;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
    }
    else {
      DAT_0057d720 = 0;
      Window_GadgetNotify_Slider_SetRange(param_1,0x435,0,((int)puVar1 * 5 + -0x28) * 0x14,0);
      Window_GadgetNotify_Slider_SetValue(param_1,0x435,DAT_0057d720 * 100,0);
      Window_GadgetNotify_Slider_SetChangeNotify(param_1,0x435,1);
    }
    DeliveryMenu_FillProductRows(param_1,DAT_0057d720);
  }
  if (*(char *)(DAT_0057d724 + 0x3c) == '\0') {
    FUN_005316b0(param_1,0x1fef);
    FUN_005316b0(param_1,0x1ff0);
    Gadget_SetTextf(param_1,0x1ff0,&DAT_005683a4,*(undefined4 *)(DAT_0057d724 + 0x40));
  }
  else {
    FUN_00531740(param_1,0x1fef);
    FUN_00531740(param_1,0x1ff0);
  }
  this = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 4),
                              *(int *)(*(int *)((int)DAT_0057c670 + 0x218) + 0x28),(int *)0x0);
  iVar2 = FUN_004da630(this,*(int *)(DAT_0057d724 + 0x30));
  iVar3 = FUN_005144a0(DAT_0057d724);
  iVar6 = 0;
  do {
    if (iVar2 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_0048c7b0(DAT_0057c670,iVar6,iVar3);
    }
    FUN_004a80e0(param_1,0x1fc8,iVar6,iVar4,DAT_00581048);
    iVar6 = iVar6 + 1;
  } while (iVar6 < 8);
  if (*(char *)(DAT_0057d724 + 0x3c) == '\0') {
    FUN_005316b0(param_1,0x1fef);
    uVar5 = *(undefined4 *)(DAT_0057d724 + 0x40);
  }
  else {
    FUN_00531740(param_1,0x1fef);
    iVar2 = *(int *)(DAT_0057d724 + 0x34);
    iVar3 = FUN_00513fd0(DAT_0057d724);
    lVar7 = FUN_004d6260(this,iVar2,iVar3);
    uVar5 = (undefined4)lVar7;
  }
  Gadget_SetTextf(param_1,0x1ff0,&DAT_005683a4,uVar5);
  return;
}

