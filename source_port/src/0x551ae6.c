// CRT_Cftoe: ported from Pizza Connection 2 at 0x551ae6.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x551ae6
#include "pc2_port.h"

uint8_t * __cdecl CRT_Cftoe(uint64_t *arg1,uint8_t *arg2,int arg3,int arg4)

{
  uint32_t local_2c [6];
  int local_14 [4];
  
  FUN_00555bce((uint32_t)*arg1,(intptr_t)((uint64_t)*arg1 >> 0x20),local_14,local_2c);
  FUN_00555b57(arg2 + (uint32_t)(0 < arg3) + (uint32_t)(local_14[0] == 0x2d),arg3 + 1,(intptr_t)local_14
              );
  CRT_FormatExponent(arg2,arg3,arg4,local_14,'\0');
  return arg2;
}
