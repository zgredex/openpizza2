// rea decompile_all
// name: Game_CompanyManager_Construct
// address: 0x4f6d30
// body: available
// range: 0x4f6d30-0x4f6d96 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __fastcall Game_CompanyManager_Construct(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* Constructs the six-company manager and spawns its AI worker thread. */
  *param_1 = &PTR_Game_CompanyManager_Delete_0055c618;
  param_1[2] = 1;
  param_1[6] = 0;
  param_1[4] = 0xffffffff;
  param_1[0xe] = 0;
  param_1[3] = 0;
  puVar1 = FUN_00539ea0(DAT_0057c5c8);
  param_1[7] = puVar1;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  puVar1 = param_1 + 0x45;
  iVar2 = 6;
  do {
    puVar1[1] = 0;
    *puVar1 = 0;
    puVar1 = puVar1 + 0x5a;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  CRT_BeginThread(0x4f6da0,0,(int)param_1);
  return param_1;
}

