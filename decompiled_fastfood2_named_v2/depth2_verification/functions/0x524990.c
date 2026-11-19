// rea decompile_all
// name: FUN_00524990
// address: 0x524990
// body: available
// range: 0x524990-0x524e67 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00524990(void *this,int param_1,int param_2,int param_3,uint param_4)

{
  void *pvVar1;
  undefined4 uVar2;
  DWORD DVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  iVar4 = param_1;
  _DAT_00584200 = param_2 - *(int *)((int)this + 0x248);
  _DAT_00584204 = param_3 - *(int *)((int)this + 0x24c);
  _DAT_005841f8 = param_2;
  *(int *)((int)this + 0x248) = param_2;
  _DAT_005841fc = param_3;
  *(int *)((int)this + 0x24c) = param_3;
  _DAT_00584208 = param_4;
  _DAT_0058420c = 0;
  switch(param_1) {
  case 0x200:
    puVar7 = (undefined4 *)0x4;
    if (*(int *)((int)this + 0x831c) != 0) {
      _DAT_00584220 = param_2;
      _DAT_00584224 = param_3;
      FUN_00525bc0(this,*(int *)((int)this + 0x8304),0,(int)this,0x12,0x584220);
    }
    if (*(int *)((int)this + 0x82dc) != 0) {
      DVar3 = timeGetTime();
      *(DWORD *)((int)this + 0x82e0) = DVar3 + *(int *)((int)this + 0x82f4);
      iVar5 = FUN_00530060(*(void **)((int)this + 0x82d0),(int *)&DAT_005841f8,
                           *(void **)((int)this + 0x82dc));
      if (iVar5 == 0) {
        if ((*(int *)((int)this + 0x82d0) != 0) &&
           (iVar5 = FUN_00520e00(*(int *)((int)this + 0x82dc)), iVar5 != 0)) {
          UI_QueueControlCommand
                    (*(void **)((int)this + 0x82d0),*(int *)(*(int *)((int)this + 0x82dc) + 4),0xd,0
                    );
        }
        *(undefined4 *)((int)this + 0x82dc) = 0;
        FUN_00527380(this);
      }
    }
    break;
  case 0x201:
    puVar7 = (undefined4 *)0x6;
    break;
  case 0x202:
    puVar7 = (undefined4 *)0x7;
    break;
  default:
    goto switchD_005249fc_caseD_203;
  case 0x204:
    puVar7 = (undefined4 *)0x8;
    if (((param_4 & 4) != 0) && (iVar5 = FUN_00539f00(*(int *)((int)this + 0xc)), iVar5 != 0)) {
      FUN_00524e80(this,(void *)0x0,(void **)0x0,(int *)&DAT_005841f8);
    }
    break;
  case 0x205:
    puVar7 = (undefined4 *)0x9;
  }
  if (iVar4 != 0x200) {
    FUN_00527380(this);
  }
  if ((*(int *)((int)this + 0x240) != 0) && (*(int *)(*(int *)((int)this + 0x240) + 0x44) != 0)) {
    if ((*(int **)((int)this + 0x82d4) != (int *)0x0) && (*(int *)((int)this + 0x82c8) != 0)) {
      (**(code **)(**(int **)((int)this + 0x82d4) + 0xc))(5,0,&DAT_005841f8);
      *(undefined4 *)((int)this + 0x82d4) = 0;
    }
    if (puVar7 == (undefined4 *)0x4) {
      iVar4 = FUN_00528820(*(void **)((int)this + 0x240),(int *)&DAT_005841f8);
      if (iVar4 == 0) {
        return;
      }
      FUN_005243c0(this);
      return;
    }
    if ((puVar7 == (undefined4 *)0x7) || (puVar7 == (undefined4 *)0x9)) {
      FUN_005288f0(*(void **)((int)this + 0x240),this);
      FUN_00528760(*(int *)((int)this + 0x240));
      FUN_005243c0(this);
      return;
    }
    return;
  }
  if (*(int *)((int)this + 0x22c) != 0) {
    iVar4 = *(int *)((int)this + 0x23c) + -1;
    if (-1 < iVar4) {
      puVar6 = (undefined4 *)((int)this + iVar4 * 4 + 0x14);
      do {
        pvVar1 = (void *)*puVar6;
        if (pvVar1 == *(void **)((int)this + 0x224)) {
          iVar4 = -1;
          break;
        }
        if ((((pvVar1 != (void *)0x0) && (*(int *)((int)pvVar1 + 0x4c) != 0)) &&
            (iVar5 = FUN_0052ffa0(pvVar1,(int *)&DAT_005841f8), iVar5 != 0)) &&
           (FUN_005300e0((void *)*puVar6,(int *)&DAT_005841f8,&param_1), param_1 != 0)) break;
        iVar4 = iVar4 + -1;
        puVar6 = puVar6 + -1;
      } while (-1 < iVar4);
    }
    _DAT_0058420c = 1;
    if (iVar4 == -1) {
      iVar4 = FUN_0052ffe0(*(void **)((int)this + 0x224),(int *)&DAT_005841f8,
                           *(void **)((int)this + 0x22c));
      if (iVar4 == 0) {
        if (puVar7 != (undefined4 *)0x4) {
          iVar4 = (**(code **)(**(int **)((int)this + 0x22c) + 0xc))(puVar7,0,&DAT_005841f8);
          goto LAB_00524c8e;
        }
        iVar4 = **(int **)((int)this + 0x22c);
        puVar6 = (undefined4 *)0x5;
      }
      else {
LAB_00524c7b:
        iVar4 = **(int **)((int)this + 0x22c);
        puVar6 = puVar7;
      }
      iVar4 = (**(code **)(iVar4 + 0xc))(puVar6,0,&DAT_005841f8);
    }
    else {
      if (puVar7 != (undefined4 *)0x4) goto LAB_00524c7b;
      iVar4 = (**(code **)(**(int **)((int)this + 0x22c) + 0xc))(5,0,&DAT_005841f8);
    }
LAB_00524c8e:
    if (iVar4 != 0) {
      return;
    }
    *(undefined4 *)((int)this + 0x224) = 0;
    *(undefined4 *)((int)this + 0x22c) = 0;
    if (puVar7 == (undefined4 *)0x7) {
      return;
    }
    param_4 = 0;
    if (puVar7 == (undefined4 *)0x9) {
      return;
    }
  }
  if (puVar7 == (undefined4 *)0x4) {
    iVar4 = *(int *)((int)this + 0x23c) + -1;
    if (-1 < iVar4) {
      puVar6 = (undefined4 *)((int)this + iVar4 * 4 + 0x14);
      do {
        pvVar1 = (void *)*puVar6;
        if (pvVar1 != (void *)0x0) {
          if (pvVar1 == *(void **)((int)this + 0x82c8)) goto LAB_00524cf9;
          iVar5 = FUN_0052ffa0(pvVar1,(int *)&DAT_005841f8);
          if (iVar5 != 0) break;
        }
        iVar4 = iVar4 + -1;
        puVar6 = puVar6 + -1;
      } while (-1 < iVar4);
    }
    if (iVar4 == -1) {
LAB_00524cf9:
      if ((*(void **)((int)this + 0x82d4) != (void *)0x0) &&
         (*(void **)((int)this + 0x82c8) != (void *)0x0)) {
        iVar4 = FUN_0052ffe0(*(void **)((int)this + 0x82c8),(int *)&DAT_005841f8,
                             *(void **)((int)this + 0x82d4));
        if (iVar4 != 0) {
          return;
        }
        (**(code **)(**(int **)((int)this + 0x82d4) + 0xc))(5,0,&DAT_005841f8);
LAB_00524d57:
        *(undefined4 *)((int)this + 0x82d4) = 0;
      }
    }
    else if ((*(int **)((int)this + 0x82d4) != (int *)0x0) && (*(int *)((int)this + 0x82c8) != 0)) {
      (**(code **)(**(int **)((int)this + 0x82d4) + 0xc))(5,0,&DAT_005841f8);
      goto LAB_00524d57;
    }
  }
  iVar4 = *(int *)((int)this + 0x23c) + -1;
  if (-1 < iVar4) {
    puVar6 = (undefined4 *)((int)this + iVar4 * 4 + 0x14);
    do {
      if (((void *)*puVar6 != (void *)0x0) &&
         (iVar5 = FUN_00525080(this,puVar7,(int *)&DAT_005841f8,(void *)*puVar6,&param_4),
         iVar5 != 0)) {
        if (*(int *)((int)this + 0x82d4) != 0) {
          uVar2 = *(undefined4 *)((int)this + iVar4 * 4 + 0x14);
          *(undefined4 *)((int)this + 0x82c8) = uVar2;
          if (param_4 == 0) {
            *(undefined4 *)((int)this + 0x224) = 0;
            *(undefined4 *)((int)this + 0x22c) = 0;
          }
          else {
            *(undefined4 *)((int)this + 0x224) = uVar2;
            *(int *)((int)this + 0x22c) = *(int *)((int)this + 0x82d4);
          }
        }
        break;
      }
      iVar4 = iVar4 + -1;
      puVar6 = puVar6 + -1;
    } while (-1 < iVar4);
  }
  if (*(int *)((int)this + 0x8304) != 0) {
    _DAT_00584220 = param_2;
    _DAT_00584224 = param_3;
    if (puVar7 == (undefined4 *)0x6) {
      iVar4 = 0xf;
    }
    else {
      if (puVar7 == (undefined4 *)0x7) {
        FUN_00525bc0(this,*(int *)((int)this + 0x8304),0,(int)this,0x10,0x584220);
        return;
      }
      if (puVar7 == (undefined4 *)0x8) {
        FUN_00525bc0(this,*(int *)((int)this + 0x8304),0,(int)this,0x14,0x584220);
        return;
      }
      if (puVar7 != (undefined4 *)0x9) {
        return;
      }
      iVar4 = 0x15;
    }
    FUN_00525bc0(this,*(int *)((int)this + 0x8304),0,(int)this,iVar4,0x584220);
  }
switchD_005249fc_caseD_203:
  return;
}

