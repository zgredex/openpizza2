// rea decompile_all
// name: RenovationScreen_UpdatePage
// address: 0x492390
// body: available
// range: 0x492390-0x492430 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl RenovationScreen_UpdatePage(void *param_1)

{
  int iVar1;
  undefined4 extraout_EDX;
  undefined4 uVar2;
  undefined4 extraout_EDX_00;
  int iVar3;
  int iVar4;
  
                    /* Refreshes the renovation/decoration page. */
  DAT_0057c6b4 = *(void **)(DAT_0057c670 + 0x9c);
  FUN_00492270(param_1,0x4ff,DAT_0057c6bc);
  FUN_004922d0(param_1);
  FUN_00531470(param_1,0x4ff,0);
  FUN_0052f830(param_1,0x1f45,(&DAT_0058319c)[DAT_0057c6c0]);
  FUN_0052f830(param_1,0x1f48,(&DAT_00583190)[DAT_0057c6c4]);
  iVar3 = 0;
  uVar2 = extraout_EDX;
  do {
    iVar4 = DAT_00582320;
    iVar1 = FUN_00478be0(DAT_0057c6b4,uVar2,iVar3);
    Rating_UpdateBarByKey(param_1,0x4f2,iVar3,iVar1,iVar4);
    iVar3 = iVar3 + 1;
    uVar2 = extraout_EDX_00;
  } while (iVar3 < 8);
  return;
}

