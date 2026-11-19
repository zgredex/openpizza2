// rea decompile_all
// name: FUN_0055606a
// address: 0x55606a
// body: available
// range: 0x55606a-0x55650a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall
FUN_0055606a(void *this,ushort *param_1,int *param_2,byte *param_3,int param_4,int param_5,
            int param_6,int param_7)

{
  uint uVar1;
  char *pcVar2;
  int iVar3;
  byte bVar4;
  byte *pbVar5;
  byte *pbVar6;
  int iVar7;
  byte *pbVar8;
  char local_60 [23];
  char local_49;
  undefined4 local_44;
  undefined2 uStack_40;
  byte *local_3e;
  ushort local_3a;
  int local_34;
  int local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  byte *local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  char *local_10;
  int local_c;
  uint local_8;
  
  local_10 = local_60;
  local_2c = 0;
  local_1c = 1;
  local_8 = 0;
  local_14 = 0;
  local_28 = 0;
  local_24 = 0;
  local_30 = 0;
  local_34 = 0;
  local_20 = (byte *)0x0;
  local_c = 0;
  local_18 = 0;
  pbVar5 = param_3;
  while( true ) {
    bVar4 = *pbVar5;
    this = (void *)CONCAT31((int3)((uint)this >> 8),bVar4);
    if ((((bVar4 != 0x20) && (bVar4 != 9)) && (bVar4 != 10)) && (bVar4 != 0xd)) break;
    pbVar5 = pbVar5 + 1;
  }
  iVar7 = 0;
LAB_005560c1:
  iVar3 = 1;
  bVar4 = *pbVar5;
  pbVar6 = pbVar5 + 1;
  switch(iVar7) {
  case 0:
    if (('0' < (char)bVar4) && ((char)bVar4 < ':')) {
LAB_005560de:
      iVar7 = 3;
      goto LAB_00556302;
    }
    if (bVar4 == DAT_00576cf4) goto LAB_005560ed;
    if (bVar4 == 0x2b) {
      local_2c = 0;
      iVar7 = 2;
      pbVar5 = pbVar6;
    }
    else if (bVar4 == 0x2d) {
      local_2c = 0x8000;
      iVar7 = 2;
      pbVar5 = pbVar6;
    }
    else {
      if (bVar4 != 0x30) goto LAB_005563dd;
LAB_0055619d:
      iVar7 = iVar3;
      pbVar5 = pbVar6;
    }
    goto LAB_005560c1;
  case 1:
    if (('0' < (char)bVar4) && (local_14 = iVar3, (char)bVar4 < ':')) goto LAB_005560de;
    local_14 = iVar3;
    if (bVar4 == DAT_00576cf4) goto LAB_005561f8;
    if ((bVar4 == 0x2b) || (bVar4 == 0x2d)) goto LAB_00556172;
    if (bVar4 == 0x30) goto LAB_0055619d;
    goto LAB_0055614b;
  case 2:
    if (('0' < (char)bVar4) && ((char)bVar4 < ':')) goto LAB_005560de;
    if (bVar4 != DAT_00576cf4) {
      if (bVar4 == 0x30) goto LAB_0055619d;
      goto LAB_00556352;
    }
LAB_005560ed:
    iVar7 = 5;
    break;
  case 3:
    local_14 = iVar3;
    while( true ) {
      if (DAT_00576cf0 < 2) {
        uVar1 = (byte)PTR_DAT_00576ae4[(uint)bVar4 * 2] & 4;
        this = PTR_DAT_00576ae4;
      }
      else {
        pbVar5 = (byte *)0x4;
        uVar1 = CRT_Mbtowc(this,(uint)bVar4,4);
        this = pbVar5;
      }
      if (uVar1 == 0) break;
      if (local_8 < 0x19) {
        local_8 = local_8 + 1;
        pcVar2 = local_10 + 1;
        *local_10 = bVar4 - 0x30;
        local_10 = pcVar2;
      }
      else {
        local_c = local_c + 1;
      }
      bVar4 = *pbVar6;
      pbVar6 = pbVar6 + 1;
    }
    if (bVar4 != DAT_00576cf4) goto LAB_0055625f;
LAB_005561f8:
    iVar7 = 4;
    pbVar5 = pbVar6;
    goto LAB_005560c1;
  case 4:
    local_28 = iVar3;
    local_14 = iVar3;
    if (local_8 == 0) {
      while (bVar4 == 0x30) {
        local_c = local_c + -1;
        bVar4 = *pbVar6;
        pbVar6 = pbVar6 + 1;
      }
    }
    while( true ) {
      if (DAT_00576cf0 < 2) {
        uVar1 = (byte)PTR_DAT_00576ae4[(uint)bVar4 * 2] & 4;
        this = PTR_DAT_00576ae4;
      }
      else {
        pbVar5 = (byte *)0x4;
        uVar1 = CRT_Mbtowc(this,(uint)bVar4,4);
        this = pbVar5;
      }
      if (uVar1 == 0) break;
      if (local_8 < 0x19) {
        local_8 = local_8 + 1;
        local_c = local_c + -1;
        pcVar2 = local_10 + 1;
        *local_10 = bVar4 - 0x30;
        local_10 = pcVar2;
      }
      bVar4 = *pbVar6;
      pbVar6 = pbVar6 + 1;
    }
LAB_0055625f:
    if ((bVar4 == 0x2b) || (bVar4 == 0x2d)) {
LAB_00556172:
      pbVar6 = pbVar6 + -1;
      iVar7 = 0xb;
    }
    else {
LAB_0055614b:
      if (((char)bVar4 < 'D') ||
         (('E' < (char)bVar4 && (((char)bVar4 < 'd' || ('e' < (char)bVar4)))))) goto LAB_005563dd;
      iVar7 = 6;
    }
    break;
  case 5:
    if (DAT_00576cf0 < 2) {
      uVar1 = (byte)PTR_DAT_00576ae4[(uint)bVar4 * 2] & 4;
      this = PTR_DAT_00576ae4;
      local_28 = iVar3;
    }
    else {
      pbVar5 = (byte *)0x4;
      local_28 = iVar3;
      uVar1 = CRT_Mbtowc(this,(uint)bVar4,4);
      this = pbVar5;
    }
    if (uVar1 != 0) {
      iVar7 = 4;
      goto LAB_00556303;
    }
LAB_00556352:
    pbVar6 = param_3;
    goto LAB_005563e2;
  case 6:
    this = pbVar5 + -1;
    param_3 = this;
    if (('0' < (char)bVar4) && ((char)bVar4 < ':')) goto LAB_00556300;
    if (bVar4 == 0x2b) goto LAB_00556338;
    if (bVar4 == 0x2d) goto LAB_0055632c;
    if (bVar4 != 0x30) goto LAB_005563e0;
LAB_005562d1:
    iVar7 = 8;
    break;
  case 7:
    if (((char)bVar4 < '1') || ('9' < (char)bVar4)) {
      if (bVar4 == 0x30) goto LAB_005562d1;
      goto LAB_00556352;
    }
    goto LAB_00556300;
  case 8:
    while (bVar4 == 0x30) {
      bVar4 = *pbVar6;
      pbVar6 = pbVar6 + 1;
    }
    local_24 = iVar3;
    if (((char)bVar4 < '1') || ('9' < (char)bVar4)) goto LAB_005563dd;
LAB_00556300:
    iVar7 = 9;
LAB_00556302:
LAB_00556303:
    pbVar5 = pbVar6 + -1;
    goto LAB_005560c1;
  case 9:
    local_24 = 1;
    pbVar5 = (byte *)0x0;
    goto LAB_00556363;
  default:
    goto switchD_005560cd_caseD_a;
  case 0xb:
    if (param_7 != 0) {
      param_3 = pbVar5;
      if (bVar4 == 0x2b) {
LAB_00556338:
        iVar7 = 7;
        this = param_3;
        break;
      }
      if (bVar4 != 0x2d) {
LAB_005563e0:
        pbVar6 = param_3;
        goto LAB_005563e2;
      }
LAB_0055632c:
      local_1c = -1;
      iVar7 = 7;
      this = param_3;
      pbVar5 = pbVar6;
      goto LAB_005560c1;
    }
    iVar7 = 10;
    pbVar6 = pbVar5;
switchD_005560cd_caseD_a:
    pbVar5 = pbVar6;
    if (iVar7 == 10) goto LAB_005563e2;
    goto LAB_005560c1;
  }
  pbVar5 = pbVar6;
  goto LAB_005560c1;
LAB_00556363:
  if (DAT_00576cf0 < 2) {
    uVar1 = (byte)PTR_DAT_00576ae4[(uint)bVar4 * 2] & 4;
    this = PTR_DAT_00576ae4;
  }
  else {
    pbVar8 = (byte *)0x4;
    uVar1 = CRT_Mbtowc(this,(uint)bVar4,4);
    this = pbVar8;
  }
  if (uVar1 == 0) goto LAB_005563aa;
  this = (void *)(int)(char)bVar4;
  pbVar5 = (byte *)((int)this + (int)pbVar5 * 10 + -0x30);
  if (0x1450 < (int)pbVar5) goto LAB_005563a5;
  bVar4 = *pbVar6;
  pbVar6 = pbVar6 + 1;
  goto LAB_00556363;
LAB_005563a5:
  pbVar5 = (byte *)0x1451;
LAB_005563aa:
  local_20 = pbVar5;
  while( true ) {
    if (DAT_00576cf0 < 2) {
      uVar1 = (byte)PTR_DAT_00576ae4[(uint)bVar4 * 2] & 4;
      this = PTR_DAT_00576ae4;
    }
    else {
      pbVar5 = (byte *)0x4;
      uVar1 = CRT_Mbtowc(this,(uint)bVar4,4);
      this = pbVar5;
    }
    if (uVar1 == 0) break;
    bVar4 = *pbVar6;
    pbVar6 = pbVar6 + 1;
  }
LAB_005563dd:
  pbVar6 = pbVar6 + -1;
LAB_005563e2:
  *param_2 = (int)pbVar6;
  if (local_14 == 0) {
    local_44._0_2_ = 0;
    local_3a = 0;
    local_3e = (byte *)0x0;
    param_3 = (byte *)0x0;
    local_18 = 4;
    goto LAB_005564f0;
  }
  if (local_8 < 0x19) {
    pcVar2 = local_10;
  }
  else {
    if ('\x04' < local_49) {
      local_49 = local_49 + '\x01';
    }
    local_8 = 0x18;
    local_c = local_c + 1;
    pcVar2 = local_10 + -1;
  }
  if (local_8 == 0) {
    local_44._0_2_ = 0;
    local_3a = 0;
    local_3e = (byte *)0x0;
    param_3 = (byte *)0x0;
  }
  else {
    while (pcVar2 = pcVar2 + -1, *pcVar2 == '\0') {
      local_8 = local_8 - 1;
      local_c = local_c + 1;
    }
    FUN_00556cb7(local_60,local_8,&local_44);
    pbVar5 = local_20;
    if (local_1c < 0) {
      pbVar5 = (byte *)-(int)local_20;
    }
    pbVar5 = pbVar5 + local_c;
    if (local_24 == 0) {
      pbVar5 = pbVar5 + param_5;
    }
    if (local_28 == 0) {
      pbVar5 = pbVar5 + -param_6;
    }
    if ((int)pbVar5 < 0x1451) {
      if (-0x1451 < (int)pbVar5) {
        FUN_005574b1(&local_44,(uint)pbVar5,param_4);
        param_3 = (byte *)CONCAT22(uStack_40,local_44._2_2_);
        goto LAB_00556475;
      }
      local_34 = 1;
    }
    else {
      local_30 = 1;
    }
    local_3a = (ushort)param_3;
    local_3e = param_3;
    local_44._0_2_ = local_3a;
  }
LAB_00556475:
  if (local_30 == 0) {
    if (local_34 != 0) {
      local_44._0_2_ = 0;
      local_3a = 0;
      local_3e = (byte *)0x0;
      param_3 = (byte *)0x0;
      local_18 = 1;
    }
  }
  else {
    param_3 = (byte *)0x0;
    local_3a = 0x7fff;
    local_3e = (byte *)0x80000000;
    local_44._0_2_ = 0;
    local_18 = 2;
  }
LAB_005564f0:
  *(byte **)(param_1 + 3) = local_3e;
  *(byte **)(param_1 + 1) = param_3;
  param_1[5] = local_3a | (ushort)local_2c;
  *param_1 = (ushort)local_44;
  return local_18;
}

