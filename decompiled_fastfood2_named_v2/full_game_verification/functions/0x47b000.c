// rea decompile_all
// name: Branch_Load
// address: 0x47b000
// body: available
// range: 0x47b000-0x47b9d8 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Branch_Load(void *this,void *param_1,undefined4 *param_2)

{
  void *this_00;
  undefined4 uVar1;
  undefined4 *puVar2;
  void *pvVar3;
  int *piVar4;
  int local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  this_00 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00557f6c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CRT_Istream_Read(param_1,(int)this + 4,0x20);
  CRT_Istream_Read(this_00,(int)this + 0x2c,4);
  CRT_Istream_Read(this_00,(int)this + 0x24,4);
  CRT_Istream_Read(this_00,(int)this + 0x28,4);
  CRT_Istream_Read(this_00,(int)this + 0x30,4);
  CRT_Istream_Read(this_00,(int *)((int)this + 0x34),4);
  CRT_Istream_Read(this_00,(int)this + 0x3c,4);
  CRT_Istream_Read(this_00,(int)this + 0x40,4);
  CRT_Istream_Read(this_00,(int)this + 0x44,0x144);
  CRT_Istream_Read(this_00,(int)this + 0x188,0x144);
  CRT_Istream_Read(this_00,(int)this + 0x554,0xe10);
  CRT_Istream_Read(this_00,(int)this + 0x1364,0x24);
  CRT_Istream_Read(this_00,(int)this + 0x2cc,0x144);
  CRT_Istream_Read(this_00,(int)this + 0x410,0x144);
  CRT_Istream_Read(this_00,(int)this + 5000,0x48);
  CRT_Istream_Read(this_00,(int)this + 0x13d0,0x48);
  CRT_Istream_Read(this_00,(int)this + 0x1418,0x48);
  CRT_Istream_Read(this_00,(int)this + 0x1460,0x48);
  CRT_Istream_Read(this_00,(int)this + 0x14a8,4);
  CRT_Istream_Read(this_00,(int)this + 0x14ac,4);
  CRT_Istream_Read(this_00,(int)this + 0x14c8,4);
  CRT_Istream_Read(this_00,(int)this + 0x14cc,4);
  CRT_Istream_Read(this_00,(int)this + 0x14d0,4);
  CRT_Istream_Read(this_00,(int)this + 0x14d4,4);
  CRT_Istream_Read(this_00,(int)this + 0x14c0,4);
  CRT_Istream_Read(this_00,(int)this + 0x14d8,4);
  CRT_Istream_Read(this_00,(int)this + 0x16f5,1);
  CRT_Istream_Read(this_00,(int)this + 0x16f4,1);
  CRT_Istream_Read(this_00,(int)this + 0x14b0,4);
  CRT_Istream_Read(this_00,(int)this + 0x1714,4);
  CRT_Istream_Read(this_00,(int)this + 0x1718,4);
  CRT_Istream_Read(this_00,(int)this + 0x171c,4);
  CRT_Istream_Read(this_00,(int)this + 0x1720,4);
  CRT_Istream_Read(this_00,(int)this + 0x1724,4);
  CRT_Istream_Read(this_00,(int)this + 0x151c,0x1a0);
  CRT_Istream_Read(this_00,(int)this + 0x16bc,0x34);
  CRT_Istream_Read(this_00,(int)this + 0x177c,0x20);
  CRT_Istream_Read(this_00,(int)this + 0x179c,0x20);
  CRT_Istream_Read(this_00,(int)this + 0x17bc,0x20);
  CRT_Istream_Read(this_00,(int)this + 0x17dc,0x20);
  CRT_Istream_Read(this_00,(int)this + 0x17fc,0x20);
  CRT_Istream_Read(this_00,(int)this + 0x181c,0x20);
  CRT_Istream_Read(this_00,(int)this + 0x183c,0x14);
  CRT_Istream_Read(this_00,(int)this + 0x1850,4);
  CRT_Istream_Read(this_00,(int)this + 0x1854,4);
  CRT_Istream_Read(this_00,(int)this + 0x1858,4);
  CRT_Istream_Read(this_00,(int)this + 0x185c,4);
  CRT_Istream_Read(this_00,(int)this + 0x1860,4);
  CRT_Istream_Read(this_00,(int)this + 0x1864,4);
  CRT_Istream_Read(this_00,(int)this + 0x1868,4);
  CRT_Istream_Read(this_00,(int)this + 0x186c,4);
  CRT_Istream_Read(this_00,(int)this + 0x1870,4);
  CRT_Istream_Read(this_00,(int)this + 0x1874,4);
  CRT_Istream_Read(this_00,(int)this + 0x1878,4);
  CRT_Istream_Read(this_00,(int)this + 0x38,4);
  CRT_Istream_Read(this_00,(int)this + 0x1898,0x40);
  CRT_Istream_Read(this_00,(int)this + 0x18d8,0xc0);
  CRT_Istream_Read(this_00,(int)this + 0x187c,4);
  CRT_Istream_Read(this_00,(int *)((int)this + 0x19fc),4);
  CRT_Istream_Read(this_00,(int)this + 0x1a00,4);
  CRT_Istream_Read(this_00,(int)this + 0x1a04,4);
  CRT_Istream_Read(this_00,(int)this + 0x1880,4);
  CRT_Istream_Read(this_00,(int)this + 0x19b4,0x10);
  CRT_Istream_Read(this_00,(int)this + 0x14b4,4);
  CRT_Istream_Read(this_00,(int)this + 0x1a20,1);
  CRT_Istream_Read(this_00,(int)this + 0x1a21,1);
  CRT_Istream_Read(this_00,(int)this + 0x1884,0x10);
  CRT_Istream_Read(this_00,(int)this + 0x1a2c,4);
  CRT_Istream_Read(this_00,(int)this + 0x1a30,4);
  CRT_Istream_Read(this_00,(int)this + 0x1a34,4);
  CRT_Istream_Read(this_00,(int)this + 0x1a38,4);
  CRT_Istream_Read(this_00,(int)this + 0x1a24,4);
  CRT_Istream_Read(this_00,(int)this + 0x14b8,4);
  CRT_Istream_Read(this_00,(int)this + 0x14bc,4);
  if (DAT_0057c668 < 0x2c) {
    *(undefined4 *)((int)this + 0x1894) = 0;
  }
  else {
    CRT_Istream_Read(this_00,(int)this + 0x1894,4);
  }
  local_14 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)((int)this + 0x34),(int *)0x0);
  CRT_Istream_Read(this_00,&param_1,4);
  if (param_1 == (void *)0x1) {
    CRT_Istream_Read(this_00,&local_18,4);
    uVar1 = IDMap_Lookup(param_2 + 0x44,local_18,(int *)0x0);
    *(undefined4 *)((int)this + 0x14dc) = uVar1;
  }
  else {
    *(undefined4 *)((int)this + 0x14dc) = 0;
  }
  CRT_Istream_Read(this_00,&param_1,4);
  uVar1 = Game_UpdateIDMapEntry(DAT_0057c5cc,(int)param_1);
  *(undefined4 *)((int)this + 0x14e0) = uVar1;
  Game_GetSizeName(this,*(int *)((int)this + 0x19fc));
  Branch_ApplyBuildingStyleVariant(this,*(int *)((int)this + 0x1a04));
  CRT_Istream_Read(this_00,&local_1c,4);
  param_1 = (void *)0x0;
  if (0 < local_1c) {
    do {
      param_2 = operator_new(0x35c);
      local_4 = 0;
      if (param_2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        puVar2 = StatsPeriodReport_StreamConstruct(param_2,this_00);
      }
      local_4 = 0xffffffff;
      List_Add((void *)((int)this + 0x14e4),puVar2);
      param_1 = (void *)((int)param_1 + 1);
    } while ((int)param_1 < local_1c);
  }
  CRT_Istream_Read(this_00,&local_18,4);
  if (local_18 == -1) {
    *(undefined4 *)((int)this + 0x16f0) = 0;
  }
  else {
    uVar1 = IDMap_Lookup((void *)(local_14 + 0xfac),local_18,(int *)0x0);
    *(undefined4 *)((int)this + 0x16f0) = uVar1;
  }
  CRT_Istream_Read(this_00,&local_1c,4);
  param_1 = (void *)0x0;
  if (0 < local_1c) {
    do {
      CRT_Istream_Read(this_00,&local_10,4);
      CRT_Istream_Read(this_00,&local_18,4);
      puVar2 = operator_new(8);
      local_4 = 1;
      param_2 = puVar2;
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        uVar1 = IDMap_Lookup((void *)(DAT_0057c670 + 0x20),local_18,(int *)0x0);
        *puVar2 = uVar1;
        puVar2[1] = local_10;
      }
      local_4 = 0xffffffff;
      List_Add((void *)((int)this + 0x1500),puVar2);
      param_1 = (void *)((int)param_1 + 1);
    } while ((int)param_1 < local_1c);
  }
  CRT_Istream_Read(this_00,&local_1c,4);
  param_1 = (void *)0x0;
  if (0 < local_1c) {
    do {
      CRT_Istream_Read(this_00,&local_18,4);
      param_2 = operator_new(0x24);
      local_4 = 2;
      if (param_2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        puVar2 = ConstructionOrder_StreamConstruct(param_2,this_00);
      }
      local_4 = 0xffffffff;
      IDMap_InsertGrow((void *)((int)this + 0x16f8),puVar2,local_18);
      param_1 = (void *)((int)param_1 + 1);
    } while ((int)param_1 < local_1c);
  }
  CRT_Istream_Read(this_00,&local_1c,4);
  param_1 = (void *)0x0;
  if (0 < local_1c) {
    do {
      CRT_Istream_Read(this_00,&local_18,4);
      if (0 < local_18) {
        List_Add((void *)((int)this + 0x1728),local_18);
      }
      param_1 = (void *)((int)param_1 + 1);
    } while ((int)param_1 < local_1c);
  }
  CRT_Istream_Read(this_00,&local_1c,4);
  param_1 = (void *)0x0;
  if (0 < local_1c) {
    do {
      CRT_Istream_Read(this_00,&local_18,4);
      List_Add((void *)((int)this + 0x1744),local_18);
      param_1 = (void *)((int)param_1 + 1);
    } while ((int)param_1 < local_1c);
  }
  CRT_Istream_Read(this_00,&local_1c,4);
  param_1 = (void *)0x0;
  if (0 < local_1c) {
    do {
      CRT_Istream_Read(this_00,&local_18,4);
      List_Add((void *)((int)this + 0x1760),local_18);
      param_1 = (void *)((int)param_1 + 1);
    } while ((int)param_1 < local_1c);
  }
  CRT_Istream_Read(this_00,&local_1c,4);
  param_1 = (void *)0x0;
  if (0 < local_1c) {
    do {
      CRT_Istream_Read(this_00,&local_18,4);
      pvVar3 = operator_new(0x20);
      CRT_Istream_Read(this_00,pvVar3,0x20);
      IDMap_InsertGrow((void *)((int)this + 0x1998),pvVar3,local_18);
      param_1 = (void *)((int)param_1 + 1);
    } while ((int)param_1 < local_1c);
  }
  CRT_Istream_Read(this_00,&local_1c,4);
  param_1 = (void *)0x0;
  if (0 < local_1c) {
    do {
      pvVar3 = operator_new(0x30);
      CRT_Istream_Read(this_00,pvVar3,0x30);
      List_Add((void *)((int)this + 0x19c4),pvVar3);
      param_1 = (void *)((int)param_1 + 1);
    } while ((int)param_1 < local_1c);
  }
  CRT_Istream_Read(this_00,&local_1c,4);
  param_1 = (void *)0x0;
  if (0 < local_1c) {
    do {
      CRT_Istream_Read(this_00,&local_18,4);
      param_2 = operator_new(0x24);
      local_4 = 3;
      if (param_2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        puVar2 = ConstructionOrder_StreamConstruct(param_2,this_00);
      }
      local_4 = 0xffffffff;
      IDMap_InsertGrow((void *)((int)this + 0x19e0),puVar2,local_18);
      param_1 = (void *)((int)param_1 + 1);
    } while ((int)param_1 < local_1c);
  }
  IsoMap_MarkPlayerFootprints(*(void **)((int)this + 0x14e0),(int)this);
  if (*(char *)((int)this + 0x1a20) != '\0') {
    Game_ShowBuildingOverlay(this,1);
  }
  *(undefined4 *)((int)this + 0x14c4) = 0;
  local_1c = *(int *)((int)this + 0x1514);
  param_1 = (void *)0x0;
  if (0 < local_1c) {
    do {
      piVar4 = (int *)IDMap_Lookup((void *)((int)this + 0x1500),(int)param_1,(int *)0x0);
      if (*(char *)(*piVar4 + 0x824) == '\x01') {
        *(int *)((int)this + 0x14c4) = *piVar4;
        ExceptionList = local_c;
        return;
      }
      param_1 = (void *)((int)param_1 + 1);
    } while ((int)param_1 < local_1c);
  }
  ExceptionList = local_c;
  return;
}

