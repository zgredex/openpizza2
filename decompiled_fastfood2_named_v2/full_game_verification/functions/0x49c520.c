// rea decompile_all
// name: CompanyRanking_SelectCompanyButton
// address: 0x49c520
// body: available
// range: 0x49c520-0x49c5c4 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl CompanyRanking_SelectCompanyButton(void *param_1,int param_2)

{
  void *this;
  int iVar1;
  int *piVar2;
  
  piVar2 = &DAT_00568a14;
  do {
    Window_GadgetNotify_Button_SetState(param_1,*piVar2,0);
    piVar2 = piVar2 + 1;
  } while ((int)piVar2 < 0x568a34);
  Window_GadgetNotify_Button_SetState(param_1,param_2,1);
  DAT_0057ca90 = *(int *)(DAT_0057ca94 + -0x119c + (DAT_0057ca40 + param_2) * 4);
  iVar1 = Game_GetActiveCompanyById
                    (*(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4),
                     DAT_0057ca90);
  *(int *)(DAT_0057c670 + 0x98) = iVar1;
  this = *(void **)(DAT_0057c670 + 0x25c);
  iVar1 = Game_FindCompanyIndex
                    (*(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4),
                     *(int *)(DAT_0057c670 + 0x98));
  UI_QueueControlCommand(this,-0x18671,0x23,iVar1);
  return;
}

