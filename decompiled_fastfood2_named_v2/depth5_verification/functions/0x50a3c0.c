// rea decompile_all
// name: FUN_0050a3c0
// address: 0x50a3c0
// body: available
// range: 0x50a3c0-0x50a570 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_0050a3c0(void *param_1,uint param_2)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *this;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a2fb;
  local_c = ExceptionList;
  if (*(int *)(*(int *)((int)param_1 + 0xfc) + 0x94) != 0) {
    ExceptionList = &local_c;
    FUN_0050e310(param_1,param_2,0);
    ExceptionList = local_c;
    return;
  }
  ExceptionList = &local_c;
  iVar2 = FUN_0050d750((int)param_1);
  if (iVar2 != 0) {
    FUN_0050e840((int)param_1);
  }
  if (*(int *)((int)param_1 + 0x108) != 1) goto LAB_0050a547;
  pvVar1 = *(void **)((int)param_1 + 0xfc);
  iVar2 = FUN_004017f0((void *)((int)DAT_0057c670 + 0x20),*(int *)((int)param_1 + 0x50),(int *)0x0);
  if (iVar2 == 0) {
    uVar3 = 0xffffffff;
  }
  else {
    FUN_0050e890(param_1,0x2e);
    uVar3 = (uint)*(byte *)(iVar2 + 0x824);
  }
  if (uVar3 == 0) {
LAB_0050a490:
    iVar2 = 0x1e;
    uVar7 = DAT_00580de0;
  }
  else if (uVar3 == 1) {
    iVar2 = 0x1d;
    uVar7 = DAT_00580dc8;
  }
  else {
    if (uVar3 == 2) goto LAB_0050a490;
    iVar2 = 0x1f;
    uVar7 = DAT_00580b00;
  }
  pvVar4 = operator_new(0x16c);
  this = (undefined4 *)0x0;
  local_4 = 0;
  if (pvVar4 != (void *)0x0) {
    this = FUN_00504610(pvVar4,iVar2,*(int *)((int)param_1 + 0x28),0,0,-1);
  }
  local_4 = 0xffffffff;
  FUN_004030f0(DAT_0057ba10,0,(undefined1 *)(this + 1),uVar7);
  FUN_00482790(DAT_0057c670,this);
  pvVar4 = (void *)FUN_00488be0(DAT_0057c670,*(int *)((int)pvVar1 + 8));
  iVar5 = FUN_004e3730(pvVar4,iVar2);
  iVar6 = FUN_004e1d40(pvVar4,iVar2);
  if (iVar6 + 1 < iVar5) {
    Object_AttachToParent(this,pvVar1,1);
    FUN_004e2080(pvVar4,this[0x59],iVar2);
    this[0x33] = pvVar1;
  }
LAB_0050a547:
  FUN_0050e850(param_1,0xffffffff);
  Object_Activate(param_1,*(void **)((int)param_1 + 0xfc));
  ExceptionList = local_c;
  return;
}

