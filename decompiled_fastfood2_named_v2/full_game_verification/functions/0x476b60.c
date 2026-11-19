// rea decompile_all
// name: Branch_Construct
// address: 0x476b60
// body: available
// range: 0x476b60-0x476fd3 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall
Branch_Construct(void *this,int param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* Constructs a branch business object and its containers. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00557e5a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  List_Construct((void *)((int)this + 0x14e4),0);
  local_4 = 0;
  List_Construct((void *)((int)this + 0x1500),0);
  local_4._0_1_ = 1;
  List_Construct((void *)((int)this + 0x16f8),0);
  local_4._0_1_ = 2;
  List_Construct((void *)((int)this + 0x1728),0);
  local_4._0_1_ = 3;
  List_Construct((void *)((int)this + 0x1744),0);
  local_4._0_1_ = 4;
  List_Construct((void *)((int)this + 0x1760),0);
  local_4._0_1_ = 5;
  List_Construct((void *)((int)this + 0x1998),0);
  local_4._0_1_ = 6;
  List_Construct((void *)((int)this + 0x19c4),0);
  local_4._0_1_ = 7;
  List_Construct((void *)((int)this + 0x19e0),0);
  *(undefined ***)this = &PTR_Branch_Delete_0055c30c;
  *(undefined4 *)((int)this + 0x30) = param_2;
  *(undefined4 *)((int)this + 0x34) = param_3;
  *(int *)((int)this + 0x38) = param_1;
  *(undefined4 *)((int)this + 0x14dc) = 0;
  *(undefined4 *)((int)this + 0x14a8) = 100;
  *(undefined4 *)((int)this + 0x14ac) = 10;
  *(undefined4 *)((int)this + 0x14b8) = 0;
  *(undefined4 *)((int)this + 0x14bc) = 0;
  *(undefined4 *)((int)this + 0x1894) = 0;
  *(undefined4 *)((int)this + 0x1a28) = 0;
  local_4._0_1_ = 8;
  puVar2 = (undefined4 *)((int)this + 0x44);
  for (iVar3 = 0x51; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)((int)this + 0x188);
  for (iVar3 = 0x51; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)((int)this + 0x2cc);
  for (iVar3 = 0x51; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)((int)this + 0x410);
  for (iVar3 = 0x51; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)((int)this + 0x554);
  for (iVar3 = 900; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)((int)this + 0x1364);
  for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)((int)this + 0x19b4) = 0;
  *(undefined4 *)((int)this + 0x19b8) = 0;
  *(undefined4 *)((int)this + 0x19bc) = 0;
  *(undefined4 *)((int)this + 0x19c0) = 0;
  puVar2 = (undefined4 *)((int)this + 5000);
  for (iVar3 = 0x12; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)((int)this + 0x13d0);
  for (iVar3 = 0x12; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)((int)this + 0x1418);
  for (iVar3 = 0x12; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)((int)this + 0x1460);
  for (iVar3 = 0x12; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)((int)this + 0x1884) = 0;
  *(undefined4 *)((int)this + 0x1888) = 0;
  *(undefined4 *)((int)this + 0x188c) = 0;
  *(undefined4 *)((int)this + 0x1890) = 0;
  *(undefined4 *)((int)this + 0x14c8) = 0;
  *(undefined4 *)((int)this + 0x14cc) = 0;
  *(undefined4 *)((int)this + 0x14d0) = 0;
  *(undefined4 *)((int)this + 0x14d4) = 0;
  *(undefined4 *)((int)this + 0x14c0) = 0;
  *(undefined4 *)((int)this + 0x14b4) = 0;
  *(undefined4 *)((int)this + 0x14d8) = 0xffffffff;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x16f0) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined1 *)((int)this + 0x16f4) = 1;
  *(undefined4 *)((int)this + 0x14b0) = 0;
  *(undefined4 *)((int)this + 0x14c4) = 0;
  *(undefined4 *)((int)this + 0x1714) = 0;
  *(undefined4 *)((int)this + 0x1718) = 0;
  *(undefined4 *)((int)this + 0x171c) = 0;
  *(undefined4 *)((int)this + 0x1720) = 0;
  *(undefined4 *)((int)this + 0x1724) = 0;
  *(undefined1 *)((int)this + 0x16f5) = 0;
  puVar2 = (undefined4 *)((int)this + 0x177c);
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)((int)this + 0x179c);
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)((int)this + 0x17bc);
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)((int)this + 0x1898);
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)((int)this + 0x18d8);
  for (iVar3 = 0x30; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)((int)this + 0x16bc);
  for (iVar3 = 0xd; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)((int)this + 0x151c);
  for (iVar3 = 0x68; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)((int)this + 0x187c) = 0;
  *(undefined4 *)((int)this + 0x19fc) = 4;
  *(undefined4 *)((int)this + 0x1a00) = 0;
  *(undefined4 *)((int)this + 0x1a04) = 4;
  *(undefined1 *)((int)this + 0x1880) = 0;
  *(undefined1 *)((int)this + 0x1881) = 0;
  *(undefined1 *)((int)this + 0x1882) = 0;
  *(undefined1 *)((int)this + 0x1883) = 0;
  *(undefined1 *)((int)this + 0x1a20) = 0;
  *(undefined1 *)((int)this + 0x1a21) = 0;
  *(undefined4 *)((int)this + 0x3c) = 0xffffffff;
  *(undefined4 *)((int)this + 0x1a2c) = 1;
  *(undefined4 *)((int)this + 0x1a30) = 0;
  *(undefined4 *)((int)this + 0x1a34) = 0;
  *(undefined4 *)((int)this + 0x1a38) = 0;
  *(undefined4 *)((int)this + 0x1a24) = 0;
  if (param_1 == 0) {
    pvVar1 = operator_new(0x10178);
    local_4 = CONCAT31(local_4._1_3_,9);
    if (pvVar1 == (void *)0x0) {
LAB_00476ee2:
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = IsoMap_Construct(pvVar1,(int)DAT_0057c5cc);
    }
  }
  else if (param_1 == 1) {
    pvVar1 = operator_new(0x10178);
    local_4 = CONCAT31(local_4._1_3_,10);
    if (pvVar1 == (void *)0x0) goto LAB_00476ee2;
    puVar2 = IsoMap_Construct(pvVar1,(int)DAT_0057c5cc);
  }
  else {
    if (param_1 != 2) goto LAB_00476eef;
    pvVar1 = operator_new(0x10178);
    local_4 = CONCAT31(local_4._1_3_,0xb);
    if (pvVar1 == (void *)0x0) goto LAB_00476ee2;
    puVar2 = IsoMap_Construct(pvVar1,(int)DAT_0057c5cc);
  }
  *(undefined4 **)((int)this + 0x14e0) = puVar2;
LAB_00476eef:
  local_4._0_1_ = 8;
  iVar3 = Object_GetBufferCount(*(void **)((int)this + 0x14e0),(undefined4 *)0x1);
  if (iVar3 == 0) {
    Grid_RebuildStreetNodes(*(void **)((int)this + 0x14e0),(int)this);
  }
  Game_GetSizeName(this,*(int *)((int)this + 0x19fc));
  Branch_ApplyBuildingStyleVariant(this,*(int *)((int)this + 0x1a04));
  Game_RegisterWorldObject(DAT_0057c5cc,*(undefined4 *)((int)this + 0x14e0),-1);
  *(uint *)((int)this + 0x40) = (uint)*(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 10);
  pvVar1 = operator_new(0x35c);
  local_4._0_1_ = 0xc;
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = Stats_Report_ConstructEmpty
                       (pvVar1,(uint)*(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 10),
                        (uint)*(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 4));
  }
  local_4 = CONCAT31(local_4._1_3_,8);
  List_Add((void *)((int)this + 0x14e4),puVar2);
  Map_CollectType351ToList((int)this);
  Stats_ResetAverages(this);
  ExceptionList = local_c;
  return this;
}

