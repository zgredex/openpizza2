// SoundStream_LoadNextSample: ported from Pizza Connection 2 at 0x541930.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x541930
#include "pc2_port.h"


int __fastcall SoundStream_LoadNextSample(int arg1)

{
  uint8_t *uptr1;
  int *ptr2;
  char *cptr3;
  uint32_t *uptr4;
  int local_14;
  void *pvStack_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0055afb6;
  local_c = ExceptionList;
  local_14 = 0;
  if (*(char *)(arg1 + 0x3c) == '\0') {
    uptr1 = *(uint8_t **)(arg1 + 0x4c);
    if (uptr1 == (uint8_t *)0x0) {
      return 1;
    }
    ExceptionList = &local_c;
    if (uptr1[1] != '\0') {
      ExceptionList = &local_c;
      *uptr1 = 0x2c;
      cptr3 = (char *)(*(int *)(arg1 + 0x4c) + 1);
      *(char **)(arg1 + 0x48) = cptr3;
      cptr3 = _strchr(cptr3,0x2c);
      *(char **)(arg1 + 0x4c) = cptr3;
      if (cptr3 != (char *)0x0) {
        *cptr3 = '\0';
      }
    }
  }
  else {
    ExceptionList = &local_c;
    *(uint8_t *)(arg1 + 0x3c) = 0;
  }
  cptr3 = *(char **)(arg1 + 0x48);
  if (cptr3 == (char *)0x0) {
    ExceptionList = local_c;
    return 1;
  }
  ptr2 = *(int **)(arg1 + 0x2c);
  if (ptr2 == (int *)0x0) {
    (**(code **)**(uint32_t **)(arg1 + 0x30))(*(uint32_t **)(arg1 + 0x30));
    pvStack_10 = operator_new(0x4c);
    uStack_4 = 0;
    if (pvStack_10 == (void *)0x0) {
      uptr4 = (uint32_t *)0x0;
    }
    else {
      uptr4 = SoundSample_Construct(pvStack_10,*(void **)(arg1 + 0x30),cptr3,&local_14);
    }
    *(uint32_t **)(arg1 + 0x2c) = uptr4;
    if (uptr4 == (uint32_t *)0x0) {
      ExceptionList = local_c;
      return -0x7ff8fff2;
    }
joined_r0x00541a81:
    uStack_4 = 0xffffffff;
    if (local_14 < 0) goto LAB_00541ab4;
    uStack_4 = 0xffffffff;
    Parser_ResetTokenState((uint32_t *)(arg1 + 8));
  }
  else if (1 < *(int *)(arg1 + 0x40)) {
    (**(code **)(*ptr2 + 4))(ptr2);
    *(uint32_t *)(arg1 + 0x2c) = 0;
    (**(code **)**(uint32_t **)(arg1 + 0x30))(*(uint32_t **)(arg1 + 0x30));
    pvStack_10 = operator_new(0x4c);
    uStack_4 = 1;
    if (pvStack_10 == (void *)0x0) {
      uptr4 = (uint32_t *)0x0;
    }
    else {
      uptr4 = SoundSample_Construct(pvStack_10,*(void **)(arg1 + 0x30),cptr3,&local_14);
    }
    *(uint32_t **)(arg1 + 0x2c) = uptr4;
    if (uptr4 == (uint32_t *)0x0) {
      ExceptionList = local_c;
      return -0x7ff8fff2;
    }
    goto joined_r0x00541a81;
  }
  if (-1 < local_14) {
    *(uint8_t *)(*(int *)(arg1 + 0x2c) + 0x34) = *(uint8_t *)(arg1 + 0x52);
    if (*(char *)(arg1 + 0x88) == '\0') {
      *(uint32_t *)(arg1 + 0x84) = 0;
      *(uint8_t *)(arg1 + 0x88) = 1;
      ExceptionList = local_c;
      return local_14;
    }
    ExceptionList = local_c;
    return local_14;
  }
LAB_00541ab4:
  (**(code **)(**(int **)(arg1 + 0x2c) + 4))(*(int **)(arg1 + 0x2c));
  *(uint32_t *)(arg1 + 0x2c) = 0;
  ExceptionList = local_c;
  return local_14;
}
