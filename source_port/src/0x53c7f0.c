// Sprite_Load: ported from Pizza Connection 2 at 0x53c7f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53c7f0
#include "pc2_port.h"

uint32_t * __thiscall
Sprite_Load(void *self,void *arg1,void *arg2,LPCSTR arg3,uint32_t *arg4,int arg5,
           void *arg6,int arg7)

{
  char cVar1;
  bool flag2;
  uint8_t flag3;
  void *pvVar4;
  char *cptr5;
  int value6;
  int *ptr7;
  uint32_t uvalue8;
  int value9;
  uint32_t uvalue10;
  uint32_t uvalue11;
  uint32_t *uptr12;
  uint32_t uvalue13;
  char *cptr14;
  uint32_t *uptr15;
  LPCSTR pCVar16;
  int value17;
  FILE *local_348;
  int local_344;
  int local_338;
  void *local_334;
  uint32_t local_330;
  uint8_t local_32c;
  uint32_t local_32b [7];
  char local_30c [768];
  void *local_c;
  uint8_t *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055adb3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_334 = self;
  SpriteBase_Construct(self);
  local_4 = 0;
  *(uint8_t ***)self = &PTR_Sprite_ScalarDeletingDestructor_0055c82c;
  flag2 = false;
  *(uint8_t *)((intptr_t)self + 0x38) = 0;
  *(uint8_t *)((intptr_t)self + 0x39) = 1;
  *(uint32_t *)((intptr_t)self + 0x3c) = 0;
  *(uint8_t *)((intptr_t)self + 0x36) = 0xff;
  *(uint32_t *)((intptr_t)self + 0x30) = 0;
  *(uint32_t *)((intptr_t)self + 0x20) = 0;
  *(uint32_t *)((intptr_t)self + 0x2c) = 0;
  *(uint32_t *)((intptr_t)self + 0x24) = 0;
  *(uint8_t *)((intptr_t)self + 0x34) = 0;
  *(uint32_t *)((intptr_t)self + 0x28) = 0;
  if (arg4 != (uint32_t *)0x0) {
    *arg4 = 0;
  }
  if (*arg3 == '\0') {
LAB_0053c869:
    *arg4 = 0x12d;
    ExceptionList = local_c;
    return self;
  }
  if (arg2 == (void *)0x0) {
    local_348 = (FILE *)CRT_Fopen(arg3,&DAT_00563184);
    if (local_348 == (FILE *)0x0) {
      if (arg4 != (uint32_t *)0x0) goto LAB_0053c869;
      NoOp_Stub();
    }
    CRT_FreadLocked((char *)&local_330,1,0x21,(int *)local_348);
  }
  else {
    local_348 = (FILE *)Resource_Open(arg2,arg3,0);
    if (local_348 == (FILE *)0x0) {
      if (arg4 != (uint32_t *)0x0) goto LAB_0053c869;
      NoOp_Stub();
    }
    Resource_Read(arg2,(char *)&local_330,0x21,(intptr_t)local_348);
  }
  uptr12 = local_32b;
  uptr15 = self;
  for (value9 = 7; uptr15 = uptr15 + 1, value9 != 0; value9 = value9 + -1) {
    *uptr15 = *uptr12;
    uptr12 = uptr12 + 1;
  }
  if ((*(uint8_t *)((intptr_t)self + 5) & 0x40) != 0) {
    flag2 = true;
    if (arg6 == (void *)0x0) {
      NoOp_Stub();
    }
    local_32c = *(uint8_t *)((intptr_t)self + 5);
    *(uint8_t *)((intptr_t)self + 5) = local_32c & 0xbf;
    local_32c = local_32c & 0xbf;
  }
  if (*(uint8_t *)((intptr_t)self + 5) < 0x80) {
    *(uint8_t *)((intptr_t)self + 0x34) = 1;
    if (local_32c != 8) {
      uvalue13 = local_330;
      flag3 = local_32c;
      goto LAB_0053c9a5;
    }
  }
  else {
    flag3 = *(uint8_t *)((intptr_t)self + 5) + 0x80;
    *(uint8_t *)((intptr_t)self + 0x34) = flag3;
    pvVar4 = operator_new((uint32_t)flag3 << 2);
    *(void **)((intptr_t)self + 0x24) = pvVar4;
    *(uint8_t *)((intptr_t)self + 5) = 8;
    local_32c = 8;
  }
  flag3 = local_32c;
  if (flag2) {
    uvalue13 = local_330 + (uint32_t)*(uint8_t *)((intptr_t)self + 0x34) * 4;
  }
  else {
    uvalue13 = (uint32_t)*(uint8_t *)((intptr_t)self + 0x34) * 0x300 + local_330;
  }
LAB_0053c9a5:
  if (((intptr_t)uvalue13 < 0) || (0x40000000 < (intptr_t)uvalue13)) {
    if (arg4 != (uint32_t *)0x0) {
      *arg4 = 0x12e;
      ExceptionList = local_c;
      return self;
    }
    NoOp_Stub();
  }
  *(uint32_t *)((intptr_t)self + 0x20) = 0;
  *(uint32_t *)((intptr_t)self + 0x28) = 0;
  if ((arg5 == 0) || (arg2 == (void *)0x0)) {
    pvVar4 = operator_new(uvalue13);
    *(void **)((intptr_t)self + 0x2c) = pvVar4;
    if (pvVar4 == (void *)0x0) {
      if (arg4 != (uint32_t *)0x0) {
        *arg4 = 0x12f;
        ExceptionList = local_c;
        return self;
      }
      NoOp_Stub();
    }
    if (arg2 == (void *)0x0) {
      CRT_FreadLocked(*(char **)((intptr_t)self + 0x2c),1,uvalue13,(int *)local_348);
      CRT_Fclose(local_348);
    }
    else {
      Resource_Read(arg2,*(char **)((intptr_t)self + 0x2c),uvalue13,(intptr_t)local_348);
      Resource_Close(arg2,(intptr_t)local_348);
    }
    if (flag3 == 8) {
      if ((*(char *)((intptr_t)arg1 + 0x18) == '\0') || ((*(uint8_t *)((intptr_t)self + 4) & 0x10) != 0)) {
        value9 = 0;
      }
      else {
        value9 = 1;
      }
      if (*(uint8_t *)((intptr_t)self + 0x34) < 2) {
        if (flag2) {
          local_338 = *(int *)(*(int *)((intptr_t)self + 0x2c) + local_330);
          uvalue8 = Array_GetPtrChecked(arg6,local_338);
          *(uint32_t *)((intptr_t)self + 0x20) = uvalue8;
        }
        else {
          pvVar4 = operator_new(0x20c);
          local_4 = (local_4 & ~(0x0u << 8)) | (((3) & 0x0u) << 8);
          if (pvVar4 == (void *)0x0) {
            local_4 = (uint32_t)((uint8_t)((local_4) >> 24)) << 8;
            *(uint32_t *)((intptr_t)self + 0x20) = 0;
          }
          else {
            ptr7 = Palette_Init(pvVar4,value9,
                                  (uint32_t *)(*(int *)((intptr_t)self + 0x2c) + local_330),arg7);
            local_4 = (uint32_t)((uint8_t)((local_4) >> 24)) << 8;
            *(int **)((intptr_t)self + 0x20) = ptr7;
          }
        }
      }
      else {
        value6 = 0;
        if (*(uint8_t *)((intptr_t)self + 0x34) != 0) {
          value17 = 0;
          do {
            if (flag2) {
              local_338 = *(int *)(*(int *)((intptr_t)self + 0x2c) + value6 * 4 + local_330);
              uvalue8 = Array_GetPtrChecked(arg6,local_338);
              *(uint32_t *)((intptr_t)self + 0x20) = uvalue8;
            }
            else {
              pvVar4 = operator_new(0x20c);
              local_4 = (local_4 & ~(0x0u << 8)) | (((4) & 0x0u) << 8);
              if (pvVar4 == (void *)0x0) {
                ptr7 = (int *)0x0;
              }
              else {
                ptr7 = Palette_Init(pvVar4,value9,
                                      (uint32_t *)
                                      (value17 + *(int *)((intptr_t)self + 0x2c) + local_330),arg7);
              }
              local_4 = (uint32_t)((uint8_t)((local_4) >> 24)) << 8;
              *(int **)(*(int *)((intptr_t)self + 0x24) + value6 * 4) = ptr7;
            }
            value6 = value6 + 1;
            value17 = value17 + 0x300;
          } while (value6 < (intptr_t)(uint32_t)*(uint8_t *)((intptr_t)self + 0x34));
        }
        *(uint32_t *)((intptr_t)self + 0x20) = **(uint32_t **)((intptr_t)self + 0x24);
      }
      *(uint8_t *)((intptr_t)self + 0x35) = 0;
      *(int *)((intptr_t)self + 0x28) = *(int *)((intptr_t)self + 0x20) + 4;
    }
    if ((*(uint8_t *)((intptr_t)self + 4) & 0x10) == 0) {
      Sprite_ConvertRGB555to565(self,arg1);
    }
  }
  else {
    if (flag3 == 8) {
      if (flag2) {
        value9 = (uint32_t)*(uint8_t *)((intptr_t)self + 0x34) << 2;
      }
      else {
        value9 = (uint32_t)*(uint8_t *)((intptr_t)self + 0x34) * 0x300;
      }
    }
    else {
      value9 = 0;
    }
    uvalue10 = 0xffffffff;
    *(uint32_t *)((intptr_t)self + 0x2c) = 0;
    *(uint8_t *)((intptr_t)self + 0x38) = 1;
    *(uint8_t *)((intptr_t)self + 0x39) = 0;
    pCVar16 = arg3;
    do {
      if (uvalue10 == 0) break;
      uvalue10 = uvalue10 - 1;
      cVar1 = *pCVar16;
      pCVar16 = pCVar16 + 1;
    } while (cVar1 != '\0');
    cptr5 = operator_new(~uvalue10);
    uvalue10 = 0xffffffff;
    *(char **)((intptr_t)self + 0x3c) = cptr5;
    do {
      cptr14 = arg3;
      if (uvalue10 == 0) break;
      uvalue10 = uvalue10 - 1;
      cptr14 = arg3 + 1;
      cVar1 = *arg3;
      arg3 = cptr14;
    } while (cVar1 != '\0');
    uvalue10 = ~uvalue10;
    cptr14 = cptr14 + -uvalue10;
    for (uvalue11 = uvalue10 >> 2; uvalue11 != 0; uvalue11 = uvalue11 - 1) {
      *(uint32_t *)cptr5 = *(uint32_t *)cptr14;
      cptr14 = cptr14 + 4;
      cptr5 = cptr5 + 4;
    }
    value6 = uvalue13 - value9;
    for (uvalue10 = uvalue10 & 3; uvalue10 != 0; uvalue10 = uvalue10 - 1) {
      *cptr5 = *cptr14;
      cptr14 = cptr14 + 1;
      cptr5 = cptr5 + 1;
    }
    *(uint32_t *)((intptr_t)self + 0x40) = 0x21;
    *(int *)((intptr_t)self + 0x44) = value6;
    *(void **)((intptr_t)self + 0x48) = arg2;
    if (value9 == 0) {
      Resource_Close(arg2,(intptr_t)local_348);
    }
    else if (*(char *)((intptr_t)self + 0x34) == '\x01') {
      if ((*(char *)((intptr_t)arg1 + 0x18) == '\0') || ((*(uint8_t *)((intptr_t)self + 4) & 0x10) != 0)) {
        value9 = 0;
      }
      else {
        value9 = 1;
      }
      Stream_Seek(value6 + 0x21,(intptr_t)local_348,0);
      if (flag2) {
        Resource_Read(arg2,(char *)&local_338,4,(intptr_t)local_348);
        ptr7 = (int *)Array_GetPtrChecked(arg6,local_338);
      }
      else {
        Resource_Read(arg2,local_30c,0x300,(intptr_t)local_348);
        pvVar4 = operator_new(0x20c);
        local_4 = (local_4 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
        if (pvVar4 == (void *)0x0) {
          ptr7 = (int *)0x0;
        }
        else {
          ptr7 = Palette_Init(pvVar4,value9,(uint32_t *)local_30c,arg7);
        }
        local_4 = (uint32_t)((uint8_t)((local_4) >> 24)) << 8;
      }
      *(int **)((intptr_t)self + 0x20) = ptr7;
      *(uint8_t *)((intptr_t)self + 0x35) = 0;
      *(int **)((intptr_t)self + 0x28) = ptr7 + 1;
      Resource_Close(arg2,(intptr_t)local_348);
    }
    else {
      if ((*(char *)((intptr_t)arg1 + 0x18) == '\0') ||
         (local_344 = 1, (*(uint8_t *)((intptr_t)self + 4) & 0x10) != 0)) {
        local_344 = 0;
      }
      Stream_Seek(value6 + 0x21,(intptr_t)local_348,0);
      value9 = 0;
      if (*(char *)((intptr_t)self + 0x34) != '\0') {
        do {
          if (flag2) {
            Resource_Read(arg2,(char *)&local_338,4,(intptr_t)local_348);
            uvalue8 = Array_GetPtrChecked(arg6,local_338);
            *(uint32_t *)(*(int *)((intptr_t)self + 0x24) + value9 * 4) = uvalue8;
          }
          else {
            Resource_Read(arg2,local_30c,0x300,(intptr_t)local_348);
            pvVar4 = operator_new(0x20c);
            local_4 = (local_4 & ~(0x0u << 8)) | (((2) & 0x0u) << 8);
            if (pvVar4 == (void *)0x0) {
              ptr7 = (int *)0x0;
            }
            else {
              ptr7 = Palette_Init(pvVar4,local_344,(uint32_t *)local_30c,arg7);
            }
            local_4 = (uint32_t)((uint8_t)((local_4) >> 24)) << 8;
            *(int **)(*(int *)((intptr_t)self + 0x24) + value9 * 4) = ptr7;
          }
          value9 = value9 + 1;
        } while (value9 < (intptr_t)(uint32_t)*(uint8_t *)((intptr_t)self + 0x34));
      }
      value9 = **(int **)((intptr_t)self + 0x24);
      *(int *)((intptr_t)self + 0x20) = value9;
      *(uint8_t *)((intptr_t)self + 0x35) = 0;
      *(int *)((intptr_t)self + 0x28) = value9 + 4;
      Resource_Close(arg2,(intptr_t)local_348);
    }
  }
  if (arg4 != (uint32_t *)0x0) {
    *arg4 = 0;
  }
  ExceptionList = local_c;
  return self;
}
