// Sound_LoadSample3DEx: ported from Pizza Connection 2 at 0x5456a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5456a0
#include "pc2_port.h"

uint32_t Sound_LoadSample3DEx(uint32_t arg1,char *arg2,int *arg3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  uint32_t uvalue1;
  char *self;
  int *ptr2;
  uint32_t *uptr3;
  int value4;
  uint32_t uvalue5;
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
  
  uvalue1 = arg1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b62b;
  pvStack_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(arg1 + 0xa0);
  ExceptionList = &pvStack_c;
  EnterCriticalSection(lpCriticalSection);
  uvalue5 = *(uint32_t *)(uvalue1 + 0x98);
  local_4 = 0;
  arg1 = 0;
  if (-1 < (intptr_t)uvalue5) {
    *arg3 = 0;
    (**(code **)**(uint32_t **)(uvalue1 + 0x9c))(*(uint32_t **)(uvalue1 + 0x9c));
    SoundSample_Construct(appuStack_58,*(void **)(uvalue1 + 0x9c),arg2,(int *)&arg1);
    uvalue5 = arg1;
    local_4 = (local_4 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
    if ((intptr_t)arg1 < 0) {
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
        goto LAB_005459ee;
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
      self = operator_new(0xb4);
      local_4 = (local_4 & ~(0x0u << 8)) | (((3) & 0x0u) << 8);
      arg2 = self;
      if (self == (char *)0x0) {
        ptr2 = (int *)0x0;
      }
      else {
        value4 = *(int *)(uvalue1 + 0x94);
        if (((value4 == 0) || (value4 == 1)) || (uvalue5 = 8, value4 == 2)) {
          uvalue5 = 4;
        }
        ptr2 = *(int **)(uvalue1 + 0xc);
        if (ptr2 == (int *)0x0) {
          ptr2 = (int *)0x0;
        }
        else {
          (**(code **)(*ptr2 + 4))(ptr2);
          ptr2 = *(int **)(uvalue1 + 0xc);
        }
        ptr2 = SoundStreamBuffer_Construct(self,ptr2,&uStack_6c,uStack_30,uvalue5 | 2,&arg1);
      }
      local_4 = (local_4 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
      if (ptr2 == (int *)0x0) {
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
        return 0x8007000e;
      }
      if ((intptr_t)arg1 < 0) {
        (**(code **)(*ptr2 + 4))(ptr2);
        uvalue5 = arg1;
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
        arg1 = SoundBuffer_FillFromSample(ptr2,appuStack_58);
        if (-1 < (intptr_t)arg1) {
          uptr3 = operator_new(0xc);
          if (uptr3 != (uint32_t *)0x0) {
            *uptr3 = ptr2;
            value4 = List_Insert((void *)(uvalue1 + 0x54),(intptr_t)uptr3,'\0');
            uvalue5 = arg1;
            if (value4 != 0) {
              local_4 = (uint32_t)((uint8_t)((local_4) >> 24)) << 8;
              *arg3 = value4;
              SoundSample_Destruct(appuStack_58);
              goto LAB_005459ee;
            }
          }
          (**(code **)(*ptr2 + 4))(ptr2);
          local_4 = (uint32_t)((uint8_t)((local_4) >> 24)) << 8;
          SoundSample_Destruct(appuStack_58);
          LeaveCriticalSection(lpCriticalSection);
          ExceptionList = pvStack_c;
          return 0x8007000e;
        }
        (**(code **)(*ptr2 + 4))(ptr2);
        uvalue5 = arg1;
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
LAB_005459ee:
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = pvStack_c;
  return uvalue5;
}
