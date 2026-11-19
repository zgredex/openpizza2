// rea decompile_all
// name: Sprite_Rotate
// address: 0x53d840
// body: available
// range: 0x53d840-0x53dd44 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined2 * __thiscall Sprite_Rotate(void *this,undefined2 *param_1)

{
  undefined2 *puVar1;
  void *pvVar2;
  uint uVar3;
  undefined2 *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined2 *puVar9;
  undefined4 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined2 *puVar13;
  undefined4 *puVar14;
  undefined2 *puVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  int local_14;
  undefined4 *local_10;
  undefined4 *local_c;
  
  puVar1 = (undefined2 *)(uint)*(byte *)((int)this + 0x36);
  if (puVar1 != param_1) {
    puVar1 = (undefined2 *)(uint)*(byte *)((int)this + 0x39);
    uVar3 = (uint)param_1 & 7;
    *(char *)((int)this + 0x36) = (char)uVar3;
    if (*(byte *)((int)this + 0x39) == 0) {
      puVar1 = (undefined2 *)Sprite_RealizeLazy(this);
    }
    if (((*(byte *)((int)this + 4) & 1) == 0) && (*(char *)((int)this + 5) == '\b')) {
      if (*(int *)((int)this + 0x30) == 0) {
        pvVar2 = operator_new(*(uint *)((int)this + 0x18));
        *(void **)((int)this + 0x30) = pvVar2;
      }
      if ((*(byte *)((int)this + 4) & 0x10) == 0) {
        local_14 = (int)(*(short *)((int)this + 6) >> 1);
        param_1 = (undefined2 *)(int)*(short *)((int)this + 6);
        if (*(char *)((int)this + 5) == '\b') {
          uVar3 = uVar3 + 8;
        }
      }
      else {
        local_14 = (int)*(short *)((int)this + 6);
        param_1 = (undefined2 *)(local_14 * 2);
      }
      puVar1 = param_1;
      iVar8 = (int)*(short *)((int)this + 8);
      switch(uVar3) {
      case 0:
      case 8:
        puVar1 = *(undefined2 **)((int)this + 0x18);
        puVar10 = *(undefined4 **)((int)this + 0x2c);
        local_c = *(undefined4 **)((int)this + 0x30);
        break;
      case 1:
        puVar9 = *(undefined2 **)((int)this + 0x2c);
        puVar1 = (undefined2 *)(*(int *)((int)this + 0x30) + -2 + local_14 * 2);
        puVar4 = puVar9;
        do {
          iVar6 = local_14;
          puVar13 = puVar4;
          puVar15 = puVar1;
          do {
            *puVar15 = *puVar13;
            puVar15 = puVar15 + -1;
            iVar6 = iVar6 + -1;
            puVar13 = puVar13 + 1;
          } while (iVar6 != 0);
          puVar4 = (undefined2 *)((int)puVar4 + (int)param_1);
          puVar1 = (undefined2 *)((int)puVar1 + (int)param_1);
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
        *(undefined1 *)((int)this + 0x37) = 0;
        return puVar9;
      case 2:
        puVar9 = *(undefined2 **)((int)this + 0x2c);
        puVar1 = (undefined2 *)(*(int *)((int)this + 0x30) + -2 + iVar8 * 2);
        iVar6 = iVar8;
        do {
          iVar5 = local_14;
          puVar4 = puVar9;
          puVar13 = puVar1;
          do {
            *puVar13 = *puVar4;
            puVar13 = puVar13 + iVar8;
            iVar5 = iVar5 + -1;
            puVar4 = puVar4 + 1;
          } while (iVar5 != 0);
          puVar9 = (undefined2 *)((int)puVar9 + (int)param_1);
          puVar1 = puVar1 + -1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        *(undefined1 *)((int)this + 0x37) = 1;
        return this;
      case 3:
        puVar9 = *(undefined2 **)((int)this + 0x2c);
        puVar1 = (undefined2 *)(*(int *)((int)this + 0x30) + -2 + iVar8 * local_14 * 2);
        iVar6 = iVar8;
        puVar4 = puVar1;
        do {
          iVar5 = local_14;
          puVar13 = puVar9;
          puVar15 = puVar4;
          do {
            *puVar15 = *puVar13;
            puVar15 = puVar15 + -iVar8;
            iVar5 = iVar5 + -1;
            puVar13 = puVar13 + 1;
          } while (iVar5 != 0);
          puVar9 = (undefined2 *)((int)puVar9 + (int)param_1);
          puVar4 = puVar4 + -1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        *(undefined1 *)((int)this + 0x37) = 1;
        return puVar1;
      case 4:
        puVar4 = *(undefined2 **)((int)this + 0x2c);
        puVar9 = (undefined2 *)(*(int *)((int)this + 0x30) + -2 + local_14 * 2);
        puVar1 = puVar4 + (iVar8 + -1) * local_14;
        do {
          iVar6 = local_14;
          puVar13 = puVar1;
          puVar15 = puVar9;
          do {
            *puVar15 = *puVar13;
            puVar15 = puVar15 + -1;
            iVar6 = iVar6 + -1;
            puVar13 = puVar13 + 1;
          } while (iVar6 != 0);
          puVar1 = (undefined2 *)((int)puVar1 - (int)param_1);
          puVar9 = (undefined2 *)((int)puVar9 + (int)param_1);
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
        *(undefined1 *)((int)this + 0x37) = 0;
        return puVar4;
      case 5:
        local_10 = *(undefined4 **)((int)this + 0x30);
        local_c = (undefined4 *)(*(int *)((int)this + 0x2c) + (iVar8 + -1) * local_14 * 2);
        param_1 = (undefined2 *)0x0;
        if (0 < iVar8 + -1) {
          do {
            puVar10 = local_c;
            puVar14 = local_10;
            for (uVar3 = (uint)puVar1 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
              *puVar14 = *puVar10;
              puVar10 = puVar10 + 1;
              puVar14 = puVar14 + 1;
            }
            for (uVar3 = (uint)puVar1 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
              *(undefined1 *)puVar14 = *(undefined1 *)puVar10;
              puVar10 = (undefined4 *)((int)puVar10 + 1);
              puVar14 = (undefined4 *)((int)puVar14 + 1);
            }
            local_10 = (undefined4 *)((int)local_10 + local_14 * 2);
            local_c = (undefined4 *)((int)local_c + local_14 * -2);
            param_1 = (undefined2 *)((int)param_1 + 1);
          } while ((int)param_1 < *(short *)((int)this + 8) + -1);
        }
        puVar10 = local_c;
        local_c = local_10;
        break;
      case 6:
        puVar9 = *(undefined2 **)((int)this + 0x2c);
        puVar1 = (undefined2 *)(*(int *)((int)this + 0x30) + (local_14 + -1) * iVar8 * 2);
        iVar6 = iVar8;
        puVar4 = puVar9;
        do {
          iVar5 = local_14;
          puVar13 = puVar4;
          puVar15 = puVar1;
          do {
            *puVar15 = *puVar13;
            puVar15 = puVar15 + -iVar8;
            iVar5 = iVar5 + -1;
            puVar13 = puVar13 + 1;
          } while (iVar5 != 0);
          puVar4 = (undefined2 *)((int)puVar4 + (int)param_1);
          puVar1 = puVar1 + 1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        *(undefined1 *)((int)this + 0x37) = 1;
        return puVar9;
      case 7:
        puVar1 = *(undefined2 **)((int)this + 0x30);
        puVar9 = *(undefined2 **)((int)this + 0x2c);
        iVar6 = iVar8;
        do {
          iVar5 = local_14;
          puVar4 = puVar9;
          puVar13 = puVar1;
          do {
            *puVar13 = *puVar4;
            puVar13 = puVar13 + iVar8;
            iVar5 = iVar5 + -1;
            puVar4 = puVar4 + 1;
          } while (iVar5 != 0);
          puVar9 = (undefined2 *)((int)puVar9 + (int)param_1);
          puVar1 = puVar1 + 1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        *(undefined1 *)((int)this + 0x37) = 1;
        return this;
      case 9:
        puVar17 = *(undefined1 **)((int)this + 0x2c);
        puVar1 = (undefined2 *)((int)param_1 + *(int *)((int)this + 0x30) + -1);
        puVar9 = puVar1;
        do {
          puVar4 = param_1;
          puVar12 = puVar17;
          puVar13 = puVar9;
          do {
            *(undefined1 *)puVar13 = *puVar12;
            puVar13 = (undefined2 *)((int)puVar13 + -1);
            puVar4 = (undefined2 *)((int)puVar4 + -1);
            puVar12 = puVar12 + 1;
          } while (puVar4 != (undefined2 *)0x0);
          puVar17 = puVar17 + (int)param_1;
          puVar9 = (undefined2 *)((int)puVar9 + (int)param_1);
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
        *(undefined1 *)((int)this + 0x37) = 0;
        return puVar1;
      case 10:
        puVar1 = *(undefined2 **)((int)this + 0x2c);
        puVar17 = (undefined1 *)(iVar8 + -1 + *(int *)((int)this + 0x30));
        iVar6 = iVar8;
        puVar9 = puVar1;
        do {
          puVar4 = param_1;
          puVar13 = puVar9;
          puVar12 = puVar17;
          do {
            *puVar12 = *(undefined1 *)puVar13;
            puVar12 = puVar12 + iVar8;
            puVar4 = (undefined2 *)((int)puVar4 + -1);
            puVar13 = (undefined2 *)((int)puVar13 + 1);
          } while (puVar4 != (undefined2 *)0x0);
          puVar9 = (undefined2 *)((int)puVar9 + (int)param_1);
          puVar17 = puVar17 + -1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        *(undefined1 *)((int)this + 0x37) = 1;
        return puVar1;
      case 0xb:
        puVar12 = *(undefined1 **)((int)this + 0x2c);
        puVar17 = (undefined1 *)(iVar8 * (int)param_1 + -1 + *(int *)((int)this + 0x30));
        iVar6 = iVar8;
        do {
          puVar1 = param_1;
          puVar11 = puVar12;
          puVar16 = puVar17;
          do {
            *puVar16 = *puVar11;
            puVar16 = puVar16 + -iVar8;
            puVar1 = (undefined2 *)((int)puVar1 + -1);
            puVar11 = puVar11 + 1;
          } while (puVar1 != (undefined2 *)0x0);
          puVar12 = puVar12 + (int)param_1;
          puVar17 = puVar17 + -1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        *(undefined1 *)((int)this + 0x37) = 1;
        return this;
      case 0xc:
        puVar17 = (undefined1 *)((int)param_1 + *(int *)((int)this + 0x30) + -1);
        puVar12 = (undefined1 *)((iVar8 + -1) * (int)param_1 + *(int *)((int)this + 0x2c));
        do {
          puVar1 = param_1;
          puVar11 = puVar12;
          puVar16 = puVar17;
          do {
            *puVar16 = *puVar11;
            puVar16 = puVar16 + -1;
            puVar1 = (undefined2 *)((int)puVar1 + -1);
            puVar11 = puVar11 + 1;
          } while (puVar1 != (undefined2 *)0x0);
          puVar12 = puVar12 + -(int)param_1;
          puVar17 = puVar17 + (int)param_1;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
        *(undefined1 *)((int)this + 0x37) = 0;
        return this;
      case 0xd:
        local_c = *(undefined4 **)((int)this + 0x30);
        local_10 = (undefined4 *)((iVar8 + -1) * (int)param_1 + *(int *)((int)this + 0x2c));
        param_1 = (undefined2 *)0x0;
        if (0 < iVar8 + -1) {
          do {
            puVar10 = local_10;
            puVar14 = local_c;
            for (uVar3 = (uint)puVar1 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
              *puVar14 = *puVar10;
              puVar10 = puVar10 + 1;
              puVar14 = puVar14 + 1;
            }
            for (uVar3 = (uint)puVar1 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
              *(undefined1 *)puVar14 = *(undefined1 *)puVar10;
              puVar10 = (undefined4 *)((int)puVar10 + 1);
              puVar14 = (undefined4 *)((int)puVar14 + 1);
            }
            local_c = (undefined4 *)((int)local_c + (int)puVar1);
            local_10 = (undefined4 *)((int)local_10 - (int)puVar1);
            param_1 = (undefined2 *)((int)param_1 + 1);
          } while ((int)param_1 < *(short *)((int)this + 8) + -1);
        }
        puVar10 = local_10;
        break;
      case 0xe:
        puVar17 = *(undefined1 **)((int)this + 0x2c);
        puVar12 = (undefined1 *)(((int)param_1 + -1) * iVar8 + *(int *)((int)this + 0x30));
        iVar6 = iVar8;
        do {
          puVar1 = param_1;
          puVar11 = puVar17;
          puVar16 = puVar12;
          do {
            *puVar16 = *puVar11;
            puVar16 = puVar16 + -iVar8;
            puVar1 = (undefined2 *)((int)puVar1 + -1);
            puVar11 = puVar11 + 1;
          } while (puVar1 != (undefined2 *)0x0);
          puVar17 = puVar17 + (int)param_1;
          puVar12 = puVar12 + 1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        *(undefined1 *)((int)this + 0x37) = 1;
        return this;
      case 0xf:
        puVar17 = *(undefined1 **)((int)this + 0x30);
        puVar12 = *(undefined1 **)((int)this + 0x2c);
        iVar6 = iVar8;
        do {
          puVar1 = param_1;
          puVar11 = puVar12;
          puVar16 = puVar17;
          do {
            *puVar16 = *puVar11;
            puVar16 = puVar16 + iVar8;
            puVar1 = (undefined2 *)((int)puVar1 + -1);
            puVar11 = puVar11 + 1;
          } while (puVar1 != (undefined2 *)0x0);
          puVar12 = puVar12 + (int)param_1;
          puVar17 = puVar17 + 1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        *(undefined1 *)((int)this + 0x37) = 1;
        return this;
      default:
        uVar3 = *(uint *)((int)this + 0x18);
        *(undefined1 *)((int)this + 0x37) = 0;
        puVar10 = *(undefined4 **)((int)this + 0x2c);
        puVar14 = *(undefined4 **)((int)this + 0x30);
        for (uVar7 = uVar3 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
          *puVar14 = *puVar10;
          puVar10 = puVar10 + 1;
          puVar14 = puVar14 + 1;
        }
        for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
          *(undefined1 *)puVar14 = *(undefined1 *)puVar10;
          puVar10 = (undefined4 *)((int)puVar10 + 1);
          puVar14 = (undefined4 *)((int)puVar14 + 1);
        }
        return param_1;
      }
      for (uVar3 = (uint)puVar1 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *local_c = *puVar10;
        puVar10 = puVar10 + 1;
        local_c = local_c + 1;
      }
      for (uVar3 = (uint)puVar1 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined1 *)local_c = *(undefined1 *)puVar10;
        puVar10 = (undefined4 *)((int)puVar10 + 1);
        local_c = (undefined4 *)((int)local_c + 1);
      }
      *(undefined1 *)((int)this + 0x37) = 0;
      return puVar1;
    }
  }
  return puVar1;
}

