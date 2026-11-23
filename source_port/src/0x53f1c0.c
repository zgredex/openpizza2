// Sound_FormatErrorString: ported from Pizza Connection 2 at 0x53f1c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53f1c0
#include "pc2_port.h"

char * __cdecl Sound_FormatErrorString(int arg1)

{
  if (arg1 < -0x7787ffcd) {
    if (arg1 == -0x7787ffce) {
      return s_Invalid_call_on_object_00574d0c;
    }
    if (arg1 < -0x7ff8fff1) {
      if (arg1 == -0x7ff8fff2) {
        return s_Out_of_memory__00574d6c;
      }
      if (arg1 < -0x7fffbffa) {
        if (arg1 == -0x7fffbffb) {
          return s_Undetermined_error_00574da0;
        }
        if (arg1 == -0x7fffbfff) {
          return s_Unsupported_function_call_00574db4;
        }
        if (arg1 == -0x7fffbffe) {
          return s_Requested_COM_interface_unavaila_00574dd0;
        }
      }
      else if (arg1 == -0x7ffbfef0) {
        return s_Object_does_not_support_aggregat_00574d7c;
      }
    }
    else {
      if (arg1 == -0x7ff8ffa9) {
        return s_Invalid_parameter_00574d24;
      }
      if (arg1 == -0x7787fff6) {
        return s_Resource_always_in_use_00574d38;
      }
      if (arg1 == -0x7787ffe2) {
        return s_Buffer_control_unavailable_00574d50;
      }
    }
  }
  else {
    switch(arg1) {
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
