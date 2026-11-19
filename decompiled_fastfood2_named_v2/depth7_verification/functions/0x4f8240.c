// rea decompile_all
// name: FUN_004f8240
// address: 0x4f8240
// body: available
// range: 0x4f8240-0x4f8502 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_004f8240(void *this,int param_1,void *param_2,int param_3,int *param_4)

{
  int iVar1;
  double dVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  longlong lVar12;
  int *piVar13;
  int local_34;
  undefined4 *local_30;
  uint local_28;
  int local_20;
  int local_1c;
  uint local_18;
  int local_14;
  
  *param_4 = 0;
  local_14 = 0;
  if (param_3 == 0) {
    local_30 = FUN_004d5b90((int)param_2);
    iVar3 = local_30[5];
  }
  else {
    local_30 = FUN_004d59c0(param_2,-1,0,'\x01');
    iVar3 = (int)local_30[5] >> 4;
  }
  iVar1 = *(int *)((int)param_2 + 0xc1c);
  local_18 = 0;
  if (0 < iVar3) {
    local_28 = 0x10;
    do {
      piVar13 = (int *)0x0;
      if (param_3 == 0) {
        uVar4 = local_18;
      }
      else {
        uVar4 = FUN_004034d0(local_18 << 4,local_28);
      }
      iVar5 = FUN_004017f0(local_30,uVar4,piVar13);
      if (iVar5 != 0) {
        iVar11 = param_1 * 0x168;
        if (*(int *)(iVar11 + 0x118 + (int)this) != 0) {
          iVar6 = FUN_004d7e90(param_2,iVar5);
          iVar10 = 0;
          piVar13 = (int *)(iVar1 * 0x10 + iVar11 + 0x138 + (int)this);
          do {
            if (*piVar13 == iVar6) {
              if (iVar10 < 4) goto LAB_004f84b1;
              break;
            }
            iVar10 = iVar10 + 1;
            piVar13 = piVar13 + 1;
          } while (iVar10 < 4);
        }
        local_34 = FUN_004d8320(param_2,iVar5,0x8c);
        local_1c = 0;
        do {
          iVar6 = FUN_00488be0(DAT_0057c670,local_1c);
          if ((iVar6 != 0) && (local_20 = 0, 0 < *(int *)(iVar6 + 0x15c))) {
            do {
              iVar10 = FUN_004017f0((void *)(iVar6 + 0x148),local_20,(int *)0x0);
              if (iVar10 != 0) {
                iVar9 = *(int *)(iVar10 + 0x16f0);
                iVar7 = FUN_004d2320(iVar5);
                iVar8 = FUN_004d2320(iVar9);
                iVar8 = iVar8 - iVar7 >> 1;
                iVar7 = FUN_004d2360(iVar5);
                iVar9 = FUN_004d2360(iVar9);
                dVar2 = SQRT((double)((iVar9 - iVar7) * (iVar9 - iVar7) + iVar8 * iVar8));
                if (dVar2 < 400.0) {
                  if (*(int *)(iVar10 + 0x30) == *(int *)(iVar11 + 0x40 + (int)this)) {
                    lVar12 = __ftol();
                    local_34 = (int)lVar12;
                  }
                  else {
                    iVar10 = *(int *)(*(int *)(iVar11 + 0x70 + (int)this) + 0x15c);
                    if (iVar10 < 2) {
                      local_34 = local_34 >> 3;
                    }
                    else if (dVar2 < (double)((0x14 - iVar10) * 0x14)) {
                      local_34 = local_34 >> 3;
                    }
                  }
                }
              }
              local_20 = local_20 + 1;
            } while (local_20 < *(int *)(iVar6 + 0x15c));
          }
          local_1c = local_1c + 1;
        } while (local_1c < 6);
        if (*param_4 < local_34) {
          *param_4 = local_34;
          local_14 = iVar5;
        }
      }
LAB_004f84b1:
      local_18 = local_18 + 1;
      local_28 = local_28 + 0x10;
    } while ((int)local_18 < iVar3);
  }
  if (local_30 != (undefined4 *)0x0) {
    (**(code **)*local_30)(1);
  }
  if (*param_4 < 1) {
    *param_4 = 0;
    return 0;
  }
  return local_14;
}

