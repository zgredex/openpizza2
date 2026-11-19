// rea decompile_all
// name: Stats_SumPlayerGrid
// address: 0x47a430
// body: available
// range: 0x47a430-0x47a498 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall Stats_SumPlayerGrid(void *this,int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  
  iVar2 = 0;
  uVar1 = *(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 10);
  uVar6 = (uint)uVar1;
  if (100 < uVar1) {
    uVar6 = 100;
  }
  iVar7 = 0;
  if (uVar6 != 0) {
    piVar5 = (int *)((int)this + 0x554);
    do {
      if ((iVar7 == param_2) || (param_2 == -1)) {
        iVar3 = 0;
        piVar4 = piVar5;
        do {
          if ((param_1 == iVar3) || (param_1 == -1)) {
            iVar2 = iVar2 + *piVar4;
          }
          iVar3 = iVar3 + 1;
          piVar4 = piVar4 + 100;
        } while (iVar3 < 8);
      }
      iVar7 = iVar7 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar7 < (int)uVar6);
  }
  return iVar2;
}

