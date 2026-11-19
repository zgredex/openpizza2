// rea decompile_all
// name: CityView_ReserveCarCell
// address: 0x4f5d40
// body: available
// range: 0x4f5d40-0x4f5dac inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall CityView_ReserveCarCell(void *this,int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
                    /* Marks a car's two street cells occupied and records their coordinates. */
  iVar1 = CityView_IsCarSpawnCellFree(this,param_1);
  if (iVar1 != 0) {
    iVar1 = *(int *)((int)this + 0x4c) + *(int *)(param_1 + 8) * 0xc;
    iVar2 = FUN_004f5c80(this,param_1);
    uVar3 = FUN_004f57f0(param_1,iVar2);
    iVar2 = FUN_004f3e10(this,iVar1,uVar3);
    *(undefined4 *)(*(int *)(iVar1 + 8) + 0x38) = 1;
    *(undefined4 *)(*(int *)(iVar2 + 8) + 0x38) = 1;
    *(undefined4 *)(param_2 + 0x44) = **(undefined4 **)(iVar1 + 8);
    *(undefined4 *)(param_2 + 0x48) = **(undefined4 **)(iVar2 + 8);
    *(undefined4 *)(param_2 + 0x4c) = 0xffffffff;
    *(undefined4 *)(param_2 + 0x50) = 0xffffffff;
  }
  return;
}

