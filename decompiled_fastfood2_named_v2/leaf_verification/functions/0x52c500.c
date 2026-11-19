// rea decompile_all
// name: FUN_0052c500
// address: 0x52c500
// body: available
// range: 0x52c500-0x52cb2c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_0052c500(void *this,char *param_1)

{
  char cVar1;
  byte bVar2;
  void *pvVar3;
  undefined4 *puVar4;
  size_t _Count;
  undefined4 uVar5;
  char *pcVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  char *pcVar13;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  char local_80 [128];
  
  uVar7 = 0xffffffff;
  pcVar6 = param_1;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  iVar8 = ~uVar7 - 1;
  local_8c = iVar8;
  if (*(int *)((int)this + 0x78) < iVar8) {
    if (*(LPVOID *)((int)this + 0x74) != (LPVOID)0x0) {
      FUN_0054dd78(*(LPVOID *)((int)this + 0x74));
    }
    *(undefined4 *)((int)this + 0x74) = 0;
    *(undefined4 *)((int)this + 0x78) = 0;
  }
  *(undefined4 *)((int)this + 0x7c) = 0;
  if (*(int *)((int)this + 0x88) != 0) {
    pvVar3 = *(void **)(*(int *)((int)this + 8) + 0x134);
    iVar8 = 0x10;
    do {
      if (pvVar3 != (void *)0x0) {
        FUN_005271d0(pvVar3,*(int *)(iVar8 + *(int *)((int)this + 0x88)));
      }
      iVar11 = iVar8 + 4;
      *(undefined4 *)(iVar8 + *(int *)((int)this + 0x88)) = 0;
      iVar8 = iVar11;
    } while (iVar11 < 0x34);
    iVar8 = local_8c;
  }
  local_90 = 0;
  while( true ) {
    if ((iVar8 <= local_90) || ((bVar2 = param_1[local_90], 0x20 < bVar2 && (bVar2 != 0x7b))))
    goto LAB_0052c5f0;
    if ((bVar2 == 0x7b) &&
       ((uVar7 = FUN_0054f9e3((uint)(byte)param_1[local_90 + 1]), uVar7 == 0x48 &&
        (uVar7 = FUN_0054f9e3((uint)(byte)param_1[local_90 + 2]), uVar7 == 0x45)))) break;
    local_90 = local_90 + 1;
  }
  *(undefined4 *)((int)this + 0x7c) = 1;
LAB_0052c5f0:
  iVar8 = 0;
  if (*(int *)((int)this + 0x74) == 0) {
    *(int *)((int)this + 0x78) = local_8c;
    pvVar3 = operator_new(local_8c + 1);
    *(void **)((int)this + 0x74) = pvVar3;
  }
  if (*(int *)((int)this + 0x7c) == 0) {
    uVar7 = 0xffffffff;
    do {
      pcVar6 = param_1;
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      pcVar6 = param_1 + 1;
      cVar1 = *param_1;
      param_1 = pcVar6;
    } while (cVar1 != '\0');
    uVar7 = ~uVar7;
    pcVar6 = pcVar6 + -uVar7;
    pcVar13 = *(char **)((int)this + 0x74);
    for (uVar9 = uVar7 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
      *(undefined4 *)pcVar13 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar13 = pcVar13 + 4;
    }
    for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *pcVar13 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar13 = pcVar13 + 1;
    }
    pcVar6 = *(char **)((int)this + 0x74);
    while ((pcVar6 != (char *)0x0 && (pcVar6 = _strchr(pcVar6,10), pcVar6 != (char *)0x0))) {
      *pcVar6 = '\r';
      pcVar6 = pcVar6 + 1;
    }
    *(undefined4 *)((int)this + 0x5c) = 0xffffffff;
    return;
  }
  if (*(int *)((int)this + 0x88) == 0) {
    puVar4 = operator_new(0x34);
    *(undefined4 **)((int)this + 0x88) = puVar4;
    for (iVar11 = 0xd; iVar11 != 0; iVar11 = iVar11 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    **(undefined4 **)((int)this + 0x88) = 0x14;
    *(undefined4 *)(*(int *)((int)this + 0x88) + 4) = 0;
    *(undefined4 *)(*(int *)((int)this + 0x88) + 8) = 2;
    *(undefined4 *)(*(int *)((int)this + 0x88) + 0xc) = *(undefined4 *)((int)this + 0x54);
  }
  iVar11 = 1;
  local_88 = 1;
  local_84 = 0;
  local_90 = 0;
  if (0 < local_8c) {
    do {
      bVar2 = param_1[local_90];
      iVar10 = local_90;
      if (bVar2 < 0x20) {
        if (iVar11 == 0) {
          if (bVar2 == 10) {
            if (local_84 == 0) {
              local_84 = 1;
            }
            else {
              *(undefined1 *)(iVar8 + *(int *)((int)this + 0x74)) = 0xd;
              iVar8 = iVar8 + 1;
            }
          }
        }
        goto LAB_0052caae;
      }
      if (bVar2 != 0x7b) {
        if (iVar11 == 0) {
          local_84 = 1;
          *(byte *)(iVar8 + *(int *)((int)this + 0x74)) = bVar2;
          iVar8 = iVar8 + 1;
        }
        goto LAB_0052caae;
      }
      iVar10 = local_90 + 1;
      bVar2 = param_1[iVar10];
      while ((0x1f < bVar2 && (bVar2 != 0x7d))) {
        iVar11 = iVar10 + 1;
        iVar10 = iVar10 + 1;
        bVar2 = param_1[iVar11];
      }
      pcVar6 = local_80;
      for (iVar11 = 0x20; iVar11 != 0; iVar11 = iVar11 + -1) {
        pcVar6[0] = '\0';
        pcVar6[1] = '\0';
        pcVar6[2] = '\0';
        pcVar6[3] = '\0';
        pcVar6 = pcVar6 + 4;
      }
      _Count = (iVar10 - local_90) - 1;
      if (0x7f < (int)_Count) {
        _Count = 0x7f;
      }
      _strncpy(local_80,param_1 + local_90 + 1,_Count);
      local_90 = 1;
      iVar12 = iVar8;
      if (local_88 != 0) {
        uVar7 = FUN_0054f9e3((int)local_80[0]);
        if (uVar7 == 0x44) {
          Text_SkipFieldSeparators((int)local_80,&local_90);
          iVar11 = FUN_0052cba0(local_80,&local_90);
          Text_SkipFieldSeparators((int)local_80,&local_90);
          uVar7 = FUN_00527090(*(void **)(*(int *)((int)this + 8) + 0x134),local_80 + local_90);
          *(uint *)(*(int *)((int)this + 0x88) + 0xc + iVar11 * 4) = uVar7;
          iVar11 = local_88;
        }
        else if (uVar7 == 0x48) {
          if (' ' < local_80[local_90]) {
            do {
              iVar11 = local_90 + 1;
              local_90 = local_90 + 1;
            } while (' ' < local_80[iVar11]);
          }
          Text_SkipFieldSeparators((int)local_80,&local_90);
          iVar11 = FUN_0052cba0(local_80,&local_90);
          if (iVar11 != -1) {
            **(int **)((int)this + 0x88) = iVar11;
          }
          Text_SkipFieldSeparators((int)local_80,&local_90);
          iVar11 = FUN_0052cba0(local_80,&local_90);
          if (iVar11 != -1) {
            if (0x13 < iVar11) {
              iVar11 = 0x14;
            }
            *(int *)(*(int *)((int)this + 0x88) + 8) = iVar11;
          }
          Text_SkipFieldSeparators((int)local_80,&local_90);
          iVar11 = FUN_0052cba0(local_80,&local_90);
          if (iVar11 == -1) goto switchD_0052c8a8_caseD_2e;
          *(int *)(*(int *)((int)this + 0x88) + 4) = iVar11;
          iVar11 = local_88;
        }
        else {
          if (uVar7 != 0x54) goto switchD_0052c8a8_caseD_2e;
          local_88 = 0;
          iVar11 = 0;
        }
        goto LAB_0052caae;
      }
      uVar7 = FUN_0054f9e3((int)local_80[0]);
      switch(uVar7) {
      case 0x2d:
        *(undefined1 *)(iVar8 + *(int *)((int)this + 0x74)) = 1;
        *(undefined1 *)(iVar8 + 1 + *(int *)((int)this + 0x74)) = 1;
        *(undefined1 *)(iVar8 + 2 + *(int *)((int)this + 0x74)) = 5;
        iVar12 = iVar8 + 3;
      default:
switchD_0052c8a8_caseD_2e:
        iVar11 = local_88;
        iVar8 = iVar12;
        break;
      case 0x41:
        *(undefined1 *)(iVar8 + *(int *)((int)this + 0x74)) = 1;
        *(undefined1 *)(iVar8 + 1 + *(int *)((int)this + 0x74)) = 2;
        *(undefined1 *)(iVar8 + 2 + *(int *)((int)this + 0x74)) = 4;
        iVar12 = iVar8 + 3;
        Text_SkipFieldSeparators((int)local_80,&local_90);
        uVar7 = FUN_0054f9e3((int)local_80[local_90]);
        iVar11 = local_88;
        if (uVar7 == 0x43) {
          *(undefined1 *)(iVar12 + *(int *)((int)this + 0x74)) = 2;
          iVar8 = iVar8 + 4;
        }
        else if (uVar7 == 0x4c) {
          *(undefined1 *)(iVar12 + *(int *)((int)this + 0x74)) = 0;
          iVar8 = iVar8 + 4;
        }
        else {
          if (uVar7 != 0x52) goto switchD_0052c8a8_caseD_2e;
          *(undefined1 *)(iVar12 + *(int *)((int)this + 0x74)) = 1;
          iVar8 = iVar8 + 4;
        }
        break;
      case 0x43:
        *(undefined1 *)(iVar8 + *(int *)((int)this + 0x74)) = 1;
        *(undefined1 *)(iVar8 + 1 + *(int *)((int)this + 0x74)) = 4;
        *(undefined1 *)(iVar8 + 2 + *(int *)((int)this + 0x74)) = 1;
        uVar5 = FUN_0052cba0(local_80,&local_90);
        *(char *)(iVar8 + 3 + *(int *)((int)this + 0x74)) = (char)uVar5;
        iVar8 = iVar8 + 4;
        Text_SkipFieldSeparators((int)local_80,&local_90);
        uVar5 = FUN_0052cba0(local_80,&local_90);
        *(char *)(iVar8 + *(int *)((int)this + 0x74)) = (char)uVar5;
        goto LAB_0052ca2e;
      case 0x45:
        *(undefined1 *)(iVar8 + *(int *)((int)this + 0x74)) = 1;
        *(undefined1 *)(iVar8 + 1 + *(int *)((int)this + 0x74)) = 2;
        iVar8 = iVar8 + 2;
        Text_SkipFieldSeparators((int)local_80,&local_90);
        uVar7 = FUN_0054f9e3((int)local_80[local_90]);
        if (uVar7 == 0x44) {
          *(undefined1 *)(iVar8 + *(int *)((int)this + 0x74)) = 3;
        }
        else {
          *(undefined1 *)(iVar8 + *(int *)((int)this + 0x74)) = 2;
        }
LAB_0052ca2e:
        Text_SkipFieldSeparators((int)local_80,&local_90);
        uVar5 = FUN_0052cba0(local_80,&local_90);
        *(char *)(iVar8 + 1 + *(int *)((int)this + 0x74)) = (char)uVar5;
        iVar8 = iVar8 + 2;
        iVar11 = local_88;
        break;
      case 0x46:
        *(undefined1 *)(iVar8 + *(int *)((int)this + 0x74)) = 1;
        *(undefined1 *)(iVar8 + 1 + *(int *)((int)this + 0x74)) = 2;
        *(undefined1 *)(iVar8 + 2 + *(int *)((int)this + 0x74)) = 0;
        uVar5 = FUN_0052cba0(local_80,&local_90);
        *(char *)(iVar8 + 3 + *(int *)((int)this + 0x74)) = (char)uVar5;
        iVar8 = iVar8 + 4;
        iVar11 = local_88;
      }
LAB_0052caae:
      local_90 = iVar10 + 1;
    } while (local_90 < local_8c);
  }
  *(undefined1 *)(iVar8 + *(int *)((int)this + 0x74)) = 0;
  *(undefined4 *)((int)this + 0x5c) = 0xffffffff;
  return;
}

