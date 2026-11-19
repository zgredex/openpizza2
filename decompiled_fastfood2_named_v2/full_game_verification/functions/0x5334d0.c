// rea decompile_all
// name: List_ReleaseSharedBuffers
// address: 0x5334d0
// body: available
// range: 0x5334d0-0x53353b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall List_ReleaseSharedBuffers(int param_1)

{
  LPVOID pvVar1;
  bool bVar2;
  int iVar3;
  
  bVar2 = false;
  if (*(char *)(param_1 + 0x34) != '\0') {
    CS_Enter(0x584248);
    if (*(char *)(param_1 + 0x35) != '\0') {
      iVar3 = 0;
      if (0 < *(int *)(param_1 + 0x68)) {
        do {
          if ((!bVar2) &&
             (pvVar1 = *(LPVOID *)(*(int *)(param_1 + 0x80) + iVar3 * 4), pvVar1 != (LPVOID)0x0)) {
            bVar2 = true;
            Mem_Free(pvVar1);
          }
          iVar3 = iVar3 + 1;
          *(undefined4 *)(*(int *)(param_1 + 0x80) + -4 + iVar3 * 4) = 0;
        } while (iVar3 < *(int *)(param_1 + 0x68));
      }
      *(undefined1 *)(param_1 + 0x35) = 0;
    }
    CS_Leave(0x584248);
  }
  return;
}

