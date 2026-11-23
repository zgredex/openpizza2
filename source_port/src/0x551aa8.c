// __fassign: ported from Pizza Connection 2 at 0x551aa8.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x551aa8
#include "pc2_port.h"

/* Library Function - Single Match
    __fassign
   
   Library: Visual Studio 2003 Release */

void __cdecl __fassign(int flag,char *argument,char *number)

{
  void *in_ECX;
  void *local_c;
  void *local_8;
  
  if (flag == 0) {
    FUN_00555b2a(in_ECX,(uint32_t *)&number,(uint8_t *)number);
    *(char **)argument = number;
    return;
  }
  local_c = in_ECX;
  local_8 = in_ECX;
  FUN_00555afd(in_ECX,(uint32_t *)&local_c,(uint8_t *)number);
  *(void **)argument = local_c;
  *(void **)(argument + 4) = local_8;
  return;
}
