// rea decompile_all
// name: FUN_0047f670
// address: 0x47f670
// body: available
// range: 0x47f670-0x47f779 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __fastcall FUN_0047f670(void *param_1)

{
  void *this;
  int iVar1;
  void *pvVar2;
  void *this_00;
  int iVar3;
  
  iVar3 = 0;
  FUN_00401320(*(int *)(DAT_0057c670 + 0x240));
  this = *(void **)((int)param_1 + 0x16f0);
  if (this == (void *)0x0) {
    FUN_00401340(*(int *)(DAT_0057c670 + 0x240));
    return 0;
  }
  iVar1 = *(int *)((int)this + 0x8c);
  while (iVar1 = iVar1 + -1, -1 < iVar1) {
    pvVar2 = (void *)FUN_004d2a60(this,iVar1);
    if ((0x2a < *(int *)((int)pvVar2 + 0x30)) && (*(int *)((int)pvVar2 + 0x30) < 0x2d)) {
      this_00 = (void *)FUN_004017f0((void *)(DAT_0057c670 + 0x3c),*(int *)((int)pvVar2 + 0x10c),
                                     (int *)0x0);
      if ((this_00 != (void *)0x0) &&
         ((*(int *)((int)this_00 + 0x74) != 0 &&
          (*(int *)((int)this_00 + 0xf4) == *(int *)((int)param_1 + 0x16f0))))) {
        iVar3 = FUN_0050e7a0((int)this_00);
        if (iVar3 == 0) {
          FUN_005090e0((int)this_00);
        }
        else {
          FUN_00507a80((int)this_00);
        }
        FUN_0050e890(this_00,6);
        FUN_0050e850(this_00,0xffffffff);
      }
      FUN_0047f5c0(param_1,pvVar2);
      iVar3 = 1;
    }
  }
  FUN_00401340(*(int *)(DAT_0057c670 + 0x240));
  if (iVar3 != 0) {
    *(undefined4 *)((int)param_1 + 0x1718) = 0;
  }
  return iVar3;
}

