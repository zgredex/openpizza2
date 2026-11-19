// rea decompile_all
// name: FUN_0054b970
// address: 0x54b970
// body: available
// range: 0x54b970-0x54baf4 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4
FUN_0054b970(void *param_1,int param_2,int param_3,void *param_4,int param_5,int param_6,int param_7
            )

{
  short sVar1;
  void *pvVar2;
  void *this;
  int iVar3;
  char *pcVar4;
  undefined4 *this_00;
  undefined4 *puVar5;
  undefined4 uVar6;
  ushort uVar7;
  int local_28;
  int local_24;
  void *local_20;
  int local_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  iVar3 = param_2;
  this = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b9db;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pcVar4 = (char *)FUN_005319a0(param_1,param_2);
  if (pcVar4 == (char *)0x0) {
    ExceptionList = local_c;
    return 0;
  }
  this_00 = FUN_00539ea0(DAT_0057c5c8);
  if (*pcVar4 == '\0') {
    pvVar2 = *(void **)(pcVar4 + 0x40);
    if (*(char *)((int)pvVar2 + 0x39) == '\0') {
      FUN_0053cea0(pvVar2);
    }
    sVar1 = *(short *)((int)pvVar2 + 6);
    uVar7 = *(ushort *)((int)pvVar2 + 8);
    uVar6 = *(undefined4 *)((int)pvVar2 + 0x2c);
  }
  else {
    FUN_0053d090(*(void **)(pcVar4 + 0x40),(int *)&param_1,&param_2);
    FUN_005314a0(this,iVar3,&local_24,&local_28);
    local_20 = operator_new(0x50);
    puVar5 = (undefined4 *)0x0;
    local_4 = 0;
    if (local_20 != (void *)0x0) {
      puVar5 = FUN_0053c710(local_20,(uint)param_1,param_2,0,0x10,0);
    }
    local_4 = 0xffffffff;
    UI_RemoveObject(this,iVar3);
    FUN_005317b0(this,iVar3,local_24,local_28,puVar5,1);
    if (*(char *)((int)puVar5 + 0x39) == '\0') {
      FUN_0053cea0(puVar5);
    }
    sVar1 = *(short *)((int)puVar5 + 6);
    uVar7 = *(ushort *)(puVar5 + 2);
    uVar6 = puVar5[0xb];
  }
  FUN_00539280(this_00,uVar6,(ushort)((int)sVar1 >> 1),uVar7,(int)sVar1);
  FUN_0054b770(DAT_0057c5ec,(int)this_00,param_3,param_4,param_5,param_6,param_7);
  FUN_005314f0(this,iVar3,local_1c);
  FUN_005321f0(this,local_1c,1);
  if (this_00 != (undefined4 *)0x0) {
    (**(code **)*this_00)(1);
  }
  ExceptionList = local_c;
  return 1;
}

