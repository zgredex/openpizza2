// CRT_Unwind: ported from Pizza Connection 2 at 0x54e5a7.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54e5a7
#include "pc2_port.h"

void CRT_Unwind(PVOID arg1,PEXCEPTION_RECORD arg2)

{
  void *pvVar1;
  
  pvVar1 = ExceptionList;
  RtlUnwind(arg1,(PVOID)0x54e5cf,arg2,(PVOID)0x0);
  arg2->ExceptionFlags = arg2->ExceptionFlags & 0xfffffffd;
  *(void **)pvVar1 = ExceptionList;
  ExceptionList = pvVar1;
  return;
}
