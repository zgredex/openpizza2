// IsoMap_Save: ported from Pizza Connection 2 at 0x4ec4f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ec4f0
#include "pc2_port.h"

void __thiscall IsoMap_Save(void *self,void *arg1,int arg2)

{
  char cVar1;
  int value2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  int value5;
  int value6;
  int value7;
  char *cptr8;
  int *ptr9;
  char *cptr10;
  uint8_t local_7d;
  int local_7c;
  int local_78;
  int local_74;
  int local_70 [3];
  char local_64 [100];
  
  local_7d = 0;
  local_70[1] = 0x11;
  CRT_Ostream_Write(arg1,local_70 + 1,4);
  CRT_Ostream_Write(arg1,&arg2,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0xc,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x10,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x14,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x18,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x1c,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x20,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x24,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x28,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x2c,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x30,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x34,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x38,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x3c,0x10);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x60,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x6c,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x7c,0x1e);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0xba,2);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0xf0,4);
  ptr9 = (int *)((intptr_t)self + 0xa4);
  CRT_Ostream_Write(arg1,ptr9,4);
  CRT_Ostream_Write(arg1,(intptr_t)self + 0xa8,4);
  value6 = 0;
  local_78 = 0;
  if (0 < *ptr9) {
    do {
      CRT_Ostream_Write(arg1,*(int *)((intptr_t)self + 0x9c) + value6,1);
      CRT_Ostream_Write(arg1,*(int *)((intptr_t)self + 0x9c) + 2 + value6,2);
      CRT_Ostream_Write(arg1,*(int *)((intptr_t)self + 0x9c) + 6 + value6,1);
      CRT_Ostream_Write(arg1,&local_7d,1);
      CRT_Ostream_Write(arg1,*(int *)((intptr_t)self + 0x9c) + 8 + value6,4);
      CRT_Ostream_Write(arg1,*(int *)((intptr_t)self + 0x9c) + 0xc + value6,4);
      CRT_Ostream_Write(arg1,*(int *)((intptr_t)self + 0x9c) + 0x10 + value6,4);
      CRT_Ostream_Write(arg1,*(int *)((intptr_t)self + 0x9c) + 0x14 + value6,0x10);
      CRT_Ostream_Write(arg1,*(int *)((intptr_t)self + 0x9c) + 0x24 + value6,1);
      local_78 = local_78 + 1;
      value6 = value6 + 0x28;
    } while (local_78 < *ptr9);
  }
  value6 = 0;
  if (0 < *(int *)((intptr_t)self + 0xa8)) {
    value7 = 0;
    do {
      CRT_Ostream_Write(arg1,value7 + *(int *)((intptr_t)self + 0xa0),1);
      CRT_Ostream_Write(arg1,value7 + 2 + *(int *)((intptr_t)self + 0xa0),2);
      CRT_Ostream_Write(arg1,value7 + 6 + *(int *)((intptr_t)self + 0xa0),1);
      CRT_Ostream_Write(arg1,&local_7d,1);
      CRT_Ostream_Write(arg1,value7 + 8 + *(int *)((intptr_t)self + 0xa0),4);
      CRT_Ostream_Write(arg1,value7 + 0xc + *(int *)((intptr_t)self + 0xa0),4);
      CRT_Ostream_Write(arg1,value7 + 0x10 + *(int *)((intptr_t)self + 0xa0),4);
      CRT_Ostream_Write(arg1,value7 + 0x14 + *(int *)((intptr_t)self + 0xa0),0x10);
      CRT_Ostream_Write(arg1,value7 + 0x24 + *(int *)((intptr_t)self + 0xa0),1);
      value6 = value6 + 1;
      value7 = value7 + 0x28;
    } while (value6 < *(int *)((intptr_t)self + 0xa8));
  }
  value6 = 0;
  value7 = *(int *)((intptr_t)self + 0x20) * *(int *)((intptr_t)self + 0x1c);
  local_78 = 0;
  if (0 < value7) {
    do {
      local_74 = 0;
      if (value6 < value7) {
        ptr9 = (int *)(*(int *)((intptr_t)self + 0x4c) + 8 + value6 * 0xc);
        value5 = value6;
        do {
          value2 = *ptr9;
          if ((value2 != 0) &&
             (((*(int *)(value2 + 4) != -1 || (*(int *)(value2 + 0x10) != -1)) ||
              (*(int *)(value2 + 0x30) != -1)))) break;
          ptr9 = ptr9 + 3;
          local_74 = local_74 + 1;
          value5 = value5 + 1;
        } while (value5 < value7);
        if (local_74 < 1) goto LAB_004ec86f;
        local_7c = 1;
        CRT_Ostream_Write(arg1,&local_7c,4);
        CRT_Ostream_Write(arg1,&local_74,4);
        value6 = value6 + local_74;
        local_78 = value6;
      }
      else {
LAB_004ec86f:
        local_7c = 0;
        CRT_Ostream_Write(arg1,&local_7c,4);
      }
      if (local_7c == 0) {
        value7 = value6 * 0xc;
        local_70[2] = value7;
        CRT_Ostream_Write(arg1,*(uint32_t *)(value7 + 8 + *(int *)((intptr_t)self + 0x4c)),4);
        CRT_Ostream_Write(arg1,*(int *)(value7 + 8 + *(int *)((intptr_t)self + 0x4c)) + 0x24,2);
        CRT_Ostream_Write(arg1,*(int *)(value7 + 8 + *(int *)((intptr_t)self + 0x4c)) + 0x30,4);
        CRT_Ostream_Write(arg1,*(int *)(value7 + 8 + *(int *)((intptr_t)self + 0x4c)) + 0x34,4);
        CRT_Ostream_Write(arg1,*(int *)(value7 + 8 + *(int *)((intptr_t)self + 0x4c)) + 0x38,4);
        CRT_Ostream_Write(arg1,*(int *)(value7 + 8 + *(int *)((intptr_t)self + 0x4c)) + 0x28,4);
        CRT_Ostream_Write(arg1,*(int *)(value7 + 8 + *(int *)((intptr_t)self + 0x4c)) + 0x1c,4);
        CRT_Ostream_Write(arg1,*(int *)(value7 + 8 + *(int *)((intptr_t)self + 0x4c)) + 0x2c,1);
        CRT_Ostream_Write(arg1,*(int *)(value7 + 8 + *(int *)((intptr_t)self + 0x4c)) + 0x2d,1);
        CRT_Ostream_Write(arg1,*(int *)(value7 + 8 + *(int *)((intptr_t)self + 0x4c)) + 0x2e,1);
        CRT_Ostream_Write(arg1,*(int *)(value7 + 8 + *(int *)((intptr_t)self + 0x4c)) + 0x2f,1);
        if (arg2 == 0) {
          local_70[0] = *(int *)(*(int *)(value7 + 8 + *(int *)((intptr_t)self + 0x4c)) + 4);
          CRT_Ostream_Write(arg1,local_70,4);
          if (-1 < local_70[0]) {
            uvalue3 = 0xffffffff;
            cptr8 = (char *)(*(int *)((intptr_t)self + 4) + 0x25 + local_70[0] * 0x48);
            do {
              cptr10 = cptr8;
              if (uvalue3 == 0) break;
              uvalue3 = uvalue3 - 1;
              cptr10 = cptr8 + 1;
              cVar1 = *cptr8;
              cptr8 = cptr10;
            } while (cVar1 != '\0');
            uvalue3 = ~uvalue3;
            cptr8 = cptr10 + -uvalue3;
            cptr10 = local_64;
            for (uvalue4 = uvalue3 >> 2; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
              *(uint32_t *)cptr10 = *(uint32_t *)cptr8;
              cptr8 = cptr8 + 4;
              cptr10 = cptr10 + 4;
            }
            for (uvalue3 = uvalue3 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
              *cptr10 = *cptr8;
              cptr8 = cptr8 + 1;
              cptr10 = cptr10 + 1;
            }
            CRT_Ostream_Write(arg1,local_64,0x32);
            value6 = local_78;
            value7 = local_70[2];
          }
        }
        else {
          CRT_Ostream_Write(arg1,*(int *)(value7 + 8 + *(int *)((intptr_t)self + 0x4c)) + 4,4);
        }
        if (arg2 == 0) {
          local_70[0] = *(int *)(*(int *)(value7 + 8 + *(int *)((intptr_t)self + 0x4c)) + 0x10);
          CRT_Ostream_Write(arg1,local_70,4);
          if (-1 < local_70[0]) {
            uvalue3 = 0xffffffff;
            cptr8 = (char *)(*(int *)((intptr_t)self + 4) + 0x25 + local_70[0] * 0x48);
            do {
              cptr10 = cptr8;
              if (uvalue3 == 0) break;
              uvalue3 = uvalue3 - 1;
              cptr10 = cptr8 + 1;
              cVar1 = *cptr8;
              cptr8 = cptr10;
            } while (cVar1 != '\0');
            uvalue3 = ~uvalue3;
            cptr8 = cptr10 + -uvalue3;
            cptr10 = local_64;
            for (uvalue4 = uvalue3 >> 2; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
              *(uint32_t *)cptr10 = *(uint32_t *)cptr8;
              cptr8 = cptr8 + 4;
              cptr10 = cptr10 + 4;
            }
            for (uvalue3 = uvalue3 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
              *cptr10 = *cptr8;
              cptr8 = cptr8 + 1;
              cptr10 = cptr10 + 1;
            }
            CRT_Ostream_Write(arg1,local_64,0x32);
            value6 = local_78;
          }
        }
        else {
          CRT_Ostream_Write(arg1,*(int *)(value7 + 8 + *(int *)((intptr_t)self + 0x4c)) + 0x10,4);
        }
        value6 = value6 + 1;
        local_78 = value6;
      }
      value7 = *(int *)((intptr_t)self + 0x20) * *(int *)((intptr_t)self + 0x1c);
    } while (value6 < value7);
  }
  if (*(int *)((intptr_t)self + 0x118) == 0) {
    local_7c = 0;
    CRT_Ostream_Write(arg1,&local_7c,4);
    return;
  }
  local_7c = 1;
  CRT_Ostream_Write(arg1,&local_7c,4);
  local_7c = **(int **)((intptr_t)self + 0x118);
  CRT_Ostream_Write(arg1,&local_7c,4);
  value6 = 0;
  if (0 < local_7c + 1) {
    do {
      CRT_Ostream_Write(arg1,*(int *)((intptr_t)self + 0x118) + value6 * 4,4);
      value6 = value6 + 1;
    } while (value6 < local_7c + 1);
  }
  return;
}
