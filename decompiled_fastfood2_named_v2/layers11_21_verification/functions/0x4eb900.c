// rea decompile_all
// name: FUN_004eb900
// address: 0x4eb900
// body: available
// range: 0x4eb900-0x4ec4e4 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004eb900(void *this,void *param_1)

{
  int *piVar1;
  char cVar2;
  byte bVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  byte *pbVar11;
  char *pcVar12;
  char *pcVar13;
  bool bVar14;
  int local_240;
  int local_23c;
  uint local_238;
  byte *local_234;
  byte *local_230;
  undefined1 local_229;
  int local_228;
  void *local_224;
  int local_220;
  int local_21c;
  int local_218;
  undefined1 local_214 [4];
  undefined4 local_210;
  char local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00559fec;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0054cbc1(param_1,local_214,4);
  FUN_0054cbc1(param_1,&local_218,4);
  FUN_0054cbc1(param_1,(int)this + 0xc,4);
  FUN_0054cbc1(param_1,(int)this + 0x10,4);
  FUN_0054cbc1(param_1,(int)this + 0x14,4);
  FUN_0054cbc1(param_1,(int)this + 0x18,4);
  piVar1 = (int *)((int)this + 0x1c);
  FUN_0054cbc1(param_1,piVar1,4);
  FUN_0054cbc1(param_1,(int)this + 0x20,4);
  FUN_0054cbc1(param_1,(undefined4 *)((int)this + 0x24),4);
  FUN_0054cbc1(param_1,(int)this + 0x28,4);
  *(undefined4 *)((int)this + 0xe8) = *(undefined4 *)((int)this + 0x24);
  *(undefined4 *)((int)this + 0xec) = *(undefined4 *)((int)this + 0x28);
  FUN_0054cbc1(param_1,(int)this + 0x2c,4);
  FUN_0054cbc1(param_1,(int)this + 0x30,4);
  FUN_0054cbc1(param_1,(int)this + 0x34,4);
  FUN_0054cbc1(param_1,(int)this + 0x38,4);
  FUN_0054cbc1(param_1,(undefined4 *)((int)this + 0x3c),0x10);
  *(undefined4 *)((int)this + 0x3c) = 1;
  *(undefined4 *)((int)this + 0x40) = 1;
  *(undefined4 *)((int)this + 0x44) = 0;
  *(undefined4 *)((int)this + 0x48) = 0;
  FUN_0054cbc1(param_1,(int)this + 0x60,4);
  *(undefined4 *)((int)this + 0x60) = 0;
  FUN_0054cbc1(param_1,(int)this + 0x6c,4);
  FUN_0054cbc1(param_1,(int)this + 0x7c,0x1e);
  FUN_0054cbc1(param_1,(int)this + 0xba,2);
  FUN_0054cbc1(param_1,(int)this + 0xf0,4);
  pvVar4 = operator_new(*(int *)((int)this + 0x20) * *piVar1 * 0xc);
  *(void **)((int)this + 0x4c) = pvVar4;
  pvVar4 = operator_new(0xc);
  *(void **)((int)this + 100) = pvVar4;
  pvVar4 = operator_new(0x3c);
  *(void **)(*(int *)((int)this + 100) + 8) = pvVar4;
  iVar5 = *(int *)((int)this + 0x20) * *piVar1;
  *(int *)((int)this + 0x13c) = iVar5;
  pvVar4 = operator_new(iVar5 * 0x3c);
  *(void **)((int)this + 0x138) = pvVar4;
  *(undefined4 *)((int)this + 0x58) = 0xffffffff;
  *(undefined4 *)((int)this + 0x5c) = 0xffffffff;
  local_234 = (byte *)0x0;
  *(undefined4 *)((int)this + 0x50) = 0;
  *(undefined4 *)((int)this + 0x54) = 0;
  *(undefined4 *)((int)this + 0x68) = 0;
  *(undefined4 *)((int)this + 0xac) = 0xffff;
  *(undefined1 *)((int)this + 0xb8) = 0;
  *(undefined4 *)((int)this + 0xbc) = 0;
  *(undefined4 *)((int)this + 0xf4) = 1;
  *(undefined4 *)((int)this + 0xf8) = 0xa0;
  *(undefined4 *)((int)this + 0xfc) = 0xd0;
  InitializeCriticalSection((LPCRITICAL_SECTION)((int)this + 0xc0));
  FUN_004ed010((int)this);
  FUN_004ed040((int)this);
  *(undefined4 *)((int)this + 0x9c) = 0;
  *(undefined4 *)((int)this + 0xa0) = 0;
  pvVar4 = operator_new(0x28);
  piVar1 = (int *)((int)this + 0xa4);
  *(void **)((int)this + 0xb0) = pvVar4;
  *(undefined4 *)((int)this + 0xb4) = 0;
  FUN_0054cbc1(param_1,piVar1,4);
  FUN_0054cbc1(param_1,(int)this + 0xa8,4);
  if (0 < *piVar1) {
    pvVar4 = operator_new(*piVar1 * 0x28);
    *(void **)((int)this + 0x9c) = pvVar4;
  }
  if (0 < *(int *)((int)this + 0xa8)) {
    pvVar4 = operator_new(*(int *)((int)this + 0xa8) * 0x28);
    *(void **)((int)this + 0xa0) = pvVar4;
  }
  local_23c = 0;
  if (0 < *piVar1) {
    iVar5 = 0;
    do {
      FUN_0054cbc1(param_1,*(int *)((int)this + 0x9c) + iVar5,1);
      FUN_0054cbc1(param_1,*(int *)((int)this + 0x9c) + 2 + iVar5,2);
      *(undefined2 *)(*(int *)((int)this + 0x9c) + 4 + iVar5) = (undefined2)local_23c;
      FUN_0054cbc1(param_1,*(int *)((int)this + 0x9c) + 6 + iVar5,1);
      FUN_0054cbc1(param_1,&local_229,1);
      FUN_0054cbc1(param_1,*(int *)((int)this + 0x9c) + 8 + iVar5,4);
      FUN_0054cbc1(param_1,*(int *)((int)this + 0x9c) + 0xc + iVar5,4);
      FUN_0054cbc1(param_1,*(int *)((int)this + 0x9c) + 0x10 + iVar5,4);
      FUN_0054cbc1(param_1,*(int *)((int)this + 0x9c) + 0x14 + iVar5,0x10);
      FUN_0054cbc1(param_1,*(int *)((int)this + 0x9c) + 0x24 + iVar5,1);
      iVar5 = iVar5 + 0x28;
      *(undefined1 *)(*(int *)((int)this + 0x9c) + -0x28 + iVar5) = 0;
      local_23c = local_23c + 1;
    } while (local_23c < *(int *)((int)this + 0xa4));
  }
  local_23c = 0;
  if (0 < *(int *)((int)this + 0xa8)) {
    iVar5 = 0;
    do {
      FUN_0054cbc1(param_1,iVar5 + *(int *)((int)this + 0xa0),1);
      FUN_0054cbc1(param_1,iVar5 + 2 + *(int *)((int)this + 0xa0),2);
      *(undefined2 *)(iVar5 + 4 + *(int *)((int)this + 0xa0)) = (undefined2)local_23c;
      FUN_0054cbc1(param_1,iVar5 + 6 + *(int *)((int)this + 0xa0),1);
      FUN_0054cbc1(param_1,&local_229,1);
      FUN_0054cbc1(param_1,iVar5 + 8 + *(int *)((int)this + 0xa0),4);
      FUN_0054cbc1(param_1,iVar5 + 0xc + *(int *)((int)this + 0xa0),4);
      FUN_0054cbc1(param_1,iVar5 + 0x10 + *(int *)((int)this + 0xa0),4);
      FUN_0054cbc1(param_1,iVar5 + 0x14 + *(int *)((int)this + 0xa0),0x10);
      FUN_0054cbc1(param_1,iVar5 + 0x24 + *(int *)((int)this + 0xa0),1);
      local_23c = local_23c + 1;
      *(undefined1 *)(iVar5 + *(int *)((int)this + 0xa0)) = 0;
      iVar5 = iVar5 + 0x28;
    } while (local_23c < *(int *)((int)this + 0xa8));
  }
  iVar5 = *(int *)((int)this + 0x20);
  iVar6 = 0;
  local_240 = 0;
  local_224 = (void *)0x0;
  if (0 < iVar5) {
    do {
      local_23c = (iVar5 - (int)local_224) * *(int *)((int)this + 0xc) >> 1;
      iVar5 = *(int *)((int)this + 0x10) * (int)local_224 >> 1;
      local_21c = 0;
      if (0 < *(int *)((int)this + 0x1c)) {
        local_230 = (byte *)((int)local_234 * 0x3c);
        do {
          *(byte **)(*(int *)((int)this + 0x4c) + 8 + iVar6 * 0xc) =
               local_230 + *(int *)((int)this + 0x138);
          local_234 = local_234 + 1;
          local_230 = local_230 + 0x3c;
          *(int *)(*(int *)((int)this + 0x4c) + local_240 * 0xc) = local_23c;
          *(int *)(*(int *)((int)this + 0x4c) + 4 + local_240 * 0xc) = iVar5;
          **(int **)(*(int *)((int)this + 0x4c) + 8 + local_240 * 0xc) = local_240;
          *(undefined4 *)(*(int *)(*(int *)((int)this + 0x4c) + 8 + local_240 * 0xc) + 0x20) = 0;
          *(undefined2 *)(*(int *)(*(int *)((int)this + 0x4c) + 8 + local_240 * 0xc) + 0x24) =
               0xffff;
          *(undefined4 *)(*(int *)(*(int *)((int)this + 0x4c) + 8 + local_240 * 0xc) + 0x28) = 0;
          *(undefined1 *)(*(int *)(*(int *)((int)this + 0x4c) + 8 + local_240 * 0xc) + 0x2c) = 0;
          *(undefined1 *)(*(int *)(*(int *)((int)this + 0x4c) + 8 + local_240 * 0xc) + 0x2d) = 0;
          *(undefined1 *)(*(int *)(*(int *)((int)this + 0x4c) + 8 + local_240 * 0xc) + 0x2e) = 0;
          *(undefined1 *)(*(int *)(*(int *)((int)this + 0x4c) + 8 + local_240 * 0xc) + 0x2f) = 0;
          *(undefined4 *)(*(int *)(*(int *)((int)this + 0x4c) + 8 + local_240 * 0xc) + 0x30) =
               0xffffffff;
          *(undefined4 *)(*(int *)(*(int *)((int)this + 0x4c) + 8 + local_240 * 0xc) + 0x34) = 0;
          *(undefined4 *)(*(int *)(*(int *)((int)this + 0x4c) + 8 + local_240 * 0xc) + 0x38) = 0;
          *(undefined4 *)(*(int *)(*(int *)((int)this + 0x4c) + 8 + local_240 * 0xc) + 0xc) = 0;
          *(undefined4 *)(*(int *)(*(int *)((int)this + 0x4c) + 8 + local_240 * 0xc) + 0x18) = 0;
          *(undefined4 *)(*(int *)(*(int *)((int)this + 0x4c) + 8 + local_240 * 0xc) + 8) = 0;
          *(undefined4 *)(*(int *)(*(int *)((int)this + 0x4c) + 8 + local_240 * 0xc) + 0x14) = 0;
          *(undefined4 *)(*(int *)(*(int *)((int)this + 0x4c) + 8 + local_240 * 0xc) + 4) =
               0xffffffff;
          *(undefined4 *)(*(int *)(*(int *)((int)this + 0x4c) + 8 + local_240 * 0xc) + 0x10) =
               0xffffffff;
          *(undefined4 *)(*(int *)(*(int *)((int)this + 0x4c) + 8 + local_240 * 0xc) + 0x1c) =
               0xffffffff;
          local_23c = local_23c + (*(int *)((int)this + 0xc) >> 1);
          iVar5 = iVar5 + (*(int *)((int)this + 0x10) >> 1);
          iVar6 = local_240 + 1;
          local_21c = local_21c + 1;
          local_240 = iVar6;
        } while (local_21c < *(int *)((int)this + 0x1c));
      }
      iVar5 = *(int *)((int)this + 0x20);
      local_224 = (void *)((int)local_224 + 1);
    } while ((int)local_224 < iVar5);
  }
  local_23c = 0;
  if (0 < *(int *)((int)this + 0x20) * *(int *)((int)this + 0x1c)) {
    do {
      iVar5 = local_23c;
      FUN_0054cbc1(param_1,&local_228,4);
      if (local_228 == 1) {
        FUN_0054cbc1(param_1,&local_240,4);
        local_23c = iVar5 + local_240;
      }
      else {
        iVar5 = iVar5 * 0xc;
        FUN_0054cbc1(param_1,*(undefined4 *)(iVar5 + 8 + *(int *)((int)this + 0x4c)),4);
        FUN_0054cbc1(param_1,*(int *)(iVar5 + 8 + *(int *)((int)this + 0x4c)) + 0x24,2);
        FUN_0054cbc1(param_1,*(int *)(iVar5 + 8 + *(int *)((int)this + 0x4c)) + 0x30,4);
        FUN_0054cbc1(param_1,*(int *)(iVar5 + 8 + *(int *)((int)this + 0x4c)) + 0x34,4);
        FUN_0054cbc1(param_1,*(int *)(iVar5 + 8 + *(int *)((int)this + 0x4c)) + 0x38,4);
        iVar6 = *(int *)(iVar5 + 8 + *(int *)((int)this + 0x4c));
        *(uint *)(iVar6 + 0x38) = (uint)(*(int *)(iVar6 + 0x38) == 1);
        FUN_0054cbc1(param_1,*(int *)(iVar5 + 8 + *(int *)((int)this + 0x4c)) + 0x28,4);
        FUN_0054cbc1(param_1,*(int *)(iVar5 + 8 + *(int *)((int)this + 0x4c)) + 0x1c,4);
        FUN_0054cbc1(param_1,*(int *)(iVar5 + 8 + *(int *)((int)this + 0x4c)) + 0x2c,1);
        FUN_0054cbc1(param_1,*(int *)(iVar5 + 8 + *(int *)((int)this + 0x4c)) + 0x2d,1);
        FUN_0054cbc1(param_1,*(int *)(iVar5 + 8 + *(int *)((int)this + 0x4c)) + 0x2e,1);
        FUN_0054cbc1(param_1,*(int *)(iVar5 + 8 + *(int *)((int)this + 0x4c)) + 0x2f,1);
        FUN_0054cbc1(param_1,&local_238,4);
        local_238 = FUN_004eaa10(*(void **)((int)this + 4),local_238);
        if ((local_218 == 0) && (-1 < (int)local_238)) {
          FUN_0054cbc1(param_1,&local_210,0x32);
          local_234 = (byte *)(*(int *)((int)this + 4) + 0x25 + local_238 * 0x48);
          local_230 = (byte *)&local_210;
          do {
            bVar3 = *local_230;
            bVar14 = bVar3 < *local_234;
            if (bVar3 != *local_234) {
LAB_004ec16e:
              iVar6 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
              goto LAB_004ec173;
            }
            if (bVar3 == 0) break;
            bVar3 = local_230[1];
            bVar14 = bVar3 < local_234[1];
            if (bVar3 != local_234[1]) goto LAB_004ec16e;
            local_230 = local_230 + 2;
            local_234 = local_234 + 2;
          } while (bVar3 != 0);
          iVar6 = 0;
LAB_004ec173:
          if (iVar6 != 0) {
            uVar9 = FUN_004eab80(*(void **)((int)this + 4),&local_210);
            local_238 = (uint)(short)uVar9;
            if (local_238 == 0xffffffff) {
              local_238 = FUN_004eb8e0();
            }
          }
        }
        *(uint *)(*(int *)(iVar5 + 8 + *(int *)((int)this + 0x4c)) + 4) = local_238;
        FUN_004eef40(this,local_238,*(int *)(iVar5 + 8 + *(int *)((int)this + 0x4c)) + 4);
        FUN_0054cbc1(param_1,&local_238,4);
        local_238 = FUN_004eaa10(*(void **)((int)this + 4),local_238);
        if ((local_218 == 0) && (-1 < (int)local_238)) {
          FUN_0054cbc1(param_1,&local_210,0x32);
          local_234 = (byte *)(*(int *)((int)this + 4) + 0x25 + local_238 * 0x48);
          pbVar11 = (byte *)&local_210;
          do {
            bVar3 = *pbVar11;
            bVar14 = bVar3 < *local_234;
            if (bVar3 != *local_234) {
LAB_004ec256:
              iVar6 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
              goto LAB_004ec25b;
            }
            if (bVar3 == 0) break;
            bVar3 = pbVar11[1];
            bVar14 = bVar3 < local_234[1];
            if (bVar3 != local_234[1]) goto LAB_004ec256;
            pbVar11 = pbVar11 + 2;
            local_234 = local_234 + 2;
          } while (bVar3 != 0);
          iVar6 = 0;
LAB_004ec25b:
          if (iVar6 != 0) {
            uVar9 = FUN_004eab80(*(void **)((int)this + 4),&local_210);
            local_238 = (uint)(short)uVar9;
            if (local_238 == 0xffffffff) {
              local_238 = FUN_004eb8e0();
            }
          }
        }
        *(uint *)(*(int *)(iVar5 + 8 + *(int *)((int)this + 0x4c)) + 0x10) = local_238;
        FUN_004eef40(this,local_238,*(int *)(iVar5 + 8 + *(int *)((int)this + 0x4c)) + 0x10);
        local_23c = local_23c + 1;
      }
    } while (local_23c < *(int *)((int)this + 0x20) * *(int *)((int)this + 0x1c));
  }
  *(undefined4 *)((int)this + 0x118) = 0;
  FUN_0054cbc1(param_1,&local_228,4);
  if (local_228 == 1) {
    FUN_0054cbc1(param_1,&local_228,4);
    pvVar4 = operator_new(local_228 * 4 + 4);
    iVar5 = 0;
    *(void **)((int)this + 0x118) = pvVar4;
    if (0 < local_228 + 1) {
      do {
        FUN_0054cbc1(param_1,*(int *)((int)this + 0x118) + iVar5 * 4,4);
        iVar5 = iVar5 + 1;
      } while (iVar5 < local_228 + 1);
    }
  }
  if (*(int *)((int)this + 0x6c) == 0) {
    *(undefined4 *)((int)this + 0x70) = 0;
  }
  else if (*(int *)((int)this + 0xc) == 0x10) {
    pcVar7 = _strrchr((char *)((int)this + 0x7c),0x2e);
    if (pcVar7 != (char *)0x0) {
      *pcVar7 = '\0';
    }
    uVar9 = 0xffffffff;
    pcVar7 = &DAT_005719f8;
    do {
      pcVar13 = pcVar7;
      if (uVar9 == 0) break;
      uVar9 = uVar9 - 1;
      pcVar13 = pcVar7 + 1;
      cVar2 = *pcVar7;
      pcVar7 = pcVar13;
    } while (cVar2 != '\0');
    uVar9 = ~uVar9;
    iVar5 = -1;
    pcVar7 = (char *)((int)this + 0x7c);
    do {
      pcVar12 = pcVar7;
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      pcVar12 = pcVar7 + 1;
      cVar2 = *pcVar7;
      pcVar7 = pcVar12;
    } while (cVar2 != '\0');
    pcVar7 = pcVar13 + -uVar9;
    pcVar13 = pcVar12 + -1;
    for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
      *(undefined4 *)pcVar13 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar13 = pcVar13 + 4;
    }
    for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
      *pcVar13 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar13 = pcVar13 + 1;
    }
    local_224 = operator_new(0x50);
    local_4 = 0;
    if (local_224 == (void *)0x0) {
      puVar8 = (undefined4 *)0x0;
    }
    else {
      puVar8 = FUN_0053c7f0(local_224,DAT_0057c5c8,*(void **)(*(int *)((int)this + 4) + 0x2bf44),
                            (LPCSTR)((int)this + 0x7c),&local_220,0,(void *)0x0,0);
    }
    *(undefined4 **)((int)this + 0x74) = puVar8;
    local_4 = 0xffffffff;
    if (local_220 != 0) {
      FUN_0048e0a0();
    }
    *(undefined4 *)((int)this + 0x78) = 0;
  }
  else {
    FUN_0054dd83(local_10c,(byte *)s__s_tga_00571b10,&DAT_0057bb44);
    local_224 = operator_new(0x11c);
    local_4 = 1;
    if (local_224 == (void *)0x0) {
      puVar8 = (undefined4 *)0x0;
    }
    else {
      puVar8 = FUN_00535fc0(local_224,local_10c,DAT_0057c5c8,
                            *(void **)(*(int *)((int)this + 4) + 0x2bf44),&local_220,
                            (undefined *)0x0);
    }
    *(undefined4 **)((int)this + 0x70) = puVar8;
    local_4 = 0xffffffff;
    if (local_220 != 0) {
      FUN_0048e0a0();
    }
  }
  if (*(int *)((int)this + 0xc) == 0x10) {
    FUN_004f3b70(this);
  }
  else {
    SetRect((LPRECT)((int)this + 0x100),0,0,0,0);
  }
  *(undefined4 *)((int)this + 0x110) = 0;
  *(undefined4 *)((int)this + 0x114) = 0;
  FUN_004f37d0(this,1,(uint)(*(int *)((int)this + 0x118) == 0),1);
  ExceptionList = local_c;
  return;
}

