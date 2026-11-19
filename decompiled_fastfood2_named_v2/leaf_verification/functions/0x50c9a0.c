// rea decompile_all
// name: FUN_0050c9a0
// address: 0x50c9a0
// body: available
// range: 0x50c9a0-0x50cd87 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x01040404) */

int __thiscall FUN_0050c9a0(void *this,void *param_1)

{
  bool bVar1;
  char cVar2;
  void *this_00;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  void *pvVar3;
  int iVar4;
  undefined3 extraout_var_03;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int local_10;
  undefined4 local_c;
  void *local_8;
  int local_4;
  
  local_8 = *(void **)((int)param_1 + 0x16f0);
  iVar7 = -1;
  if (local_8 != (void *)0x0) {
    local_4 = *(int *)((int)this + 0x84);
    local_10 = 0;
    pvVar3 = param_1;
    if (0 < *(int *)((int)local_8 + 0x8c)) {
      do {
        this_00 = (void *)FUN_004d2a60(local_8,local_10);
        if (((((this_00 != this) && (iVar4 = *(int *)((int)this_00 + 0xa4), iVar4 != 0x19)) &&
             (iVar4 != 0x1a)) && ((iVar4 != -1 || (*(int *)((int)this_00 + 0x30) == 0x1d)))) &&
           ((*(int *)((int)this_00 + 0x38) != 0x2d && (*(int *)((int)this_00 + 0x38) != 0x2e)))) {
          switch(*(undefined4 *)((int)this_00 + 0x30)) {
          case 0x16:
            bVar1 = FUN_0050c540(this_00,param_1,this);
            if (CONCAT31(extraout_var,bVar1) != 0) {
              if (*(int *)((int)this_00 + 0xa4) == 1) {
                if (iVar7 < 1) {
                  pvVar3 = *(void **)((int)this_00 + 0x164);
                  iVar7 = 1;
                }
              }
              else if (iVar7 < 2) {
                pvVar3 = *(void **)((int)this_00 + 0x164);
                iVar7 = 2;
              }
            }
            break;
          case 0x1d:
            bVar1 = FUN_0050c540(this_00,param_1,this);
            if (CONCAT31(extraout_var_02,bVar1) != 0) {
              if (*(int *)((int)this_00 + 0xa4) == 0xe) {
                if (iVar7 < 5) {
                  pvVar3 = *(void **)((int)this_00 + 0x164);
                  iVar7 = 5;
                }
              }
              else if (iVar7 < 6) {
                pvVar3 = *(void **)((int)this_00 + 0x164);
                iVar7 = 6;
              }
            }
            break;
          case 0x1e:
            bVar1 = FUN_0050c540(this_00,param_1,this);
            if ((CONCAT31(extraout_var_01,bVar1) != 0) && (iVar7 < 4)) {
              pvVar3 = *(void **)((int)this_00 + 0x164);
              iVar7 = 4;
            }
            break;
          case 0x1f:
            bVar1 = FUN_0050c540(this_00,param_1,this);
            if ((CONCAT31(extraout_var_00,bVar1) != 0) && (iVar7 < 3)) {
              pvVar3 = *(void **)((int)this_00 + 0x164);
              iVar7 = 3;
            }
          }
        }
        local_10 = local_10 + 1;
      } while (local_10 < *(int *)((int)local_8 + 0x8c));
    }
    if (local_4 < iVar7) {
      *(void **)((int)this + 0x8c) = pvVar3;
      *(int *)((int)this + 0x84) = iVar7;
      switch(iVar7) {
      case 1:
      case 2:
      case 3:
      case 4:
        iVar4 = FUN_0050bf50(this,param_1,(int)pvVar3,&local_c);
        iVar6 = FUN_00509bf0((int)this);
        if (iVar6 != iVar4) {
          *(undefined4 *)((int)this + 0x88) = local_c;
          FUN_0050e890(this,0x28);
          FUN_00507d90(this,iVar4);
          return iVar7;
        }
        break;
      case 5:
      case 6:
        pvVar3 = (void *)IDMap_Lookup((void *)((int)DAT_0057c670 + 0x3c),(int)pvVar3,(int *)0x0);
        FUN_0050e890(this,0x2c);
        *(undefined4 *)((int)pvVar3 + 0x8c) = *(undefined4 *)((int)this + 0x164);
        FUN_0050e890(pvVar3,0x2c);
        FUN_00480200(param_1,0x1e);
        if (*(int *)((int)pvVar3 + 0x110) != -1) {
          iVar7 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((int)pvVar3 + 0x110));
          *(int *)(iVar7 + 0x78) = *(int *)(iVar7 + 0x78) + 1;
          return -1;
        }
      }
    }
    else if (local_4 != -1) {
      iVar7 = IDMap_Lookup((void *)((int)DAT_0057c670 + 0x3c),*(int *)((int)this + 0x8c),(int *)0x0)
      ;
      if ((iVar7 != 0) && (*(int *)(iVar7 + 200) != 0)) {
        iVar4 = State_Is2DOr2E(iVar7);
        iVar7 = local_4;
        if (iVar4 == 0) {
          if (0 < local_4) {
            if (local_4 < 4) {
              iVar4 = FUN_0050c0f0(this,param_1,*(int *)((int)this + 0x8c));
              if (iVar4 != 0) {
LAB_0050ccfd:
                if (*(int *)((int)this + 200) == 0) {
                  uVar5 = 0xffffffff;
                }
                else {
                  uVar5 = *(undefined4 *)(*(int *)((int)this + 200) + 0xc);
                }
                *(undefined4 *)((int)this + 0x88) = uVar5;
                FUN_00507a80((int)this);
                *(undefined4 *)((int)this + 0x84) = 0xffffffff;
                FUN_0050e890(this,8);
                return -1;
              }
              iVar4 = FUN_0050bf50(this,param_1,*(int *)((int)this + 0x8c),&local_c);
              iVar6 = FUN_00509bf0((int)this);
              if (iVar6 != iVar4) {
                FUN_00507d90(this,iVar4);
                return iVar7;
              }
            }
            else if (local_4 == 4) {
              cVar2 = FUN_0050c2e0(this,param_1,*(int *)((int)this + 0x8c));
              iVar7 = CONCAT31(extraout_var_03,cVar2);
              if (iVar7 == 0) {
                iVar7 = FUN_0050bf50(this,param_1,*(int *)((int)this + 0x8c),&local_c);
                iVar4 = FUN_00509bf0((int)this);
                if (iVar4 != iVar7) {
                  FUN_00507d90(this,iVar7);
                  return 4;
                }
              }
              else {
                if (iVar7 == 1) goto LAB_0050ccfd;
                if (iVar7 == 2) {
                  FUN_00507a80((int)this);
                  FUN_0050e890(this,0x2c);
                }
              }
            }
          }
          goto switchD_0050cb6f_default;
        }
      }
      *(undefined4 *)((int)this + 0x84) = 0xffffffff;
      return -1;
    }
  }
switchD_0050cb6f_default:
  return -1;
}

