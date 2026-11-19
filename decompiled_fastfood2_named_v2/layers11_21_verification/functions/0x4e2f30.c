// rea decompile_all
// name: FUN_004e2f30
// address: 0x4e2f30
// body: available
// range: 0x4e2f30-0x4e3311 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004e2f30(void *this,int param_1,int *param_2,char *param_3)

{
  char cVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  char *pcVar10;
  char *pcVar11;
  char *pcVar12;
  int *local_7c;
  int local_78 [30];
  
  piVar5 = local_78;
  for (iVar7 = 0x1e; iVar7 != 0; iVar7 = iVar7 + -1) {
    *piVar5 = 0;
    piVar5 = piVar5 + 1;
  }
  iVar7 = 0;
  bVar4 = false;
  bVar3 = false;
  if (0 < *(int *)((int)this + 0x1cc)) {
    do {
      piVar5 = (int *)FUN_004017f0((void *)((int)this + 0x1b8),iVar7,(int *)0x0);
      iVar6 = FUN_004017f0((void *)(DAT_0057c670 + 0x3c),*piVar5,(int *)0x0);
      if (*(int *)(iVar6 + 0x74) == 0) {
        if ((*(int *)(iVar6 + 0xfc) == param_1) && (*(int *)(iVar6 + 0xa4) != -1)) {
          iVar2 = *(int *)(iVar6 + 0x30);
          local_78[*(int *)(iVar6 + 0xa4)] = 1;
          if (iVar2 == 0x1d) {
            param_2[6] = param_2[6] + 1;
          }
          else if (iVar2 == 0x1e) {
            param_2[4] = param_2[4] + 1;
          }
          else if (iVar2 == 0x1f) {
            param_2[2] = param_2[2] + 1;
          }
        }
      }
      else if ((*(int *)(iVar6 + 0xf4) == param_1) && (*(int *)(iVar6 + 0xa4) != -1)) {
        iVar2 = *(int *)(iVar6 + 0x30);
        local_78[*(int *)(iVar6 + 0xa4)] = 1;
        if (iVar2 == 0x1d) {
          param_2[7] = param_2[7] + 1;
        }
        else if (iVar2 == 0x1e) {
          param_2[5] = param_2[5] + 1;
        }
        else if (iVar2 == 0x1f) {
          param_2[3] = param_2[3] + 1;
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < *(int *)((int)this + 0x1cc));
  }
  iVar7 = 0;
  if (0 < *(int *)(DAT_0057c670 + 0x50)) {
    do {
      iVar6 = FUN_004017f0((void *)(DAT_0057c670 + 0x3c),iVar7,(int *)0x0);
      if (((*(int *)(iVar6 + 0x110) == *(int *)((int)this + 0x48)) &&
          (*(int *)(iVar6 + 0x30) == 0x16)) && (*(int *)(iVar6 + 0xa4) != -1)) {
        if (*(int *)(iVar6 + 0x74) == 0) {
          if (*(int *)(iVar6 + 0xfc) == param_1) {
            *param_2 = *param_2 + 1;
            local_78[*(int *)(iVar6 + 0xa4)] = 1;
          }
        }
        else if (*(int *)(iVar6 + 0xf4) == param_1) {
          param_2[1] = param_2[1] + 1;
          local_78[*(int *)(iVar6 + 0xa4)] = 1;
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < *(int *)(DAT_0057c670 + 0x50));
  }
  iVar6 = 0;
  piVar5 = local_78;
  iVar7 = -5;
  do {
    if (0 < *piVar5) {
      iVar6 = iVar6 + 1;
      switch(iVar7) {
      case 0:
      case 1:
      case 10:
      case 0xb:
      case 0xc:
      case 0x18:
        bVar3 = true;
        break;
      default:
        bVar4 = true;
      }
    }
    piVar5 = piVar5 + 1;
    iVar2 = iVar7 + 6;
    iVar7 = iVar7 + 1;
  } while (iVar2 < 0x1e);
  if (iVar6 < 5) {
    local_7c = local_78;
    iVar7 = -1;
    do {
      if (0 < *local_7c) {
        switch(iVar7) {
        case 0:
          pcVar10 = DAT_00582bc4;
          break;
        case 1:
          pcVar10 = DAT_00582024;
          break;
        case 2:
          pcVar10 = DAT_0058200c;
          break;
        default:
          goto switchD_004e3219_caseD_3;
        case 4:
          pcVar10 = DAT_00582698;
          break;
        case 5:
          pcVar10 = DAT_00580e1c;
          break;
        case 6:
          pcVar10 = DAT_005827c4;
          break;
        case 8:
          pcVar10 = DAT_00582fa4;
          break;
        case 0xc:
          pcVar10 = DAT_00581788;
          break;
        case 0xd:
          pcVar10 = DAT_00580f4c;
          break;
        case 0xe:
          pcVar10 = DAT_00582398;
          break;
        case 0xf:
          pcVar10 = DAT_005828a8;
          break;
        case 0x10:
          pcVar10 = DAT_00582a70;
          break;
        case 0x18:
        case 0x19:
          pcVar10 = DAT_00582918;
          break;
        case 0x1c:
          pcVar10 = DAT_00582aac;
        }
        uVar8 = 0xffffffff;
        do {
          pcVar11 = pcVar10;
          if (uVar8 == 0) break;
          uVar8 = uVar8 - 1;
          pcVar11 = pcVar10 + 1;
          cVar1 = *pcVar10;
          pcVar10 = pcVar11;
        } while (cVar1 != '\0');
        uVar8 = ~uVar8;
        iVar6 = -1;
        pcVar10 = param_3;
        do {
          pcVar12 = pcVar10;
          if (iVar6 == 0) break;
          iVar6 = iVar6 + -1;
          pcVar12 = pcVar10 + 1;
          cVar1 = *pcVar10;
          pcVar10 = pcVar12;
        } while (cVar1 != '\0');
        pcVar10 = pcVar11 + -uVar8;
        pcVar11 = pcVar12 + -1;
        for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
          *(undefined4 *)pcVar11 = *(undefined4 *)pcVar10;
          pcVar10 = pcVar10 + 4;
          pcVar11 = pcVar11 + 4;
        }
        for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
          *pcVar11 = *pcVar10;
          pcVar10 = pcVar10 + 1;
          pcVar11 = pcVar11 + 1;
        }
switchD_004e3219_caseD_3:
        uVar8 = 0xffffffff;
        pcVar10 = &DAT_0056d140;
        do {
          pcVar11 = pcVar10;
          if (uVar8 == 0) break;
          uVar8 = uVar8 - 1;
          pcVar11 = pcVar10 + 1;
          cVar1 = *pcVar10;
          pcVar10 = pcVar11;
        } while (cVar1 != '\0');
        uVar8 = ~uVar8;
        iVar6 = -1;
        pcVar10 = param_3;
        do {
          pcVar12 = pcVar10;
          if (iVar6 == 0) break;
          iVar6 = iVar6 + -1;
          pcVar12 = pcVar10 + 1;
          cVar1 = *pcVar10;
          pcVar10 = pcVar12;
        } while (cVar1 != '\0');
        pcVar10 = pcVar11 + -uVar8;
        pcVar11 = pcVar12 + -1;
        for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
          *(undefined4 *)pcVar11 = *(undefined4 *)pcVar10;
          pcVar10 = pcVar10 + 4;
          pcVar11 = pcVar11 + 4;
        }
        for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
          *pcVar11 = *pcVar10;
          pcVar10 = pcVar10 + 1;
          pcVar11 = pcVar11 + 1;
        }
      }
      local_7c = local_7c + 1;
      iVar6 = iVar7 + 2;
      iVar7 = iVar7 + 1;
    } while (iVar6 < 0x1e);
    uVar8 = 0xffffffff;
    pcVar10 = param_3;
    do {
      if (uVar8 == 0) break;
      uVar8 = uVar8 - 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar10 + 1;
    } while (cVar1 != '\0');
    param_3[~uVar8 - 2] = '\0';
  }
  else {
    if (!bVar3) {
      uVar8 = 0xffffffff;
      pcVar10 = DAT_00582ce8;
      do {
        pcVar11 = pcVar10;
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        pcVar11 = pcVar10 + 1;
        cVar1 = *pcVar10;
        pcVar10 = pcVar11;
      } while (cVar1 != '\0');
      uVar8 = ~uVar8;
      iVar7 = -1;
      do {
        pcVar10 = param_3;
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        pcVar10 = param_3 + 1;
        cVar1 = *param_3;
        param_3 = pcVar10;
      } while (cVar1 != '\0');
      pcVar11 = pcVar11 + -uVar8;
      pcVar10 = pcVar10 + -1;
      for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar11;
        pcVar11 = pcVar11 + 4;
        pcVar10 = pcVar10 + 4;
      }
      for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *pcVar10 = *pcVar11;
        pcVar11 = pcVar11 + 1;
        pcVar10 = pcVar10 + 1;
      }
      return;
    }
    uVar8 = 0xffffffff;
    pcVar10 = DAT_00582ce8;
    do {
      pcVar11 = pcVar10;
      if (uVar8 == 0) break;
      uVar8 = uVar8 - 1;
      pcVar11 = pcVar10 + 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar11;
    } while (cVar1 != '\0');
    uVar8 = ~uVar8;
    iVar7 = -1;
    pcVar10 = param_3;
    do {
      pcVar12 = pcVar10;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pcVar12 = pcVar10 + 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar12;
    } while (cVar1 != '\0');
    pcVar10 = pcVar11 + -uVar8;
    pcVar11 = pcVar12 + -1;
    for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
      *(undefined4 *)pcVar11 = *(undefined4 *)pcVar10;
      pcVar10 = pcVar10 + 4;
      pcVar11 = pcVar11 + 4;
    }
    for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
      *pcVar11 = *pcVar10;
      pcVar10 = pcVar10 + 1;
      pcVar11 = pcVar11 + 1;
    }
    if (bVar4) {
      uVar8 = 0xffffffff;
      pcVar10 = &DAT_0056d140;
      do {
        pcVar11 = pcVar10;
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        pcVar11 = pcVar10 + 1;
        cVar1 = *pcVar10;
        pcVar10 = pcVar11;
      } while (cVar1 != '\0');
      uVar8 = ~uVar8;
      iVar7 = -1;
      pcVar10 = param_3;
      do {
        pcVar12 = pcVar10;
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        pcVar12 = pcVar10 + 1;
        cVar1 = *pcVar10;
        pcVar10 = pcVar12;
      } while (cVar1 != '\0');
      pcVar10 = pcVar11 + -uVar8;
      pcVar11 = pcVar12 + -1;
      for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        *(undefined4 *)pcVar11 = *(undefined4 *)pcVar10;
        pcVar10 = pcVar10 + 4;
        pcVar11 = pcVar11 + 4;
      }
      for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *pcVar11 = *pcVar10;
        pcVar10 = pcVar10 + 1;
        pcVar11 = pcVar11 + 1;
      }
      uVar8 = 0xffffffff;
      pcVar10 = DAT_0058114c;
      do {
        pcVar11 = pcVar10;
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        pcVar11 = pcVar10 + 1;
        cVar1 = *pcVar10;
        pcVar10 = pcVar11;
      } while (cVar1 != '\0');
      uVar8 = ~uVar8;
      iVar7 = -1;
      do {
        pcVar10 = param_3;
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        pcVar10 = param_3 + 1;
        cVar1 = *param_3;
        param_3 = pcVar10;
      } while (cVar1 != '\0');
      pcVar11 = pcVar11 + -uVar8;
      pcVar10 = pcVar10 + -1;
      for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar11;
        pcVar11 = pcVar11 + 4;
        pcVar10 = pcVar10 + 4;
      }
      for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *pcVar10 = *pcVar11;
        pcVar11 = pcVar11 + 1;
        pcVar10 = pcVar10 + 1;
      }
      return;
    }
  }
  return;
}

