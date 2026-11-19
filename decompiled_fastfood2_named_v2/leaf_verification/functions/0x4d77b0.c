// rea decompile_all
// name: FUN_004d77b0
// address: 0x4d77b0
// body: available
// range: 0x4d77b0-0x4d7cfa inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall
FUN_004d77b0(void *this,void *param_1,undefined4 param_2,int param_3,void *param_4,int param_5)

{
  undefined4 *puVar1;
  void *pvVar2;
  void *this_00;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 local_c;
  
  this_00 = param_1;
  local_c = 0;
  iVar3 = IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)param_1 + 0x28),(int *)0x0);
  pvVar2 = *(void **)(iVar3 + 0xfa8);
  switch(param_2) {
  case 1:
    puVar1 = (undefined4 *)((int)param_1 + 4);
    param_1 = (void *)0xf;
    switch(*puVar1) {
    case 0xf:
      iVar4 = Building_GetSpriteVariant((int)this_00);
      iVar3 = *(int *)((int)this_00 + 0x48);
      *(undefined4 *)((int)this_00 + 0x38) = 2;
      if ((iVar3 < 0) || (3 < iVar3)) {
        iVar6 = iVar3;
      }
      else {
        iVar6 = *(int *)(&DAT_00568188 + iVar3 * 4);
      }
      param_5 = iVar6 + 0x810 + iVar4 * 4;
      if ((-1 < iVar3) && (iVar3 < 4)) {
        iVar3 = *(int *)(&DAT_00568188 + iVar3 * 4);
      }
      *(undefined4 *)((int)this_00 + 0x30) = 0xf;
      *(int *)((int)this_00 + 0x34) = iVar3 + 0x85c + iVar4 * 4;
      FUN_004dc720(this,this_00,param_3);
      break;
    default:
      iVar3 = *(int *)((int)this_00 + 0x48);
      param_1 = (void *)0x1a;
      if ((iVar3 < 0) || (3 < iVar3)) {
        iVar4 = iVar3;
      }
      else {
        iVar4 = *(int *)(&DAT_00568188 + iVar3 * 4);
      }
      if (param_5 == -1) {
        if ((-1 < iVar3) && (iVar3 < 4)) {
          iVar3 = *(int *)(&DAT_00568188 + iVar3 * 4);
        }
        param_5 = iVar3 + 0x858;
      }
      FUN_004d2f10(this_00);
      *(undefined4 *)((int)this_00 + 0x38) = 2;
      *(undefined4 *)((int)this_00 + 0x50) = 0;
      *(undefined4 *)((int)this_00 + 0x4c) = 0;
      *(undefined4 *)((int)this_00 + 0x30) = 0xf;
      *(int *)((int)this_00 + 0x34) = param_5;
      param_5 = iVar4 + 0x80c;
      goto LAB_004d78bf;
    case 0x14:
      iVar3 = *(int *)((int)this_00 + 0x48);
      if ((-1 < iVar3) && (iVar3 < 4)) {
        iVar3 = *(int *)(&DAT_00568188 + iVar3 * 4);
      }
      param_5 = iVar3 + 0x80c;
      local_c = 0;
      FUN_004dc720(this,this_00,param_3);
      break;
    case 0x15:
      iVar3 = *(int *)((int)this_00 + 0x48);
      if ((-1 < iVar3) && (iVar3 < 4)) {
        iVar3 = *(int *)(&DAT_00568188 + iVar3 * 4);
      }
      param_5 = iVar3 + 0x810;
      local_c = 1;
      FUN_004dc720(this,this_00,param_3);
      break;
    case 0x16:
      iVar3 = *(int *)((int)this_00 + 0x48);
      if ((-1 < iVar3) && (iVar3 < 4)) {
        iVar3 = *(int *)(&DAT_00568188 + iVar3 * 4);
      }
      param_5 = iVar3 + 0x814;
      local_c = 2;
      FUN_004dc720(this,this_00,param_3);
    }
    goto LAB_004d78d0;
  case 2:
    iVar3 = *(int *)((int)param_1 + 0x48);
    if ((-1 < iVar3) && (iVar3 < 4)) {
      iVar3 = *(int *)(&DAT_00568188 + iVar3 * 4);
    }
    iVar3 = iVar3 + 0x818;
    FUN_004d2f10(param_1);
    iVar4 = *(int *)((int)param_1 + 0x48);
    *(undefined4 *)((int)param_1 + 0x50) = 0;
    *(undefined4 *)((int)param_1 + 0x4c) = 0;
    *(undefined4 *)((int)param_1 + 0x38) = 5;
    if ((-1 < iVar4) && (iVar4 < 4)) {
      iVar4 = *(int *)(&DAT_00568188 + iVar4 * 4);
    }
    *(undefined4 *)((int)param_1 + 0x30) = 0x11;
    param_5 = iVar4 + 0x975;
    goto LAB_004d78bc;
  case 3:
    puVar1 = (undefined4 *)((int)param_1 + 4);
    param_1 = (void *)0x10;
    switch(*puVar1) {
    case 0x10:
      iVar4 = Building_GetSpriteVariant((int)this_00);
      iVar3 = *(int *)((int)this_00 + 0x48);
      *(undefined4 *)((int)this_00 + 0x38) = 3;
      if ((iVar3 < 0) || (3 < iVar3)) {
        iVar6 = iVar3;
      }
      else {
        iVar6 = *(int *)(&DAT_00568188 + iVar3 * 4);
      }
      param_5 = iVar6 + 0x804 + iVar4 * 4;
      if ((-1 < iVar3) && (iVar3 < 4)) {
        iVar3 = *(int *)(&DAT_00568188 + iVar3 * 4);
      }
      *(undefined4 *)((int)this_00 + 0x30) = 0x10;
      *(int *)((int)this_00 + 0x34) = iVar3 + 0x838 + iVar4 * 4;
      FUN_004dc720(this,this_00,param_3);
      break;
    default:
      iVar3 = *(int *)((int)this_00 + 0x48);
      param_1 = (void *)0x1a;
      if ((iVar3 < 0) || (3 < iVar3)) {
        iVar4 = iVar3;
      }
      else {
        iVar4 = *(int *)(&DAT_00568188 + iVar3 * 4);
      }
      if (param_5 == -1) {
        if ((-1 < iVar3) && (iVar3 < 4)) {
          iVar3 = *(int *)(&DAT_00568188 + iVar3 * 4);
        }
        param_5 = iVar3 + 0x834;
      }
      FUN_004d2f10(this_00);
      *(undefined4 *)((int)this_00 + 0x38) = 3;
      *(undefined4 *)((int)this_00 + 0x50) = 0;
      *(undefined4 *)((int)this_00 + 0x4c) = 0;
      *(undefined4 *)((int)this_00 + 0x30) = 0x10;
      *(int *)((int)this_00 + 0x34) = param_5;
      param_5 = iVar4 + 0x800;
      goto LAB_004d78bf;
    case 0x14:
      iVar3 = *(int *)((int)this_00 + 0x48);
      if ((-1 < iVar3) && (iVar3 < 4)) {
        iVar3 = *(int *)(&DAT_00568188 + iVar3 * 4);
      }
      param_5 = iVar3 + 0x800;
      local_c = 0;
      FUN_004dc720(this,this_00,param_3);
      break;
    case 0x15:
      iVar3 = *(int *)((int)this_00 + 0x48);
      if ((-1 < iVar3) && (iVar3 < 4)) {
        iVar3 = *(int *)(&DAT_00568188 + iVar3 * 4);
      }
      param_5 = iVar3 + 0x804;
      local_c = 1;
      FUN_004dc720(this,this_00,param_3);
      break;
    case 0x16:
      iVar3 = *(int *)((int)this_00 + 0x48);
      if ((-1 < iVar3) && (iVar3 < 4)) {
        iVar3 = *(int *)(&DAT_00568188 + iVar3 * 4);
      }
      param_5 = iVar3 + 0x808;
      local_c = 2;
      FUN_004dc720(this,this_00,param_3);
    }
    goto LAB_004d78d0;
  case 4:
    iVar3 = *(int *)((int)param_1 + 0x48);
    param_1 = (void *)0x1a;
    iVar4 = *(int *)((int)this + param_3 * 4 + 0xc20);
    if ((iVar3 < 0) || (3 < iVar3)) {
      iVar6 = iVar3;
    }
    else {
      iVar6 = *(int *)(&DAT_00568188 + iVar3 * 4);
    }
    if ((-1 < iVar3) && (iVar3 < 4)) {
      iVar3 = *(int *)(&DAT_00568188 + iVar3 * 4);
    }
    if (iVar4 == 0) {
      FUN_004d2f10(this_00);
    }
    *(undefined4 *)((int)this_00 + 0x38) = 4;
    *(undefined4 *)((int)this_00 + 0x50) = 0;
    *(undefined4 *)((int)this_00 + 0x4c) = 0;
    *(undefined4 *)((int)this_00 + 0x30) = 0x1c;
    *(int *)((int)this_00 + 0x34) = iVar3 + 0x81c + iVar4 * 4;
    param_5 = iVar6 + 0x7e4 + iVar4 * 4;
    goto LAB_004d78bf;
  case 5:
    iVar3 = *(int *)((int)param_1 + 0x48);
    if ((-1 < iVar3) && (iVar3 < 4)) {
      iVar3 = *(int *)(&DAT_00568188 + iVar3 * 4);
    }
    iVar3 = iVar3 + 0x7fc;
    FUN_004d2f10(param_1);
    uVar5 = FUN_004034d0(6,10);
    *(uint *)((int)param_1 + 0x38) = uVar5;
    *(void **)((int)param_1 + 0x30) = param_4;
LAB_004d78bc:
    param_1 = (void *)0x1a;
    *(int *)((int)this_00 + 0x34) = param_5;
    param_5 = iVar3;
    goto LAB_004d78bf;
  case 6:
    param_1 = param_4;
    iVar3 = IsSpecialIdRange((int)this_00);
    if (iVar3 == 0) {
      FUN_004d2f10(this_00);
    }
    if (param_4 == (void *)0x11) {
      *(undefined4 *)((int)this_00 + 0xc) = *(undefined4 *)((int)this + 0x10c4);
      Player_SetSlotFlag18(this,*(int *)((int)this + 0x10c4));
      FUN_004dae90(this,(int)this_00);
      *(int *)((int)this + 0x10c4) = *(int *)((int)this + 0x10c4) + 1;
      FUN_004dc720(this,this_00,param_3);
      goto LAB_004d78d0;
    }
    break;
  case 7:
    param_1 = param_4;
    iVar3 = *(int *)((int)this_00 + 0x48);
    if ((-1 < iVar3) && (iVar3 < 4)) {
      iVar3 = *(int *)(&DAT_00568188 + iVar3 * 4);
    }
    param_5 = iVar3 + 0x864;
    FUN_004d2f10(this_00);
    break;
  default:
  }
  if (param_1 == (void *)0x1a) {
LAB_004d78bf:
    FUN_004d3020(this_00,pvVar2,param_3);
  }
  else {
    FUN_004dc720(this,this_00,param_3);
  }
LAB_004d78d0:
  FUN_004d2420(this_00,(int)param_1,param_5);
  FUN_0048b600(DAT_0057c670);
  *(undefined4 *)((int)pvVar2 + 0xf4) = 1;
  return local_c;
}

