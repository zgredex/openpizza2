// rea decompile_all
// name: FUN_004f3ec0
// address: 0x4f3ec0
// body: available
// range: 0x4f3ec0-0x4f43a1 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004f3ec0(void *this,int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  longlong lVar7;
  int local_84;
  undefined4 *local_7c;
  int local_78;
  int local_74;
  int local_70;
  short *local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  uint local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  uint local_34;
  void *local_30;
  uint local_2c;
  double local_28;
  double local_20;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0055a04b;
  pvStack_14 = ExceptionList;
  local_60 = 10000000;
  local_84 = 0x28;
  local_4c = param_3;
  ExceptionList = &pvStack_14;
  local_30 = operator_new(0x1c);
  local_c = 0;
  if (local_30 == (void *)0x0) {
    local_7c = (undefined4 *)0x0;
  }
  else {
    local_7c = FUN_004013a0(local_30,0);
  }
  local_c = 0xffffffff;
  iVar2 = FUN_004f0d00(this,(int *)0x1,param_1,param_2,(uint *)0x0);
  local_50 = (uint)*(ushort *)(iVar2 + 4);
  *(undefined4 *)((int)this + 0xb4) = 0;
  piVar3 = (int *)Grid_GetNeighborCell
                            (this,*(int *)((int)this + 0x4c) + *(int *)(iVar2 + 8) * 0xc,param_3);
  FUN_004f34c0(this,piVar3,&local_74,&local_78);
  local_70 = *(int *)(iVar2 + 0x10);
  local_6c = *(short **)(iVar2 + 0xc);
  local_54 = 0;
  local_28 = (double)(local_78 - local_70) / (double)(local_74 - (int)local_6c);
  local_20 = (double)local_70 - (double)(int)local_6c * local_28;
LAB_004f3fd7:
  do {
    local_84 = local_84 + 10;
    Grid_CollectNearbyIds(this,local_7c,iVar2,0x14,local_84);
    if (local_7c[5] == 0) {
      if (local_84 < 800) goto LAB_004f3fd7;
LAB_004f400d:
      param_3 = param_3 + 1;
      if (param_3 == local_4c) {
        FUN_0048e0a0();
      }
      if (3 < param_3) {
        param_3 = 0;
      }
      local_84 = 0x28;
      piVar3 = (int *)Grid_GetNeighborCell
                                (this,*(int *)((int)this + 0x4c) + *(int *)(iVar2 + 8) * 0xc,param_3
                                );
      FUN_004f34c0(this,piVar3,&local_74,&local_78);
      local_70 = *(int *)(iVar2 + 0x10);
      local_6c = *(short **)(iVar2 + 0xc);
      local_28 = (double)(local_78 - local_70) / (double)(local_74 - (int)local_6c);
      local_20 = (double)local_70 - (double)(int)local_6c * local_28;
    }
    else if (799 < local_84) goto LAB_004f400d;
    local_58 = 0;
    if (0 < (int)local_7c[5]) {
      do {
        iVar4 = FUN_004017f0(local_7c,local_58,(int *)0x0);
        local_5c = FUN_004f0cc0(this,1,iVar4);
        local_64 = 0;
        local_6c = (short *)(local_5c + 0x14);
        do {
          iVar4 = local_5c;
          if (*local_6c != -1) {
            local_40 = FUN_004f0cc0(this,1,(int)*local_6c);
            iVar5 = *(int *)(local_40 + 0x10);
            local_70 = *(int *)(iVar4 + 0x10);
            iVar6 = *(int *)(local_40 + 0xc);
            iVar4 = *(int *)(iVar4 + 0xc);
            local_68 = iVar6 - iVar4;
            local_48 = iVar4;
            if (local_28 != (double)(iVar5 - local_70) / (double)local_68) {
              lVar7 = __ftol();
              local_48 = (int)lVar7;
              lVar7 = __ftol();
              iVar1 = local_48;
              local_44 = (int)lVar7;
              local_68 = iVar6;
              if (iVar4 <= iVar6) {
                local_68 = iVar4;
              }
              if (iVar4 < iVar6) {
                iVar4 = iVar6;
              }
              iVar6 = iVar5;
              if (local_70 <= iVar5) {
                iVar6 = local_70;
              }
              if (iVar5 <= local_70) {
                iVar5 = local_70;
              }
              if ((((local_68 <= local_48) && (local_48 <= iVar4)) && (iVar6 <= local_44)) &&
                 (local_44 <= iVar5)) {
                switch(param_3) {
                case 0:
                  if (local_48 < *(int *)(iVar2 + 0xc)) {
                    iVar4 = *(int *)(iVar2 + 0x10);
joined_r0x004f41fc:
                    if (iVar4 < local_44) goto switchD_004f41d7_default;
                  }
                  break;
                case 1:
                  if (*(int *)(iVar2 + 0xc) < local_48) {
                    iVar4 = *(int *)(iVar2 + 0x10);
                    goto joined_r0x004f41fc;
                  }
                  break;
                case 2:
                  if (*(int *)(iVar2 + 0xc) < local_48) {
                    iVar4 = *(int *)(iVar2 + 0x10);
joined_r0x004f4220:
                    if (local_44 < iVar4) goto switchD_004f41d7_default;
                  }
                  break;
                case 3:
                  if (local_48 < *(int *)(iVar2 + 0xc)) {
                    iVar4 = *(int *)(iVar2 + 0x10);
                    goto joined_r0x004f4220;
                  }
                  break;
                default:
switchD_004f41d7_default:
                  iVar4 = FUN_004ed570(*(int *)(iVar2 + 0xc),*(int *)(iVar2 + 0x10),local_48,
                                       local_44);
                  if (iVar4 < local_60) {
                    local_34 = (uint)*(ushort *)(local_5c + 4);
                    local_38 = local_44;
                    local_3c = iVar1;
                    local_30 = (void *)(uint)*(ushort *)(local_40 + 4);
                    local_54 = 1;
                    local_60 = iVar4;
                  }
                  goto LAB_004f4298;
                }
              }
            }
          }
          local_64 = local_64 + 1;
          local_6c = local_6c + 1;
        } while (local_64 < 8);
LAB_004f4298:
        local_58 = local_58 + 1;
      } while (local_58 < (int)local_7c[5]);
    }
    List_Node_Reset((int)local_7c);
    if (local_54 != 0) {
      iVar2 = FUN_004f0d00(this,(int *)0x1,local_3c - *(int *)((int)this + 0x24),
                           local_38 - *(int *)((int)this + 0x28),&local_2c);
      *(undefined4 *)((int)this + 0xb4) = 0;
      iVar4 = FUN_004f0cc0(this,1,local_50);
      Map_LinkObjects(1,iVar4,iVar2);
      iVar4 = FUN_004f0cc0(this,1,local_34);
      Map_LinkObjects(1,iVar4,iVar2);
      iVar5 = FUN_004f0cc0(this,1,(int)local_30);
      Map_LinkObjects(1,iVar5,iVar2);
      if (local_2c == 0) {
        FUN_004f08e0(1,iVar4,iVar5);
      }
      *(undefined4 *)((int)this + 0xb4) = 0;
      if (local_7c != (undefined4 *)0x0) {
        (**(code **)*local_7c)(1);
      }
      FUN_004f0cc0(this,1,local_50);
      ExceptionList = pvStack_14;
      return;
    }
  } while( true );
}

