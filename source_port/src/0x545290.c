// Sound_LoadSample3D: ported from Pizza Connection 2 at 0x545290.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x545290
#include "pc2_port.h"

int Sound_LoadSample3D(int arg1,char *arg2,int *arg3)

{
  int *self;
  int *ptr1;
  DWORD DVar2;
  int value3;
  uint32_t *uptr4;
  uint32_t uvalue5;
  LPCRITICAL_SECTION lpCriticalSection;
  uint8_t uStack00000000;
  int local_74;
  LPCRITICAL_SECTION local_70;
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
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b5db;
  pvStack_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(arg1 + 0xa0);
  ExceptionList = &pvStack_c;
  local_70 = lpCriticalSection;
  EnterCriticalSection(lpCriticalSection);
  value3 = *(int *)(arg1 + 0x98);
  local_4 = 0;
  local_74 = 0;
  if (-1 < value3) {
    *arg3 = 0;
    (**(code **)**(uint32_t **)(arg1 + 0x9c))(*(uint32_t **)(arg1 + 0x9c));
    SoundSample_Construct(appuStack_58,*(void **)(arg1 + 0x9c),arg2,&local_74);
    value3 = local_74;
    local_4 = (local_4 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
    if (local_74 < 0) {
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
      }
      appuStack_58[0] = &PTR_LAB_0055c840;
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
      self = operator_new(0xac);
      local_4 = (local_4 & ~(0x0u << 8)) | (((3) & 0x0u) << 8);
      if (self == (int *)0x0) {
        self = (int *)0x0;
      }
      else {
        value3 = *(int *)(arg1 + 0x94);
        if ((value3 == 0) || ((value3 != 1 && (value3 != 2)))) {
          uvalue5 = 8;
        }
        else {
          uvalue5 = 4;
        }
        ptr1 = *(int **)(arg1 + 0xc);
        if (ptr1 == (int *)0x0) {
          ptr1 = (int *)0x0;
        }
        else {
          (**(code **)(*ptr1 + 4))(ptr1);
          ptr1 = *(int **)(arg1 + 0xc);
        }
        SoundBuffer_CreateDSBuffer(self,ptr1,&uStack_6c,uStack_30,(uint32_t *)(uvalue5 | 0x12));
        local_4 = (local_4 & ~(0x0u << 8)) | (((4) & 0x0u) << 8);
        Rect_Zero(self + 0x13);
        ptr1 = self + 0x17;
        *(uint8_t *)(self + 0x28) = 0;
        *(uint8_t *)((intptr_t)self + 0xa1) = 0;
        *ptr1 = 0;
        DVar2 = timeGetTime();
        self[0x29] = DVar2;
        self[0x2a] = DVar2;
        *self = (intptr_t)&PTR_LAB_0055c8c8;
        if (-1 < local_74) {
          value3 = (*(code *)**(uint32_t **)self[0x12])
                            ((uint32_t *)self[0x12],&DAT_0055cb88,ptr1);
          if (value3 < 0) {
            *ptr1 = 0;
          }
          else {
            Sound_Get3DBufferParams((intptr_t)self);
          }
          self[0x14] = self[0x14] | 3;
          if (&uStack00000000 != (uint8_t *)0x74) {
            local_74 = value3;
          }
        }
        lpCriticalSection = local_70;
      }
      local_4 = (local_4 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
      if (self == (int *)0x0) {
        appuStack_58[0] = &PTR_LAB_0055c850;
        local_4 = CONCAT31(((uint8_t)((local_4) >> 24)),5);
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
      if (local_74 < 0) {
        (**(code **)(*self + 4))(self);
        value3 = local_74;
        appuStack_58[0] = &PTR_LAB_0055c850;
        local_4 = CONCAT31(((uint8_t)((local_4) >> 24)),6);
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
      }
      else {
        local_74 = SoundBuffer_FillFromSample(self,appuStack_58);
        if (local_74 < 0) {
          (**(code **)(*self + 4))(self);
        }
        else {
          uptr4 = operator_new(0xc);
          if (uptr4 == (uint32_t *)0x0) {
LAB_005455e3:
            (**(code **)(*self + 4))(self);
            local_4 = (uint32_t)((uint8_t)((local_4) >> 24)) << 8;
            SoundSample_Destruct(appuStack_58);
            LeaveCriticalSection(lpCriticalSection);
            ExceptionList = pvStack_c;
            return -0x7ff8fff2;
          }
          *uptr4 = self;
          value3 = List_Insert((void *)(arg1 + 0x54),(intptr_t)uptr4,'\0');
          if (value3 == 0) goto LAB_005455e3;
          *arg3 = value3;
        }
        value3 = local_74;
        local_4 = (uint32_t)((uint8_t)((local_4) >> 24)) << 8;
        SoundSample_Destruct(appuStack_58);
      }
    }
  }
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = pvStack_c;
  return value3;
}
