// Anim_Load: ported from Pizza Connection 2 at 0x532c40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x532c40
#include "pc2_port.h"


uint32_t * __thiscall
Anim_Load(void *self,int arg1,void *arg2,LPCSTR arg3,uint32_t *arg4,int arg5)

{
  char cVar1;
  uint16_t uvalue2;
  bool flag3;
  FILE *pFVar4;
  char *cptr5;
  void *pvVar6;
  int *ptr7;
  uint32_t uvalue8;
  uint32_t uvalue9;
  uint16_t *uptr10;
  int value11;
  uint32_t uvalue12;
  char *cptr13;
  uint16_t *uptr14;
  uint32_t *uptr15;
  int value16;
  LPCSTR pCVar17;
  int *local_3c0;
  uint32_t local_3b8;
  uint32_t local_3b4;
  void *local_3b0;
  int local_3ac;
  void *local_3a8;
  char local_3a4 [152];
  char local_30c [768];
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Loads a .ani animation object from file or archive. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055ac87;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_3a8 = self;
  SpriteBase_Construct(self);
  *(uint32_t *)((intptr_t)self + 0x90) = 0;
  local_4 = 0;
  *(uint8_t ***)self = &PTR_Animation_ScalarDeletingDestructor_0055c80c;
  flag3 = false;
  *(uint8_t *)((intptr_t)self + 0x34) = 0;
  *(uint8_t *)((intptr_t)self + 0x35) = 1;
  *(uint32_t *)((intptr_t)self + 0x38) = 0;
  *(uint32_t *)((intptr_t)self + 0x78) = 0;
  *(uint32_t *)((intptr_t)self + 0x94) = 0x3ff00000;
  *(uint32_t *)((intptr_t)self + 0x20) = 0;
  *(uint32_t *)((intptr_t)self + 0x80) = 0;
  *(uint32_t *)((intptr_t)self + 0x50) = 0;
  *(uint32_t *)((intptr_t)self + 0x4c) = 0;
  if (arg4 != (uint32_t *)0x0) {
    *arg4 = 0;
  }
  if (arg2 == (void *)0x0) {
    pFVar4 = (FILE *)CRT_Fopen(arg3,&DAT_00563184);
    if (pFVar4 == (FILE *)0x0) {
      if (arg4 != (uint32_t *)0x0) {
        *arg4 = 0x191;
        ExceptionList = local_c;
        return self;
      }
      NoOp_Stub();
    }
    ptr7 = (int *)((intptr_t)self + 100);
    CRT_FreadLocked((char *)ptr7,1,0x14,(int *)pFVar4);
    CRT_FreadLocked((char *)((intptr_t)self + 4),1,0x1c,(int *)pFVar4);
    if ((((*(uint32_t *)((intptr_t)self + 0x70) & 0xffff0000) != 0xca420000) ||
        (local_3b4 = *(uint32_t *)((intptr_t)self + 0x70) & 0xffff, local_3b4 == 0)) || (2 < local_3b4)) {
      flag3 = true;
      local_3b4 = 0;
    }
    if ((*ptr7 < 0) || (500 < *ptr7)) {
      if (arg4 != (uint32_t *)0x0) {
        *arg4 = 0x192;
        ExceptionList = local_c;
        return self;
      }
      NoOp_Stub();
    }
    if (*ptr7 < 1) {
      *ptr7 = 4;
      uptr15 = operator_new(0x260);
      *(uint32_t **)((intptr_t)self + 0x50) = uptr15;
      for (value16 = 0x98; value16 != 0; value16 = value16 + -1) {
        *uptr15 = 0;
        uptr15 = uptr15 + 1;
      }
    }
    else {
      cptr5 = operator_new(*ptr7 * 0x98);
      *(char **)((intptr_t)self + 0x50) = cptr5;
      if (flag3) {
        value16 = 0;
        if (0 < *ptr7) {
          local_3c0 = (int *)0x0;
          do {
            CRT_FreadLocked(local_3a4,1,0x98,(int *)pFVar4);
            Record_CopyTemplate98(local_3a4,(intptr_t)local_3c0 + *(int *)((intptr_t)self + 0x50));
            value16 = value16 + 1;
            local_3c0 = local_3c0 + 0x26;
          } while (value16 < *ptr7);
        }
      }
      else {
        CRT_FreadLocked(cptr5,1,*ptr7 * 0x98,(int *)pFVar4);
      }
    }
    CRT_FreadLocked((char *)&local_3b8,1,4,(int *)pFVar4);
    cptr5 = operator_new(local_3b8);
    CRT_FreadLocked(cptr5,1,local_3b8,(int *)pFVar4);
    CRT_Fclose(pFVar4);
  }
  else {
    local_3c0 = Resource_Open(arg2,arg3,0);
    if (local_3c0 == (int *)0x0) {
      if (arg4 != (uint32_t *)0x0) {
        *arg4 = 0x192;
        ExceptionList = local_c;
        return self;
      }
      NoOp_Stub();
    }
    ptr7 = (int *)((intptr_t)self + 100);
    Resource_Read(arg2,(char *)ptr7,0x14,(intptr_t)local_3c0);
    Resource_Read(arg2,(char *)((intptr_t)self + 4),0x1c,(intptr_t)local_3c0);
    if ((((*(uint32_t *)((intptr_t)self + 0x70) & 0xffff0000) != 0xca420000) ||
        (local_3b4 = *(uint32_t *)((intptr_t)self + 0x70) & 0xffff, local_3b4 == 0)) || (2 < local_3b4)) {
      flag3 = true;
      local_3b4 = 0;
    }
    cptr5 = operator_new(*ptr7 * 0x98);
    *(char **)((intptr_t)self + 0x50) = cptr5;
    if (flag3) {
      local_3b0 = (void *)0x0;
      if (0 < *ptr7) {
        local_3ac = 0;
        do {
          Resource_Read(arg2,local_3a4,0x98,(intptr_t)local_3c0);
          Record_CopyTemplate98(local_3a4,local_3ac + *(int *)((intptr_t)self + 0x50));
          local_3b0 = (void *)((intptr_t)local_3b0 + 1);
          local_3ac = local_3ac + 0x98;
        } while ((intptr_t)local_3b0 < *ptr7);
      }
    }
    else {
      Resource_Read(arg2,cptr5,*ptr7 * 0x98,(intptr_t)local_3c0);
    }
    Resource_Read(arg2,(char *)&local_3b8,4,(intptr_t)local_3c0);
    local_3b8 = local_3b8 - 4;
    if (arg5 == 0) {
      cptr5 = operator_new(local_3b8);
      Resource_Read(arg2,cptr5,local_3b8,(intptr_t)local_3c0);
    }
    else {
      value16 = 8;
      if (flag3) {
        value16 = 9;
      }
      if ((intptr_t)local_3b4 < 2) {
        value16 = value16 + 2;
      }
      else {
        value16 = value16 + 4;
      }
      uvalue12 = *(int *)((intptr_t)self + 0x68) * value16;
      if (*(uint8_t *)((intptr_t)self + 5) < 9) {
        value16 = (local_3b8 - uvalue12) + -0x300;
      }
      else {
        value16 = local_3b8 - uvalue12;
      }
      *(int *)((intptr_t)self + 0x40) = value16;
      *(void **)((intptr_t)self + 0x44) = arg2;
      uvalue8 = 0xffffffff;
      *(uint8_t *)((intptr_t)self + 0x34) = 1;
      *(uint8_t *)((intptr_t)self + 0x35) = 0;
      pCVar17 = arg3;
      do {
        if (uvalue8 == 0) break;
        uvalue8 = uvalue8 - 1;
        cVar1 = *pCVar17;
        pCVar17 = pCVar17 + 1;
      } while (cVar1 != '\0');
      cptr5 = operator_new(~uvalue8);
      uvalue8 = 0xffffffff;
      *(char **)((intptr_t)self + 0x38) = cptr5;
      do {
        cptr13 = arg3;
        if (uvalue8 == 0) break;
        uvalue8 = uvalue8 - 1;
        cptr13 = arg3 + 1;
        cVar1 = *arg3;
        arg3 = cptr13;
      } while (cVar1 != '\0');
      uvalue8 = ~uvalue8;
      cptr13 = cptr13 + -uvalue8;
      for (uvalue9 = uvalue8 >> 2; uvalue9 != 0; uvalue9 = uvalue9 - 1) {
        *(uint32_t *)cptr5 = *(uint32_t *)cptr13;
        cptr13 = cptr13 + 4;
        cptr5 = cptr5 + 4;
      }
      for (uvalue8 = uvalue8 & 3; uvalue8 != 0; uvalue8 = uvalue8 - 1) {
        *cptr5 = *cptr13;
        cptr13 = cptr13 + 1;
        cptr5 = cptr5 + 1;
      }
      cptr5 = operator_new(uvalue12);
      Resource_Read(arg2,cptr5,uvalue12,(intptr_t)local_3c0);
      *(int *)((intptr_t)self + 0x3c) = local_3c0[4];
    }
  }
  value16 = *(int *)((intptr_t)self + 0x68);
  *(char **)((intptr_t)self + 0x20) = cptr5;
  value11 = value16 * 2;
  cptr5 = cptr5 + value11;
  *(char **)((intptr_t)self + 0x24) = cptr5;
  cptr5 = cptr5 + value11;
  *(char **)((intptr_t)self + 0x28) = cptr5;
  *(char **)((intptr_t)self + 0x2c) = cptr5 + value11;
  uptr14 = (uint16_t *)(cptr5 + value11 + value11);
  if ((intptr_t)local_3b4 < 2) {
    pvVar6 = operator_new(value16 << 2);
    *(void **)((intptr_t)self + 0x30) = pvVar6;
    value16 = 0;
    *(uint32_t *)((intptr_t)self + 0x88) = 1;
    if (0 < *(int *)((intptr_t)self + 0x68)) {
      uptr10 = uptr14;
      do {
        uvalue2 = *uptr10;
        uptr10 = uptr10 + 1;
        *(uint32_t *)(*(int *)((intptr_t)self + 0x30) + value16 * 4) = (uint32_t)uvalue2;
        value16 = value16 + 1;
      } while (value16 < *(int *)((intptr_t)self + 0x68));
    }
    value16 = *(int *)((intptr_t)self + 0x68);
    value11 = value16 * 2;
  }
  else {
    *(uint16_t **)((intptr_t)self + 0x30) = uptr14;
    *(uint32_t *)((intptr_t)self + 0x88) = 0;
    value11 = value16 * 4;
  }
  uptr15 = (uint32_t *)((intptr_t)uptr14 + value11);
  if (flag3) {
    uptr15 = (uint32_t *)((intptr_t)uptr15 + value16);
  }
  pvVar6 = operator_new(value16 << 2);
  *(void **)((intptr_t)self + 0x80) = pvVar6;
  if (*(char *)((intptr_t)self + 0x34) == '\0') {
    value16 = 0;
    if (0 < *(int *)((intptr_t)self + 0x68)) {
      do {
        if (*(int *)(*(int *)((intptr_t)self + 0x30) + value16 * 4) == 0) {
          *(uint32_t *)(*(int *)((intptr_t)self + 0x80) + value16 * 4) = 0;
        }
        else {
          *(uint32_t **)(*(int *)((intptr_t)self + 0x80) + value16 * 4) = uptr15;
        }
        uptr15 = (uint32_t *)((intptr_t)uptr15 + *(int *)(*(int *)((intptr_t)self + 0x30) + value16 * 4));
        value16 = value16 + 1;
      } while (value16 < *(int *)((intptr_t)self + 0x68));
    }
  }
  else {
    value16 = 0;
    if (0 < *(int *)((intptr_t)self + 0x68)) {
      do {
        value16 = value16 + 1;
        *(uint32_t *)(*(int *)((intptr_t)self + 0x80) + -4 + value16 * 4) = 0;
      } while (value16 < *(int *)((intptr_t)self + 0x68));
    }
  }
  if (8 < *(uint8_t *)((intptr_t)self + 5)) {
    *(uint32_t *)((intptr_t)self + 0x78) = 0;
    *(uint32_t *)((intptr_t)self + 0x7c) = 0;
    if ((((*(char *)((intptr_t)self + 0x35) != '\0') && (*(char *)(arg1 + 0x18) != '\0')) &&
        ((*(uint8_t *)((intptr_t)self + 4) & 0x10) == 0)) && (value16 = 0, 0 < *(int *)((intptr_t)self + 0x68))) {
      do {
        uptr14 = *(uint16_t **)(*(int *)((intptr_t)self + 0x80) + value16 * 4);
        value11 = 0;
        if (*(uint32_t *)(*(int *)((intptr_t)self + 0x30) + value16 * 4) >> 1 != 0) {
          do {
            uvalue2 = *uptr14;
            if ((uint32_t)uvalue2 == *(uint32_t *)((intptr_t)self + 0x1c)) {
              value11 = value11 + 1;
              uptr14 = uptr14 + 1;
            }
            else {
              *uptr14 = (uvalue2 & 0xffe0) << 1 | uvalue2 & 0x1f;
            }
            value11 = value11 + 1;
            uptr14 = uptr14 + 1;
          } while (value11 < (intptr_t)(*(uint32_t *)(*(int *)((intptr_t)self + 0x30) + value16 * 4) >> 1));
        }
        value16 = value16 + 1;
      } while (value16 < *(int *)((intptr_t)self + 0x68));
    }
    goto LAB_005332d0;
  }
  if ((*(char *)(arg1 + 0x18) == '\0') || ((*(uint8_t *)((intptr_t)self + 4) & 0x10) != 0)) {
    value16 = 0;
  }
  else {
    value16 = 1;
  }
  if (*(char *)((intptr_t)self + 0x35) == '\0') {
    Stream_Seek(*(int *)((intptr_t)self + 0x40) + *(int *)((intptr_t)self + 0x3c),(intptr_t)local_3c0,0);
    Resource_Read(arg2,local_30c,0x300,(intptr_t)local_3c0);
    local_3b0 = operator_new(0x20c);
    local_4 = CONCAT31(((uint8_t)((local_4) >> 24)),1);
    if (local_3b0 == (void *)0x0) {
LAB_00533237:
      ptr7 = (int *)0x0;
    }
    else {
      ptr7 = Palette_Init(local_3b0,value16,(uint32_t *)local_30c,0);
    }
  }
  else {
    local_3b0 = operator_new(0x20c);
    local_4 = CONCAT31(((uint8_t)((local_4) >> 24)),2);
    if (local_3b0 == (void *)0x0) goto LAB_00533237;
    ptr7 = Palette_Init(local_3b0,value16,uptr15,0);
  }
  *(int **)((intptr_t)self + 0x78) = ptr7;
  local_4 = local_4 & 0xffffff00;
  *(int **)((intptr_t)self + 0x7c) = ptr7 + 1;
LAB_005332d0:
  Resource_Close(arg2,(intptr_t)local_3c0);
  *(uint32_t *)((intptr_t)self + 0x48) = 0;
  *(uint32_t *)((intptr_t)self + 0x4c) = 0;
  *(uint32_t *)((intptr_t)self + 0x54) = 0xfffffc19;
  ExceptionList = local_c;
  return self;
}
