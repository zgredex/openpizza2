// Resource_Open: ported from Pizza Connection 2 at 0x402290.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x402290
#include "pc2_port.h"


int * __thiscall Resource_Open(void *self,char *arg1,int arg2)

{
  int value1;
  char cVar2;
  int *ptr3;
  int *ptr4;
  uint32_t uvalue5;
  uint32_t uvalue6;
  int value7;
  char *cptr8;
  char *cptr9;
  char *cptr10;
  int local_210;
  int local_20c;
  char local_208 [260];
  uint32_t local_104;
  
  value1 = (intptr_t)self + 0x1688;
  CS_Enter(value1);
  ResourceManager_NormalizeResourcePath(self,arg1,&local_104);
  ptr3 = (int *)ResourceHandle_Alloc((intptr_t)self);
  if (ptr3 == (int *)0x0) {
    CS_Leave(value1);
    if (arg2 != 0) {
      NoOp_Stub();
    }
    return (int *)0x0;
  }
  if (*(int *)((intptr_t)self + 0x1ab8) != 0) {
    if (((uint8_t)((local_104) >> 8)) == ':') {
      local_208[0] = '\0';
    }
    else {
      uvalue5 = 0xffffffff;
      cptr8 = (char *)((intptr_t)self + 0x19b0);
      do {
        cptr10 = cptr8;
        if (uvalue5 == 0) break;
        uvalue5 = uvalue5 - 1;
        cptr10 = cptr8 + 1;
        cVar2 = *cptr8;
        cptr8 = cptr10;
      } while (cVar2 != '\0');
      uvalue5 = ~uvalue5;
      cptr8 = cptr10 + -uvalue5;
      cptr10 = local_208;
      for (uvalue6 = uvalue5 >> 2; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
        *(uint32_t *)cptr10 = *(uint32_t *)cptr8;
        cptr8 = cptr8 + 4;
        cptr10 = cptr10 + 4;
      }
      for (uvalue5 = uvalue5 & 3; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
        *cptr10 = *cptr8;
        cptr8 = cptr8 + 1;
        cptr10 = cptr10 + 1;
      }
    }
    uvalue5 = 0xffffffff;
    cptr8 = (char *)&local_104;
    do {
      cptr10 = cptr8;
      if (uvalue5 == 0) break;
      uvalue5 = uvalue5 - 1;
      cptr10 = cptr8 + 1;
      cVar2 = *cptr8;
      cptr8 = cptr10;
    } while (cVar2 != '\0');
    uvalue5 = ~uvalue5;
    *(uint32_t *)((intptr_t)self + 0x1ac0) = 0;
    value7 = -1;
    cptr8 = local_208;
    do {
      cptr9 = cptr8;
      if (value7 == 0) break;
      value7 = value7 + -1;
      cptr9 = cptr8 + 1;
      cVar2 = *cptr8;
      cptr8 = cptr9;
    } while (cVar2 != '\0');
    cptr8 = cptr10 + -uvalue5;
    cptr10 = cptr9 + -1;
    for (uvalue6 = uvalue5 >> 2; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
      *(uint32_t *)cptr10 = *(uint32_t *)cptr8;
      cptr8 = cptr8 + 4;
      cptr10 = cptr10 + 4;
    }
    for (uvalue5 = uvalue5 & 3; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
      *cptr10 = *cptr8;
      cptr8 = cptr8 + 1;
      cptr10 = cptr10 + 1;
    }
    ptr4 = (int *)CRT_Fopen(local_208,&DAT_00563184);
    if (ptr4 != (int *)0x0) {
      CRT_Fseek(ptr4,0,2);
      value7 = CRT_Ftell((char *)ptr4);
      ptr3[2] = value7;
      CRT_Fseek(ptr4,0,0);
      ptr3[3] = 0;
      *ptr3 = -1;
      ptr3[1] = -1;
      ptr3[4] = 0;
      ptr3[6] = (intptr_t)ptr4;
      ptr3[7] = 1;
      CS_Leave(value1);
      return ptr3;
    }
  }
  value7 = Pak_FindEntry(self,(uint8_t *)&local_104,&local_20c,&local_210);
  if (value7 != 0) {
    ptr3[2] = *(int *)(*(int *)(local_20c * 0x120 + 0x114 + (intptr_t)self) + 8 + local_210 * 0x14);
    ptr3[3] = *(int *)(*(int *)(local_20c * 0x120 + 0x114 + (intptr_t)self) + 0xc + local_210 * 0x14) +
                0x6c;
    *ptr3 = local_20c;
    ptr3[1] = local_210;
    ptr3[4] = 0;
    if (*(int *)((local_20c * 9 + 9) * 0x20 + (intptr_t)self) == 0) {
      ptr3[6] = 0;
      ptr3[7] = 2;
      ptr3[8] = *(int *)(local_20c * 0x120 + 0x11c + (intptr_t)self);
    }
    else {
      value7 = *(int *)(local_20c * 0x120 + 4 + (intptr_t)self);
      ptr3[7] = 0;
      ptr3[6] = value7;
      ptr3[8] = 0;
    }
    CS_Leave(value1);
    return ptr3;
  }
  if (*(int *)((intptr_t)self + 0x1ab8) == 0) {
    if (((uint8_t)((local_104) >> 8)) == ':') {
      local_208[0] = '\0';
    }
    else {
      uvalue5 = 0xffffffff;
      cptr8 = (char *)((intptr_t)self + 0x19b0);
      do {
        cptr10 = cptr8;
        if (uvalue5 == 0) break;
        uvalue5 = uvalue5 - 1;
        cptr10 = cptr8 + 1;
        cVar2 = *cptr8;
        cptr8 = cptr10;
      } while (cVar2 != '\0');
      uvalue5 = ~uvalue5;
      cptr8 = cptr10 + -uvalue5;
      cptr10 = local_208;
      for (uvalue6 = uvalue5 >> 2; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
        *(uint32_t *)cptr10 = *(uint32_t *)cptr8;
        cptr8 = cptr8 + 4;
        cptr10 = cptr10 + 4;
      }
      for (uvalue5 = uvalue5 & 3; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
        *cptr10 = *cptr8;
        cptr8 = cptr8 + 1;
        cptr10 = cptr10 + 1;
      }
    }
    uvalue5 = 0xffffffff;
    cptr8 = (char *)&local_104;
    do {
      cptr10 = cptr8;
      if (uvalue5 == 0) break;
      uvalue5 = uvalue5 - 1;
      cptr10 = cptr8 + 1;
      cVar2 = *cptr8;
      cptr8 = cptr10;
    } while (cVar2 != '\0');
    uvalue5 = ~uvalue5;
    *(uint32_t *)((intptr_t)self + 0x1ac0) = 0;
    value7 = -1;
    cptr8 = local_208;
    do {
      cptr9 = cptr8;
      if (value7 == 0) break;
      value7 = value7 + -1;
      cptr9 = cptr8 + 1;
      cVar2 = *cptr8;
      cptr8 = cptr9;
    } while (cVar2 != '\0');
    cptr8 = cptr10 + -uvalue5;
    cptr10 = cptr9 + -1;
    for (uvalue6 = uvalue5 >> 2; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
      *(uint32_t *)cptr10 = *(uint32_t *)cptr8;
      cptr8 = cptr8 + 4;
      cptr10 = cptr10 + 4;
    }
    for (uvalue5 = uvalue5 & 3; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
      *cptr10 = *cptr8;
      cptr8 = cptr8 + 1;
      cptr10 = cptr10 + 1;
    }
    ptr4 = (int *)CRT_Fopen(local_208,&DAT_00563184);
    if (ptr4 != (int *)0x0) {
      CRT_Fseek(ptr4,0,2);
      value7 = CRT_Ftell((char *)ptr4);
      ptr3[2] = value7;
      CRT_Fseek(ptr4,0,0);
      ptr3[3] = 0;
      *ptr3 = -1;
      ptr3[1] = -1;
      ptr3[4] = 0;
      ptr3[6] = (intptr_t)ptr4;
      ptr3[7] = 1;
      CS_Leave(value1);
      return ptr3;
    }
  }
  CS_Leave(value1);
  ptr3[5] = 0;
  if (arg2 != 0) {
    NoOp_Stub();
  }
  return (int *)0x0;
}
