// rea decompile_all
// name: LoadGameMenu_UpdateSlotRows
// address: 0x4a1a10
// body: available
// range: 0x4a1a10-0x4a1a9d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl LoadGameMenu_UpdateSlotRows(void *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int local_4;
  
                    /* Fills the thirteen load-slot rows from the save list. */
  local_4 = *(int *)((int)DAT_0057cfc8 + 0x14);
  if (local_4 < 0xe) {
    param_2 = 0;
  }
  else {
    local_4 = 0xd;
  }
  if (0 < local_4) {
    iVar2 = 0x1f6a;
    do {
      iVar1 = FUN_004017f0(DAT_0057cfc8,iVar2 + -0x1f6a + param_2,(int *)0x0);
      Window_GadgetNotify_Text_SetTextColor(param_1,iVar2,*(undefined4 *)(iVar1 + 0x54));
      Window_GadgetNotify_Text_SetText(param_1,iVar2,iVar1 + 4);
      if (*(char **)(iVar1 + 0x44) != (char *)0x0) {
        FUN_00531f50(param_1,iVar2 + -0xd,*(char **)(iVar1 + 0x44));
      }
      iVar1 = iVar2 + -0x1f69;
      iVar2 = iVar2 + 1;
    } while (iVar1 < local_4);
  }
  return;
}

