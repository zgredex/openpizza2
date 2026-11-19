// rea decompile_all
// name: FurnitureMenu_RefreshSlots
// address: 0x4902a0
// body: available
// range: 0x4902a0-0x49098f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FurnitureMenu_RefreshSlots(void *param_1)

{
  int *piVar1;
  int iVar2;
  
  switch(DAT_0057c6a8) {
  case 0:
    FurnitureMenu_SetItemSprite(param_1,0x1f59,1,0,0);
    FurnitureMenu_SetItemSprite(param_1,0x1f5a,1,0,1);
    FurnitureMenu_SetItemSprite(param_1,0x1f5b,1,0,2);
    FurnitureMenu_SetItemSprite(param_1,0x1f5c,1,1,0);
    FurnitureMenu_SetItemSprite(param_1,0x1f5d,1,1,1);
    FurnitureMenu_SetItemSprite(param_1,0x1f5e,1,1,2);
    FurnitureMenu_SetItemSprite(param_1,0x1f64,1,2,0);
    FurnitureMenu_SetItemSprite(param_1,0x1f63,1,2,1);
    FurnitureMenu_SetItemSprite(param_1,0x1f62,1,2,2);
    FurnitureMenu_SetItemSprite(param_1,0x1f5f,1,3,0);
    FurnitureMenu_SetItemSprite(param_1,0x1f60,1,3,1);
    iVar2 = 1;
    break;
  case 1:
    FurnitureMenu_SetItemSprite(param_1,0x1f59,2,0,0);
    FurnitureMenu_SetItemSprite(param_1,0x1f5a,2,0,1);
    FurnitureMenu_SetItemSprite(param_1,0x1f5b,2,0,2);
    FurnitureMenu_SetItemSprite(param_1,0x1f5c,2,1,0);
    FurnitureMenu_SetItemSprite(param_1,0x1f5d,2,1,1);
    FurnitureMenu_SetItemSprite(param_1,0x1f5e,2,1,2);
    FurnitureMenu_SetItemSprite(param_1,0x1f64,2,2,0);
    FurnitureMenu_SetItemSprite(param_1,0x1f63,2,2,1);
    FurnitureMenu_SetItemSprite(param_1,0x1f62,2,2,2);
    FurnitureMenu_SetItemSprite(param_1,0x1f5f,2,3,0);
    FurnitureMenu_SetItemSprite(param_1,0x1f60,2,3,1);
    iVar2 = 2;
    break;
  case 2:
    FurnitureMenu_SetItemSprite(param_1,0x1f59,3,0,0);
    FurnitureMenu_SetItemSprite(param_1,0x1f5a,3,0,1);
    FurnitureMenu_SetItemSprite(param_1,0x1f5b,3,0,2);
    FurnitureMenu_SetItemSprite(param_1,0x1f5c,3,1,0);
    FurnitureMenu_SetItemSprite(param_1,0x1f5d,3,1,1);
    FurnitureMenu_SetItemSprite(param_1,0x1f5e,3,1,2);
    FurnitureMenu_SetItemSprite(param_1,0x1f64,3,2,0);
    FurnitureMenu_SetItemSprite(param_1,0x1f63,3,2,1);
    FurnitureMenu_SetItemSprite(param_1,0x1f62,3,2,2);
    FurnitureMenu_SetItemSprite(param_1,0x1f5f,3,3,0);
    FurnitureMenu_SetItemSprite(param_1,0x1f60,3,3,1);
    iVar2 = 3;
    break;
  case 3:
    FurnitureMenu_SetItemSprite(param_1,0x1f59,4,0,0);
    FurnitureMenu_SetItemSprite(param_1,0x1f5a,4,0,1);
    FurnitureMenu_SetItemSprite(param_1,0x1f5b,4,0,2);
    FurnitureMenu_SetItemSprite(param_1,0x1f5c,4,1,0);
    FurnitureMenu_SetItemSprite(param_1,0x1f5d,4,1,1);
    FurnitureMenu_SetItemSprite(param_1,0x1f5e,4,1,2);
    FurnitureMenu_SetItemSprite(param_1,0x1f64,4,2,0);
    FurnitureMenu_SetItemSprite(param_1,0x1f63,4,2,1);
    FurnitureMenu_SetItemSprite(param_1,0x1f62,4,2,2);
    FurnitureMenu_SetItemSprite(param_1,0x1f5f,4,3,0);
    FurnitureMenu_SetItemSprite(param_1,0x1f60,4,3,1);
    iVar2 = 4;
    break;
  case 4:
    FurnitureMenu_SetWallFloorSprite(param_1,0x1f59,10,0,DAT_0057c6ac);
    FurnitureMenu_SetWallFloorSprite(param_1,0x1f5c,10,1,DAT_0057c6ac);
    FurnitureMenu_SetWallFloorSprite(param_1,0x1f64,10,2,DAT_0057c6ac);
    FurnitureMenu_SetWallFloorSprite(param_1,0x1f5f,10,3,DAT_0057c6ac);
    FurnitureMenu_SetWallFloorSprite(param_1,0x1f5a,8,0,DAT_0057c6ac);
    FurnitureMenu_SetWallFloorSprite(param_1,0x1f5d,8,1,DAT_0057c6ac);
    FurnitureMenu_SetWallFloorSprite(param_1,0x1f63,8,2,DAT_0057c6ac);
    FurnitureMenu_SetWallFloorSprite(param_1,0x1f60,8,3,DAT_0057c6ac);
    FurnitureMenu_SetWallFloorSprite(param_1,0x1f5b,6,0,DAT_0057c6ac);
    FurnitureMenu_SetWallFloorSprite(param_1,0x1f5e,6,1,DAT_0057c6ac);
    FurnitureMenu_SetWallFloorSprite(param_1,0x1f62,6,2,DAT_0057c6ac);
    FurnitureMenu_SetWallFloorSprite(param_1,0x1f61,6,3,DAT_0057c6ac);
    goto switchD_004902b4_default;
  case 5:
    FurnitureMenu_SetItemSprite(param_1,0x1f59,5,0,0);
    FurnitureMenu_SetItemSprite(param_1,0x1f5a,5,0,1);
    FurnitureMenu_SetItemSprite(param_1,0x1f5b,5,0,2);
    FurnitureMenu_SetItemSprite(param_1,0x1f5c,5,1,0);
    FurnitureMenu_SetItemSprite(param_1,0x1f5d,5,1,1);
    FurnitureMenu_SetItemSprite(param_1,0x1f5e,5,1,2);
    FurnitureMenu_SetItemSprite(param_1,0x1f64,5,2,0);
    FurnitureMenu_SetItemSprite(param_1,0x1f63,5,2,1);
    FurnitureMenu_SetItemSprite(param_1,0x1f62,5,2,2);
    FurnitureMenu_SetItemSprite(param_1,0x1f5f,5,3,0);
    FurnitureMenu_SetItemSprite(param_1,0x1f60,5,3,1);
    iVar2 = 5;
    break;
  default:
    goto switchD_004902b4_default;
  }
  FurnitureMenu_SetItemSprite(param_1,0x1f61,iVar2,3,2);
switchD_004902b4_default:
  piVar1 = &DAT_00568420;
  do {
    Window_GadgetNotify_Button_SetState(param_1,*piVar1,0);
    piVar1 = piVar1 + 1;
  } while ((int)piVar1 < 0x568450);
  return;
}

