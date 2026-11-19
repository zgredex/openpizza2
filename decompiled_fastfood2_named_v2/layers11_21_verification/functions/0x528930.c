// rea decompile_all
// name: FUN_00528930
// address: 0x528930
// body: available
// range: 0x528930-0x52913c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall
FUN_00528930(void *this,undefined4 param_1,int param_2,int param_3,int param_4,uint param_5,
            int param_6,char *param_7,undefined4 param_8,undefined4 *param_9)

{
  uint *puVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  void *pvVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  char *pcVar13;
  undefined1 uVar14;
  int local_250;
  uint local_24c;
  uint local_248;
  uint local_244;
  uint local_240;
  int local_23c;
  int local_238;
  int local_234;
  int local_230;
  int local_22c;
  int local_228;
  int local_224;
  int local_220;
  void *local_21c;
  void *local_218;
  char local_214 [260];
  char local_110 [260];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a849;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_218 = this;
  FUN_00520a80(this,param_1,param_3,param_4,param_6);
  *(undefined ***)this = &PTR_FUN_0055c78c;
  pvVar5 = *(void **)(param_6 + 0x134);
  local_4 = 0;
  if (param_9 != (undefined4 *)0x0) {
    *param_9 = 0;
  }
  local_250 = 0;
  do {
    *(undefined4 *)((int)this + local_250 * 0x44 + 0x120) = 0;
    *(undefined4 *)((int)this + local_250 * 0x44 + 0x1ec) = 0;
    local_250 = local_250 + 1;
  } while (local_250 < 3);
  *(undefined4 *)((int)this + 0x344) = 0;
  iVar8 = 0;
  do {
    local_250 = 0;
    do {
      *(undefined4 *)((int)this + (local_250 + iVar8) * 0x44 + 0x388) = 0;
      local_250 = local_250 + 1;
    } while (local_250 < 3);
    iVar8 = iVar8 + 3;
  } while (iVar8 < 6);
  uVar9 = 0xffffffff;
  do {
    pcVar4 = param_7;
    if (uVar9 == 0) break;
    uVar9 = uVar9 - 1;
    pcVar4 = param_7 + 1;
    cVar2 = *param_7;
    param_7 = pcVar4;
  } while (cVar2 != '\0');
  uVar9 = ~uVar9;
  pcVar4 = pcVar4 + -uVar9;
  pcVar13 = local_110;
  for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
    *(undefined4 *)pcVar13 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar13 = pcVar13 + 4;
  }
  for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
    *pcVar13 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar13 = pcVar13 + 1;
  }
  *(undefined4 *)((int)this + 0xc0) = param_8;
  *(undefined4 *)((int)this + 0x60) = 0;
  *(int *)((int)this + 0x54) = param_2;
  *(undefined4 *)((int)this + 0xb8) = 0;
  *(undefined4 *)((int)this + 0xbc) = 0;
  *(undefined4 *)((int)this + 0xa8) = 0;
  *(undefined4 *)((int)this + 0xc4) = 0;
  *(undefined4 *)((int)this + 0xcc) = 0;
  *(undefined4 *)((int)this + 0xd0) = 0xffffffff;
  *(undefined4 *)((int)this + 0x5c) = 0;
  *(undefined4 *)((int)this + 0x40) = 5;
  pcVar4 = _strrchr(local_110,0x5f);
  if (pcVar4 != (char *)0x0) {
    if (((('/' < pcVar4[1]) && (pcVar4[1] < ':')) && ('/' < pcVar4[2])) && (pcVar4[2] < ':')) {
      FUN_0054e157(pcVar4 + 1,(byte *)(pcVar4 + 1));
      *pcVar4 = '\0';
    }
  }
  local_250 = 0;
  do {
    FUN_0054dd83(local_214,(byte *)s__s__02d_spr_00573b9c,local_110);
    iVar8 = Window_LoadSpriteCached
                      (pvVar5,local_214,(undefined4 *)0x1,
                       (undefined4 *)((int)this + local_250 * 0x44 + 0x1ac));
    if (iVar8 == 0) goto LAB_00528d08;
    local_250 = local_250 + 1;
  } while (local_250 < 3);
  if (*(int *)((int)this + 0xc0) == 0) {
    FUN_0053d090(*(void **)((int)this + 0x1ec),&local_250,(int *)&local_24c);
    FUN_0053d090(*(void **)((int)this + 0x230),(int *)&local_248,(int *)&local_24c);
    local_250 = local_250 + local_248;
    FUN_0053d090(*(void **)((int)this + 0x274),(int *)&local_248,(int *)&local_24c);
    uVar9 = local_248;
  }
  else {
    FUN_0053d090(*(void **)((int)this + 0x1ec),(int *)&local_248,&local_250);
    FUN_0053d090(*(void **)((int)this + 0x230),(int *)&local_248,(int *)&local_24c);
    local_250 = local_250 + local_24c;
    FUN_0053d090(*(void **)((int)this + 0x274),(int *)&local_248,(int *)&local_24c);
    uVar9 = local_24c;
  }
  if ((int)param_5 < (int)(local_250 + uVar9)) {
    param_5 = local_250 + uVar9;
  }
  *(uint *)((int)this + 0xb4) = param_5;
  local_250 = 0;
  do {
    FUN_0054dd83(local_214,(byte *)s__s__02d_spr_00573b9c,local_110);
    iVar8 = Window_LoadSpriteCached
                      (pvVar5,local_214,(undefined4 *)0x1,
                       (undefined4 *)((int)this + local_250 * 0x44 + 0xe0));
    if (iVar8 == 0) {
LAB_00528d08:
      *param_9 = 2;
      ExceptionList = local_c;
      return this;
    }
    local_250 = local_250 + 1;
  } while (local_250 < 3);
  if (param_2 == 0) {
    local_250 = 0;
    do {
      FUN_0054dd83(local_214,(byte *)s__s__02d_spr_00573b9c,local_110);
      Window_LoadSpriteCached
                (pvVar5,local_214,(undefined4 *)(uint)(local_250 < 2),
                 (undefined4 *)((int)this + local_250 * 0x44 + 0x348));
      local_250 = local_250 + 1;
    } while (local_250 < 3);
  }
  *(undefined4 *)((int)this + 100) = 0xfffffc19;
  *(undefined4 *)((int)this + 0x68) = 0xfffffc19;
  *(undefined4 *)((int)this + 0x4f0) = 0;
  *(undefined4 *)((int)this + 0x4f4) = 0;
  FUN_0053d090(*(void **)((int)this + 0x1ec),(int *)&local_240,(int *)&local_244);
  FUN_0053d090(*(void **)((int)this + 0x230),(int *)&local_248,(int *)&local_24c);
  if (*(int *)((int)this + 0xc0) == 0) {
    if ((int)local_244 <= (int)local_24c) {
      local_244 = local_24c;
    }
  }
  else if ((int)local_240 <= (int)local_248) {
    local_240 = local_248;
  }
  *(uint *)((int)this + 200) = param_5;
  *(undefined4 *)((int)this + 0x9c) = 0;
  *(undefined4 *)((int)this + 0x94) = 0;
  *(undefined4 *)((int)this + 0xa0) = 100;
  *(undefined4 *)((int)this + 0x98) = 100;
  *(undefined4 *)((int)this + 0x58) = 0;
  FUN_0052a3a0(this,0,0);
  FUN_0052a3a0(this,0,1);
  FUN_0053d090(*(void **)((int)this + 0x274),(int *)&local_248,(int *)&local_24c);
  if (*(int *)((int)this + 0xc0) == 0) {
    local_240 = param_5;
    if ((int)local_244 <= (int)local_24c) {
      local_244 = local_24c;
    }
  }
  else {
    if ((int)local_240 <= (int)local_248) {
      local_240 = local_248;
    }
    local_244 = param_5;
  }
  pvVar5 = operator_new(0x50);
  local_4._0_1_ = 1;
  local_21c = pvVar5;
  if (pvVar5 == (void *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    uVar14 = 2;
    iVar8 = 0x10;
    uVar9 = FUN_005397e0(DAT_0057c5c8,0,0xff,0);
    puVar6 = FUN_0053c710(pvVar5,local_240,local_244,uVar9,iVar8,uVar14);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  *(undefined4 **)((int)this + 0x344) = puVar6;
  *(undefined4 *)((int)this + 0xd4) = 0xffff;
  *(undefined4 *)((int)this + 0xd8) = 0xffffff;
  *(undefined4 *)((int)this + 0xdc) = 0xff0000;
  FUN_0052a440((int)this);
  if (*(int *)((int)this + 0xa8) == 999999) {
    *(undefined4 *)((int)this + 0xa8) = 0;
  }
  FUN_0053d090(*(void **)((int)this + 0x230),&local_220,&local_224);
  if (*(int *)((int)this + 0xc0) == 0) {
    *(int *)((int)this + 0x4f0) = -*(int *)((int)this + 0xa8);
    FUN_0053d100(*(void **)((int)this + 0x1ec),(int *)&local_248,(int *)&local_24c);
    local_248 = 0;
    *(int *)((int)this + 0x4f4) = -(local_224 / 2);
  }
  else {
    *(int *)((int)this + 0x4f0) = -(local_220 / 2);
    FUN_0053d100(*(void **)((int)this + 0x1ec),(int *)&local_248,(int *)&local_24c);
    local_24c = 0;
    *(int *)((int)this + 0x4f4) = -*(int *)((int)this + 0xa8);
  }
  *(uint *)((int)this + 0x28) = *(int *)((int)this + 0x28) + local_248 + *(int *)((int)this + 0x4f0)
  ;
  *(uint *)((int)this + 0x2c) = *(int *)((int)this + 0x2c) + *(int *)((int)this + 0x4f4) + local_24c
  ;
  FUN_00529160((int)this);
  FUN_00520b40(this,local_240,local_244);
  *(undefined4 *)((int)this + 0x88) = 0;
  *(undefined4 *)((int)this + 0x84) = 0;
  if (*(int *)((int)this + 0x388) == 0) {
    ExceptionList = local_c;
    return this;
  }
  local_250 = 0;
  iVar8 = local_234;
  iVar12 = local_230;
  do {
    pvVar5 = *(void **)((int)this + local_250 * 0x44 + 0x388);
    if (pvVar5 != (void *)0x0) {
      FUN_0053d090(pvVar5,(int *)&local_248,(int *)&local_24c);
      FUN_0053d100(*(void **)((int)this + local_250 * 0x44 + 0x388),&local_228,&local_22c);
      if (local_250 == 0) {
        local_23c = local_228;
        local_238 = local_22c;
        iVar8 = local_228 + local_248;
        iVar12 = local_22c + local_24c;
      }
      else {
        if (local_228 < local_23c) {
          local_23c = local_228;
        }
        if (local_22c < local_238) {
          local_238 = local_22c;
        }
        if (iVar8 < (int)(local_228 + local_248)) {
          iVar8 = local_228 + local_248;
        }
        if (iVar12 < (int)(local_24c + local_22c)) {
          iVar12 = local_24c + local_22c;
        }
      }
    }
    local_250 = local_250 + 1;
  } while (local_250 < 3);
  puVar1 = (uint *)((int)this + 0xb0);
  local_234 = iVar8;
  local_230 = iVar12;
  FUN_0053d040(*(void **)((int)this + 0x388),(uint *)((int)this + 0xac),puVar1);
  FUN_0053d040(*(void **)((int)this + 0x1ec),&local_248,&local_24c);
  uVar9 = *(uint *)((int)this + 0xac);
  if (*(int *)((int)this + 0xc0) == 0) {
    *(int *)((int)this + 0x84) = -(((int)(local_248 - uVar9) >> 1) + *(int *)((int)this + 0x4f0));
    iVar8 = (int)(local_24c - *puVar1) >> 1;
  }
  else {
    *(int *)((int)this + 0x84) = -((int)(local_248 - uVar9) >> 1);
    iVar8 = ((int)(local_24c - *puVar1) >> 1) + *(int *)((int)this + 0x4f4);
  }
  *(int *)((int)this + 0x88) = -iVar8;
  if (*(int *)((int)this + 0xc0) == 0) {
    iVar12 = *(int *)((int)this + 0x84);
    iVar8 = *(int *)((int)this + 0x28);
    local_234 = (*(int *)((int)this + 0xa4) - iVar12) + iVar8 + local_234;
    iVar11 = *(int *)((int)this + 0x30);
    if (local_234 <= *(int *)((int)this + 0x30)) {
LAB_005290aa:
      local_234 = iVar11;
    }
  }
  else {
    iVar8 = *(int *)((int)this + 0x28);
    iVar12 = *(int *)((int)this + 0x84);
    local_234 = (iVar8 - iVar12) + local_234;
    iVar11 = *(int *)((int)this + 0x30);
    if (local_234 <= *(int *)((int)this + 0x30)) goto LAB_005290aa;
  }
  *(int *)((int)this + 0x30) = local_234;
  if (*(int *)((int)this + 0xc0) == 0) {
    iVar7 = *(int *)((int)this + 0x2c);
    iVar11 = *(int *)((int)this + 0x88);
    local_230 = (iVar7 - iVar11) + local_230;
    iVar3 = *(int *)((int)this + 0x34);
    if (*(int *)((int)this + 0x34) < local_230) goto LAB_005290f7;
  }
  else {
    iVar11 = *(int *)((int)this + 0x88);
    iVar7 = *(int *)((int)this + 0x2c);
    local_230 = (*(int *)((int)this + 0xa4) - iVar11) + iVar7 + local_230;
    iVar3 = *(int *)((int)this + 0x34);
    if (*(int *)((int)this + 0x34) < local_230) goto LAB_005290f7;
  }
  local_230 = iVar3;
LAB_005290f7:
  *(int *)((int)this + 0x34) = local_230;
  local_23c = (iVar8 - iVar12) + local_23c;
  if (local_23c < iVar8) {
    iVar8 = local_23c;
  }
  *(int *)((int)this + 0x28) = iVar8;
  local_238 = local_238 + (iVar7 - iVar11);
  if (local_238 < iVar7) {
    iVar7 = local_238;
  }
  *(int *)((int)this + 0x2c) = iVar7;
  ExceptionList = local_c;
  return this;
}

