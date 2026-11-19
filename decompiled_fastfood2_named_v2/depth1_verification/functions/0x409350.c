// rea decompile_all
// name: FUN_00409350
// address: 0x409350
// body: available
// range: 0x409350-0x4096f1 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00409350(void *param_1,void *param_2)

{
  void *this;
  undefined1 uVar1;
  char cVar2;
  undefined3 extraout_var;
  int iVar3;
  void *pvVar4;
  undefined1 unaff_SI;
  undefined4 unaff_EDI;
  undefined4 local_24;
  undefined4 local_20 [8];
  
  this = param_2;
  local_20[0] = 0x10;
  local_20[1] = 0x12;
  local_20[2] = 0x14;
  local_20[3] = 0x16;
  local_20[4] = 0x11;
  local_20[5] = 0x13;
  local_20[6] = 0x15;
  local_20[7] = 0x17;
  uVar1 = FUN_00505e00((int)param_2);
  iVar3 = *(int *)((int)this + 0x38);
  if (iVar3 == 0x1f) {
    return;
  }
  if (CONCAT31(extraout_var,uVar1) == 0) {
    switch(iVar3) {
    case 8:
      if (*(int *)((int)this + 0xa4) == 10) {
        iVar3 = *(int *)((int)this + 0x88);
        FUN_0050e890(this,0x1b);
        FUN_0050d200(this,0x14);
        FUN_00509060(this,iVar3);
        FUN_00548210(DAT_0057ba0c,(int)param_1,0x21);
        return;
      }
      if (*(int *)((int)this + 0xa4) == 0xb) {
        FUN_0050e890(this,0x18);
        return;
      }
      break;
    case 0x18:
      iVar3 = FUN_004f5310(*(void **)((int)this + 0xc4),(int)this,param_1,&local_24,&param_2);
      if (iVar3 != 0) {
        *(undefined4 *)((int)this + 0x88) = local_20[(int)param_2];
        *(undefined4 *)((int)this + 0x8c) = local_24;
        FUN_00507d90(this,iVar3);
        FUN_0050e890(this,8);
        Object_SetFieldA4Locked(this,10);
        return;
      }
      iVar3 = AI_ComputePath(0,0,0,unaff_EDI,unaff_SI);
      if (iVar3 != 0) {
        FUN_00507d90(this,iVar3);
        FUN_0050e890(this,8);
        Object_SetFieldA4Locked(this,0xb);
        return;
      }
      break;
    case 0x23:
    case 0x24:
      iVar3 = FUN_0050b370((int)this);
      if (iVar3 == 0) {
        FUN_005091c0((int)this);
        FUN_0050e890(this,0x18);
        return;
      }
      iVar3 = *(int *)((int)this + 0xa8) + -0x14;
      *(int *)((int)this + 0xa8) = iVar3;
      goto joined_r0x0040953e;
    }
  }
  else {
    if (iVar3 == 0x1b) {
      iVar3 = *(int *)((int)this + 0x94) + -1;
      *(int *)((int)this + 0x94) = iVar3;
      if (iVar3 == 0) {
        pvVar4 = (void *)Game_FindRecordByField20(param_1,*(int *)((int)this + 0x8c));
        if (pvVar4 != (void *)0x0) {
          iVar3 = *(int *)((int)pvVar4 + 0xc);
          if (iVar3 < 6) {
            FUN_004e6300(pvVar4,0);
            FUN_00480d80(param_1,(int)pvVar4);
            cVar2 = Game_GetPlayerByte8((int)pvVar4);
            if (cVar2 == '\x01') {
              iVar3 = 0x1d;
            }
            else {
              iVar3 = 0x1e;
            }
            FUN_00548210(DAT_0057ba0c,(int)param_1,iVar3);
            FUN_004e6170(pvVar4,param_1);
          }
          else {
            FUN_004e6300(pvVar4,CONCAT31((int3)((uint)iVar3 >> 8),(char)iVar3 + -5));
          }
        }
      }
      else {
        pvVar4 = (void *)Game_FindRecordByField20(param_1,*(int *)((int)this + 0x8c));
        if ((pvVar4 != (void *)0x0) && (iVar3 = *(int *)((int)pvVar4 + 0xc), 0 < iVar3)) {
          if (iVar3 < 6) {
            FUN_004e6300(pvVar4,0);
            FUN_00480d80(param_1,(int)pvVar4);
            FUN_004e6170(pvVar4,param_1);
            return;
          }
          FUN_004e6300(pvVar4,CONCAT31((int3)((uint)iVar3 >> 8),(char)iVar3 + -5));
          return;
        }
      }
      FUN_0050d200(this,-1);
      UI_DetachChildRecord((int)this);
      FUN_0050e890(this,0x18);
      return;
    }
    if (iVar3 == 0x23) {
      iVar3 = FUN_0050b370((int)this);
      if (iVar3 == 0) {
        return;
      }
      iVar3 = FUN_0050e7a0((int)this);
      if (iVar3 == 0) {
        UI_DetachChildRecord((int)this);
      }
      iVar3 = *(int *)((int)this + 0xa8) + -0x14;
      *(int *)((int)this + 0xa8) = iVar3;
      if (iVar3 < 0) {
        *(undefined4 *)((int)this + 0xa8) = 0;
      }
      UI_SetChildHeightFromValue((int)this);
      if (*(int *)((int)this + 0xa8) == 0) {
        UI_ShiftChildRect((int)this);
        FUN_0050e890(this,0x1f);
        return;
      }
      FUN_00509170((int)this);
      iVar3 = AI_ComputePath(0,0,0,unaff_EDI,unaff_SI);
      if (iVar3 == 0) {
        return;
      }
      FUN_00507d90(this,iVar3);
      FUN_0050e890(this,0x24);
      return;
    }
    if (iVar3 != 0x24) {
      return;
    }
    iVar3 = FUN_0050b370((int)this);
    if (iVar3 == 0) {
      return;
    }
    iVar3 = *(int *)((int)this + 0xa8) + -0x14;
    *(int *)((int)this + 0xa8) = iVar3;
joined_r0x0040953e:
    if (iVar3 < 0) {
      *(undefined4 *)((int)this + 0xa8) = 0;
    }
    UI_SetChildHeightFromValue((int)this);
    if (*(int *)((int)this + 0xa8) == 0) {
      UI_ShiftChildRect((int)this);
      FUN_0050e890(this,0x1f);
      return;
    }
  }
  return;
}

