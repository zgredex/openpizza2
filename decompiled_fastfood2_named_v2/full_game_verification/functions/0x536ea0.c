// rea decompile_all
// name: Sprite_ConvertTo16Bit
// address: 0x536ea0
// body: available
// range: 0x536ea0-0x5371fa inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


ushort * __thiscall Sprite_ConvertTo16Bit(void *this,int param_1,int param_2,int param_3)

{
  byte *pbVar1;
  byte bVar2;
  ushort *puVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  ushort uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  ushort uVar12;
  uint uVar13;
  ushort *puVar14;
  uint uVar15;
  undefined4 *puVar16;
  ushort uVar17;
  int iVar18;
  uint local_1c;
  char local_10 [16];
  
  if ((param_3 != 0) &&
     ((*(char *)((int)this + 0x10) == '\x10' || (*(char *)((int)this + 0x10) == '\x0f')))) {
    return *(ushort **)((int)this + 0x18);
  }
  puVar3 = operator_new(*(int *)((int)this + 8) * *(int *)((int)this + 4) * 2);
  if (puVar3 == (ushort *)0x0) {
    return (ushort *)0x0;
  }
  switch(*(char *)((int)this + 0x10)) {
  case '\b':
    iVar10 = *(int *)((int)this + 0x14);
    iVar8 = *(int *)((int)this + 8) * *(int *)((int)this + 4);
    iVar18 = *(int *)((int)this + 0x18);
    iVar4 = 0;
    puVar14 = puVar3;
    if (0 < iVar8) {
      do {
        pbVar6 = (byte *)(iVar4 + iVar18);
        iVar4 = iVar4 + 1;
        *puVar14 = *(ushort *)(iVar10 + 4 + (uint)*pbVar6 * 2);
        puVar14 = puVar14 + 1;
      } while (iVar4 < iVar8);
    }
    break;
  case '\x0f':
  case '\x10':
    uVar9 = *(int *)((int)this + 8) * *(int *)((int)this + 4);
    puVar16 = *(undefined4 **)((int)this + 0x18);
    puVar14 = puVar3;
    for (uVar15 = (uVar9 & 0x7fffffff) >> 1; uVar15 != 0; uVar15 = uVar15 - 1) {
      *(undefined4 *)puVar14 = *puVar16;
      puVar16 = puVar16 + 1;
      puVar14 = puVar14 + 2;
    }
    for (uVar9 = uVar9 * 2 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
      *(undefined1 *)puVar14 = *(undefined1 *)puVar16;
      puVar16 = (undefined4 *)((int)puVar16 + 1);
      puVar14 = (ushort *)((int)puVar14 + 1);
    }
    break;
  case '\x18':
  case ' ':
    pbVar6 = *(byte **)((int)this + 0x18);
    uVar9 = (uint)(*(char *)((int)this + 0x10) == ' ');
    if (param_2 == 0) {
      iVar10 = *(int *)((int)this + 8) * *(int *)((int)this + 4);
      if (*(char *)(param_1 + 0x18) == '\0') {
        if (0 < iVar10) {
          puVar14 = puVar3;
          do {
            pbVar1 = pbVar6 + 1;
            bVar2 = *pbVar6;
            pbVar5 = pbVar6 + 2;
            pbVar6 = pbVar5 + uVar9 + 1;
            iVar10 = iVar10 + -1;
            *puVar14 = (*pbVar5 & 0xf8) << 7 | (*pbVar1 & 0xf8) << 2 | (ushort)(bVar2 >> 3);
            puVar14 = puVar14 + 1;
          } while (iVar10 != 0);
        }
      }
      else if (0 < iVar10) {
        puVar14 = puVar3;
        do {
          pbVar1 = pbVar6 + 1;
          bVar2 = *pbVar6;
          pbVar5 = pbVar6 + 2;
          pbVar6 = pbVar5 + uVar9 + 1;
          iVar10 = iVar10 + -1;
          *puVar14 = (*pbVar5 & 0xf8) << 8 | (*pbVar1 & 0xfc) << 3 | (ushort)(bVar2 >> 3);
          puVar14 = puVar14 + 1;
        } while (iVar10 != 0);
      }
    }
    else {
      local_10[1] = 0xfe;
      local_10[3] = 0xff;
      local_10[4] = 0xfe;
      local_10[0xb] = 0xff;
      local_10[6] = 0xfd;
      local_10[0xe] = 0xfd;
      local_10[0] = '\0';
      local_10[2] = 1;
      local_10[5] = 2;
      local_10[7] = 3;
      local_10[8] = 2;
      local_10[9] = 0;
      local_10[10] = 1;
      local_10[0xc] = 0xfc;
      local_10[0xd] = 4;
      local_10[0xf] = 3;
      param_2 = 0;
      local_1c = 0;
      if (0 < *(int *)((int)this + 8)) {
        do {
          uVar15 = 0;
          if (0 < *(int *)((int)this + 4)) {
            puVar14 = puVar3 + param_2;
            do {
              iVar10 = (int)local_10[(uVar15 & 3) + (local_1c & 3) * 4];
              iVar18 = (uint)*pbVar6 + iVar10;
              uVar11 = (uint)pbVar6[1] + iVar10;
              uVar13 = (uint)pbVar6[2] + iVar10;
              if (iVar18 < 0x100) {
                if (iVar18 < 1) {
                  uVar17 = 0;
                }
                else {
                  uVar17 = (ushort)(iVar18 >> 3);
                }
              }
              else {
                uVar17 = 0x1f;
              }
              if (*(char *)(param_1 + 0x18) == '\0') {
                if ((int)uVar11 < 0x100) {
                  if ((int)uVar11 < 1) {
                    uVar7 = 0;
                  }
                  else {
                    uVar7 = (ushort)((uVar11 & 0xf8) << 2);
                  }
                }
                else {
                  uVar7 = 0x3e0;
                }
                if ((int)uVar13 < 0x100) {
                  if ((int)uVar13 < 1) goto LAB_0053717d;
                  uVar12 = (ushort)((uVar13 & 0xf8) << 7);
                }
                else {
                  uVar12 = 0x7c00;
                }
              }
              else {
                if ((int)uVar11 < 0x100) {
                  if ((int)uVar11 < 1) {
                    uVar7 = 0;
                  }
                  else {
                    uVar7 = (ushort)((uVar11 & 0xfc) << 3);
                  }
                }
                else {
                  uVar7 = 0x7e0;
                }
                if ((int)uVar13 < 0x100) {
                  if ((int)uVar13 < 1) {
LAB_0053717d:
                    uVar12 = 0;
                  }
                  else {
                    uVar12 = (ushort)((uVar13 & 0xf8) << 8);
                  }
                }
                else {
                  uVar12 = 0xf800;
                }
              }
              *puVar14 = uVar12 | uVar7 | uVar17;
              param_2 = param_2 + 1;
              puVar14 = puVar14 + 1;
              pbVar6 = pbVar6 + uVar9 + 3;
              uVar15 = uVar15 + 1;
            } while ((int)uVar15 < *(int *)((int)this + 4));
          }
          local_1c = local_1c + 1;
        } while ((int)local_1c < *(int *)((int)this + 8));
      }
    }
  }
  if (param_3 != 0) {
    Mem_Free(*(LPVOID *)((int)this + 0x18));
    *(ushort **)((int)this + 0x18) = puVar3;
    *(undefined1 *)((int)this + 0x10) = 0x10;
    *(int *)((int)this + 0xc) = *(int *)((int)this + 8) * *(int *)((int)this + 4) * 2;
  }
  return puVar3;
}

