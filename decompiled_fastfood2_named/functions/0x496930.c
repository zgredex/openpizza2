// rea decompile_all
// name: FUN_00496930
// address: 0x496930
// body: available
// range: 0x496930-0x49699f inclusive
// range: 0x4969b0-0x4969eb inclusive
// range: 0x496a80-0x496abb inclusive
// range: 0x496b60-0x496b9b inclusive
// range: 0x496ba0-0x496bdb inclusive
// non_contiguous: true
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00496930(void)

{
  int iVar1;
  
  if (DAT_0057c714 != (int *)0x0) {
    Mem_Free(DAT_0057c714);
    DAT_0057c714 = (int *)0x0;
  }
  if (0 < (int)DAT_0057c704) {
    DAT_0057c714 = operator_new((int)DAT_0057c704 << 2);
    DAT_0057c6fc = *(undefined4 *)(*(int *)(DAT_0057c670 + 0x9c) + 0x3c);
    switch(DAT_0057c708) {
    case 0:
      if (0 < (int)DAT_0057c704) {
        iVar1 = 0;
        if (0 < (int)DAT_0057c704) {
          do {
            DAT_0057c714[iVar1] = iVar1;
            iVar1 = iVar1 + 1;
          } while (iVar1 < (int)DAT_0057c704);
        }
        FUN_0054ea8f(DAT_0057c714,DAT_0057c704,4,&LAB_00496160);
      }
      return;
    case 1:
      if (0 < (int)DAT_0057c704) {
        iVar1 = 0;
        if (0 < (int)DAT_0057c704) {
          do {
            DAT_0057c714[iVar1] = iVar1;
            iVar1 = iVar1 + 1;
          } while (iVar1 < (int)DAT_0057c704);
        }
        FUN_0054ea8f(DAT_0057c714,DAT_0057c704,4,&LAB_00496200);
      }
      return;
    case 2:
      if (0 < (int)DAT_0057c704) {
        iVar1 = 0;
        if (0 < (int)DAT_0057c704) {
          do {
            DAT_0057c714[iVar1] = iVar1;
            iVar1 = iVar1 + 1;
          } while (iVar1 < (int)DAT_0057c704);
        }
        FUN_0054ea8f(DAT_0057c714,DAT_0057c704,4,&LAB_004969f0);
      }
      return;
    case 3:
      if (0 < (int)DAT_0057c704) {
        iVar1 = 0;
        if (0 < (int)DAT_0057c704) {
          do {
            DAT_0057c714[iVar1] = iVar1;
            iVar1 = iVar1 + 1;
          } while (iVar1 < (int)DAT_0057c704);
        }
        FUN_0054ea8f(DAT_0057c714,DAT_0057c704,4,&LAB_00496ac0);
      }
      return;
    }
  }
  return;
}

