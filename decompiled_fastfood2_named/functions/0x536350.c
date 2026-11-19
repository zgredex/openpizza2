// rea decompile_all
// name: FUN_00536350
// address: 0x536350
// body: available
// range: 0x536350-0x536aa2 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall
FUN_00536350(void *this,int param_1,char *param_2,void *param_3,undefined *param_4)

{
  bool bVar1;
  byte bVar2;
  void *pvVar3;
  int *piVar4;
  char *pcVar5;
  char *pcVar6;
  uint uVar7;
  char cVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  byte *pbVar14;
  byte *pbVar15;
  char *pcVar16;
  byte *pbVar17;
  bool bVar18;
  FILE *local_750;
  int iStack_74c;
  char *pcStack_748;
  byte *pbStack_73c;
  int iStack_738;
  int iStack_730;
  byte abStack_724 [4];
  undefined4 local_720;
  short sStack_71b;
  uint uStack_719;
  short local_714;
  short local_712;
  undefined2 local_710;
  byte abStack_70c [1024];
  char acStack_30c [768];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0055acdc;
  local_c = ExceptionList;
  uVar9 = 0xffffffff;
  do {
    pcVar5 = param_2;
    if (uVar9 == 0) break;
    uVar9 = uVar9 - 1;
    pcVar5 = param_2 + 1;
    cVar8 = *param_2;
    param_2 = pcVar5;
  } while (cVar8 != '\0');
  uVar9 = ~uVar9;
  pcVar6 = (char *)((int)this + 0x1c);
  pcVar5 = pcVar5 + -uVar9;
  pcVar16 = pcVar6;
  ExceptionList = &local_c;
  for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
    *(undefined4 *)pcVar16 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar16 = pcVar16 + 4;
  }
  for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
    *pcVar16 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar16 = pcVar16 + 1;
  }
  if (param_3 == (void *)0x0) {
    local_750 = (FILE *)FUN_0054dfe0(pcVar6,&DAT_00563184);
    if (local_750 == (FILE *)0x0) {
      ExceptionList = local_c;
      return 0;
    }
    FUN_0054e978((char *)&local_720,1,0x12,(int *)local_750);
  }
  else {
    local_750 = (FILE *)Resource_Open(param_3,pcVar6,0);
    if (local_750 == (FILE *)0x0) {
      ExceptionList = local_c;
      return 0;
    }
    Resource_Read(param_3,(char *)&local_720,0x12,(int)local_750);
  }
  if (((local_720._2_1_ == '\t') || (local_720._2_1_ == '\n')) ||
     (bVar1 = false, local_720._2_1_ == '\v')) {
    bVar1 = true;
  }
  bVar2 = (byte)local_710;
  *(byte *)((int)this + 0x10) = bVar2;
  bVar18 = ((byte)((ushort)local_710 >> 8) & 0x20) != 0x20;
  *(int *)((int)this + 4) = (int)local_714;
  *(int *)((int)this + 8) = (int)local_712;
  if (bVar2 < 9) {
    *(undefined1 *)((int)this + 0x11) = 1;
  }
  else if (bVar2 < 0x11) {
    *(undefined1 *)((int)this + 0x11) = 2;
  }
  else if (bVar2 < 0x19) {
    *(undefined1 *)((int)this + 0x11) = 3;
  }
  else {
    *(undefined1 *)((int)this + 0x11) = 4;
  }
  if (param_4 != (undefined *)0x0) {
    (*(code *)param_4)((int)local_712);
  }
  if (param_3 == (void *)0x0) {
    FUN_0054ede0((int *)local_750,(local_720 & 0xff) + 0x12,0);
  }
  else {
    FUN_00540000((local_720 & 0xff) + 0x12,(int)local_750,0);
  }
  if (local_720._1_1_ == '\x01') {
    uVar9 = (int)((int)sStack_71b * (uStack_719 & 0xff)) >> 3;
    pcVar5 = acStack_30c;
    for (iVar11 = 0xc0; iVar11 != 0; iVar11 = iVar11 + -1) {
      pcVar5[0] = '\0';
      pcVar5[1] = '\0';
      pcVar5[2] = '\0';
      pcVar5[3] = '\0';
      pcVar5 = pcVar5 + 4;
    }
    if (param_3 == (void *)0x0) {
      FUN_0054e978(acStack_30c,1,uVar9,(int *)local_750);
    }
    else {
      Resource_Read(param_3,acStack_30c,uVar9,(int)local_750);
    }
    pvVar3 = operator_new(0x20c);
    uStack_4 = 0;
    if (pvVar3 == (void *)0x0) {
LAB_005365c1:
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = FUN_00535d70(pvVar3,(uint)*(byte *)(param_1 + 0x18),(undefined4 *)acStack_30c,0);
    }
  }
  else {
    if ((local_720._2_1_ != '\x03') && (local_720._2_1_ != '\v')) goto LAB_005365d1;
    iVar11 = 0;
    pcVar5 = acStack_30c;
    do {
      cVar8 = (char)iVar11;
      *pcVar5 = cVar8;
      pcVar5[1] = cVar8;
      pcVar5[2] = cVar8;
      pcVar5 = pcVar5 + 3;
      iVar11 = iVar11 + 1;
    } while (iVar11 < 0x100);
    pvVar3 = operator_new(0x20c);
    uStack_4 = 1;
    if (pvVar3 == (void *)0x0) goto LAB_005365c1;
    piVar4 = FUN_00535d70(pvVar3,(uint)*(byte *)(param_1 + 0x18),(undefined4 *)acStack_30c,0);
  }
  uStack_4 = 0xffffffff;
  *(int **)((int)this + 0x14) = piVar4;
