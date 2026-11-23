// Object_InitCompanyBuildingGraphics: ported from Pizza Connection 2 at 0x506330.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x506330
#include "pc2_port.h"

void __thiscall Object_InitCompanyBuildingGraphics(void *self,int arg1)

{
  int value1;
  uint32_t uvalue2;
  uint32_t uvalue3;
  
  if (arg1 == -1) {
    arg1 = *(int *)((intptr_t)self + 0x30);
  }
  switch(arg1) {
  case 0:
    Object_SetCompanyStylePalette(0,1,6,2,5,7,4,0x12);
    value1 = Object_PickWeightedBuildingRecord(self,100,0,0,0,0,0,0,0);
    *(int *)((intptr_t)self + 0xd8) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0,100,0,0,0,0,0,0);
    *(int *)((intptr_t)self + 0xdc) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0,100,0,0,0,0,0,0);
    *(int *)((intptr_t)self + 0xe0) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0x14,10,0x19,10,0x14,10,0,5);
    *(int *)((intptr_t)self + 0xe4) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,5,0,0x1e,10,0x14,10,0x14,5);
    *(int *)((intptr_t)self + 0xe8) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0x3c,0,10,0,0,0x14,10,0);
    uvalue3 = 0;
    *(int *)((intptr_t)self + 0xec) = value1;
    uvalue2 = 100;
    break;
  case 1:
    Object_SetCompanyStylePalette(0,1,2,4,8,6,7,0xd);
    value1 = Object_PickWeightedBuildingRecord(self,100,0,0,0,0,0,0,0);
    *(int *)((intptr_t)self + 0xd8) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0,100,0,0,0,0,0,0);
    *(int *)((intptr_t)self + 0xdc) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0,100,0,0,0,0,0,0);
    *(int *)((intptr_t)self + 0xe0) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,10,0x28,0x14,0,0,0x14,5,5);
    *(int *)((intptr_t)self + 0xe4) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0,10,0x1e,10,5,0x28,5,0);
    *(int *)((intptr_t)self + 0xe8) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0,0,0,0x1e,0x2d,0x14,5,0);
    *(int *)((intptr_t)self + 0xec) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0x14,0,0,0x1e,0x1e,10,10,0);
    *(int *)((intptr_t)self + 0xf0) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0x5a,0,0,5,5,0,0,0);
    *(int *)((intptr_t)self + 0xd4) = value1;
    return;
  case 2:
    Object_SetCompanyStylePalette(0,9,2,8,4,10,0xb,6);
    value1 = Object_PickWeightedBuildingRecord(self,100,0,0,0,0,0,0,0);
    *(int *)((intptr_t)self + 0xd8) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0x32,0x28,0,0,0,10,0,0);
    *(int *)((intptr_t)self + 0xdc) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0,0x50,10,0,0,10,0,0);
    *(int *)((intptr_t)self + 0xe0) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0,0x28,0x14,10,0,5,5,0x14);
    *(int *)((intptr_t)self + 0xe4) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0,0x1e,10,5,0x14,5,10,0x14);
    *(int *)((intptr_t)self + 0xe8) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0,10,0,0x1e,0x1e,0,10,0x14);
    *(int *)((intptr_t)self + 0xec) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0,5,0,0x32,0x1e,0,0,0xf);
    uvalue3 = 10;
    *(int *)((intptr_t)self + 0xf0) = value1;
    uvalue2 = 0x28;
    goto LAB_0050691d;
  case 3:
  case 0x15:
    Object_SetCompanyStylePalette(0,0xc,2,4,8,6,7,0x12);
    value1 = Object_PickWeightedBuildingRecord(self,100,0,0,0,0,0,0,0);
    *(int *)((intptr_t)self + 0xd8) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0,100,0,0,0,0,0,0);
    *(int *)((intptr_t)self + 0xdc) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0,100,0,0,0,0,0,0);
    *(int *)((intptr_t)self + 0xe0) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0x1e,0,0x1e,0,0x14,10,0,10);
    *(int *)((intptr_t)self + 0xe4) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0,100,0,0,0,0,0,0);
    *(int *)((intptr_t)self + 0xe8) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0x14,0,0,0x14,0x1e,0x14,10,0);
    *(int *)((intptr_t)self + 0xec) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0x28,0,0,0x14,0x1e,0,10,0);
    *(int *)((intptr_t)self + 0xf0) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0x5a,0,0,0,5,0,5,0);
    *(int *)((intptr_t)self + 0xd4) = value1;
    return;
  case 4:
    Object_SetCompanyStylePalette(0,10,2,4,8,6,0xd,0x21);
    value1 = Object_PickWeightedBuildingRecord(self,100,0,0,0,0,0,0,0);
    *(int *)((intptr_t)self + 0xd8) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0,100,0,0,0,0,0,0);
    *(int *)((intptr_t)self + 0xdc) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0,100,0,0,0,0,0,0);
    *(int *)((intptr_t)self + 0xe0) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0,0x28,0x14,0,10,0x14,10,0);
    *(int *)((intptr_t)self + 0xe4) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0,0x46,0x14,0,0,0,10,0);
    *(int *)((intptr_t)self + 0xe8) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0,10,0,0x14,0x14,0x14,0,0x1e);
    *(int *)((intptr_t)self + 0xec) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0x14,0,0,10,0x28,0,0,0x1e);
    *(int *)((intptr_t)self + 0xf0) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0x3c,0,0,10,0x1e,0,0,0);
    *(int *)((intptr_t)self + 0xd4) = value1;
    return;
  case 5:
    Object_SetCompanyStylePalette(0,10,2,4,8,0xd,0xc,0x21);
    value1 = Object_PickWeightedBuildingRecord(self,100,0,0,0,0,0,0,0);
    *(int *)((intptr_t)self + 0xd8) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0x3c,0x14,0,0,0,0,0x14,0);
    *(int *)((intptr_t)self + 0xdc) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0,10,0x28,0,0,0x28,10,0);
    *(int *)((intptr_t)self + 0xe0) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0,10,0x28,0,0x14,0x14,10,0);
    *(int *)((intptr_t)self + 0xe4) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0,10,0x32,0,0x1e,0,10,0);
    *(int *)((intptr_t)self + 0xe8) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0,0,0,10,0x14,0,0,0x46);
    *(int *)((intptr_t)self + 0xec) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0,0,0,10,0x28,0,0,0x32);
    uvalue3 = 0x32;
    *(int *)((intptr_t)self + 0xf0) = value1;
    uvalue2 = 0;
