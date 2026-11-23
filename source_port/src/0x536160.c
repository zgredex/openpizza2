// FullscreenImage_LoadBmp: ported from Pizza Connection 2 at 0x536160.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x536160
#include "pc2_port.h"

uint32_t __thiscall
FullscreenImage_LoadBmp
          (void *self,uint32_t arg1,FILE *arg2,void *arg3,uint8_t *arg4)

{
  char **ppcVar1;
  char *cptr2;
  int value3;
  uint32_t uvalue4;
  uint32_t uvalue5;
  char *cptr6;
  FILE *pFVar7;
  char *cptr8;
  int value9;
  short local_38 [9];
  uint32_t local_26;
  uint32_t local_22;
  short local_1c;
  int local_1a;
  
  uvalue4 = 0xffffffff;
  cptr2 = (char *)((intptr_t)self + 0x1c);
  do {
    pFVar7 = arg2;
    if (uvalue4 == 0) break;
    uvalue4 = uvalue4 - 1;
    pFVar7 = (FILE *)((intptr_t)&arg2->_ptr + 1);
    ppcVar1 = &arg2->_ptr;
    arg2 = pFVar7;
  } while (*(char *)ppcVar1 != '\0');
  uvalue4 = ~uvalue4;
  cptr6 = (char *)((intptr_t)pFVar7 - uvalue4);
  cptr8 = cptr2;
  for (uvalue5 = uvalue4 >> 2; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
    *(uint32_t *)cptr8 = *(uint32_t *)cptr6;
    cptr6 = cptr6 + 4;
    cptr8 = cptr8 + 4;
  }
  for (uvalue4 = uvalue4 & 3; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
    *cptr8 = *cptr6;
    cptr6 = cptr6 + 1;
    cptr8 = cptr8 + 1;
  }
  if (arg3 == (void *)0x0) {
    arg2 = (FILE *)CRT_Fopen(cptr2,&DAT_00563184);
    if (arg2 == (FILE *)0x0) {
      return 0;
    }
    CRT_FreadLocked((char *)local_38,1,0x36,(int *)arg2);
  }
  else {
    arg2 = (FILE *)Resource_Open(arg3,cptr2,0);
    if (arg2 == (FILE *)0x0) {
      return 0;
    }
    Resource_Read(arg3,(char *)local_38,0x36,(intptr_t)arg2);
  }
  if (local_38[0] != 0x4d42) {
    if (arg3 == (void *)0x0) {
      CRT_Fclose(arg2);
    }
    else {
      Resource_Close(arg3,(intptr_t)arg2);
    }
  }
  *(uint32_t *)((intptr_t)self + 4) = local_26;
  *(uint32_t *)((intptr_t)self + 8) = local_22;
  *(uint8_t *)((intptr_t)self + 0x10) = (uint8_t)local_1c;
  if ((uint8_t)local_1c < 9) {
    *(uint8_t *)((intptr_t)self + 0x11) = 1;
  }
  else if ((uint8_t)local_1c < 0x11) {
    *(uint8_t *)((intptr_t)self + 0x11) = 2;
  }
  else if ((uint8_t)local_1c < 0x19) {
    *(uint8_t *)((intptr_t)self + 0x11) = 3;
  }
  else {
    *(uint8_t *)((intptr_t)self + 0x11) = 4;
  }
  if (arg4 != (uint8_t *)0x0) {
    (*(code *)arg4)(local_22);
  }
  uvalue4 = (uint32_t)*(uint8_t *)((intptr_t)self + 0x11) * *(int *)((intptr_t)self + 8) * *(int *)((intptr_t)self + 4);
  *(uint32_t *)((intptr_t)self + 0xc) = uvalue4;
  cptr2 = operator_new(uvalue4);
  *(char **)((intptr_t)self + 0x18) = cptr2;
  if ((local_1a == 0) && (local_1c == 0x18)) {
    if (arg3 == (void *)0x0) {
      CRT_FreadLocked(cptr2,1,*(uint32_t *)((intptr_t)self + 0xc),(int *)arg2);
      goto LAB_00536325;
    }
    value3 = *(int *)((intptr_t)self + 8);
    uvalue4 = -(*(int *)((intptr_t)self + 4) * 3 & 3U) & 3;
    value9 = 0;
    if (0 < value3) {
      do {
        Resource_Read(arg3,cptr2 + ((value3 - value9) + -1) * *(int *)((intptr_t)self + 4) * 3,
                      *(int *)((intptr_t)self + 4) * 3,(intptr_t)arg2);
        if (uvalue4 != 0) {
          Stream_Seek(uvalue4,(intptr_t)arg2,1);
        }
        value3 = *(int *)((intptr_t)self + 8);
        value9 = value9 + 1;
      } while (value9 < value3);
    }
  }
  if (arg3 != (void *)0x0) {
    Resource_Close(arg3,(intptr_t)arg2);
    return 1;
  }
LAB_00536325:
  CRT_Fclose(arg2);
  return 1;
}
