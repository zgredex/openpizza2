// rea decompile_all
// name: FUN_00557291
// address: 0x557291
// body: available
// range: 0x557291-0x5574b0 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_00557291(int *param_1,int *param_2)

{
  int *piVar1;
  short sVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  ushort uVar6;
  uint uVar7;
  int iVar8;
  ushort uVar9;
  uint uVar10;
  ushort uVar11;
  byte local_28;
  undefined1 uStack_27;
  undefined2 uStack_26;
  short local_24;
  undefined2 uStack_22;
  undefined2 local_20;
  undefined1 uStack_1e;
  byte bStack_1d;
  int *local_1c;
  int local_18;
  int local_14;
  ushort *local_10;
  ushort *local_c;
  short *local_8;
  
  piVar5 = param_2;
  piVar4 = param_1;
  local_18 = 0;
  local_28 = 0;
  uStack_27 = 0;
  uStack_26 = 0;
  local_24 = 0;
  uStack_22 = 0;
  local_20 = 0;
  uStack_1e = 0;
  bStack_1d = 0;
  uVar7 = *(ushort *)((int)param_1 + 10) & 0x7fff;
  uVar10 = *(ushort *)((int)param_2 + 10) & 0x7fff;
  uVar11 = (*(ushort *)((int)param_2 + 10) ^ *(ushort *)((int)param_1 + 10)) & 0x8000;
  uVar6 = (ushort)uVar7;
  piVar1 = (int *)(uVar10 + uVar7);
  if (((uVar6 < 0x7fff) && (uVar9 = (ushort)uVar10, uVar9 < 0x7fff)) && ((ushort)piVar1 < 0xbffe)) {
    if ((ushort)piVar1 < 0x3fc0) {
LAB_00557334:
      piVar4[2] = 0;
      piVar4[1] = 0;
      *piVar4 = 0;
      return;
    }
    if (((uVar6 != 0) || (piVar1 = (int *)((int)piVar1 + 1), (param_1[2] & 0x7fffffffU) != 0)) ||
       ((uVar6 = 0, param_1[1] != 0 || (*param_1 != 0)))) {
      param_1 = piVar1;
      if (((uVar9 == 0) && (param_1 = (int *)((int)param_1 + 1), (param_2[2] & 0x7fffffffU) == 0))
         && ((param_2[1] == 0 && (*param_2 == 0)))) goto LAB_00557334;
      local_14 = 0;
      local_8 = &local_24;
      param_2 = (int *)0x5;
      do {
        if (0 < (int)param_2) {
          local_c = (ushort *)(local_14 * 2 + (int)piVar4);
          local_10 = (ushort *)(piVar5 + 2);
          local_1c = param_2;
          do {
            iVar8 = FUN_00556bdd(*(uint *)(local_8 + -2),(uint)*local_c * (uint)*local_10,
                                 (uint *)(local_8 + -2));
            if (iVar8 != 0) {
              *local_8 = *local_8 + 1;
            }
            local_c = local_c + 1;
            local_10 = local_10 + -1;
            local_1c = (int *)((int)local_1c + -1);
          } while (local_1c != (int *)0x0);
        }
        local_8 = local_8 + 1;
        local_14 = local_14 + 1;
        param_2 = (int *)((int)param_2 + -1);
      } while (0 < (int)param_2);
      param_1 = (int *)((int)param_1 + 0xc002);
      if ((short)(ushort)param_1 < 1) {
LAB_005573e8:
        param_1._0_2_ = (ushort)param_1 - 1;
        if ((short)(ushort)param_1 < 0) {
          iVar8 = -(int)(short)(ushort)param_1;
          param_1._0_2_ = (ushort)param_1 + (short)iVar8;
          do {
            if ((local_28 & 1) != 0) {
              local_18 = local_18 + 1;
            }
            FUN_00556c8a((uint *)&local_28);
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
          if (local_18 != 0) {
            local_28 = local_28 | 1;
          }
        }
      }
      else {
        do {
          if ((bStack_1d & 0x80) != 0) break;
          FUN_00556c5c((uint *)&local_28);
          param_1 = (int *)((int)param_1 + 0xffff);
        } while (0 < (short)(ushort)param_1);
        if ((short)(ushort)param_1 < 1) goto LAB_005573e8;
      }
      if ((0x8000 < CONCAT11(uStack_27,local_28)) ||
         (sVar2 = CONCAT11(bStack_1d,uStack_1e), iVar3 = CONCAT22(local_20,uStack_22),
         iVar8 = CONCAT22(local_24,uStack_26),
         (CONCAT22(uStack_26,CONCAT11(uStack_27,local_28)) & 0x1ffff) == 0x18000)) {
        if (CONCAT22(local_24,uStack_26) == -1) {
          iVar8 = 0;
          if (CONCAT22(local_20,uStack_22) == -1) {
            if (CONCAT11(bStack_1d,uStack_1e) == -1) {
              param_1._0_2_ = (ushort)param_1 + 1;
              sVar2 = -0x8000;
              iVar3 = 0;
              iVar8 = 0;
            }
            else {
              sVar2 = CONCAT11(bStack_1d,uStack_1e) + 1;
              iVar3 = 0;
              iVar8 = 0;
            }
          }
          else {
            sVar2 = CONCAT11(bStack_1d,uStack_1e);
            iVar3 = CONCAT22(local_20,uStack_22) + 1;
          }
        }
        else {
          iVar8 = CONCAT22(local_24,uStack_26) + 1;
          sVar2 = CONCAT11(bStack_1d,uStack_1e);
          iVar3 = CONCAT22(local_20,uStack_22);
        }
      }
      local_24 = (short)((uint)iVar8 >> 0x10);
      uStack_26 = (undefined2)iVar8;
      local_20 = (undefined2)((uint)iVar3 >> 0x10);
      uStack_22 = (undefined2)iVar3;
      bStack_1d = (byte)((ushort)sVar2 >> 8);
      uStack_1e = (undefined1)sVar2;
      if (0x7ffe < (ushort)param_1) goto LAB_00557491;
      uVar6 = (ushort)param_1 | uVar11;
      *(undefined2 *)piVar4 = uStack_26;
      *(uint *)((int)piVar4 + 2) = CONCAT22(uStack_22,local_24);
      *(uint *)((int)piVar4 + 6) = CONCAT13(bStack_1d,CONCAT12(uStack_1e,local_20));
    }
    *(ushort *)((int)piVar4 + 10) = uVar6;
  }
  else {
LAB_00557491:
    piVar4[1] = 0;
    *piVar4 = 0;
    piVar4[2] = (-(uint)(uVar11 != 0) & 0x80000000) + 0x7fff8000;
  }
  return;
}

