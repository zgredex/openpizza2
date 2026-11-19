// rea decompile_all
// name: Person_SelectFacingTarget
// address: 0x50cdc0
// body: available
// range: 0x50cdc0-0x50d1be inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x01040404) */

int __thiscall Person_SelectFacingTarget(void *this,void *param_1)

{
  bool bVar1;
  char cVar2;
  void *this_00;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  int iVar3;
  void *pvVar4;
  undefined3 extraout_var_03;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int local_10;
  undefined4 local_c;
  int local_8;
  void *local_4;
  
                    /* Selects and links a facing target. */
  iVar7 = -1;
  local_4 = *(void **)((int)param_1 + 0x16f0);
  if (local_4 != (void *)0x0) {
    local_8 = *(int *)((int)this + 0x84);
    local_10 = 0;
    pvVar4 = param_1;
    if (0 < *(int *)((int)local_4 + 0x8c)) {
      do {
        this_00 = (void *)Game_MapRecordToGlobal(local_4,local_10);
        iVar5 = *(int *)((int)this_00 + 0xa4);
        if ((((iVar5 != -1) && (*(int *)((int)this_00 + 0x38) != 0x2d)) &&
            (*(int *)((int)this_00 + 0x38) != 0x2e)) &&
           ((*(int *)((int)this_00 + 0x30) != 0x1d || ((iVar5 != 0x1a && (iVar5 != 0x19)))))) {
          switch(*(int *)((int)this_00 + 0x30)) {
          case 0x16:
            if ((*(int *)((int)this + 0xa4) != 0x16) &&
               (bVar1 = MapObject_IsFacingTarget(this_00,param_1,this),
               CONCAT31(extraout_var,bVar1) != 0)) {
              if (*(int *)((int)this_00 + 0xa4) == 1) {
                if (iVar7 < 1) {
                  pvVar4 = *(void **)((int)this_00 + 0x164);
                  iVar7 = 1;
                }
              }
              else if (iVar7 < 2) {
                pvVar4 = *(void **)((int)this_00 + 0x164);
                iVar7 = 2;
              }
            }
            break;
          case 0x1d:
            bVar1 = MapObject_IsFacingTarget(this_00,param_1,this);
            if (CONCAT31(extraout_var_02,bVar1) != 0) {
              if (*(int *)((int)this_00 + 0xa4) == 0xe) {
                if (iVar7 < 5) {
                  pvVar4 = *(void **)((int)this_00 + 0x164);
                  iVar7 = 5;
                }
              }
              else if (iVar7 < 6) {
                pvVar4 = *(void **)((int)this_00 + 0x164);
                iVar7 = 6;
              }
            }
            break;
          case 0x1e:
            bVar1 = MapObject_IsFacingTarget(this_00,param_1,this);
            if ((CONCAT31(extraout_var_01,bVar1) != 0) && (iVar7 < 4)) {
              pvVar4 = *(void **)((int)this_00 + 0x164);
              iVar7 = 4;
            }
            break;
          case 0x1f:
            if (((*(int *)((int)this + 0xa4) != 0x16) &&
                (bVar1 = MapObject_IsFacingTarget(this_00,param_1,this),
                CONCAT31(extraout_var_00,bVar1) != 0)) && (iVar7 < 3)) {
              pvVar4 = *(void **)((int)this_00 + 0x164);
              iVar7 = 3;
            }
          }
        }
        local_10 = local_10 + 1;
      } while (local_10 < *(int *)((int)local_4 + 0x8c));
    }
    if (local_8 < iVar7) {
      *(void **)((int)this + 0x8c) = pvVar4;
      *(int *)((int)this + 0x84) = iVar7;
      switch(iVar7) {
      case 1:
      case 2:
      case 3:
      case 4:
        iVar5 = Person_FindFreeNeighborCell(this,param_1,(int)pvVar4,&local_c);
        iVar3 = UI_RemoveLastChild((int)this);
        if (iVar3 != iVar5) {
          *(undefined4 *)((int)this + 0x88) = local_c;
          Object_SetState(this,0x28);
          Person_AdvanceRoute(this,iVar5);
          return iVar7;
        }
        break;
      case 5:
      case 6:
        pvVar4 = (void *)IDMap_Lookup((void *)((int)DAT_0057c670 + 0x3c),(int)pvVar4,(int *)0x0);
        Object_SetState(this,0x2c);
        *(undefined4 *)((int)pvVar4 + 0x8c) = *(undefined4 *)((int)this + 0x164);
        Object_SetState(pvVar4,0x2c);
        Branch_InitCityObjects(param_1,0x1e);
        if (*(int *)((int)pvVar4 + 0x110) != -1) {
          iVar7 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((int)pvVar4 + 0x110));
          *(int *)(iVar7 + 0x78) = *(int *)(iVar7 + 0x78) + 1;
          return -1;
        }
      }
    }
    else if (local_8 != -1) {
      iVar7 = IDMap_Lookup((void *)((int)DAT_0057c670 + 0x3c),*(int *)((int)this + 0x8c),(int *)0x0)
      ;
      if (((iVar7 == 0) || (*(int *)(iVar7 + 200) == 0)) ||
         (iVar7 = State_Is2DOr2E(iVar7), iVar7 != 0)) {
        *(undefined4 *)((int)this + 0x84) = 0xffffffff;
        return -1;
      }
      if (0 < local_8) {
        if (local_8 < 4) {
          iVar7 = Person_ApplyAttackOutcome(this,param_1,*(int *)((int)this + 0x8c));
          if (iVar7 != 0) {
LAB_0050d132:
            if (*(int *)((int)this + 200) == 0) {
              uVar6 = 0xffffffff;
            }
            else {
              uVar6 = *(undefined4 *)(*(int *)((int)this + 200) + 0xc);
            }
            *(undefined4 *)((int)this + 0x88) = uVar6;
            Person_TruncatePathToCurrentStep((int)this);
            *(undefined4 *)((int)this + 0x84) = 0xffffffff;
            Object_SetState(this,8);
            return -1;
          }
          iVar7 = Person_FindFreeNeighborCell(this,param_1,*(int *)((int)this + 0x8c),&local_c);
          iVar5 = UI_RemoveLastChild((int)this);
          if (iVar5 != iVar7) {
            Person_AdvanceRoute(this,iVar7);
            return local_8;
          }
        }
        else if (local_8 == 4) {
          cVar2 = Person_ResolveGroupFight(this,param_1,*(int *)((int)this + 0x8c));
          iVar7 = CONCAT31(extraout_var_03,cVar2);
          if (iVar7 == 0) {
            iVar7 = Person_FindFreeNeighborCell(this,param_1,*(int *)((int)this + 0x8c),&local_c);
            iVar5 = UI_RemoveLastChild((int)this);
            if (iVar5 != iVar7) {
              Person_AdvanceRoute(this,iVar7);
              return 4;
            }
          }
          else {
            if (iVar7 == 1) goto LAB_0050d132;
            if (iVar7 == 2) {
              Person_TruncatePathToCurrentStep((int)this);
              Object_SetState(this,0x2c);
            }
          }
        }
      }
    }
  }
  return -1;
}

