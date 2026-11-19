// rea decompile_all
// name: Object_SetCompanyStylePalette
// address: 0x505f40
// body: available
// range: 0x505f40-0x506002 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl
Object_SetCompanyStylePalette
          (undefined1 param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
          undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  
                    /* Writes the eight per-company building-type ids used for style selection. */
  DAT_00580ac8 = param_1;
  DAT_00580ac9 = param_2;
  DAT_00580acb = param_4;
  DAT_00580aca = param_3;
  DAT_00580acc = param_5;
  DAT_00580ace = param_7;
  DAT_00580acd = param_6;
  DAT_00580acf = param_8;
  pvVar1 = (void *)FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0
                               );
  iVar2 = FUN_004d8780(pvVar1,3);
  if (0 < iVar2) {
    pvVar1 = (void *)FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),
                                  (int *)0x0);
    iVar2 = FUN_004d74c0(pvVar1,3,0,'\0');
    if (iVar2 != 0) {
      iVar2 = 0;
      do {
        if (((&DAT_00580ac8)[iVar2] == '\f') && (uVar3 = FUN_004034d0(1,100), 0x32 < (int)uVar3)) {
          (&DAT_00580ac8)[iVar2] = 3;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < 8);
    }
  }
  return;
}

