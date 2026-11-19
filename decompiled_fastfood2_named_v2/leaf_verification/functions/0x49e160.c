// rea decompile_all
// name: FUN_0049e160
// address: 0x49e160
// body: available
// range: 0x49e160-0x49e26d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_0049e160(void *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int local_54;
  int local_50;
  undefined1 local_48 [68];
  
  iVar3 = 0;
  local_54 = 0;
  iVar1 = Game_CountActiveStats(DAT_0057cc34);
  local_50 = 0;
  if (0 < iVar1) {
    piVar2 = &DAT_0057cadc;
    do {
      local_54 = local_54 + 1;
      if (param_2 < local_54) {
        FUN_0052f9b0(param_1,*(int *)((int)&DAT_00568b4c + iVar3),
                     *(int *)(DAT_0057c670 + 0xa8 + *piVar2 * 4) + 0x88);
        if (DAT_00568b48 == 0) {
          FUN_0054dd83(local_48,(byte *)s__0_2f___005688b0,
                       SUB84(*(double *)(*(int *)(DAT_0057c670 + 0xa8 + *piVar2 * 4) + 0xc0) *
                             (double)*(int *)(DAT_0057cc34 + 100 + *piVar2 * 4) * 0.001,0));
        }
        else {
          FUN_0054dd83(local_48,&DAT_00568ba4,*(undefined4 *)(DAT_0057cc34 + 100 + *piVar2 * 4));
        }
        FUN_0052f9b0(param_1,*(int *)((int)&DAT_00568b78 + iVar3),local_48);
        iVar3 = iVar3 + 4;
      }
      if (0x2b < iVar3) {
        return;
      }
      piVar2 = piVar2 + 1;
      local_50 = local_50 + 1;
    } while (local_50 < iVar1);
  }
  return;
}

