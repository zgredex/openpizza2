// Pak_OpenEmbedded: ported from Pizza Connection 2 at 0x401cf0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x401cf0
#include "pc2_port.h"

uint32_t __thiscall Pak_OpenEmbedded(char *self,LPCSTR arg1)

{
  int value1;
  uint32_t *uptr2;
  char cVar3;
  int *ptr4;
  HRSRC hResInfo;
  HGLOBAL hResData;
  uint32_t *uptr5;
  uint32_t *uptr6;
  int value7;
  uint32_t uvalue8;
  int value9;
  char *cptr10;
  char local_6c [96];
  uint32_t local_c;
  int local_8;
  int local_4;
  
  value1 = (intptr_t)self + 0x1688;
  CS_Enter(value1);
  if (0x13 < *(int *)((intptr_t)self + 0x1684)) {
    NoOp_Stub();
    CS_Leave(value1);
    return 0;
  }
  uptr2 = (uint32_t *)(*(int *)((intptr_t)self + 0x1684) * 0x120 + 4 + (intptr_t)self);
  uptr5 = uptr2 + 2;
  for (value7 = 0x41; value7 != 0; value7 = value7 + -1) {
    *uptr5 = 0;
    uptr5 = uptr5 + 1;
  }
  hResInfo = FindResourceA((HMODULE)0x0,arg1,s_ResourceFiles_005631d8);
  if (hResInfo == (HRSRC)0x0) {
    CS_Leave(value1);
    return 0;
  }
  hResData = LoadResource((HMODULE)0x0,hResInfo);
  if (hResData == (HGLOBAL)0x0) {
    CS_Leave(value1);
    return 0;
  }
  uptr5 = LockResource(hResData);
  uptr2[0x46] = uptr5;
  if (uptr5 == (uint32_t *)0x0) {
    CS_Leave(value1);
    return 0;
  }
  uptr2[0x47] = 0;
  *uptr2 = 0;
  uptr6 = uptr5;
  cptr10 = local_6c;
  for (value7 = 0x1b; value7 != 0; value7 = value7 + -1) {
    *(uint32_t *)cptr10 = *uptr6;
    uptr6 = uptr6 + 1;
    cptr10 = cptr10 + 4;
  }
  uvalue8 = 0xffffffff;
  cptr10 = s_ResourceFile_ID_7654_0056316c;
  do {
    if (uvalue8 == 0) break;
    uvalue8 = uvalue8 - 1;
    cVar3 = *cptr10;
    cptr10 = cptr10 + 1;
  } while (cVar3 != '\0');
  value7 = _strncmp(local_6c,s_ResourceFile_ID_7654_0056316c,~uvalue8 - 1);
  if (value7 != 0) {
    CS_Leave(value1);
    return 0;
  }
  if (100 < local_8) {
    NoOp_Stub();
    CS_Leave(value1);
    return 0;
  }
  uptr6 = operator_new(local_c);
  uptr2[1] = uptr6;
  uptr5 = uptr5 + 0x1b;
  for (uvalue8 = local_c >> 2; uvalue8 != 0; uvalue8 = uvalue8 - 1) {
    *uptr6 = *uptr5;
    uptr5 = uptr5 + 1;
    uptr6 = uptr6 + 1;
  }
  for (uvalue8 = local_c & 3; uvalue8 != 0; uvalue8 = uvalue8 - 1) {
    *(uint8_t *)uptr6 = *(uint8_t *)uptr5;
    uptr5 = (uint32_t *)((intptr_t)uptr5 + 1);
    uptr6 = (uint32_t *)((intptr_t)uptr6 + 1);
  }
  if (local_4 != 0) {
    Pak_DecodeIndex(uptr2[1],local_c);
    ptr4 = (int *)uptr2[1];
    uptr2[0x43] = ptr4;
    uptr2[0x44] = ptr4 + 1;
    uptr2[0x45] = ptr4 + *ptr4 * 5 + 1;
  }
  value7 = 0;
  if (0 < *(int *)uptr2[0x43]) {
    value9 = 0;
    do {
      value7 = value7 + 1;
      *(int *)(value9 + 0x10 + uptr2[0x44]) = *(int *)(value9 + 0x10 + uptr2[0x44]) + uptr2[0x45];
      value9 = value9 + 0x14;
    } while (value7 < *(int *)uptr2[0x43]);
  }
  Pak_SortEntries((int *)uptr2[0x44],*(uint32_t **)uptr2[0x43]);
  *(int *)((intptr_t)self + 0x1684) = *(int *)((intptr_t)self + 0x1684) + 1;
  CS_Leave(value1);
  return 1;
}
