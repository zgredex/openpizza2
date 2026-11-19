// rea decompile_all
// name: Economy_GetModifier
// address: 0x4e25b0
// body: available
// range: 0x4e25b0-0x4e2741 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined * __thiscall Economy_GetModifier(void *this,int param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  
                    /* Type-0x17 economy modifier from a table, adjusted by player stats. */
  puVar1 = (undefined *)0x0;
  if (param_1 == 0x17) {
    puVar1 = *(undefined **)(&DAT_0056d0d4 + (param_2 + *(int *)((int)this + 100) * 3) * 4);
    if (param_2 == 1) {
      iVar3 = *(int *)(*(int *)(DAT_0057c670 + 0x224) + 0xa8);
      iVar2 = *(int *)(iVar3 + 0x168);
      if (0 < iVar2) {
        do {
          puVar1 = (undefined *)(((int)puVar1 * 0xf) / 10);
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      iVar3 = *(int *)(iVar3 + 0x24c);
      if (0 < iVar3) {
        do {
          puVar1 = (undefined *)(((int)puVar1 * 9) / 10);
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
        return puVar1;
      }
    }
    else if (param_2 == 2) {
      iVar3 = *(int *)(*(int *)(DAT_0057c670 + 0x224) + 0xa8);
      iVar2 = *(int *)(iVar3 + 0x164);
      if (0 < iVar2) {
        do {
          puVar1 = (undefined *)(((int)puVar1 * 0xf) / 10);
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      iVar3 = *(int *)(iVar3 + 0x248);
      if (0 < iVar3) {
        do {
          puVar1 = (undefined *)(((int)puVar1 * 9) / 10);
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
    }
  }
  else if (param_1 == 0x1d) {
    puVar1 = *(undefined **)(&DAT_0056d0b0 + (param_2 + *(int *)((int)this + 0x6c) * 3) * 4);
    if (param_2 == 1) {
      iVar3 = *(int *)(*(int *)(DAT_0057c670 + 0x224) + 0xa8);
      iVar2 = *(int *)(iVar3 + 0xa8);
      if (0 < iVar2) {
        do {
          puVar1 = (undefined *)(((int)puVar1 * 0xf) / 10);
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      iVar3 = *(int *)(iVar3 + 0x18c);
      if (0 < iVar3) {
        do {
          puVar1 = (undefined *)(((int)puVar1 * 9) / 10);
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
        return puVar1;
      }
    }
  }
  else if (param_1 == 0x1e) {
    return (&PTR_s_can_t_perform_action_0056d08c)[param_2 + *(int *)((int)this + 0x68) * 3];
  }
  return puVar1;
}

