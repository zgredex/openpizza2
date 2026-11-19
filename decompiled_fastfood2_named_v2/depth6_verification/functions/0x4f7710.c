// rea decompile_all
// name: FUN_004f7710
// address: 0x4f7710
// body: available
// range: 0x4f7710-0x4f78d2 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_004f7710(int param_1,void *param_2,int param_3,int param_4,int param_5)

{
  void *this;
  void *this_00;
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  char *pcVar6;
  int local_18;
  int local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a0eb;
  local_c = ExceptionList;
  puVar4 = (undefined4 *)0x0;
  ExceptionList = &local_c;
  this = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 4),param_1,(int *)0x0);
  local_10 = (void *)FUN_00488be0(DAT_0057c670,param_3);
  FUN_00486be0(DAT_0057c670,0);
  iVar1 = *(int *)((int)param_2 + 0x48);
  if ((-1 < iVar1) && (iVar1 < 4)) {
    iVar1 = *(int *)(&DAT_00568188 + iVar1 * 4);
  }
  if (param_5 == 0) {
    uVar5 = 3;
  }
  else {
    uVar5 = 6;
  }
  FUN_004d77b0(this,param_2,uVar5,param_3,(void *)0x10,iVar1 + 0x834 + param_4 * 4);
  *(undefined4 *)(*(int *)((int)this + 0xfa8) + 0xf4) = 1;
  *(undefined4 *)((int)param_2 + 0x4c) = 0;
  this_00 = operator_new(0x150);
  local_4 = 0;
  if (this_00 != (void *)0x0) {
    puVar4 = FUN_00513c90(this_00,(void *)0x0);
  }
  local_4 = 0xffffffff;
  iVar1 = FUN_00488be0(DAT_0057c670,param_3);
  iVar2 = FUN_004014b0((void *)(iVar1 + 0x180),puVar4);
  *(int *)((int)param_2 + 0x2c) = iVar2;
  iVar1 = (int)this + 4;
  pcVar6 = s__s__d_00568964;
  puVar3 = (undefined1 *)FUN_00513fc0((int)puVar4);
  FUN_0054dd83(puVar3,(byte *)pcVar6,iVar1);
  puVar4[9] = param_3;
  puVar4[10] = param_1;
  puVar4[0xb] = param_4;
  puVar4[0xd] = param_2;
  *(int *)((int)this + 0xdc4) = *(int *)((int)this + 0xdc4) + 1;
  if (*(void **)((int)DAT_0057c670 + 0x264) != (void *)0x0) {
    FUN_005301c0(*(void **)((int)DAT_0057c670 + 0x264),-0x18689,0x23,1);
  }
  FUN_00486e00((int)DAT_0057c670);
  FUN_004d5dd0(this,(int)param_2,3,&local_18,&local_14,param_3,(int *)0x0);
  if (param_5 == 0) {
    *(undefined1 *)(puVar4 + 0xf) = 1;
    puVar4[0x10] = 0;
    Game_CanAffordWithCurrency(local_10,2,(float)local_14,'\0',0xffffffff);
  }
  else {
    *(undefined1 *)(puVar4 + 0xf) = 0;
    puVar4[0x10] = local_18;
    FUN_005140e0(puVar4);
  }
  ExceptionList = local_c;
  return iVar2;
}

