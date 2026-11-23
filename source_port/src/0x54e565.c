// CRT_CallExceptionHandler: ported from Pizza Connection 2 at 0x54e565.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54e565
#include "pc2_port.h"

void CRT_CallExceptionHandler(uint8_t *UNRECOVERED_JUMPTABLE)

{
  ExceptionList = *(void **)ExceptionList;
                    /* WARNING: Could not recover jumptable at 0x0054e590. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}
