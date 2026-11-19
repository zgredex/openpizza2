// rea decompile_all
// name: FUN_00502220
// address: 0x502220
// body: available
// range: 0x502220-0x5022c4 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined8 FUN_00502220(void)

{
  int iVar1;
  uint extraout_EDX;
  undefined4 uVar2;
  int iVar3;
  float10 fVar4;
  ulonglong uVar5;
  float local_4;
  
  local_4 = 0.0;
  iVar3 = 0;
  do {
    iVar1 = FUN_00488be0(DAT_0057c670,iVar3);
    if (iVar1 != 0) {
      fVar4 = Stats_SumFilteredFloats3(iVar1,-1,-1,-1);
      local_4 = (float)(fVar4 + (float10)local_4);
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 6);
  Stats_SumFilteredFloats3
            (*(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200),-1,-1,-1)
  ;
  uVar5 = (ulonglong)extraout_EDX << 0x20;
  if (0.0 < local_4) {
    uVar5 = __ftol();
    uVar2 = (undefined4)(uVar5 >> 0x20);
    iVar3 = (int)uVar5;
    if (0x3c < iVar3) {
      return CONCAT44(uVar2,3);
    }
    if (0x31 < iVar3) {
      return CONCAT44(uVar2,2);
    }
    if (0x27 < iVar3) {
      return CONCAT44(uVar2,1);
    }
  }
  return uVar5 & 0xffffffff00000000;
}

