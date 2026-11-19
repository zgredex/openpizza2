// rea decompile_all
// name: FUN_00552269
// address: 0x552269
// body: available
// range: 0x552269-0x552330 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * FUN_00552269(void)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)0x0;
  FUN_0055395d(2);
  iVar3 = 0;
  if (0 < DAT_00586c00) {
    do {
      iVar1 = *(int *)(DAT_00585bec + iVar3 * 4);
      if (iVar1 == 0) {
        iVar3 = iVar3 * 4;
        pvVar2 = _malloc(0x38);
        *(void **)(iVar3 + DAT_00585bec) = pvVar2;
        if (*(int *)(iVar3 + DAT_00585bec) != 0) {
          InitializeCriticalSection((LPCRITICAL_SECTION)(*(int *)(iVar3 + DAT_00585bec) + 0x20));
          EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(iVar3 + DAT_00585bec) + 0x20));
          puVar4 = *(undefined4 **)(iVar3 + DAT_00585bec);
LAB_0055230d:
          if (puVar4 != (undefined4 *)0x0) {
            puVar4[4] = 0xffffffff;
            puVar4[1] = 0;
            puVar4[3] = 0;
            puVar4[2] = 0;
            *puVar4 = 0;
            puVar4[7] = 0;
          }
        }
        break;
      }
      if ((*(byte *)(iVar1 + 0xc) & 0x83) == 0) {
        CRT_LockFile2(iVar3,iVar1);
        iVar1 = *(int *)(DAT_00585bec + iVar3 * 4);
        if ((*(byte *)(iVar1 + 0xc) & 0x83) == 0) {
          puVar4 = *(undefined4 **)(DAT_00585bec + iVar3 * 4);
          goto LAB_0055230d;
        }
        FUN_005508f8(iVar3,iVar1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_00586c00);
  }
  FUN_005539be(2);
  return puVar4;
}

