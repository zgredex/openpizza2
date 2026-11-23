// Sound_LoadSample2D: ported from Pizza Connection 2 at 0x544d90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x544d90
#include "pc2_port.h"

int Sound_LoadSample2D(int arg1,char *arg2,int *arg3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  char *self;
  int *ptr1;
  uint32_t *uptr2;
  int value3;
  uint32_t uvalue4;
  int value5;
  uint32_t uStack_6c;
  uint32_t uStack_68;
  uint32_t uStack_64;
  uint32_t uStack_60;
  uint16_t uStack_5c;
  uint8_t **appuStack_58 [2];
  int *piStack_50;
  int iStack_4c;
  LPVOID pvStack_48;
  uint32_t uStack_44;
  uint32_t uStack_40;
  uint32_t uStack_3c;
  uint32_t uStack_38;
  uint16_t uStack_34;
  uint32_t uStack_30;
  LPVOID pvStack_1c;
  void *pvStack_c;
  uint8_t *puStack_8;
  int local_4;
  
  value3 = arg1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b56b;
  pvStack_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(arg1 + 0xa0);
  ExceptionList = &pvStack_c;
  EnterCriticalSection(lpCriticalSection);
  value5 = *(int *)(value3 + 0x98);
  local_4 = 0;
  arg1 = 0;
  if (-1 < value5) {
    *arg3 = 0;
    (**(code **)**(uint32_t **)(value3 + 0x9c))(*(uint32_t **)(value3 + 0x9c));
    SoundSample_Construct(appuStack_58,*(void **)(value3 + 0x9c),arg2,&arg1);
    value5 = arg1;
    local_4 = (local_4 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
    if (arg1 < 0) {
      appuStack_58[0] = &PTR_LAB_0055c850;
      local_4 = CONCAT31(((uint8_t)((local_4) >> 24)),2);
      if (pvStack_1c != (LPVOID)0x0) {
        Mem_Free(pvStack_1c);
      }
      if (iStack_4c != 0) {
        SoundStream_Close(piStack_50,iStack_4c);
      }
      if (pvStack_48 != (LPVOID)0x0) {
        Mem_Free(pvStack_48);
      }
      if (piStack_50 != (int *)0x0) {
        (**(code **)(*piStack_50 + 4))(piStack_50);
        appuStack_58[0] = &PTR_LAB_0055c840;
        goto LAB_005450dd;
      }
    }
    else {
      if (iStack_4c != 0) {
        uStack_68 = uStack_40;
        uStack_64 = uStack_3c;
        uStack_6c = uStack_44;
        uStack_60 = uStack_38;
        uStack_5c = uStack_34;
        if ((short)uStack_44 != 1) {
          SoundFormat_Init((uint16_t *)&uStack_6c);
        }
      }
      self = operator_new(0x4c);
      local_4 = (local_4 & ~(0x0u << 8)) | (((3) & 0x0u) << 8);
      arg2 = self;
      if (self == (char *)0x0) {
        ptr1 = (int *)0x0;
      }
      else {
        value5 = *(int *)(value3 + 0x94);
        if ((value5 == 0) || ((value5 != 1 && (value5 != 2)))) {
          uvalue4 = 8;
        }
        else {
          uvalue4 = 4;
        }
        ptr1 = *(int **)(value3 + 0xc);
        if (ptr1 == (int *)0x0) {
          ptr1 = (int *)0x0;
        }
        else {
          (**(code **)(*ptr1 + 4))(ptr1);
          ptr1 = *(int **)(value3 + 0xc);
        }
        ptr1 = SoundBuffer_CreateDSBuffer
                           (self,ptr1,&uStack_6c,uStack_30,(uint32_t *)(uvalue4 | 2));
      }
      local_4 = (local_4 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
      if (ptr1 == (int *)0x0) {
        appuStack_58[0] = &PTR_LAB_0055c850;
        local_4 = CONCAT31(((uint8_t)((local_4) >> 24)),4);
        if (pvStack_1c != (LPVOID)0x0) {
          Mem_Free(pvStack_1c);
        }
        if (iStack_4c != 0) {
          SoundStream_Close(piStack_50,iStack_4c);
        }
        if (pvStack_48 != (LPVOID)0x0) {
          Mem_Free(pvStack_48);
        }
        if (piStack_50 != (int *)0x0) {
          (**(code **)(*piStack_50 + 4))(piStack_50);
        }
        appuStack_58[0] = &PTR_LAB_0055c840;
        LeaveCriticalSection(lpCriticalSection);
        ExceptionList = pvStack_c;
        return -0x7ff8fff2;
      }
      if (arg1 < 0) {
        (**(code **)(*ptr1 + 4))(ptr1);
        value5 = arg1;
        appuStack_58[0] = &PTR_LAB_0055c850;
        local_4 = CONCAT31(((uint8_t)((local_4) >> 24)),5);
        if (pvStack_1c != (LPVOID)0x0) {
          Mem_Free(pvStack_1c);
        }
        if (iStack_4c != 0) {
          SoundStream_Close(piStack_50,iStack_4c);
        }
      }
      else {
        arg1 = SoundBuffer_FillFromSample(ptr1,appuStack_58);
        if (-1 < arg1) {
          uptr2 = operator_new(0xc);
          if (uptr2 != (uint32_t *)0x0) {
            *uptr2 = ptr1;
            value3 = List_Insert((void *)(value3 + 0x54),(intptr_t)uptr2,'\0');
            value5 = arg1;
            if (value3 != 0) {
              local_4 = (uint32_t)((uint8_t)((local_4) >> 24)) << 8;
              *arg3 = value3;
              SoundSample_Destruct(appuStack_58);
              goto LAB_005450dd;
            }
          }
          (**(code **)(*ptr1 + 4))(ptr1);
          local_4 = (uint32_t)((uint8_t)((local_4) >> 24)) << 8;
          SoundSample_Destruct(appuStack_58);
          LeaveCriticalSection(lpCriticalSection);
          ExceptionList = pvStack_c;
          return -0x7ff8fff2;
        }
        (**(code **)(*ptr1 + 4))(ptr1);
        value5 = arg1;
        appuStack_58[0] = &PTR_LAB_0055c850;
        local_4 = CONCAT31(((uint8_t)((local_4) >> 24)),6);
        if (pvStack_1c != (LPVOID)0x0) {
          Mem_Free(pvStack_1c);
        }
        if (iStack_4c != 0) {
          SoundStream_Close(piStack_50,iStack_4c);
        }
      }
      if (pvStack_48 != (LPVOID)0x0) {
        Mem_Free(pvStack_48);
      }
      if (piStack_50 != (int *)0x0) {
        (**(code **)(*piStack_50 + 4))(piStack_50);
      }
    }
    appuStack_58[0] = &PTR_LAB_0055c840;
  }
LAB_005450dd:
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = pvStack_c;
  return value5;
}
