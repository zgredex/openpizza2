// rea decompile_all
// name: SoundOptions_Init
// address: 0x4a1170
// body: available
// range: 0x4a1170-0x4a1246 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl SoundOptions_Init(void *param_1)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
                    /* Initializes the sound-options sliders and enable checkbox. */
  FUN_00547770(&local_10);
  Window_GadgetNotify_Slider_SetRange(param_1,0x43a,0,10000,0);
  Window_GadgetNotify_Slider_SetValue(param_1,0x43a,local_c,0);
  Window_GadgetNotify_Slider_SetChangeNotify(param_1,0x43a,1);
  Window_GadgetNotify_Slider_SetRange(param_1,0x43b,0,10000,0);
  Window_GadgetNotify_Slider_SetValue(param_1,0x43b,local_8,0);
  Window_GadgetNotify_Slider_SetChangeNotify(param_1,0x43b,1);
  Window_GadgetNotify_Slider_SetRange(param_1,0x43c,0,10000,0);
  Window_GadgetNotify_Slider_SetValue(param_1,0x43c,local_4,0);
  Window_GadgetNotify_Slider_SetChangeNotify(param_1,0x43c,1);
  Window_GadgetNotify_Button_SetState(param_1,0x1f53,(uint)(local_10._1_1_ == '\0'));
  return;
}

