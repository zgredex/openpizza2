// rea decompile_all
// name: Sprite_BlitAlphaRLE
// address: 0x53b300
// body: available
// range: 0x53b300-0x53b5f8 inclusive
// range: 0x53b600-0x53b6d4 inclusive
// range: 0x53b6e0-0x53b8e0 inclusive
// non_contiguous: true
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall
Sprite_BlitAlphaRLE(void *this,uint *param_1,void *param_2,ushort *param_3,int param_4,uint *param_5
                   ,int param_6,undefined1 param_7)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  uint uVar6;
  bool bVar7;
  uint uVar8;
  int iVar9;
  uint *puVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  byte *pbVar20;
  ushort *puVar21;
  ushort *puVar22;
  undefined2 *puVar23;
  ushort *puVar24;
  int local_1c;
  uint *local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
                    /* Depth-1 proposal batch 3/4. */
  FUN_00535160(param_2,&local_c,&local_10);
  if ((*(byte *)((int)this + 4) & 4) == 0) {
    local_18 = param_5;
  }
  else {
    param_6 = param_6 + *(short *)((int)this + 0xc);
    local_18 = (uint *)((int)param_5 + (int)*(short *)((int)this + 10));
  }
  iVar19 = (int)*(short *)((int)this + 6);
  iVar14 = (int)*(short *)((int)this + 8);
  local_14 = 0;
  local_1c = 0;
  param_5 = (uint *)param_6;
  if ((int)local_18 < 0) {
    iVar19 = iVar19 + (int)local_18;
    local_14 = -(int)local_18;
    if (iVar19 < 1) {
      return;
    }
    local_18 = (uint *)0x0;
  }
  if (param_6 < 0) {
    iVar14 = iVar14 + param_6;
    local_1c = -param_6;
    if (iVar14 < 1) {
      return;
    }
    param_5 = (uint *)0x0;
  }
  if ((((int)local_18 + iVar19 < local_c) || (iVar19 = local_c - (int)local_18, 0 < iVar19)) &&
     (((int)param_5 + iVar14 < local_10 || (iVar14 = local_10 - (int)param_5, 0 < iVar14)))) {
    uVar8 = (int)local_18 + iVar19;
    iVar11 = param_1[8] * (int)param_5 + param_1[10];
    iVar9 = FUN_00535150(param_2,&local_8);
    uVar6 = param_1[8];
    iVar12 = (int)*(short *)((int)this + 6);
    param_5 = (uint *)(iVar9 + local_8 * (int)param_5 * 2);
    if ((iVar19 != 0) && (iVar14 != 0)) {
      if ((*(byte *)((int)this + 4) & 1) == 0) {
        if (*(char *)((int)this + 5) == '\b') {
          bVar1 = *(byte *)((int)this + 0x1c);
          iVar19 = iVar12 * local_1c + local_14 + (int)param_3;
          do {
            param_1 = param_5;
            param_5 = (uint *)((int)param_5 + local_8 * 2);
            while( true ) {
              uVar15 = *param_1;
              param_1 = param_1 + 1;
              puVar10 = (uint *)(uVar15 & 0xffff);
              if (puVar10 == (uint *)0xffff) break;
              uVar15 = uVar15 >> 0x10;
              if ((int)local_18 < (int)uVar15) {
                if ((int)uVar8 <= (int)puVar10) break;
                if ((int)uVar8 <= (int)uVar15) {
                  uVar15 = uVar8;
                }
                if ((int)puVar10 <= (int)local_18) {
                  puVar10 = local_18;
                }
                puVar23 = (undefined2 *)(iVar11 + (int)puVar10 * 3);
                iVar9 = uVar15 - (int)puVar10;
                pbVar20 = (byte *)((int)puVar10 + (iVar19 - (int)local_18));
                do {
                  bVar2 = *pbVar20;
                  if (bVar2 != bVar1) {
                    *(undefined1 *)(puVar23 + 1) = param_7;
                    *puVar23 = *(undefined2 *)(param_4 + (uint)bVar2 * 2);
                  }
                  puVar23 = (undefined2 *)((int)puVar23 + 3);
                  iVar9 = iVar9 + -1;
                  pbVar20 = pbVar20 + 1;
                } while (iVar9 != 0);
              }
            }
            iVar11 = iVar11 + uVar6;
            iVar19 = iVar19 + iVar12;
            iVar14 = iVar14 + -1;
            if (iVar14 == 0) {
              return;
            }
          } while( true );
        }
      }
      else if (*(char *)((int)this + 5) == '\b') {
        bVar1 = *(byte *)((int)this + 0x1c);
        if ((*(byte *)((int)this + 4) & 0x10) != 0) {
          uVar15 = param_1[6];
LAB_0053b521:
          param_1 = param_5;
          param_5 = (uint *)((int)param_5 + local_8 * 2);
          for (; local_1c != 0; local_1c = local_1c + -1) {
            iVar19 = iVar12;
            puVar24 = param_3;
            do {
              while( true ) {
                param_3 = puVar24 + 1;
                uVar3 = *puVar24;
                puVar24 = param_3;
                if (((uVar3 & 0xff) == 0) || ((byte)uVar3 == bVar1)) break;
                iVar19 = iVar19 + -1;
                if (iVar19 == 0) goto LAB_0053b55b;
              }
              iVar9 = iVar19 - (uint)(uVar3 >> 8);
              bVar7 = (int)(uint)(uVar3 >> 8) <= iVar19;
              iVar19 = iVar9;
            } while (iVar9 != 0 && bVar7);
LAB_0053b55b:
          }
LAB_0053b566:
          do {
            uVar16 = *param_1;
            param_1 = param_1 + 1;
            puVar10 = (uint *)(uVar16 & 0xffff);
            if (puVar10 == (uint *)0xffff) goto LAB_0053b7ab;
            uVar16 = uVar16 >> 0x10;
            if ((int)local_18 < (int)uVar16) {
              if ((int)uVar8 <= (int)puVar10) goto LAB_0053b7ab;
              if ((int)uVar8 <= (int)uVar16) {
                uVar16 = uVar8;
              }
              if ((int)puVar10 <= (int)local_18) {
                puVar10 = local_18;
              }
              puVar24 = (ushort *)(iVar11 + (int)puVar10 * 3);
              iVar19 = uVar16 - (int)puVar10;
              iVar9 = (int)puVar10 + (local_14 - (int)local_18);
              puVar21 = param_3;
              puVar22 = param_3;
              if (iVar9 != 0) {
                do {
                  while( true ) {
                    puVar22 = puVar21 + 1;
                    if ((*puVar21 & 0xff) == 0) break;
                    iVar9 = iVar9 + -1;
                    puVar21 = puVar22;
                    if (iVar9 == 0) goto LAB_0053b5ea;
                  }
                  uVar16 = (uint)(*puVar21 >> 8);
                  iVar13 = iVar9 - uVar16;
                  bVar7 = (int)uVar16 <= iVar9;
                  iVar9 = iVar13;
                  puVar21 = puVar22;
                } while (iVar13 != 0 && bVar7);
                iVar19 = iVar19 + iVar13;
                puVar24 = (ushort *)((int)puVar24 + iVar13 * -3);
                if (iVar19 < 1) goto LAB_0053b566;
              }
LAB_0053b5ea:
              if ((char)uVar15 == '\0') {
                do {
                  while( true ) {
                    uVar3 = *puVar22;
                    if ((uVar3 & 0xff) == 0) break;
                    if ((char)uVar3 == '<') {
                      *puVar24 = (ushort)*(undefined4 *)(param_4 + (uint)(uVar3 >> 8) * 2);
                      *(undefined1 *)(puVar24 + 1) = param_7;
                    }
                    else {
                      uVar4 = *puVar24;
                      uVar5 = *(ushort *)(param_4 + (uint)(byte)(uVar3 >> 8) * 2);
                      iVar9 = (uVar3 & 0xff) * 0x40 + 0x584594;
                      uVar16 = (uVar4 & 0xf800) >> 10;
                      uVar17 = uVar4 >> 5 & 0x1f;
                      uVar18 = uVar4 & 0x1f;
                      *puVar24 = (((short)uVar16 +
                                  (short)*(undefined4 *)
                                          (iVar9 + ((uVar5 >> 10 & 0x1f) - uVar16) * 4)) * 0x20 +
                                  (short)uVar17 +
                                 (short)*(undefined4 *)
                                         (iVar9 + (((uVar5 & 0x3e0) >> 5) - uVar17) * 4)) * 0x20 +
                                 (short)uVar18 +
                                 (short)*(undefined4 *)(iVar9 + ((uVar5 & 0x1f) - uVar18) * 4);
                      *(undefined1 *)(puVar24 + 1) = param_7;
                    }
                    iVar19 = iVar19 + -1;
                    puVar24 = (ushort *)((int)puVar24 + 3);
                    puVar22 = puVar22 + 1;
                    if (iVar19 == 0) goto LAB_0053b566;
                  }
                  puVar24 = (ushort *)((int)puVar24 + (uint)(uVar3 >> 8) * 3);
                  iVar19 = iVar19 - (uint)(uVar3 >> 8);
                  puVar22 = puVar22 + 1;
                } while (0 < iVar19);
              }
              else {
                do {
                  while( true ) {
                    uVar3 = *puVar22;
                    if ((uVar3 & 0xff) == 0) break;
                    if ((char)uVar3 == '<') {
                      uVar3 = (ushort)*(undefined4 *)(param_4 + (uint)(uVar3 >> 8) * 2);
                      *puVar24 = uVar3 + (uVar3 & 0x7fe0);
                      *(undefined1 *)(puVar24 + 1) = param_7;
                    }
                    else {
                      uVar4 = *puVar24;
                      uVar5 = *(ushort *)(param_4 + (uint)(byte)(uVar3 >> 8) * 2);
                      iVar9 = (uVar3 & 0xff) * 0x40 + 0x584594;
                      uVar16 = uVar4 >> 6 & 0x1f;
                      *puVar24 = (((uVar4 >> 0xb) +
                                  (short)*(undefined4 *)
                                          (iVar9 + ((uVar5 >> 10 & 0x1f) - (uint)(uVar4 >> 0xb)) * 4
                                          )) * 0x20 + (short)uVar16 +
                                 (short)*(undefined4 *)
                                         (iVar9 + (((uVar5 & 0x3e0) >> 5) - uVar16) * 4)) * 0x40 +
                                 (short)(uVar4 & 0x1f) +
                                 (short)*(undefined4 *)
                                         (iVar9 + ((uVar5 & 0x1f) - (uVar4 & 0x1f)) * 4);
                      *(undefined1 *)(puVar24 + 1) = param_7;
                    }
                    iVar19 = iVar19 + -1;
                    puVar24 = (ushort *)((int)puVar24 + 3);
                    puVar22 = puVar22 + 1;
                    if (iVar19 == 0) goto LAB_0053b566;
                  }
                  puVar24 = (ushort *)((int)puVar24 + (uint)(uVar3 >> 8) * 3);
                  iVar19 = iVar19 - (uint)(uVar3 >> 8);
                  puVar22 = puVar22 + 1;
                } while (0 < iVar19);
              }
            }
          } while( true );
        }
        do {
          param_1 = param_5;
          param_5 = (uint *)((int)param_5 + local_8 * 2);
          for (; local_1c != 0; local_1c = local_1c + -1) {
            iVar19 = iVar12;
            do {
              while ((byte)*param_3 == bVar1) {
                pbVar20 = (byte *)((int)param_3 + 1);
                param_3 = param_3 + 1;
                iVar9 = iVar19 - (uint)*pbVar20;
                bVar7 = (int)(uint)*pbVar20 <= iVar19;
                iVar19 = iVar9;
                if (!(iVar9 != 0 && bVar7)) goto LAB_0053b804;
              }
              param_3 = (ushort *)((int)param_3 + 1);
              iVar19 = iVar19 + -1;
            } while (iVar19 != 0);
LAB_0053b804:
          }
LAB_0053b80f:
          uVar15 = *param_1;
          param_1 = param_1 + 1;
          puVar10 = (uint *)(uVar15 & 0xffff);
          if (puVar10 != (uint *)0xffff) {
            uVar15 = uVar15 >> 0x10;
            if ((int)local_18 < (int)uVar15) {
              if ((int)uVar8 <= (int)puVar10) goto LAB_0053b8c6;
              if ((int)uVar8 <= (int)uVar15) {
                uVar15 = uVar8;
              }
              if ((int)puVar10 <= (int)local_18) {
                puVar10 = local_18;
              }
              puVar23 = (undefined2 *)(iVar11 + (int)puVar10 * 3);
              iVar9 = uVar15 - (int)puVar10;
              puVar24 = param_3;
              for (iVar19 = (int)puVar10 + (local_14 - (int)local_18); iVar19 != 0;
                  iVar19 = iVar19 + -1) {
                while (puVar22 = (ushort *)((int)puVar24 + 1), (byte)*puVar24 == bVar1) {
                  puVar24 = puVar24 + 1;
                  iVar19 = iVar19 - (uint)*(byte *)puVar22;
                  if (iVar19 < 1) {
                    iVar9 = iVar9 + iVar19;
                    puVar23 = (undefined2 *)((int)puVar23 + iVar19 * -3);
                    if (0 < iVar9) goto LAB_0053b890;
                    goto LAB_0053b80f;
                  }
                }
                puVar24 = puVar22;
              }
LAB_0053b890:
              do {
                uVar3 = *puVar24;
                if ((byte)uVar3 != bVar1) {
                  *(undefined1 *)(puVar23 + 1) = param_7;
                  *puVar23 = *(undefined2 *)(param_4 + (uint)(byte)uVar3 * 2);
                  iVar9 = iVar9 + -1;
                  puVar24 = (ushort *)((int)puVar24 + 1);
                  puVar23 = (undefined2 *)((int)puVar23 + 3);
                  if (iVar9 == 0) break;
                  goto LAB_0053b890;
                }
                uVar15 = (uint)*(byte *)((int)puVar24 + 1);
                puVar24 = puVar24 + 1;
                puVar23 = (undefined2 *)((int)puVar23 + uVar15 * 3);
                iVar19 = iVar9 - uVar15;
                bVar7 = iVar9 < (int)uVar15;
                iVar9 = iVar19;
              } while (!(iVar19 == 0 || bVar7));
            }
            goto LAB_0053b80f;
          }
LAB_0053b8c6:
          iVar11 = iVar11 + uVar6;
          local_1c = 1;
          iVar14 = iVar14 + -1;
        } while (iVar14 != 0);
      }
    }
  }
  return;
LAB_0053b7ab:
  iVar11 = iVar11 + uVar6;
  local_1c = 1;
  iVar14 = iVar14 + -1;
  if (iVar14 == 0) {
    return;
  }
  goto LAB_0053b521;
}

