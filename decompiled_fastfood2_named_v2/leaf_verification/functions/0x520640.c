// rea decompile_all
// name: Surface_BlitOriented
// address: 0x520640
// body: available
// range: 0x520640-0x520a57 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall
Surface_BlitOriented
          (void *this,int param_1,undefined2 *param_2,uint param_3,uint param_4,int *param_5)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined2 *puVar8;
  uint uVar9;
  undefined4 *puVar10;
  int iVar11;
  undefined4 *puVar12;
  int local_8;
  uint local_4;
  
                    /* Leaf reversal proposal batch 1. */
  switch(*param_5) {
  case 0:
    puVar7 = (undefined4 *)(param_1 + *(int *)((int)this + 0x20) * param_3 * 2);
    puVar2 = (undefined4 *)((int)param_2 + *(int *)((int)this + 0x1c) * param_3);
    if ((int)param_3 < (int)param_4) {
      param_3 = param_4 - param_3;
      do {
        uVar5 = *(uint *)((int)this + 0x28);
        puVar10 = puVar7;
        puVar12 = puVar2;
        for (uVar4 = (uVar5 & 0x7fffffff) >> 1; uVar4 != 0; uVar4 = uVar4 - 1) {
          *puVar12 = *puVar10;
          puVar10 = puVar10 + 1;
          puVar12 = puVar12 + 1;
        }
        for (iVar1 = (uVar5 & 1) << 1; iVar1 != 0; iVar1 = iVar1 + -1) {
          *(undefined1 *)puVar12 = *(undefined1 *)puVar10;
          puVar10 = (undefined4 *)((int)puVar10 + 1);
          puVar12 = (undefined4 *)((int)puVar12 + 1);
        }
        puVar2 = (undefined4 *)((int)puVar2 + *(int *)((int)this + 0x1c));
        puVar7 = (undefined4 *)((int)puVar7 + *(int *)((int)this + 0x20) * 2);
        param_3 = param_3 - 1;
      } while (param_3 != 0);
      return;
    }
    break;
  case 1:
    iVar1 = (*(int *)((int)this + 0x28) - param_3) + -1;
    puVar7 = (undefined4 *)(param_1 + *(int *)((int)this + 0x20) * iVar1 * 2);
    puVar2 = (undefined4 *)((int)param_2 + iVar1 * *(int *)((int)this + 0x1c));
    if ((int)param_3 < (int)param_4) {
      param_3 = param_4 - param_3;
      do {
        uVar5 = *(uint *)((int)this + 0x28);
        puVar10 = puVar7;
        puVar12 = puVar2;
        for (uVar4 = (uVar5 & 0x7fffffff) >> 1; uVar4 != 0; uVar4 = uVar4 - 1) {
          *puVar12 = *puVar10;
          puVar10 = puVar10 + 1;
          puVar12 = puVar12 + 1;
        }
        for (iVar1 = (uVar5 & 1) << 1; iVar1 != 0; iVar1 = iVar1 + -1) {
          *(undefined1 *)puVar12 = *(undefined1 *)puVar10;
          puVar10 = (undefined4 *)((int)puVar10 + 1);
          puVar12 = (undefined4 *)((int)puVar12 + 1);
        }
        puVar2 = (undefined4 *)((int)puVar2 - *(int *)((int)this + 0x1c));
        puVar7 = (undefined4 *)((int)puVar7 + *(int *)((int)this + 0x20) * -2);
        param_3 = param_3 - 1;
      } while (param_3 != 0);
      return;
    }
    break;
  case 2:
    puVar7 = (undefined4 *)(param_1 + param_3 * 2);
    puVar2 = (undefined4 *)(param_2 + param_3);
    uVar5 = (param_4 - param_3) * 2;
    if ((0 < (int)uVar5) && (local_8 = 0, 0 < *(int *)((int)this + 0x28))) {
      do {
        puVar10 = puVar7;
        puVar12 = puVar2;
        for (uVar4 = (param_4 - param_3 & 0x7fffffff) >> 1; uVar4 != 0; uVar4 = uVar4 - 1) {
          *puVar12 = *puVar10;
          puVar10 = puVar10 + 1;
          puVar12 = puVar12 + 1;
        }
        for (uVar4 = uVar5 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined1 *)puVar12 = *(undefined1 *)puVar10;
          puVar10 = (undefined4 *)((int)puVar10 + 1);
          puVar12 = (undefined4 *)((int)puVar12 + 1);
        }
        puVar2 = (undefined4 *)((int)puVar2 + *(int *)((int)this + 0x1c));
        puVar7 = (undefined4 *)((int)puVar7 + *(int *)((int)this + 0x20) * 2);
        local_8 = local_8 + 1;
      } while (local_8 < *(int *)((int)this + 0x28));
      return;
    }
    break;
  case 3:
    iVar1 = *(int *)((int)this + 0x28) - param_4;
    puVar7 = (undefined4 *)(param_1 + iVar1 * 2);
    puVar2 = (undefined4 *)(param_2 + iVar1);
    uVar5 = (param_4 - param_3) * 2;
    if ((0 < (int)uVar5) && (local_8 = 0, 0 < *(int *)((int)this + 0x28))) {
      do {
        puVar10 = puVar7;
        puVar12 = puVar2;
        for (uVar4 = (param_4 - param_3 & 0x7fffffff) >> 1; uVar4 != 0; uVar4 = uVar4 - 1) {
          *puVar12 = *puVar10;
          puVar10 = puVar10 + 1;
          puVar12 = puVar12 + 1;
        }
        for (uVar4 = uVar5 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined1 *)puVar12 = *(undefined1 *)puVar10;
          puVar10 = (undefined4 *)((int)puVar10 + 1);
          puVar12 = (undefined4 *)((int)puVar12 + 1);
        }
        puVar2 = (undefined4 *)((int)puVar2 + *(int *)((int)this + 0x1c));
        local_8 = local_8 + 1;
        puVar7 = (undefined4 *)((int)puVar7 + *(int *)((int)this + 0x20) * 2);
      } while (local_8 < *(int *)((int)this + 0x28));
      return;
    }
    break;
  case 4:
  case 6:
    goto LAB_0052083f;
  case 5:
  case 7:
    uVar5 = *(int *)((int)this + 0x2c) - param_3;
    param_3 = *(int *)((int)this + 0x2c) - param_4;
    param_4 = uVar5;
