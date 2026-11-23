// KERNEL32.DLL::RtlUnwind: ported from Pizza Connection 2 at 0x557ae0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557ae0
#include "pc2_port.h"

void RtlUnwind(PVOID TargetFrame,PVOID TargetIp,PEXCEPTION_RECORD ExceptionRecord,PVOID ReturnValue)

{
                    /* WARNING: Could not recover jumptable at 0x00557ae0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlUnwind(TargetFrame,TargetIp,ExceptionRecord,ReturnValue);
  return;
}
