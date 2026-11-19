// rea decompile_all
// name: SoundSample_ParseWavFormat
// address: 0x53f320
// body: available
// range: 0x53f320-0x53f455 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __fastcall SoundSample_ParseWavFormat(int param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  char local_4 [4];
  
                    /* Parses WAV fmt/data headers and prepares decode buffers. */
  if (*(int *)(param_1 + 0xc) == 0) {
    return 0x80004003;
  }
  local_4[0] = '\0';
  local_4[1] = '\0';
  local_4[2] = '\0';
  local_4[3] = '\0';
  FUN_00540000(0x10,*(int *)(param_1 + 0xc),0);
  uVar2 = SoundPakStream_Read(*(void **)(param_1 + 8),local_4,4,*(int *)(param_1 + 0xc));
  if (3 < uVar2) {
    *(short *)(param_1 + 0x24) = local_4._0_2_ + -0x10;
    uVar2 = SoundPakStream_Read(*(void **)(param_1 + 8),(char *)(param_1 + 0x14),0x10,
                                *(int *)(param_1 + 0xc));
    if (0xf < uVar2) {
      if (*(short *)(param_1 + 0x14) == 1) {
        FUN_00540000(4,*(int *)(param_1 + 0xc),1);
        iVar3 = *(int *)(param_1 + 0xc);
        pcVar4 = (char *)(param_1 + 0x28);
      }
      else {
        iVar3 = FUN_0053f880(param_1);
        if (iVar3 < 0) {
          FUN_0048e0a0();
          return 0x80004001;
        }
        FUN_00540000(*(ushort *)(param_1 + 0x24) + 8,*(int *)(param_1 + 0xc),1);
        piVar1 = (int *)(param_1 + 0x28);
        uVar2 = SoundPakStream_Read(*(void **)(param_1 + 8),(char *)piVar1,4,*(int *)(param_1 + 0xc)
                                   );
        if (uVar2 < 4) {
          return 0x80004005;
        }
        *piVar1 = (uint)*(ushort *)(param_1 + 0x16) * *piVar1 * 2;
        FUN_00540000(4,*(int *)(param_1 + 0xc),1);
        iVar3 = *(int *)(param_1 + 0xc);
        pcVar4 = (char *)(param_1 + 0x38);
      }
      uVar2 = SoundPakStream_Read(*(void **)(param_1 + 8),pcVar4,4,iVar3);
      if (3 < uVar2) {
        *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x10);
        return 0;
      }
    }
  }
  return 0x80004005;
}

