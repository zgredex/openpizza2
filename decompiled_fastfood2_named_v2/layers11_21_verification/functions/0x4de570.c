// rea decompile_all
// name: FUN_004de570
// address: 0x4de570
// body: available
// range: 0x4de570-0x4de5f5 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


float10 __thiscall FUN_004de570(int param_1,int param_2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  float local_4;
  
  local_4 = 0.0;
  if (param_2 != 0) {
    fVar5 = FUN_0047a7b0(param_2);
    return fVar5;
  }
  uVar1 = *(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 10);
  uVar2 = (uint)uVar1;
  if (100 < uVar1) {
    uVar2 = 100;
  }
  iVar4 = 0;
  if (uVar2 == 0) {
    return (float10)0.0;
  }
  do {
    iVar3 = 0;
    do {
      fVar5 = FUN_004de4f0(param_1,iVar3,iVar4,0);
      if ((float10)local_4 < fVar5) {
        local_4 = (float)fVar5;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 7);
    iVar4 = iVar4 + 1;
  } while (iVar4 < (int)uVar2);
  return (float10)local_4;
}

