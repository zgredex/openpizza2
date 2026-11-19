// rea decompile_all
// name: FUN_0052d360
// address: 0x52d360
// body: available
// range: 0x52d360-0x52d688 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall
FUN_0052d360(void *this,undefined4 param_1,int param_2,int param_3,char *param_4,char *param_5,
            char *param_6,int param_7,int param_8,int *param_9)

{
  char cVar1;
  char *pcVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  void *this_00;
  int iVar9;
  char *pcVar10;
  uint local_230;
  int local_22c;
  void *local_228;
  int local_224;
  undefined4 *local_220;
  undefined4 local_21c;
  void *local_218;
  char local_214 [260];
  char local_110 [260];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a90b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_218 = this;
  FUN_00520a80(this,param_1,param_2,param_3,param_8);
  *(undefined ***)this = &PTR_FUN_0055c7e8;
  pvVar3 = *(void **)(param_8 + 0x134);
  *(undefined4 *)((int)this + 0x40) = 2;
  *param_9 = 0;
  local_4 = 0;
  *(undefined4 *)((int)this + 0x3c0) = 0;
  *(undefined4 *)((int)this + 0x3c4) = 0;
  *(undefined4 *)((int)this + 0x3ac) = 0;
  if (param_7 == 0) {
    *(undefined4 *)((int)this + 0x3a8) = 0;
  }
  else {
    *(undefined4 *)((int)this + 0x3a8) = 1;
  }
  uVar6 = 0xffffffff;
  *(undefined4 *)((int)this + 0x38c) = 0xd0d0d0;
  *(undefined4 *)((int)this + 0x390) = 0xffffff;
  *(undefined4 *)((int)this + 0x394) = 0xffff00;
  pcVar2 = param_5;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  local_228 = pvVar3;
  pcVar2 = operator_new(~uVar6);
  uVar6 = 0xffffffff;
  *(char **)((int)this + 0x58) = pcVar2;
  do {
    pcVar10 = param_5;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar10 = param_5 + 1;
    cVar1 = *param_5;
    param_5 = pcVar10;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  pcVar10 = pcVar10 + -uVar6;
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pcVar2 = *(undefined4 *)pcVar10;
    pcVar10 = pcVar10 + 4;
    pcVar2 = pcVar2 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar2 = *pcVar10;
    pcVar10 = pcVar10 + 1;
    pcVar2 = pcVar2 + 1;
  }
  *(undefined4 *)((int)this + 0x3b0) = 0;
  *(undefined4 *)((int)this + 0x3b4) = 0;
  *(undefined4 *)((int)this + 0x3b8) = 0;
  *(undefined4 *)((int)this + 0x3bc) = 0;
  pvVar3 = (void *)FUN_00527090(pvVar3,param_4);
  *(void **)((int)this + 0x54) = pvVar3;
  *(undefined4 *)((int)this + 0x398) = 0;
  *(undefined4 *)((int)this + 0x3b8) = 0;
  if (pvVar3 == (void *)0x0) {
    uVar6 = 0xffffffff;
    local_224 = 0x10;
    pcVar2 = *(char **)((int)this + 0x58);
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    iVar4 = (~uVar6 - 1) * 0xc;
    *(int *)((int)this + 0x3a4) = iVar4;
  }
  else {
    iVar4 = FUN_005355f0(pvVar3,*(char **)((int)this + 0x58));
    *(int *)((int)this + 0x3a4) = iVar4;
    local_224 = *(int *)(*(int *)((int)this + 0x54) + 0x9b0);
  }
  iVar5 = local_224;
  puVar8 = (undefined4 *)((int)this + 0x9c);
  iVar9 = 0xc;
  do {
    *puVar8 = 0;
    puVar8 = puVar8 + 0x11;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  if (param_6 == (char *)0x0) {
    *(short *)((int)this + 0x3b0) = (short)iVar4;
    *(short *)((int)this + 0x3b2) = (short)local_224;
    FUN_00520b40(this,iVar4,local_224);
  }
  else {
    uVar6 = 0xffffffff;
    do {
      pcVar2 = param_6;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar2 = param_6 + 1;
      cVar1 = *param_6;
      param_6 = pcVar2;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    pcVar2 = pcVar2 + -uVar6;
    pcVar10 = local_214;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar10 = *(undefined4 *)pcVar2;
      pcVar2 = pcVar2 + 4;
      pcVar10 = pcVar10 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar10 = *pcVar2;
      pcVar2 = pcVar2 + 1;
      pcVar10 = pcVar10 + 1;
    }
    local_21c = 0;
    pcVar2 = _strrchr(local_214,0x5f);
    if (pcVar2 != (char *)0x0) {
      local_21c = FUN_0054e157(this_00,(byte *)(pcVar2 + 1));
      *pcVar2 = '\0';
    }
    local_22c = 0;
    local_230 = 4 - (*(int *)((int)this + 0x3a8) != 1);
    if (0 < (int)local_230) {
      local_220 = (undefined4 *)((int)this + 0x5c);
      do {
        iVar4 = 0;
        puVar8 = local_220;
        do {
          String_Format(local_110,(byte *)s__s__02d_spr_00573b9c,local_214);
          iVar5 = FUN_00527580(local_228,local_110,(undefined4 *)0x1,puVar8);
          if (iVar5 == 0) {
            *param_9 = 2;
            ExceptionList = local_c;
            return this;
          }
          iVar4 = iVar4 + 1;
          puVar8 = puVar8 + 0x11;
        } while (iVar4 < 3);
        local_22c = local_22c + 1;
        local_220 = local_220 + 0x33;
      } while (local_22c < (int)local_230);
      iVar5 = local_224;
    }
    if (*param_9 == 0) {
      FUN_0053d040(*(void **)((int)this + 0x9c),(uint *)&local_228,&local_230);
      *(void **)((int)this + 0x39c) = local_228;
      *(int *)((int)this + 0x3a0) = (int)(local_230 - iVar5) >> 1;
      FUN_0052e230(this);
      *(short *)((int)this + 0x3b0) = *(short *)((int)this + 0x30) - *(short *)((int)this + 0x28);
      *(short *)((int)this + 0x3b2) = *(short *)((int)this + 0x34) - *(short *)((int)this + 0x2c);
    }
  }
  ExceptionList = local_c;
  return this;
}

