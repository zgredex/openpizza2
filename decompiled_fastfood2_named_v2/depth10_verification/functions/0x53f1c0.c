// rea decompile_all
// name: FUN_0053f1c0
// address: 0x53f1c0
// body: available
// range: 0x53f1c0-0x53f28b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


char * __cdecl FUN_0053f1c0(int param_1)

{
  if (param_1 < -0x7787ffcd) {
    if (param_1 == -0x7787ffce) {
      return s_Invalid_call_on_object_00574d0c;
    }
    if (param_1 < -0x7ff8fff1) {
      if (param_1 == -0x7ff8fff2) {
        return s_Out_of_memory__00574d6c;
      }
      if (param_1 < -0x7fffbffa) {
        if (param_1 == -0x7fffbffb) {
          return s_Undetermined_error_00574da0;
        }
        if (param_1 == -0x7fffbfff) {
          return s_Unsupported_function_call_00574db4;
        }
        if (param_1 == -0x7fffbffe) {
          return s_Requested_COM_interface_unavaila_00574dd0;
        }
      }
      else if (param_1 == -0x7ffbfef0) {
        return s_Object_does_not_support_aggregat_00574d7c;
      }
    }
    else {
      if (param_1 == -0x7ff8ffa9) {
        return s_Invalid_parameter_00574d24;
      }
      if (param_1 == -0x7787fff6) {
        return s_Resource_always_in_use_00574d38;
      }
      if (param_1 == -0x7787ffe2) {
        return s_Buffer_control_unavailable_00574d50;
      }
    }
  }
  else {
    switch(param_1) {
    case -0x7787ffba:
      return &DAT_00574c44;
    case -0x7787ff9c:
      return s_Specific_wave_format_is_not_PCM_00574cd0;
    case -0x7787ff88:
      return s_No_DirectSound_driver_avaiable_00574c94;
    case -0x7787ff7e:
      return s_Object_already_initialized_00574cf0;
    case -0x7787ff6a:
      return s_Buffer_memory_has_been_lost_00574cb4;
    case -0x7787ff60:
      return s_Other_application_has_higher_pri_00574c68;
    case -0x7787ff56:
      return s_DirectSound_not_initialized_00574c28;
    }
  }
  return s_Unknown_error_00574c18;
}

