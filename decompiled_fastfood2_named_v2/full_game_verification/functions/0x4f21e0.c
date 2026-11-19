// rea decompile_all
// name: Object_UpdateWalkStep
// address: 0x4f21e0
// body: available
// range: 0x4f21e0-0x4f26e4 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall Object_UpdateWalkStep(void *this,uint *param_1,uint param_2)

{
  uint *this_00;
  uint *puVar1;
  bool bVar2;
  int iVar3;
  undefined3 extraout_var;
  uint uVar4;
  int iVar5;
  uint uVar6;
  longlong lVar7;
  longlong lVar8;
  int local_34;
  int local_30;
  int local_28;
  uint local_20;
  undefined4 local_1c;
  undefined4 local_18 [2];
  undefined4 local_10 [3];
  
                    /* Advances one walking sprite element and its directional variant. */
  _DAT_00580a58 = 1;
  if ((short)param_1[10] == -1) {
    RecordList_TickFrameAndGetPoints((void *)param_1[0x16],*param_1,local_10,local_18);
    _DAT_00580a58 = 0;
    return;
  }
  if ((param_1[0x10] != 0xffffffff) &&
     (iVar3 = MapActor_UpdateLinkedOverlays(this,(int *)param_1), iVar3 != 0)) {
    _DAT_00580a58 = 0;
    return;
  }
  uVar6 = local_20;
LAB_004f2245:
  do {
    uVar4 = *param_1;
    local_20 = 0;
    if (((-1 < (int)uVar4) && ((int)uVar4 < *(int *)(param_1[0x16] + 0x48))) &&
       (*(char *)(*(int *)(param_1[0x16] + 0x4c) + 0x3e + uVar4 * 0x48) != '\0')) {
      Record_TryAdvanceFrame((void *)param_1[0x16],uVar4,param_2,local_10,local_18,&local_1c);
      lVar7 = __ftol();
      lVar8 = __ftol();
      bVar2 = Object_TryNeighborPlacement(this,(int *)param_1,(int)lVar7,(int)lVar8);
      if (CONCAT31(extraout_var,bVar2) != 0) {
        uVar6 = Enum_MapDirection((int)param_1);
        param_1[0x10] = uVar6;
        Object_UpdateState(this,(int)param_1);
        Record_ClearFlags48((void *)param_1[0x16],*param_1);
        _DAT_00580a58 = 0;
        return;
      }
      RecordList_TickFrameAtTimeAndGetPoints
                ((void *)param_1[0x16],*param_1,param_2,local_10,local_18,&local_20);
      Object_MoveToMapCell(this,(int *)param_1,(int)lVar7,(int)lVar8);
      if (local_20 == 0) {
        _DAT_00580a58 = 0;
        return;
      }
      Object_SetShort28(param_1,(short)param_1[10] + 1);
      param_1[9] = param_1[8];
      uVar4 = Array_GetPtr4(param_1 + 5,(int)(short)param_1[10]);
      param_1[8] = uVar4;
      iVar3 = Array_GetPtr4(param_1 + 5,(short)param_1[10] + 1);
      if (iVar3 == 0) {
        Object_UpdateState(this,(int)param_1);
        Record_ClearFlags48((void *)param_1[0x16],*param_1);
LAB_004f2693:
        param_1[3] = 0;
        Object_SetShort28(param_1,0xffff);
        _DAT_00580a58 = 0;
        return;
      }
    }
    this_00 = param_1 + 5;
    iVar3 = Array_GetPtr4(this_00,(int)(short)param_1[10]);
    if (iVar3 == 0) {
      _DAT_00580a58 = 0;
      return;
    }
    local_28 = *(int *)(iVar3 + 0xc);
    local_34 = *(int *)(iVar3 + 0x10);
    iVar3 = Array_GetPtr4(this_00,(short)param_1[10] + 1);
    if (iVar3 == 0) {
      _DAT_00580a58 = 0;
      return;
    }
    local_30 = *(int *)(iVar3 + 0xc);
    iVar3 = *(int *)(iVar3 + 0x10);
    iVar5 = Array_GetPtr4(this_00,(int)(short)param_1[10]);
    if ((*(char *)(iVar5 + 6) == '\x02') &&
       (iVar5 = Array_GetPtr4(this_00,(short)param_1[10] + 1), *(char *)(iVar5 + 6) == '\x02')) {
      Object_UpdateState(this,(int)param_1);
      Record_ClearFlags48((void *)param_1[0x16],*param_1);
      Object_SetShort28(param_1,(short)param_1[10] + 1);
      uVar4 = Array_GetPtr4(this_00,(int)(short)param_1[10]);
      param_1[9] = uVar4;
      uVar4 = Array_GetPtr4(this_00,(int)(short)param_1[10]);
      param_1[8] = uVar4;
      Record_SetDoubles48((void *)param_1[0x16],*param_1,local_30 - *(int *)((int)this + 0xf8),
                          iVar3 - *(int *)((int)this + 0xfc));
      iVar3 = Array_GetPtr4(this_00,(int)(short)param_1[10]);
      local_28 = *(int *)(iVar3 + 0xc);
      iVar3 = Array_GetPtr4(this_00,(int)(short)param_1[10]);
      local_34 = *(int *)(iVar3 + 0x10);
      puVar1 = param_1 + 0x17;
      *puVar1 = *puVar1 - *(int *)((int)this + 0x24);
      param_1[0x19] = param_1[0x19] - *(int *)((int)this + 0x24);
      param_1[0x18] = param_1[0x18] - *(int *)((int)this + 0x28);
      param_1[0x1a] = param_1[0x1a] - *(int *)((int)this + 0x28);
      Gfx_BlitRectList(DAT_0058072c,puVar1);
      iVar3 = Array_GetPtr4(this_00,(short)param_1[10] + 1);
      if (iVar3 == 0) goto LAB_004f2693;
      iVar3 = Array_GetPtr4(this_00,(short)param_1[10] + 1);
      local_30 = *(int *)(iVar3 + 0xc);
      iVar3 = Array_GetPtr4(this_00,(short)param_1[10] + 1);
      iVar3 = *(int *)(iVar3 + 0x10);
    }
    if (param_1[1] != 0xffffffff) {
      local_28 = local_28 - *(int *)((int)this + 0xf8);
      iVar3 = iVar3 - *(int *)((int)this + 0xfc);
      local_34 = local_34 - *(int *)((int)this + 0xfc);
      local_30 = local_30 - *(int *)((int)this + 0xf8);
      Record_SetDoubles48B(param_1[0x16],*param_1,(double)local_30,(double)iVar3);
      if (local_30 < local_28) {
LAB_004f2610:
        uVar6 = param_1[0xb];
        if (iVar3 < local_34) {
          uVar6 = uVar6 + 6;
          param_1[3] = uVar6;
          Record_SelectVariant((void *)param_1[0x16],*param_1,uVar6);
          goto LAB_004f2245;
        }
        if (iVar3 <= local_34) {
          uVar6 = uVar6 + 7;
          param_1[3] = uVar6;
          Record_SelectVariant((void *)param_1[0x16],*param_1,uVar6);
          goto LAB_004f2245;
        }
      }
      else {
        if (local_28 < local_30) {
          uVar6 = param_1[0xb];
          if (iVar3 < local_34) {
            uVar6 = uVar6 + 4;
            param_1[3] = uVar6;
            Record_SelectVariant((void *)param_1[0x16],*param_1,uVar6);
          }
          else if (local_34 < iVar3) {
LAB_004f2555:
            uVar6 = uVar6 + 2;
            param_1[3] = uVar6;
            Record_SelectVariant((void *)param_1[0x16],*param_1,uVar6);
          }
          else {
LAB_004f256c:
            uVar6 = uVar6 + 3;
            param_1[3] = uVar6;
            Record_SelectVariant((void *)param_1[0x16],*param_1,uVar6);
          }
          goto LAB_004f2245;
        }
LAB_004f2583:
        if (local_28 == local_30) {
          if (iVar3 < local_34) {
            uVar6 = param_1[0xb] + 5;
            param_1[3] = uVar6;
            Record_SelectVariant((void *)param_1[0x16],*param_1,uVar6);
            goto LAB_004f2245;
          }
          uVar6 = param_1[0xb] + 1;
        }
      }
      param_1[3] = uVar6;
      Record_SelectVariant((void *)param_1[0x16],*param_1,uVar6);
      goto LAB_004f2245;
    }
    iVar3 = iVar3 + -0xd0;
    local_28 = local_28 + -0xa0;
    local_30 = local_30 + -0xa0;
    local_34 = local_34 + -0xd0;
    Record_SetDoubles48B(param_1[0x16],*param_1,(double)local_30,(double)iVar3);
    if (local_30 < local_28) goto LAB_004f2610;
    if (local_30 <= local_28) goto LAB_004f2583;
    uVar6 = param_1[0xb];
    if (local_34 <= iVar3) {
      if (iVar3 <= local_34) goto LAB_004f256c;
      goto LAB_004f2555;
    }
    uVar6 = uVar6 + 4;
    param_1[3] = uVar6;
    Record_SelectVariant((void *)param_1[0x16],*param_1,uVar6);
  } while( true );
}

