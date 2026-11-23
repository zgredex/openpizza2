// Sound_CreatePrimaryBuffer: ported from Pizza Connection 2 at 0x542b50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x542b50
#include "pc2_port.h"

int __cdecl Sound_CreatePrimaryBuffer(uint32_t arg1,HWND arg2,uint32_t *arg3)

{
  uint32_t *uptr1;
  int value2;
  uint32_t *uptr3;
  uint32_t unaff_EBP;
  uint8_t uStack00000000;
  int local_8c;
  uint32_t *local_88;
  uint32_t *puStack_84;
  uint32_t local_80;
  uint32_t local_7c;
  uint32_t local_78;
  uint32_t local_74;
  uint32_t local_70;
  uint32_t uStack_6c;
  uint32_t uStack_64;
  uint32_t uStack_60;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b0c1;
  local_c = ExceptionList;
  local_8c = 0;
  ExceptionList = &local_c;
  *arg3 = 0;
  uptr1 = operator_new(0xb8);
  local_4 = 0;
  if (uptr1 == (uint32_t *)0x0) {
    ExceptionList = local_c;
    return -0x7ff8fff2;
  }
  *uptr1 = &PTR_LAB_0055ca08;
  local_88 = uptr1;
  SoundDevice_Construct(uptr1 + 1,arg1,arg2,3,&local_8c);
  local_4 = (local_4 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
  uptr1[6] = 0;
  uptr1[5] = &PTR_DirectSoundBuffer_Delete_0055c860;
  if (&uStack00000000 != (uint8_t *)0x8c) {
    if (local_8c < 0) goto LAB_00542cb2;
    local_8c = 0;
  }
  local_7c = 1;
  local_74 = 0;
  local_80 = 0x14;
  local_78 = 0;
  local_70 = 0;
  value2 = (**(code **)(*(int *)uptr1[3] + 0xc))((int *)uptr1[3],&local_80,uptr1 + 6,0);
  if (-1 < value2) goto LAB_00542cb2;
  Sound_SetLastError(&DAT_00585578,s_creating_primary_buffer__00574f34,value2,unaff_EBP);
  if (value2 < -0x7ffbfeef) {
    if (value2 == -0x7ffbfef0) {
      value2 = -0x7ffbfef0;
    }
    else if (value2 == -0x7fffbfff) {
      value2 = -0x7fffbfff;
    }
    else if (value2 == -0x7fffbffe) {
      value2 = -0x7fffbffe;
    }
    else {
      if (value2 != -0x7fffbffb) goto LAB_00542c93;
      value2 = -0x7fffbffb;
    }
  }
  else if (value2 == -0x7ff8fff2) {
    value2 = -0x7ff8fff2;
  }
  else if (value2 == -0x7ff8ffa9) {
    value2 = -0x7ff8ffa9;
  }
  else {
LAB_00542c93:
    value2 = -0x7fff0001;
  }
  if (&uStack00000000 != (uint8_t *)0x8c) {
    local_8c = value2;
  }
LAB_00542cb2:
  local_4 = (local_4 & ~(0x0u << 8)) | (((2) & 0x0u) << 8);
  SoundVoiceThread_Construct(uptr1 + 7,&local_8c);
  uptr1[0x15] = 0;
  uptr1[0x16] = 0;
  uptr1[0x17] = 0;
  uptr1[0x18] = 0;
  uptr1[0x19] = 0;
  uptr1[0x1a] = 0;
  uptr1[0x1b] = 0;
  uptr1[0x1c] = 0;
  uptr1[0x1d] = 0;
  uptr1[0x1e] = 0;
  uptr1[0x1f] = 0;
  uptr1[0x20] = 0;
  uptr1[0x23] = 100;
  uptr1[0x21] = 10000;
  uptr1[0x22] = 10000;
  uptr1[0x24] = 100000;
  uptr1[0x25] = 0;
  uptr1[0x26] = 0x80004002;
  uptr1[0x27] = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(uptr1 + 0x28));
  uptr1[1] = &PTR_LAB_0055c9f8;
  uptr1[7] = &PTR_LAB_0055c9f4;
  local_4 = (local_4 & ~(0x0u << 8)) | (((7) & 0x0u) << 8);
  *uptr1 = &PTR_LAB_0055c8f8;
  uptr1[5] = &PTR_LAB_0055c8f4;
  if ((&uStack00000000 != (uint8_t *)0x8c) && (-1 < local_8c)) {
    uptr1[0x26] = local_8c;
    puStack_84 = operator_new(0x62c);
    local_4 = (local_4 & ~(0x0u << 8)) | (((8) & 0x0u) << 8);
    if (puStack_84 == (uint32_t *)0x0) {
      uptr3 = (uint32_t *)0x0;
    }
    else {
      uptr3 = SoundBuffer_ConstructBase(puStack_84);
    }
    local_4 = CONCAT31(((uint8_t)((local_4) >> 24)),7);
    uptr1[0x27] = uptr3;
    if (uptr3 == (uint32_t *)0x0) {
      uptr1[0x26] = 0x8007000e;
    }
    else {
      uStack_6c = 0x60;
      value2 = (**(code **)(*(int *)uptr1[3] + 0x10))();
      if (-1 < value2) {
        uptr1[0x23] = uStack_64;
        uptr1[0x24] = uStack_60;
      }
    }
  }
  *arg3 = uptr1;
  ExceptionList = local_c;
  return local_8c;
}
