// rea decompile_all
// name: FUN_0052d1c0
// address: 0x52d1c0
// body: available
// range: 0x52d1c0-0x52d358 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0052d1c0(void *param_1,int param_2,int param_3,int param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  int iVar7;
  int iVar8;
  undefined2 *puVar9;
  int iVar10;
  int iVar11;
  longlong lVar12;
  int local_1c;
  
  uVar6 = Color_RGBTo16FromDword(param_1,param_5);
  if (0 < param_4) {
    iVar1 = *(int *)((int)param_1 + 8);
    iVar2 = *(int *)((int)param_1 + 4);
    iVar3 = *(int *)((int)param_1 + 0x10);
    iVar4 = *(int *)((int)param_1 + 0xc);
    iVar11 = 0;
    iVar5 = *(int *)((int)param_1 + 0x20);
    if (param_3 < iVar4) {
      iVar11 = iVar4 - param_3;
    }
    if (iVar3 < param_3) {
      iVar11 = param_3 - iVar3;
    }
    if (iVar11 < param_4) {
      param_5 = iVar11 + param_3;
      param_3 = param_3 - iVar11;
      iVar10 = param_5 * iVar5 * 2;
      local_1c = param_3 * iVar5 * 2;
      do {
        if ((iVar3 < (int)param_5) && (param_3 < iVar4)) {
          return;
        }
        lVar12 = __ftol();
        iVar7 = (int)lVar12;
        if (((int)param_5 < iVar3) && (iVar4 <= (int)param_5)) {
          iVar8 = param_2 - iVar7;
          if (iVar8 < param_2 + iVar7) {
            puVar9 = (undefined2 *)(*(int *)((int)param_1 + 0x28) + iVar10 + iVar8 * 2);
            do {
              if ((iVar2 <= iVar8) && (iVar8 < iVar1)) {
                *puVar9 = uVar6;
              }
              iVar8 = iVar8 + 1;
              puVar9 = puVar9 + 1;
            } while (iVar8 < param_2 + iVar7);
          }
        }
        if ((param_3 < iVar3) && (iVar4 <= param_3)) {
          iVar8 = param_2 - iVar7;
          if (iVar8 < iVar7 + param_2) {
            puVar9 = (undefined2 *)(*(int *)((int)param_1 + 0x28) + local_1c + iVar8 * 2);
            do {
              if ((iVar2 <= iVar8) && (iVar8 < iVar1)) {
                *puVar9 = uVar6;
              }
              iVar8 = iVar8 + 1;
              puVar9 = puVar9 + 1;
            } while (iVar8 < iVar7 + param_2);
          }
        }
        iVar10 = iVar10 + iVar5 * 2;
        iVar11 = iVar11 + 1;
        local_1c = local_1c + iVar5 * -2;
        param_5 = param_5 + 1;
        param_3 = param_3 + -1;
      } while (iVar11 < param_4);
    }
  }
  return;
}