LAB_005365d1:
  iVar11 = (uint)*(byte *)((int)this + 0x11) * *(int *)((int)this + 4) * *(int *)((int)this + 8);
  *(int *)((int)this + 0xc) = iVar11;
  pcVar5 = operator_new((iVar11 >> 1) * 2 + 2);
  uVar9 = (uint)*(byte *)((int)this + 0x11) * *(int *)((int)this + 4);
  *(char **)((int)this + 0x18) = pcVar5;
  if (bVar1) {
    iStack_74c = *(int *)((int)this + 8) + -1;
    iStack_738 = 0;
    iVar11 = iStack_74c;
    if (!bVar18) {
      iVar11 = (*(int *)((int)this + 8) - iStack_74c) + -1;
    }
    pbVar14 = (byte *)(pcVar5 + iVar11 * uVar9);
    if (param_3 == (void *)0x0) {
      FUN_0054e978((char *)abStack_70c,1,0x400,(int *)local_750);
      iVar11 = 0;
    }
    else {
      Resource_Read(param_3,(char *)abStack_70c,0x400,(int)local_750);
      iVar11 = 0;
    }
    do {
      bVar2 = abStack_70c[iVar11];
      uVar10 = (uint)bVar2;
      iVar11 = iVar11 + 1;
      if (iVar11 == 0x400) {
        if (param_3 == (void *)0x0) {
          FUN_0054e978((char *)abStack_70c,1,0x400,(int *)local_750);
        }
        else {
          Resource_Read(param_3,(char *)abStack_70c,0x400,(int)local_750);
        }
        iVar11 = 0;
      }
      if (bVar2 < 0x80) {
        iStack_730 = 0;
        if (uVar10 != 0xffffffff) {
          pbStack_73c = (byte *)(pcVar5 + iStack_74c * uVar9);
          do {
            if (0x3ff < (int)((uint)*(byte *)((int)this + 0x11) + iVar11)) {
              iVar13 = -iVar11;
              uVar7 = iVar13 + 0x400;
              pbVar15 = abStack_70c + iVar11;
              pbVar17 = abStack_70c;
              for (uVar12 = uVar7 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
                *(undefined4 *)pbVar17 = *(undefined4 *)pbVar15;
                pbVar15 = pbVar15 + 4;
                pbVar17 = pbVar17 + 4;
              }
              for (uVar12 = uVar7 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
                *pbVar17 = *pbVar15;
                pbVar15 = pbVar15 + 1;
                pbVar17 = pbVar17 + 1;
              }
              if (param_3 == (void *)0x0) {
                FUN_0054e978(acStack_30c + iVar13,1,0x400 - uVar7,(int *)local_750);
              }
              else {
                Resource_Read(param_3,acStack_30c + iVar13,0x400 - uVar7,(int)local_750);
              }
              iVar11 = 0;
            }
            bVar2 = *(byte *)((int)this + 0x11);
            pbVar15 = abStack_70c + iVar11;
            pbVar17 = pbVar14;
            for (uVar7 = (uint)(bVar2 >> 2); uVar7 != 0; uVar7 = uVar7 - 1) {
              *(undefined4 *)pbVar17 = *(undefined4 *)pbVar15;
              pbVar15 = pbVar15 + 4;
              pbVar17 = pbVar17 + 4;
            }
            for (uVar7 = bVar2 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
              *pbVar17 = *pbVar15;
              pbVar15 = pbVar15 + 1;
              pbVar17 = pbVar17 + 1;
            }
            iVar11 = iVar11 + (uint)*(byte *)((int)this + 0x11);
            iStack_738 = iStack_738 + 1;
            pbVar14 = pbVar14 + *(byte *)((int)this + 0x11);
            if (iStack_738 == *(int *)((int)this + 4)) {
              iStack_74c = iStack_74c + -1;
              pbStack_73c = pbStack_73c + -uVar9;
              iStack_738 = 0;
              if (param_4 != (undefined *)0x0) {
                (*(code *)param_4)(iStack_74c);
              }
              if (iStack_74c < 0) goto LAB_00536a5f;
              if (bVar18) {
                pbVar14 = pbStack_73c;
              }
              else {
                pbVar14 = (byte *)(pcVar5 + ((*(int *)((int)this + 8) - iStack_74c) + -1) * uVar9);
              }
            }
            iStack_730 = iStack_730 + 1;
          } while (iStack_730 < (int)(uVar10 + 1));
        }
      }
      else {
        abStack_724[0] = 0;
        abStack_724[1] = 0;
        abStack_724[2] = 0;
        abStack_724[3] = 0;
        if (0x3ff < (int)((uint)*(byte *)((int)this + 0x11) + iVar11)) {
          iVar13 = -iVar11;
          uVar7 = iVar13 + 0x400;
          pbVar15 = abStack_70c + iVar11;
          pbVar17 = abStack_70c;
          for (uVar12 = uVar7 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
            *(undefined4 *)pbVar17 = *(undefined4 *)pbVar15;
            pbVar15 = pbVar15 + 4;
            pbVar17 = pbVar17 + 4;
          }
          for (uVar12 = uVar7 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
            *pbVar17 = *pbVar15;
            pbVar15 = pbVar15 + 1;
            pbVar17 = pbVar17 + 1;
          }
          if (param_3 == (void *)0x0) {
            FUN_0054e978(acStack_30c + iVar13,1,0x400 - uVar7,(int *)local_750);
          }
          else {
            Resource_Read(param_3,acStack_30c + iVar13,0x400 - uVar7,(int)local_750);
          }
          iVar11 = 0;
        }
        pbVar15 = abStack_70c + iVar11;
        bVar2 = *(byte *)((int)this + 0x11);
        iStack_730 = 0;
        iVar11 = iVar11 + (uint)bVar2;
        pbVar17 = abStack_724;
        for (uVar7 = (uint)(bVar2 >> 2); uVar7 != 0; uVar7 = uVar7 - 1) {
          *(undefined4 *)pbVar17 = *(undefined4 *)pbVar15;
          pbVar15 = pbVar15 + 4;
          pbVar17 = pbVar17 + 4;
        }
        for (uVar7 = bVar2 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
          *pbVar17 = *pbVar15;
          pbVar15 = pbVar15 + 1;
          pbVar17 = pbVar17 + 1;
        }
        if ((uVar10 & 0x7f) != 0xffffffff) {
          pbStack_73c = (byte *)(pcVar5 + iStack_74c * uVar9);
          do {
            bVar2 = *(byte *)((int)this + 0x11);
            pbVar15 = abStack_724;
            pbVar17 = pbVar14;
            for (uVar7 = (uint)(bVar2 >> 2); uVar7 != 0; uVar7 = uVar7 - 1) {
              *(undefined4 *)pbVar17 = *(undefined4 *)pbVar15;
              pbVar15 = pbVar15 + 4;
              pbVar17 = pbVar17 + 4;
            }
            for (uVar7 = bVar2 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
              *pbVar17 = *pbVar15;
              pbVar15 = pbVar15 + 1;
              pbVar17 = pbVar17 + 1;
            }
            iStack_738 = iStack_738 + 1;
            pbVar14 = pbVar14 + *(byte *)((int)this + 0x11);
            if (iStack_738 == *(int *)((int)this + 4)) {
              iStack_74c = iStack_74c + -1;
              pbStack_73c = pbStack_73c + -uVar9;
              iStack_738 = 0;
              if (param_4 != (undefined *)0x0) {
                (*(code *)param_4)(iStack_74c);
              }
              if (iStack_74c < 0) goto LAB_00536a5f;
              if (bVar18) {
                pbVar14 = pbStack_73c;
              }
              else {
                pbVar14 = (byte *)(pcVar5 + ((*(int *)((int)this + 8) - iStack_74c) + -1) * uVar9);
              }
            }
            iStack_730 = iStack_730 + 1;
          } while (iStack_730 < (int)((uVar10 & 0x7f) + 1));
        }
      }
    } while (-1 < iStack_74c);
  }
  else {
    iVar11 = *(int *)((int)this + 8);
    iVar13 = 0;
    if (0 < iVar11) {
      pcStack_748 = pcVar5;
      do {
        if (param_4 != (undefined *)0x0) {
          (*(code *)param_4)((iVar11 - iVar13) + -1);
        }
        if (bVar18) {
          pcVar6 = pcVar5 + ((*(int *)((int)this + 8) - iVar13) + -1) * uVar9;
        }
        else {
          pcVar6 = pcStack_748;
        }
        if (param_3 == (void *)0x0) {
          FUN_0054e978(pcVar6,1,uVar9,(int *)local_750);
        }
        else {
          Resource_Read(param_3,pcVar6,uVar9,(int)local_750);
        }
        iVar11 = *(int *)((int)this + 8);
        iVar13 = iVar13 + 1;
        pcStack_748 = pcStack_748 + uVar9;
      } while (iVar13 < iVar11);
    }
  }
LAB_00536a5f:
  if (param_3 == (void *)0x0) {
    FUN_0054dee4(local_750);
  }
  else {
    Resource_Close(param_3,(int)local_750);
  }
  ExceptionList = local_c;
  return 1;
}

