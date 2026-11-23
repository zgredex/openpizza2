// Sound_UpdateCityAmbience: ported from Pizza Connection 2 at 0x548780.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x548780
#include "pc2_port.h"

void __thiscall Sound_UpdateCityAmbience(void *self,int arg1,int arg2)

{
  bool flag1;
  float fVar2;
  int *ptr3;
  int value4;
  int *ptr5;
  int value6;
  int *ptr7;
  int64_t lvalue8;
  float local_108;
  uint8_t local_104 [260];
  
  if (*(char *)((intptr_t)self + 0xfc) == '\0') {
    return;
  }
  if (0 < *(int *)((intptr_t)self + 0x154)) {
    *(int *)((intptr_t)self + 0x154) = *(int *)((intptr_t)self + 0x154) + -1;
  }
  if (0 < *(int *)((intptr_t)self + 0x15c)) {
    *(int *)((intptr_t)self + 0x15c) = *(int *)((intptr_t)self + 0x15c) + -1;
  }
  if (0 < *(int *)((intptr_t)self + 0x158)) {
    *(int *)((intptr_t)self + 0x158) = *(int *)((intptr_t)self + 0x158) + -1;
  }
  flag1 = true;
  if (0 < *(int *)((intptr_t)self + 0x150)) {
    value4 = *(int *)((intptr_t)self + 0x150) + -1;
    *(int *)((intptr_t)self + 0x150) = value4;
    if (value4 == 0) {
      *(uint32_t *)((intptr_t)self + 0x18) = 1000;
    }
    else {
      *(uint32_t *)((intptr_t)self + 0x18) = 0x3ec;
    }
    flag1 = false;
  }
  if (*(char *)((intptr_t)self + 0x169) == '\0') {
    *(uint32_t *)((intptr_t)self + 0x1c) = 1000;
    return;
  }
  Sound_UpdateProximityGain(self);
  if (flag1) {
    if ((arg1 < 0x13) || (0x17 < arg1)) {
      if ((arg1 < 6) || (9 < arg1)) {
        *(uint32_t *)((intptr_t)self + 0x18) = 0x3e9;
        *(uint8_t *)((intptr_t)self + 0x168) = 0;
        goto LAB_0054885e;
      }
      value4 = 0x3eb;
    }
    else {
      value4 = 0x3ea;
    }
    if (*(int *)((intptr_t)self + 0x18) != value4) {
      *(uint8_t *)((intptr_t)self + 0x168) = 1;
    }
    *(int *)((intptr_t)self + 0x18) = value4;
  }
LAB_0054885e:
  value4 = *(int *)((intptr_t)self + 0x18);
  if (value4 == *(int *)((intptr_t)self + 0x1c)) goto LAB_005488a8;
  if (value4 == 0x3ec) {
    value4 = 0x3ec;
LAB_0054889b:
    Sound_SetMusicTrack(self,value4);
  }
  else if (*(char *)((intptr_t)self + 0x168) == '\0') {
    if (*(int *)((intptr_t)self + 0x144) == 3) goto LAB_0054889b;
  }
  else {
    Sound_SetMusicTrack(self,value4);
    *(uint8_t *)((intptr_t)self + 0x168) = 0;
  }
  *(uint32_t *)((intptr_t)self + 0x1c) = *(uint32_t *)((intptr_t)self + 0x18);
LAB_005488a8:
  if (0 < *(int *)((intptr_t)self + 0x14c)) {
    *(int *)((intptr_t)self + 0x14c) = *(int *)((intptr_t)self + 0x14c) + -1;
    return;
  }
  fVar2 = (float)arg2 * 0.016666668;
  ptr3 = &DAT_0057529c;
  while (ptr5 = ptr3, ptr5 != (int *)&DAT_005752d8) {
    ptr7 = ptr5 + -3;
    flag1 = false;
    if (((ptr5[-3] <= arg1) && (arg1 <= *ptr5 + -1)) ||
       (ptr3 = ptr5 + 3, &DAT_005752e4 <= ptr5 + 3)) goto LAB_0054890c;
  }
  ptr7 = &DAT_005752cc;
  ptr5 = &DAT_00575290;
  flag1 = true;
LAB_0054890c:
  if (1.0 < fVar2) {
    fVar2 = 1.0;
  }
  value4 = *ptr7;
  if (flag1) {
    value6 = (*ptr5 - value4) + 0x18;
  }
  else {
    value6 = *ptr5 - value4;
  }
  local_108 = (((float)ptr5[2] - (float)ptr7[2]) * ((fVar2 + (float)arg1) - (float)value4)) /
              (float)value6 + (float)ptr7[2];
  if (1.0 < local_108) {
    local_108 = 1.0;
  }
  *(float *)((intptr_t)self + 0x148) = local_108;
  lvalue8 = __ftol();
  *(int *)((intptr_t)self + 0x14c) = (intptr_t)lvalue8 + ptr7[1];
  value4 = Random_Range((void *)((intptr_t)self + 4),0,0xf);
  String_Format(local_104,(uint8_t *)s_Sfx__s_00576108,(&PTR_s_Sfx_City_Lkw_Pass1_wav_00575250)[value4])
  ;
  Sound_PlayChannel(self,local_104,1);
  return;
}
