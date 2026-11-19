// rea decompile_all
// name: FUN_005395a0
// address: 0x5395a0
// body: available
// range: 0x5395a0-0x539652 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_005395a0(void *this,int *param_1,uint param_2,int param_3)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 *puVar10;
  
  if (param_3 != 0) {
    param_2 = FUN_00539840(this,param_2);
  }
  iVar7 = *param_1;
  if (*param_1 < *(int *)((int)this + 4)) {
    iVar7 = *(int *)((int)this + 4);
  }
  iVar3 = *(int *)((int)this + 8);
  if (iVar7 < iVar3) {
    iVar9 = param_1[1];
    if (param_1[1] < *(int *)((int)this + 0xc)) {
      iVar9 = *(int *)((int)this + 0xc);
    }
    iVar1 = *(int *)((int)this + 0x10);
    if (iVar9 < iVar1) {
      iVar4 = param_1[2];
      if (iVar3 <= param_1[2]) {
        iVar4 = iVar3;
      }
      iVar3 = param_1[3];
      if (iVar1 <= param_1[3]) {
        iVar3 = iVar1;
      }
      uVar5 = iVar4 - iVar7;
      param_3 = iVar3 - iVar9;
      if (((0 < (int)uVar5) && (0 < param_3)) &&
         (puVar8 = (undefined4 *)
                   (*(int *)((int)this + 0x28) + (*(int *)((int)this + 0x20) * iVar9 + iVar7) * 2),
         0 < param_3)) {
        do {
          if (0 < (int)uVar5) {
            uVar2 = (undefined2)param_2;
            puVar10 = puVar8;
            for (uVar6 = uVar5 >> 1; uVar6 != 0; uVar6 = uVar6 - 1) {
              *puVar10 = CONCAT22(uVar2,uVar2);
              puVar10 = puVar10 + 1;
            }
            for (uVar6 = (uint)((uVar5 & 1) != 0); uVar6 != 0; uVar6 = uVar6 - 1) {
              *(undefined2 *)puVar10 = uVar2;
              puVar10 = (undefined4 *)((int)puVar10 + 2);
            }
          }
          puVar8 = (undefined4 *)((int)puVar8 + *(int *)((int)this + 0x20) * 2);
          param_3 = param_3 + -1;
        } while (param_3 != 0);
      }
    }
  }
  return;
}

