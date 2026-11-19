// rea decompile_all
// name: FUN_004f3b70
// address: 0x4f3b70
// body: available
// range: 0x4f3b70-0x4f3cdd inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_004f3b70(void *param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  iVar9 = 0;
  bVar1 = false;
  bVar2 = false;
  bVar3 = false;
  if (*(int *)((int)param_1 + 0xc) != 0x10) {
    NoOp_Stub();
  }
  if (0 < *(int *)((int)param_1 + 0x20)) {
    do {
      iVar8 = 0;
      if (0 < *(int *)((int)param_1 + 0x1c)) {
        do {
          iVar5 = Grid_GetCell(param_1,iVar8,iVar9);
          if (*(int *)(iVar5 + 8) != 0) {
            if ((!bVar1) &&
               (iVar6 = IsMenuId351Or355(*(int *)(*(int *)(iVar5 + 8) + 4)), iVar6 != 0)) {
              local_10 = iVar8 + -5;
              local_c = iVar9 + -5;
              bVar1 = true;
            }
            if (!bVar2) {
              iVar5 = IsMenuId34EOr350(*(int *)(*(int *)(iVar5 + 8) + 4));
              if (iVar5 != 0) {
                bVar2 = true;
                iVar5 = iVar8;
                do {
                  iVar7 = iVar5;
                  iVar5 = Grid_GetCell(param_1,iVar7,iVar9);
                  iVar6 = IsMenuId34EOr350(*(int *)(*(int *)(iVar5 + 8) + 4));
                  iVar5 = iVar7 + 1;
                } while (iVar6 != 0);
                local_8 = iVar7 + 5;
              }
              iVar5 = Grid_GetCell(param_1,iVar8,iVar9);
            }
            if (((!bVar3) &&
                (bVar4 = IsMenuId352(*(int *)(*(int *)(iVar5 + 8) + 4)),
                CONCAT31(extraout_var,bVar4) != 0)) &&
               (bVar4 = IsMenuId352(*(int *)(*(int *)(*(int *)((int)param_1 + 0x4c) + 8 +
                                                     (**(int **)(iVar5 + 8) +
                                                     *(int *)((int)param_1 + 0x1c)) * 0xc) + 4)),
               CONCAT31(extraout_var_00,bVar4) == 0)) {
              local_4 = iVar9 + 5;
              bVar3 = true;
            }
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < *(int *)((int)param_1 + 0x1c));
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < *(int *)((int)param_1 + 0x20));
  }
  *(int *)((int)param_1 + 0x100) = local_10;
  *(int *)((int)param_1 + 0x104) = local_c;
  *(int *)((int)param_1 + 0x108) = local_8;
  *(int *)((int)param_1 + 0x10c) = local_4;
  return;
}

