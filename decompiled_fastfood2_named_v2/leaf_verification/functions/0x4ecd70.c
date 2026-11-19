// rea decompile_all
// name: FUN_004ecd70
// address: 0x4ecd70
// body: available
// range: 0x4ecd70-0x4ed005 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_004ecd70(void *param_1,uint *param_2)

{
  void *this;
  uint *this_00;
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  undefined4 uVar5;
  int local_18;
  uint local_14;
  int local_10;
  void *local_c;
  int local_8;
  undefined2 local_4 [2];
  
  this = param_1;
  FUN_0054cbc1(param_1,&param_1,1);
  FUN_0054cbc1(this,&local_18,4);
  FUN_0054cbc1(this,&local_10,4);
  this_00 = param_2;
  Record_SetDoubles48((void *)param_2[0x16],*param_2,local_18,local_10);
  FUN_0054cbc1(this,&local_18,4);
  FUN_0054cbc1(this,&local_10,4);
  Record_SetDoubles48B(this_00[0x16],*this_00,(double)local_18,(double)local_10);
  FUN_0054cbc1(this,this_00 + 2,2);
  FUN_0054cbc1(this,(int)this_00 + 10,2);
  FUN_0054cbc1(this,this_00 + 3,4);
  FUN_0054cbc1(this,this_00 + 4,1);
  FUN_0054cbc1(this,local_4,4);
  Object_SetShort28(this_00,local_4[0]);
  FUN_0054cbc1(this,this_00 + 0xb,4);
  FUN_0054cbc1(this,this_00 + 0xc,8);
  FUN_0054cbc1(this,this_00 + 0xe,8);
  FUN_0054cbc1(this,this_00 + 0x10,4);
  if (DAT_0057c668 < 0x2a) {
    puVar4 = this_00 + 0x12;
    this_00[0x11] = 0xffffffff;
    uVar5 = 4;
  }
  else {
    puVar4 = this_00 + 0x11;
    uVar5 = 8;
  }
  FUN_0054cbc1(this,puVar4,uVar5);
  FUN_0054cbc1(this,this_00 + 0x15,4);
  if (DAT_0057c668 < 0x2a) {
    puVar4 = this_00 + 0x14;
    this_00[0x13] = 0xffffffff;
    uVar5 = 4;
  }
  else {
    puVar4 = this_00 + 0x13;
    uVar5 = 8;
  }
  FUN_0054cbc1(this,puVar4,uVar5);
  SetRect((LPRECT)(this_00 + 0x17),0xffff,0xffff,-1,-1);
  piVar1 = (int *)(uint)(this_00[1] != 0xffffffff);
  FUN_0054cbc1(this,&local_8,4);
  Object_ClearField4((int)(this_00 + 5));
  local_18 = 0;
  if (0 < local_8) {
    do {
      FUN_0054cbc1(this,&local_14,2);
      iVar2 = FUN_004f0c60(local_c,piVar1,local_14 & 0xffff);
      FUN_0054b3d0(this_00 + 5,iVar2);
      local_18 = local_18 + 1;
    } while (local_18 < local_8);
  }
  FUN_0054cbc1(this,&local_18,4);
  if (local_18 == 0) {
    this_00[8] = 0;
  }
  else {
    FUN_0054cbc1(this,&local_14,2);
    uVar3 = FUN_004f0c60(local_c,piVar1,local_14 & 0xffff);
    this_00[8] = uVar3;
  }
  FUN_0054cbc1(this,&local_18,4);
  if (local_18 == 0) {
    this_00[9] = 0;
  }
  else {
    FUN_0054cbc1(this,&local_14,2);
    uVar3 = FUN_004f0c60(local_c,piVar1,local_14 & 0xffff);
    this_00[9] = uVar3;
  }
  Record_ClearActive48((void *)this_00[0x16],*this_00);
  if ((char)param_1 != '\0') {
    FUN_00533aa0((void *)this_00[0x16],*this_00,this_00[3]);
  }
  return;
}

