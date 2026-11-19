// rea decompile_all
// name: UI_CustomControl_Destructor
// address: 0x5211a0
// body: available
// range: 0x5211a0-0x52126e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall UI_CustomControl_Destructor(undefined4 *param_1)

{
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
                    /* Destroys the sprite-backed custom control and its children. */
  puStack_8 = &LAB_0055a5d6;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_UI_Viewport_Delete_0055c73c;
  local_4 = 1;
  FUN_00521b90((int)param_1);
  if ((undefined4 *)param_1[0x20] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x20])(1);
  }
  if ((undefined4 *)param_1[0x18] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x18])(1);
  }
  if ((undefined4 *)param_1[0x19] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x19])(1);
  }
  if ((undefined4 *)param_1[0x1a] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x1a])(1);
  }
  if ((undefined4 *)param_1[0x1b] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x1b])(1);
  }
  if (param_1[0x1f] != 0) {
    FUN_00531400((void *)param_1[2],*(int *)(param_1[0x1f] + 4),param_1[0xe],param_1[0xf]);
    UI_SetChildVisibleByID((void *)param_1[2],*(int *)(param_1[0x1f] + 4),1);
  }
  local_4 = local_4 & 0xffffff00;
  FUN_00522f20(param_1 + 0x21);
  local_4 = 0xffffffff;
  FUN_00520b10(param_1);
  ExceptionList = pvStack_c;
  return;
}

