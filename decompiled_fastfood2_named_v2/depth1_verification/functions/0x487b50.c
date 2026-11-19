// rea decompile_all
// name: FUN_00487b50
// address: 0x487b50
// body: available
// range: 0x487b50-0x4880bb inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00487b50(void *this,int *param_1)

{
  int *this_00;
  void *pvVar1;
  int iVar2;
  int *piVar3;
  int local_34 [5];
  int local_20 [4];
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  this_00 = param_1;
  local_34[2] = 0x2e;
  local_34[3] = 0x2a;
  local_34[4] = FUN_0054d272(param_1);
  piVar3 = local_20;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar3 = 0;
    piVar3 = piVar3 + 1;
  }
  FUN_0054cc2b(this_00,local_20,0x20);
  FUN_0054cc2b(this_00,local_34 + 2,4);
  FUN_0054cc2b(this_00,&DAT_0057bb20,0x5b8);
  FUN_0054cc2b(this_00,(int)this + 0x298,0x20);
  FUN_0054cc2b(this_00,(int)this + 0x2b8,0x20);
  FUN_0054cc2b(this_00,(int)this + 0x2d8,4);
  FUN_0054cc2b(this_00,(int)this + 0x2dc,4);
  FUN_0054cc2b(this_00,(int)this + 0x2ec,4);
  FUN_0054cc2b(this_00,(int)this + 0x2f0,4);
  FUN_0054cc2b(this_00,(int)this + 0x2f4,4);
  FUN_0054cc2b(this_00,(int)this + 0x2e8,4);
  FUN_0054cc2b(this_00,(int)this + 0x2f8,4);
  FUN_0054cc2b(this_00,(int)this + 0x33c,4);
  FUN_0054cc2b(this_00,(int)this + 0x348,4);
  FUN_0054cc2b(this_00,(int)this + 0x34c,4);
  FUN_0054cc2b(this_00,(int)this + 0x350,4);
  FUN_0054cc2b(this_00,(int)this + 0x344,4);
  FUN_0054cc2b(this_00,(int)this + 0x354,4);
  FUN_0054cc2b(this_00,(int)this + 0x340,4);
  FUN_0054cc2b(this_00,(int)this + 0x364,4);
  FUN_0054cc2b(this_00,(int)this + 0x368,4);
  FUN_0054cc2b(this_00,(int)this + 0x360,4);
  FUN_0054cc2b(this_00,(int)this + 0x358,4);
  FUN_0054cc2b(this_00,(int)this + 0x35c,4);
  FUN_0054cc2b(this_00,(int)this + 0x2d90,4);
  FUN_00499590(this_00);
  FUN_00498130(this_00);
  FUN_0049ad00(this_00);
  FUN_0049b490(this_00);
  FUN_004b3ce0(this_00);
  FUN_004aa700(this_00);
  FUN_004ac400(this_00);
  FUN_004b0d60(this_00);
  FUN_004919d0(this_00);
  FUN_00492250(this_00);
  FUN_004900c0(this_00);
  FUN_004c0d60(this_00);
  FUN_004dd4f0(*(void **)((int)this + 0x94),this_00);
  FUN_0054b1b0((void *)((int)this + 0x304),this_00);
  FUN_004eaaa0(DAT_0057c5cc,this_00);
  param_1 = *(int **)((int)DAT_0057c5cc + 0x2c40c);
  FUN_0054cc2b(this_00,&param_1,4);
  iVar2 = 0;
  if (0 < (int)param_1) {
    do {
      pvVar1 = (void *)FUN_004017f0((void *)((int)DAT_0057c5cc + 0x2c3f8),iVar2,(int *)0x0);
      local_34[0] = Game_RemoveIDMapEntry(DAT_0057c5cc,(int)pvVar1);
      FUN_0054cc2b(this_00,local_34,4);
      FUN_004ec4f0(pvVar1,this_00,1);
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)param_1);
  }
  local_20[1] = FUN_0054d272(this_00);
  param_1 = *(int **)((int)this + 0x34);
  FUN_0054cc2b(this_00,&param_1,4);
  iVar2 = 0;
  if (0 < (int)param_1) {
    do {
      pvVar1 = (void *)FUN_004017f0((void *)((int)this + 0x20),iVar2,local_34);
      FUN_0054cc2b(this_00,local_34,4);
      FUN_004d3ba0(pvVar1,this_00);
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)param_1);
  }
  local_20[2] = FUN_0054d272(this_00);
  param_1 = *(int **)((int)this + 0x18);
  FUN_0054cc2b(this_00,&param_1,4);
  iVar2 = 0;
  if (0 < (int)param_1) {
    do {
      piVar3 = this_00;
      pvVar1 = (void *)FUN_004017f0((void *)((int)this + 4),iVar2,(int *)0x0);
      FUN_004d7090(pvVar1,piVar3);
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)param_1);
  }
  local_20[0] = FUN_0054d272(this_00);
  param_1 = *(int **)((int)this + 0x50);
  FUN_0054cc2b(this_00,&param_1,4);
  iVar2 = 0;
  if (0 < (int)param_1) {
    do {
      pvVar1 = (void *)FUN_004017f0((void *)((int)this + 0x3c),iVar2,local_34);
      FUN_0054cc2b(this_00,local_34,4);
      FUN_005053d0(pvVar1,this_00);
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)param_1);
  }
  local_8 = FUN_0054d272(this_00);
  param_1 = *(int **)((int)this + 0x6c);
  FUN_0054cc2b(this_00,&param_1,4);
  iVar2 = 0;
  if (0 < (int)param_1) {
    do {
      pvVar1 = (void *)FUN_004017f0((void *)((int)this + 0x58),iVar2,local_34);
      FUN_0054cc2b(this_00,local_34,4);
      FUN_004d3490(pvVar1,this_00);
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)param_1);
  }
  local_10 = FUN_0054d272(this_00);
  piVar3 = (int *)((int)this + 0x224);
  iVar2 = 6;
  do {
    if (*piVar3 == 0) {
      local_34[0] = 0;
      FUN_0054cc2b(this_00,local_34,4);
    }
    else {
      local_34[0] = 1;
      FUN_0054cc2b(this_00,local_34,4);
      FUN_0050ea90((void *)*piVar3,this_00);
    }
    piVar3 = piVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  local_20[3] = FUN_0054d272(this_00);
  piVar3 = (int *)((int)this + 0x200);
  iVar2 = 6;
  do {
    if (*piVar3 == 0) {
      local_34[1] = 0;
      FUN_0054cc2b(this_00,local_34 + 1,4);
    }
    else {
      local_34[1] = 1;
      FUN_0054cc2b(this_00,local_34 + 1,4);
      FUN_004e1540((void *)*piVar3,this_00);
    }
    piVar3 = piVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  local_c = FUN_0054d272(this_00);
  FUN_004f6e20(*(void **)((int)this + 0x90),this_00);
  if (*(int *)((int)this + 0x9c) == 0) {
    local_34[0] = 0;
  }
  else {
    local_34[0] = 1;
    FUN_0054cc2b(this_00,local_34,4);
    local_34[0] = *(int *)(*(int *)((int)this + 0x9c) + 0x30);
    FUN_0054cc2b(this_00,local_34,4);
    local_34[0] = *(int *)(*(int *)((int)this + 0x9c) + 0x3c);
  }
  FUN_0054cc2b(this_00,local_34,4);
  FUN_00487940(this,this_00);
  FUN_0054cc2b(this_00,local_34 + 3,4);
  iVar2 = FUN_0054d272(this_00);
  local_4 = iVar2;
  FUN_0054d20a(this_00,local_34[4]);
  FUN_0054cc2b(this_00,local_20,0x20);
  FUN_0054d20a(this_00,iVar2);
  return;
}

