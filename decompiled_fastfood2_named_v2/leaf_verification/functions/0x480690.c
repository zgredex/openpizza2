// rea decompile_all
// name: FUN_00480690
// address: 0x480690
// body: available
// range: 0x480690-0x480736 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_00480690(int param_1)

{
  int iVar1;
  int *piVar2;
  void *this;
  int iVar3;
  int iVar4;
  float10 fVar5;
  
  CS_Enter(*(int *)(DAT_0057c670 + 0x240));
  iVar1 = *(int *)(param_1 + 0x1514);
  iVar4 = 0;
  if (0 < iVar1) {
    do {
      piVar2 = (int *)IDMap_Lookup((void *)(param_1 + 0x1500),iVar4,(int *)0x0);
      if (piVar2 != (int *)0x0) {
        iVar3 = *piVar2;
        this = (void *)FUN_004d3910(iVar3);
        if (*(int *)((int)this + 0x74) != 0) {
          iVar3 = Rating_AdjustA(iVar3);
          fVar5 = FUN_0047ac10(param_1);
          FUN_00509130(this,(double)(fVar5 * (float10)iVar3));
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar1);
  }
  CS_Leave(*(int *)(DAT_0057c670 + 0x240));
  return;
}

