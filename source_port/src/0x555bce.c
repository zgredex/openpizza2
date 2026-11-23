// FUN_00555bce: ported from Pizza Connection 2 at 0x555bce.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x555bce
#include "pc2_port.h"

int * __cdecl FUN_00555bce(uint32_t arg1,uint32_t arg2,int *arg3,uint32_t *arg4)

{
  int *ptr1;
  uint32_t *uptr2;
  int value3;
  uint32_t in_stack_ffffffbc;
  uint16_t uvalue4;
  short local_2c;
  char local_2a;
  uint32_t local_28 [6];
  uint32_t local_10;
  uint32_t uStack_c;
  uint16_t uStack_8;
  
  uvalue4 = (uint16_t)((uint32_t)in_stack_ffffffbc >> 0x10);
  FUN_00555c2a(&local_10,&arg1);
  value3 = FUN_00556d7e(local_10,uStack_c,CONCAT22(uvalue4,uStack_8),0x11,0,&local_2c);
  uptr2 = arg4;
  ptr1 = arg3;
  arg3[2] = value3;
  *arg3 = (intptr_t)local_2a;
  arg3[1] = (intptr_t)local_2c;
  _strcpy(arg4,local_28);
  ptr1[3] = (intptr_t)uptr2;
  return ptr1;
}