LAB_0050691d:
    value1 = Object_PickWeightedBuildingRecord(self,0x32,0,0,uvalue2,uvalue3,0,0,0);
    *(int *)((intptr_t)self + 0xd4) = value1;
    return;
  case 6:
    Object_SetCompanyStylePalette(0,0xd,0x12,2,4,0xb,6,8);
    value1 = Object_PickWeightedBuildingRecord(self,100,0,0,0,0,0,0,0);
    *(int *)((intptr_t)self + 0xd8) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,100,0,0,0,0,0,0,0);
    *(int *)((intptr_t)self + 0xdc) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0,0x14,0x28,0x14,0,0,0x14,0);
    *(int *)((intptr_t)self + 0xe0) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,10,0,0x1e,0x14,0,0x14,0x14,0);
    *(int *)((intptr_t)self + 0xe4) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0,10,0x14,0x14,0x14,10,0x14,0);
    *(int *)((intptr_t)self + 0xe8) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0x14,0,0x14,0,0x14,10,10,0x14);
    uvalue3 = 0x14;
    *(int *)((intptr_t)self + 0xec) = value1;
    uvalue2 = 0x50;
    break;
  case 7:
    Object_SetCompanyStylePalette(0xe,0xb,2,0x12,0x21,0xd,6,8);
    value1 = Object_PickWeightedBuildingRecord(self,100,0,0,0,0,0,0,0);
    *(int *)((intptr_t)self + 0xd8) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,100,0,0,0,0,0,0,0);
    *(int *)((intptr_t)self + 0xdc) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0,0x14,0x1e,0x14,0,10,0x14,0);
    *(int *)((intptr_t)self + 0xe0) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0,0x19,0x14,0xf,0,10,0x14,10);
    *(int *)((intptr_t)self + 0xe4) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0,0x19,0x14,0xf,0,0,0x14,0x14);
    *(int *)((intptr_t)self + 0xe8) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0,0xf,0,0x14,0x14,0,0x19,0x14);
    *(int *)((intptr_t)self + 0xec) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0,0,0,0,0x19,0,0x14,0x37);
    *(int *)((intptr_t)self + 0xf0) = value1;
    value1 = Object_PickWeightedBuildingRecord(self,0x28,0,0,0,0,0,0,0x3c);
    *(int *)((intptr_t)self + 0xd4) = value1;
    return;
  default:
    Object_SetBuildingRecordForAllCompanies(self,0,0);
    return;
  case 10:
  case 0x10:
  case 0x18:
  case 0x19:
  case 0x20:
    Object_SetBuildingRecordForAllCompanies(self,0x19,0);
    return;
  case 0xb:
    Object_SetBuildingRecordForAllCompanies(self,0xe,0);
    return;
  case 0xc:
    Object_SetBuildingRecordForAllCompanies(self,0x13,0);
    return;
  case 0xd:
    Object_SetBuildingRecordForAllCompanies(self,0x11,0);
    return;
  case 0x16:
  case 0x17:
  case 0x1d:
  case 0x1e:
  case 0x1f:
    Object_SetBuildingRecordForAllCompanies(self,0x17,0);
    return;
  }
  value1 = Object_PickWeightedBuildingRecord(self,uvalue2,0,0,0,0,0,0,uvalue3);
  *(int *)((intptr_t)self + 0xf0) = value1;
  value1 = Object_PickWeightedBuildingRecord(self,100,0,0,0,0,0,0,0);
  *(int *)((intptr_t)self + 0xd4) = value1;
  return;
}
