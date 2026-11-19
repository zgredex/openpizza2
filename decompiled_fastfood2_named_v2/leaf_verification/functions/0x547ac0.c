// rea decompile_all
// name: FUN_00547ac0
// address: 0x547ac0
// body: available
// range: 0x547ac0-0x547b9f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


bool __thiscall FUN_00547ac0(void *this,int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  uVar2 = (uint)(param_2 * 10000) / 10000;
  if (10000 < uVar2) {
    uVar2 = 10000;
  }
  if (param_1 == 1) {
    bVar3 = uVar2 != DAT_00575094;
    DAT_00575094 = uVar2;
    *(uint *)((int)this + 0x1d0) = uVar2;
    uVar2 = FUN_00547a00(DAT_00575098);
    *(uint *)((int)this + 0x1d4) = uVar2;
    uVar2 = FUN_00547a00(DAT_0057509c);
    *(uint *)((int)this + 0x1d8) = uVar2;
    return bVar3;
  }
  if (param_1 == 2) {
    DAT_00575098 = uVar2;
    uVar1 = FUN_00547a00(uVar2);
    uVar2 = *(uint *)((int)this + 0x1d4);
    *(uint *)((int)this + 0x1d4) = uVar1;
    return uVar1 != uVar2;
  }
  if (param_1 == 3) {
    DAT_0057509c = uVar2;
    uVar1 = FUN_00547a00(uVar2);
    uVar2 = *(uint *)((int)this + 0x1d8);
    *(uint *)((int)this + 0x1d8) = uVar1;
    return uVar1 != uVar2;
  }
  return false;
}

