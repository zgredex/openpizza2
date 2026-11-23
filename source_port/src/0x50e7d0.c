// Person_ResumeRouteOrDetach: ported from Pizza Connection 2 at 0x50e7d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50e7d0
#include "pc2_port.h"

void __fastcall Person_ResumeRouteOrDetach(void *arg1)

{
  uint8_t uvalue1;
  uint32_t extraout_var;
  int value2;
  
                    /* Resumes a person's route or releases it and sets state 6. */
  uvalue1 = Object_IsVisibleThisFrame((intptr_t)arg1);
  if (CONCAT31(extraout_var,uvalue1) != 0) {
    value2 = Person_CanContinuePath((intptr_t)arg1);
    if (value2 != 0) {
      Person_TruncatePathToCurrentStep((intptr_t)arg1);
      Object_SetState(arg1,6);
      return;
    }
    UI_DetachChildRecord((intptr_t)arg1);
  }
  Object_SetState(arg1,6);
  return;
}
