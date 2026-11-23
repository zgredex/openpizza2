// SoundSample_ReadADPCM: ported from Pizza Connection 2 at 0x53f8e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53f8e0
#include "pc2_port.h"

int __thiscall SoundSample_ReadADPCM(void *self,uint32_t *arg1,uint32_t arg2)

{
  short *psVar1;
  uint32_t uvalue2;
  uint32_t uvalue3;
  uint32_t *uptr4;
  uint32_t uvalue5;
  uint32_t uvalue6;
  uint32_t *uptr7;
  int local_810;
  uint32_t *local_80c;
  uint32_t local_808;
  short local_800;
  uint8_t local_7fe;
  uint16_t local_7fc;
  uint8_t local_7fa;
  char local_7f8 [2040];
  
  uvalue2 = (uint32_t)*(uint16_t *)((intptr_t)self + 0x20);
  local_80c = arg1;
  uvalue5 = uvalue2 * 4 + (uint32_t)*(uint16_t *)((intptr_t)self + 0x16) * -0xe;
  local_808 = arg2;
  if (*(uint32_t *)((intptr_t)self + 0x30) % uvalue5 != 0) {
    if (*(char *)((intptr_t)self + 0x48) != '\0') {
      uvalue6 = uvalue2 + (uint32_t)*(uint16_t *)((intptr_t)self + 0x16) * -4;
      uvalue2 = SoundPakStream_Read(*(void **)((intptr_t)self + 8),(char *)&local_800,uvalue2,
                                  *(int *)((intptr_t)self + 0xc));
      if (uvalue2 < *(uint16_t *)((intptr_t)self + 0x20)) {
        NoOp_Stub();
        return -0x7fffbffb;
      }
      psVar1 = (short *)((intptr_t)self + 0x40);
      *(uint8_t *)((intptr_t)self + 0x42) = local_7fe;
      *psVar1 = local_800;
      **(short **)((intptr_t)self + 0x3c) = local_800;
      if (*(short *)((intptr_t)self + 0x16) == 2) {
        *(uint16_t *)((intptr_t)self + 0x44) = local_7fc;
        *(uint8_t *)((intptr_t)self + 0x46) = local_7fa;
        *(uint16_t *)(*(int *)((intptr_t)self + 0x3c) + 2) = local_7fc;
        Sound_ADPCMDecode(local_7f8,(uint16_t *)(*(int *)((intptr_t)self + 0x3c) + 4),uvalue6,psVar1);
      }
      else {
        Sound_DecodeADPCM((char *)&local_7fc,(short *)(*(int *)((intptr_t)self + 0x3c) + 2),uvalue6,psVar1)
        ;
      }
    }
    uvalue6 = *(uint32_t *)((intptr_t)self + 0x30) % uvalue5;
    uvalue2 = uvalue5 - uvalue6;
    if (arg2 < uvalue2) {
      uvalue2 = arg2;
    }
    local_808 = arg2 - uvalue2;
    uptr4 = (uint32_t *)(*(int *)((intptr_t)self + 0x3c) + uvalue6);
    uptr7 = arg1;
    for (uvalue3 = uvalue2 >> 2; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
      *uptr7 = *uptr4;
      uptr4 = uptr4 + 1;
      uptr7 = uptr7 + 1;
    }
    for (uvalue6 = uvalue2 & 3; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
      *(uint8_t *)uptr7 = *(uint8_t *)uptr4;
      uptr4 = (uint32_t *)((intptr_t)uptr4 + 1);
      uptr7 = (uint32_t *)((intptr_t)uptr7 + 1);
    }
    local_80c = (uint32_t *)(uvalue2 + (intptr_t)arg1);
    *(uint32_t *)((intptr_t)self + 0x30) = *(int *)((intptr_t)self + 0x30) + uvalue2;
  }
  local_810 = 0;
  *(uint8_t *)((intptr_t)self + 0x48) = 0;
  uvalue2 = local_808;
  do {
    while( true ) {
      if (local_808 == 0) {
        return local_810;
      }
      if (*(uint32_t *)((intptr_t)self + 0x28) <= *(uint32_t *)((intptr_t)self + 0x30)) break;
      uvalue3 = (uint32_t)*(uint16_t *)((intptr_t)self + 0x20) + (uint32_t)*(uint16_t *)((intptr_t)self + 0x16) * -4;
      uvalue6 = SoundPakStream_Read(*(void **)((intptr_t)self + 8),(char *)&local_800,
                                  (uint32_t)*(uint16_t *)((intptr_t)self + 0x20),*(int *)((intptr_t)self + 0xc));
      if (uvalue6 < *(uint16_t *)((intptr_t)self + 0x20)) {
        NoOp_Stub();
        return -0x7fffbffb;
      }
      psVar1 = (short *)((intptr_t)self + 0x40);
      *(uint8_t *)((intptr_t)self + 0x42) = local_7fe;
      *psVar1 = local_800;
      **(short **)((intptr_t)self + 0x3c) = local_800;
      if (*(short *)((intptr_t)self + 0x16) == 2) {
        *(uint16_t *)((intptr_t)self + 0x44) = local_7fc;
        *(uint8_t *)((intptr_t)self + 0x46) = local_7fa;
        *(uint16_t *)(*(int *)((intptr_t)self + 0x3c) + 2) = local_7fc;
        Sound_ADPCMDecode(local_7f8,(uint16_t *)(*(int *)((intptr_t)self + 0x3c) + 4),uvalue3,psVar1);
      }
      else {
        Sound_DecodeADPCM((char *)&local_7fc,(short *)(*(int *)((intptr_t)self + 0x3c) + 2),uvalue3,psVar1)
        ;
        uvalue2 = local_808;
      }
      local_810 = 0;
      uvalue6 = uvalue5;
      if (uvalue2 <= uvalue5) {
        uvalue6 = uvalue2;
      }
      uvalue3 = *(int *)((intptr_t)self + 0x28) - *(int *)((intptr_t)self + 0x30);
      if (uvalue3 < uvalue6) {
        uvalue6 = uvalue3;
      }
      local_808 = uvalue2 - uvalue6;
      uptr4 = *(uint32_t **)((intptr_t)self + 0x3c);
      uptr7 = local_80c;
      for (uvalue2 = uvalue6 >> 2; uvalue2 != 0; uvalue2 = uvalue2 - 1) {
        *uptr7 = *uptr4;
        uptr4 = uptr4 + 1;
        uptr7 = uptr7 + 1;
      }
      for (uvalue2 = uvalue6 & 3; uvalue2 != 0; uvalue2 = uvalue2 - 1) {
        *(uint8_t *)uptr7 = *(uint8_t *)uptr4;
        uptr4 = (uint32_t *)((intptr_t)uptr4 + 1);
        uptr7 = (uint32_t *)((intptr_t)uptr7 + 1);
      }
      local_80c = (uint32_t *)((intptr_t)local_80c + uvalue6);
      *(uint32_t *)((intptr_t)self + 0x30) = *(int *)((intptr_t)self + 0x30) + uvalue6;
      uvalue2 = local_808;
    }
    if (*(char *)((intptr_t)self + 0x34) == '\0') {
      for (uvalue2 = local_808 >> 2; uvalue2 != 0; uvalue2 = uvalue2 - 1) {
        *local_80c = 0;
        local_80c = local_80c + 1;
      }
      for (local_808 = local_808 & 3; local_808 != 0; local_808 = local_808 - 1) {
        *(uint8_t *)local_80c = 0;
        local_80c = (uint32_t *)((intptr_t)local_80c + 1);
      }
      return 1;
    }
    local_810 = SoundBuffer_SeekSample(self,0);
  } while (-1 < local_810);
  return local_810;
}
