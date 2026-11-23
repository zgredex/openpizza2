// IsoMap_RenderViewport: ported from Pizza Connection 2 at 0x4f4400.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f4400
#include "pc2_port.h"

void __thiscall IsoMap_RenderViewport(char *self,void *arg1,int *arg2)

{
  uint8_t flag1;
  uint8_t flag2;
  uint8_t flag3;
  uint32_t uvalue4;
  int value5;
  int value6;
  void *pvVar7;
  uint32_t *uptr8;
  int value9;
  uint32_t uvalue10;
  uint32_t uvalue11;
  int *ptr12;
  int value13;
  uint32_t uvalue14;
  int value15;
  int value16;
  uint32_t uvalue17;
  uint32_t uvalue18;
  uint32_t uvalue19;
  uint8_t *bptr20;
  char *cptr21;
  int local_184;
  int local_180;
  int local_17c;
  int local_178;
  int local_174;
  int local_170;
  uint8_t *local_16c;
  int local_168;
  uint8_t *local_15c;
  int local_158;
  uint8_t *local_154;
  int local_150;
  uint32_t local_148;
  int local_144;
  int local_140;
  uint8_t *local_13c;
  uint8_t *local_134;
  uint32_t local_120;
  short local_11b;
  uint32_t local_119;
  short local_114;
  short local_112;
  char local_10c [256];
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  value5 = DAT_00571954;
  uvalue4 = DAT_00571950;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a06e;
  local_c = ExceptionList;
  value9 = *(int *)((intptr_t)self + 0x70);
  if (value9 != 0) {
    value15 = *(int *)(value9 + 8);
    value9 = *(int *)(value9 + 4);
    if (arg2 == (int *)0x0) {
      local_174 = *(int *)((intptr_t)self + 0x1016c) + *(int *)((intptr_t)self + 0x2c);
      local_170 = (*(int *)((intptr_t)self + 0x2c) - *(int *)((intptr_t)self + 0x10168)) + value9;
      local_184 = *(int *)((intptr_t)self + 0x30) - *(int *)((intptr_t)self + 0x10174);
      local_180 = *(int *)((intptr_t)self + 0x30) + *(int *)((intptr_t)self + 0x10170) + value15;
    }
    else {
      local_174 = *arg2;
      local_170 = arg2[2];
      local_184 = arg2[1];
      local_180 = arg2[3];
      value6 = *(int *)((intptr_t)self + 0xc) * DAT_00571960;
      value16 = (value6 - *(int *)((intptr_t)self + 0x2c)) + -0x100 + local_174;
      if (value16 < 0) {
        local_174 = (*(int *)((intptr_t)self + 0x2c) - value6) + 0x100;
        value16 = 0;
      }
      value13 = *(int *)((intptr_t)self + 0x10) * DAT_00571964;
      value6 = (value13 - *(int *)((intptr_t)self + 0x30)) + -0x80 + local_184;
      if (value6 < 0) {
        local_184 = (*(int *)((intptr_t)self + 0x30) - value13) + 0x80;
        value6 = 0;
      }
      if (value9 < (value16 - local_174) + local_170) {
        local_170 = (value9 - value16) + local_174;
      }
      if (value15 < (value6 - local_184) + local_180) {
        local_180 = (value15 - value6) + local_184;
      }
    }
    uvalue14 = local_170 - local_174;
    local_148 = DAT_00571950;
    if ((intptr_t)uvalue14 <= (intptr_t)DAT_00571950) {
      local_148 = uvalue14;
    }
    local_168 = local_180 - local_184;
    local_144 = DAT_00571954;
    if (local_168 <= DAT_00571954) {
      local_144 = local_168;
    }
    ExceptionList = &local_c;
    pvVar7 = operator_new(0x11c);
    local_4 = 0;
    if (pvVar7 == (void *)0x0) {
      local_16c = (uint8_t *)0x0;
    }
    else {
      local_16c = (uint8_t *)Window_Construct(pvVar7,local_148,local_144,8);
    }
    local_4 = 0xffffffff;
    uptr8 = Renderer_CreateChild(arg1);
    *(uint32_t **)((intptr_t)self + 8) = uptr8;
    Surface_ConfigureFromOwner(local_16c,uptr8);
    value9 = Object_GetChildField14(*(int *)((intptr_t)self + 0x70));
    if (*(int *)((intptr_t)self + 0x1015c) == 0) {
      value9 = (*(int *)((intptr_t)self + 0xc) * DAT_00571960 - *(int *)((intptr_t)self + 0x2c)) + -0x100 +
              local_174;
      pvVar7 = *(void **)(*(int *)((intptr_t)self + 4) + 0x2bf44);
      local_17c = (*(int *)((intptr_t)self + 0x10) * DAT_00571964 - *(int *)((intptr_t)self + 0x30)) + -0x80 +
                  local_184;
      String_Format(local_10c,(uint8_t *)s__s_tga_00571b10,&DAT_0057bb44);
      ptr12 = Resource_Open(pvVar7,local_10c,0);
      if (ptr12 != (int *)0x0) {
        Resource_Read(pvVar7,(char *)&local_120,0x12,(intptr_t)ptr12);
        cptr21 = (char *)(*(int *)(*(int *)((intptr_t)self + 0x70) + 4) * local_17c +
                           *(int *)(*(int *)((intptr_t)self + 0x70) + 0x18) + value9);
        if (local_184 < local_180) {
          do {
            Stream_Seek(((local_112 - local_17c) + -1) * (intptr_t)local_114 +
                        ((intptr_t)((intptr_t)local_11b * (local_119 & 0xff)) >> 3) + 0x12 +
                        (local_120 & 0xff) + value9,(intptr_t)ptr12,0);
            Resource_Read(pvVar7,cptr21,uvalue14,(intptr_t)ptr12);
            cptr21 = cptr21 + *(int *)(*(int *)((intptr_t)self + 0x70) + 4);
            local_17c = local_17c + 1;
            local_168 = local_168 + -1;
          } while (local_168 != 0);
        }
        Resource_Close(pvVar7,(intptr_t)ptr12);
      }
    }
    else {
      local_154 = (uint8_t *)((intptr_t)self + 0x15c);
      local_15c = (uint8_t *)(value9 + 2);
      local_178 = 0x100;
      do {
        flag1 = local_15c[-2];
        flag2 = local_15c[-1];
        flag3 = *local_15c;
        local_150 = 0;
        local_158 = 0;
        local_17c = 0;
        local_134 = local_154;
        local_168 = 0x100;
        do {
          local_13c = (uint8_t *)0x0;
          local_140 = 1000;
          bptr20 = (uint8_t *)(value9 + 1);
          do {
            uvalue14 = (uint32_t)bptr20[1] - (local_150 >> 8);
            uvalue17 = (intptr_t)uvalue14 >> 0x1f;
            uvalue10 = (uint32_t)bptr20[-1] - (local_17c >> 8);
            uvalue18 = (intptr_t)uvalue10 >> 0x1f;
            uvalue11 = (uint32_t)*bptr20 - (local_158 >> 8);
            uvalue19 = (intptr_t)uvalue11 >> 0x1f;
            value15 = ((uvalue14 ^ uvalue17) - uvalue17) + ((uvalue10 ^ uvalue18) - uvalue18) +
                     ((uvalue11 ^ uvalue19) - uvalue19);
            if (value15 < local_140) {
              local_13c = bptr20 + (-1 - value9);
              local_140 = value15;
            }
            bptr20 = bptr20 + 3;
          } while ((intptr_t)(bptr20 + (-1 - value9)) < 0x300);
          *local_134 = (char)((intptr_t)local_13c / 3);
          local_134 = local_134 + 0x100;
          local_17c = local_17c + (uint32_t)flag1;
          local_158 = local_158 + (uint32_t)flag2;
          local_150 = local_150 + (uint32_t)flag3;
          local_168 = local_168 + -1;
        } while (local_168 != 0);
        local_15c = local_15c + 3;
        local_154 = local_154 + 1;
        local_178 = local_178 + -1;
      } while (local_178 != 0);
    }
    *(uint32_t *)((intptr_t)self + 0x1015c) = 0;
    for (; local_184 < local_180; local_184 = local_184 + value5) {
      if (local_174 < local_170) {
        value9 = local_174;
        do {
          uptr8 = *(uint32_t **)(local_16c + 0x18);
          for (uvalue14 = local_144 * local_148 >> 2; uvalue14 != 0; uvalue14 = uvalue14 - 1) {
            *uptr8 = 0xffffffff;
            uptr8 = uptr8 + 1;
          }
          for (uvalue14 = local_144 * local_148 & 3; uvalue14 != 0; uvalue14 = uvalue14 - 1) {
            *(uint8_t *)uptr8 = 0xff;
            uptr8 = (uint32_t *)((intptr_t)uptr8 + 1);
          }
          *(int *)((intptr_t)self + 0x24) = value9;
          *(int *)((intptr_t)self + 0x28) = local_184;
          Map_UpdateObjectVisibility(self);
          Sprite_ApplyPaletteRemap(self,value9,local_184,local_16c,(intptr_t)self + 0x15c);
          value9 = value9 + uvalue4;
        } while (value9 < local_170);
      }
    }
    if (*(uint32_t **)((intptr_t)self + 8) != (uint32_t *)0x0) {
      (**(code **)**(uint32_t **)((intptr_t)self + 8))(1);
    }
    if (local_16c != (uint8_t *)0x0) {
      (*(code *)**(uint32_t **)local_16c)(1);
    }
    *(uint32_t *)((intptr_t)self + 8) = 0;
  }
  ExceptionList = local_c;
  return;
}
