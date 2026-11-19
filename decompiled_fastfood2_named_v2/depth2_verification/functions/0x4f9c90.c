// rea decompile_all
// name: FUN_004f9c90
// address: 0x4f9c90
// body: available
// range: 0x4f9c90-0x4f9d45 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_004f9c90(int param_1,int *param_2,int *param_3)

{
  void *this;
  void *pvVar1;
  int iVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  int local_4;
  
  *param_2 = -1;
  this = (void *)FUN_004e4140(param_1);
  if (this != (void *)0x0) {
    iVar4 = 0;
    local_4 = 0;
    if (0 < *(int *)(DAT_0057c670 + 0x88)) {
      do {
        pvVar1 = (void *)FUN_004017f0((void *)(DAT_0057c670 + 0x74),iVar4,(int *)0x0);
        if (pvVar1 == this) break;
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)(DAT_0057c670 + 0x88));
      local_4 = iVar4;
    }
    iVar5 = 0;
    iVar4 = FUN_004e4180((int)this);
    if (0 < iVar4) {
      iVar4 = 0;
      psVar3 = (short *)((int)this + 0x78);
      do {
        iVar2 = FUN_004e41a0(this,iVar5);
        if ((*psVar3 <= param_1) && (param_1 <= *(short *)((int)this + (iVar2 + iVar4) * 2 + 0x76)))
        {
          *param_2 = local_4;
          *param_3 = iVar5;
        }
        iVar5 = iVar5 + 1;
        psVar3 = psVar3 + 6;
        iVar4 = iVar4 + 6;
        iVar2 = FUN_004e4180((int)this);
      } while (iVar5 < iVar2);
    }
  }
  return;
}

