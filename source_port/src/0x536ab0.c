// FullscreenImage_LoadPCX: ported from Pizza Connection 2 at 0x536ab0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x536ab0
#include "pc2_port.h"

struct pc2_obj_0x536ab0_local_39c { intptr_t _ptr; };
uint32_t __thiscall FullscreenImage_LoadPCX(char *self,int arg1,char *arg2,void *arg3)

{
  char cVar1;
  uint32_t uvalue2;
  char *pvVar3;
  char *cptr4;
  int *ptr5;
  uint32_t uvalue6;
  uint32_t uvalue7;
  int value8;
  int value9;
  char *cptr10;
  uint32_t uvalue11;
  char *cptr12;
  uint8_t *bptr13;
  struct pc2_obj_0x536ab0_local_39c *local_39c;
  uint32_t local_398;
  int local_394;
  void *local_390;
  char local_38c [3];
  char cStack_389;
  uint16_t local_388;
  uint8_t uStack_386;
  uint8_t uStack_385;
  uint16_t local_384;
  uint16_t uStack_382;
  uint32_t local_34b;
  char local_30c [768];
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055acfe;
  local_c = ExceptionList;
  uvalue6 = 0xffffffff;
  cptr4 = (char *)((intptr_t)self + 0x1c);
  do {
    cptr10 = arg2;
    if (uvalue6 == 0) break;
    uvalue6 = uvalue6 - 1;
    cptr10 = arg2 + 1;
    cVar1 = *arg2;
    arg2 = cptr10;
  } while (cVar1 != '\0');
  uvalue6 = ~uvalue6;
  cptr10 = cptr10 + -uvalue6;
  cptr12 = cptr4;
  ExceptionList = &local_c;
  for (uvalue7 = uvalue6 >> 2; uvalue7 != 0; uvalue7 = uvalue7 - 1) {
    *(uint32_t *)cptr12 = *(uint32_t *)cptr10;
    cptr10 = cptr10 + 4;
    cptr12 = cptr12 + 4;
  }
  for (uvalue6 = uvalue6 & 3; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
    *cptr12 = *cptr10;
    cptr10 = cptr10 + 1;
    cptr12 = cptr12 + 1;
  }
  if (arg3 == (void *)0x0) {
    local_39c = (FILE *)CRT_Fopen(cptr4,&DAT_00563184);
    if (local_39c == (FILE *)0x0) {
      Debug_WarningMessageBox();
      ExceptionList = local_c;
      return 0;
    }
    CRT_FreadLocked(local_38c,1,0x80,(int *)local_39c);
  }
  else {
    local_39c = (FILE *)Resource_Open(arg3,cptr4,0);
    if (local_39c == (FILE *)0x0) {
      Debug_WarningMessageBox();
      ExceptionList = local_c;
      return 0;
    }
    Resource_Read(arg3,local_38c,0x80,(intptr_t)local_39c);
  }
  value8 = ((uint32_t)local_384 - (CONCAT12(uStack_386,local_388) & 0xffff)) + 1;
  *(int *)((intptr_t)self + 4) = value8;
  value9 = ((uint32_t)uStack_382 - (uint32_t)CONCAT11(uStack_385,uStack_386)) + 1;
  cVar1 = (char)local_34b;
  *(int *)((intptr_t)self + 8) = value9;
  if (((cVar1 == '\x01') || (cVar1 == '\x03')) && (cStack_389 == '\b')) {
    if (cVar1 == '\x01') {
      *(uint8_t *)((intptr_t)self + 0x10) = 8;
      *(uint8_t *)((intptr_t)self + 0x11) = 1;
    }
    else {
      *(uint8_t *)((intptr_t)self + 0x10) = 0x18;
      *(uint8_t *)((intptr_t)self + 0x11) = 3;
    }
    value8 = (uint32_t)*(uint8_t *)((intptr_t)self + 0x11) * value9 * value8;
    *(int *)((intptr_t)self + 0xc) = value8;
    pvVar3 = operator_new((value8 >> 1) * 2 + 2);
    *(void **)((intptr_t)self + 0x18) = pvVar3;
    local_394 = 0;
    if (0 < *(int *)((intptr_t)self + 8)) {
      do {
        value9 = 0;
        uvalue6 = (uint32_t)*(uint8_t *)((intptr_t)self + 0x11);
        if (uvalue6 != 0) {
          uvalue7 = local_34b >> 8;
          do {
            uvalue11 = 0;
            bptr13 = (uint8_t *)(((local_394 * *(int *)((intptr_t)self + 4) + 1) * uvalue6 - value9) + -1 +
                              *(int *)((intptr_t)self + 0x18));
            if ((short)uvalue7 != 0) {
              do {
                if ((intptr_t)(uint32_t)*(uint8_t *)((intptr_t)self + 0x11) <= value9) break;
                if (arg3 == (void *)0x0) {
                  local_398 = CRT_Fgetc(&local_39c->_ptr);
                }
                else {
                  local_398 = 0;
                  Resource_Read(arg3,(char *)&local_398,1,(intptr_t)local_39c);
                }
                if (((uint8_t)local_398 & 0xc0) == 0xc0) {
                  local_390 = (void *)(local_398 & 0x3f);
                  if (arg3 == (void *)0x0) {
                    local_398 = CRT_Fgetc(&local_39c->_ptr);
                  }
                  else {
                    local_398 = 0;
                    Resource_Read(arg3,(char *)&local_398,1,(intptr_t)local_39c);
                  }
                  if (0 < (intptr_t)local_390) {
                    pvVar3 = local_390;
                    do {
                      if ((intptr_t)uvalue11 < *(int *)((intptr_t)self + 4)) {
                        *bptr13 = (uint8_t)local_398;
                      }
                      bptr13 = bptr13 + *(uint8_t *)((intptr_t)self + 0x11);
                      uvalue11 = uvalue11 + 1;
                      if (uvalue11 == (local_34b >> 8 & 0xffff)) {
                        value9 = value9 + 1;
                        uvalue11 = 0;
                        bptr13 = (uint8_t *)(((local_394 * *(int *)((intptr_t)self + 4) + 1) *
                                            (uint32_t)*(uint8_t *)((intptr_t)self + 0x11) - value9) + -1 +
                                          *(int *)((intptr_t)self + 0x18));
                      }
                      pvVar3 = (void *)((intptr_t)pvVar3 - 1);
                    } while (pvVar3 != (void *)0x0);
                  }
                }
                else {
                  if ((intptr_t)uvalue11 < *(int *)((intptr_t)self + 4)) {
                    *bptr13 = (uint8_t)local_398;
                  }
                  bptr13 = bptr13 + *(uint8_t *)((intptr_t)self + 0x11);
                  uvalue11 = uvalue11 + 1;
                }
                uvalue7 = local_34b >> 8;
              } while ((intptr_t)uvalue11 < (intptr_t)(uvalue7 & 0xffff));
            }
            value9 = value9 + 1;
            uvalue6 = (uint32_t)*(uint8_t *)((intptr_t)self + 0x11);
          } while (value9 < (intptr_t)uvalue6);
        }
        local_394 = local_394 + 1;
      } while (local_394 < *(int *)((intptr_t)self + 8));
    }
    if (*(char *)((intptr_t)self + 0x10) == '\b') {
      if (arg3 == (void *)0x0) {
        CRT_Fseek((int *)local_39c,1,1);
        CRT_FreadLocked(local_30c,1,0x300,(int *)local_39c);
      }
      else {
        Stream_Seek(1,(intptr_t)local_39c,1);
        Resource_Read(arg3,local_30c,0x300,(intptr_t)local_39c);
      }
      cptr4 = local_30c;
      value9 = 0x100;
      do {
        cVar1 = cptr4[2];
        cptr4[2] = *cptr4;
        *cptr4 = cVar1;
        cptr4 = cptr4 + 3;
        value9 = value9 + -1;
      } while (value9 != 0);
      local_390 = operator_new(0x20c);
      local_4 = 0;
      if (local_390 == (void *)0x0) {
        ptr5 = (int *)0x0;
      }
      else {
        ptr5 = Palette_Init(local_390,(uint32_t)*(uint8_t *)(arg1 + 0x18),(uint32_t *)local_30c,0);
      }
      local_4 = 0xffffffff;
      *(int **)((intptr_t)self + 0x14) = ptr5;
    }
    if (arg3 == (void *)0x0) {
      CRT_Fclose(local_39c);
    }
    else {
      Resource_Close(arg3,(intptr_t)local_39c);
    }
    uvalue2 = 1;
  }
  else {
    Debug_WarningMessageBox();
    uvalue2 = 0;
  }
  ExceptionList = local_c;
  return uvalue2;
}
