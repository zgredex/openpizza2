// rea decompile_all
// name: CRT_Istream_SkipWhitespace
// address: 0x54d599
// body: available
// range: 0x54d599-0x54d611 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall CRT_Istream_SkipWhitespace(int *param_1)

{
  int iVar1;
  uint uVar2;
  void *extraout_ECX;
  void *this;
  void *extraout_ECX_00;
  
                    /* Skips whitespace in an old-iostream input stream. */
  iVar1 = *(int *)(*(int *)(*param_1 + 4) + 4 + (int)param_1);
  if (*(int *)(iVar1 + 0x30) < 0) {
    FUN_0054d35c((LPCRITICAL_SECTION)(iVar1 + 0x34));
  }
  uVar2 = FUN_0054d3be(*(int **)(*(int *)(*param_1 + 4) + 4 + (int)param_1));
  this = extraout_ECX;
  while (uVar2 != 0xffffffff) {
    uVar2 = FUN_0055062d(this,uVar2);
    if (uVar2 == 0) goto LAB_0054d5f7;
    uVar2 = FUN_0054d372(*(int **)(*(int *)(*param_1 + 4) + 4 + (int)param_1));
    this = extraout_ECX_00;
  }
  FUN_0054cd63((void *)(*(int *)(*param_1 + 4) + (int)param_1),
               *(uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) | 1);
LAB_0054d5f7:
  iVar1 = *(int *)(*(int *)(*param_1 + 4) + 4 + (int)param_1);
  if (*(int *)(iVar1 + 0x30) < 0) {
    FUN_0054d367((LPCRITICAL_SECTION)(iVar1 + 0x34));
  }
  return;
}

