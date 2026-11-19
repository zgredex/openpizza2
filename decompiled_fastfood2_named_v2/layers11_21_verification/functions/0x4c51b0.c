// rea decompile_all
// name: FUN_004c51b0
// address: 0x4c51b0
// body: available
// range: 0x4c51b0-0x4c5221 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004c51b0(void *param_1)

{
  void *this;
  int iVar1;
  int iVar2;
  
  this = (void *)FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  iVar2 = 0;
  do {
    iVar1 = FUN_004dd0f0(this,iVar2);
    FUN_004a80e0(param_1,0x58e,iVar2,iVar1,DAT_00580ed4);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 8);
  Submenu_SetObjectPicture
            (param_1,*(int *)(*(int *)(DAT_0057c670 + 0x218) + 0x20),1,0x1f55,-1,
             *(int *)(DAT_0057c670 + 0x218));
  FUN_004c4fa0(param_1);
  return;
}

