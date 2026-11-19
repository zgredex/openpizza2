// rea decompile_all
// name: Person_SetAtWork
// address: 0x50e2a0
// body: available
// range: 0x50e2a0-0x50e304 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall Person_SetAtWork(int param_1,uint param_2,int param_3,char param_4)

{
  void *this;
  int iVar1;
  longlong lVar2;
  
                    /* Sets a person's at-work flag and adjusts household motivation for workers. */
  if (*(char *)(param_1 + 0x80) != param_4) {
    *(char *)(param_1 + 0x80) = param_4;
    if ((param_3 != 0) &&
       (((iVar1 = *(int *)(param_1 + 0x30), iVar1 == 0x11 || (iVar1 == 0x13)) || (iVar1 == 0x14))))
    {
      lVar2 = FUN_00480760(param_3,param_2,iVar1);
      this = (void *)FUN_004017f0((void *)(DAT_0057c670 + 0x20),*(int *)(param_1 + 0x50),(int *)0x0)
      ;
      if (this != (void *)0x0) {
        iVar1 = *(int *)((int)this + 0xc) - (int)lVar2;
        if (iVar1 < 0) {
          iVar1 = 0;
        }
        FUN_004d4120(this,iVar1);
      }
    }
  }
  return;
}

