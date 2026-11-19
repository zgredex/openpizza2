// rea decompile_all
// name: UI_ShowModalMessageBox
// address: 0x406d70
// body: available
// range: 0x406d70-0x406e89 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl UI_ShowModalMessageBox(undefined1 param_1)

{
  DWORD DVar1;
  undefined1 local_res0;
  undefined4 in_stack_00001008;
  byte *in_stack_0000100c;
  undefined4 auStack_7ffffffc [536870905];
  
  local_res0 = (undefined1)_local_res0;
                    /* Shows a formatted message in a modal box and pumps the UI. */
  __chkstk(local_res0);
  CRT_Vsprintf(&param_1,in_stack_0000100c,(undefined4 *)((int)register0x00000010 + 0x1010));
  DAT_0057c5f4 = LoadingScreen_Create((int *)&local_res0);
  Gadget_SetText(DAT_0057c5f4,0x3f8,in_stack_00001008);
  Window_GadgetNotify_Text_SetText(DAT_0057c5f4,0x3e9,&param_1);
  UI_RemoveObjectByKey(DAT_0057c5f4,0x3f9);
  UI_RemoveObjectByKey(DAT_0057c5f4,0x3fa);
  DAT_0057de70 = 0;
  Window_ShowWindowById(DAT_0057c5e0,_local_res0);
  Set_Field228(DAT_0057c5e0,DAT_0057c5f4);
  while ((DAT_0057de70 == 0 && (DVar1 = WaitForSingleObject(DAT_0057c0d8,0), DVar1 != 0))) {
    Window_ProcessMessageQueue(DAT_0057c5e0,0);
    Sleep(10);
  }
  Clear_Field228((int)DAT_0057c5e0);
  Window_DestroyChild(DAT_0057c5e0,DAT_0057c5f4);
  DAT_0057c5f4 = (undefined4 *)0x0;
  return;
}

