// Resource_ReadLine: ported from Pizza Connection 2 at 0x402840.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x402840
#include "pc2_port.h"

int __thiscall Resource_ReadLine(void *self,uint8_t *arg1,int arg2,int arg3)

{
  int value1;
  char cVar2;
  uint32_t uvalue3;
  char *cptr4;
  int value5;
  int value6;
  
  value1 = (intptr_t)self + 0x1688;
  CS_Enter(value1);
  value5 = arg2 + -1;
  if (value5 < 1) {
    CS_Leave(value1);
    *arg1 = 0;
    return 0;
  }
  uvalue3 = *(uint32_t *)(arg3 + 0x10);
  if (*(uint32_t *)(arg3 + 8) <= uvalue3) {
    CS_Leave(value1);
    return -1;
  }
  if (*(int *)(arg3 + 0x1c) == 2) {
    value6 = 0;
    cptr4 = (char *)(*(int *)(arg3 + 0x20) + *(int *)(arg3 + 0xc) + uvalue3);
    if (0 < value5) {
      do {
        cVar2 = *cptr4;
        cptr4 = cptr4 + 1;
        *(int *)(arg3 + 0x10) = *(int *)(arg3 + 0x10) + 1;
        if (cVar2 != '\n') {
          if (cVar2 == '\r') break;
          arg1[value6] = cVar2;
          value6 = value6 + 1;
        }
      } while (value6 < value5);
    }
    arg1[value6] = 0;
    CS_Leave(value1);
    return value6;
  }
  if ((*(int **)((intptr_t)self + 0x1ac0) != *(int **)(arg3 + 0x18)) ||
     (*(int *)((intptr_t)self + 0x1abc) != *(int *)(arg3 + 0xc) + uvalue3)) {
    CRT_Fseek(*(int **)(arg3 + 0x18),*(int *)(arg3 + 0xc) + uvalue3,0);
  }
  value6 = 0;
  if (0 < value5) {
    do {
      if (*(uint32_t *)(arg3 + 8) <= *(uint32_t *)(arg3 + 0x10)) break;
      uvalue3 = CRT_Fgetc(*(uint32_t **)(arg3 + 0x18));
      *(int *)((intptr_t)self + 0x1abc) = *(int *)((intptr_t)self + 0x1abc) + 1;
      *(int *)(arg3 + 0x10) = *(int *)(arg3 + 0x10) + 1;
      if (uvalue3 == 0xd) break;
      if (uvalue3 != 10) {
        arg1[value6] = (char)uvalue3;
        value6 = value6 + 1;
      }
    } while (value6 < value5);
  }
  arg1[value6] = 0;
  *(uint32_t *)((intptr_t)self + 0x1ac0) = *(uint32_t *)(arg3 + 0x18);
  CS_Leave(value1);
  return value6;
}
