// rea decompile_all
// name: FUN_00532c40
// address: 0x532c40
// body: available
// range: 0x532c40-0x53330a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall
FUN_00532c40(void *this,int param_1,void *param_2,LPCSTR param_3,undefined4 *param_4,int param_5)

{
  char cVar1;
  ushort uVar2;
  bool bVar3;
  FILE *pFVar4;
  char *pcVar5;
  void *pvVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  ushort *puVar10;
  int iVar11;
  uint uVar12;
  char *pcVar13;
  ushort *puVar14;
  undefined4 *puVar15;
  int iVar16;
  LPCSTR pCVar17;
  int *local_3c0;
  uint local_3b8;
  uint local_3b4;
  void *local_3b0;
  int local_3ac;
  void *local_3a8;
  char local_3a4 [152];
  char local_30c [768];
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055ac87;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_3a8 = this;
  FUN_0053a1e0(this);
  *(undefined4 *)((int)this + 0x90) = 0;
  local_4 = 0;
  *(undefined ***)this = &PTR_FUN_0055c80c;
  bVar3 = false;
  *(undefined1 *)((int)this + 0x34) = 0;
  *(undefined1 *)((int)this + 0x35) = 1;
  *(undefined4 *)((int)this + 0x38) = 0;
  *(undefined4 *)((int)this + 0x78) = 0;
  *(undefined4 *)((int)this + 0x94) = 0x3ff00000;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x80) = 0;
  *(undefined4 *)((int)this + 0x50) = 0;
  *(undefined4 *)((int)this + 0x4c) = 0;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  if (param_2 == (void *)0x0) {
    pFVar4 = (FILE *)FUN_0054dfe0(param_3,&DAT_00563184);
    if (pFVar4 == (FILE *)0x0) {
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = 0x191;
        ExceptionList = local_c;
        return this;
      }
      NoOp_Stub();
    }
    piVar7 = (int *)((int)this + 100);
    FUN_0054e978((char *)piVar7,1,0x14,(int *)pFVar4);
    FUN_0054e978((char *)((int)this + 4),1,0x1c,(int *)pFVar4);
    if ((((*(uint *)((int)this + 0x70) & 0xffff0000) != 0xca420000) ||
        (local_3b4 = *(uint *)((int)this + 0x70) & 0xffff, local_3b4 == 0)) || (2 < local_3b4)) {
      bVar3 = true;
      local_3b4 = 0;
    }
    if ((*piVar7 < 0) || (500 < *piVar7)) {
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = 0x192;
        ExceptionList = local_c;
        return this;
      }
      NoOp_Stub();
    }
    if (*piVar7 < 1) {
      *piVar7 = 4;
      puVar15 = operator_new(0x260);
      *(undefined4 **)((int)this + 0x50) = puVar15;
      for (iVar16 = 0x98; iVar16 != 0; iVar16 = iVar16 + -1) {
        *puVar15 = 0;
        puVar15 = puVar15 + 1;
      }
    }
    else {
      pcVar5 = operator_new(*piVar7 * 0x98);
      *(char **)((int)this + 0x50) = pcVar5;
      if (bVar3) {
        iVar16 = 0;
        if (0 < *piVar7) {
          local_3c0 = (int *)0x0;
          do {
            FUN_0054e978(local_3a4,1,0x98,(int *)pFVar4);
            FUN_00533310(local_3a4,(int)local_3c0 + *(int *)((int)this + 0x50));
            iVar16 = iVar16 + 1;
            local_3c0 = local_3c0 + 0x26;
          } while (iVar16 < *piVar7);
        }
      }
      else {
        FUN_0054e978(pcVar5,1,*piVar7 * 0x98,(int *)pFVar4);
      }
    }
    FUN_0054e978((char *)&local_3b8,1,4,(int *)pFVar4);
    pcVar5 = operator_new(local_3b8);
    FUN_0054e978(pcVar5,1,local_3b8,(int *)pFVar4);
    FUN_0054dee4(pFVar4);
  }
  else {
    local_3c0 = FUN_00402290(param_2,param_3,0);
    if (local_3c0 == (int *)0x0) {
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = 0x192;
        ExceptionList = local_c;
        return this;
      }
      NoOp_Stub();
    }
    piVar7 = (int *)((int)this + 100);
    FUN_00402750(param_2,(char *)piVar7,0x14,(int)local_3c0);
    FUN_00402750(param_2,(char *)((int)this + 4),0x1c,(int)local_3c0);
    if ((((*(uint *)((int)this + 0x70) & 0xffff0000) != 0xca420000) ||
        (local_3b4 = *(uint *)((int)this + 0x70) & 0xffff, local_3b4 == 0)) || (2 < local_3b4)) {
      bVar3 = true;
      local_3b4 = 0;
    }
    pcVar5 = operator_new(*piVar7 * 0x98);
    *(char **)((int)this + 0x50) = pcVar5;
    if (bVar3) {
      local_3b0 = (void *)0x0;
      if (0 < *piVar7) {
        local_3ac = 0;
        do {
          FUN_00402750(param_2,local_3a4,0x98,(int)local_3c0);
          FUN_00533310(local_3a4,local_3ac + *(int *)((int)this + 0x50));
          local_3b0 = (void *)((int)local_3b0 + 1);
          local_3ac = local_3ac + 0x98;
        } while ((int)local_3b0 < *piVar7);
      }
    }
    else {
      FUN_00402750(param_2,pcVar5,*piVar7 * 0x98,(int)local_3c0);
    }
    FUN_00402750(param_2,(char *)&local_3b8,4,(int)local_3c0);
    local_3b8 = local_3b8 - 4;
    if (param_5 == 0) {
      pcVar5 = operator_new(local_3b8);
      FUN_00402750(param_2,pcVar5,local_3b8,(int)local_3c0);
    }
    else {
      iVar16 = 8;
      if (bVar3) {
        iVar16 = 9;
      }
      if ((int)local_3b4 < 2) {
        iVar16 = iVar16 + 2;
      }
      else {
        iVar16 = iVar16 + 4;
      }
      uVar12 = *(int *)((int)this + 0x68) * iVar16;
      if (*(byte *)((int)this + 5) < 9) {
        iVar16 = (local_3b8 - uVar12) + -0x300;
      }
      else {
        iVar16 = local_3b8 - uVar12;
      }
      *(int *)((int)this + 0x40) = iVar16;
      *(void **)((int)this + 0x44) = param_2;
      uVar8 = 0xffffffff;
      *(undefined1 *)((int)this + 0x34) = 1;
      *(undefined1 *)((int)this + 0x35) = 0;
      pCVar17 = param_3;
      do {
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        cVar1 = *pCVar17;
        pCVar17 = pCVar17 + 1;
      } while (cVar1 != '\0');
      pcVar5 = operator_new(~uVar8);
      uVar8 = 0xffffffff;
      *(char **)((int)this + 0x38) = pcVar5;
      do {
        pcVar13 = param_3;
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        pcVar13 = param_3 + 1;
        cVar1 = *param_3;
        param_3 = pcVar13;
      } while (cVar1 != '\0');
      uVar8 = ~uVar8;
      pcVar13 = pcVar13 + -uVar8;
      for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        *(undefined4 *)pcVar5 = *(undefined4 *)pcVar13;
        pcVar13 = pcVar13 + 4;
        pcVar5 = pcVar5 + 4;
      }
      for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *pcVar5 = *pcVar13;
        pcVar13 = pcVar13 + 1;
        pcVar5 = pcVar5 + 1;
      }
      pcVar5 = operator_new(uVar12);
      FUN_00402750(param_2,pcVar5,uVar12,(int)local_3c0);
      *(int *)((int)this + 0x3c) = local_3c0[4];
    }
  }
  iVar16 = *(int *)((int)this + 0x68);
  *(char **)((int)this + 0x20) = pcVar5;
  iVar11 = iVar16 * 2;
  pcVar5 = pcVar5 + iVar11;
  *(char **)((int)this + 0x24) = pcVar5;
  pcVar5 = pcVar5 + iVar11;
  *(char **)((int)this + 0x28) = pcVar5;
  *(char **)((int)this + 0x2c) = pcVar5 + iVar11;
  puVar14 = (ushort *)(pcVar5 + iVar11 + iVar11);
  if ((int)local_3b4 < 2) {
    pvVar6 = operator_new(iVar16 << 2);
    *(void **)((int)this + 0x30) = pvVar6;
    iVar16 = 0;
    *(undefined4 *)((int)this + 0x88) = 1;
    if (0 < *(int *)((int)this + 0x68)) {
      puVar10 = puVar14;
      do {
        uVar2 = *puVar10;
        puVar10 = puVar10 + 1;
        *(uint *)(*(int *)((int)this + 0x30) + iVar16 * 4) = (uint)uVar2;
        iVar16 = iVar16 + 1;
      } while (iVar16 < *(int *)((int)this + 0x68));
    }
    iVar16 = *(int *)((int)this + 0x68);
    iVar11 = iVar16 * 2;
  }
  else {
    *(ushort **)((int)this + 0x30) = puVar14;
    *(undefined4 *)((int)this + 0x88) = 0;
    iVar11 = iVar16 * 4;
  }
  puVar15 = (undefined4 *)((int)puVar14 + iVar11);
  if (bVar3) {
    puVar15 = (undefined4 *)((int)puVar15 + iVar16);
  }
  pvVar6 = operator_new(iVar16 << 2);
  *(void **)((int)this + 0x80) = pvVar6;
  if (*(char *)((int)this + 0x34) == '\0') {
    iVar16 = 0;
    if (0 < *(int *)((int)this + 0x68)) {
      do {
        if (*(int *)(*(int *)((int)this + 0x30) + iVar16 * 4) == 0) {
          *(undefined4 *)(*(int *)((int)this + 0x80) + iVar16 * 4) = 0;
        }
        else {
          *(undefined4 **)(*(int *)((int)this + 0x80) + iVar16 * 4) = puVar15;
        }
        puVar15 = (undefined4 *)((int)puVar15 + *(int *)(*(int *)((int)this + 0x30) + iVar16 * 4));
        iVar16 = iVar16 + 1;
      } while (iVar16 < *(int *)((int)this + 0x68));
    }
  }
  else {
    iVar16 = 0;
    if (0 < *(int *)((int)this + 0x68)) {
      do {
        iVar16 = iVar16 + 1;
        *(undefined4 *)(*(int *)((int)this + 0x80) + -4 + iVar16 * 4) = 0;
      } while (iVar16 < *(int *)((int)this + 0x68));
    }
  }
  if (8 < *(byte *)((int)this + 5)) {
    *(undefined4 *)((int)this + 0x78) = 0;
    *(undefined4 *)((int)this + 0x7c) = 0;
    if ((((*(char *)((int)this + 0x35) != '\0') && (*(char *)(param_1 + 0x18) != '\0')) &&
        ((*(byte *)((int)this + 4) & 0x10) == 0)) && (iVar16 = 0, 0 < *(int *)((int)this + 0x68))) {
      do {
        puVar14 = *(ushort **)(*(int *)((int)this + 0x80) + iVar16 * 4);
        iVar11 = 0;
        if (*(uint *)(*(int *)((int)this + 0x30) + iVar16 * 4) >> 1 != 0) {
          do {
            uVar2 = *puVar14;
            if ((uint)uVar2 == *(uint *)((int)this + 0x1c)) {
              iVar11 = iVar11 + 1;
              puVar14 = puVar14 + 1;
            }
            else {
              *puVar14 = (uVar2 & 0xffe0) << 1 | uVar2 & 0x1f;
            }
            iVar11 = iVar11 + 1;
            puVar14 = puVar14 + 1;
          } while (iVar11 < (int)(*(uint *)(*(int *)((int)this + 0x30) + iVar16 * 4) >> 1));
        }
        iVar16 = iVar16 + 1;
      } while (iVar16 < *(int *)((int)this + 0x68));
    }
    goto LAB_005332d0;
  }
  if ((*(char *)(param_1 + 0x18) == '\0') || ((*(byte *)((int)this + 4) & 0x10) != 0)) {
    iVar16 = 0;
  }
  else {
    iVar16 = 1;
  }
  if (*(char *)((int)this + 0x35) == '\0') {
    Stream_Seek(*(int *)((int)this + 0x40) + *(int *)((int)this + 0x3c),(int)local_3c0,0);
    FUN_00402750(param_2,local_30c,0x300,(int)local_3c0);
    local_3b0 = operator_new(0x20c);
    local_4 = CONCAT31(local_4._1_3_,1);
    if (local_3b0 == (void *)0x0) {
LAB_00533237:
      piVar7 = (int *)0x0;
    }
    else {
      piVar7 = FUN_00535d70(local_3b0,iVar16,(undefined4 *)local_30c,0);
    }
  }
  else {
    local_3b0 = operator_new(0x20c);
    local_4 = CONCAT31(local_4._1_3_,2);
    if (local_3b0 == (void *)0x0) goto LAB_00533237;
    piVar7 = FUN_00535d70(local_3b0,iVar16,puVar15,0);
  }
  *(int **)((int)this + 0x78) = piVar7;
  local_4 = local_4 & 0xffffff00;
  *(int **)((int)this + 0x7c) = piVar7 + 1;
LAB_005332d0:
  FUN_00402990(param_2,(int)local_3c0);
  *(undefined4 *)((int)this + 0x48) = 0;
  *(undefined4 *)((int)this + 0x4c) = 0;
  *(undefined4 *)((int)this + 0x54) = 0xfffffc19;
  ExceptionList = local_c;
  return this;
}

