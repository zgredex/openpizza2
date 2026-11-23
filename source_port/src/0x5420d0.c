// SoundVoice_ServiceStream: ported from Pizza Connection 2 at 0x5420d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5420d0
#include "pc2_port.h"

int __fastcall SoundVoice_ServiceStream(void *arg1)

{
  char cVar1;
  int *ptr2;
  int value3;
  char *cptr4;
  int value5;
  uint32_t uvalue6;
  int value7;
  uint32_t uvalue8;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
  value7 = 0;
  if (*(char *)((intptr_t)arg1 + 0x54) == '\0') {
    return 1;
  }
  if (*(char *)((intptr_t)arg1 + 0x56) == '\0') {
    return 0;
  }
  if (*(char *)((intptr_t)arg1 + 0x53) == '\0') {
    value7 = SoundVoice_Open(arg1);
    if (value7 < 0) {
      *(uint8_t *)((intptr_t)arg1 + 0x57) = 1;
      return value7;
    }
    EnterCriticalSection(*(LPCRITICAL_SECTION *)((intptr_t)arg1 + 0x38));
    if (*(char *)((intptr_t)arg1 + 0x54) == '\0') {
      LeaveCriticalSection(*(LPCRITICAL_SECTION *)((intptr_t)arg1 + 0x38));
      return 1;
    }
    SoundBuffer_Configure(*(int **)(*(int *)((intptr_t)arg1 + 0x28) + 0x48),'\x01');
    LeaveCriticalSection(*(LPCRITICAL_SECTION *)((intptr_t)arg1 + 0x38));
    return value7;
  }
  local_c = 0;
  uvalue6 = *(uint32_t *)(*(int *)((intptr_t)arg1 + 0x28) + 0x10) >> 1;
  if (*(char *)((intptr_t)arg1 + 0x55) != '\0') {
    local_c = uvalue6;
  }
  if (*(char *)((intptr_t)arg1 + 0x57) == '\0') {
    do {
      local_8 = 0;
      local_4 = 0;
      value7 = *(int *)((intptr_t)arg1 + 0x2c);
      if (*(short *)(value7 + 0x14) == 1) {
        value7 = *(int *)(value7 + 0x30) - (uint32_t)*(uint16_t *)(value7 + 0x20);
      }
      else {
        value7 = *(int *)(value7 + 0x30) + (uint32_t)*(uint16_t *)(value7 + 0x16) * -2;
      }
      value7 = Stream_RequestBlock((void *)((intptr_t)arg1 + 8),value7,uvalue6,(int *)&local_8,&local_4);
      if (value7 != 2) {
        if ((value7 == 1) &&
           (uvalue8 = *(int *)(*(int *)((intptr_t)arg1 + 0x2c) + 0x28) -
                    *(int *)(*(int *)((intptr_t)arg1 + 0x2c) + 0x30), uvalue8 < uvalue6)) {
          if ((uvalue8 != 0) &&
             (local_4 = SoundVoice_WriteSamples(arg1,local_c,uvalue8), (intptr_t)local_4 < 0)) {
            EnterCriticalSection(*(LPCRITICAL_SECTION *)((intptr_t)arg1 + 0x38));
            value7 = *(int *)((intptr_t)arg1 + 0x28);
            ptr2 = *(int **)(value7 + 0x48);
            if ((ptr2 != (int *)0x0) &&
               (value3 = (**(code **)(*ptr2 + 0x48))(ptr2), -1 < value3)) {
              if (*(char *)(value7 + 0x34) != '\0') {
                List_DestroyObjects(value7);
              }
              (**(code **)(**(int **)(value7 + 0x48) + 0x34))(*(int **)(value7 + 0x48),0);
            }
            LeaveCriticalSection(*(LPCRITICAL_SECTION *)((intptr_t)arg1 + 0x38));
            return local_4;
          }
          local_c = local_c + uvalue8;
          uvalue6 = uvalue6 - uvalue8;
          value7 = SoundStream_LoadNextSample((intptr_t)arg1);
          if (value7 < 0) {
            return value7;
          }
          goto LAB_0054236d;
        }
        break;
      }
      value7 = SoundVoice_WriteSamples(arg1,local_c,local_8);
      if (value7 < 0) {
        EnterCriticalSection(*(LPCRITICAL_SECTION *)((intptr_t)arg1 + 0x38));
        value3 = *(int *)((intptr_t)arg1 + 0x28);
        ptr2 = *(int **)(value3 + 0x48);
        if ((ptr2 != (int *)0x0) && (value5 = (**(code **)(*ptr2 + 0x48))(ptr2), -1 < value5)) {
          if (*(char *)(value3 + 0x34) != '\0') {
            List_DestroyObjects(value3);
          }
          (**(code **)(**(int **)(value3 + 0x48) + 0x34))(*(int **)(value3 + 0x48),0);
        }
        LeaveCriticalSection(*(LPCRITICAL_SECTION *)((intptr_t)arg1 + 0x38));
        return value7;
      }
      local_c = local_c + local_8;
      uvalue6 = uvalue6 - local_8;
      *(uint32_t *)((intptr_t)arg1 + 0x84) = local_4;
      *(uint8_t *)((intptr_t)arg1 + 0x88) = 1;
    } while (uvalue6 != 0);
LAB_00542418:
    value7 = SoundVoice_WriteSamples(arg1,local_c,uvalue6);
    if (value7 < 0) {
      EnterCriticalSection(*(LPCRITICAL_SECTION *)((intptr_t)arg1 + 0x38));
      value3 = *(int *)((intptr_t)arg1 + 0x28);
      ptr2 = *(int **)(value3 + 0x48);
      if ((ptr2 != (int *)0x0) && (value5 = (**(code **)(*ptr2 + 0x48))(ptr2), -1 < value5)) {
        if (*(char *)(value3 + 0x34) != '\0') {
          List_DestroyObjects(value3);
        }
        (**(code **)(**(int **)(value3 + 0x48) + 0x34))(*(int **)(value3 + 0x48),0);
      }
      LeaveCriticalSection(*(LPCRITICAL_SECTION *)((intptr_t)arg1 + 0x38));
      return value7;
    }
    goto LAB_0054248b;
  }
  cVar1 = *(char *)((intptr_t)arg1 + 0x70);
  if (cVar1 == '\0') {
    value7 = SoundVoice_WriteSilence(arg1,local_c,uvalue6);
    if (-1 < value7) {
      *(uint8_t *)((intptr_t)arg1 + 0x70) = 1;
      goto LAB_005421ae;
    }
  }
  else {
    *(uint8_t *)((intptr_t)arg1 + 0x54) = 0;
LAB_005421ae:
    if (cVar1 == '\0') goto LAB_0054248b;
  }
  EnterCriticalSection(*(LPCRITICAL_SECTION *)((intptr_t)arg1 + 0x38));
  value7 = *(int *)((intptr_t)arg1 + 0x28);
  ptr2 = *(int **)(value7 + 0x48);
  if ((ptr2 != (int *)0x0) && (value3 = (**(code **)(*ptr2 + 0x48))(ptr2), -1 < value3)) {
    if (*(char *)(value7 + 0x34) != '\0') {
      List_DestroyObjects(value7);
    }
    (**(code **)(**(int **)(value7 + 0x48) + 0x34))(*(int **)(value7 + 0x48),0);
  }
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)((intptr_t)arg1 + 0x38));
  value7 = 1;
