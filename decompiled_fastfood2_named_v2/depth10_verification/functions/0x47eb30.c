// rea decompile_all
// name: Branch_PayConstructionOrder
// address: 0x47eb30
// body: available
// range: 0x47eb30-0x47eb9d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Branch_PayConstructionOrder(void *this,int param_1)

{
  int *piVar1;
  void *pvVar2;
  float10 fVar3;
  
                    /* Charges the market price of a construction order and refreshes its queue. */
  piVar1 = (int *)FUN_004017f0((void *)((int)this + 0x1998),param_1,(int *)0x0);
  if ((piVar1 != (int *)0x0) && (piVar1[7] != 0)) {
    pvVar2 = (void *)FUN_00488be0(DAT_0057c670,*(int *)((int)this + 0x30));
    fVar3 = FUN_0048c060((int)DAT_0057c670,piVar1,pvVar2);
    if ((float10)0.0 < fVar3) {
      FUN_00477e40(this,0xc,(float)fVar3,'\0',-1);
    }
    FUN_0047ea30(this);
  }
  return;
}

