// rea decompile_all
// name: FUN_004a7180
// address: 0x4a7180
// body: available
// range: 0x4a7180-0x4a7364 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004a7180(void *param_1,char param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  DAT_0057d290 = FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  DAT_0057d284 = 0;
  FUN_00532310(param_1,&LAB_004a6f80,0);
  if (DAT_0057d288 != (undefined4 *)0x0) {
    (**(code **)*DAT_0057d288)(1);
    DAT_0057d288 = (undefined4 *)0x0;
  }
  if (param_2 != '\0') {
    FUN_00532330(param_1,0,2,0x4ef);
    if (*(int *)(DAT_0057c670 + 0x218) == 0) {
      puVar1 = FUN_004d5b90(DAT_0057d290);
      DAT_0057d280 = (uint)((int)puVar1[5] < 1);
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(1);
      }
    }
    else {
      iVar3 = *(int *)(*(int *)(DAT_0057c670 + 0x218) + 4);
      if ((iVar3 < 0x14) || (DAT_0057d280 = 0, 0x16 < iVar3)) {
        DAT_0057d280 = 1;
      }
    }
  }
  Window_GadgetNotify_Button_SetState(param_1,DAT_0057d280 + 0x4ef,1);
  if (DAT_0057d280 == 0) {
    DAT_0057d288 = FUN_004d5b90(DAT_0057d290);
  }
  else {
    DAT_0057d288 = FUN_004d5c40(DAT_0057d290);
  }
  puVar1 = (undefined4 *)DAT_0057d288[5];
  FUN_004a7370(puVar1);
  puVar2 = FUN_004d5b90(DAT_0057d290);
  FUN_005316f0(param_1,0x4ef,(uint)(0 < (int)puVar2[5]));
  if (puVar2 != (undefined4 *)0x0) {
    (**(code **)*puVar2)(1);
  }
  puVar2 = FUN_004d5c40(DAT_0057d290);
  FUN_005316f0(param_1,0x4f0,(uint)(0 < (int)puVar2[5]));
  if (puVar2 != (undefined4 *)0x0) {
    (**(code **)*puVar2)(1);
  }
  if (0 < (int)puVar1) {
    iVar3 = *(int *)(DAT_0057c670 + 0x218);
    if (iVar3 == 0) {
      iVar3 = FUN_004017f0(DAT_0057d288,*DAT_0057d28c,(int *)0x0);
    }
    DAT_0057d27c = iVar3;
    if (*(int *)(iVar3 + 0x4c) == 0) {
      DAT_0057d27c = FUN_004017f0(DAT_0057d288,*DAT_0057d28c,(int *)0x0);
    }
  }
  *(int *)(DAT_0057c670 + 0x218) = DAT_0057d27c;
  UI_DrawNeighborhoodCustomerIcons(param_1,0x1f43);
  BuildingMarket_ShowSelectedBuildingInfo(param_1);
  return;
}

