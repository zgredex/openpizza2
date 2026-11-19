// rea decompile_all
// name: Game_ValidateObjectPlacement
// address: 0x489180
// body: available
// range: 0x489180-0x48939a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall
Game_ValidateObjectPlacement
          (void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  void *this_00;
  bool bVar1;
  int iVar2;
  void *this_01;
  undefined4 *this_02;
  undefined3 extraout_var;
  int iVar3;
  
                    /* Validates a building placement at a screen point or cell. */
  if (*(int *)((int)this + 0x344) == -1) {
    return 0;
  }
  this_00 = *(void **)((int)this + 0x2fc);
  if (param_4 == 0) {
    if (((param_1 < 0) || (DAT_00571950 + -0x1e < param_1)) ||
       ((param_2 < 0 || (DAT_00571954 < param_2)))) {
LAB_00489222:
      *(undefined4 *)((int)this + 0x358) = 0;
      return 0;
    }
    iVar2 = Map_ComputeBlitRect(this_00,param_1,param_2,(int *)0x0,0);
    param_4 = **(int **)(iVar2 + 8) % *(int *)((int)this_00 + 0x1c);
    param_2 = **(int **)(iVar2 + 8) / *(int *)((int)this_00 + 0x1c);
  }
  else {
    if (((param_5 != -1) && (param_6 != -1)) &&
       ((param_5 < 0 ||
        (((DAT_00571950 + -0x1e < param_5 || (param_6 < 0)) || (DAT_00571954 < param_6))))))
    goto LAB_00489222;
    param_4 = param_1;
    iVar2 = Grid_GetCell(this_00,param_1,param_2);
    if (iVar2 == 0) {
      return 0;
    }
    if (*(int *)(iVar2 + 8) == 0) {
      return 0;
    }
  }
  *(undefined4 *)((int)this + 0x358) = 1;
  this_01 = (void *)IDMap_Lookup((void *)((int)this + 0x74),*(int *)((int)this + 0x344),(int *)0x0);
  Object_GetPair68(this_01,&param_6,&param_5);
  this_02 = Grid_CollectFootprintCellsAtCell(this_00,(int)this_01,param_4,param_2);
  param_1 = 0;
  if (0 < (int)this_02[5]) {
    do {
      iVar2 = IDMap_Lookup(this_02,param_1,(int *)0x0);
      if (*(int *)((int)this_01 + 8) == 5) {
        bVar1 = IsMenuId352(*(int *)(*(int *)(iVar2 + 8) + 4));
        if (CONCAT31(extraout_var,bVar1) == 0) goto LAB_0048933a;
      }
      else {
        iVar3 = IsMenuId34EOr350(*(int *)(*(int *)(iVar2 + 8) + 4));
        if (iVar3 == 0) goto LAB_00489368;
      }
      if (*(int *)(*(int *)(iVar2 + 8) + 4) < 0) goto LAB_0048933a;
      if (*(int *)(*(int *)(iVar2 + 8) + 0x10) != -1) goto LAB_00489368;
      param_1 = param_1 + 1;
    } while (param_1 < (int)this_02[5]);
  }
  if (this_02 != (undefined4 *)0x0) {
    (**(code **)*this_02)(1);
  }
  this_02 = Grid_CollectFootprintCellsAtCell(this_00,(int)this_01,param_4,param_2);
  iVar2 = MapCell_CheckSpriteOverlap(this,this_02);
  if (iVar2 == 0) {
    if ((param_3 == 0) || (iVar2 = Game_AnyBuildingReachesCellList(this,this_02), iVar2 == 0)) {
      if (this_02 != (undefined4 *)0x0) {
        (**(code **)*this_02)(1);
      }
      return 1;
    }
LAB_00489368:
    if (this_02 != (undefined4 *)0x0) {
      (**(code **)*this_02)(1);
      return 0;
    }
  }
  else {
LAB_0048933a:
    if (this_02 != (undefined4 *)0x0) {
      (**(code **)*this_02)(1);
      return 0;
    }
  }
  return 0;
}

