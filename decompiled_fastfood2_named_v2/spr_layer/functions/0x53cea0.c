// rea decompile_all
// name: Sprite_RealizeLazy
// address: 0x53cea0
// body: available
// range: 0x53cea0-0x53cf31 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall Sprite_RealizeLazy(void *param_1)

{
  void *pvVar1;
  int *piVar2;
  
                    /* Lazily reloads the sprite payload and realizes the pixel buffer. */
  if (*(char *)((int)param_1 + 0x38) != '\0') {
    FUN_00401320(0x585520);
    if (*(char *)((int)param_1 + 0x39) == '\0') {
      pvVar1 = operator_new(*(uint *)((int)param_1 + 0x44));
      *(void **)((int)param_1 + 0x2c) = pvVar1;
      piVar2 = FUN_00402290(*(void **)((int)param_1 + 0x48),*(char **)((int)param_1 + 0x3c),0);
      if (piVar2 != (int *)0x0) {
        FUN_00540000(*(int *)((int)param_1 + 0x40),(int)piVar2,0);
        FUN_00402750(*(void **)((int)param_1 + 0x48),*(char **)((int)param_1 + 0x2c),
                     *(uint *)((int)param_1 + 0x44),(int)piVar2);
        FUN_00402990(*(void **)((int)param_1 + 0x48),(int)piVar2);
      }
      if ((*(byte *)((int)param_1 + 4) & 0x10) == 0) {
        Sprite_ConvertRGB555to565(param_1,DAT_0057c5c8);
      }
      *(undefined1 *)((int)param_1 + 0x39) = 1;
    }
    FUN_00401340(0x585520);
  }
  return;
}

