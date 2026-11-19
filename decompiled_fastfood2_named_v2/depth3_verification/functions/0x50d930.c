// rea decompile_all
// name: FUN_0050d930
// address: 0x50d930
// body: available
// range: 0x50d930-0x50dbcf inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_0050d930(void *this,float param_1,uint param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  void *pvVar5;
  int iVar6;
  
  fVar1 = param_1;
  if ((param_1 != 0.0) && (*(int *)((int)param_1 + 0x30) == 0x17)) {
    iVar2 = FUN_00488be0(DAT_0057c670,*(int *)((int)param_1 + 0x110));
    if (iVar2 != 0) {
      iVar3 = FUN_004ddcc0(iVar2);
      *(int *)(iVar3 + 0x38) = *(int *)(iVar3 + 0x38) + 1;
      FUN_004fcc30(*(void **)((int)DAT_0057c670 + 0x90),*(int *)(iVar2 + 0x4c),-5);
    }
  }
  if ((*(int *)((int)this + 0x110) != -1) &&
     ((*(int *)((int)this + 0x30) == 0x1d || (*(int *)((int)this + 0x30) == 0x1e)))) {
    iVar2 = FUN_00488be0(DAT_0057c670,*(int *)((int)this + 0x110));
    if (iVar2 != 0) {
      *(int *)(iVar2 + 0x80) = *(int *)(iVar2 + 0x80) + 1;
    }
    iVar2 = FUN_00488be0(DAT_0057c670,*(int *)((int)param_1 + 0x110));
    if (iVar2 != 0) {
      *(int *)(iVar2 + 0x8c) = *(int *)(iVar2 + 0x8c) + 1;
    }
  }
  iVar2 = FUN_004017f0((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                       (int *)0x0);
  *(int *)(iVar2 + 0x10ac) = *(int *)(iVar2 + 0x10ac) + 1;
  if (param_2 == 0) {
    FUN_00509220((int)this);
    FUN_005086e0((int)this);
    if (*(int *)((int)this + 200) == 0) {
      param_1 = 0.0;
      uVar4 = UI_HitTestChildPoint(this,fVar1);
    }
    else {
      fVar1 = *(float *)(*(int *)((int)this + 200) + 0x20);
      uVar4 = UI_HitTestChildPoint(this,param_1);
      param_1 = fVar1;
    }
  }
  else {
    uVar4 = param_2;
  }
  if (*(int *)((int)this + 0x30) != 0xd) {
    pvVar5 = (void *)FUN_00488be0(DAT_0057c670,*(int *)((int)this + 0x110));
    FUN_004e21d0(pvVar5,*(int *)((int)this + 0x164));
  }
  if (param_2 == 0) {
    iVar2 = FUN_00489820(DAT_0057c670,*(int *)(*(int *)((int)this + 0xf4) + 8),
                         *(int *)(*(int *)((int)this + 0xf4) + 0x2c));
    UI_DestroyChildObject((int)this);
    FUN_0050e890(this,0x2d);
    FUN_00504e90(this,1,-1,-1);
    Sound_ProcessEventForSelectedObject(DAT_0057ba0c,iVar2,*(int *)((int)this + 0x30),9,'\x01');
    if ((*(int *)((int)this + 0x30) == 0x1d) || (*(int *)((int)this + 0x30) == 0x1e)) {
      FUN_00548210(DAT_0057ba0c,iVar2,0x2e);
    }
    else {
      FUN_00548210(DAT_0057ba0c,iVar2,0x1f);
    }
  }
  else {
    FUN_0050e890(this,0x2e);
    *(undefined4 *)((int)DAT_0057c670 + 0x368) = 1;
    FUN_004d2960(*(void **)((int)this + 0xfc),this,0);
  }
  if (*(int *)((int)this + 0x30) == 0xd) {
    pvVar5 = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 4),
                                  *(int *)((int)DAT_0057c670 + 0x2f4),(int *)0x0);
    iVar2 = *(int *)((int)this + 0x58);
    iVar3 = *(int *)((int)pvVar5 + iVar2 * 0x18 + 0x10d8);
    iVar6 = *(int *)((int)pvVar5 + iVar2 * 0x18 + 0x10dc) + 1;
    *(int *)((int)pvVar5 + iVar2 * 0x18 + 0x10dc) = iVar6;
    if (iVar6 == iVar3) {
      iVar2 = *(int *)((int)this + 0x58);
      iVar3 = 1;
    }
    else {
      if (*(int *)((int)pvVar5 + iVar2 * 0x18 + 0x10e0) + iVar6 != iVar3) goto LAB_0050db64;
      iVar2 = *(int *)((int)this + 0x58);
      iVar3 = 2;
    }
    FUN_004dc330(pvVar5,iVar3,iVar2);
  }
LAB_0050db64:
  if (param_2 == 0) {
    FUN_00505e60(this,1,(int)param_1);
    FUN_0050d8f0((int)this);
    FUN_00509060(this,uVar4);
  }
  if ((this == *(void **)((int)DAT_0057c670 + 0x21c)) &&
     (*(void **)((int)DAT_0057c670 + 0x25c) != (void *)0x0)) {
    FUN_005301c0(*(void **)((int)DAT_0057c670 + 0x25c),-0x18629,0x23,0);
    pvVar5 = DAT_0057c670;
    *(undefined4 *)((int)DAT_0057c670 + 0x21c) = 0;
    *(undefined4 *)((int)pvVar5 + 0x2da8) = 1;
  }
  return;
}

