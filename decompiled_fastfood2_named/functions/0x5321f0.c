// rea decompile_all
// name: FUN_005321f0
// address: 0x5321f0
// body: available
// range: 0x5321f0-0x53229f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_005321f0(void *this,int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = *param_1;
  iVar5 = param_1[1];
  iVar2 = param_1[2];
  iVar3 = param_1[3];
  if (param_2 != 0) {
    iVar4 = iVar4 + *(int *)((int)this + 0x18);
    iVar2 = iVar2 + *(int *)((int)this + 0x18);
    iVar5 = iVar5 + *(int *)((int)this + 0x1c);
    iVar3 = iVar3 + *(int *)((int)this + 0x1c);
  }
  if (iVar4 < *(int *)((int)this + 8)) {
    iVar4 = *(int *)((int)this + 8);
  }
  if (iVar5 < *(int *)((int)this + 0xc)) {
    iVar5 = *(int *)((int)this + 0xc);
  }
  if (*(int *)((int)this + 0x10) < iVar2) {
    iVar2 = *(int *)((int)this + 0x10);
  }
  if (*(int *)((int)this + 0x14) < iVar3) {
    iVar3 = *(int *)((int)this + 0x14);
  }
  if ((0 < iVar2 - iVar4) && (0 < iVar3 - iVar5)) {
    iVar1 = *(int *)((int)this + 0x38);
    if (iVar1 == -999) {
      *(int *)((int)this + 0x38) = iVar4;
      *(int *)((int)this + 0x3c) = iVar5;
      *(int *)((int)this + 0x40) = iVar2;
      *(int *)((int)this + 0x44) = iVar3;
      return;
    }
    if (iVar1 < iVar4) {
      iVar4 = iVar1;
    }
    *(int *)((int)this + 0x38) = iVar4;
    iVar4 = *(int *)((int)this + 0x40);
    if (*(int *)((int)this + 0x40) <= iVar2) {
      iVar4 = iVar2;
    }
    *(int *)((int)this + 0x40) = iVar4;
    iVar4 = *(int *)((int)this + 0x3c);
    if (iVar5 <= *(int *)((int)this + 0x3c)) {
      iVar4 = iVar5;
    }
    *(int *)((int)this + 0x3c) = iVar4;
    iVar4 = *(int *)((int)this + 0x44);
    if (*(int *)((int)this + 0x44) <= iVar3) {
      iVar4 = iVar3;
    }
    *(int *)((int)this + 0x44) = iVar4;
  }
  return;
}

