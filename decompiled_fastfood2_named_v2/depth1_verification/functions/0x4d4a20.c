// rea decompile_all
// name: FUN_004d4a20
// address: 0x4d4a20
// body: available
// range: 0x4d4a20-0x4d5097 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004d4a20(void *this,int param_1,int param_2)

{
  void *pvVar1;
  uint uVar2;
  undefined4 *puVar3;
  char *pcVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  longlong lVar10;
  int iVar11;
  char cVar12;
  int iVar13;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558f04;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(int *)((int)this + 0x48) = param_1;
  iVar8 = 0;
  do {
    lVar10 = __ftol();
    iVar6 = (int)lVar10;
    if (0 < iVar6) {
      do {
        pvVar1 = operator_new(0x16c);
        local_4 = 0;
        if (pvVar1 == (void *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          iVar13 = -1;
          iVar11 = 0;
          uVar2 = _rand();
          puVar3 = FUN_00504610(pvVar1,iVar8,*(int *)((int)this + 0xc1c),uVar2 & 1,iVar11,iVar13);
        }
        local_4 = 0xffffffff;
        IDMap_GetRandomName(DAT_0057ba10,puVar3[9],(char *)(puVar3 + 1));
        FUN_00482790(DAT_0057c670,puVar3);
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    iVar8 = iVar8 + 1;
  } while (iVar8 < 8);
  if ((int)(*(uint *)((int)this + 0x48) & 0xfffffffe) < 200) {
    iVar8 = (int)*(uint *)((int)this + 0x48) >> 1;
  }
  else {
    iVar8 = 100;
  }
  if (0 < iVar8) {
    do {
      pvVar1 = operator_new(0x14);
      local_4 = 1;
      if (pvVar1 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = FUN_004d31f0(pvVar1,*(int *)((int)this + 0xc1c));
      }
      local_4 = 0xffffffff;
      Game_RegisterObject(DAT_0057c670,puVar3);
      do {
        iVar6 = FUN_004f1280(*(void **)((int)this + 0xfa8),(int *)0x0);
        iVar11 = FUN_004f5cd0(*(void **)((int)this + 0xfa8),iVar6);
      } while (iVar11 == 0);
      FUN_004f5d40(*(void **)((int)this + 0xfa8),iVar6,puVar3[2]);
      MapObject_PlaceAtPoint(puVar3,iVar6);
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  uVar2 = 0;
  do {
    iVar8 = 10;
    do {
      FUN_004d4940(this,uVar2);
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 4);
  pvVar1 = operator_new(0x16c);
  local_4 = 2;
  if (pvVar1 == (void *)0x0) {
    pcVar4 = (char *)0x0;
  }
  else {
    pcVar4 = (char *)FUN_00504610(pvVar1,0x18,*(int *)((int)this + 0xc1c),0,0,-1);
  }
  uVar2 = 0xffffffff;
  local_4 = 0xffffffff;
  pcVar9 = DAT_00581064;
  do {
    pcVar7 = pcVar9;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar7 = pcVar9 + 1;
    cVar12 = *pcVar9;
    pcVar9 = pcVar7;
  } while (cVar12 != '\0');
  uVar2 = ~uVar2;
  pcVar7 = pcVar7 + -uVar2;
  pcVar9 = pcVar4;
  for (uVar5 = uVar2 >> 2; pcVar9 = pcVar9 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  FUN_00482790(DAT_0057c670,pcVar4);
  param_1 = 0;
  do {
    pvVar1 = operator_new(0x16c);
    local_4 = 3;
    if (pvVar1 == (void *)0x0) {
      pcVar4 = (char *)0x0;
    }
    else {
      pcVar4 = (char *)FUN_00504610(pvVar1,10,*(int *)((int)this + 0xc1c),0,0,-1);
    }
    uVar2 = 0xffffffff;
    local_4 = 0xffffffff;
    if (param_1 == 0) {
      pcVar9 = DAT_00581fe8;
code_r0x004d4c8e:
      do {
        pcVar7 = pcVar9;
        if (uVar2 == 0) break;
        uVar2 = uVar2 - 1;
        pcVar7 = pcVar9 + 1;
        cVar12 = *pcVar9;
        pcVar9 = pcVar7;
      } while (cVar12 != '\0');
      uVar2 = ~uVar2;
      pcVar7 = pcVar7 + -uVar2;
      pcVar9 = pcVar4;
      for (uVar5 = uVar2 >> 2; pcVar9 = pcVar9 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
      }
      for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
        *pcVar9 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar9 = pcVar9 + 1;
      }
    }
    else {
      if (param_1 == 1) {
        pcVar9 = DAT_00582aec;
        goto code_r0x004d4c8e;
      }
      if (param_1 == 2) {
        pcVar9 = DAT_00582fbc;
        goto code_r0x004d4c8e;
      }
    }
    FUN_00482790(DAT_0057c670,pcVar4);
    *(int *)(pcVar4 + 0x10c) = param_1;
    param_1 = param_1 + 1;
  } while (param_1 < 3);
  iVar8 = 10;
  do {
    pvVar1 = operator_new(0x16c);
    local_4 = 4;
    if (pvVar1 == (void *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar3 = FUN_00504610(pvVar1,0x16,*(int *)((int)this + 0xc1c),0,0,-1);
    }
    local_4 = 0xffffffff;
    FUN_004030f0(DAT_0057ba10,puVar3[9],(undefined1 *)(puVar3 + 1),DAT_00581ad4);
    FUN_00482790(DAT_0057c670,puVar3);
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  iVar8 = param_2;
  if (0 < param_2) {
    do {
      pvVar1 = operator_new(0x16c);
      local_4 = 5;
      if (pvVar1 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = FUN_00504610(pvVar1,0x1d,*(int *)((int)this + 0xc1c),0,0,-1);
      }
      local_4 = 0xffffffff;
      FUN_004030f0(DAT_0057ba10,puVar3[9],(undefined1 *)(puVar3 + 1),DAT_00582eec);
      FUN_00482790(DAT_0057c670,puVar3);
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  iVar8 = param_2 * 2;
  if (0 < iVar8) {
    do {
      pvVar1 = operator_new(0x16c);
      local_4 = 6;
      if (pvVar1 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = FUN_00504610(pvVar1,0x1e,*(int *)((int)this + 0xc1c),0,0,-1);
      }
      local_4 = 0xffffffff;
      FUN_004030f0(DAT_0057ba10,puVar3[9],(undefined1 *)(puVar3 + 1),DAT_00582dd0);
      FUN_00482790(DAT_0057c670,puVar3);
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  iVar8 = param_2 * 3;
  if (0 < iVar8) {
    do {
      pvVar1 = operator_new(0x16c);
      local_4 = 7;
      if (pvVar1 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = FUN_00504610(pvVar1,0x1f,*(int *)((int)this + 0xc1c),0,0,-1);
      }
      local_4 = 0xffffffff;
      FUN_004030f0(DAT_0057ba10,puVar3[9],(undefined1 *)(puVar3 + 1),DAT_00582418);
      FUN_00482790(DAT_0057c670,puVar3);
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  iVar8 = param_2 * 4;
  if (0 < iVar8) {
    do {
      pvVar1 = operator_new(0x16c);
      local_4 = 8;
      if (pvVar1 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = FUN_00504610(pvVar1,0x17,*(int *)((int)this + 0xc1c),0,0,-1);
      }
      local_4 = 0xffffffff;
      IDMap_GetRandomName(DAT_0057ba10,0,(char *)(puVar3 + 1));
      FUN_00482790(DAT_0057c670,puVar3);
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  pvVar1 = operator_new(0x16c);
  local_4 = 9;
  if (pvVar1 == (void *)0x0) {
    pcVar4 = (char *)0x0;
  }
  else {
    pcVar4 = (char *)FUN_00504610(pvVar1,0xb,*(int *)((int)this + 0xc1c),0,0,-1);
  }
  uVar2 = 0xffffffff;
  pcVar9 = DAT_00582484;
  do {
    pcVar7 = pcVar9;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar7 = pcVar9 + 1;
    cVar12 = *pcVar9;
    pcVar9 = pcVar7;
  } while (cVar12 != '\0');
  uVar2 = ~uVar2;
  pcVar7 = pcVar7 + -uVar2;
  pcVar9 = pcVar4;
  for (uVar5 = uVar2 >> 2; pcVar9 = pcVar9 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
  }
  local_4 = 0xffffffff;
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  FUN_00482790(DAT_0057c670,pcVar4);
  pvVar1 = operator_new(0x16c);
  local_4 = 10;
  if (pvVar1 == (void *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = FUN_00504610(pvVar1,0xf,*(int *)((int)this + 0xc1c),0,0,-1);
  }
  local_4 = 0xffffffff;
  FUN_00403150(DAT_0057ba10,(undefined1 *)(puVar3 + 1),DAT_00582294);
  FUN_00482790(DAT_0057c670,puVar3);
  pvVar1 = operator_new(0x16c);
  local_4 = 0xb;
  if (pvVar1 == (void *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = FUN_00504610(pvVar1,0x21,*(int *)((int)this + 0xc1c),0,0,-1);
  }
  local_4 = 0xffffffff;
  FUN_00403150(DAT_0057ba10,(undefined1 *)(puVar3 + 1),DAT_00582294);
  FUN_00482790(DAT_0057c670,puVar3);
  iVar8 = *(int *)((int)this + 0xfc0);
  iVar6 = 0;
  if (0 < iVar8) {
    do {
      iVar11 = FUN_004017f0((void *)((int)this + 0xfac),iVar6,(int *)0x0);
      if (*(int *)(iVar11 + 0x8c) < 1) {
        cVar12 = '\x01';
      }
      else {
        cVar12 = '\x02';
      }
      FUN_004f57a0(*(void **)((int)this + 0xfa8),*(int *)(iVar11 + 0x24),cVar12);
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar8);
  }
  ExceptionList = local_c;
  return;
}

