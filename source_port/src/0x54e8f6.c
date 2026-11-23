// __abnormal_termination: ported from Pizza Connection 2 at 0x54e8f6.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54e8f6
#include "pc2_port.h"


/* Library Function - Single Match
    __abnormal_termination
   
   Library: Visual Studio */

int __cdecl __abnormal_termination(void)

{
  int value1;
  
  value1 = 0;
  if ((*(uint8_t **)((intptr_t)ExceptionList + 4) == &LAB_0054e86c) &&
     (*(int *)((intptr_t)ExceptionList + 8) == *(int *)(*(int *)((intptr_t)ExceptionList + 0xc) + 0xc))) {
    value1 = 1;
  }
  return value1;
}
