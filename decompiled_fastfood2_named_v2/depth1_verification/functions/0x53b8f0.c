// rea decompile_all
// name: FUN_0053b8f0
// address: 0x53b8f0
// body: available
// range: 0x53b8f0-0x53bee9 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall
FUN_0053b8f0(void *this,void *param_1,byte *param_2,int param_3,int param_4,int param_5,
            undefined4 param_6,uint param_7)

{
  byte bVar1;
  short *psVar2;
  bool bVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  short sVar12;
  byte *pbVar13;
  byte *pbVar14;
  short *psVar15;
  short *psVar16;
  int local_228 [128];
  undefined4 local_28;
  int *local_24;
  short *local_20;
  uint local_1c;
  int local_18;
  uint local_14;
  int local_10;
  short *local_c;
  int local_8;
  
  local_24 = local_228;
  local_20 = (short *)0x0;
  if (param_2 != (byte *)0x0) {
    local_28 = Color_RGBTo16FromDword(param_1,param_7);
    if (*(int *)((int)param_1 + 0x28) != 0) {
      local_8 = (int)*(short *)((int)this + 8);
      local_14 = (uint)*(short *)((int)this + 6);
      local_10 = *(int *)((int)param_1 + 0x20);
      if (8 < *(byte *)((int)this + 5)) {
        local_14 = (int)local_14 >> 1;
      }
      if ((*(byte *)((int)this + 4) & 4) == 0) {
        iVar9 = param_4;
        iVar8 = param_5;
      }
      else {
        iVar9 = param_4 + *(short *)((int)this + 10);
        iVar8 = param_5 + *(short *)((int)this + 0xc);
      }
      param_4 = 0;
      param_5 = 0;
      param_7 = local_14;
      if (iVar9 < *(int *)((int)param_1 + 4)) {
        param_7 = local_14 + (iVar9 - *(int *)((int)param_1 + 4));
        param_5 = *(int *)((int)param_1 + 4) - iVar9;
        iVar9 = *(int *)((int)param_1 + 4);
      }
      if (*(int *)((int)param_1 + 8) < (int)(param_7 + iVar9)) {
        param_7 = *(int *)((int)param_1 + 8) - iVar9;
      }
      iVar5 = iVar8;
      if (iVar8 < *(int *)((int)param_1 + 0xc)) {
        local_8 = local_8 + (iVar8 - *(int *)((int)param_1 + 0xc));
        iVar5 = *(int *)((int)param_1 + 0xc);
        param_4 = iVar5 - iVar8;
      }
      if (*(int *)((int)param_1 + 0x10) < local_8 + iVar5) {
        local_8 = *(int *)((int)param_1 + 0x10) - iVar5;
      }
      if ((0 < (int)param_7) && (0 < local_8)) {
        local_c = (short *)(*(int *)((int)param_1 + 0x28) + iVar9 * 3 + local_10 * iVar5);
        uVar11 = *(uint *)((int)this + 0x1c);
        local_18 = (local_14 - param_5) - param_7;
        param_1._3_1_ = (byte)uVar11;
        switch(param_6) {
        case 0:
          for (; iVar9 = param_5, param_4 != 0; param_4 = param_4 + -1) {
            uVar10 = local_14;
            pbVar13 = param_2;
            do {
              while (param_2 = pbVar13 + 1, *pbVar13 == uVar11) {
                pbVar13 = pbVar13 + 2;
                uVar10 = uVar10 - *param_2;
                param_2 = pbVar13;
                if (uVar10 == 0) goto LAB_0053ba67;
              }
              uVar10 = uVar10 - 1;
              pbVar13 = param_2;
            } while (uVar10 != 0);
LAB_0053ba67:
          }
          do {
            for (; uVar11 = param_7, psVar16 = local_c, iVar9 != 0; iVar9 = iVar9 + -1) {
              while (*param_2 == param_1._3_1_) {
                pbVar13 = param_2 + 2;
                iVar8 = iVar9 - (uint)param_2[1];
                bVar3 = iVar9 < (int)(uint)param_2[1];
                iVar9 = iVar8;
                param_2 = pbVar13;
                if (iVar8 == 0 || bVar3) {
                  psVar16 = (short *)((int)local_c + iVar8 * -3);
                  uVar11 = param_7 + iVar8;
                  goto joined_r0x0053baa6;
                }
              }
              param_2 = param_2 + 1;
            }
            do {
              while (pbVar13 = param_2 + 1, *param_2 == param_1._3_1_) {
                pbVar13 = param_2 + 2;
                psVar16 = (short *)((int)psVar16 + (uint)param_2[1] * 3);
                uVar11 = uVar11 - param_2[1];
joined_r0x0053baa6:
                param_2 = pbVar13;
                if ((int)uVar11 < 1) goto LAB_0053bad5;
              }
              *psVar16 = -1;
              uVar11 = uVar11 - 1;
              param_2 = pbVar13;
              psVar16 = (short *)((int)psVar16 + 3);
            } while (uVar11 != 0);
            uVar11 = 0;
LAB_0053bad5:
            for (iVar9 = local_18 + uVar11; pbVar14 = pbVar13, iVar9 != 0;
                iVar9 = iVar9 - (uint)pbVar14[1]) {
              while (pbVar13 = pbVar14 + 1, *pbVar14 != param_1._3_1_) {
                iVar9 = iVar9 + -1;
                pbVar14 = pbVar13;
                if (iVar9 == 0) goto LAB_0053baf8;
              }
              pbVar13 = pbVar14 + 2;
            }
LAB_0053baf8:
            local_c = (short *)((int)local_c + local_10);
            local_8 = local_8 + -1;
            param_2 = pbVar13;
            iVar9 = param_5;
            if (local_8 == 0) {
              return;
            }
          } while( true );
        case 1:
          piVar4 = local_228;
          local_1c = uVar11;
          for (iVar9 = 0x80; iVar9 != 0; iVar9 = iVar9 + -1) {
            *piVar4 = 0;
            piVar4 = piVar4 + 1;
          }
          for (; iVar9 = param_5, psVar16 = local_c, iVar8 = local_8, param_4 != 0;
              param_4 = param_4 + -1) {
            uVar10 = local_14;
            pbVar13 = param_2;
            do {
              while (param_2 = pbVar13 + 1, *pbVar13 == local_1c) {
                pbVar13 = pbVar13 + 2;
                uVar10 = uVar10 - *param_2;
                param_2 = pbVar13;
                if (uVar10 == 0) goto LAB_0053bb40;
              }
              uVar10 = uVar10 - 1;
              pbVar13 = param_2;
            } while (uVar10 != 0);
LAB_0053bb40:
          }
joined_r0x0053bb56:
          do {
            uVar10 = param_7;
            pbVar13 = param_2;
            psVar15 = psVar16;
            if (iVar9 == 0) {
LAB_0053bb83:
              uVar6 = uVar11 & 0xff;
              piVar4 = local_24;
              pbVar13 = param_2;
              do {
                while( true ) {
                  psVar2 = local_20;
                  param_2 = pbVar13 + 1;
                  sVar12 = (short)local_28;
                  if (*pbVar13 == (byte)uVar6) break;
                  if (*psVar15 == -1) {
                    local_20 = (short *)0x0;
                    *piVar4 = (int)psVar15;
                  }
                  else {
                    iVar9 = *piVar4;
                    *piVar4 = (int)psVar15;
                    if (iVar9 == 0) {
                      uVar6 = uVar6 & 0xfffeffff;
                    }
                    local_20 = psVar15;
                    if ((uVar6 & 0x10000) == 0) {
                      *psVar15 = sVar12;
                    }
                  }
                  psVar2 = local_20;
                  piVar4 = piVar4 + 1;
                  uVar6 = uVar6 | 0x10000;
                  psVar15 = (short *)((int)psVar15 + 3);
                  uVar10 = uVar10 - 1;
                  pbVar13 = param_2;
                  if (uVar10 == 0) {
                    uVar10 = 0;
                    if (local_20 != (short *)0x0) {
                      local_20 = (short *)0x0;
                      *psVar2 = sVar12;
                    }
                    goto LAB_0053bc41;
                  }
                }
                if (((uVar6 & 0x10000) != 0) &&
                   (uVar6 = uVar6 & 0xfffeffff, local_20 != (short *)0x0)) {
                  local_20 = (short *)0x0;
                  *psVar2 = sVar12;
                }
                param_2 = pbVar13 + 2;
                uVar7 = (uint)pbVar13[1];
                uVar10 = uVar10 - uVar7;
                psVar15 = (short *)((int)psVar15 + uVar7 * 3);
                do {
                  psVar2 = (short *)*piVar4;
                  if ((psVar2 != (short *)0x0) && (*piVar4 = 0, *psVar2 != -1)) {
                    *psVar2 = sVar12;
                  }
                  piVar4 = piVar4 + 1;
                  uVar7 = uVar7 - 1;
                } while (uVar7 != 0);
                pbVar13 = param_2;
              } while (0 < (int)uVar10);
            }
            else {
              do {
                param_2 = pbVar13 + 1;
                if (*pbVar13 != param_1._3_1_) {
                  iVar9 = iVar9 + -1;
                  goto joined_r0x0053bb56;
                }
                param_2 = pbVar13 + 2;
                iVar5 = iVar9 - (uint)pbVar13[1];
                bVar3 = (int)(uint)pbVar13[1] <= iVar9;
                iVar9 = iVar5;
                pbVar13 = param_2;
              } while (iVar5 != 0 && bVar3);
              psVar15 = (short *)((int)psVar16 + iVar5 * -3);
              uVar10 = param_7 + iVar5;
              if (0 < (int)uVar10) goto LAB_0053bb83;
            }
LAB_0053bc41:
            for (iVar9 = local_18 + uVar10; pbVar13 = param_2, iVar9 != 0;
                iVar9 = iVar9 - (uint)pbVar13[1]) {
              while (param_2 = pbVar13 + 1, *pbVar13 != param_1._3_1_) {
                iVar9 = iVar9 + -1;
                pbVar13 = param_2;
                if (iVar9 == 0) goto LAB_0053bc64;
              }
              param_2 = pbVar13 + 2;
            }
LAB_0053bc64:
            iVar8 = iVar8 + -1;
            iVar9 = param_5;
            psVar16 = (short *)((int)psVar16 + local_10);
            if (iVar8 == 0) {
              return;
            }
          } while( true );
        case 2:
          for (; iVar9 = param_5, param_4 != 0; param_4 = param_4 + -1) {
            uVar10 = local_14;
            pbVar13 = param_2;
            do {
              while (param_2 = pbVar13 + 1, *pbVar13 == uVar11) {
                pbVar13 = pbVar13 + 2;
                uVar10 = uVar10 - *param_2;
                param_2 = pbVar13;
                if (uVar10 == 0) goto LAB_0053bc9d;
              }
              uVar10 = uVar10 - 1;
              pbVar13 = param_2;
            } while (uVar10 != 0);
LAB_0053bc9d:
          }
          do {
            for (; uVar11 = param_7, psVar16 = local_c, iVar9 != 0; iVar9 = iVar9 + -1) {
              while (*param_2 == param_1._3_1_) {
                pbVar13 = param_2 + 2;
                iVar8 = iVar9 - (uint)param_2[1];
                bVar3 = iVar9 < (int)(uint)param_2[1];
                iVar9 = iVar8;
                param_2 = pbVar13;
                if (iVar8 == 0 || bVar3) {
                  psVar16 = (short *)((int)local_c + iVar8 * -3);
                  uVar11 = param_7 + iVar8;
                  goto joined_r0x0053bcda;
                }
              }
              param_2 = param_2 + 1;
            }
            do {
              while( true ) {
                pbVar13 = param_2 + 1;
                if (*param_2 != param_1._3_1_) break;
                pbVar13 = param_2 + 2;
                psVar16 = (short *)((int)psVar16 + (uint)param_2[1] * 3);
                uVar11 = uVar11 - param_2[1];
joined_r0x0053bcda:
                param_2 = pbVar13;
                if ((int)uVar11 < 1) goto LAB_0053bd13;
              }
              if (*psVar16 == -1) {
                *psVar16 = *(short *)(param_3 + (uint)*param_2 * 2);
              }
              uVar11 = uVar11 - 1;
              param_2 = pbVar13;
              psVar16 = (short *)((int)psVar16 + 3);
            } while (uVar11 != 0);
            uVar11 = 0;
LAB_0053bd13:
            for (iVar9 = local_18 + uVar11; pbVar14 = pbVar13, iVar9 != 0;
                iVar9 = iVar9 - (uint)pbVar14[1]) {
              while (pbVar13 = pbVar14 + 1, *pbVar14 != param_1._3_1_) {
                iVar9 = iVar9 + -1;
                pbVar14 = pbVar13;
                if (iVar9 == 0) goto LAB_0053bd36;
              }
              pbVar13 = pbVar14 + 2;
            }
LAB_0053bd36:
            local_c = (short *)((int)local_c + local_10);
            local_8 = local_8 + -1;
            param_2 = pbVar13;
            iVar9 = param_5;
            if (local_8 == 0) {
              return;
            }
          } while( true );
        case 0xfffffffe:
          for (; iVar9 = param_5, param_4 != 0; param_4 = param_4 + -1) {
            uVar10 = local_14;
            pbVar13 = param_2;
            do {
              while (param_2 = pbVar13 + 1, *pbVar13 == uVar11) {
                pbVar13 = pbVar13 + 2;
                uVar10 = uVar10 - *param_2;
                param_2 = pbVar13;
                if (uVar10 == 0) goto LAB_0053bd6f;
              }
              uVar10 = uVar10 - 1;
              pbVar13 = param_2;
            } while (uVar10 != 0);
LAB_0053bd6f:
          }
          do {
            for (; uVar11 = param_7, psVar16 = local_c, iVar9 != 0; iVar9 = iVar9 + -1) {
              while (*param_2 == param_1._3_1_) {
                pbVar13 = param_2 + 2;
                iVar8 = iVar9 - (uint)param_2[1];
                bVar3 = iVar9 < (int)(uint)param_2[1];
                iVar9 = iVar8;
                param_2 = pbVar13;
                if (iVar8 == 0 || bVar3) {
                  psVar16 = (short *)((int)local_c + iVar8 * -3);
                  uVar11 = param_7 + iVar8;
                  goto joined_r0x0053bdac;
                }
              }
              param_2 = param_2 + 1;
            }
            do {
              while( true ) {
                pbVar13 = param_2 + 1;
                bVar1 = *param_2;
                if (bVar1 != param_1._3_1_) break;
                pbVar13 = param_2 + 2;
                psVar16 = (short *)((int)psVar16 + (uint)param_2[1] * 3);
                uVar11 = uVar11 - param_2[1];
joined_r0x0053bdac:
                param_2 = pbVar13;
                if ((int)uVar11 < 1) goto LAB_0053bde6;
              }
              if ((*psVar16 != -1) && (bVar1 < *(byte *)(psVar16 + 1))) {
                *(byte *)(psVar16 + 1) = bVar1;
              }
              uVar11 = uVar11 - 1;
              param_2 = pbVar13;
              psVar16 = (short *)((int)psVar16 + 3);
            } while (uVar11 != 0);
            uVar11 = 0;
LAB_0053bde6:
            for (iVar9 = local_18 + uVar11; pbVar14 = pbVar13, iVar9 != 0;
                iVar9 = iVar9 - (uint)pbVar14[1]) {
              while (pbVar13 = pbVar14 + 1, *pbVar14 != param_1._3_1_) {
                iVar9 = iVar9 + -1;
                pbVar14 = pbVar13;
                if (iVar9 == 0) goto LAB_0053be09;
              }
              pbVar13 = pbVar14 + 2;
            }
LAB_0053be09:
            local_c = (short *)((int)local_c + local_10);
            local_8 = local_8 + -1;
            param_2 = pbVar13;
            iVar9 = param_5;
            if (local_8 == 0) {
              return;
            }
          } while( true );
        case 0xffffffff:
          for (; iVar9 = param_5, param_4 != 0; param_4 = param_4 + -1) {
            uVar10 = local_14;
            pbVar13 = param_2;
            do {
              while (param_2 = pbVar13 + 1, *pbVar13 == uVar11) {
                pbVar13 = pbVar13 + 2;
                uVar10 = uVar10 - *param_2;
                param_2 = pbVar13;
                if (uVar10 == 0) goto LAB_0053be42;
              }
              uVar10 = uVar10 - 1;
              pbVar13 = param_2;
            } while (uVar10 != 0);
LAB_0053be42:
          }
          do {
            for (; uVar11 = param_7, psVar16 = local_c, iVar9 != 0; iVar9 = iVar9 + -1) {
              while (*param_2 == param_1._3_1_) {
                pbVar13 = param_2 + 2;
                iVar8 = iVar9 - (uint)param_2[1];
                bVar3 = iVar9 < (int)(uint)param_2[1];
                iVar9 = iVar8;
                param_2 = pbVar13;
                if (iVar8 == 0 || bVar3) {
                  psVar16 = (short *)((int)local_c + iVar8 * -3);
                  uVar11 = param_7 + iVar8;
                  goto joined_r0x0053be7f;
                }
              }
              param_2 = param_2 + 1;
            }
            do {
              while( true ) {
                pbVar13 = param_2 + 1;
                if (*param_2 != param_1._3_1_) break;
                pbVar13 = param_2 + 2;
                psVar16 = (short *)((int)psVar16 + (uint)param_2[1] * 3);
                uVar11 = uVar11 - param_2[1];
joined_r0x0053be7f:
                param_2 = pbVar13;
                if ((int)uVar11 < 1) goto LAB_0053beb2;
              }
              *psVar16 = *(short *)(param_3 + (uint)*param_2 * 2);
              uVar11 = uVar11 - 1;
              param_2 = pbVar13;
              psVar16 = (short *)((int)psVar16 + 3);
            } while (uVar11 != 0);
            uVar11 = 0;
LAB_0053beb2:
            for (iVar9 = local_18 + uVar11; pbVar14 = pbVar13, iVar9 != 0;
                iVar9 = iVar9 - (uint)pbVar14[1]) {
              while (pbVar13 = pbVar14 + 1, *pbVar14 != param_1._3_1_) {
                iVar9 = iVar9 + -1;
                pbVar14 = pbVar13;
                if (iVar9 == 0) goto LAB_0053bed5;
              }
              pbVar13 = pbVar14 + 2;
            }
LAB_0053bed5:
            local_c = (short *)((int)local_c + local_10);
            local_8 = local_8 + -1;
            param_2 = pbVar13;
            iVar9 = param_5;
          } while (local_8 != 0);
        }
      }
    }
  }
  return;
}

