// rea decompile_all
// name: FUN_00479960
// address: 0x479960
// body: available
// range: 0x479960-0x479a38 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00479960(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  short *psVar3;
  int iVar4;
  longlong lVar5;
  int local_c;
  float local_8;
  
  iVar2 = 0;
  local_8 = 0.0;
  local_c = 0;
  psVar3 = (short *)(param_1 + 0xc);
  do {
    iVar4 = 0;
    do {
      if ((((psVar3[-4] == 1) && (*psVar3 == 1)) && (psVar3[0x140] == 1)) && (psVar3[0x13c] == 1)) {
        iVar1 = FUN_00479750(iVar2,iVar4,param_1);
        local_c = local_c + 1;
        local_8 = (float)iVar1 + local_8;
      }
      iVar4 = iVar4 + 1;
      psVar3 = psVar3 + 4;
    } while (iVar4 < 0x50);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x50);
  if (local_c < 1) {
    *(undefined4 *)((int)this + 0x1860) = 0;
  }
  else {
    lVar5 = FUN_00403850(local_8 / (float)local_c);
    *(int *)((int)this + 0x1860) = (int)lVar5;
  }
  if (*(int *)((int)this + 0x1860) < 0) {
    *(undefined4 *)((int)this + 0x1860) = 0;
  }
  if (8 < *(int *)((int)this + 0x1860)) {
    *(undefined4 *)((int)this + 0x1860) = 8;
  }
  return;
}

