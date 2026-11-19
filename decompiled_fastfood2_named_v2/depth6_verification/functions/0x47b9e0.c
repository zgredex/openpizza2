// rea decompile_all
// name: FUN_0047b9e0
// address: 0x47b9e0
// body: available
// range: 0x47b9e0-0x47c2ae inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_0047b9e0(void *this,void *param_1)

{
  void *pvVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int local_14;
  int local_10;
  int local_c;
  void *local_8;
  int local_4;
  
  local_8 = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 4),*(int *)((int)this + 0x34),
                                 (int *)0x0);
  FUN_0054cc2b(param_1,(int)this + 4,0x20);
  FUN_0054cc2b(param_1,(int)this + 0x2c,4);
  FUN_0054cc2b(param_1,(int)this + 0x24,4);
  FUN_0054cc2b(param_1,(int)this + 0x28,4);
  FUN_0054cc2b(param_1,(int *)((int)this + 0x30),4);
  FUN_0054cc2b(param_1,(int)this + 0x34,4);
  FUN_0054cc2b(param_1,(int)this + 0x3c,4);
  FUN_0054cc2b(param_1,(int)this + 0x40,4);
  FUN_0054cc2b(param_1,(int)this + 0x44,0x144);
  FUN_0054cc2b(param_1,(int)this + 0x188,0x144);
  FUN_0054cc2b(param_1,(int)this + 0x554,0xe10);
  FUN_0054cc2b(param_1,(int)this + 0x1364,0x24);
  FUN_0054cc2b(param_1,(int)this + 0x2cc,0x144);
  FUN_0054cc2b(param_1,(int)this + 0x410,0x144);
  FUN_0054cc2b(param_1,(int)this + 5000,0x48);
  FUN_0054cc2b(param_1,(int)this + 0x13d0,0x48);
  FUN_0054cc2b(param_1,(int)this + 0x1418,0x48);
  FUN_0054cc2b(param_1,(int)this + 0x1460,0x48);
  FUN_0054cc2b(param_1,(int)this + 0x14a8,4);
  FUN_0054cc2b(param_1,(int)this + 0x14ac,4);
  FUN_0054cc2b(param_1,(int)this + 0x14c8,4);
  FUN_0054cc2b(param_1,(int)this + 0x14cc,4);
  FUN_0054cc2b(param_1,(int)this + 0x14d0,4);
  FUN_0054cc2b(param_1,(int)this + 0x14d4,4);
  FUN_0054cc2b(param_1,(int)this + 0x14c0,4);
  FUN_0054cc2b(param_1,(int)this + 0x14d8,4);
  FUN_0054cc2b(param_1,(int)this + 0x16f5,1);
  FUN_0054cc2b(param_1,(int)this + 0x16f4,1);
  FUN_0054cc2b(param_1,(int)this + 0x14b0,4);
  FUN_0054cc2b(param_1,(int)this + 0x1714,4);
  FUN_0054cc2b(param_1,(int)this + 0x1718,4);
  FUN_0054cc2b(param_1,(int)this + 0x171c,4);
  FUN_0054cc2b(param_1,(int)this + 0x1720,4);
  FUN_0054cc2b(param_1,(int)this + 0x1724,4);
  FUN_0054cc2b(param_1,(int)this + 0x151c,0x1a0);
  FUN_0054cc2b(param_1,(int)this + 0x16bc,0x34);
  FUN_0054cc2b(param_1,(int)this + 0x177c,0x20);
  FUN_0054cc2b(param_1,(int)this + 0x179c,0x20);
  FUN_0054cc2b(param_1,(int)this + 0x17bc,0x20);
  FUN_0054cc2b(param_1,(int)this + 0x17dc,0x20);
  FUN_0054cc2b(param_1,(int)this + 0x17fc,0x20);
  FUN_0054cc2b(param_1,(int)this + 0x181c,0x20);
  FUN_0054cc2b(param_1,(int)this + 0x183c,0x14);
  FUN_0054cc2b(param_1,(int)this + 0x1850,4);
  FUN_0054cc2b(param_1,(int)this + 0x1854,4);
  FUN_0054cc2b(param_1,(int)this + 0x1858,4);
  FUN_0054cc2b(param_1,(int)this + 0x185c,4);
  FUN_0054cc2b(param_1,(int)this + 0x1860,4);
  FUN_0054cc2b(param_1,(int)this + 0x1864,4);
  FUN_0054cc2b(param_1,(int)this + 0x1868,4);
  FUN_0054cc2b(param_1,(int)this + 0x186c,4);
  FUN_0054cc2b(param_1,(int)this + 0x1870,4);
  FUN_0054cc2b(param_1,(int)this + 0x1874,4);
  FUN_0054cc2b(param_1,(int)this + 0x1878,4);
  FUN_0054cc2b(param_1,(int)this + 0x38,4);
  FUN_0054cc2b(param_1,(int)this + 0x1898,0x40);
  FUN_0054cc2b(param_1,(int)this + 0x18d8,0xc0);
  FUN_0054cc2b(param_1,(int)this + 0x187c,4);
  FUN_0054cc2b(param_1,(int)this + 0x19fc,4);
  FUN_0054cc2b(param_1,(int)this + 0x1a00,4);
  FUN_0054cc2b(param_1,(int)this + 0x1a04,4);
  FUN_0054cc2b(param_1,(int)this + 0x1880,4);
  FUN_0054cc2b(param_1,(int)this + 0x19b4,0x10);
  FUN_0054cc2b(param_1,(int)this + 0x14b4,4);
  FUN_0054cc2b(param_1,(int)this + 0x1a20,1);
  FUN_0054cc2b(param_1,(int)this + 0x1a21,1);
  FUN_0054cc2b(param_1,(int)this + 0x1884,0x10);
  FUN_0054cc2b(param_1,(int)this + 0x1a2c,4);
  FUN_0054cc2b(param_1,(int)this + 0x1a30,4);
  FUN_0054cc2b(param_1,(int)this + 0x1a34,4);
  FUN_0054cc2b(param_1,(int)this + 0x1a38,4);
  FUN_0054cc2b(param_1,(int)this + 0x1a24,4);
  FUN_0054cc2b(param_1,(int)this + 0x14b8,4);
  FUN_0054cc2b(param_1,(int)this + 0x14bc,4);
  FUN_0054cc2b(param_1,(int)this + 0x1894,4);
  if (*(int *)((int)this + 0x14dc) == 0) {
    piVar2 = &local_10;
    local_10 = 0;
  }
  else {
    local_10 = 1;
    FUN_0054cc2b(param_1,&local_10,4);
    iVar4 = *(int *)((int)this + 0x14dc);
    pvVar1 = (void *)FUN_00488be0(DAT_0057c670,*(int *)((int)this + 0x30));
    local_c = FUN_004dde70(pvVar1,iVar4);
    piVar2 = &local_c;
  }
  FUN_0054cc2b(param_1,piVar2,4);
  local_10 = FUN_004eacb0(DAT_0057c5cc,*(int *)((int)this + 0x14e0));
  FUN_0054cc2b(param_1,&local_10,4);
  local_14 = *(int *)((int)this + 0x14f8);
  FUN_0054cc2b(param_1,&local_14,4);
  local_10 = 0;
  if (0 < local_14) {
    do {
      pvVar1 = (void *)FUN_004017f0((void *)((int)this + 0x14e4),local_10,(int *)0x0);
      FUN_00401200(pvVar1,param_1);
      local_10 = local_10 + 1;
    } while (local_10 < local_14);
  }
  local_c = FUN_004d7e90(local_8,*(int *)((int)this + 0x16f0));
  FUN_0054cc2b(param_1,&local_c,4);
  local_14 = *(int *)((int)this + 0x1514);
  FUN_0054cc2b(param_1,&local_14,4);
  local_10 = 0;
  if (0 < local_14) {
    do {
      piVar2 = (int *)FUN_004017f0((void *)((int)this + 0x1500),local_10,(int *)0x0);
      local_4 = piVar2[1];
      FUN_0054cc2b(param_1,&local_4,4);
      local_c = FUN_00401930((void *)((int)DAT_0057c670 + 0x20),*piVar2);
      FUN_0054cc2b(param_1,&local_c,4);
      local_10 = local_10 + 1;
    } while (local_10 < local_14);
  }
  local_14 = *(int *)((int)this + 0x170c);
  FUN_0054cc2b(param_1,&local_14,4);
  local_10 = 0;
  if (0 < local_14) {
    do {
      pvVar1 = (void *)FUN_004017f0((void *)((int)this + 0x16f8),local_10,&local_c);
      FUN_0054cc2b(param_1,&local_c,4);
      FUN_004e5e30(pvVar1,param_1);
      local_10 = local_10 + 1;
    } while (local_10 < local_14);
  }
  local_14 = *(int *)((int)this + 0x173c);
  FUN_0054cc2b(param_1,&local_14,4);
  local_10 = 0;
  if (0 < local_14) {
    do {
      local_c = FUN_004017f0((void *)((int)this + 0x1728),local_10,(int *)0x0);
      FUN_0054cc2b(param_1,&local_c,4);
      local_10 = local_10 + 1;
    } while (local_10 < local_14);
  }
  local_14 = *(int *)((int)this + 0x1758);
  FUN_0054cc2b(param_1,&local_14,4);
  local_10 = 0;
  if (0 < local_14) {
    do {
      local_c = FUN_004017f0((void *)((int)this + 0x1744),local_10,(int *)0x0);
      FUN_0054cc2b(param_1,&local_c,4);
      local_10 = local_10 + 1;
    } while (local_10 < local_14);
  }
  local_14 = *(int *)((int)this + 0x1774);
  FUN_0054cc2b(param_1,&local_14,4);
  local_10 = 0;
  if (0 < local_14) {
    do {
      local_c = FUN_004017f0((void *)((int)this + 0x1760),local_10,(int *)0x0);
      FUN_0054cc2b(param_1,&local_c,4);
      local_10 = local_10 + 1;
    } while (local_10 < local_14);
  }
  local_14 = *(int *)((int)this + 0x19ac);
  FUN_0054cc2b(param_1,&local_14,4);
  local_10 = 0;
  if (0 < local_14) {
    do {
      uVar3 = FUN_004017f0((void *)((int)this + 0x1998),local_10,&local_c);
      FUN_0054cc2b(param_1,&local_c,4);
      FUN_0054cc2b(param_1,uVar3,0x20);
      local_10 = local_10 + 1;
    } while (local_10 < local_14);
  }
  local_14 = *(int *)((int)this + 0x19d8);
  FUN_0054cc2b(param_1,&local_14,4);
  local_10 = 0;
  if (0 < local_14) {
    do {
      uVar3 = FUN_004017f0((void *)((int)this + 0x19c4),local_10,(int *)0x0);
      FUN_0054cc2b(param_1,uVar3,0x30);
      local_10 = local_10 + 1;
    } while (local_10 < local_14);
  }
  local_14 = *(int *)((int)this + 0x19f4);
  FUN_0054cc2b(param_1,&local_14,4);
  local_10 = 0;
  if (0 < local_14) {
    do {
      pvVar1 = (void *)FUN_004017f0((void *)((int)this + 0x19e0),local_10,&local_c);
      FUN_0054cc2b(param_1,&local_c,4);
      FUN_004e5e30(pvVar1,param_1);
      local_10 = local_10 + 1;
    } while (local_10 < local_14);
  }
  return;
}

