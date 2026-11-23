// IsoMap_DeserializeGrid: ported from Pizza Connection 2 at 0x4eb900.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4eb900
#include "pc2_port.h"


void __thiscall IsoMap_DeserializeGrid(void *self,void *arg1)

{
  int *ptr1;
  char cVar2;
  uint8_t flag3;
  void *pvVar4;
  int value5;
  int value6;
  char *cptr7;
  uint32_t *uptr8;
  uint32_t uvalue9;
  uint32_t uvalue10;
  uint8_t *bptr11;
  char *cptr12;
  char *cptr13;
  bool flag14;
  int local_240;
  int local_23c;
  uint32_t local_238;
  uint8_t *local_234;
  uint8_t *local_230;
  uint8_t local_229;
  int local_228;
  void *local_224;
  int local_220;
  int local_21c;
  int local_218;
  uint8_t local_214 [4];
  uint32_t local_210;
  char local_10c [256];
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Deserializes an iso-map grid, tiles, names, and sprite. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00559fec;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CRT_Istream_Read(arg1,local_214,4);
  CRT_Istream_Read(arg1,&local_218,4);
  CRT_Istream_Read(arg1,(intptr_t)self + 0xc,4);
  CRT_Istream_Read(arg1,(intptr_t)self + 0x10,4);
  CRT_Istream_Read(arg1,(intptr_t)self + 0x14,4);
  CRT_Istream_Read(arg1,(intptr_t)self + 0x18,4);
  ptr1 = (int *)((intptr_t)self + 0x1c);
  CRT_Istream_Read(arg1,ptr1,4);
  CRT_Istream_Read(arg1,(intptr_t)self + 0x20,4);
  CRT_Istream_Read(arg1,(uint32_t *)((intptr_t)self + 0x24),4);
  CRT_Istream_Read(arg1,(intptr_t)self + 0x28,4);
  *(uint32_t *)((intptr_t)self + 0xe8) = *(uint32_t *)((intptr_t)self + 0x24);
  *(uint32_t *)((intptr_t)self + 0xec) = *(uint32_t *)((intptr_t)self + 0x28);
  CRT_Istream_Read(arg1,(intptr_t)self + 0x2c,4);
  CRT_Istream_Read(arg1,(intptr_t)self + 0x30,4);
  CRT_Istream_Read(arg1,(intptr_t)self + 0x34,4);
  CRT_Istream_Read(arg1,(intptr_t)self + 0x38,4);
  CRT_Istream_Read(arg1,(uint32_t *)((intptr_t)self + 0x3c),0x10);
  *(uint32_t *)((intptr_t)self + 0x3c) = 1;
  *(uint32_t *)((intptr_t)self + 0x40) = 1;
  *(uint32_t *)((intptr_t)self + 0x44) = 0;
  *(uint32_t *)((intptr_t)self + 0x48) = 0;
  CRT_Istream_Read(arg1,(intptr_t)self + 0x60,4);
  *(uint32_t *)((intptr_t)self + 0x60) = 0;
  CRT_Istream_Read(arg1,(intptr_t)self + 0x6c,4);
  CRT_Istream_Read(arg1,(intptr_t)self + 0x7c,0x1e);
  CRT_Istream_Read(arg1,(intptr_t)self + 0xba,2);
  CRT_Istream_Read(arg1,(intptr_t)self + 0xf0,4);
  pvVar4 = operator_new(*(int *)((intptr_t)self + 0x20) * *ptr1 * 0xc);
  *(void **)((intptr_t)self + 0x4c) = pvVar4;
  pvVar4 = operator_new(0xc);
  *(void **)((intptr_t)self + 100) = pvVar4;
  pvVar4 = operator_new(0x3c);
  *(void **)(*(int *)((intptr_t)self + 100) + 8) = pvVar4;
  value5 = *(int *)((intptr_t)self + 0x20) * *ptr1;
  *(int *)((intptr_t)self + 0x13c) = value5;
  pvVar4 = operator_new(value5 * 0x3c);
  *(void **)((intptr_t)self + 0x138) = pvVar4;
  *(uint32_t *)((intptr_t)self + 0x58) = 0xffffffff;
  *(uint32_t *)((intptr_t)self + 0x5c) = 0xffffffff;
  local_234 = (uint8_t *)0x0;
  *(uint32_t *)((intptr_t)self + 0x50) = 0;
  *(uint32_t *)((intptr_t)self + 0x54) = 0;
  *(uint32_t *)((intptr_t)self + 0x68) = 0;
  *(uint32_t *)((intptr_t)self + 0xac) = 0xffff;
  *(uint8_t *)((intptr_t)self + 0xb8) = 0;
  *(uint32_t *)((intptr_t)self + 0xbc) = 0;
  *(uint32_t *)((intptr_t)self + 0xf4) = 1;
  *(uint32_t *)((intptr_t)self + 0xf8) = 0xa0;
  *(uint32_t *)((intptr_t)self + 0xfc) = 0xd0;
  InitializeCriticalSection((LPCRITICAL_SECTION)((intptr_t)self + 0xc0));
  Map_ComputeIsoOffsets((intptr_t)self);
  Surface_AliasPixelPlanes((intptr_t)self);
  *(uint32_t *)((intptr_t)self + 0x9c) = 0;
  *(uint32_t *)((intptr_t)self + 0xa0) = 0;
  pvVar4 = operator_new(0x28);
  ptr1 = (int *)((intptr_t)self + 0xa4);
  *(void **)((intptr_t)self + 0xb0) = pvVar4;
  *(uint32_t *)((intptr_t)self + 0xb4) = 0;
  CRT_Istream_Read(arg1,ptr1,4);
  CRT_Istream_Read(arg1,(intptr_t)self + 0xa8,4);
  if (0 < *ptr1) {
    pvVar4 = operator_new(*ptr1 * 0x28);
    *(void **)((intptr_t)self + 0x9c) = pvVar4;
  }
  if (0 < *(int *)((intptr_t)self + 0xa8)) {
    pvVar4 = operator_new(*(int *)((intptr_t)self + 0xa8) * 0x28);
    *(void **)((intptr_t)self + 0xa0) = pvVar4;
  }
  local_23c = 0;
  if (0 < *ptr1) {
    value5 = 0;
    do {
      CRT_Istream_Read(arg1,*(int *)((intptr_t)self + 0x9c) + value5,1);
      CRT_Istream_Read(arg1,*(int *)((intptr_t)self + 0x9c) + 2 + value5,2);
      *(uint16_t *)(*(int *)((intptr_t)self + 0x9c) + 4 + value5) = (uint16_t)local_23c;
      CRT_Istream_Read(arg1,*(int *)((intptr_t)self + 0x9c) + 6 + value5,1);
      CRT_Istream_Read(arg1,&local_229,1);
      CRT_Istream_Read(arg1,*(int *)((intptr_t)self + 0x9c) + 8 + value5,4);
      CRT_Istream_Read(arg1,*(int *)((intptr_t)self + 0x9c) + 0xc + value5,4);
      CRT_Istream_Read(arg1,*(int *)((intptr_t)self + 0x9c) + 0x10 + value5,4);
      CRT_Istream_Read(arg1,*(int *)((intptr_t)self + 0x9c) + 0x14 + value5,0x10);
      CRT_Istream_Read(arg1,*(int *)((intptr_t)self + 0x9c) + 0x24 + value5,1);
      value5 = value5 + 0x28;
      *(uint8_t *)(*(int *)((intptr_t)self + 0x9c) + -0x28 + value5) = 0;
      local_23c = local_23c + 1;
    } while (local_23c < *(int *)((intptr_t)self + 0xa4));
  }
  local_23c = 0;
  if (0 < *(int *)((intptr_t)self + 0xa8)) {
    value5 = 0;
    do {
      CRT_Istream_Read(arg1,value5 + *(int *)((intptr_t)self + 0xa0),1);
      CRT_Istream_Read(arg1,value5 + 2 + *(int *)((intptr_t)self + 0xa0),2);
      *(uint16_t *)(value5 + 4 + *(int *)((intptr_t)self + 0xa0)) = (uint16_t)local_23c;
      CRT_Istream_Read(arg1,value5 + 6 + *(int *)((intptr_t)self + 0xa0),1);
      CRT_Istream_Read(arg1,&local_229,1);
      CRT_Istream_Read(arg1,value5 + 8 + *(int *)((intptr_t)self + 0xa0),4);
      CRT_Istream_Read(arg1,value5 + 0xc + *(int *)((intptr_t)self + 0xa0),4);
      CRT_Istream_Read(arg1,value5 + 0x10 + *(int *)((intptr_t)self + 0xa0),4);
      CRT_Istream_Read(arg1,value5 + 0x14 + *(int *)((intptr_t)self + 0xa0),0x10);
      CRT_Istream_Read(arg1,value5 + 0x24 + *(int *)((intptr_t)self + 0xa0),1);
      local_23c = local_23c + 1;
      *(uint8_t *)(value5 + *(int *)((intptr_t)self + 0xa0)) = 0;
      value5 = value5 + 0x28;
    } while (local_23c < *(int *)((intptr_t)self + 0xa8));
  }
  value5 = *(int *)((intptr_t)self + 0x20);
  value6 = 0;
  local_240 = 0;
  local_224 = (void *)0x0;
  if (0 < value5) {
    do {
      local_23c = (value5 - (intptr_t)local_224) * *(int *)((intptr_t)self + 0xc) >> 1;
      value5 = *(int *)((intptr_t)self + 0x10) * (intptr_t)local_224 >> 1;
      local_21c = 0;
      if (0 < *(int *)((intptr_t)self + 0x1c)) {
        local_230 = (uint8_t *)((intptr_t)local_234 * 0x3c);
        do {
          *(uint8_t **)(*(int *)((intptr_t)self + 0x4c) + 8 + value6 * 0xc) =
               local_230 + *(int *)((intptr_t)self + 0x138);
          local_234 = local_234 + 1;
          local_230 = local_230 + 0x3c;
          *(int *)(*(int *)((intptr_t)self + 0x4c) + local_240 * 0xc) = local_23c;
          *(int *)(*(int *)((intptr_t)self + 0x4c) + 4 + local_240 * 0xc) = value5;
          **(int **)(*(int *)((intptr_t)self + 0x4c) + 8 + local_240 * 0xc) = local_240;
          *(uint32_t *)(*(int *)(*(int *)((intptr_t)self + 0x4c) + 8 + local_240 * 0xc) + 0x20) = 0;
          *(uint16_t *)(*(int *)(*(int *)((intptr_t)self + 0x4c) + 8 + local_240 * 0xc) + 0x24) =
               0xffff;
          *(uint32_t *)(*(int *)(*(int *)((intptr_t)self + 0x4c) + 8 + local_240 * 0xc) + 0x28) = 0;
          *(uint8_t *)(*(int *)(*(int *)((intptr_t)self + 0x4c) + 8 + local_240 * 0xc) + 0x2c) = 0;
          *(uint8_t *)(*(int *)(*(int *)((intptr_t)self + 0x4c) + 8 + local_240 * 0xc) + 0x2d) = 0;
          *(uint8_t *)(*(int *)(*(int *)((intptr_t)self + 0x4c) + 8 + local_240 * 0xc) + 0x2e) = 0;
          *(uint8_t *)(*(int *)(*(int *)((intptr_t)self + 0x4c) + 8 + local_240 * 0xc) + 0x2f) = 0;
          *(uint32_t *)(*(int *)(*(int *)((intptr_t)self + 0x4c) + 8 + local_240 * 0xc) + 0x30) =
               0xffffffff;
          *(uint32_t *)(*(int *)(*(int *)((intptr_t)self + 0x4c) + 8 + local_240 * 0xc) + 0x34) = 0;
          *(uint32_t *)(*(int *)(*(int *)((intptr_t)self + 0x4c) + 8 + local_240 * 0xc) + 0x38) = 0;
          *(uint32_t *)(*(int *)(*(int *)((intptr_t)self + 0x4c) + 8 + local_240 * 0xc) + 0xc) = 0;
          *(uint32_t *)(*(int *)(*(int *)((intptr_t)self + 0x4c) + 8 + local_240 * 0xc) + 0x18) = 0;
          *(uint32_t *)(*(int *)(*(int *)((intptr_t)self + 0x4c) + 8 + local_240 * 0xc) + 8) = 0;
          *(uint32_t *)(*(int *)(*(int *)((intptr_t)self + 0x4c) + 8 + local_240 * 0xc) + 0x14) = 0;
          *(uint32_t *)(*(int *)(*(int *)((intptr_t)self + 0x4c) + 8 + local_240 * 0xc) + 4) =
               0xffffffff;
          *(uint32_t *)(*(int *)(*(int *)((intptr_t)self + 0x4c) + 8 + local_240 * 0xc) + 0x10) =
               0xffffffff;
          *(uint32_t *)(*(int *)(*(int *)((intptr_t)self + 0x4c) + 8 + local_240 * 0xc) + 0x1c) =
               0xffffffff;
          local_23c = local_23c + (*(int *)((intptr_t)self + 0xc) >> 1);
          value5 = value5 + (*(int *)((intptr_t)self + 0x10) >> 1);
          value6 = local_240 + 1;
          local_21c = local_21c + 1;
          local_240 = value6;
        } while (local_21c < *(int *)((intptr_t)self + 0x1c));
      }
      value5 = *(int *)((intptr_t)self + 0x20);
      local_224 = (void *)((intptr_t)local_224 + 1);
    } while ((intptr_t)local_224 < value5);
  }
  local_23c = 0;
  if (0 < *(int *)((intptr_t)self + 0x20) * *(int *)((intptr_t)self + 0x1c)) {
    do {
      value5 = local_23c;
      CRT_Istream_Read(arg1,&local_228,4);
      if (local_228 == 1) {
        CRT_Istream_Read(arg1,&local_240,4);
        local_23c = value5 + local_240;
      }
      else {
        value5 = value5 * 0xc;
        CRT_Istream_Read(arg1,*(uint32_t *)(value5 + 8 + *(int *)((intptr_t)self + 0x4c)),4);
        CRT_Istream_Read(arg1,*(int *)(value5 + 8 + *(int *)((intptr_t)self + 0x4c)) + 0x24,2);
        CRT_Istream_Read(arg1,*(int *)(value5 + 8 + *(int *)((intptr_t)self + 0x4c)) + 0x30,4);
        CRT_Istream_Read(arg1,*(int *)(value5 + 8 + *(int *)((intptr_t)self + 0x4c)) + 0x34,4);
        CRT_Istream_Read(arg1,*(int *)(value5 + 8 + *(int *)((intptr_t)self + 0x4c)) + 0x38,4);
        value6 = *(int *)(value5 + 8 + *(int *)((intptr_t)self + 0x4c));
        *(uint32_t *)(value6 + 0x38) = (uint32_t)(*(int *)(value6 + 0x38) == 1);
        CRT_Istream_Read(arg1,*(int *)(value5 + 8 + *(int *)((intptr_t)self + 0x4c)) + 0x28,4);
        CRT_Istream_Read(arg1,*(int *)(value5 + 8 + *(int *)((intptr_t)self + 0x4c)) + 0x1c,4);
        CRT_Istream_Read(arg1,*(int *)(value5 + 8 + *(int *)((intptr_t)self + 0x4c)) + 0x2c,1);
        CRT_Istream_Read(arg1,*(int *)(value5 + 8 + *(int *)((intptr_t)self + 0x4c)) + 0x2d,1);
        CRT_Istream_Read(arg1,*(int *)(value5 + 8 + *(int *)((intptr_t)self + 0x4c)) + 0x2e,1);
        CRT_Istream_Read(arg1,*(int *)(value5 + 8 + *(int *)((intptr_t)self + 0x4c)) + 0x2f,1);
        CRT_Istream_Read(arg1,&local_238,4);
        local_238 = Game_GetMapValue(*(void **)((intptr_t)self + 4),local_238);
        if ((local_218 == 0) && (-1 < (intptr_t)local_238)) {
          CRT_Istream_Read(arg1,&local_210,0x32);
          local_234 = (uint8_t *)(*(int *)((intptr_t)self + 4) + 0x25 + local_238 * 0x48);
          local_230 = (uint8_t *)&local_210;
          do {
            flag3 = *local_230;
            flag14 = flag3 < *local_234;
            if (flag3 != *local_234) {
LAB_004ec16e:
              value6 = (1 - (uint32_t)flag14) - (uint32_t)(flag14 != 0);
              goto LAB_004ec173;
            }
            if (flag3 == 0) break;
            flag3 = local_230[1];
            flag14 = flag3 < local_234[1];
            if (flag3 != local_234[1]) goto LAB_004ec16e;
            local_230 = local_230 + 2;
            local_234 = local_234 + 2;
          } while (flag3 != 0);
          value6 = 0;
LAB_004ec173:
          if (value6 != 0) {
            uvalue9 = World_FindNameIndex(*(void **)((intptr_t)self + 4),&local_210);
            local_238 = (uint32_t)(short)uvalue9;
            if (local_238 == 0xffffffff) {
              local_238 = Map_MissingNameFallback();
            }
          }
        }
        *(uint32_t *)(*(int *)(value5 + 8 + *(int *)((intptr_t)self + 0x4c)) + 4) = local_238;
        Map_BuildElementAnimationList
                  (self,local_238,*(int *)(value5 + 8 + *(int *)((intptr_t)self + 0x4c)) + 4);
        CRT_Istream_Read(arg1,&local_238,4);
        local_238 = Game_GetMapValue(*(void **)((intptr_t)self + 4),local_238);
        if ((local_218 == 0) && (-1 < (intptr_t)local_238)) {
          CRT_Istream_Read(arg1,&local_210,0x32);
          local_234 = (uint8_t *)(*(int *)((intptr_t)self + 4) + 0x25 + local_238 * 0x48);
          bptr11 = (uint8_t *)&local_210;
          do {
            flag3 = *bptr11;
            flag14 = flag3 < *local_234;
            if (flag3 != *local_234) {
LAB_004ec256:
              value6 = (1 - (uint32_t)flag14) - (uint32_t)(flag14 != 0);
              goto LAB_004ec25b;
            }
            if (flag3 == 0) break;
            flag3 = bptr11[1];
            flag14 = flag3 < local_234[1];
            if (flag3 != local_234[1]) goto LAB_004ec256;
            bptr11 = bptr11 + 2;
            local_234 = local_234 + 2;
          } while (flag3 != 0);
          value6 = 0;
LAB_004ec25b:
          if (value6 != 0) {
            uvalue9 = World_FindNameIndex(*(void **)((intptr_t)self + 4),&local_210);
            local_238 = (uint32_t)(short)uvalue9;
            if (local_238 == 0xffffffff) {
              local_238 = Map_MissingNameFallback();
            }
          }
        }
        *(uint32_t *)(*(int *)(value5 + 8 + *(int *)((intptr_t)self + 0x4c)) + 0x10) = local_238;
        Map_BuildElementAnimationList
                  (self,local_238,*(int *)(value5 + 8 + *(int *)((intptr_t)self + 0x4c)) + 0x10);
        local_23c = local_23c + 1;
      }
    } while (local_23c < *(int *)((intptr_t)self + 0x20) * *(int *)((intptr_t)self + 0x1c));
  }
  *(uint32_t *)((intptr_t)self + 0x118) = 0;
  CRT_Istream_Read(arg1,&local_228,4);
  if (local_228 == 1) {
    CRT_Istream_Read(arg1,&local_228,4);
    pvVar4 = operator_new(local_228 * 4 + 4);
    value5 = 0;
    *(void **)((intptr_t)self + 0x118) = pvVar4;
    if (0 < local_228 + 1) {
      do {
        CRT_Istream_Read(arg1,*(int *)((intptr_t)self + 0x118) + value5 * 4,4);
        value5 = value5 + 1;
      } while (value5 < local_228 + 1);
    }
  }
  if (*(int *)((intptr_t)self + 0x6c) == 0) {
    *(uint32_t *)((intptr_t)self + 0x70) = 0;
  }
  else if (*(int *)((intptr_t)self + 0xc) == 0x10) {
    cptr7 = _strrchr((char *)((intptr_t)self + 0x7c),0x2e);
    if (cptr7 != (char *)0x0) {
      *cptr7 = '\0';
    }
    uvalue9 = 0xffffffff;
    cptr7 = &DAT_005719f8;
    do {
      cptr13 = cptr7;
      if (uvalue9 == 0) break;
      uvalue9 = uvalue9 - 1;
      cptr13 = cptr7 + 1;
      cVar2 = *cptr7;
      cptr7 = cptr13;
    } while (cVar2 != '\0');
    uvalue9 = ~uvalue9;
    value5 = -1;
    cptr7 = (char *)((intptr_t)self + 0x7c);
    do {
      cptr12 = cptr7;
      if (value5 == 0) break;
      value5 = value5 + -1;
      cptr12 = cptr7 + 1;
      cVar2 = *cptr7;
      cptr7 = cptr12;
    } while (cVar2 != '\0');
    cptr7 = cptr13 + -uvalue9;
    cptr13 = cptr12 + -1;
    for (uvalue10 = uvalue9 >> 2; uvalue10 != 0; uvalue10 = uvalue10 - 1) {
      *(uint32_t *)cptr13 = *(uint32_t *)cptr7;
      cptr7 = cptr7 + 4;
      cptr13 = cptr13 + 4;
    }
    for (uvalue9 = uvalue9 & 3; uvalue9 != 0; uvalue9 = uvalue9 - 1) {
      *cptr13 = *cptr7;
      cptr7 = cptr7 + 1;
      cptr13 = cptr13 + 1;
    }
    local_224 = operator_new(0x50);
    local_4 = 0;
    if (local_224 == (void *)0x0) {
      uptr8 = (uint32_t *)0x0;
    }
    else {
      uptr8 = Sprite_Load(local_224,DAT_0057c5c8,*(void **)(*(int *)((intptr_t)self + 4) + 0x2bf44),
                           (LPCSTR)((intptr_t)self + 0x7c),&local_220,0,(void *)0x0,0);
    }
    *(uint32_t **)((intptr_t)self + 0x74) = uptr8;
    local_4 = 0xffffffff;
    if (local_220 != 0) {
      NoOp_Stub();
    }
    *(uint32_t *)((intptr_t)self + 0x78) = 0;
  }
  else {
    String_Format(local_10c,(uint8_t *)s__s_tga_00571b10,&DAT_0057bb44);
    local_224 = operator_new(0x11c);
    local_4 = 1;
    if (local_224 == (void *)0x0) {
      uptr8 = (uint32_t *)0x0;
    }
    else {
      uptr8 = FullscreenImage_Load
                         (local_224,local_10c,DAT_0057c5c8,
                          *(void **)(*(int *)((intptr_t)self + 4) + 0x2bf44),&local_220,(uint8_t *)0x0)
      ;
    }
    *(uint32_t **)((intptr_t)self + 0x70) = uptr8;
    local_4 = 0xffffffff;
    if (local_220 != 0) {
      NoOp_Stub();
    }
  }
  if (*(int *)((intptr_t)self + 0xc) == 0x10) {
    Map_ComputeSpecialTileBounds(self);
  }
  else {
    SetRect((LPRECT)((intptr_t)self + 0x100),0,0,0,0);
  }
  *(uint32_t *)((intptr_t)self + 0x110) = 0;
  *(uint32_t *)((intptr_t)self + 0x114) = 0;
  Map_CollectObjectIDsByType(self,1,(uint32_t)(*(int *)((intptr_t)self + 0x118) == 0),1);
  ExceptionList = local_c;
  return;
}
