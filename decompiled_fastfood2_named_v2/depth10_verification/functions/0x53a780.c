// rea decompile_all
// name: FUN_0053a780
// address: 0x53a780
// body: available
// range: 0x53a780-0x53a965 inclusive
// range: 0x53a970-0x53aa34 inclusive
// range: 0x53aa40-0x53abc0 inclusive
// range: 0x53abd0-0x53ac82 inclusive
// range: 0x53ac90-0x53b2f9 inclusive
// non_contiguous: true
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint * __thiscall
FUN_0053a780(void *this,int param_1,uint *param_2,int param_3,uint *param_4,int param_5,
            byte *param_6,int param_7)

{
  ulonglong uVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  bool bVar8;
  uint *puVar9;
  int iVar10;
  uint *puVar11;
  int iVar12;
  uint *puVar13;
  uint *puVar14;
  uint *puVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  ulonglong *puVar20;
  int *piVar21;
  int *piVar22;
  uint *puVar23;
  ulonglong *puVar24;
  ulonglong *puVar25;
  ulonglong *puVar26;
  ulonglong *puVar27;
  ulonglong uVar28;
  longlong lVar29;
  int local_18;
  int local_c;
  uint *local_8;
  
  puVar13 = param_2;
  if ((param_2 != (uint *)0x0) && (*(int *)(param_1 + 0x28) != 0)) {
    if (param_6 == (byte *)0xffffffff) {
      param_6 = (byte *)(int)*(short *)((int)this + 6);
    }
    if (param_7 == -1) {
      param_7 = (int)*(short *)((int)this + 8);
    }
    bVar2 = *(byte *)((int)this + 5);
    puVar14 = (uint *)((int)param_6 >> 1);
    local_8 = (uint *)param_6;
    if (8 < bVar2) {
      local_8 = puVar14;
    }
    bVar3 = *(byte *)((int)this + 4);
    if ((bVar3 & 4) == 0) {
      puVar13 = param_4;
    }
    else {
      param_5 = param_5 + *(short *)((int)this + 0xc);
      puVar13 = (uint *)((int)param_4 + (int)*(short *)((int)this + 10));
    }
    local_18 = 0;
    param_4 = (uint *)0x0;
    puVar15 = *(uint **)(param_1 + 4);
    if ((int)puVar13 < (int)puVar15) {
      local_8 = (uint *)((int)local_8 + ((int)puVar13 - (int)puVar15));
      param_4 = (uint *)((int)puVar15 - (int)puVar13);
      puVar13 = puVar15;
    }
    if (*(int *)(param_1 + 8) < (int)local_8 + (int)puVar13) {
      local_8 = (uint *)(*(int *)(param_1 + 8) - (int)puVar13);
    }
    iVar12 = param_5;
    local_c = param_7;
    if (param_5 < *(int *)(param_1 + 0xc)) {
      local_c = param_7 + (param_5 - *(int *)(param_1 + 0xc));
      iVar12 = *(int *)(param_1 + 0xc);
      local_18 = iVar12 - param_5;
    }
    if (*(int *)(param_1 + 0x10) < local_c + iVar12) {
      local_c = *(int *)(param_1 + 0x10) - iVar12;
    }
    if ((0 < (int)local_8) && (0 < local_c)) {
      iVar10 = *(int *)(param_1 + 0x20) * 2;
      puVar25 = (ulonglong *)
                (*(int *)(param_1 + 0x28) +
                (int)(*(int *)(param_1 + 0x20) * iVar12 + (int)puVar13) * 2);
      puVar15 = *(uint **)((int)this + 0x1c);
      lVar29 = __allmul((uint)puVar15,(int)puVar15 >> 0x1f,0x10001,0x10001);
      if ((bVar3 & 0x10) != 0) {
        if (bVar2 != 8) {
          cVar4 = *(char *)(param_1 + 0x18);
          for (; puVar13 = param_4, local_18 != 0; local_18 = local_18 + -1) {
            puVar13 = puVar14;
            do {
              while( true ) {
                uVar16 = *param_2;
                param_2 = param_2 + 1;
                if ((uVar16 & 0xffff) == 0) break;
                puVar13 = (uint *)((int)puVar13 + -1);
                if (puVar13 == (uint *)0x0) goto LAB_0053ab79;
              }
              puVar13 = (uint *)((int)puVar13 - (uVar16 >> 0x10));
            } while (puVar13 != (uint *)0x0);
LAB_0053ab79:
          }
joined_r0x0053ab89:
          do {
            puVar15 = local_8;
            puVar24 = puVar25;
            if (puVar13 == (uint *)0x0) {
LAB_0053abb2:
              puVar13 = puVar15;
              if (cVar4 == '\0') {
                do {
                  while( true ) {
                    uVar16 = *param_2;
                    param_2 = param_2 + 1;
                    if ((uVar16 & 0xffff) == 0) break;
                    if ((char)(uVar16 >> 8) == '<') {
                      puVar9 = (uint *)(uVar16 >> 0x10 & 0x7fff);
                      *(short *)puVar24 = (short)puVar9;
                      puVar13 = (uint *)((int)puVar13 + -1);
                      puVar24 = (ulonglong *)((int)puVar24 + 2);
                      if (puVar13 == (uint *)0x0) {
                        puVar15 = (uint *)0x0;
                        goto LAB_0053ad3a;
                      }
                    }
                    else {
                      uVar17 = (uint)*puVar24;
                      puVar9 = (uint *)((uVar16 & 0xffff) >> 2);
                      uVar18 = (uVar17 & 0x7c00) >> 10;
                      uVar19 = uVar17 >> 5 & 0x1f;
                      *(short *)puVar24 =
                           (((short)uVar18 +
                            (short)puVar9[((uVar16 >> 0x1a & 0x1f) - uVar18) + 0x161165]) * 0x20 +
                            (short)uVar19 +
                           (short)puVar9[(((uVar16 >> 0x10 & 0x3e0) >> 5) - uVar19) + 0x161165]) *
                           0x20 + (short)(uVar17 & 0x1f) +
                           (short)puVar9[((uVar16 >> 0x10 & 0x1f) - (uVar17 & 0x1f)) + 0x161165];
                      puVar24 = (ulonglong *)((int)puVar24 + 2);
                      puVar13 = (uint *)((int)puVar13 + -1);
                      puVar15 = (uint *)0x0;
                      if (puVar13 == (uint *)0x0) goto LAB_0053ad3a;
                    }
                  }
                  puVar9 = (uint *)(uVar16 >> 0x10);
                  puVar24 = (ulonglong *)((int)puVar24 + (int)puVar9 * 2);
                  puVar15 = (uint *)((int)puVar13 - (int)puVar9);
                  puVar13 = puVar15;
                } while (0 < (int)puVar15);
              }
              else {
                do {
                  while( true ) {
                    uVar16 = *param_2;
                    param_2 = param_2 + 1;
                    if ((uVar16 & 0xffff) == 0) break;
                    if ((char)(uVar16 >> 8) == '<') {
                      puVar9 = (uint *)((uVar16 >> 0x10 & 0xffe0) + (uVar16 >> 0x10));
                      *(short *)puVar24 = (short)puVar9;
                      puVar15 = (uint *)((int)puVar15 + -1);
                      puVar24 = (ulonglong *)((int)puVar24 + 2);
                      if (puVar15 == (uint *)0x0) {
                        puVar15 = (uint *)0x0;
                        goto LAB_0053ad3a;
                      }
                    }
                    else {
                      uVar17 = (uint)*puVar24;
                      puVar9 = (uint *)((uVar16 & 0xffff) >> 2);
                      uVar18 = (uVar17 & 0xf800) >> 0xb;
                      uVar19 = uVar17 >> 6 & 0x1f;
                      *(short *)puVar24 =
                           (((short)uVar18 +
                            (short)puVar9[((uVar16 >> 0x1a & 0x1f) - uVar18) + 0x161165]) * 0x20 +
                            (short)uVar19 +
                           (short)puVar9[(((uVar16 >> 0x10 & 0x3e0) >> 5) - uVar19) + 0x161165]) *
                           0x40 + (short)(uVar17 & 0x1f) +
                           (short)puVar9[((uVar16 >> 0x10 & 0x1f) - (uVar17 & 0x1f)) + 0x161165];
                      puVar24 = (ulonglong *)((int)puVar24 + 2);
                      puVar15 = (uint *)((int)puVar15 + -1);
                      if (puVar15 == (uint *)0x0) {
                        puVar15 = (uint *)0x0;
                        goto LAB_0053ad3a;
                      }
                    }
                  }
                  puVar9 = (uint *)(uVar16 >> 0x10);
                  puVar24 = (ulonglong *)((int)puVar24 + (int)puVar9 * 2);
                  puVar15 = (uint *)((int)puVar15 - (int)puVar9);
                } while (0 < (int)puVar15);
              }
            }
            else {
              do {
                uVar16 = *param_2;
                param_2 = param_2 + 1;
                if ((uVar16 & 0xffff) != 0) {
                  puVar13 = (uint *)((int)puVar13 + -1);
                  goto joined_r0x0053ab89;
                }
                puVar9 = (uint *)(uVar16 >> 0x10);
                puVar11 = (uint *)((int)puVar13 - (int)puVar9);
                bVar8 = (int)puVar9 <= (int)puVar13;
                puVar13 = puVar11;
              } while (puVar11 != (uint *)0x0 && bVar8);
              puVar15 = (uint *)((int)local_8 + (int)puVar11);
              puVar24 = (ulonglong *)((int)puVar25 + (int)puVar11 * -2);
              if (0 < (int)puVar15) goto LAB_0053abb2;
            }
LAB_0053ad3a:
            for (iVar12 = (int)puVar14 + (-(int)local_8 - (int)param_4) + (int)puVar15; iVar12 != 0;
                iVar12 = iVar12 - (int)puVar9) {
              while( true ) {
                puVar9 = (uint *)*param_2;
                param_2 = param_2 + 1;
                if (((uint)puVar9 & 0xffff) == 0) break;
                iVar12 = iVar12 + -1;
                if (iVar12 == 0) goto LAB_0053ad5b;
              }
              puVar9 = (uint *)((uint)puVar9 >> 0x10);
            }
LAB_0053ad5b:
            puVar25 = (ulonglong *)((int)puVar25 + iVar10);
            local_c = local_c + -1;
            puVar13 = param_4;
            if (local_c == 0) {
              return puVar9;
            }
          } while( true );
        }
        cVar4 = *(char *)(param_1 + 0x18);
        for (; puVar13 = param_4, local_18 != 0; local_18 = local_18 + -1) {
          puVar13 = (uint *)param_6;
          puVar14 = param_2;
          do {
            while( true ) {
              param_2 = (uint *)((int)puVar14 + 2);
              if (((ushort)*puVar14 & 0xff) == 0) break;
              puVar13 = (uint *)((int)puVar13 + -1);
              puVar14 = param_2;
              if (puVar13 == (uint *)0x0) goto LAB_0053a91a;
            }
            puVar13 = (uint *)((int)puVar13 - (uint)(ushort)((ushort)*puVar14 >> 8));
            puVar14 = param_2;
          } while (puVar13 != (uint *)0x0);
LAB_0053a91a:
        }
joined_r0x0053a92a:
        do {
          puVar14 = local_8;
          puVar15 = param_2;
          puVar24 = puVar25;
          if (puVar13 == (uint *)0x0) {
LAB_0053a957:
            puVar13 = puVar14;
            if (cVar4 == '\0') {
              do {
                while( true ) {
                  param_2 = (uint *)((int)puVar15 + 2);
                  uVar16 = *puVar15;
                  uVar7 = (ushort)uVar16;
                  puVar15 = param_2;
                  if ((uVar7 & 0xff) == 0) break;
                  if ((char)uVar16 == '<') {
                    puVar9 = *(uint **)(param_3 + (uint)(uVar7 >> 8) * 2);
                    *(short *)puVar24 = (short)puVar9;
                    puVar24 = (ulonglong *)((int)puVar24 + 2);
                    puVar13 = (uint *)((int)puVar13 + -1);
                    if (puVar13 == (uint *)0x0) {
                      puVar14 = (uint *)0x0;
                      goto LAB_0053aaf6;
                    }
                  }
                  else {
                    uVar5 = (ushort)*puVar24;
                    uVar6 = *(ushort *)(param_3 + (uint)(byte)(uVar16 >> 8) * 2);
                    puVar9 = (uint *)((uVar7 & 0xff) * 0x40);
                    uVar16 = (uVar5 & 0xf800) >> 10;
                    uVar17 = uVar5 >> 5 & 0x1f;
                    uVar18 = uVar5 & 0x1f;
                    *(short *)puVar24 =
                         (((short)uVar16 + (short)puVar9[((uVar6 >> 10 & 0x1f) - uVar16) + 0x161165]
                          ) * 0x20 + (short)uVar17 +
                         (short)puVar9[(((uVar6 & 0x3e0) >> 5) - uVar17) + 0x161165]) * 0x20 +
                         (short)uVar18 + (short)puVar9[((uVar6 & 0x1f) - uVar18) + 0x161165];
                    puVar24 = (ulonglong *)((int)puVar24 + 2);
                    puVar13 = (uint *)((int)puVar13 + -1);
                    puVar14 = (uint *)0x0;
                    if (puVar13 == (uint *)0x0) goto LAB_0053aaf6;
                  }
                }
                puVar9 = (uint *)(uint)(uVar7 >> 8);
                puVar24 = (ulonglong *)((int)puVar24 + (int)puVar9 * 2);
                puVar14 = (uint *)((int)puVar13 - (int)puVar9);
                puVar13 = puVar14;
              } while (0 < (int)puVar14);
            }
            else {
              do {
                while( true ) {
                  param_2 = (uint *)((int)puVar15 + 2);
                  uVar16 = *puVar15;
                  uVar7 = (ushort)uVar16;
                  puVar15 = param_2;
                  if ((uVar7 & 0xff) == 0) break;
                  if ((char)uVar16 == '<') {
                    uVar16 = *(uint *)(param_3 + (uint)(uVar7 >> 8) * 2);
                    puVar9 = (uint *)(uVar16 + (uVar16 & 0x7fe0));
                    *(short *)puVar24 = (short)puVar9;
                    puVar24 = (ulonglong *)((int)puVar24 + 2);
                    puVar14 = (uint *)((int)puVar14 + -1);
                    if (puVar14 == (uint *)0x0) {
                      puVar14 = (uint *)0x0;
                      goto LAB_0053aaf6;
                    }
                  }
                  else {
                    uVar5 = (ushort)*puVar24;
                    uVar6 = *(ushort *)(param_3 + (uint)(byte)(uVar16 >> 8) * 2);
                    puVar9 = (uint *)((uVar7 & 0xff) * 0x40);
                    uVar16 = uVar5 >> 6 & 0x1f;
                    *(ushort *)puVar24 =
                         (((uVar5 >> 0xb) +
                          (short)puVar9[((uVar6 >> 10 & 0x1f) - (uint)(uVar5 >> 0xb)) + 0x161165]) *
                          0x20 + (short)uVar16 +
                         (short)puVar9[(((uVar6 & 0x3e0) >> 5) - uVar16) + 0x161165]) * 0x40 +
                         (short)(uVar5 & 0x1f) +
                         (short)puVar9[((uVar6 & 0x1f) - (uVar5 & 0x1f)) + 0x161165];
                    puVar24 = (ulonglong *)((int)puVar24 + 2);
                    puVar14 = (uint *)((int)puVar14 + -1);
                    if (puVar14 == (uint *)0x0) {
                      puVar14 = (uint *)0x0;
                      goto LAB_0053aaf6;
                    }
                  }
                }
                puVar9 = (uint *)(uint)(uVar7 >> 8);
                puVar24 = (ulonglong *)((int)puVar24 + (int)puVar9 * 2);
                puVar14 = (uint *)((int)puVar14 - (int)puVar9);
              } while (0 < (int)puVar14);
            }
          }
          else {
            do {
              param_2 = (uint *)((int)puVar15 + 2);
              if (((ushort)*puVar15 & 0xff) != 0) {
                puVar13 = (uint *)((int)puVar13 + -1);
                goto joined_r0x0053a92a;
              }
              puVar9 = (uint *)(uint)(ushort)((ushort)*puVar15 >> 8);
              puVar11 = (uint *)((int)puVar13 - (int)puVar9);
              bVar8 = (int)puVar9 <= (int)puVar13;
              puVar13 = puVar11;
              puVar15 = param_2;
            } while (puVar11 != (uint *)0x0 && bVar8);
            puVar14 = (uint *)((int)local_8 + (int)puVar11);
            puVar24 = (ulonglong *)((int)puVar25 + (int)puVar11 * -2);
            if (0 < (int)puVar14) goto LAB_0053a957;
          }
LAB_0053aaf6:
          for (iVar12 = (int)param_6 + (-(int)local_8 - (int)param_4) + (int)puVar14;
              puVar13 = param_2, iVar12 != 0; iVar12 = iVar12 - (int)puVar9) {
            while( true ) {
              param_2 = (uint *)((int)puVar13 + 2);
              uVar7 = (ushort)*puVar13;
              puVar9 = (uint *)(uint)uVar7;
              if ((uVar7 & 0xff) == 0) break;
              iVar12 = iVar12 + -1;
              puVar13 = param_2;
              if (iVar12 == 0) goto LAB_0053ab1b;
            }
            puVar9 = (uint *)(uint)(uVar7 >> 8);
          }
LAB_0053ab1b:
          puVar25 = (ulonglong *)((int)puVar25 + iVar10);
          local_c = local_c + -1;
          puVar13 = param_4;
          if (local_c == 0) {
            return puVar9;
          }
        } while( true );
      }
      if ((bVar3 & 1) == 0) {
        if ((bVar3 & 2) != 0) {
          if (bVar2 < 9) {
            puVar13 = (uint *)((int)param_2 + (int)(local_18 * (int)param_6 + (int)param_4));
            do {
              puVar9 = (uint *)((uint)puVar13 & 3);
              puVar14 = local_8;
              puVar11 = puVar13;
              puVar24 = puVar25;
              for (uVar16 = 4U - (int)puVar9 & 3; puVar23 = puVar11, uVar16 != 0;
                  uVar16 = uVar16 - 1) {
                puVar23 = (uint *)((int)puVar11 + 1);
                puVar9 = (uint *)(uint)(byte)*puVar11;
                if (puVar9 != puVar15) {
                  uVar7 = *(ushort *)(param_3 + (int)puVar9 * 2);
                  puVar9 = (uint *)(uint)uVar7;
                  *(ushort *)puVar24 = uVar7;
                }
                puVar24 = (ulonglong *)((int)puVar24 + 2);
                puVar14 = (uint *)((int)puVar14 + -1);
                if (puVar14 == (uint *)0x0) break;
                puVar11 = puVar23;
              }
              uVar16 = (uint)puVar14 >> 2;
              puVar11 = (uint *)0x0;
              if (uVar16 != 0) {
                do {
                  uVar17 = *puVar23;
                  puVar23 = puVar23 + 1;
                  if ((uint *)(uVar17 & 0xff) != puVar15) {
                    *(undefined2 *)puVar24 = *(undefined2 *)(param_3 + (int)(uVar17 & 0xff) * 2);
                  }
                  puVar9 = (uint *)(uVar17 >> 8 & 0xff);
                  if (puVar9 != puVar15) {
                    *(undefined2 *)((int)puVar24 + 2) = *(undefined2 *)(param_3 + (int)puVar9 * 2);
                  }
                  puVar9 = (uint *)(uVar17 >> 0x10 & 0xff);
                  if (puVar9 != puVar15) {
                    uVar7 = *(ushort *)(param_3 + (int)puVar9 * 2);
                    puVar9 = (uint *)(uint)uVar7;
                    *(ushort *)((int)puVar24 + 4) = uVar7;
                  }
                  if ((uint *)(uVar17 >> 0x18) != puVar15) {
                    uVar7 = *(ushort *)(param_3 + (int)(uVar17 >> 0x18) * 2);
                    puVar9 = (uint *)(uint)uVar7;
                    *(ushort *)((int)puVar24 + 6) = uVar7;
                  }
                  puVar24 = puVar24 + 1;
                  uVar16 = uVar16 - 1;
                } while (uVar16 != 0);
                puVar11 = puVar14;
              }
              for (uVar16 = (uint)puVar11 & 3; uVar16 != 0; uVar16 = uVar16 - 1) {
                puVar9 = (uint *)(uint)(byte)*puVar23;
                puVar23 = (uint *)((int)puVar23 + 1);
                if (puVar9 != puVar15) {
                  uVar7 = *(ushort *)(param_3 + (int)puVar9 * 2);
                  puVar9 = (uint *)(uint)uVar7;
                  *(ushort *)puVar24 = uVar7;
                }
                puVar24 = (ulonglong *)((int)puVar24 + 2);
              }
              puVar13 = (uint *)((int)puVar13 + (int)param_6);
              puVar25 = (ulonglong *)((int)puVar25 + iVar10);
              local_c = local_c + -1;
              if (local_c == 0) {
                return puVar9;
              }
            } while( true );
          }
          if ((*(int *)(param_1 + 0x14) != 0) || (*(int *)(param_1 + 0x74) == 0)) {
            puVar13 = (uint *)(local_18 * (int)param_6 + (int)param_4 * 2);
            puVar14 = (uint *)((int)param_2 + (int)puVar13);
            do {
              puVar11 = local_8;
              puVar9 = puVar14;
              puVar24 = puVar25;
              do {
                puVar20 = puVar24;
                if (((uint)puVar11 & 1) == 0) break;
                uVar7 = (ushort)*puVar9;
                puVar13 = (uint *)CONCAT22((short)((uint)puVar13 >> 0x10),uVar7);
                puVar20 = (ulonglong *)((int)puVar24 + 2);
                if (uVar7 != (ushort)puVar15) {
                  *(ushort *)puVar24 = uVar7;
                }
                puVar9 = (uint *)((int)puVar9 + 2);
                puVar11 = (uint *)(((uint)puVar11 & 1) - 1);
                puVar24 = puVar20;
              } while (puVar11 != (uint *)0x0);
              for (uVar16 = (uint)local_8 >> 1; uVar16 != 0; uVar16 = uVar16 - 1) {
                uVar17 = *puVar9;
                puVar9 = puVar9 + 1;
                puVar13 = (uint *)(uVar17 >> 0x10);
                if ((uint *)(uVar17 & 0xffff) != puVar15) {
                  *(short *)puVar20 = (short)uVar17;
                }
                if (puVar13 != puVar15) {
                  *(short *)((int)puVar20 + 2) = (short)(uVar17 >> 0x10);
                }
                puVar20 = (ulonglong *)((int)puVar20 + 4);
              }
              puVar14 = (uint *)((int)puVar14 + (int)param_6);
              puVar25 = (ulonglong *)((int)puVar25 + iVar10);
              local_c = local_c + -1;
              if (local_c == 0) {
                return puVar13;
              }
            } while( true );
          }
          puVar24 = (ulonglong *)((int)param_2 + local_18 * (int)param_6 + (int)param_4 * 2);
          do {
            puVar14 = (uint *)0x0;
            puVar13 = local_8;
            puVar20 = puVar24;
            puVar27 = puVar25;
            do {
              puVar26 = puVar27;
              if (((uint)puVar13 & 3) == 0) break;
              puVar14 = (uint *)(uint)(ushort)*puVar20;
              puVar26 = (ulonglong *)((int)puVar27 + 2);
              if (puVar14 != puVar15) {
                *(ushort *)puVar27 = (ushort)*puVar20;
              }
              puVar20 = (ulonglong *)((int)puVar20 + 2);
              puVar13 = (uint *)(((uint)puVar13 & 3) - 1);
              puVar27 = puVar26;
            } while (puVar13 != (uint *)0x0);
            for (uVar16 = (uint)local_8 >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {
              uVar1 = *puVar20;
              puVar20 = puVar20 + 1;
              uVar28 = CONCAT26(-(ushort)((short)(uVar1 >> 0x30) ==
                                         (short)((ulonglong)lVar29 >> 0x30)),
                                CONCAT24(-(ushort)((short)(uVar1 >> 0x20) ==
                                                  (short)((ulonglong)lVar29 >> 0x20)),
                                         CONCAT22(-(ushort)((short)(uVar1 >> 0x10) ==
                                                           (short)((ulonglong)lVar29 >> 0x10)),
                                                  -(ushort)((short)uVar1 == (short)lVar29))));
              *puVar26 = uVar1 & (uVar28 ^ 0xffffffffffffffff) | *puVar26 & uVar28;
              puVar26 = puVar26 + 1;
            }
            puVar24 = (ulonglong *)((int)puVar24 + (int)param_6);
            puVar25 = (ulonglong *)((int)puVar25 + iVar10);
            local_c = local_c + -1;
            if (local_c == 0) {
              return puVar14;
            }
          } while( true );
        }
        if (bVar2 < 9) {
          puVar13 = (uint *)((int)param_2 + (int)(local_18 * (int)param_6 + (int)param_4));
          do {
            puVar15 = (uint *)((uint)puVar13 & 3);
            puVar14 = local_8;
            puVar9 = puVar13;
            puVar24 = puVar25;
            for (uVar16 = 4U - (int)puVar15 & 3; uVar16 != 0; uVar16 = uVar16 - 1) {
              uVar17 = *puVar9;
              puVar9 = (uint *)((int)puVar9 + 1);
              uVar7 = *(ushort *)(param_3 + (uint)(byte)uVar17 * 2);
              puVar15 = (uint *)(uint)uVar7;
              *(ushort *)puVar24 = uVar7;
              puVar24 = (ulonglong *)((int)puVar24 + 2);
              puVar14 = (uint *)((int)puVar14 + -1);
              if (puVar14 == (uint *)0x0) break;
            }
            uVar16 = (uint)puVar14 >> 2;
            puVar11 = (uint *)0x0;
            if (uVar16 != 0) {
              do {
                uVar17 = *puVar9;
                puVar9 = puVar9 + 1;
                *(uint *)puVar24 =
                     *(uint *)(param_3 + (uVar17 & 0xff) * 2) & 0xffff |
                     *(int *)(param_3 + (uVar17 >> 8 & 0xff) * 2) << 0x10;
                puVar15 = (uint *)(*(int *)(param_3 + (uVar17 >> 0x18) * 2) << 0x10 |
                                  *(uint *)(param_3 + (uVar17 >> 0x10 & 0xff) * 2) & 0xffff);
                *(uint **)((int)puVar24 + 4) = puVar15;
                puVar24 = puVar24 + 1;
                uVar16 = uVar16 - 1;
              } while (uVar16 != 0);
              puVar11 = puVar14;
            }
            for (uVar16 = (uint)puVar11 & 3; uVar16 != 0; uVar16 = uVar16 - 1) {
              uVar17 = *puVar9;
              puVar9 = (uint *)((int)puVar9 + 1);
              uVar7 = *(ushort *)(param_3 + (uint)(byte)uVar17 * 2);
              puVar15 = (uint *)(uint)uVar7;
              *(ushort *)puVar24 = uVar7;
              puVar24 = (ulonglong *)((int)puVar24 + 2);
            }
            puVar13 = (uint *)((int)puVar13 + (int)param_6);
            puVar25 = (ulonglong *)((int)puVar25 + iVar10);
            local_c = local_c + -1;
            if (local_c == 0) {
              return puVar15;
            }
          } while( true );
        }
        if (*(int *)(param_1 + 0x74) == 0) {
          puVar13 = (uint *)(local_18 * (int)param_6 + (int)param_4 * 2);
          piVar21 = (int *)((int)param_2 + (int)puVar13);
          do {
            piVar22 = piVar21;
            puVar24 = puVar25;
            if (((uint)local_8 & 1) != 0) {
              puVar13 = (uint *)CONCAT22((short)((uint)puVar13 >> 0x10),(short)*piVar21);
              puVar24 = (ulonglong *)((int)puVar25 + 2);
              *(short *)puVar25 = (short)*piVar21;
              piVar22 = (int *)((int)piVar21 + 2);
            }
            for (uVar16 = (uint)local_8 >> 1; uVar16 != 0; uVar16 = uVar16 - 1) {
              puVar13 = (uint *)*piVar22;
              *(uint **)puVar24 = puVar13;
              piVar22 = piVar22 + 1;
              puVar24 = (ulonglong *)((int)puVar24 + 4);
            }
            piVar21 = (int *)((int)piVar21 + (int)param_6);
            puVar25 = (ulonglong *)((int)puVar25 + iVar10);
            local_c = local_c + -1;
          } while (local_c != 0);
          return puVar13;
        }
        puVar13 = (uint *)(local_18 * (int)param_6 + (int)param_4 * 2);
        puVar24 = (ulonglong *)((int)param_2 + (int)puVar13);
        do {
          puVar14 = local_8;
          puVar20 = puVar24;
          puVar27 = puVar25;
          do {
            puVar26 = puVar27;
            if (((uint)puVar14 & 3) == 0) break;
            puVar13 = (uint *)CONCAT22((short)((uint)puVar13 >> 0x10),(short)*puVar20);
            puVar26 = (ulonglong *)((int)puVar27 + 2);
            *(short *)puVar27 = (short)*puVar20;
            puVar20 = (ulonglong *)((int)puVar20 + 2);
            puVar14 = (uint *)(((uint)puVar14 & 3) - 1);
            puVar27 = puVar26;
          } while (puVar14 != (uint *)0x0);
          for (uVar16 = (uint)local_8 >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {
            *puVar26 = *puVar20;
            puVar20 = puVar20 + 1;
            puVar26 = puVar26 + 1;
          }
          puVar24 = (ulonglong *)((int)puVar24 + (int)param_6);
          puVar25 = (ulonglong *)((int)puVar25 + iVar10);
          local_c = local_c + -1;
          if (local_c == 0) {
            return puVar13;
          }
        } while( true );
      }
      if (8 < bVar2) {
        puVar13 = local_8;
        for (; puVar9 = param_4, local_18 != 0; local_18 = local_18 + -1) {
          puVar13 = puVar14;
          puVar9 = param_2;
          do {
            while (param_2 = (uint *)((int)puVar9 + 2), (uint *)(uint)(ushort)*puVar9 != puVar15) {
              puVar13 = (uint *)((int)puVar13 + -1);
              puVar9 = param_2;
              if (puVar13 == (uint *)0x0) goto LAB_0053b175;
            }
            puVar9 = puVar9 + 1;
            puVar13 = (uint *)((int)puVar13 - (uint)*(ushort *)param_2);
            param_2 = puVar9;
          } while (puVar13 != (uint *)0x0);
LAB_0053b175:
          puVar13 = (uint *)0x0;
        }
joined_r0x0053b188:
        do {
          puVar11 = local_8;
          puVar24 = puVar25;
          if (puVar9 == (uint *)0x0) goto LAB_0053b1b8;
          do {
            puVar13 = (uint *)(uint)(ushort)*param_2;
            if (puVar13 != puVar15) {
              param_2 = (uint *)((int)param_2 + 2);
              puVar9 = (uint *)((int)puVar9 + -1);
              goto joined_r0x0053b188;
            }
            puVar23 = param_2 + 1;
            puVar13 = (uint *)(uint)*(ushort *)((int)param_2 + 2);
            puVar11 = (uint *)((int)puVar9 - (int)puVar13);
            bVar8 = (int)puVar13 <= (int)puVar9;
            puVar9 = puVar11;
            param_2 = puVar23;
          } while (puVar11 != (uint *)0x0 && bVar8);
          puVar24 = (ulonglong *)((int)puVar25 + (int)puVar11 * -2);
          for (puVar11 = (uint *)((int)local_8 + (int)puVar11); param_2 = puVar23, 0 < (int)puVar11;
              puVar11 = (uint *)((int)puVar11 - (int)puVar13)) {
LAB_0053b1b8:
            while( true ) {
              uVar7 = (ushort)*param_2;
              puVar13 = (uint *)CONCAT22((short)((uint)puVar13 >> 0x10),uVar7);
              puVar23 = (uint *)((int)param_2 + 2);
              if (uVar7 == (ushort)puVar15) break;
              *(ushort *)puVar24 = uVar7;
              puVar11 = (uint *)((int)puVar11 + -1);
              param_2 = puVar23;
              puVar24 = (ulonglong *)((int)puVar24 + 2);
              if (puVar11 == (uint *)0x0) {
                puVar11 = (uint *)0x0;
                goto LAB_0053b1e2;
              }
            }
            puVar23 = param_2 + 1;
            puVar13 = (uint *)(uint)*(ushort *)((int)param_2 + 2);
            puVar24 = (ulonglong *)((int)puVar24 + (int)puVar13 * 2);
          }
LAB_0053b1e2:
          iVar12 = (int)puVar14 + (-(int)local_8 - (int)param_4) + (int)puVar11;
          puVar9 = puVar23;
          if (0 < iVar12) {
            do {
              while( true ) {
                puVar23 = (uint *)((int)puVar9 + 2);
                puVar13 = (uint *)(uint)(ushort)*puVar9;
                if (puVar13 == puVar15) break;
                iVar12 = iVar12 + -1;
                puVar9 = puVar23;
                if (iVar12 == 0) goto LAB_0053b20e;
              }
              puVar23 = puVar9 + 1;
              puVar13 = (uint *)(uint)*(ushort *)((int)puVar9 + 2);
              iVar12 = iVar12 - (int)puVar13;
              puVar9 = puVar23;
            } while (iVar12 != 0);
          }
LAB_0053b20e:
          puVar25 = (ulonglong *)((int)puVar25 + iVar10);
          local_c = local_c + -1;
          param_2 = puVar23;
          puVar9 = param_4;
          if (local_c == 0) {
            return puVar13;
          }
        } while( true );
      }
      for (; puVar14 = param_4, local_18 != 0; local_18 = local_18 + -1) {
        puVar13 = (uint *)param_6;
        puVar14 = param_2;
        do {
          while (param_2 = (uint *)((int)puVar14 + 1), (uint *)(uint)(byte)*puVar14 == puVar15) {
            puVar14 = (uint *)((int)puVar14 + 2);
            puVar13 = (uint *)((int)puVar13 - (uint)*(byte *)param_2);
            param_2 = puVar14;
            if (puVar13 == (uint *)0x0) goto LAB_0053b257;
          }
          puVar13 = (uint *)((int)puVar13 + -1);
          puVar14 = param_2;
        } while (puVar13 != (uint *)0x0);
LAB_0053b257:
      }
      do {
        for (; puVar9 = local_8, puVar24 = puVar25, puVar14 != (uint *)0x0;
            puVar14 = (uint *)((int)puVar14 + -1)) {
          while ((byte)*param_2 == (byte)lVar29) {
            puVar11 = (uint *)((int)param_2 + 2);
            puVar13 = (uint *)(uint)*(byte *)((int)param_2 + 1);
            puVar9 = (uint *)((int)puVar14 - (int)puVar13);
            bVar8 = (int)puVar14 < (int)puVar13;
            puVar14 = puVar9;
            param_2 = puVar11;
            if (puVar9 == (uint *)0x0 || bVar8) {
              puVar24 = (ulonglong *)((int)puVar25 + (int)puVar9 * -2);
              puVar9 = (uint *)((int)local_8 + (int)puVar9);
              goto joined_r0x0053b292;
            }
          }
          param_2 = (uint *)((int)param_2 + 1);
        }
        do {
          while( true ) {
            puVar11 = (uint *)((int)param_2 + 1);
            if ((uint *)(uint)(byte)*param_2 == puVar15) break;
            uVar7 = *(ushort *)(param_3 + (int)(uint)(byte)*param_2 * 2);
            puVar13 = (uint *)(uint)uVar7;
            *(ushort *)puVar24 = uVar7;
            puVar9 = (uint *)((int)puVar9 + -1);
            param_2 = puVar11;
            puVar24 = (ulonglong *)((int)puVar24 + 2);
            if (puVar9 == (uint *)0x0) {
              puVar9 = (uint *)0x0;
              goto LAB_0053b2c2;
            }
          }
          puVar11 = (uint *)((int)param_2 + 2);
          puVar13 = (uint *)(uint)*(byte *)((int)param_2 + 1);
          puVar24 = (ulonglong *)((int)puVar24 + (int)puVar13 * 2);
          puVar9 = (uint *)((int)puVar9 - (int)puVar13);
joined_r0x0053b292:
          param_2 = puVar11;
        } while (0 < (int)puVar9);
LAB_0053b2c2:
        for (iVar12 = (int)param_6 + (-(int)local_8 - (int)param_4) + (int)puVar9; puVar14 = puVar11
            , iVar12 != 0; iVar12 = iVar12 - (int)puVar13) {
          while( true ) {
            puVar11 = (uint *)((int)puVar14 + 1);
            puVar13 = (uint *)(uint)(byte)*puVar14;
            if ((byte)*puVar14 == (byte)lVar29) break;
            iVar12 = iVar12 + -1;
            puVar14 = puVar11;
            if (iVar12 == 0) goto LAB_0053b2e5;
          }
          puVar11 = (uint *)((int)puVar14 + 2);
          puVar13 = (uint *)(uint)*(byte *)((int)puVar14 + 1);
        }
LAB_0053b2e5:
        puVar25 = (ulonglong *)((int)puVar25 + iVar10);
        local_c = local_c + -1;
        param_2 = puVar11;
        puVar14 = param_4;
      } while (local_c != 0);
    }
  }
  return puVar13;
}

