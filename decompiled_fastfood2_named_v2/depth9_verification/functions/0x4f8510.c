// rea decompile_all
// name: AI_FindBranchPlotNearOwn
// address: 0x4f8510
// body: available
// range: 0x4f8510-0x4f8707 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall AI_FindBranchPlotNearOwn(void *this,int param_1,void *param_2)

{
  int iVar1;
  undefined4 *this_00;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  longlong lVar9;
  int *piVar10;
  int local_58;
  int local_54;
  uint local_48;
  int local_44;
  int local_40;
  int local_38;
  int local_34;
  int local_20;
  int local_1c;
  int local_18 [5];
  
                    /* Finds an empty plot near the company's own buildings for a branch. */
  local_34 = 0;
  iVar1 = *(int *)((int)this + param_1 * 0x168 + 0x70);
  this_00 = FUN_004d59c0(param_2,0,0,'\x01');
  local_44 = 0;
  local_38 = 0;
  iVar8 = (int)this_00[5] >> 3;
  local_1c = iVar8;
  do {
    local_40 = 0;
    if (0 < iVar8) {
      local_48 = 8;
      do {
        piVar10 = (int *)0x0;
        uVar2 = FUN_004034d0(local_40 * 8,local_48);
        iVar3 = FUN_004017f0(this_00,uVar2,piVar10);
        if (iVar3 != 0) {
          local_58 = 0;
          local_54 = 0;
          if (0 < *(int *)(iVar1 + 0x15c)) {
            do {
              iVar4 = FUN_004017f0((void *)(iVar1 + 0x148),local_54,(int *)0x0);
              iVar8 = *(int *)(iVar4 + 0x16f0);
              iVar5 = FUN_004d2320(iVar3);
              iVar6 = FUN_004d2320(iVar8);
              iVar7 = FUN_004d2360(iVar3);
              iVar8 = FUN_004d2360(iVar8);
              if (SQRT((double)((iVar8 - iVar7) * (iVar8 - iVar7) +
                               (iVar6 - iVar5) * (iVar6 - iVar5))) < 400.0) {
                FUN_004f7b90(iVar4,&local_20,local_18,4);
                lVar9 = __ftol();
                local_58 = local_58 + 1000 + (int)lVar9;
              }
              local_54 = local_54 + 1;
            } while (local_54 < *(int *)(iVar1 + 0x15c));
            iVar8 = local_1c;
          }
          if (local_44 < local_58) {
            local_44 = local_58;
            local_34 = iVar3;
          }
        }
        local_40 = local_40 + 1;
        local_48 = local_48 + 8;
      } while (local_40 < iVar8);
    }
  } while ((local_58 < 1) && (local_38 = local_38 + 1, local_38 < 10));
  if (this_00 != (undefined4 *)0x0) {
    (**(code **)*this_00)(1);
  }
  if (local_44 < 1) {
    return 0;
  }
  return local_34;
}

