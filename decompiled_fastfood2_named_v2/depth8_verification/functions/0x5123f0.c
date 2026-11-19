// rea decompile_all
// name: FUN_005123f0
// address: 0x5123f0
// body: available
// range: 0x5123f0-0x51261c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Type propagation algorithm not settling */

void __thiscall FUN_005123f0(void *this,int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  longlong lVar9;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_70;
  int local_64 [25];
  
  piVar7 = local_64;
  for (iVar4 = 0x18; piVar7 = piVar7 + 1, iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar7 = 0;
  }
  iVar2 = *(int *)(param_1 + 0x14);
  iVar8 = *(int *)(DAT_0057c670 + 0xa8 + (uint)*(byte *)(param_1 + 4) * 4);
  local_78 = *(int *)(param_1 + 0x18);
  local_80 = 0;
  iVar4 = (uint)*(byte *)(param_1 + 0x10) + (uint)*(byte *)(param_1 + 6) * 8;
  iVar5 = (int)*(short *)(iVar8 + 8 + iVar4 * 2);
  local_7c = (int)*(short *)(iVar8 + 0x48 + iVar4 * 2);
  if (iVar5 <= local_7c) {
    local_7c = iVar5;
  }
  if (0 < local_7c) {
    local_84 = 0;
    if (local_78 < 0) {
      local_84 = -local_78;
    }
    if (599 < local_78) {
      local_84 = local_78 + -599;
    }
    if (local_84 < local_7c) {
      local_70 = local_84 + local_78;
      local_78 = local_78 - local_84;
      iVar8 = local_70 * 800 + param_2;
      iVar4 = local_78 * 800 + param_2;
      do {
        if ((599 < local_70) && (local_78 < 0)) break;
        __ftol();
        lVar9 = __ftol();
        iVar5 = (int)lVar9;
        if ((local_70 < 599) && (-1 < local_70)) {
          for (iVar6 = iVar2 - iVar5; iVar6 < iVar5 + iVar2; iVar6 = iVar6 + 1) {
            if ((((-1 < iVar6) && (iVar6 < 799)) && (bVar1 = *(byte *)(iVar8 + iVar6), bVar1 != 0))
               && (bVar1 != 0xff)) {
              local_80 = local_80 + 1;
              local_64[bVar1] = local_64[bVar1] + 1;
            }
          }
        }
        if ((local_78 < 599) && (-1 < local_78)) {
          for (iVar6 = iVar2 - iVar5; iVar6 < iVar2 + iVar5; iVar6 = iVar6 + 1) {
            if (((-1 < iVar6) && (iVar6 < 799)) &&
               ((bVar1 = *(byte *)(iVar4 + iVar6), bVar1 != 0 && (bVar1 != 0xff)))) {
              local_80 = local_80 + 1;
              local_64[bVar1] = local_64[bVar1] + 1;
            }
          }
        }
        local_84 = local_84 + 1;
        iVar8 = iVar8 + 800;
        local_70 = local_70 + 1;
        iVar4 = iVar4 + -800;
        local_78 = local_78 + -1;
      } while (local_84 < local_7c);
      if (0 < local_80) {
        piVar7 = local_64;
        piVar3 = (int *)((int)this + 0x1e0);
        iVar4 = 0x18;
        do {
          piVar7 = piVar7 + 1;
          *piVar3 = *piVar3 + *piVar7;
          piVar3 = piVar3 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
    }
  }
  return;
}

