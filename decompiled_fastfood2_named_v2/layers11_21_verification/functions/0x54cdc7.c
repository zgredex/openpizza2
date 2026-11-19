// rea decompile_all
// name: CRT_Filebuf_Destroy
// address: 0x54cdc7
// body: available
// range: 0x54cdc7-0x54ce1d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void CRT_Filebuf_Destroy(void)

{
  int *extraout_ECX;
  int unaff_EBP;
  
                    /* Destroys the CRT filebuf, closing or syncing its file. */
  FUN_0054fe6c();
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = (int)&PTR_CRT_Filebuf_Delete_0055cc54;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (extraout_ECX[0xc] < 0) {
    FUN_0054d35c((LPCRITICAL_SECTION)(extraout_ECX + 0xd));
  }
  if (extraout_ECX[0x14] == 0) {
    FUN_0054cfd6((int)extraout_ECX);
  }
  else {
    CRT_Filebuf_Close(extraout_ECX);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0054db21(extraout_ECX);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

