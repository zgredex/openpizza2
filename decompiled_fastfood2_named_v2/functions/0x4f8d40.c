// rea decompile_all
// name: FUN_004f8d40
// address: 0x4f8d40
// body: available
// range: 0x4f8d40-0x4f96d3 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_004f8d40(void *this,void *param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  short *psVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int *piVar12;
  short *local_ac;
  int *local_a8;
  uint local_a4;
  undefined4 local_a0;
  int local_98 [11];
  undefined4 local_6c [5];
  int local_58;
  int local_50 [8];
  int local_30 [8];
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a108;
  local_c = ExceptionList;
  local_a0 = 0;
  ExceptionList = &local_c;
  FUN_004013a0(local_6c,0);
  local_4 = 0;
  if (param_2 != 0) {
    iVar9 = 0;
    psVar7 = (short *)(param_2 + 4);
    do {
      iVar5 = ((int)*(short *)(param_2 + 4 + (iVar9 - 1U & 7) * 0x34) >> 1) + (int)*psVar7;
      local_30[iVar9] = iVar5;
      if (iVar5 < 6) {
        local_98[iVar9] = 0;
      }
      else {
        local_98[iVar9] = 1;
      }
      iVar9 = iVar9 + 1;
      psVar7 = psVar7 + 0x1a;
    } while (iVar9 < 8);
    iVar9 = 0;
    uVar4 = 2;
    do {
      if ((*(int *)((int)local_98 + iVar9) == 0) && (uVar8 = uVar4 - 1 & 7, local_98[uVar8] != 0)) {
        uVar10 = uVar4 & 7;
        if (local_98[uVar10] == 0) {
          if ((local_98[uVar4 + 1 & 7] == 0) || (local_30[uVar10] < 3)) {
            if ((local_98[uVar4 - 3 & 7] == 0) || (*(int *)((int)local_30 + iVar9) < 3)) {
              local_98[uVar8] = 0;
            }
            else {
LAB_004f8f06:
              *(undefined4 *)((int)local_98 + iVar9) = 1;
            }
          }
          else {
            local_98[uVar10] = 1;
          }
        }
        else {
          uVar8 = uVar4 + 1 & 7;
          if (local_98[uVar8] == 0) {
            if (local_30[uVar8] <= *(int *)((int)local_30 + iVar9)) goto LAB_004f8f06;
            local_98[uVar8] = 1;
          }
        }
      }
      iVar9 = iVar9 + 4;
      iVar5 = uVar4 - 1;
      uVar4 = uVar4 + 1;
    } while (iVar5 < 8);
    iVar5 = 0;
    piVar6 = local_98;
    iVar9 = 8;
    do {
      if (*piVar6 == 0) {
        iVar5 = iVar5 + 1;
      }
      piVar6 = piVar6 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    if (iVar5 == 8) {
      iVar9 = FUN_00488be0(DAT_0057c670,*(int *)((int)param_1 + 0x30));
      if (iVar9 != *(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200)) {
        FUN_004fc990(this,param_1,0);
        local_4 = 0xffffffff;
        List_Node_Destroy(local_6c);
        ExceptionList = local_c;
        return 0;
      }
      local_98[3] = 1;
      local_98[4] = 1;
      local_98[5] = 1;
    }
    else if (iVar5 < 2) {
      iVar9 = 0;
      iVar11 = 1;
      piVar6 = local_30;
      do {
        piVar6 = piVar6 + 1;
        if (*piVar6 < local_30[0]) {
          iVar9 = iVar11;
          local_30[0] = *piVar6;
        }
        iVar11 = iVar11 + 1;
      } while (iVar11 < 8);
      local_98[iVar9] = 0;
      if (iVar5 < 1) {
        uVar4 = iVar9 - 1U & 7;
        uVar8 = iVar9 + 1U & 7;
        if (local_98[uVar8] < local_98[uVar4]) {
          local_98[uVar8] = 0;
        }
        else {
          local_98[uVar4] = 0;
        }
      }
    }
    goto LAB_004f8ffe;
  }
  piVar6 = local_98;
  for (iVar9 = 8; iVar9 != 0; iVar9 = iVar9 + -1) {
    *piVar6 = 0;
    piVar6 = piVar6 + 1;
  }
  piVar6 = local_30;
  for (iVar9 = 8; iVar9 != 0; iVar9 = iVar9 + -1) {
    *piVar6 = 0;
    piVar6 = piVar6 + 1;
  }
  iVar9 = *(int *)((int)param_1 + 0x38);
  if (iVar9 == 0) {
LAB_004f8dc7:
    local_98[3] = 1;
    local_98[7] = 1;
    local_98[6] = 1;
    local_98[5] = 1;
    local_98[4] = 1;
  }
  else if ((0 < iVar9) && (iVar9 < 3)) {
    local_98[2] = 1;
    goto LAB_004f8dc7;
  }
  iVar9 = 0;
  do {
    if (*(int *)((int)local_98 + iVar9) != 0) {
      *(undefined4 *)((int)local_30 + iVar9) = 10;
    }
    iVar9 = iVar9 + 4;
  } while (iVar9 < 0x20);
  local_30[7] = 5;
  if (local_98[2] == 0) {
    local_30[3] = 5;
  }
  else {
    local_30[2] = 5;
  }
LAB_004f8ffe:
  local_98[9] = 3;
  iVar9 = 0;
  uVar4 = 2;
  piVar6 = local_98;
  do {
    if (((*piVar6 != 0) && (local_98[uVar4 - 1 & 7] != 0)) && (local_98[uVar4 & 7] != 0)) {
      local_98[9] = iVar9;
      break;
    }
    iVar9 = iVar9 + 1;
    piVar6 = piVar6 + 1;
    uVar4 = uVar4 + 1;
  } while ((int)uVar4 < 10);
  local_98[8] = 0;
  iVar9 = local_98[10];
  do {
    if (local_98[8] == 0) {
      local_a4 = 0;
    }
    else if (local_98[8] == 1) {
      local_a4 = 2;
    }
    else if (local_98[8] == 2) {
      local_a4 = 3;
    }
    iVar5 = FUN_0047aac0(param_1,0xffffffff);
    iVar11 = 0;
    if (0 < iVar5) {
      do {
        piVar6 = (int *)IDMap_Lookup((void *)((int)param_1 + 0x1500),iVar11,(int *)0x0);
        iVar2 = *piVar6;
        bVar1 = *(byte *)(iVar2 + 0x824);
        local_10 = CONCAT31(local_10._1_3_,bVar1);
        if (bVar1 == local_a4) {
          List_Add(local_6c,piVar6);
        }
        if (*(char *)(iVar2 + 0x824) == '\x01') {
          piVar6[1] = local_98[9];
        }
        iVar11 = iVar11 + 1;
      } while (iVar11 < iVar5);
    }
    if (param_2 == 0) {
      iVar5 = *(int *)((int)param_1 + 0x38);
      if (iVar5 == 0) {
        iVar9 = (-(uint)(local_a4 != 3) & 0xfffffffd) + 5;
      }
      else if (iVar5 == 1) {
        iVar9 = (-(uint)(local_a4 != 3) & 0xfffffffd) + 6;
      }
      else if (iVar5 == 2) {
        iVar9 = (-(uint)(local_a4 != 3) & 0xfffffffd) + 7;
      }
      piVar6 = local_30;
      piVar12 = local_50;
      for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
        *piVar12 = *piVar6;
        piVar6 = piVar6 + 1;
        piVar12 = piVar12 + 1;
      }
    }
    else {
      iVar9 = 0;
      if (local_a4 == 0) {
        psVar7 = (short *)(param_2 + 0x30);
        local_ac = (short *)(param_2 + 0x20);
        piVar6 = local_30;
        piVar12 = local_50;
        for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
          *piVar12 = *piVar6;
          piVar6 = piVar6 + 1;
          piVar12 = piVar12 + 1;
        }
        iVar5 = 8;
        do {
          iVar9 = iVar9 + ((int)psVar7[-10] >> 2);
          if (0x32 < *psVar7) {
            iVar9 = iVar9 - (int)*local_ac / (int)*psVar7;
          }
          psVar7 = psVar7 + 0x1a;
          local_ac = local_ac + 0x1a;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
LAB_004f92c5:
        if (iVar9 < 4) {
          if (iVar9 < 2) {
            if (-2 < iVar9) goto LAB_004f92e7;
            iVar9 = -1;
          }
          else {
            iVar9 = 1;
          }
        }
        else {
          iVar9 = 2;
        }
      }
      else {
        if (local_a4 == 2) {
          psVar7 = (short *)(param_2 + 0x30);
          local_ac = (short *)(param_2 + 0x24);
          piVar6 = local_30;
          piVar12 = local_50;
          for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
            *piVar12 = *piVar6;
            piVar6 = piVar6 + 1;
            piVar12 = piVar12 + 1;
          }
          iVar5 = 8;
          do {
            iVar9 = iVar9 + ((int)psVar7[-0xd] >> 2);
            if (0x32 < *psVar7) {
              iVar9 = iVar9 - (int)*local_ac / (int)*psVar7;
            }
            psVar7 = psVar7 + 0x1a;
            local_ac = local_ac + 0x1a;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          goto LAB_004f92c5;
        }
        if (local_a4 == 3) {
          psVar7 = (short *)(param_2 + 0x30);
          local_ac = (short *)(param_2 + 0x26);
          piVar6 = local_30;
          piVar12 = local_50;
          for (iVar9 = 8; iVar9 != 0; iVar9 = iVar9 + -1) {
            *piVar12 = *piVar6;
            piVar6 = piVar6 + 1;
            piVar12 = piVar12 + 1;
          }
          local_a8 = (int *)0x8;
          do {
            iVar9 = FUN_0047aac0(param_1,2);
            iVar5 = FUN_0047aac0(param_1,3);
            iVar9 = iVar9 * 2 - iVar5;
            if (0x32 < *psVar7) {
              iVar9 = iVar9 - (int)*local_ac / (int)*psVar7;
            }
            if (iVar5 + iVar9 < 2) {
              iVar9 = 2 - iVar5;
            }
            local_ac = local_ac + 0x1a;
            psVar7 = psVar7 + 0x1a;
            local_a8 = (int *)((int)local_a8 + -1);
          } while (local_a8 != (int *)0x0);
          goto LAB_004f92c5;
        }
LAB_004f92e7:
        iVar9 = 0;
      }
    }
    local_a8 = local_98;
    local_ac = (short *)0x2;
    do {
      if ((*local_a8 == 0) && (uVar4 = (int)local_ac - 1U & 7, local_98[uVar4] != 0)) {
        iVar11 = 1;
        iVar5 = local_98[(uint)local_ac & 7];
        psVar7 = local_ac;
        while (iVar5 != 0) {
          iVar11 = iVar11 + 1;
          psVar7 = (short *)((int)psVar7 + 1);
          iVar5 = local_98[(uint)psVar7 & 7];
        }
        piVar6 = (int *)IDMap_Lookup(local_6c,0,(int *)0x0);
        if (piVar6 == (int *)0x0) {
          piVar6 = FUN_004f7dd0(param_1,local_a4);
          iVar9 = iVar9 + -1;
          local_a0 = 1;
          if (iVar9 < 0) {
            iVar9 = 0;
          }
        }
        else {
          FUN_004016b0(local_6c,0);
        }
        piVar6[1] = uVar4;
        local_50[uVar4] = local_50[uVar4] + -6;
        uVar8 = uVar4 + 1 & 7;
        uVar4 = uVar4 + 2 & 7;
        local_50[uVar8] = local_50[uVar8] + -6;
        local_50[uVar4] = local_50[uVar4] + -6;
        if (3 < iVar11) {
          piVar6 = (int *)IDMap_Lookup(local_6c,0,(int *)0x0);
          if (piVar6 == (int *)0x0) {
            piVar6 = FUN_004f7dd0(param_1,local_a4);
            iVar9 = iVar9 + -1;
            local_a0 = 1;
            if (iVar9 < 0) {
              iVar9 = 0;
            }
          }
          else {
            FUN_004016b0(local_6c,0);
          }
          uVar4 = ((int)local_ac - 4U) + iVar11 & 7;
          piVar6[1] = uVar4;
          local_50[uVar4] = local_50[uVar4] + -6;
          uVar8 = uVar4 + 1 & 7;
          local_50[uVar8] = local_50[uVar8] + -6;
          local_50[uVar4 + 2 & 7] = local_50[uVar4 + 2 & 7] + -6;
        }
        if (6 < iVar11) {
          piVar6 = (int *)IDMap_Lookup(local_6c,0,(int *)0x0);
          if (piVar6 == (int *)0x0) {
            piVar6 = FUN_004f7dd0(param_1,local_a4);
            iVar9 = iVar9 + -1;
            local_a0 = 1;
            if (iVar9 < 0) {
              iVar9 = 0;
            }
          }
          else {
            FUN_004016b0(local_6c,0);
          }
          uVar4 = (uint)local_ac & 7;
          if (local_30[uVar4] <= local_30[(int)local_ac - 5U & 7]) {
            uVar4 = (int)local_ac + 1U & 7;
          }
          uVar8 = uVar4 + 1 & 7;
          piVar6[1] = uVar4;
          local_50[uVar4] = local_50[uVar4] + -6;
          local_50[uVar8] = local_50[uVar8] + -6;
          local_50[uVar4 + 2 & 7] = local_50[uVar4 + 2 & 7] + -6;
        }
      }
      local_a8 = local_a8 + 1;
      iVar5 = (int)local_ac - 1;
      local_ac = (short *)((int)local_ac + 1);
    } while (iVar5 < 8);
    if ((iVar9 < 0) && (0 < local_58)) {
      piVar6 = (int *)IDMap_Lookup(local_6c,0,(int *)0x0);
      FUN_0047a9d0(param_1,piVar6,0);
      FUN_004016b0(local_6c,0);
      local_a0 = 1;
    }
    iVar5 = iVar9;
    if (0 < iVar9) {
      local_a0 = 1;
      do {
        piVar6 = FUN_004f7dd0(param_1,local_a4);
        List_Add(local_6c,piVar6);
        iVar9 = iVar9 + -1;
        iVar5 = 0;
      } while (iVar9 != 0);
    }
    while (iVar9 = iVar5, 0 < local_58) {
      piVar6 = (int *)IDMap_Lookup(local_6c,0,(int *)0x0);
      uVar4 = 0xffffffff;
      iVar5 = 0;
      uVar8 = 1;
      do {
        if ((((*(int *)((int)local_98 + iVar5) != 0) && (local_98[uVar8 & 7] != 0)) &&
            (uVar10 = uVar8 + 1 & 7, local_98[uVar10] != 0)) &&
           ((iVar11 = local_50[uVar10] + local_50[uVar8 & 7] + *(int *)((int)local_50 + iVar5),
            uVar4 == 0xffffffff || (local_98[10] < iVar11)))) {
          uVar4 = uVar8 - 1;
          local_98[10] = iVar11;
        }
        iVar5 = iVar5 + 4;
        bVar3 = (int)uVar8 < 8;
        uVar8 = uVar8 + 1;
      } while (bVar3);
      if ((uVar4 == 0xffffffff) || (local_98[10] < 1)) {
        FUN_0047a9d0(param_1,piVar6,0);
      }
      else {
        piVar6[1] = uVar4;
        local_50[uVar4 & 7] = local_50[uVar4 & 7] + -6;
        uVar8 = uVar4 + 1 & 7;
        uVar4 = uVar4 + 2 & 7;
        local_50[uVar8] = local_50[uVar8] + -6;
        local_50[uVar4] = local_50[uVar4] + -6;
      }
      FUN_004016b0(local_6c,0);
      iVar5 = iVar9;
    }
    local_98[8] = local_98[8] + 1;
    if (2 < local_98[8]) {
      FUN_0047ec70(param_1);
      FUN_004805d0(param_1);
      local_4 = 0xffffffff;
      List_Node_Destroy(local_6c);
      ExceptionList = local_c;
      return local_a0;
    }
  } while( true );
}

