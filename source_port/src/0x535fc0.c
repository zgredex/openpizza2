// FullscreenImage_Load: ported from Pizza Connection 2 at 0x535fc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x535fc0
#include "pc2_port.h"

uint32_t * __thiscall
FullscreenImage_Load
          (void *self,char *arg1,void *arg2,void *arg3,uint32_t *arg4,
          uint8_t *arg5)

{
  char cVar1;
  char *cptr2;
  int value3;
  uint32_t uvalue4;
  uint32_t uvalue5;
  FILE *pFVar6;
  FILE local_104 [8];
  
  *(uint8_t ***)self = &PTR_Window_Delete_0055c814;
  *(uint32_t *)((intptr_t)self + 0x18) = 0;
  *(uint32_t *)((intptr_t)self + 0x14) = 0;
  if (arg4 != (uint32_t *)0x0) {
    *arg4 = 0;
  }
  uvalue4 = 0xffffffff;
  do {
    cptr2 = arg1;
    if (uvalue4 == 0) break;
    uvalue4 = uvalue4 - 1;
    cptr2 = arg1 + 1;
    cVar1 = *arg1;
    arg1 = cptr2;
  } while (cVar1 != '\0');
  uvalue4 = ~uvalue4;
  cptr2 = cptr2 + -uvalue4;
  pFVar6 = local_104;
  for (uvalue5 = uvalue4 >> 2; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
    pFVar6->_ptr = *(char **)cptr2;
    cptr2 = cptr2 + 4;
    pFVar6 = (FILE *)&pFVar6->_cnt;
  }
  for (uvalue4 = uvalue4 & 3; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
    *(char *)&pFVar6->_ptr = *cptr2;
    cptr2 = cptr2 + 1;
    pFVar6 = (FILE *)((intptr_t)&pFVar6->_ptr + 1);
  }
  CRT_Strupr((uint32_t *)local_104);
  cptr2 = _strstr((char *)local_104,&DAT_00574688);
  if (cptr2 == (char *)0x0) {
    cptr2 = _strstr((char *)local_104,&DAT_00574680);
    if (cptr2 == (char *)0x0) {
      cptr2 = _strstr((char *)local_104,&DAT_00574678);
      if (cptr2 == (char *)0x0) goto LAB_005360d1;
      value3 = FullscreenImage_LoadBmp(self,arg2,local_104,arg3,arg5);
    }
    else {
      value3 = FullscreenImage_LoadPCX(self,(intptr_t)arg2,(char *)local_104,arg3);
    }
  }
  else {
    value3 = FullscreenImage_LoadTGA(self,(intptr_t)arg2,(char *)local_104,arg3,arg5);
  }
  if (value3 != 0) {
    if ((*(char *)((intptr_t)self + 0x11) == '\x02') && (arg2 != (void *)0x0)) {
      Color_Convert555To565
                (arg2,*(uint16_t **)((intptr_t)self + 0x18),
                 *(int *)((intptr_t)self + 8) * *(int *)((intptr_t)self + 4));
    }
    return self;
  }
LAB_005360d1:
  if (arg4 == (uint32_t *)0x0) {
    NoOp_Stub();
    return self;
  }
  *arg4 = 0x1f5;
  return self;
}