LAB_0052083f:
    uVar5 = param_3 * 2;
    uVar4 = param_4 * 2;
    puVar7 = (undefined4 *)(param_1 + param_3 * 4);
    puVar2 = (undefined4 *)(param_2 + param_3 * 2);
    uVar9 = (uVar4 + param_3 * -2) * 2;
    if (5 < *param_5) {
      iVar1 = *(int *)((int)this + 0x28) + -1;
      puVar7 = (undefined4 *)((int)puVar7 + *(int *)((int)this + 0x20) * iVar1 * 2);
      puVar2 = (undefined4 *)((int)puVar2 + *(int *)((int)this + 0x1c) * iVar1);
    }
    iVar1 = *(int *)((int)this + 0x28);
    local_8 = 0;
    param_3 = uVar5;
    param_4 = uVar4;
    local_4 = uVar9;
    if (0 < iVar1) {
      while (0 < (int)uVar9) {
        if (iVar1 < (int)uVar4) {
          uVar3 = uVar9 + (iVar1 - uVar4) * 2;
        }
        else {
          uVar3 = uVar9;
        }
        if (0 < (int)uVar3) {
          puVar10 = puVar7;
          puVar12 = puVar2;
          for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar12 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar12 = puVar12 + 1;
          }
          for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
            *(undefined1 *)puVar12 = *(undefined1 *)puVar10;
            puVar10 = (undefined4 *)((int)puVar10 + 1);
            puVar12 = (undefined4 *)((int)puVar12 + 1);
          }
          uVar4 = param_4;
          uVar9 = local_4;
          uVar5 = param_3;
        }
        if ((int)uVar5 < 1) {
          uVar9 = uVar9 - 2;
          local_4 = uVar9;
        }
        else {
          puVar2 = (undefined4 *)((int)puVar2 + -2);
          puVar7 = (undefined4 *)((int)puVar7 + -2);
          uVar5 = uVar5 - 1;
          uVar4 = uVar4 - 1;
          param_3 = uVar5;
          param_4 = uVar4;
        }
        iVar1 = *(int *)((int)this + 0x1c);
        if (*param_5 < 6) {
          iVar11 = *(int *)((int)this + 0x20);
        }
        else {
          iVar1 = -iVar1;
          iVar11 = -*(int *)((int)this + 0x20);
        }
        puVar2 = (undefined4 *)((int)puVar2 + iVar1);
        puVar7 = (undefined4 *)((int)puVar7 + iVar11 * 2);
        local_8 = local_8 + 1;
        iVar1 = *(int *)((int)this + 0x28);
        if (iVar1 <= local_8) {
          return;
        }
      }
    }
    break;
  case 8:
    if (param_4 * 2 != 0) {
      param_3 = param_4;
      if ((param_4 & 1) == 0) {
        param_3 = param_4 | 1;
      }
      iVar1 = (int)(*(int *)((int)this + 0x2c) - param_3) / 2;
      puVar7 = (undefined4 *)(param_1 + (*(int *)((int)this + 0x20) + 1) * iVar1 * 2);
      puVar2 = (undefined4 *)((int)param_2 + (*(int *)((int)this + 0x1c) + 2) * iVar1);
      if (0 < (int)param_3) {
        do {
          puVar10 = puVar7;
          puVar12 = puVar2;
          for (uVar5 = (param_4 & 0x7fffffff) >> 1; uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar12 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar12 = puVar12 + 1;
          }
          for (uVar5 = param_4 * 2 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *(undefined1 *)puVar12 = *(undefined1 *)puVar10;
            puVar10 = (undefined4 *)((int)puVar10 + 1);
            puVar12 = (undefined4 *)((int)puVar12 + 1);
          }
          puVar2 = (undefined4 *)((int)puVar2 + *(int *)((int)this + 0x1c));
          puVar7 = (undefined4 *)((int)puVar7 + *(int *)((int)this + 0x20) * 2);
          param_3 = param_3 - 1;
        } while (param_3 != 0);
        return;
      }
    }
    break;
  case 9:
    iVar1 = *(int *)((int)this + 0x28);
    local_8 = 0;
    if (0 < iVar1) {
      param_5 = (int *)0x0;
      piVar6 = param_5;
      do {
        for (; iVar1 <= (int)piVar6; piVar6 = (int *)((int)piVar6 - iVar1)) {
        }
        iVar11 = 0;
        if (0 < iVar1) {
          puVar8 = param_2;
          do {
            if (((int)param_3 <= *(int *)(&DAT_00573bc0 + (int)piVar6 * 4)) &&
               (*(int *)(&DAT_00573bc0 + (int)piVar6 * 4) <= (int)param_4)) {
              *puVar8 = *(undefined2 *)((param_1 - (int)param_2) + (int)puVar8);
            }
            piVar6 = (int *)((int)piVar6 + 1);
            if (*(int *)((int)this + 0x28) <= (int)piVar6) {
              piVar6 = (int *)0x0;
            }
            iVar11 = iVar11 + 1;
            puVar8 = puVar8 + 1;
          } while (iVar11 < *(int *)((int)this + 0x28));
        }
        param_2 = (undefined2 *)((int)param_2 + *(int *)((int)this + 0x1c));
        iVar1 = *(int *)((int)this + 0x28);
        param_1 = param_1 + *(int *)((int)this + 0x20) * 2;
        local_8 = local_8 + 1;
        piVar6 = (int *)((int)param_5 + 5);
        param_5 = piVar6;
      } while (local_8 < iVar1);
    }
  }
  return;
}

