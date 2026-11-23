// CRT_Filebuf_Open: ported from Pizza Connection 2 at 0x54d950.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54d950
#include "pc2_port.h"

int * __thiscall CRT_Filebuf_Open(void *self,LPCSTR arg1,uint32_t arg2,uint32_t arg3)

{
  void *pvVar1;
  int value2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  uint32_t uvalue5;
  
  if (*(int *)((intptr_t)self + 0x4c) != -1) {
    return (int *)0x0;
  }
  uvalue4 = (-(uint32_t)((arg2 & 0x80) != 0) & 0x4000) + 0x4000;
  if ((arg2 & 0x20) == 0) {
    uvalue4 = uvalue4 | 0x100;
  }
  uvalue5 = 0x40;
  if ((arg2 & 0x40) != 0) {
    uvalue4 = uvalue4 | 0x400;
  }
  if ((arg2 & 8) != 0) {
    arg2 = arg2 | 2;
    uvalue4 = uvalue4 | 8;
  }
  if ((arg2 & 0x10) != 0) {
    arg2 = arg2 | 2;
    uvalue4 = uvalue4 | 0x200;
  }
  if ((arg2 & 2) == 0) {
    if ((arg2 & 1) == 0) {
      return (int *)0x0;
    }
  }
  else {
    if ((arg2 & 1) == 0) {
      uvalue4 = uvalue4 | 1;
    }
    else {
      uvalue4 = uvalue4 | 2;
    }
    if ((arg2 & 0x4d) == 0) {
      arg2 = arg2 | 0x10;
      uvalue4 = uvalue4 | 0x200;
    }
  }
  uvalue3 = arg3 & 0xe00;
  if (uvalue3 != 0) {
    if (uvalue3 == 0x800) {
      uvalue5 = 0x10;
    }
    else if (uvalue3 == 0xa00) {
      uvalue5 = 0x20;
    }
    else if (uvalue3 == 0xc00) {
      uvalue5 = 0x30;
    }
    else if (uvalue3 == 0xe00) {
      uvalue5 = 0x40;
    }
  }
  uvalue4 = CRT_Sopen(arg1,uvalue4,uvalue5,0x180);
  *(uint32_t *)((intptr_t)self + 0x4c) = uvalue4;
  if (uvalue4 != 0xffffffff) {
    if (*(int *)((intptr_t)self + 0x30) < 0) {
      CS_EnterRaw((LPCRITICAL_SECTION)((intptr_t)self + 0x34));
    }
    *(uint32_t *)((intptr_t)self + 0x50) = 1;
    if ((*(int *)((intptr_t)self + 8) == 0) && (*(int *)((intptr_t)self + 0x14) == 0)) {
      pvVar1 = operator_new(0x200);
      if (pvVar1 == (void *)0x0) {
        *(uint32_t *)((intptr_t)self + 8) = 1;
      }
      else {
        Stream_AttachBuffer(self,pvVar1,(intptr_t)pvVar1 + 0x200,1);
      }
    }
    if (((arg2 & 4) == 0) ||
       (value2 = (**(code **)(*(int *)self + 0xc))(0,2,arg2), value2 != -1)) {
      if (*(int *)((intptr_t)self + 0x30) < 0) {
        CS_LeaveRaw((LPCRITICAL_SECTION)((intptr_t)self + 0x34));
      }
      return self;
    }
    CRT_Filebuf_Close(self);
    if (*(int *)((intptr_t)self + 0x30) < 0) {
      CS_LeaveRaw((LPCRITICAL_SECTION)((intptr_t)self + 0x34));
    }
  }
  return (int *)0x0;
}
