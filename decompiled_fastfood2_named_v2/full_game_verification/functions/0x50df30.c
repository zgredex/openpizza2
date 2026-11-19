// rea decompile_all
// name: Person_UpdateSocialEncounter
// address: 0x50df30
// body: available
// range: 0x50df30-0x50e1da inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Person_UpdateSocialEncounter(void *this,int param_1)

{
  bool bVar1;
  bool bVar2;
  undefined1 uVar3;
  void *this_00;
  int iVar4;
  int iVar5;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  float fVar6;
  int iVar7;
  uint uVar8;
  bool bVar9;
  undefined4 local_4;
  
                    /* Advances a social encounter between two people. */
  if ((*(int *)((int)this + 0x30) != 0xd) && (*(int *)((int)this + 0x110) == -1)) {
    return;
  }
  switch(*(int *)((int)this + 0x30)) {
  default:
    iVar7 = param_1;
    break;
  case 0x1d:
  case 0x1e:
  case 0xd:
  case 0x17:
    iVar7 = *(int *)((int)this + 0x8c);
  }
  this_00 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),iVar7,(int *)0x0);
  if ((((this_00 == (void *)0x0) || (iVar4 = State_Is2DOr2E((int)this_00), iVar4 != 0)) ||
      (*(int *)((int)this_00 + 0x74) == 0)) ||
     ((*(int *)((int)this_00 + 0x30) != 0xd && (*(int *)((int)this_00 + 0x110) == -1)))) {
LAB_0050e1c8:
    Object_SetState(this,0x2f);
    return;
  }
  iVar5 = Object_IsWithinServiceRange(this,param_1,iVar7);
  bVar9 = *(short *)(*(int *)((int)this + 200) + 0x28) != -1;
  iVar4 = *(int *)((int)this + 0x108);
  uVar3 = Object_IsVisibleThisFrame((int)this);
  if ((CONCAT31(extraout_var,uVar3) == 0) || (bVar9)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  bVar1 = bVar2;
  if ((*(int *)((int)this + 0x108) == 4) || (bVar1 = bVar9, *(int *)((int)this + 0x108) == 5)) {
    if (bVar1) {
      return;
    }
  }
  else {
    if (iVar4 != 3) {
      if (iVar5 == 0) {
        iVar7 = Person_FindFreeNeighborCell(this,param_1,iVar7,&local_4);
        *(undefined4 *)((int)this + 0x88) = local_4;
        Person_AdvanceRoute(this,iVar7);
        return;
      }
      if (bVar9) {
        Person_TruncatePathToCurrentStep((int)this);
        return;
      }
      if (bVar2) {
        UI_DetachChildRecord((int)this);
      }
      Object_BeginServiceDecision(this,(float)this_00);
      return;
    }
    if (bVar2) {
      return;
    }
    bVar9 = AI_TestActionChance(this,(int)this_00,0);
    if (CONCAT31(extraout_var_00,bVar9) != 0) {
      *(undefined4 *)((int)this_00 + 0x108) = 4;
      fVar6 = Object_ComputeInteractionCell(this_00,(float)this);
      UI_DetachChildRecord((int)this_00);
      UI_SetChildRecordVariant(this_00,(int)fVar6);
      UI_UpdateValueBar(this_00,this,0);
      if (0 < *(int *)((int)this_00 + 0xa8)) {
        if (*(int *)((int)this_00 + 0x38) == 7) {
          Object_SetState(this_00,0x2c);
        }
        *(undefined4 *)((int)this + 0x108) = 0xffffffff;
        if (*(int *)((int)this + 0x30) == 0x1e) {
          return;
        }
        AI_WanderToRandomRoadTile(this);
        return;
      }
      iVar7 = State_Is2DOr2E((int)this_00);
      if (iVar7 == 0) {
        uVar8 = UI_HitTestChildPoint(this,(float)this_00);
        *(uint *)((int)this + 0x88) = uVar8;
        Object_SetState(this,0x2f);
        Character_OnArriveAtDestination(this_00,(float)this,0);
        return;
      }
      goto LAB_0050e1c8;
    }
    if (*(int *)((int)this + 0x30) != 0x1e) {
      uVar8 = Random_RangeFast(1,100);
      if ((int)uVar8 < 0x32) {
        Object_BeginServiceDecision(this,(float)this_00);
        return;
      }
      *(undefined4 *)((int)this + 0x108) = 0xffffffff;
      AI_WanderToRandomRoadTile(this);
      return;
    }
  }
  *(undefined4 *)((int)this + 0x108) = 0xffffffff;
  return;
}

