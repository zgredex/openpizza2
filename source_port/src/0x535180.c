// Font_Load: ported from Pizza Connection 2 at 0x535180.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x535180
#include "pc2_port.h"

char * __thiscall
Font_Load(void *self,uint32_t arg1,void *arg2,LPCSTR arg3,uint32_t *arg4)

{
  uint32_t *uptr1;
  short svalue2;
  FILE *pFVar3;
  uint8_t *bptr4;
  short *psVar5;
  char *cptr6;
  int *ptr7;
  short *psVar8;
  int value9;
  uint32_t local_4;
  
  local_4 = 0;
  if (arg4 != (uint32_t *)0x0) {
    *arg4 = 0;
  }
  *(uint32_t *)((intptr_t)self + 0x460) = 0;
  if (arg2 == (void *)0x0) {
    pFVar3 = (FILE *)CRT_Fopen(arg3,&DAT_00563184);
    if (pFVar3 == (FILE *)0x0) {
      if (arg4 == (uint32_t *)0x0) {
        NoOp_Stub();
        return self;
      }
      *arg4 = 0x321;
      return self;
    }
    Set_Field9B8(self,0xffffff);
    CRT_FreadLocked(self,1,0xe0,(int *)pFVar3);
    bptr4 = (uint8_t *)((intptr_t)self + 0xe0);
    CRT_FreadLocked((char *)bptr4,1,0xe0,(int *)pFVar3);
    do {
      if ((0x80 < bptr4[-0xe0]) || (0x80 < *bptr4)) {
        if (arg4 == (uint32_t *)0x0) {
          NoOp_Stub();
          return self;
        }
        *arg4 = 0x321;
        return self;
      }
      bptr4 = bptr4 + 1;
    } while ((intptr_t)(bptr4 + (-0xe0 - (intptr_t)self)) < 0xe0);
    CRT_FreadLocked((char *)((intptr_t)self + 0x2a0),1,0xe0,(int *)pFVar3);
    CRT_FreadLocked((char *)((intptr_t)self + 0x380),1,0xe0,(int *)pFVar3);
    psVar8 = (short *)((intptr_t)self + 0x7e0);
    CRT_FreadLocked((char *)psVar8,1,0x1c0,(int *)pFVar3);
    CRT_FreadLocked((char *)((intptr_t)self + 0x1c0),1,0xe0,(int *)pFVar3);
    uptr1 = (uint32_t *)((intptr_t)self + 0x9b0);
    CRT_FreadLocked((char *)uptr1,1,4,(int *)pFVar3);
    *(int *)((intptr_t)self + 0x9b4) = (intptr_t)*uptr1 >> 0x10;
    *uptr1 = *uptr1 & 0xffff;
    value9 = 0xe0;
    psVar5 = psVar8;
    do {
      svalue2 = *psVar5;
      psVar5 = psVar5 + 1;
      local_4 = local_4 + (intptr_t)svalue2;
      value9 = value9 + -1;
    } while (value9 != 0);
    cptr6 = operator_new(local_4);
    *(char **)((intptr_t)self + 0x460) = cptr6;
    CRT_FreadLocked(cptr6,1,local_4,(int *)pFVar3);
    CRT_Fclose(pFVar3);
    ptr7 = (int *)((intptr_t)self + 0x464);
    value9 = 0xdf;
    do {
      svalue2 = *psVar8;
      psVar8 = psVar8 + 1;
      *ptr7 = ptr7[-1] + (intptr_t)svalue2;
      ptr7 = ptr7 + 1;
      value9 = value9 + -1;
    } while (value9 != 0);
    value9 = *(int *)((intptr_t)self + 0x9b4);
  }
  else {
    ptr7 = Resource_Open(arg2,arg3,0);
    if (ptr7 == (int *)0x0) {
      if (arg4 != (uint32_t *)0x0) {
        *arg4 = 0x321;
        return self;
      }
      NoOp_Stub();
    }
    Set_Field9B8(self,0xffffff);
    Resource_Read(arg2,self,0xe0,(intptr_t)ptr7);
    Resource_Read(arg2,(char *)((intptr_t)self + 0xe0),0xe0,(intptr_t)ptr7);
    Resource_Read(arg2,(char *)((intptr_t)self + 0x2a0),0xe0,(intptr_t)ptr7);
    Resource_Read(arg2,(char *)((intptr_t)self + 0x380),0xe0,(intptr_t)ptr7);
    Resource_Read(arg2,(char *)((intptr_t)self + 0x7e0),0x1c0,(intptr_t)ptr7);
    Resource_Read(arg2,(char *)((intptr_t)self + 0x1c0),0xe0,(intptr_t)ptr7);
    uptr1 = (uint32_t *)((intptr_t)self + 0x9b0);
    Resource_Read(arg2,(char *)uptr1,4,(intptr_t)ptr7);
    *(int *)((intptr_t)self + 0x9b4) = (intptr_t)*uptr1 >> 0x10;
    *uptr1 = *uptr1 & 0xffff;
    psVar8 = (short *)((intptr_t)self + 0x7e0);
    value9 = 0xe0;
    do {
      svalue2 = *psVar8;
      psVar8 = psVar8 + 1;
      local_4 = local_4 + (intptr_t)svalue2;
      value9 = value9 + -1;
    } while (value9 != 0);
    cptr6 = operator_new(local_4);
    *(char **)((intptr_t)self + 0x460) = cptr6;
    Resource_Read(arg2,cptr6,local_4,(intptr_t)ptr7);
    Resource_Close(arg2,(intptr_t)ptr7);
    ptr7 = (int *)((intptr_t)self + 0x464);
    psVar8 = (short *)((intptr_t)self + 0x7e0);
    value9 = 0xdf;
    do {
      svalue2 = *psVar8;
      psVar8 = psVar8 + 1;
      *ptr7 = ptr7[-1] + (intptr_t)svalue2;
      ptr7 = ptr7 + 1;
      value9 = value9 + -1;
    } while (value9 != 0);
    value9 = *(int *)((intptr_t)self + 0x9b4);
  }
  if (value9 == 0) {
    *(uint32_t *)((intptr_t)self + 0x9b4) =
         (uint32_t)*(uint8_t *)((intptr_t)self + 0x3a9) + (uint32_t)*(uint8_t *)((intptr_t)self + 0x109);
  }
  return self;
}
