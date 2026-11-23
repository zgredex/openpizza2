// Game_Construct: ported from Pizza Connection 2 at 0x4e64c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e64c0
#include "pc2_port.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint32_t * __thiscall Game_Construct(void *self,uint32_t arg1)

{
  char cVar1;
  void *pvVar2;
  uint32_t *uptr3;
  uint32_t uvalue4;
  uint32_t uvalue5;
  char *cptr6;
  int value7;
  char *cptr8;
  int *ptr9;
  char *cptr10;
  int *ptr11;
  int64_t lvalue12;
  uint16_t *local_178;
  int local_174;
  double dStack_170;
  double dStack_168;
  uint64_t local_160;
  uint32_t auStack_158 [2];
  uint32_t auStack_150 [2];
  double dStack_148;
  int local_13c [8];
  void *local_11c;
  CHAR local_118 [260];
  void *pvStack_14;
  uint8_t *puStack_10;
  int local_c;
  
                    /* Constructs the game/engine object and loads its animation banks. */
  local_c = 0xffffffff;
  puStack_10 = &LAB_00559e3d;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  local_11c = self;
  List_Construct((void *)((intptr_t)self + 0x2c3f8),0);
  *(uint8_t ***)self = &PTR_Game_Delete_0055c5d0;
  local_13c[1] = 0xab;
  local_13c[3] = 0xab;
  local_13c[7] = 0xab;
  *(uint32_t *)((intptr_t)self + 0x2bf44) = arg1;
  *(uint8_t *)((intptr_t)self + 0x2bf48) = 0xff;
  *(uint32_t *)((intptr_t)self + 0x2f87c) = 0;
  *(uint32_t *)((intptr_t)self + 0x2f880) = 0;
  *(uint32_t *)((intptr_t)self + 0x2f884) = 0;
  *(uint32_t *)((intptr_t)self + 0x2f88c) = 0;
  *(uint32_t *)((intptr_t)self + 0x2f888) = 0;
  DAT_0058072c = 0;
  _DAT_00580a48 = 0;
  *(uint32_t *)((intptr_t)self + 0x1c) = 0;
  local_c = (local_c & ~(0xffu << 24)) | (((0) & 0xffu) << 24);
  local_13c[0] = 0x6c;
  local_13c[2] = 0x56;
  local_13c[4] = 0x6b;
  local_13c[5] = 0xaa;
  local_13c[6] = 0x56;
  *(uint32_t *)((intptr_t)self + 0x20) = 0;
  value7 = 0;
  do {
    local_c = (local_c & ~(0x0u << 8)) | (((0) & 0x0u) << 8);
    String_Format(local_118,(uint8_t *)s_pink__02d_spr_005718b8,value7);
    pvVar2 = operator_new(0x50);
    local_c = (local_c & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
    if (pvVar2 == (void *)0x0) {
      uptr3 = (uint32_t *)0x0;
    }
    else {
      uptr3 = Sprite_Load(pvVar2,DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),local_118,
                           (uint32_t *)0x0,0,(void *)0x0,0);
    }
    (&DAT_005806ec)[value7] = uptr3;
    local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
    String_Format(local_118,(uint8_t *)s_ping__02d_spr_005718a8,value7);
    pvVar2 = operator_new(0x50);
    local_c = (local_c & ~(0x0u << 8)) | (((2) & 0x0u) << 8);
    if (pvVar2 == (void *)0x0) {
      uptr3 = (uint32_t *)0x0;
    }
    else {
      uptr3 = Sprite_Load(pvVar2,DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),local_118,
                           (uint32_t *)0x0,0,(void *)0x0,0);
    }
    (&DAT_0058070c)[value7] = uptr3;
    value7 = value7 + 1;
    local_c = (local_c & ~(0x0u << 8)) | (((0) & 0x0u) << 8);
  } while (value7 < 8);
  pvVar2 = operator_new(0x50);
  local_c = (local_c & ~(0x0u << 8)) | (((3) & 0x0u) << 8);
  if (pvVar2 == (void *)0x0) {
    DAT_00580730 = (uint32_t *)0x0;
  }
  else {
    DAT_00580730 = Sprite_Load(pvVar2,DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                               s_man_shadow_spr_00571898,&local_174,0,(void *)0x0,0);
  }
  local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
  if (local_174 != 0) {
    if (DAT_00580730 != (uint32_t *)0x0) {
      (**(code **)*DAT_00580730)(1);
    }
    DAT_00580730 = (uint32_t *)0x0;
  }
  local_178 = (uint16_t *)((intptr_t)self + 0x2e4f4);
  local_160 = (double)((uint64_t)((uint32_t)((local_160) >> 32)) << 0x20);
  cptr6 = (char *)((intptr_t)self + 0x25);
  do {
    *local_178 = (uint16_t)local_160;
    uvalue4 = 0xffffffff;
    cptr6[-1] = -1;
    cptr8 = &DAT_00579aec;
    do {
      cptr10 = cptr8;
      if (uvalue4 == 0) break;
      uvalue4 = uvalue4 - 1;
      cptr10 = cptr8 + 1;
      cVar1 = *cptr8;
      cptr8 = cptr10;
    } while (cVar1 != '\0');
    uvalue4 = ~uvalue4;
    cptr8 = cptr10 + -uvalue4;
    cptr10 = cptr6;
    for (uvalue5 = uvalue4 >> 2; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
      *(uint32_t *)cptr10 = *(uint32_t *)cptr8;
      cptr8 = cptr8 + 4;
      cptr10 = cptr10 + 4;
    }
    for (uvalue4 = uvalue4 & 3; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
      *cptr10 = *cptr8;
      cptr8 = cptr8 + 1;
      cptr10 = cptr10 + 1;
    }
    cptr6[0x33] = '\0';
    cptr6[0x34] = '\0';
    cptr6[0x35] = '\0';
    cptr6[0x36] = '\0';
    cptr6[0x37] = '\0';
    cptr6[0x38] = '\0';
    cptr6[0x39] = '\0';
    cptr6[0x3a] = '\0';
    cptr6[0x3b] = '\0';
    cptr6[0x3c] = '\0';
    cptr6[0x3d] = '\0';
    cptr6[0x3e] = '\0';
    cptr6[0x3f] = '\0';
    cptr6[0x40] = '\0';
    cptr6[0x41] = '\0';
    cptr6[0x42] = '\0';
    cptr6[0x43] = '\0';
    cptr6[0x44] = '\0';
    cptr6[0x45] = '\0';
    cptr6[0x46] = '\0';
    local_178 = local_178 + 1;
    value7 = (intptr_t)local_160 + 1;
    local_160 = (double)CONCAT44(((uint32_t)((local_160) >> 32)),value7);
    cptr6 = cptr6 + 0x48;
    if (0x9c3 < value7) {
      *(uint32_t *)((intptr_t)self + 0xc) = 0;
      *(uint32_t *)((intptr_t)self + 0x14) = 0;
      *(uint32_t *)((intptr_t)self + 0x10) = 0;
      *(uint32_t *)((intptr_t)self + 0x18) = 0;
      value7 = 0x30;
      uptr3 = (uint32_t *)((intptr_t)self + 0x2c00c);
      do {
        uptr3[-0x30] = 0;
        *uptr3 = 0;
        uptr3[0x8a] = 0;
        uptr3[0xba] = 0;
        uptr3 = uptr3 + 1;
        value7 = value7 + -1;
      } while (value7 != 0);
      uptr3 = (uint32_t *)((intptr_t)self + 0x2c180);
      value7 = 0x2d;
      do {
        uptr3[-0x2d] = 0;
        *uptr3 = 0;
        uptr3 = uptr3 + 1;
        value7 = value7 + -1;
      } while (value7 != 0);
      *(uint32_t *)((intptr_t)self + 0x2c3b4) = 0;
      *(uint32_t *)((intptr_t)self + 0x2c3b8) = 0;
      *(uint32_t *)((intptr_t)self + 0x2c3bc) = 0;
      *(uint32_t *)((intptr_t)self + 0x2c3c0) = 0;
      *(uint32_t *)((intptr_t)self + 0x2c3c8) = 0;
      *(uint32_t *)((intptr_t)self + 0x2c3c4) = 0;
      *(uint32_t *)((intptr_t)self + 0x2c3cc) = 0;
      *(uint32_t *)((intptr_t)self + 0x2c3d0) = 0;
      *(uint32_t *)((intptr_t)self + 0x2c3d4) = 0;
      uptr3 = (uint32_t *)((intptr_t)self + 0x2c3e8);
      value7 = 6;
      do {
        uptr3[-4] = 0;
        *uptr3 = 0;
        uptr3 = uptr3 + 1;
        value7 = value7 + -1;
      } while (value7 != 0);
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((4) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_KID_M_SMA_ani_00571888,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2bf4c) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((5) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_TEEN_M_SMA_ani_00571878,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2bf50) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((6) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_STUDENT_M_SMA_ani_00571864,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2bf54) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((7) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_PROLL_M_SMA_ani_00571854,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2bf58) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((8) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_BUERO_M_SMA_ani_00571844,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2bf5c) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((9) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_BONZE_M_SMA_ani_00571834,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2bf60) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((10) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_GRUFTIE_M_SMA_ani_00571820,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2bf64) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0xb) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_TOURISTEN_M_SMA_ani_0057180c,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2bf68) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0xc) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_SERVICE_M_SMA_ani_005717f8,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2bf98) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0xd) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_KOCH_M_SMA_ani_005717e8,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2bf90) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0xe) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_BUERGERMEISTER_M_SMA_ani_005717cc,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2bfac) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0xf) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_LAUFBURSCHE_M_SMA_ani_005717b4,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2bf9c) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x10) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_PUNK_M_SMA_ani_005717a4,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2bfa4) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x11) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_MANAGER_M_SMA_ani_00571790,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2bf94) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x12) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_KURRIER_M_SMA_ani_0057177c,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2bfc8) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x13) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_SCHLAEGER_M_SMA_ani_00571768,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2bfc4) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x14) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_DARKMAN_SMA_ani_00571758,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2bfc0) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x15) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_POLIZIST_SMA_ani_00571744,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2bf80) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x16) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_BEAMTER_M_SMA_ani_00571730,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2bf74) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x17) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_FATMAN_M_SMA_ani_0057171c,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2bf78) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x18) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_KAMMERJAEGER_M_SMA_ani_00571704,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2bfcc) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x19) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_REINIGUNG_M_SMA_ani_005716f0,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2bf84) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x1a) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_WACHE_M_SMA_ani_005716e0,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2bfa8) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x1b) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_PROMMI_M_SMA_ani_005716cc,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2bf88) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x1c) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_WISSENSCHAFTLER_M_SMA_ani_005716b0,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2bfd0) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x1d) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_ARBEITSLOS_KOCH_M_SMA_ani_00571694,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2bfe0) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x1e) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_ARBEITSLOS_SERVICE_M_SMA_ani_00571674,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2bfe8) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x1f) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_ARBEITSLOS_MANAGER_M_SMA_ani_00571654,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2bfe4) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x20) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_ARBEITSLOS_LAUFBURSCHE_M_SMA_ani_00571630,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2bfec) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x21) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_LIEFERANT_M_SMA_ani_0057161c,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2bf7c) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x22) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_WERBEJUNGE_M_SMA_ani_00571604,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2bfd4) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x23) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_KID_W_SMA_ani_005715f4,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t *)((intptr_t)self + 0x2c00c) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x24) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_TEEN_W_SMA_ani_005715e4,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c010) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x25) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_STUDENT_W_SMA_ani_005715d0,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c014) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x26) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_PROLL_W_SMA_ani_005715c0,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c018) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x27) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_BUERO_W_SMA_ani_005715b0,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c01c) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x28) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_BONZE_W_SMA_ani_005715a0,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c020) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x29) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_GRUFTIE_W_SMA_ani_0057158c,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c024) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x2a) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_TOURISTEN_W_SMA_ani_00571578,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c028) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x2b) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_SERVICE_W_SMA_ani_00571564,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c058) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x2c) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_KOCH_W_SMA_ani_00571554,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c050) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x2d) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_MANAGER_W_SMA_ani_00571540,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c054) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x2e) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_PROMMI_W_SMA_ani_0057152c,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c048) = uptr3;
      *(uint32_t *)((intptr_t)self + 0x2c05c) = 0;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x2f) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_ARBEITSLOS_KOCH_W_SMA_ani_00571510,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c0a0) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x30) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_ARBEITSLOS_SERVICE_W_SMA_ani_005714f0,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c0a8) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x31) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_ARBEITSLOS_MANAGER_W_SMA_ani_005714d0,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c0a4) = uptr3;
      *(uint32_t *)((intptr_t)self + 0x2c0ac) = 0;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x32) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_KID_M_BIG_ani_005714c0,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c234) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x33) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_TEEN_M_BIG_ani_005714b0,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c238) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x34) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_STUDENT_M_BIG_ani_0057149c,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c23c) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x35) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_PROLL_M_BIG_ani_0057148c,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c240) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x36) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_BUERO_M_BIG_ani_0057147c,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c244) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x37) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_BONZE_M_BIG_ani_0057146c,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c248) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x38) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_GRUFTIE_M_BIG_ani_00571458,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c24c) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x39) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_TOURISTEN_M_BIG_ani_00571444,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c250) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x3a) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_SERVICE_M_BIG_ani_00571430,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c280) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x3b) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_KOCH_M_BIG_ani_00571420,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c278) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x3c) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_BUERGERMEISTER_M_BIG_ani_00571404,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c294) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x3d) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_LAUFBURSCHE_M_BIG_ani_005713ec,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c284) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x3e) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_PUNK_M_BIG_ani_005713dc,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c28c) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x3f) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_MANAGER_M_BIG_ani_005713c8,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c27c) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x40) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_RATTE_ani_005713bc,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c29c) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x41) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_KAKERLAKE_ani_005713ac,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c2a0) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x42) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_WURM_ani_005713a0,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c2a4) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x43) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_KURRIER_M_BIG_ani_0057138c,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c2b0) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x44) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_SCHLAEGER_M_BIG_ani_00571378,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c2ac) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x45) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_DARKMAN_BIG_ani_00571368,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c2a8) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x46) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_POLIZIST_BIG_ani_00571354,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c268) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x47) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_BEAMTER_M_BIG_ani_00571340,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c25c) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x48) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_FATMAN_M_BIG_ani_0057132c,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c260) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x49) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_KAMMERJAEGER_M_BIG_ani_00571314,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c2b4) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x4a) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_REINIGUNG_M_BIG_ani_00571300,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c26c) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x4b) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_WACHE_M_BIG_ani_005712f0,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c290) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x4c) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_PROMMI_M_BIG_ani_005712dc,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c270) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x4d) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_WISSENSCHAFTLER_M_BIG_ani_005712c0,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c2b8) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x4e) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_KID_W_BIG_ani_005712b0,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c2f4) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x4f) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_TEEN_W_BIG_ani_005712a0,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c2f8) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x50) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_STUDENT_W_BIG_ani_0057128c,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c2fc) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x51) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_PROLL_W_BIG_ani_0057127c,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c300) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x52) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_BUERO_W_BIG_ani_0057126c,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c304) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x53) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_BONZE_W_BIG_ani_0057125c,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c308) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x54) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_GRUFTIE_W_BIG_ani_00571248,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c30c) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x55) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_TOURISTEN_W_BIG_ani_00571234,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c310) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x56) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_SERVICE_W_BIG_ani_00571220,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c340) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x57) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_KOCH_W_BIG_ani_00571210,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c338) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x58) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_MANAGER_W_BIG_ani_005711fc,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c33c) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x59) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_PROMMI_W_BIG_ani_005711e8,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c330) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x5a) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_LAUFBURSCHE_M_BIG_ani_005713ec,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c344) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x5b) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_ALBERTO01_00_ani_005711d4,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c0cc) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x5c) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_ALBERTO01_M_ani_005711c4,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c180) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x5d) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_KLEINWAG01A_00_ani_005711b0,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c0d0) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x5e) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_KLEINWAG01_M_ani_0057119c,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c184) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x5f) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_KLEINWAG01B_00_ani_00571188,&local_174,1);
      }
      *(uint32_t **)((intptr_t)self + 0x2c0d4) = uptr3;
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t *)((intptr_t)self + 0x2c188) = *(uint32_t *)((intptr_t)self + 0x2c184);
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x60) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_KLEINWAG01C_00_ani_00571174,&local_174,1);
      }
      *(uint32_t **)((intptr_t)self + 0x2c0d8) = uptr3;
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t *)((intptr_t)self + 0x2c18c) = *(uint32_t *)((intptr_t)self + 0x2c184);
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x61) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_KLEINWAG01D_00_ani_00571160,&local_174,1);
      }
      *(uint32_t **)((intptr_t)self + 0x2c0dc) = uptr3;
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t *)((intptr_t)self + 0x2c190) = *(uint32_t *)((intptr_t)self + 0x2c184);
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x62) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_KLEINWAG01E_00_ani_0057114c,&local_174,1);
      }
      *(uint32_t **)((intptr_t)self + 0x2c0e0) = uptr3;
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t *)((intptr_t)self + 0x2c194) = *(uint32_t *)((intptr_t)self + 0x2c184);
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((99) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_KLEINWAG01F_00_ani_00571138,&local_174,1);
      }
      *(uint32_t **)((intptr_t)self + 0x2c0e4) = uptr3;
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t *)((intptr_t)self + 0x2c198) = *(uint32_t *)((intptr_t)self + 0x2c184);
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((100) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_KLEINWAG02A_00_ani_00571124,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c0e8) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x65) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_KLEINWAG02_M_ani_00571110,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c19c) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x66) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_KLEINWAG02B_00_ani_005710fc,&local_174,1);
      }
      *(uint32_t **)((intptr_t)self + 0x2c0ec) = uptr3;
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t *)((intptr_t)self + 0x2c1a0) = *(uint32_t *)((intptr_t)self + 0x2c19c);
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x67) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_KLEINWAG02C_00_ani_005710e8,&local_174,1);
      }
      *(uint32_t **)((intptr_t)self + 0x2c0f0) = uptr3;
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t *)((intptr_t)self + 0x2c1a4) = *(uint32_t *)((intptr_t)self + 0x2c19c);
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x68) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_KLEINWAG02D_00_ani_005710d4,&local_174,1);
      }
      *(uint32_t **)((intptr_t)self + 0x2c0f4) = uptr3;
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t *)((intptr_t)self + 0x2c1a8) = *(uint32_t *)((intptr_t)self + 0x2c19c);
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x69) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_KLEINWAG02E_00_ani_005710c0,&local_174,1);
      }
      *(uint32_t **)((intptr_t)self + 0x2c0f8) = uptr3;
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t *)((intptr_t)self + 0x2c1ac) = *(uint32_t *)((intptr_t)self + 0x2c19c);
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x6a) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_KLEINWAG02F_00_ani_005710ac,&local_174,1);
      }
      *(uint32_t **)((intptr_t)self + 0x2c0fc) = uptr3;
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t *)((intptr_t)self + 0x2c1b0) = *(uint32_t *)((intptr_t)self + 0x2c19c);
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x6b) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_LIMUSINE01A_00_ani_00571098,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c100) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x6c) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_LIMUSINE01_M_ani_00571084,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c1b4) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x6d) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_LIMUSINE01B_00_ani_00571070,&local_174,1);
      }
      *(uint32_t **)((intptr_t)self + 0x2c104) = uptr3;
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t *)((intptr_t)self + 0x2c1b8) = *(uint32_t *)((intptr_t)self + 0x2c1b4);
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x6e) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_LIMUSINE01C_00_ani_0057105c,&local_174,1);
      }
      *(uint32_t **)((intptr_t)self + 0x2c108) = uptr3;
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t *)((intptr_t)self + 0x2c1bc) = *(uint32_t *)((intptr_t)self + 0x2c1b4);
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x6f) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_LIMUSINE01D_00_ani_00571048,&local_174,1);
      }
      *(uint32_t **)((intptr_t)self + 0x2c10c) = uptr3;
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t *)((intptr_t)self + 0x2c1c0) = *(uint32_t *)((intptr_t)self + 0x2c1b4);
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x70) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_LIMUSINE01E_00_ani_00571034,&local_174,1);
      }
      *(uint32_t **)((intptr_t)self + 0x2c110) = uptr3;
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t *)((intptr_t)self + 0x2c1c4) = *(uint32_t *)((intptr_t)self + 0x2c1b4);
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x71) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_LIMUSINE01F_00_ani_00571020,&local_174,1);
      }
      *(uint32_t **)((intptr_t)self + 0x2c114) = uptr3;
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t *)((intptr_t)self + 0x2c1c8) = *(uint32_t *)((intptr_t)self + 0x2c1b4);
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x72) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_LIMUSINE02A_00_ani_0057100c,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c118) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x73) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_LIMUSINE02_M_ani_00570ff8,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c1cc) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x74) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_LIMUSINE02B_00_ani_00570fe4,&local_174,1);
      }
      *(uint32_t **)((intptr_t)self + 0x2c11c) = uptr3;
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t *)((intptr_t)self + 0x2c1d0) = *(uint32_t *)((intptr_t)self + 0x2c1cc);
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x75) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_LIMUSINE02C_00_ani_00570fd0,&local_174,1);
      }
      *(uint32_t **)((intptr_t)self + 0x2c120) = uptr3;
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t *)((intptr_t)self + 0x2c1d4) = *(uint32_t *)((intptr_t)self + 0x2c1cc);
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x76) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_LIMUSINE02D_00_ani_00570fbc,&local_174,1);
      }
      *(uint32_t **)((intptr_t)self + 0x2c124) = uptr3;
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t *)((intptr_t)self + 0x2c1d8) = *(uint32_t *)((intptr_t)self + 0x2c1cc);
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x77) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_LIMUSINE02E_00_ani_00570fa8,&local_174,1);
      }
      *(uint32_t **)((intptr_t)self + 0x2c128) = uptr3;
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t *)((intptr_t)self + 0x2c1dc) = *(uint32_t *)((intptr_t)self + 0x2c1cc);
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x78) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_LIMUSINE02F_00_ani_00570f94,&local_174,1);
      }
      *(uint32_t **)((intptr_t)self + 0x2c12c) = uptr3;
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t *)((intptr_t)self + 0x2c1e0) = *(uint32_t *)((intptr_t)self + 0x2c1cc);
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x79) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_LKW01A_00_ani_00570f84,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c130) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x7a) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_LKW01_M_ani_00570f78,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c1e4) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x7b) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_MITTELKLASSE01A_00_ani_00570f60,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c134) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x7c) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_MITTELKLASSE01_M_ani_00570f48,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c1e8) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x7d) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_MITTELKLASSE01B_00_ani_00570f30,&local_174,1);
      }
      *(uint32_t **)((intptr_t)self + 0x2c138) = uptr3;
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t *)((intptr_t)self + 0x2c1ec) = *(uint32_t *)((intptr_t)self + 0x2c1e8);
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x7e) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_MITTELKLASSE01C_00_ani_00570f18,&local_174,1);
      }
      *(uint32_t **)((intptr_t)self + 0x2c13c) = uptr3;
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t *)((intptr_t)self + 0x2c1f0) = *(uint32_t *)((intptr_t)self + 0x2c1e8);
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x7f) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_MITTELKLASSE01D_00_ani_00570f00,&local_174,1);
      }
      *(uint32_t **)((intptr_t)self + 0x2c140) = uptr3;
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t *)((intptr_t)self + 0x2c1f4) = *(uint32_t *)((intptr_t)self + 0x2c1e8);
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x80) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_MITTELKLASSE01E_00_ani_00570ee8,&local_174,1);
      }
      *(uint32_t **)((intptr_t)self + 0x2c144) = uptr3;
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t *)((intptr_t)self + 0x2c1f8) = *(uint32_t *)((intptr_t)self + 0x2c1e8);
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x81) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_MITTELKLASSE01F_00_ani_00570ed0,&local_174,1);
      }
      *(uint32_t **)((intptr_t)self + 0x2c148) = uptr3;
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t *)((intptr_t)self + 0x2c1fc) = *(uint32_t *)((intptr_t)self + 0x2c1e8);
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x82) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_MITTELKLASSE02A_00_ani_00570eb8,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c14c) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x83) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_MITTELKLASSE02_M_ani_00570ea0,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c200) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x84) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_MITTELKLASSE02B_00_ani_00570e88,&local_174,1);
      }
      *(uint32_t **)((intptr_t)self + 0x2c150) = uptr3;
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t *)((intptr_t)self + 0x2c204) = *(uint32_t *)((intptr_t)self + 0x2c200);
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x85) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_MITTELKLASSE02C_00_ani_00570e70,&local_174,1);
      }
      *(uint32_t **)((intptr_t)self + 0x2c154) = uptr3;
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t *)((intptr_t)self + 0x2c208) = *(uint32_t *)((intptr_t)self + 0x2c200);
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x86) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_MITTELKLASSE02D_00_ani_00570e58,&local_174,1);
      }
      *(uint32_t **)((intptr_t)self + 0x2c158) = uptr3;
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t *)((intptr_t)self + 0x2c20c) = *(uint32_t *)((intptr_t)self + 0x2c200);
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x87) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_MITTELKLASSE02E_00_ani_00570e40,&local_174,1);
      }
      *(uint32_t **)((intptr_t)self + 0x2c15c) = uptr3;
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t *)((intptr_t)self + 0x2c210) = *(uint32_t *)((intptr_t)self + 0x2c200);
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x88) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_MITTELKLASSE02F_00_ani_00570e28,&local_174,1);
      }
      *(uint32_t **)((intptr_t)self + 0x2c160) = uptr3;
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t *)((intptr_t)self + 0x2c214) = *(uint32_t *)((intptr_t)self + 0x2c200);
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x89) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_POLIZEI01A_00_ani_00570e14,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c164) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x8a) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_POLIZEI01_M_ani_00570e04,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c218) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x8b) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_VAN01A_00_ani_00570df4,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c168) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x8c) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_VAN01_M_ani_00570de8,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c21c) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x8d) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_VAN01B_00_ani_00570dd8,&local_174,1);
      }
      *(uint32_t **)((intptr_t)self + 0x2c16c) = uptr3;
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t *)((intptr_t)self + 0x2c220) = *(uint32_t *)((intptr_t)self + 0x2c21c);
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x8e) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_VAN01C_00_ani_00570dc8,&local_174,1);
      }
      *(uint32_t **)((intptr_t)self + 0x2c170) = uptr3;
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t *)((intptr_t)self + 0x2c224) = *(uint32_t *)((intptr_t)self + 0x2c21c);
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x8f) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_VAN01D_00_ani_00570db8,&local_174,1);
      }
      *(uint32_t **)((intptr_t)self + 0x2c174) = uptr3;
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t *)((intptr_t)self + 0x2c228) = *(uint32_t *)((intptr_t)self + 0x2c21c);
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x90) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_VAN01E_00_ani_00570da8,&local_174,1);
      }
      *(uint32_t **)((intptr_t)self + 0x2c178) = uptr3;
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t *)((intptr_t)self + 0x2c22c) = *(uint32_t *)((intptr_t)self + 0x2c21c);
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x91) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_VAN01F_00_ani_00570d98,&local_174,1);
      }
      *(uint32_t **)((intptr_t)self + 0x2c17c) = uptr3;
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t *)((intptr_t)self + 0x2c230) = *(uint32_t *)((intptr_t)self + 0x2c21c);
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x92) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_TEUFEL_ani_00570d8c,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c3c0) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x93) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_ENGEL_ani_00570d80,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c3bc) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x94) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_GRAFFITI_ani_00570d70,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c3c8) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x95) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_STINKBOMBE_ani_00570d60,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c3c4) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x96) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_KOPFICON_ani_00565e68,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c3b4) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x97) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_TPIZZA_ani_00570d54,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c3b8) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x98) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_BOMBE_ani_00570d48,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c3d0) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x99) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_EXPLO_ani_00570d3c,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c3cc) = uptr3;
      Record_GetRect98(uptr3,0,(uint32_t *)&dStack_170,(uint32_t *)&dStack_168,auStack_150,
                       auStack_158);
      dStack_170 = dStack_170 + 18.0;
      dStack_168 = dStack_168 - 14.0;
      Animation_SetPointPairs
                (*(void **)((intptr_t)self + 0x2c3cc),0,(uint32_t *)&dStack_170,
                 (uint32_t *)&dStack_168,auStack_150,auStack_158);
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x9a) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_ZEP01A_00_ani_00570d2c,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c3d4) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x9b) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_ZEP_WLOGO_01_ani_00570d18,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c3d8) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x9c) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_ZEP_WLOGO_02_ani_00570d04,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c3dc) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x9d) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_ZEP_WLOGO_03_ani_00570cf0,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c3e0) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x9e) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_ZEP_WLOGO_04_ani_00570cdc,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c3e4) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0x9f) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_ZEP_WSCHILD_01_ani_00570cc8,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c3e8) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0xa0) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_ZEP_WSCHILD_02_ani_00570cb4,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c3ec) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0xa1) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_ZEP_WSCHILD_03_ani_00570ca0,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c3f0) = uptr3;
      pvVar2 = operator_new(0x98);
      local_c = (local_c & ~(0x0u << 8)) | (((0xa2) & 0x0u) << 8);
      if (pvVar2 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Anim_Load(pvVar2,(intptr_t)DAT_0057c5c8,*(void **)((intptr_t)self + 0x2bf44),
                           s_ZEP_WSCHILD_04_ani_00570c8c,&local_174,1);
      }
      local_c = (uint32_t)((uint8_t)((local_c) >> 24)) << 8;
      *(uint32_t **)((intptr_t)self + 0x2c3f4) = uptr3;
      ptr9 = local_13c + 1;
      uptr3 = (uint32_t *)((intptr_t)self + 0x2c3e8);
      local_178 = (uint16_t *)0x4;
      do {
        Record_GetRect98((void *)uptr3[-4],0,(uint32_t *)&dStack_170,(uint32_t *)&dStack_168,
                         auStack_150,auStack_158);
        local_160 = (double)ptr9[-1];
        dStack_170 = dStack_170 - local_160;
        dStack_148 = (double)*ptr9;
        dStack_168 = dStack_168 - dStack_148;
        Animation_SetPointPairs
                  ((void *)uptr3[-4],0,(uint32_t *)&dStack_170,(uint32_t *)&dStack_168,
                   auStack_150,auStack_158);
        Record_GetRect98((void *)*uptr3,0,(uint32_t *)&dStack_170,(uint32_t *)&dStack_168,
                         auStack_150,auStack_158);
        dStack_170 = dStack_170 - local_160;
        dStack_168 = dStack_168 - dStack_148;
        Animation_SetPointPairs
                  ((void *)*uptr3,0,(uint32_t *)&dStack_170,(uint32_t *)&dStack_168,auStack_150
                   ,auStack_158);
        uptr3 = uptr3 + 1;
        ptr9 = ptr9 + 2;
        local_178 = (uint16_t *)((intptr_t)local_178 + -1);
      } while (local_178 != (uint16_t *)0x0);
      value7 = RecordList_FindFreeSlot(*(void **)((intptr_t)self + 0x2c3b8),-1);
      *(int *)((intptr_t)self + 0x2c414) = value7;
      value7 = RecordList_FindFreeSlot(*(void **)((intptr_t)self + 0x2c3b4),-1);
      *(int *)((intptr_t)self + 0x2c418) = value7;
      ptr9 = (int *)((intptr_t)self + 0x2c498);
      ptr11 = (int *)((intptr_t)self + 0x2c41c);
      local_178 = (uint16_t *)0x6;
      do {
        value7 = RecordList_FindFreeSlot(*(void **)((intptr_t)self + 0x2c3d4),-1);
        *ptr11 = value7;
        value7 = RecordList_FindFreeSlot(*(void **)((intptr_t)self + 0x2c3e8),-1);
        ptr9[-1] = value7;
        value7 = RecordList_FindFreeSlot(*(void **)((intptr_t)self + 0x2c3ec),-1);
        *ptr9 = value7;
        value7 = RecordList_FindFreeSlot(*(void **)((intptr_t)self + 0x2c3f0),-1);
        ptr9[1] = value7;
        value7 = RecordList_FindFreeSlot(*(void **)((intptr_t)self + 0x2c3f4),-1);
        ptr9[2] = value7;
        value7 = RecordList_FindFreeSlot(*(void **)((intptr_t)self + 0x2c3d8),-1);
        ptr9[-0x19] = value7;
        value7 = RecordList_FindFreeSlot(*(void **)((intptr_t)self + 0x2c3dc),-1);
        ptr9[-0x18] = value7;
        value7 = RecordList_FindFreeSlot(*(void **)((intptr_t)self + 0x2c3e0),-1);
        ptr9[-0x17] = value7;
        value7 = RecordList_FindFreeSlot(*(void **)((intptr_t)self + 0x2c3e4),-1);
        ptr9[-0x16] = value7;
        ptr11 = ptr11 + 1;
        ptr9 = ptr9 + 4;
        local_178 = (uint16_t *)((intptr_t)local_178 + -1);
      } while (local_178 != (uint16_t *)0x0);
      value7 = 0;
      uptr3 = (uint32_t *)((intptr_t)self + 0x2c4f4);
      do {
        lvalue12 = __ftol();
        *uptr3 = (intptr_t)lvalue12;
        value7 = value7 + 1;
        uptr3 = uptr3 + 1;
      } while (value7 < 0x800);
      ExceptionList = pvStack_14;
      return self;
    }
  } while( true );
}
