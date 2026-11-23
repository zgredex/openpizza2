// CRT_Cftof: ported from Pizza Connection 2 at 0x551c09.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x551c09
#include "pc2_port.h"

char * __cdecl CRT_Cftof(uint64_t *arg1,char *arg2,size_t arg3)

{
  uint32_t local_2c [6];
  int local_14;
  int local_10;
  
  FUN_00555bce((uint32_t)*arg1,(intptr_t)((uint64_t)*arg1 >> 0x20),&local_14,local_2c);
  FUN_00555b57(arg2 + (local_14 == 0x2d),local_10 + arg3,(intptr_t)&local_14);
  CRT_InsertDecimalPoint(arg2,arg3,&local_14,'\0');
  return arg2;
}
