// Employee_GetProfessionName: ported from Pizza Connection 2 at 0x549300.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x549300
#include "pc2_port.h"

uint8_t ** __thiscall
Employee_GetProfessionName(void *self,uint32_t arg1,int arg2,uint32_t *arg3)

{
  int value1;
  uint8_t *uptr2;
  
  if (arg2 == 0) {
    switch(arg1) {
    case 0:
      if (arg3 != (uint32_t *)0x0) {
        value1 = *(int *)((intptr_t)self + 0x1dc);
        if (value1 == 2) {
          *(uint32_t *)((intptr_t)self + 0x1dc) = 1;
        }
        else {
          *(int *)((intptr_t)self + 0x1dc) = value1 + 1;
        }
        if ((value1 == 1) || (uptr2 = &DAT_005762b4, value1 != 2)) {
          uptr2 = &DAT_005762b0;
        }
        *arg3 = uptr2;
      }
      return (uint8_t **)&DAT_005762a8;
    case 1:
      if (arg3 != (uint32_t *)0x0) {
        value1 = *(int *)((intptr_t)self + 0x1e0);
        if (value1 == 2) {
          *(uint32_t *)((intptr_t)self + 0x1e0) = 1;
        }
        else {
          *(int *)((intptr_t)self + 0x1e0) = value1 + 1;
        }
        if ((value1 == 1) || (uptr2 = &DAT_005762b4, value1 != 2)) {
          uptr2 = &DAT_005762b0;
        }
        *arg3 = uptr2;
      }
      return (uint8_t **)s_Teens_005762a0;
    case 2:
      if (arg3 != (uint32_t *)0x0) {
        value1 = *(int *)((intptr_t)self + 0x1e4);
        if (value1 == 2) {
          *(uint32_t *)((intptr_t)self + 0x1e4) = 1;
        }
        else {
          *(int *)((intptr_t)self + 0x1e4) = value1 + 1;
        }
        if ((value1 == 1) || (uptr2 = &DAT_005762b4, value1 != 2)) {
          uptr2 = &DAT_005762b0;
        }
        *arg3 = uptr2;
      }
      return (uint8_t **)s_Studies_00576298;
    case 3:
      if (arg3 != (uint32_t *)0x0) {
        value1 = *(int *)((intptr_t)self + 0x1e8);
        if (value1 == 2) {
          *(uint32_t *)((intptr_t)self + 0x1e8) = 1;
        }
        else {
          *(int *)((intptr_t)self + 0x1e8) = value1 + 1;
        }
        if ((value1 == 1) || (uptr2 = &DAT_005762b4, value1 != 2)) {
          uptr2 = &DAT_005762b0;
        }
        *arg3 = uptr2;
      }
      return (uint8_t **)s_Prolls_00576290;
    case 4:
      if (arg3 != (uint32_t *)0x0) {
        value1 = *(int *)((intptr_t)self + 0x1ec);
        if (value1 == 2) {
          *(uint32_t *)((intptr_t)self + 0x1ec) = 1;
        }
        else {
          *(int *)((intptr_t)self + 0x1ec) = value1 + 1;
        }
        if ((value1 == 1) || (uptr2 = &DAT_005762b4, value1 != 2)) {
          uptr2 = &DAT_005762b0;
        }
        *arg3 = uptr2;
      }
      return (uint8_t **)s_Yuppie_00576288;
    case 5:
      if (arg3 != (uint32_t *)0x0) {
        value1 = *(int *)((intptr_t)self + 0x1f0);
        if (value1 == 2) {
          *(uint32_t *)((intptr_t)self + 0x1f0) = 1;
        }
        else {
          *(int *)((intptr_t)self + 0x1f0) = value1 + 1;
        }
        if ((value1 == 1) || (uptr2 = &DAT_005762b4, value1 != 2)) {
          uptr2 = &DAT_005762b0;
        }
        *arg3 = uptr2;
      }
      return (uint8_t **)s_Bonzen_00576280;
    case 6:
      if (arg3 != (uint32_t *)0x0) {
        value1 = *(int *)((intptr_t)self + 500);
        if (value1 == 2) {
          *(uint32_t *)((intptr_t)self + 500) = 1;
        }
        else {
          *(int *)((intptr_t)self + 500) = value1 + 1;
        }
        if ((value1 == 1) || (uptr2 = &DAT_005762b4, value1 != 2)) {
          uptr2 = &DAT_005762b0;
        }
        *arg3 = uptr2;
      }
      return (uint8_t **)s_Grufties_00576274;
    case 7:
      if (arg3 != (uint32_t *)0x0) {
        value1 = *(int *)((intptr_t)self + 0x1f8);
        if (value1 == 2) {
          *(uint32_t *)((intptr_t)self + 0x1f8) = 1;
        }
        else {
          *(int *)((intptr_t)self + 0x1f8) = value1 + 1;
        }
        if ((value1 == 1) || (uptr2 = &DAT_005762b4, value1 != 2)) {
          uptr2 = &DAT_005762b0;
        }
        *arg3 = uptr2;
      }
      return (uint8_t **)s_Touris_0057626c;
    case 0xb:
      if (arg3 != (uint32_t *)0x0) {
        if ((*(int *)((intptr_t)self + 0x230) == 1) ||
           (uptr2 = &DAT_005762b4, *(int *)((intptr_t)self + 0x230) != 2)) {
          uptr2 = &DAT_005762b0;
        }
        *arg3 = uptr2;
      }
      return (uint8_t **)s_Fatman_00576260;
    case 0xf:
    case 0x21:
      if (arg3 != (uint32_t *)0x0) {
        value1 = *(int *)((intptr_t)self + 0x22c);
        if (value1 == 2) {
          *(uint32_t *)((intptr_t)self + 0x22c) = 1;
        }
        else {
          *(int *)((intptr_t)self + 0x22c) = value1 + 1;
        }
        if ((value1 == 1) || (uptr2 = &DAT_005762b4, value1 != 2)) {
          uptr2 = &DAT_005762b0;
        }
        *arg3 = uptr2;
      }
      return &PTR_BYTE_00576268;
    case 0x16:
      if (arg3 != (uint32_t *)0x0) {
        value1 = *(int *)((intptr_t)self + 0x21c);
        if (value1 == 2) {
          *(uint32_t *)((intptr_t)self + 0x21c) = 1;
        }
        else {
          *(int *)((intptr_t)self + 0x21c) = value1 + 1;
        }
        if ((value1 == 1) || (uptr2 = &DAT_005762b4, value1 != 2)) {
          uptr2 = &DAT_005762b0;
        }
        *arg3 = uptr2;
      }
      return (uint8_t **)&DAT_00576250;
    case 0x1f:
      if (arg3 != (uint32_t *)0x0) {
        value1 = *(int *)((intptr_t)self + 0x218);
        if (value1 == 2) {
          *(uint32_t *)((intptr_t)self + 0x218) = 1;
        }
        else {
          *(int *)((intptr_t)self + 0x218) = value1 + 1;
        }
        if ((value1 == 1) || (uptr2 = &DAT_005762b4, value1 != 2)) {
          uptr2 = &DAT_005762b0;
        }
        *arg3 = uptr2;
      }
      return (uint8_t **)s_Kurier_00576258;
    case 0x22:
      if (arg3 != (uint32_t *)0x0) {
        if ((*(int *)((intptr_t)self + 0x23c) == 1) ||
           (uptr2 = &DAT_005762b4, *(int *)((intptr_t)self + 0x23c) != 2)) {
          uptr2 = &DAT_005762b0;
        }
        *arg3 = uptr2;
      }
      return (uint8_t **)s_Junge_00576248;
    }
  }
  else if (arg2 != 1) goto switchD_0054967f_default;
  switch(arg1) {
  case 0x11:
    if (arg3 != (uint32_t *)0x0) {
      if ((*(int *)((intptr_t)self + 0x1fc) == 1) ||
         (uptr2 = &DAT_005762b4, *(int *)((intptr_t)self + 0x1fc) != 2)) {
        uptr2 = &DAT_005762b0;
      }
      *arg3 = uptr2;
    }
    return (uint8_t **)&DAT_00576240;
  case 0x12:
    if (arg3 != (uint32_t *)0x0) {
      uptr2 = Employee_NextSpriteVariant(self,10,1,1);
      *arg3 = uptr2;
    }
    return (uint8_t **)s_Manager_005725c0;
  case 0x13:
    if (arg3 != (uint32_t *)0x0) {
      if ((*(int *)((intptr_t)self + 0x200) == 1) ||
         (uptr2 = &DAT_005762b4, *(int *)((intptr_t)self + 0x200) != 2)) {
        uptr2 = &DAT_005762b0;
      }
      *arg3 = uptr2;
    }
    return (uint8_t **)s_Servicek_00576234;
  case 0x14:
    if (arg3 != (uint32_t *)0x0) {
      uptr2 = Employee_NextSpriteVariant(self,0xb,1,1);
      *arg3 = uptr2;
    }
    return (uint8_t **)s_Laufbursche_00576228;
  }
switchD_0054967f_default:
  if ((arg2 == 0) || (arg2 == 2)) {
    switch(arg1) {
    case 0xd:
      if (arg3 != (uint32_t *)0x0) {
        uptr2 = Employee_NextSpriteVariant(self,0x11,1,1);
        *arg3 = uptr2;
      }
      return (uint8_t **)s_Polizei_00576200;
    case 0x17:
      if (arg3 != (uint32_t *)0x0) {
        uptr2 = Employee_NextSpriteVariant(self,0xc,1,2);
        *arg3 = uptr2;
      }
      return (uint8_t **)s_Wache_00576220;
    case 0x1d:
      if (arg3 != (uint32_t *)0x0) {
        uptr2 = Employee_NextSpriteVariant(self,0xe,1,2);
        *arg3 = uptr2;
      }
      return (uint8_t **)s_Gaengster_00576208;
    case 0x1e:
      if (arg3 != (uint32_t *)0x0) {
        uptr2 = Employee_NextSpriteVariant(self,0xd,1,2);
        *arg3 = uptr2;
      }
      return (uint8_t **)s_Schlaeger_00576214;
    }
  }
  if ((arg2 == 0) || (arg2 == 3)) {
    switch(arg1) {
    case 10:
      if (arg3 != (uint32_t *)0x0) {
        uptr2 = Employee_NextSpriteVariant(self,0x12,1,1);
        *arg3 = uptr2;
      }
      return (uint8_t **)s_Beamter_005761f8;
    case 0xe:
      if (arg3 != (uint32_t *)0x0) {
        uptr2 = Employee_NextSpriteVariant(self,0x17,1,1);
        *arg3 = uptr2;
      }
      return (uint8_t **)s_Reinigungst_005761d4;
    case 0x18:
      if (arg3 != (uint32_t *)0x0) {
        uptr2 = Employee_NextSpriteVariant(self,0x13,1,1);
        *arg3 = uptr2;
      }
      return (uint8_t **)s_Buergerm_005761ec;
    case 0x20:
      if (arg3 != (uint32_t *)0x0) {
        uptr2 = Employee_NextSpriteVariant(self,0x16,1,1);
        *arg3 = uptr2;
      }
      return (uint8_t **)s_Kammerjae_005761e0;
    }
  }
  return (uint8_t **)0x0;
}
