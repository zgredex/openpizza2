// rea decompile_all
// name: Map_ComputeBlitRect
// address: 0x4ed5a0
// body: available
// range: 0x4ed5a0-0x4ed77d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall Map_ComputeBlitRect(void *this,int param_1,int param_2,int *param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  int local_4;
  
                    /* Computes a clipped blit rectangle for a map object. */
  local_18 = *(int *)((int)this + 0x1c);
  iVar7 = *(int *)((int)this + 0x28);
  local_c = -1 - local_18;
  local_1c = local_18 + 1;
  local_14 = local_18 + -1;
  local_34 = *(int *)((int)this + 0x24);
  local_4 = 1 - local_18;
  local_20 = 1;
  local_8 = -local_18;
  local_10 = 0xffffffff;
  if (param_3 != (int *)0x0) {
    local_34 = 0;
    iVar7 = 0;
  }
  iVar8 = *(int *)((int)this + 0x20) * local_18;
  iVar3 = *(int *)((int)this + 0x10) >> 1;
  iVar4 = (((iVar7 - *(int *)((int)this + 0x10)) + param_2) / iVar3) * local_18;
  if ((iVar4 < iVar8) ||
     (iVar4 = (iVar8 - local_18) + 1,
     iVar4 = iVar4 + (((iVar7 - *(int *)(*(int *)((int)this + 0x4c) + 4 + iVar4 * 0xc)) -
                      *(int *)((int)this + 0x10)) + param_2) / iVar3, iVar4 <= iVar8)) {
    iVar3 = (local_34 - *(int *)(*(int *)((int)this + 0x4c) + iVar4 * 0xc)) + param_1;
    if (-1 < iVar3) {
      iVar4 = iVar4 - (iVar3 / *(int *)((int)this + 0xc)) * local_14;
      local_30 = FUN_004ed480(this,local_34,iVar7,param_1,param_2,iVar4);
      param_3 = &local_20;
      local_2c = 8;
      local_28 = iVar4;
      do {
        iVar3 = *param_3;
        iVar1 = FUN_004ed480(this,local_34,iVar7,param_1,param_2,iVar4 + iVar3);
        if (iVar1 < local_30) {
          local_30 = iVar1;
          local_28 = iVar4 + iVar3;
        }
        param_3 = param_3 + 1;
        local_2c = local_2c + -1;
      } while (local_2c != 0);
      if (((-1 < local_28) && (local_28 != -1)) && (local_28 <= iVar8)) {
        if (param_4 == 0) {
          return *(int *)((int)this + 0x4c) + local_28 * 0xc;
        }
        iVar7 = *(int *)((int)this + 0x1c);
        uVar5 = local_28 % iVar7;
        uVar2 = local_28 / iVar7;
        uVar6 = uVar5 & 0x80000001;
        bVar9 = uVar6 == 0;
        if ((int)uVar6 < 0) {
          bVar9 = (uVar6 - 1 | 0xfffffffe) == 0xffffffff;
        }
        if (!bVar9) {
          uVar5 = uVar5 - 1;
        }
        uVar6 = uVar2 & 0x80000001;
        bVar9 = uVar6 == 0;
        if ((int)uVar6 < 0) {
          bVar9 = (uVar6 - 1 | 0xfffffffe) == 0xffffffff;
        }
        if (!bVar9) {
          uVar2 = uVar2 - 1;
        }
        return *(int *)((int)this + 0x4c) + (iVar7 * uVar2 + uVar5) * 0xc;
      }
    }
  }
  return 0;
}

