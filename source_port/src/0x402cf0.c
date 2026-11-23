// FileObject_Open: ported from Pizza Connection 2 at 0x402cf0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x402cf0
#include "pc2_port.h"

uint32_t * __thiscall FileObject_Open(char *self,void *arg1,char *arg2,uint32_t *arg3)

{
  uint8_t flag1;
  int *ptr2;
  int value3;
  uint8_t *bptr4;
  int value5;
  char *cptr6;
  uint8_t *bptr7;
  bool flag8;
  uint8_t local_100 [256];
  
  *(uint8_t ***)self = &PTR_FileObject_Delete_0055c2f4;
  if (arg3 != (uint32_t *)0x0) {
    *arg3 = 0;
  }
  *(uint16_t *)((intptr_t)self + 0x14) = 0;
  *(uint16_t *)((intptr_t)self + 0x12) = 0;
  *(uint16_t *)((intptr_t)self + 0x10) = 0;
  *(uint32_t *)((intptr_t)self + 0xc) = 0;
  *(uint32_t *)((intptr_t)self + 8) = 0;
  *(uint32_t *)((intptr_t)self + 4) = 0;
  ptr2 = Resource_Open(arg1,arg2,0);
  if (ptr2 == (int *)0x0) {
    if (arg3 != (uint32_t *)0x0) {
      *arg3 = 0x2bd;
      return self;
    }
    NoOp_Stub();
  }
  value5 = -1;
LAB_00402d6f:
  do {
    while( true ) {
      do {
        value3 = Resource_ReadLine(arg1,local_100,0x100,(intptr_t)ptr2);
        if (value3 == -1) {
          Resource_Close(arg1,(intptr_t)ptr2);
          if (((*(int *)((intptr_t)self + 4) == 0) || (*(int *)((intptr_t)self + 8) == 0)) ||
             (*(int *)((intptr_t)self + 0xc) == 0)) {
            if (arg3 != (uint32_t *)0x0) {
              *arg3 = 0x2be;
              return self;
            }
            NoOp_Stub();
          }
          CRT_QSort(*(int **)((intptr_t)self + 0xc),(uint32_t *)(intptr_t)*(short *)((intptr_t)self + 0x14),0x10,
                    _strcmp);
          return self;
        }
      } while (((local_100[0] == 0) || (local_100[0] == 0x5c)) || (local_100[0] == 0x2f));
      if (local_100[0] == 0x5b) break;
      NamePool_AddName(self,(char *)local_100,value5);
    }
    cptr6 = s__SURNAME_FEMALE__005632d8;
    bptr4 = local_100;
    do {
      flag1 = *bptr4;
      flag8 = flag1 < (uint8_t)*cptr6;
      if (flag1 != *cptr6) {
LAB_00402dda:
        value3 = (1 - (uint32_t)flag8) - (uint32_t)(flag8 != 0);
        goto LAB_00402ddf;
      }
      if (flag1 == 0) break;
      flag1 = bptr4[1];
      flag8 = flag1 < (uint8_t)cptr6[1];
      if (flag1 != cptr6[1]) goto LAB_00402dda;
      bptr4 = bptr4 + 2;
      cptr6 = cptr6 + 2;
    } while (flag1 != 0);
    value3 = 0;
LAB_00402ddf:
    if (value3 == 0) {
      value5 = 0;
      goto LAB_00402d6f;
    }
    cptr6 = s__SURNAME_MALE__005632c8;
    bptr4 = local_100;
    do {
      flag1 = *bptr4;
      flag8 = flag1 < (uint8_t)*cptr6;
      if (flag1 != *cptr6) {
LAB_00402e14:
        value3 = (1 - (uint32_t)flag8) - (uint32_t)(flag8 != 0);
        goto LAB_00402e19;
      }
      if (flag1 == 0) break;
      flag1 = bptr4[1];
      flag8 = flag1 < (uint8_t)cptr6[1];
      if (flag1 != cptr6[1]) goto LAB_00402e14;
      bptr4 = bptr4 + 2;
      cptr6 = cptr6 + 2;
    } while (flag1 != 0);
    value3 = 0;
LAB_00402e19:
    if (value3 == 0) {
      value5 = 1;
    }
    else {
      bptr7 = &DAT_005632c0;
      bptr4 = local_100;
      do {
        flag1 = *bptr4;
        flag8 = flag1 < *bptr7;
        if (flag1 != *bptr7) {
LAB_00402e54:
          value3 = (1 - (uint32_t)flag8) - (uint32_t)(flag8 != 0);
          goto LAB_00402e59;
        }
        if (flag1 == 0) break;
        flag1 = bptr4[1];
        flag8 = flag1 < bptr7[1];
        if (flag1 != bptr7[1]) goto LAB_00402e54;
        bptr4 = bptr4 + 2;
        bptr7 = bptr7 + 2;
      } while (flag1 != 0);
      value3 = 0;
LAB_00402e59:
      if (value3 == 0) {
        value5 = 2;
      }
    }
  } while( true );
}
