// rea decompile_all
// name: Map_UnlinkCells
// address: 0x4f08e0
// body: available
// range: 0x4f08e0-0x4f0956 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void Map_UnlinkCells(undefined4 param_1,int param_2,int param_3)

{
  ushort uVar1;
  ushort uVar2;
  bool bVar3;
  short *psVar4;
  int iVar5;
  
                    /* Removes the neighbour links between two grid cells. */
  uVar1 = *(ushort *)(param_2 + 4);
  uVar2 = *(ushort *)(param_3 + 4);
  psVar4 = (short *)(param_3 + 0x14);
  bVar3 = true;
  iVar5 = 8;
  do {
    if ((int)*(short *)((param_2 - param_3) + (int)psVar4) == (uint)uVar2) {
      *(undefined2 *)((param_2 - param_3) + (int)psVar4) = 0xffff;
      bVar3 = false;
    }
    if ((int)*psVar4 == (uint)uVar1) {
      *psVar4 = -1;
      bVar3 = false;
    }
    psVar4 = psVar4 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  if (bVar3) {
    FUN_00403510();
  }
  FUN_004edbc0();
  return;
}

