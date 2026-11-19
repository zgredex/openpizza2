// rea decompile_all
// name: Gfx_BlitRLEScaled
// address: 0x53c130
// body: available
// range: 0x53c130-0x53c6c2 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Restarted to delay deadcode elimination for space: stack */

void __thiscall
Gfx_BlitRLEScaled(void *this,int param_1,uint *param_2,uint *param_3,int param_4,int param_5,
                 int param_6)

{
  ushort uVar1;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  ushort *puVar10;
  uint *puVar11;
  uint *puVar12;
  short *psVar13;
  int local_1c;
  undefined4 local_10;
  uint local_c;
  int local_8;
  
                    /* Depth-1 proposal batch 1. */
  if (DAT_005747a8 != 0) {
    DAT_00584510 = operator_new(0x1000);
    local_1c = 0;
    do {
      uVar5 = 0;
      iVar9 = 0;
      do {
        *(int *)((int)DAT_00584510 + (local_1c << 5 | uVar5) * 4) =
             (int)(iVar9 + (iVar9 >> 0x1f & 0x1fU)) >> 5;
        uVar5 = uVar5 + 1;
        iVar9 = iVar9 + local_1c;
      } while ((int)uVar5 < 0x20);
      local_1c = local_1c + 1;
    } while (local_1c < 0x20);
    DAT_005747a8 = 0;
  }
  FUN_00535160(param_2,&local_10,&local_c);
  if ((int)*(short *)((int)this + 8) <= (int)local_c) {
    local_c = (int)*(short *)((int)this + 8);
  }
  iVar9 = *(int *)(param_1 + 0x28) + (*(int *)(param_1 + 0x20) * param_5 + param_4) * 2;
  param_2 = (uint *)FUN_00535150(param_2,&local_8);
  iVar8 = local_8;
  iVar7 = (int)*(short *)((int)this + 6);
  iVar6 = *(int *)(param_1 + 0x20) * 2;
  local_8 = local_8 * 2;
  if (param_6 == 0) {
    if (*(char *)(param_1 + 0x18) == '\0') {
      puVar11 = param_3;
      do {
        param_3 = param_2;
        param_2 = (uint *)((int)param_2 + local_8);
        while( true ) {
          pvVar2 = DAT_00584510;
          uVar5 = *param_3;
          param_3 = param_3 + 1;
          uVar3 = uVar5 & 0xffff;
          if (uVar3 == 0xffff) break;
          puVar10 = (ushort *)((int)puVar11 + uVar3 * 3);
          iVar8 = (uVar5 >> 0x10) - uVar3;
          uVar5 = *(uint *)(&DAT_00574798 + (local_c & 3) * 4);
          psVar13 = (short *)(iVar9 + uVar3 * 2);
          do {
            uVar1 = *puVar10;
            uVar3 = (uint)(byte)((byte)puVar10[1] + (byte)uVar5);
            if ((CARRY1((byte)puVar10[1],(byte)uVar5)) && ((uVar5 & 8) == 0)) {
              uVar3 = 0xff;
            }
            uVar5 = uVar5 << 8 | uVar5 >> 0x18;
            puVar10 = (ushort *)((int)puVar10 + 3);
            uVar3 = uVar3 & 0xf8;
            *psVar13 = ((short)*(undefined4 *)((int)pvVar2 + (uint)(uVar1 >> 10) * 4 + uVar3 * 0x10)
                        * 0x20 + (short)*(undefined4 *)
                                         ((int)pvVar2 + ((uVar1 & 0x3c0) >> 5) * 4 + uVar3 * 0x10))
                       * 0x20 + (short)*(undefined4 *)
                                        ((int)pvVar2 + (uVar1 & 0x1f) * 4 + uVar3 * 0x10);
            iVar8 = iVar8 + -1;
            psVar13 = psVar13 + 1;
          } while (iVar8 != 0);
        }
        iVar9 = iVar9 + iVar6;
        puVar11 = (uint *)((int)puVar11 + iVar7);
        local_c = local_c - 1;
      } while (local_c != 0);
      return;
    }
    puVar11 = param_3;
    do {
      param_3 = param_2;
      param_2 = (uint *)((int)param_2 + local_8);
      while( true ) {
        pvVar2 = DAT_00584510;
        uVar5 = *param_3;
        param_3 = param_3 + 1;
        uVar3 = uVar5 & 0xffff;
        if (uVar3 == 0xffff) break;
        puVar10 = (ushort *)((int)puVar11 + uVar3 * 3);
        iVar8 = (uVar5 >> 0x10) - uVar3;
        uVar5 = *(uint *)(&DAT_00574798 + (local_c & 3) * 4);
        psVar13 = (short *)(iVar9 + uVar3 * 2);
        do {
          uVar1 = *puVar10;
          uVar3 = (uint)(byte)((byte)puVar10[1] + (byte)uVar5);
          if ((CARRY1((byte)puVar10[1],(byte)uVar5)) && ((uVar5 & 8) == 0)) {
            uVar3 = 0xff;
          }
          uVar5 = uVar5 << 8 | uVar5 >> 0x18;
          puVar10 = (ushort *)((int)puVar10 + 3);
          uVar3 = uVar3 & 0xf8;
          *psVar13 = ((short)*(undefined4 *)((int)pvVar2 + (uint)(uVar1 >> 0xb) * 4 + uVar3 * 0x10)
                      * 0x20 + (short)*(undefined4 *)
                                       ((int)pvVar2 + ((uVar1 & 0x7c0) >> 6) * 4 + uVar3 * 0x10)) *
                     0x40 + (short)*(undefined4 *)((int)pvVar2 + (uVar1 & 0x1f) * 4 + uVar3 * 0x10);
          iVar8 = iVar8 + -1;
          psVar13 = psVar13 + 1;
        } while (iVar8 != 0);
      }
      iVar9 = iVar9 + iVar6;
      puVar11 = (uint *)((int)puVar11 + iVar7);
      local_c = local_c - 1;
    } while (local_c != 0);
    return;
  }
  if (param_6 != 1) {
    if (param_6 == 2) {
      local_8 = iVar8 * 8;
      if (*(char *)(param_1 + 0x18) != '\0') {
        local_c = local_c >> 2;
        puVar11 = param_3;
        do {
          param_3 = param_2;
          param_2 = param_2 + iVar8 * 2;
          while( true ) {
            pvVar2 = DAT_00584510;
            uVar5 = *param_3;
            param_3 = param_3 + 1;
            uVar3 = uVar5 & 0xffff;
            if (uVar3 == 0xffff) break;
            uVar4 = uVar3 + 3 >> 2;
            puVar12 = puVar11 + uVar4 * 3;
            uVar5 = (uVar5 >> 0x10) - uVar3 >> 2;
            if (uVar5 != 0) {
              uVar3 = *(uint *)(&DAT_00574798 + (local_c & 3) * 4);
              psVar13 = (short *)(iVar9 + uVar4 * 2);
              do {
                uVar1 = (ushort)*puVar12;
                uVar4 = (uint)(byte)(*(byte *)((int)puVar12 + 2) + (byte)uVar3);
                if ((CARRY1(*(byte *)((int)puVar12 + 2),(byte)uVar3)) && ((uVar3 & 8) == 0)) {
                  uVar4 = 0xff;
                }
                uVar3 = uVar3 << 8 | uVar3 >> 0x18;
                puVar12 = puVar12 + 3;
                uVar4 = uVar4 & 0xf8;
                *psVar13 = ((short)*(undefined4 *)
                                    ((int)pvVar2 + (uint)(uVar1 >> 0xb) * 4 + uVar4 * 0x10) * 0x20 +
                           (short)*(undefined4 *)
                                   ((int)pvVar2 + ((uVar1 & 0x7c0) >> 6) * 4 + uVar4 * 0x10)) * 0x40
                           + (short)*(undefined4 *)((int)pvVar2 + (uVar1 & 0x1f) * 4 + uVar4 * 0x10)
                ;
                uVar5 = uVar5 - 1;
                psVar13 = psVar13 + 1;
              } while (uVar5 != 0);
            }
          }
          iVar9 = iVar9 + iVar6;
          puVar11 = puVar11 + iVar7;
          local_c = local_c - 1;
        } while (local_c != 0);
      }
    }
    return;
  }
  local_8 = iVar8 * 4;
  if (*(char *)(param_1 + 0x18) == '\0') {
    local_c = local_c >> 1;
    puVar11 = param_3;
    do {
      param_3 = param_2;
      param_2 = param_2 + iVar8;
      while( true ) {
        pvVar2 = DAT_00584510;
        uVar5 = *param_3;
        param_3 = param_3 + 1;
        uVar3 = uVar5 & 0xffff;
        if (uVar3 == 0xffff) break;
        uVar4 = uVar3 + 1 >> 1;
        puVar10 = (ushort *)((int)puVar11 + uVar4 * 6);
        uVar5 = (uVar5 >> 0x10) - uVar3 >> 1;
        if (uVar5 != 0) {
          uVar3 = *(uint *)(&DAT_00574798 + (local_c & 3) * 4);
          psVar13 = (short *)(iVar9 + uVar4 * 2);
          do {
            uVar1 = *puVar10;
            uVar4 = (uint)(byte)((byte)puVar10[1] + (byte)uVar3);
            if ((CARRY1((byte)puVar10[1],(byte)uVar3)) && ((uVar3 & 8) == 0)) {
              uVar4 = 0xff;
            }
            uVar3 = uVar3 << 8 | uVar3 >> 0x18;
            puVar10 = puVar10 + 3;
            uVar4 = uVar4 & 0xf8;
            *psVar13 = ((short)*(undefined4 *)((int)pvVar2 + (uint)(uVar1 >> 10) * 4 + uVar4 * 0x10)
                        * 0x20 + (short)*(undefined4 *)
                                         ((int)pvVar2 + ((uVar1 & 0x3c0) >> 5) * 4 + uVar4 * 0x10))
                       * 0x20 + (short)*(undefined4 *)
                                        ((int)pvVar2 + (uVar1 & 0x1f) * 4 + uVar4 * 0x10);
            uVar5 = uVar5 - 1;
            psVar13 = psVar13 + 1;
          } while (uVar5 != 0);
        }
      }
      iVar9 = iVar9 + iVar6;
      puVar11 = (uint *)((int)puVar11 + iVar7 * 2);
      local_c = local_c - 1;
    } while (local_c != 0);
    return;
  }
  local_c = local_c >> 1;
  puVar11 = param_3;
  do {
    param_3 = param_2;
    param_2 = param_2 + iVar8;
    while( true ) {
      pvVar2 = DAT_00584510;
      uVar5 = *param_3;
      param_3 = param_3 + 1;
      uVar3 = uVar5 & 0xffff;
      if (uVar3 == 0xffff) break;
      uVar4 = uVar3 + 1 >> 1;
      puVar10 = (ushort *)((int)puVar11 + uVar4 * 6);
      uVar5 = (uVar5 >> 0x10) - uVar3 >> 1;
      if (uVar5 != 0) {
        uVar3 = *(uint *)(&DAT_00574798 + (local_c & 3) * 4);
        psVar13 = (short *)(iVar9 + uVar4 * 2);
        do {
          uVar1 = *puVar10;
          uVar4 = (uint)(byte)((byte)puVar10[1] + (byte)uVar3);
          if ((CARRY1((byte)puVar10[1],(byte)uVar3)) && ((uVar3 & 8) == 0)) {
            uVar4 = 0xff;
          }
          uVar3 = uVar3 << 8 | uVar3 >> 0x18;
          puVar10 = puVar10 + 3;
          uVar4 = uVar4 & 0xf8;
          *psVar13 = ((short)*(undefined4 *)((int)pvVar2 + (uint)(uVar1 >> 0xb) * 4 + uVar4 * 0x10)
                      * 0x20 + (short)*(undefined4 *)
                                       ((int)pvVar2 + ((uVar1 & 0x7c0) >> 6) * 4 + uVar4 * 0x10)) *
                     0x40 + (short)*(undefined4 *)((int)pvVar2 + (uVar1 & 0x1f) * 4 + uVar4 * 0x10);
          uVar5 = uVar5 - 1;
          psVar13 = psVar13 + 1;
        } while (uVar5 != 0);
      }
    }
    iVar9 = iVar9 + iVar6;
    puVar11 = (uint *)((int)puVar11 + iVar7 * 2);
    local_c = local_c - 1;
  } while (local_c != 0);
  return;
}

