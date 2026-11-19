// rea decompile_all
// name: Company_AllocateMenuSales
// address: 0x4fe870
// body: available
// range: 0x4fe870-0x4fea68 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Company_AllocateMenuSales(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  longlong lVar10;
  longlong lVar11;
  int local_334;
  int local_324;
  int local_320 [4];
  int local_310 [196];
  
                    /* Distributes expected company sales across menu recipes. */
  iVar9 = *(int *)((int)this + param_1 * 0x168 + 0x70);
  iVar1 = *(int *)((int)this + param_1 * 0x168 + 0x40);
  FUN_004e3780(iVar9);
  lVar10 = __ftol();
  lVar11 = __ftol();
  iVar7 = ((int)lVar10 >> 5) + (int)lVar11;
  iVar2 = *(int *)(iVar9 + 0x140);
  iVar8 = 0;
  local_334 = 0;
  if (0 < iVar2) {
    piVar6 = local_320 + 4;
    iVar5 = iVar7;
    do {
      pvVar3 = (void *)FUN_004017f0((void *)(iVar9 + 300),iVar8,(int *)0x0);
      iVar4 = *(int *)((int)pvVar3 + 8);
      piVar6[-4] = (int)pvVar3;
      if (iVar4 == 1) {
        local_324 = *(int *)(iVar9 + 0x15c);
        iVar5 = 10000;
LAB_004fe920:
        *(int *)((int)pvVar3 + 0x20) = iVar5;
        iVar4 = GamePlan_ComputeAverageEffect(pvVar3,iVar1);
        piVar6[-3] = iVar4;
        if (iVar4 < 0x29) {
          piVar6[-2] = 0;
          GamePlan_SetActiveEffect((void *)piVar6[-4],0,iVar1);
          *piVar6 = 1;
        }
        else {
          *piVar6 = 0;
          piVar6[-2] = piVar6[-3] * local_324;
          piVar6[-1] = iVar5;
        }
        local_334 = local_334 + piVar6[-2];
      }
      else {
        if (iVar4 == 2) {
          local_324 = 1;
          iVar5 = 5000;
          goto LAB_004fe920;
        }
        if (iVar4 != 3) goto LAB_004fe920;
        *piVar6 = 1;
      }
      iVar8 = iVar8 + 1;
      piVar6 = piVar6 + 5;
    } while (iVar8 < iVar2);
  }
  while( true ) {
    iVar8 = -1;
    iVar5 = 0;
    iVar9 = 9999;
    if (iVar2 < 1) {
      return;
    }
    piVar6 = local_320 + 2;
    do {
      if ((piVar6[2] == 0) && ((iVar8 == -1 || (iVar9 < *piVar6)))) {
        iVar9 = *piVar6;
        iVar8 = iVar5;
      }
      iVar5 = iVar5 + 1;
      piVar6 = piVar6 + 5;
    } while (iVar5 < iVar2);
    if (iVar8 == -1) break;
    local_320[iVar8 * 5 + 4] = 1;
    if (*(int *)(local_320[iVar8 * 5] + 8) == 1) {
      iVar9 = local_320[iVar8 * 5 + 1];
      piVar6 = local_320 + 4;
      iVar5 = iVar2;
      do {
        if ((*piVar6 == 0) && (piVar6[-3] <= iVar9)) {
          *piVar6 = 1;
          local_334 = local_334 - piVar6[-2];
        }
        piVar6 = piVar6 + 5;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    if (local_334 < 1) {
      return;
    }
    iVar9 = local_320[iVar8 * 5 + 2];
    iVar5 = (iVar9 * iVar7) / local_334;
    if (local_320[iVar8 * 5 + 3] < iVar5) {
      iVar5 = local_320[iVar8 * 5 + 3];
    }
    pvVar3 = (void *)local_320[iVar8 * 5];
    *(int *)((int)pvVar3 + 0x20) = iVar5;
    GamePlan_SetActiveEffect(pvVar3,(uint)(0 < iVar5),iVar1);
    iVar7 = iVar7 - iVar5;
    local_334 = local_334 - iVar9;
    if (iVar7 < 1) {
      return;
    }
  }
  return;
}

