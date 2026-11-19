// rea decompile_all
// name: Map_BuildOccupiedCellList
// address: 0x4d5940
// body: available
// range: 0x4d5940-0x4d59b0 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall Map_BuildOccupiedCellList(void *param_1)

{
  undefined4 *this;
  int iVar1;
  int iVar2;
  
                    /* Rebuilds the map's occupied-cell map from type-0x20 buildings. */
  this = FUN_004d59c0(param_1,0x20,0,'\0');
  iVar2 = 0;
  if (0 < (int)this[5]) {
    do {
      iVar1 = FUN_004017f0(this,iVar2,(int *)0x0);
      iVar1 = FUN_004f0cc0(*(void **)((int)param_1 + 0xfa8),1,*(int *)(iVar1 + 0x54));
      if ((iVar1 != 0) && (*(char *)(iVar1 + 6) == '\x02')) {
        FUN_004014b0((void *)(*(int *)((int)param_1 + 0xfa8) + 0x11c),iVar1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)this[5]);
  }
  FUN_00401440((int)this);
  if (this != (undefined4 *)0x0) {
    (**(code **)*this)(1);
  }
  return;
}

