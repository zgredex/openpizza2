// rea decompile_all
// name: Person_UpdateStreetBehavior
// address: 0x40b110
// body: available
// range: 0x40b110-0x40b3b9 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Person_UpdateStreetBehavior(void *this,void *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined1 uVar4;
  undefined3 extraout_var;
  int iVar5;
  uint uVar6;
  void *pvVar7;
  void *this_00;
  uint uVar8;
  undefined4 *this_01;
  uint extraout_EDX;
  
                    /* Updates a person or vehicle outside any building. */
  uVar4 = Object_IsVisibleThisFrame((int)param_1);
  iVar5 = *(int *)((int)param_1 + 0x90);
  iVar1 = *(int *)((int)param_1 + 0x4c);
  iVar2 = *(int *)((int)param_1 + 0x54);
  Person_UpdateWaitAndHunger(param_1);
  if (CONCAT31(extraout_var,uVar4) == 0) {
    if (iVar5 != 0) {
      if (*(int *)((int)param_1 + 200) == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(*(int *)((int)param_1 + 200) + 0x20);
      }
      if (*(int *)((int)param_1 + 0xf8) == iVar5) {
        iVar5 = *(int *)((int)param_1 + 0x90);
        *(undefined4 *)((int)param_1 + 0x90) = 0;
        if (iVar5 == 1) {
          if (*(int *)((int)param_1 + 0xfc) == 0) {
            return;
          }
          iVar5 = *(int *)((int)param_1 + 0x30);
          if (((iVar5 == 0xb) || (iVar5 == 0xf)) || (iVar5 == 0x21)) {
            Object_ActionActivate(param_1,extraout_EDX);
            return;
          }
          return;
        }
        if (iVar5 != 7) {
          if (iVar5 == 0xd) {
            FUN_0050ab10(param_1);
            return;
          }
          return;
        }
        do {
          uVar6 = FUN_004034d0(0,7);
        } while (uVar6 == *(uint *)((int)param_1 + 0x34));
        pvVar3 = *(void **)((int)this + 0x21c);
        FUN_0050e710(param_1,1);
        FUN_0050e890(param_1,0x2e);
        pvVar7 = (void *)FUN_004017f0((void *)((int)this + 4),*(int *)((int)this + 0x2f4),(int *)0x0
                                     );
        pvVar7 = (void *)FUN_004d74c0(pvVar7,0x22,0,'\0');
        this_00 = (void *)FUN_004017f0((void *)((int)this + 4),*(int *)((int)this + 0x2f4),
                                       (int *)0x0);
        uVar8 = FUN_004034d0(0,1);
        this_01 = FUN_004d8c80(this_00,(undefined4 *)0x1,uVar6,uVar8);
        FUN_0050e730(this_01,pvVar7,1);
        if (pvVar3 == param_1) {
          *(undefined4 **)((int)this + 0x21c) = this_01;
          *(undefined4 *)((int)this + 0x2da8) = 1;
          return;
        }
        return;
      }
    }
    if (((iVar2 != 0) && (*(int *)((int)param_1 + 0xfc) != 0)) &&
       (*(int *)(*(int *)((int)param_1 + 0xfc) + 4) == 0xf)) {
      Object_ActionActivate(param_1,extraout_EDX);
      return;
    }
    switch(*(undefined4 *)((int)param_1 + 0x38)) {
    case 1:
      MapObject_StepToRandomCell(param_1);
      return;
    case 2:
      pvVar3 = *(void **)((int)param_1 + 0xd0);
      if ((pvVar3 != (void *)0x0) && (*(int *)((int)pvVar3 + 4) != 0x1a)) {
        FUN_0050ab30(param_1,pvVar3);
        FUN_00506c00(param_1);
        return;
      }
      break;
    case 3:
      iVar5 = Person_SelectRouteStopForTimeSlot(param_1,param_2);
      if (iVar5 == 0) {
        Person_WanderToRandomTile(param_1);
        return;
      }
      break;
    case 4:
      if (*(int *)((int)param_1 + 0x168) == 0) {
        Person_ReturnToHomeBase(param_1);
        return;
      }
      Person_SelectRouteStopForTimeSlot(param_1,param_2);
      return;
    case 0x1d:
      FUN_0050ab70(param_1,*(void **)((int)param_1 + 0xfc));
      FUN_0050e890(param_1,3);
      return;
    }
  }
  else {
    if (iVar1 != 0) {
      Person_FindNearbyBranchToVisit(param_1);
      return;
    }
    Person_SelectRouteStopForTimeSlot(param_1,param_2);
  }
  return;
}

