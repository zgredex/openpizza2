// rea decompile_all
// name: FUN_0047c730
// address: 0x47c730
// body: available
// range: 0x47c730-0x47c7aa inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_0047c730(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = FUN_00480050(param_1);
  if (0 < iVar2) {
    do {
      puVar3 = (undefined4 *)FUN_004017f0((void *)(param_1 + 0x19e0),0,(int *)0x0);
      iVar2 = puVar3[8];
      iVar1 = *(int *)(*(int *)(param_1 + 0x14e0) + 0x4c);
      *(undefined4 *)(*(int *)(iVar1 + 8 + iVar2 * 0xc) + 0x1c) = 0xffffffff;
      Map_SetTileFieldWithDefault(*(void **)(param_1 + 0x14e0),iVar1 + iVar2 * 0xc,-1,1);
      IDMap_RemoveByKey((void *)(param_1 + 0x19e0),(int)puVar3);
      if (puVar3 != (undefined4 *)0x0) {
        (**(code **)*puVar3)(1);
      }
      iVar2 = FUN_00480050(param_1);
    } while (0 < iVar2);
    *(undefined4 *)(param_1 + 0x1718) = 0;
  }
  return;
}

