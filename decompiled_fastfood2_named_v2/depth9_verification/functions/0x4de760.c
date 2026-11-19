// rea decompile_all
// name: FUN_004de760
// address: 0x4de760
// body: available
// range: 0x4de760-0x4dec0d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004de760(void *this,char *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  void *pvVar8;
  uint uVar9;
  uint uVar10;
  char *pcVar11;
  float *pfVar12;
  int iVar13;
  char *pcVar14;
  char *pcVar15;
  float10 fVar16;
  uint local_30;
  float local_20;
  float local_1c;
  char *local_18;
  float *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005593db;
  local_c = ExceptionList;
  local_30 = (uint)*(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 4);
  if (param_1 != (char *)0x0) {
    local_30 = local_30 - 1;
  }
  iVar2 = *(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 10) - 1;
  ExceptionList = &local_c;
  iVar3 = FUN_004ddce0(this,iVar2);
  iVar4 = FUN_00482820(DAT_0057c670);
  if (*(int *)((int)this + 0x48) == iVar4) {
    FUN_004f5fc0(*(int *)(*(int *)(DAT_0057c670 + 0x224) + 0xac));
  }
  iVar4 = FUN_004e2280((int)this);
  iVar5 = FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  FUN_004e0b60(this,3,(float)(iVar4 * iVar4 * 0xbc) * *(float *)(iVar5 + 0x94),'\0',0xffffffff);
  iVar5 = FUN_004ddcc0((int)this);
  iVar4 = *(int *)((int)this + 0x1cc);
  iVar13 = 0;
  iVar5 = (((*(int *)(iVar5 + 0x68) + *(int *)(iVar5 + 0x50)) * -0x1e + 100) * 500) / 100;
  if (0 < iVar4) {
    do {
      piVar6 = (int *)FUN_004017f0((void *)((int)this + 0x1b8),iVar13,(int *)0x0);
      if (piVar6[1] == 0x17) {
        iVar7 = FUN_004017f0((void *)(DAT_0057c670 + 0x3c),*piVar6,(int *)0x0);
        if ((*(int *)(iVar7 + 0x10c) == -1) ||
           (pvVar8 = (void *)FUN_004017f0((void *)((int)this + 0x148),*(int *)(iVar7 + 0x10c),
                                          (int *)0x0), pvVar8 == (void *)0x0)) {
          FUN_004e0b60(this,10,(float)iVar5,'\0',0xffffffff);
        }
        else {
          FUN_00477e40(pvVar8,10,(float)iVar5,'\0',-1);
        }
      }
      iVar13 = iVar13 + 1;
    } while (iVar13 < iVar4);
  }
  iVar4 = 0;
  if (0 < *(int *)((int)this + 0x194)) {
    do {
      pvVar8 = (void *)FUN_004017f0((void *)((int)this + 0x180),iVar4,(int *)0x0);
      FUN_005140e0(pvVar8);
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)((int)this + 0x194));
  }
  iVar4 = *(int *)((int)this + 0x15c);
  if (iVar3 != 0) {
    local_1c = 0.0;
    if (0 < iVar4) {
      local_18 = (char *)(iVar3 + 0xdc);
      local_10 = (float *)(iVar3 + 0x10);
      do {
        iVar5 = FUN_004017f0((void *)((int)this + 0x148),(int)local_1c,(int *)0x0);
        uVar9 = 0xffffffff;
        pcVar11 = (char *)(iVar5 + 4);
        do {
          pcVar14 = pcVar11;
          if (uVar9 == 0) break;
          uVar9 = uVar9 - 1;
          pcVar14 = pcVar11 + 1;
          cVar1 = *pcVar11;
          pcVar11 = pcVar14;
        } while (cVar1 != '\0');
        uVar9 = ~uVar9;
        pcVar11 = pcVar14 + -uVar9;
        pcVar14 = local_18;
        for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
          *(undefined4 *)pcVar14 = *(undefined4 *)pcVar11;
          pcVar11 = pcVar11 + 4;
          pcVar14 = pcVar14 + 4;
        }
        for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
          *pcVar14 = *pcVar11;
          pcVar11 = pcVar11 + 1;
          pcVar14 = pcVar14 + 1;
        }
        iVar13 = 0;
        pfVar12 = (float *)(iVar3 + 0x78);
        do {
          fVar16 = FUN_00478090(iVar5,iVar13,local_30,iVar2);
          iVar13 = iVar13 + 1;
          *pfVar12 = (float)(fVar16 + (float10)*pfVar12);
          pfVar12 = pfVar12 + 1;
        } while (iVar13 < 0x19);
        local_20 = 0.0;
        iVar13 = 0;
        pfVar12 = (float *)(iVar3 + 0x10);
        do {
          if (iVar13 < 0x14) {
            fVar16 = FUN_00477fe0(iVar5,iVar13,local_30,iVar2);
            local_20 = (float)(fVar16 + (float10)local_20);
          }
          else {
            fVar16 = FUN_00477fe0(iVar5,iVar13,local_30,iVar2);
            *pfVar12 = (float)(fVar16 + (float10)*pfVar12);
          }
          iVar13 = iVar13 + 1;
          pfVar12 = pfVar12 + 1;
        } while (iVar13 < 0x1a);
        local_1c = (float)((int)local_1c + 1);
        local_18 = local_18 + 0x20;
        *local_10 = local_20 + *local_10;
        local_10 = local_10 + 1;
      } while ((int)local_1c < iVar4);
    }
    if (iVar4 < 0x14) {
      local_10 = (float *)(0x14 - iVar4);
      pcVar11 = (char *)(iVar4 * 0x20 + 0xdc + iVar3);
      do {
        uVar9 = 0xffffffff;
        pcVar14 = DAT_00582e4c;
        do {
          pcVar15 = pcVar14;
          if (uVar9 == 0) break;
          uVar9 = uVar9 - 1;
          pcVar15 = pcVar14 + 1;
          cVar1 = *pcVar14;
          pcVar14 = pcVar15;
        } while (cVar1 != '\0');
        uVar9 = ~uVar9;
        pcVar14 = pcVar15 + -uVar9;
        pcVar15 = pcVar11;
        for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
          *(undefined4 *)pcVar15 = *(undefined4 *)pcVar14;
          pcVar14 = pcVar14 + 4;
          pcVar15 = pcVar15 + 4;
        }
        local_10 = (float *)((int)local_10 + -1);
        for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
          *pcVar15 = *pcVar14;
          pcVar14 = pcVar14 + 1;
          pcVar15 = pcVar15 + 1;
        }
        pcVar11 = pcVar11 + 0x20;
      } while (local_10 != (float *)0x0);
    }
  }
  iVar2 = 0;
  if (0 < iVar4) {
    do {
      pvVar8 = (void *)FUN_004017f0((void *)((int)this + 0x148),iVar2,(int *)0x0);
      FUN_00477850(pvVar8,(int)param_1);
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar4);
  }
  if (param_1 != (char *)0x0) {
    local_1c = 0.0;
    local_20 = 0.0;
    pvVar8 = operator_new(0x35c);
    local_4 = 0;
    if (pvVar8 == (void *)0x0) {
      local_18 = (char *)0x0;
    }
    else {
      local_18 = (char *)FUN_00401040(pvVar8,0xfffffffe,local_30,(int)this);
    }
    iVar2 = 0;
    local_4 = 0xffffffff;
    if (0 < iVar4) {
      param_1 = (char *)((int)local_18 + 0xdc);
      pfVar12 = (float *)((int)local_18 + 0x10);
      do {
        iVar3 = FUN_004017f0((void *)((int)this + 0x148),iVar2,(int *)0x0);
        uVar9 = 0xffffffff;
        pcVar11 = (char *)(iVar3 + 4);
        do {
          pcVar14 = pcVar11;
          if (uVar9 == 0) break;
          uVar9 = uVar9 - 1;
          pcVar14 = pcVar11 + 1;
          cVar1 = *pcVar11;
          pcVar11 = pcVar14;
        } while (cVar1 != '\0');
        uVar9 = ~uVar9;
        pcVar11 = pcVar14 + -uVar9;
        pcVar14 = param_1;
        for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
          *(undefined4 *)pcVar14 = *(undefined4 *)pcVar11;
          pcVar11 = pcVar11 + 4;
          pcVar14 = pcVar14 + 4;
        }
        for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
          *pcVar14 = *pcVar11;
          pcVar11 = pcVar11 + 1;
          pcVar14 = pcVar14 + 1;
        }
        fVar16 = FUN_00477fe0(iVar3,-1,local_30,-1);
        iVar2 = iVar2 + 1;
        param_1 = param_1 + 0x20;
        local_20 = (float)((float10)local_20 + fVar16);
        *pfVar12 = (float)(fVar16 + (float10)*pfVar12);
        pfVar12 = pfVar12 + 1;
      } while (iVar2 < iVar4);
    }
    iVar2 = 0;
    do {
      fVar16 = FUN_004e09e0((int)this,iVar2,local_30,-1);
      iVar2 = iVar2 + 1;
      local_1c = (float)(fVar16 + (float10)local_1c);
    } while (iVar2 < 0x1a);
    if (0.0 < local_1c - local_20) {
      *(float *)((int)local_18 + 0x60) = (local_1c - local_20) + *(float *)((int)local_18 + 0x60);
    }
    FUN_004014b0((void *)((int)this + 0x164),local_18);
  }
  ExceptionList = local_c;
  return;
}

