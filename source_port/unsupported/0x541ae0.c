// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x541ae0.c:46:60: error: invalid operands to binary expression ('void *' and 'int')
// SoundVoice_Open: ported from Pizza Connection 2 at 0x541ae0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x541ae0
#include "pc2_port.h"

int __fastcall SoundVoice_Open(void *arg1)

{
  int value1;
  int *ptr2;
  char *cptr3;
  int value4;
  void *self;
  uint32_t uvalue5;
  uint32_t *uptr6;
  uint32_t local_20;
  uint32_t local_1c;
  uint32_t local_18;
  uint32_t local_14;
  void *local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0055afcb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(uint8_t *)((intptr_t)arg1 + 0x53) = 0;
  *(char **)((intptr_t)arg1 + 0x48) = *(char **)((intptr_t)arg1 + 0x44);
  cptr3 = _strchr(*(char **)((intptr_t)arg1 + 0x44),0x2c);
  *(char **)((intptr_t)arg1 + 0x4c) = cptr3;
  if (cptr3 != (char *)0x0) {
    *cptr3 = '\0';
  }
  *(uint8_t *)((intptr_t)arg1 + 0x3c) = 1;
  value4 = SoundStream_LoadNextSample((intptr_t)arg1);
  if (-1 < value4) {
    if (*(int *)((intptr_t)arg1 + 0x28) == 0) {
      value1 = *(int *)((intptr_t)arg1 + 0x2c);
      if (*(int *)(value1 + 0xc) != 0) {
        local_20 = *(uint32_t *)(value1 + 0x14);
        local_1c = *(uint32_t *)(value1 + 0x18);
        local_18 = *(uint32_t *)(value1 + 0x1c);
        local_14 = *(uint32_t *)(value1 + 0x20);
        local_10 = (void *)CONCAT22(((uint16_t)((local_10) >> 16)),*(uint16_t *)(value1 + 0x24));
        if (*(short *)(value1 + 0x14) != 1) {
          SoundFormat_Init((uint16_t *)&local_20);
        }
      }
      (**(code **)(**(int **)((intptr_t)arg1 + 0x34) + 4))(*(int **)((intptr_t)arg1 + 0x34));
      self = operator_new(0x4c);
      uStack_4 = 0;
      if (self == (void *)0x0) {
        uptr6 = (uint32_t *)0x0;
      }
      else {
        uvalue5 = Sound_GetDeviceCaps(*(int **)((intptr_t)arg1 + 0x34));
        uptr6 = (uint32_t *)(uvalue5 | *(uint32_t *)((intptr_t)arg1 + 0x74));
        uvalue5 = Sound_AlignBufferSize(0,0x3ff00000,(intptr_t)&local_20);
        uptr6 = SoundBuffer_CreateDSBuffer
                           (self,*(int **)((intptr_t)arg1 + 0x34),&local_20,uvalue5,uptr6);
      }
      uStack_4 = 0xffffffff;
      *(uint32_t **)((intptr_t)arg1 + 0x28) = uptr6;
      if (uptr6 == (uint32_t *)0x0) {
        (**(code **)(**(int **)((intptr_t)arg1 + 0x34) + 8))(*(int **)((intptr_t)arg1 + 0x34));
        ExceptionList = local_10;
        return -0x7ff8fff2;
      }
      if (value4 < 0) {
        ExceptionList = local_c;
        return value4;
      }
      if (*(int *)((intptr_t)arg1 + 0x8c) == 0) {
        uvalue5 = *(uint32_t *)((intptr_t)arg1 + 0x78);
      }
      else {
        uvalue5 = *(uint32_t *)((intptr_t)arg1 + 0x9c);
      }
      Sound_SetBufferVolume(uptr6,uvalue5);
      SoundBuffer_SetVolume(*(int *)((intptr_t)arg1 + 0x28));
      (**(code **)(**(int **)((intptr_t)arg1 + 0x28) + 0x14))(*(uint32_t *)((intptr_t)arg1 + 0x7c));
    }
    value4 = SoundVoice_WriteSamples(arg1,0,*(uint32_t *)(*(int *)((intptr_t)arg1 + 0x28) + 0x10) >> 1);
    if (-1 < value4) {
      ptr2 = *(int **)(*(int *)((intptr_t)arg1 + 0x28) + 0x48);
      (**(code **)(*ptr2 + 0x34))(ptr2,0);
      *(uint8_t *)((intptr_t)arg1 + 0x55) = 1;
      *(uint8_t *)((intptr_t)arg1 + 0x53) = 1;
    }
  }
  ExceptionList = local_c;
  return value4;
}
