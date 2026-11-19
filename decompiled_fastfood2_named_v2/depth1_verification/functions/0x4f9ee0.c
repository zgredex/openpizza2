// rea decompile_all
// name: FUN_004f9ee0
// address: 0x4f9ee0
// body: available
// range: 0x4f9ee0-0x4faaf3 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4
FUN_004f9ee0(int *param_1,uint param_2,uint param_3,int *param_4,int param_5,int param_6,int param_7
            ,char param_8)

{
  undefined1 *puVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  uint uVar10;
  undefined1 *puVar11;
  uint uVar12;
  short sVar13;
  int iVar14;
  undefined1 *puVar15;
  uint uVar16;
  int *piVar17;
  int *piVar18;
  char *pcVar19;
  int *piVar20;
  bool bVar21;
  char local_2d6;
  char local_2d5;
  int *local_2d4;
  int *local_2d0;
  uint local_2cc;
  int local_2c8;
  int *local_2c4;
  int *local_2c0;
  int *local_2bc;
  int local_2b8;
  int local_2b4;
  int local_2b0;
  uint local_2ac;
  uint local_2a8;
  int local_2a0;
  int local_29c;
  int local_298;
  void *local_294;
  int local_290;
  byte abStack_28c [32];
  undefined4 local_26c;
  int local_268 [32];
  int local_1e8 [32];
  int local_168 [30];
  int local_f0 [30];
  int local_78 [30];
  
  uVar12 = param_3;
  if (param_8 == ' ') {
    local_2d6 = '#';
    local_2d5 = 'W';
  }
  else if ((param_8 == '-') || (param_8 == '+')) {
    local_2d6 = '1';
    local_2d5 = '#';
  }
  else if (param_8 == '1') {
    local_2d5 = '1';
    local_2d6 = '1';
    param_8 = '-';
  }
  else if (param_8 == '2') {
    local_2d5 = '1';
    local_2d6 = '1';
    param_8 = '+';
  }
  local_2ac = param_2 * param_3;
  piVar17 = local_1e8;
  for (uVar6 = local_2ac >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *piVar17 = *param_4;
    param_4 = param_4 + 1;
    piVar17 = piVar17 + 1;
  }
  for (uVar6 = local_2ac & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(char *)piVar17 = (char)*param_4;
    param_4 = (int *)((int)param_4 + 1);
    piVar17 = (int *)((int)piVar17 + 1);
  }
  uVar6 = 0;
  FUN_004f3b30((void *)param_1[4],&local_2b8,&local_2b4,&local_298,&local_2b0);
  if (param_6 == 0) {
    local_2c8 = 0;
    local_2c4 = (int *)local_298;
    if (local_2b0 <= local_298) {
      return 0;
    }
    local_2d0 = (int *)0x0;
    uVar16 = local_2cc;
    do {
      if (0x1d < (int)uVar6) break;
      local_2cc = 0;
      local_2d4 = (int *)local_2b8;
      if (local_2b8 < local_2b4) {
        while ((int)uVar6 < 0x1e) {
          uVar10 = 0;
          if (0 < (int)param_3) {
            iVar14 = (int)local_2d0 + local_2cc + 0x28 + (int)param_1;
            do {
              uVar16 = 0;
              if (0 < (int)param_2) {
                do {
                  if (*(char *)(iVar14 + uVar16) != param_8) {
                    if ((int)uVar16 < (int)param_2) goto LAB_004fa55d;
                    break;
                  }
                  uVar16 = uVar16 + 1;
                } while ((int)uVar16 < (int)param_2);
              }
              uVar10 = uVar10 + 1;
              iVar14 = iVar14 + 0x50;
            } while ((int)uVar10 < (int)param_3);
          }
LAB_004fa55d:
          if ((uVar10 == param_3) && (uVar16 == param_2)) {
            local_78[uVar6] = (int)local_2d4;
            local_f0[uVar6] = (int)local_2c4;
            local_168[uVar6] = local_2cc;
            local_268[uVar6] = local_2c8;
            uVar10 = _rand();
            if ((uVar10 & 1) == 0) {
              abStack_28c[uVar6] = 2;
            }
            else {
              abStack_28c[uVar6] = 0;
            }
            uVar6 = uVar6 + 1;
            if (uVar6 == 0x1e) break;
          }
          uVar10 = 0;
          if (0 < (int)param_2) {
            pcVar19 = (char *)((int)local_2d0 + local_2cc + 0x28 + (int)param_1);
            do {
              uVar16 = 0;
              if (0 < (int)param_3) {
                pcVar9 = pcVar19;
                do {
                  if (*pcVar9 != param_8) {
                    if ((int)uVar16 < (int)param_3) goto LAB_004fa60a;
                    break;
                  }
                  uVar16 = uVar16 + 1;
                  pcVar9 = pcVar9 + 1;
                } while ((int)uVar16 < (int)param_3);
              }
              uVar10 = uVar10 + 1;
              pcVar19 = pcVar19 + 0x50;
            } while ((int)uVar10 < (int)param_2);
          }
LAB_004fa60a:
          if ((uVar10 == param_2) && (uVar16 == param_3)) {
            local_78[uVar6] = (int)local_2d4;
            local_f0[uVar6] = (int)local_2c4;
            local_168[uVar6] = local_2cc;
            local_268[uVar6] = local_2c8;
            uVar10 = _rand();
            if ((uVar10 & 1) == 0) {
              abStack_28c[uVar6] = 3;
            }
            else {
              abStack_28c[uVar6] = 1;
            }
            break;
          }
          local_2cc = local_2cc + 1;
          local_2d4 = (int *)((int)local_2d4 + 1);
          if (local_2b4 <= (int)local_2d4) break;
        }
      }
      local_2c8 = local_2c8 + 1;
      local_2d0 = (int *)((int)local_2d0 + 0x50);
      local_2c4 = (int *)((int)local_2c4 + 1);
    } while ((int)local_2c4 < local_2b0);
  }
  else {
    local_2c8 = 0;
    local_2c4 = (int *)local_298;
    if (local_2b0 <= local_298) {
      return 0;
    }
    do {
      if (0x1d < (int)uVar6) break;
      iVar14 = 0;
      if (local_2b8 < local_2b4) {
        local_2d4 = local_78 + uVar6;
        local_2d0 = local_268 + uVar6;
        local_2bc = local_168 + uVar6;
        local_2c0 = local_f0 + uVar6;
        local_2a8 = 1 - local_2b8;
        do {
          if (0x1d < (int)uVar6) break;
          iVar7 = local_2c8 * 0x50;
          cVar2 = *(char *)(iVar7 + iVar14 + 0x28 + (int)param_1);
          if ((cVar2 == local_2d6) || (cVar2 == local_2d5)) {
            if (param_8 != '-') {
              local_2cc = 1;
              bVar21 = param_2 == 1;
              if (1 < (int)param_2) {
                do {
                  cVar2 = *(char *)((int)param_1 + local_2cc + iVar7 + iVar14 + 0x28);
                  if ((cVar2 != local_2d6) && (cVar2 != local_2d5)) break;
                  local_2cc = local_2cc + 1;
                } while ((int)local_2cc < (int)param_2);
                bVar21 = local_2cc == param_2;
              }
              if (bVar21) {
                uVar16 = 0;
                if (0 < (int)param_3) {
                  iVar8 = iVar7 + iVar14 + 0x78 + (int)param_1;
                  do {
                    local_2cc = 0;
                    if (0 < (int)param_2) {
                      do {
                        if (*(char *)(iVar8 + local_2cc) != param_8) {
                          if ((int)local_2cc < (int)param_2) goto LAB_004fa102;
                          break;
                        }
                        local_2cc = local_2cc + 1;
                      } while ((int)local_2cc < (int)param_2);
                    }
                    uVar16 = uVar16 + 1;
                    iVar8 = iVar8 + 0x50;
                  } while ((int)uVar16 < (int)param_3);
                }
LAB_004fa102:
                if ((uVar16 == param_3) && (local_2cc == param_2)) {
                  abStack_28c[uVar6] = 0;
                  uVar6 = uVar6 + 1;
                  *local_2d4 = iVar14 + local_2b8;
                  *local_2c0 = (int)local_2c4;
                  *local_2bc = iVar14;
                  *local_2d0 = local_2c8 + 1;
                  local_2c0 = local_2c0 + 1;
                  local_2d0 = local_2d0 + 1;
                  local_2bc = local_2bc + 1;
                  local_2d4 = local_2d4 + 1;
                  if (uVar6 == 0x1e) break;
                }
                uVar16 = 0;
                if (0 < (int)param_3) {
                  pcVar19 = (char *)(iVar7 + iVar14 + -0x28 + (int)param_1);
                  do {
                    local_2cc = 0;
                    if (0 < (int)param_2) {
                      pcVar9 = pcVar19;
                      do {
                        if (*pcVar9 != param_8) {
                          if ((int)local_2cc < (int)param_2) goto LAB_004fa1d4;
                          break;
                        }
                        local_2cc = local_2cc + 1;
                        pcVar9 = pcVar9 + 1;
                      } while ((int)local_2cc < (int)param_2);
                    }
                    uVar16 = uVar16 + 1;
                    pcVar19 = pcVar19 + -0x50;
                  } while ((int)uVar16 < (int)param_3);
                }
LAB_004fa1d4:
                if ((uVar16 == param_3) && (local_2cc == param_2)) {
                  abStack_28c[uVar6] = 2;
                  *local_2d4 = iVar14 + local_2b8;
                  *local_2c0 = (int)local_2c4;
                  *local_2bc = iVar14;
                  *local_2d0 = local_2c8;
                  uVar16 = param_3;
                  if (0 < (int)param_3) {
                    do {
                      *local_2c0 = *local_2c0 + -1;
                      *local_2d0 = *local_2d0 + -1;
                      uVar16 = uVar16 - 1;
                    } while (uVar16 != 0);
                  }
                  local_2d0 = local_2d0 + 1;
                  local_2c0 = local_2c0 + 1;
                  uVar6 = uVar6 + 1;
                  local_2bc = local_2bc + 1;
                  local_2d4 = local_2d4 + 1;
                  if (uVar6 == 0x1e) break;
                }
              }
            }
            uVar16 = 1;
            bVar21 = param_2 == 1;
            if (1 < (int)param_2) {
              pcVar19 = (char *)(iVar7 + iVar14 + 0x78 + (int)param_1);
              do {
                if ((*pcVar19 != local_2d6) && (*pcVar19 != local_2d5)) break;
                uVar16 = uVar16 + 1;
                pcVar19 = pcVar19 + 0x50;
              } while ((int)uVar16 < (int)param_2);
              bVar21 = uVar16 == param_2;
            }
            if (bVar21) {
              if (param_8 != '-') {
                uVar16 = 0;
                if (0 < (int)param_2) {
                  pcVar19 = (char *)(iVar7 + iVar14 + 0x27 + (int)param_1);
                  do {
                    local_2cc = 0;
                    if (0 < (int)param_3) {
                      pcVar9 = pcVar19;
                      do {
                        if (*pcVar9 != param_8) {
                          if ((int)local_2cc < (int)param_3) goto LAB_004fa313;
                          break;
                        }
                        local_2cc = local_2cc + 1;
                        pcVar9 = pcVar9 + -1;
                      } while ((int)local_2cc < (int)param_3);
                    }
                    uVar16 = uVar16 + 1;
                    pcVar19 = pcVar19 + 0x50;
                  } while ((int)uVar16 < (int)param_2);
                }
LAB_004fa313:
                if ((uVar16 == param_2) && (local_2cc == param_3)) {
                  abStack_28c[uVar6] = 1;
                  *local_2d4 = iVar14 + local_2b8;
                  *local_2c0 = (int)local_2c4;
                  *local_2bc = iVar14;
                  *local_2d0 = local_2c8;
                  uVar16 = param_3;
                  if (0 < (int)param_3) {
                    do {
                      *local_2d4 = *local_2d4 + -1;
                      *local_2bc = *local_2bc + -1;
                      uVar16 = uVar16 - 1;
                    } while (uVar16 != 0);
                  }
                  uVar6 = uVar6 + 1;
                  local_2c0 = local_2c0 + 1;
                  local_2bc = local_2bc + 1;
                  local_2d0 = local_2d0 + 1;
                  local_2d4 = local_2d4 + 1;
                  if (uVar6 == 0x1e) break;
                }
              }
              uVar16 = 0;
              if (0 < (int)param_2) {
                pcVar19 = (char *)(iVar7 + iVar14 + 0x29 + (int)param_1);
                do {
                  local_2cc = 0;
                  if (0 < (int)param_3) {
                    pcVar9 = pcVar19;
                    do {
                      if (*pcVar9 != param_8) {
                        if ((int)local_2cc < (int)param_3) goto LAB_004fa403;
                        break;
                      }
                      local_2cc = local_2cc + 1;
                      pcVar9 = pcVar9 + 1;
                    } while ((int)local_2cc < (int)param_3);
                  }
                  uVar16 = uVar16 + 1;
                  pcVar19 = pcVar19 + 0x50;
                } while ((int)uVar16 < (int)param_2);
              }
LAB_004fa403:
              if ((uVar16 == param_2) && (local_2cc == param_3)) {
                *local_2c0 = (int)local_2c4;
                iVar7 = local_2a8 + iVar14 + local_2b8;
                abStack_28c[uVar6] = 3;
                *local_2bc = iVar7;
                *local_2d0 = local_2c8;
                uVar6 = uVar6 + 1;
                *local_2d4 = iVar7 + local_2b8;
                local_2c0 = local_2c0 + 1;
                local_2d4 = local_2d4 + 1;
                local_2bc = local_2bc + 1;
                local_2d0 = local_2d0 + 1;
                if (uVar6 == 0x1e) break;
              }
            }
          }
          iVar14 = iVar14 + 1;
        } while (iVar14 + local_2b8 < local_2b4);
      }
      local_2c8 = local_2c8 + 1;
      local_2c4 = (int *)((int)local_2c4 + 1);
    } while ((int)local_2c4 < local_2b0);
  }
  if (uVar6 == 0) {
    return 0;
  }
  if (param_7 == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = Random_Mod(uVar6);
  }
  local_2d0 = (int *)local_78[uVar6];
  local_2c8 = local_f0[uVar6];
  iVar14 = local_168[uVar6];
  local_2a8 = (uint)abStack_28c[uVar6];
  iVar7 = local_268[uVar6];
  if ((local_2a8 == 1) || (uVar6 = param_2, local_2a8 == 3)) {
    iVar8 = 0;
    if (0 < (int)param_3) {
      piVar17 = local_1e8;
      do {
        iVar4 = 0;
        if (0 < (int)param_2) {
          puVar11 = (undefined1 *)((int)local_268 + iVar8);
          do {
            puVar15 = (undefined1 *)((int)piVar17 + iVar4);
            iVar4 = iVar4 + 1;
            *puVar11 = *puVar15;
            puVar11 = puVar11 + param_3;
          } while (iVar4 < (int)param_2);
        }
        iVar8 = iVar8 + 1;
        piVar17 = (int *)((int)piVar17 + param_2);
      } while (iVar8 < (int)param_3);
    }
    piVar17 = local_268;
    piVar5 = local_1e8;
    for (uVar6 = local_2ac >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *piVar5 = *piVar17;
      piVar17 = piVar17 + 1;
      piVar5 = piVar5 + 1;
    }
    for (uVar6 = local_2ac & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(char *)piVar5 = (char)*piVar17;
      piVar17 = (int *)((int)piVar17 + 1);
      piVar5 = (int *)((int)piVar5 + 1);
    }
    param_3 = param_2;
    uVar6 = uVar12;
    if (local_2a8 != 1) goto LAB_004fa7c3;
    if (0 < (int)param_2) {
      piVar17 = local_1e8;
      puVar11 = (undefined1 *)((int)&local_26c + 3);
      uVar6 = param_2;
      do {
        puVar11 = puVar11 + uVar12;
        iVar8 = 0;
        if (0 < (int)uVar12) {
          puVar15 = puVar11;
          do {
            puVar1 = (undefined1 *)((int)piVar17 + iVar8);
            iVar8 = iVar8 + 1;
            *puVar15 = *puVar1;
            puVar15 = puVar15 + -1;
          } while (iVar8 < (int)uVar12);
        }
        piVar17 = (int *)((int)piVar17 + uVar12);
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    uVar6 = param_2 * uVar12;
    param_2 = uVar12;
  }
  else {
LAB_004fa7c3:
    param_2 = uVar6;
    if (local_2a8 != 2) goto LAB_004fa843;
    if (0 < (int)param_3) {
      piVar5 = local_1e8;
      local_2cc = param_3;
      piVar17 = (int *)((int)local_268 + (param_3 - 1) * param_2);
      do {
        if (0 < (int)param_2) {
          piVar18 = piVar5;
          piVar20 = piVar17;
          for (uVar12 = param_2 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
            *piVar20 = *piVar18;
            piVar18 = piVar18 + 1;
            piVar20 = piVar20 + 1;
          }
          for (uVar12 = param_2 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
            *(char *)piVar20 = (char)*piVar18;
            piVar18 = (int *)((int)piVar18 + 1);
            piVar20 = (int *)((int)piVar20 + 1);
          }
        }
        piVar17 = (int *)((int)piVar17 - param_2);
        piVar5 = (int *)((int)piVar5 + param_2);
        local_2cc = local_2cc - 1;
      } while (local_2cc != 0);
    }
    uVar6 = param_2 * param_3;
  }
  piVar17 = local_268;
  piVar5 = local_1e8;
  for (uVar12 = uVar6 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
    *piVar5 = *piVar17;
    piVar17 = piVar17 + 1;
    piVar5 = piVar5 + 1;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(char *)piVar5 = (char)*piVar17;
    piVar17 = (int *)((int)piVar17 + 1);
    piVar5 = (int *)((int)piVar5 + 1);
  }
LAB_004fa843:
  local_2bc = (int *)0x0;
  if ((int)param_3 < 1) {
    return 1;
  }
  local_2c0 = local_1e8;
  local_2d4 = (int *)(iVar7 * 0x50 + iVar14 + 0x28 + (int)param_1);
  do {
    local_2cc = 0;
    local_290 = (int)local_2d0;
    if (0 < (int)param_2) {
      local_2c4 = local_2c0;
      do {
        *(undefined1 *)((int)local_2d4 + local_2cc) = 0x78;
        if ((char)*local_2c4 != ' ') {
          iVar7 = 0;
          uVar6 = (uint)(char)*local_2c4;
          iVar14 = 0;
          uVar12 = local_2cc;
          while( true ) {
            piVar17 = local_2c4;
            piVar5 = local_2bc;
            if (((int)param_2 <= (int)uVar12) || ((int)*(char *)((int)local_2c4 + iVar14) != uVar6))
            break;
            uVar12 = uVar12 + 1;
            iVar14 = iVar14 + 1;
          }
          for (; ((int)piVar5 < (int)param_3 && ((int)(char)*piVar17 == uVar6));
              piVar17 = (int *)((int)piVar17 + param_2)) {
            iVar7 = iVar7 + 1;
            piVar5 = (int *)((int)piVar5 + 1);
          }
          uVar12 = FUN_0054f8a9(uVar6);
          iVar8 = *(int *)(param_5 + (uVar12 - 0x61) * 8);
          iVar4 = *(int *)(param_5 + 4 + (uVar12 - 0x61) * 8) - iVar8;
          if (local_2a8 == 1) {
            if (iVar4 < 3) {
joined_r0x004fa959:
              if (0 < iVar4) {
                iVar8 = iVar8 + 1;
              }
            }
            else {
              iVar8 = iVar8 + 3;
            }
          }
          else if (local_2a8 == 2) {
            if (1 < iVar4) {
              iVar8 = iVar8 + 2;
            }
          }
          else if (local_2a8 == 3) goto joined_r0x004fa959;
          City_FindListContainingValue(iVar8,(int *)&local_2ac,&local_26c);
          if (0 < (int)local_2ac) {
            local_294 = (void *)FUN_004017f0((void *)(DAT_0057c670 + 0x74),local_2ac,(int *)0x0);
          }
          FUN_004e4160(local_294,&local_2a0,&local_29c);
          if ((((local_2a0 == 0) || (10 < local_2a0)) || (local_29c == 0)) || (10 < local_29c))
          break;
          if ((local_2a0 <= iVar14) && (local_29c <= iVar7)) {
            if (local_2a0 == 3) {
              sVar13 = (short)local_2d0 + 1;
            }
            else {
              sVar13 = (short)local_2d0;
              if ((3 < local_2a0) && (local_2a0 < 6)) {
                sVar13 = (short)local_2d0 + 2;
              }
            }
            sVar3 = (short)local_2c8;
            switch(local_29c) {
            case 2:
              sVar3 = (short)local_2c8 + 1;
              break;
            case 3:
              sVar3 = (short)local_2c8 + 1;
              break;
            case 4:
              sVar3 = (short)local_2c8 + 3;
              break;
            case 5:
              sVar3 = (short)local_2c8 + 2;
            }
            FUN_004f9df0(param_1,iVar8,sVar13,sVar3,2,1,0);
            if (0 < local_2a0) {
              piVar17 = local_2c4;
              iVar14 = local_2a0;
              do {
                if (0 < local_29c) {
                  piVar5 = piVar17;
                  iVar7 = local_29c;
                  do {
                    *(char *)piVar5 = ' ';
                    piVar5 = (int *)((int)piVar5 + param_2);
                    iVar7 = iVar7 + -1;
                  } while (iVar7 != 0);
                }
                piVar17 = (int *)((int)piVar17 + 1);
                iVar14 = iVar14 + -1;
              } while (iVar14 != 0);
            }
          }
        }
        local_2d0 = (int *)((int)local_2d0 + 1);
        local_2cc = local_2cc + 1;
        local_2c4 = (int *)((int)local_2c4 + 1);
      } while ((int)local_2cc < (int)param_2);
    }
    local_2d0 = (int *)local_290;
    local_2c8 = local_2c8 + 1;
    local_2c0 = (int *)((int)local_2c0 + param_2);
    local_2bc = (int *)((int)local_2bc + 1);
    local_2d4 = (int *)((int)local_2d4 + 0x50);
    if ((int)param_3 <= (int)local_2bc) {
      return 1;
    }
  } while( true );
}