LAB_0054248b:
  *(bool *)((intptr_t)arg1 + 0x55) = *(char *)((intptr_t)arg1 + 0x55) == '\0';
  *(uint8_t *)((intptr_t)arg1 + 0x56) = 0;
  return value7;
LAB_0054236d:
  if (value7 != 1) goto LAB_00542418;
  if (*(char *)((intptr_t)arg1 + 0x52) == '\0') {
    value7 = 1;
    if ((uvalue6 != 0) && (value7 = SoundVoice_WriteSilence(arg1,local_c,uvalue6), value7 < 0)) {
      EnterCriticalSection(*(LPCRITICAL_SECTION *)((intptr_t)arg1 + 0x38));
      value3 = *(int *)((intptr_t)arg1 + 0x28);
      ptr2 = *(int **)(value3 + 0x48);
      if ((ptr2 != (int *)0x0) && (value5 = (**(code **)(*ptr2 + 0x48))(ptr2), -1 < value5)) {
        if (*(char *)(value3 + 0x34) != '\0') {
          List_DestroyObjects(value3);
        }
        (**(code **)(**(int **)(value3 + 0x48) + 0x34))(*(int **)(value3 + 0x48),0);
      }
      LeaveCriticalSection(*(LPCRITICAL_SECTION *)((intptr_t)arg1 + 0x38));
      return value7;
    }
    *(uint8_t *)((intptr_t)arg1 + 0x70) = 0;
    *(uint8_t *)((intptr_t)arg1 + 0x57) = 1;
    (**(code **)(**(int **)((intptr_t)arg1 + 0x2c) + 4))(*(int **)((intptr_t)arg1 + 0x2c));
    *(uint32_t *)((intptr_t)arg1 + 0x2c) = 0;
    goto LAB_0054248b;
  }
  *(char **)((intptr_t)arg1 + 0x48) = *(char **)((intptr_t)arg1 + 0x44);
  cptr4 = _strchr(*(char **)((intptr_t)arg1 + 0x44),0x2c);
  *(char **)((intptr_t)arg1 + 0x4c) = cptr4;
  if (cptr4 != (char *)0x0) {
    *cptr4 = '\0';
  }
  *(uint8_t *)((intptr_t)arg1 + 0x3c) = 1;
  value7 = SoundStream_LoadNextSample((intptr_t)arg1);
  if (value7 < 0) {
    return value7;
  }
  goto LAB_0054236d;
}
