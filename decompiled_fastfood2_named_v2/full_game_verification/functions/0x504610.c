// rea decompile_all
// name: Object_Construct
// address: 0x504610
// body: available
// range: 0x504610-0x504920 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall
Object_Construct(void *this,undefined4 param_1,int param_2,undefined4 param_3,int param_4,
                int param_5)

{
  void *this_00;
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a21c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  List_Construct((void *)((int)this + 0x114),0);
  local_4 = 0;
  List_Construct((void *)((int)this + 0x130),0);
  *(undefined ***)this = &PTR_LAB_0055c668;
  local_4 = CONCAT31(local_4._1_3_,1);
  this_00 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),param_2,(int *)0x0);
  if (this_00 == (void *)0x0) {
    NoOp_Stub();
  }
  *(undefined1 *)((int)this + 0x80) = 1;
  *(undefined4 *)((int)this + 0x30) = param_1;
  *(int *)((int)this + 0x28) = param_2;
  *(undefined4 *)((int)this + 0x24) = param_3;
  *(undefined4 *)((int)this + 0x50) = 0xffffffff;
  *(undefined4 *)((int)this + 0x7c) = 0xff;
  *(undefined1 *)((int)this + 0x81) = 0;
  *(undefined4 *)((int)this + 0x84) = 0;
  *(undefined4 *)((int)this + 0x88) = 0;
  *(undefined4 *)((int)this + 0x8c) = 0;
  *(undefined4 *)((int)this + 0x90) = 0;
  *(undefined4 *)((int)this + 0xa0) = 0;
  *(undefined4 *)((int)this + 0xa4) = 0xffffffff;
  *(undefined4 *)((int)this + 0xa8) = 100;
  *(undefined4 *)((int)this + 0x110) = 0xffffffff;
  Object_SetFieldFC(this,0);
  *(undefined1 *)((int)this + 0x104) = 0;
  *(undefined4 *)((int)this + 0x100) = 0;
  *(undefined4 *)((int)this + 0x108) = 0xffffffff;
  *(undefined4 *)((int)this + 0x34) = 3;
  uVar1 = Random_RangeFast(0x1e,0x32);
  *(uint *)((int)this + 0x2c) = uVar1;
  *(undefined4 *)((int)this + 0x164) = 0xffffffff;
  *(undefined4 *)((int)this + 0x74) = 0;
  *(undefined4 *)((int)this + 0x168) = 0;
  *(undefined4 *)((int)this + 0x38) = 2;
  if (param_4 != 0) {
    param_5 = -1;
    *(undefined4 *)((int)this + 0xc4) = *(undefined4 *)(param_4 + 0x14e0);
  }
  else {
    iVar2 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)((int)this + 0x28),(int *)0x0);
    *(undefined4 *)((int)this + 0xc4) = *(undefined4 *)(iVar2 + 0xfa8);
  }
  MapObject_InitRenderRecord(this,(uint)(param_4 != 0),-1,param_5);
  UI_SetChildState(this,0xffff);
  switch(param_1) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
    *(undefined4 *)((int)this + 0x34) = param_1;
    break;
  case 9:
  case 10:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x19:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x1e:
  case 0x20:
    *(undefined4 *)((int)this + 0x34) = 3;
    break;
  case 0xb:
  case 0xf:
  case 0x21:
    *(undefined4 *)((int)this + 0x34) = 5;
    break;
  case 0x18:
    *(undefined4 *)((int)this + 0x34) = 3;
    UI_SetChildState(this,4);
  }
  iVar2 = *(int *)((int)this + 0x30);
  if ((((-1 < iVar2) && (iVar2 < 8)) || (iVar2 == 0xb)) || ((iVar2 == 0xf || (iVar2 == 0x21)))) {
    *(undefined4 *)((int)this + 0xa0) = 1;
  }
  iVar2 = Map_GetRandomBuildingOfType(this_00,0,0,'\0');
  *(int *)((int)this + 0xcc) = iVar2;
  *(int *)((int)this + 0xd0) = iVar2;
  *(undefined4 *)((int)this + 0xf4) = 0;
  *(undefined4 *)((int)this + 0xf8) = 0;
  Object_InitCompanyBuildingGraphics(this,-1);
  *(undefined4 *)((int)this + 0x3c) = 0xffffffff;
  Game_GetTimeByMode(this,0);
  *(undefined2 *)((int)this + 0x40) = 0xffff;
  *(undefined4 *)((int)this + 0x58) = 0xffffffff;
  *(undefined4 *)((int)this + 0x10c) = 0xffffffff;
  *(undefined4 *)((int)this + 0x94) = 0xffffffff;
  *(undefined4 *)((int)this + 0x9c) = 0xffffffff;
  *(undefined4 *)((int)this + 0x4c) = 0;
  *(undefined4 *)((int)this + 0x54) = 0;
  *(undefined4 *)((int)this + 0x74) = 0;
  *(undefined4 *)((int)this + 0x78) = 0;
  *(undefined4 *)((int)this + 0x98) = 0;
  puVar3 = (undefined4 *)((int)this + 0x14c);
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  puVar3 = (undefined4 *)((int)this + 0xac);
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  puVar3 = (undefined4 *)((int)this + 0x5c);
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  switch(*(undefined4 *)((int)this + 0x30)) {
  case 0xd:
    iVar2 = 0x11;
    break;
  default:
    goto switchD_00504872_caseD_e;
  case 0x10:
  case 0x20:
    iVar2 = 0x19;
    break;
  case 0x16:
  case 0x17:
  case 0x1d:
  case 0x1e:
  case 0x1f:
    iVar2 = 0x17;
  }
  iVar2 = Map_GetRandomBuildingOfType(this_00,iVar2,0,'\0');
  *(int *)((int)this + 0xcc) = iVar2;
switchD_00504872_caseD_e:
  if (param_4 == 0) {
    iVar2 = Array_GetRecord28(*(void **)((int)this + 0xc4),1,
                              *(int *)(*(int *)((int)this + 0xcc) + 0x54));
    UI_SetChildTracking(this,0,iVar2);
    Object_SetFieldFC(this,*(undefined4 *)((int)this + 0xcc));
  }
  else {
    Object_SetFieldFC(this,*(undefined4 *)(param_4 + 0x16f0));
    *(undefined4 *)((int)this + 0x74) = 1;
    *(undefined1 *)((int)this + 0x104) = 1;
    *(undefined4 *)((int)this + 0xf4) = *(undefined4 *)(param_4 + 0x16f0);
  }
  if (*(int *)((int)this + 0x30) == 0x2e) {
    *(undefined4 *)((int)this + 0xcc) = 0;
    Object_SetFieldFC(this,0);
  }
  ExceptionList = local_c;
  return this;
}

