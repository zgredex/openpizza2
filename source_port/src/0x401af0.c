// Pak_Open: ported from Pizza Connection 2 at 0x401af0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x401af0
#include "pc2_port.h"

uint32_t __thiscall Pak_Open(void *self,LPCSTR arg1)

{
  int value1;
  uint32_t *uptr2;
  char cVar3;
  int *ptr4;
  uint32_t uvalue5;
  int value6;
  char *cptr7;
  uint32_t uvalue8;
  uint32_t uvalue9;
  int value10;
  char *cptr11;
  char local_6c [96];
  uint32_t local_c;
  int local_8;
  int local_4;
  
  value1 = (intptr_t)self + 0x1688;
  CS_Enter(value1);
  if (0x13 < *(int *)((intptr_t)self + 0x1684)) {
    CS_Leave(value1);
    return 0;
  }
  uptr2 = (uint32_t *)(*(int *)((intptr_t)self + 0x1684) * 0x120 + 4 + (intptr_t)self);
  *(uint32_t *)((intptr_t)self + 0x1ac0) = 0;
  uvalue5 = CRT_Fopen(arg1,&DAT_00563184);
  *uptr2 = uvalue5;
  uvalue8 = 0xffffffff;
  do {
    cptr7 = arg1;
    if (uvalue8 == 0) break;
    uvalue8 = uvalue8 - 1;
    cptr7 = arg1 + 1;
    cVar3 = *arg1;
    arg1 = cptr7;
  } while (cVar3 != '\0');
  uvalue8 = ~uvalue8;
  cptr7 = cptr7 + -uvalue8;
  cptr11 = (char *)(uptr2 + 2);
  for (uvalue9 = uvalue8 >> 2; uvalue9 != 0; uvalue9 = uvalue9 - 1) {
    *(uint32_t *)cptr11 = *(uint32_t *)cptr7;
    cptr7 = cptr7 + 4;
    cptr11 = cptr11 + 4;
  }
  for (uvalue8 = uvalue8 & 3; uvalue8 != 0; uvalue8 = uvalue8 - 1) {
    *cptr11 = *cptr7;
    cptr7 = cptr7 + 1;
    cptr11 = cptr11 + 1;
  }
  if ((int *)*uptr2 == (int *)0x0) {
    CS_Leave(value1);
    return 0;
  }
  uptr2[0x47] = 1;
  CRT_FreadLocked(local_6c,1,0x6c,(int *)*uptr2);
  uvalue8 = 0xffffffff;
  cptr7 = s_ResourceFile_ID_7654_0056316c;
  do {
    if (uvalue8 == 0) break;
    uvalue8 = uvalue8 - 1;
    cVar3 = *cptr7;
    cptr7 = cptr7 + 1;
  } while (cVar3 != '\0');
  value6 = _strncmp(local_6c,s_ResourceFile_ID_7654_0056316c,~uvalue8 - 1);
  if (value6 != 0) {
    CS_Leave(value1);
    CRT_Fclose((FILE *)*uptr2);
    return 0;
  }
  if (100 < local_8) {
    CRT_Fclose((FILE *)*uptr2);
    CS_Leave(value1);
    return 0;
  }
  cptr7 = operator_new(local_c);
  uptr2[1] = cptr7;
  CRT_FreadLocked(cptr7,1,local_c,(int *)*uptr2);
  if (local_4 != 0) {
    Pak_DecodeIndex(uptr2[1],local_c);
    ptr4 = (int *)uptr2[1];
    uptr2[0x43] = ptr4;
    uptr2[0x44] = ptr4 + 1;
    uptr2[0x45] = ptr4 + *ptr4 * 5 + 1;
  }
  value6 = 0;
  if (0 < *(int *)uptr2[0x43]) {
    value10 = 0;
    do {
      value6 = value6 + 1;
      *(int *)(value10 + 0x10 + uptr2[0x44]) = *(int *)(value10 + 0x10 + uptr2[0x44]) + uptr2[0x45]
      ;
      value10 = value10 + 0x14;
    } while (value6 < *(int *)uptr2[0x43]);
  }
  Pak_SortEntries((int *)uptr2[0x44],*(uint32_t **)uptr2[0x43]);
  *(int *)((intptr_t)self + 0x1684) = *(int *)((intptr_t)self + 0x1684) + 1;
  CS_Leave(value1);
  return 1;
}
