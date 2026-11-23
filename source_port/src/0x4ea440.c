// Map_LoadIsodata: ported from Pizza Connection 2 at 0x4ea440.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ea440
#include "pc2_port.h"


uint32_t __fastcall Map_LoadIsodata(int arg1)

{
  int *ptr1;
  char cVar2;
  int *ptr3;
  uint32_t *uptr4;
  char *cptr5;
  uint32_t uvalue6;
  uint32_t uvalue7;
  int value8;
  char *cptr9;
  char *cptr10;
  char *local_128;
  int local_124;
  void *local_120;
  int local_11c;
  uint32_t local_118;
  uint32_t local_114;
  void *local_110;
  char local_10c [256];
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00559ee4;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (*(int *)(arg1 + 0x2bf44) == 0) {
    ExceptionList = &local_c;
    NoOp_Stub();
  }
  ptr3 = Resource_Open(*(void **)(arg1 + 0x2bf44),s_Isodaten_idx_00571908,0);
  ptr1 = (int *)(arg1 + 0x20);
  Resource_Read(*(void **)(arg1 + 0x2bf44),(char *)ptr1,4,(intptr_t)ptr3);
  Window_GadgetNotify_Slider_SetRange(DAT_0057c5f4,0x3f7,0,*ptr1,0);
  local_114 = 0;
  if (0 < *ptr1) {
    local_128 = (char *)(arg1 + 0x25);
    do {
      if ((local_114 & 0xf) == 0) {
        Window_GadgetNotify_Slider_SetValue(DAT_0057c5f4,0x3f7,local_114,0);
        Window_ProcessMessageQueue(DAT_0057c5e0,0);
      }
      Resource_Read(*(void **)(arg1 + 0x2bf44),local_128 + -1,1,(intptr_t)ptr3);
      Resource_Read(*(void **)(arg1 + 0x2bf44),local_128,0x32,(intptr_t)ptr3);
      local_120 = operator_new(0x50);
      local_4 = 0;
      if (local_120 == (void *)0x0) {
        uptr4 = (uint32_t *)0x0;
      }
      else {
        uptr4 = Sprite_Load(local_120,DAT_0057c5c8,*(void **)(arg1 + 0x2bf44),local_128,
                             &local_124,1,*(void **)(arg1 + 0x1c),0);
      }
      *(uint32_t **)(local_128 + 0x33) = uptr4;
      local_4 = 0xffffffff;
      if (local_124 != 0) {
        NoOp_Stub();
      }
      Resource_Read(*(void **)(arg1 + 0x2bf44),(char *)&local_11c,4,(intptr_t)ptr3);
      if (local_11c == 1) {
        uvalue6 = 0xffffffff;
        cptr5 = local_128;
        do {
          cptr10 = cptr5;
          if (uvalue6 == 0) break;
          uvalue6 = uvalue6 - 1;
          cptr10 = cptr5 + 1;
          cVar2 = *cptr5;
          cptr5 = cptr10;
        } while (cVar2 != '\0');
        uvalue6 = ~uvalue6;
        cptr5 = cptr10 + -uvalue6;
        cptr10 = local_10c;
        for (uvalue7 = uvalue6 >> 2; uvalue7 != 0; uvalue7 = uvalue7 - 1) {
          *(uint32_t *)cptr10 = *(uint32_t *)cptr5;
          cptr5 = cptr5 + 4;
          cptr10 = cptr10 + 4;
        }
        for (uvalue6 = uvalue6 & 3; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
          *cptr10 = *cptr5;
          cptr5 = cptr5 + 1;
          cptr10 = cptr10 + 1;
        }
        Filename_ToUpperStripExt(local_10c);
        uvalue6 = 0xffffffff;
        cptr5 = &DAT_005718d8;
        do {
          cptr10 = cptr5;
          if (uvalue6 == 0) break;
          uvalue6 = uvalue6 - 1;
          cptr10 = cptr5 + 1;
          cVar2 = *cptr5;
          cptr5 = cptr10;
        } while (cVar2 != '\0');
        uvalue6 = ~uvalue6;
        value8 = -1;
        cptr5 = local_10c;
        do {
          cptr9 = cptr5;
          if (value8 == 0) break;
          value8 = value8 + -1;
          cptr9 = cptr5 + 1;
          cVar2 = *cptr5;
          cptr5 = cptr9;
        } while (cVar2 != '\0');
        cptr5 = cptr10 + -uvalue6;
        cptr10 = cptr9 + -1;
        for (uvalue7 = uvalue6 >> 2; uvalue7 != 0; uvalue7 = uvalue7 - 1) {
          *(uint32_t *)cptr10 = *(uint32_t *)cptr5;
          cptr5 = cptr5 + 4;
          cptr10 = cptr10 + 4;
        }
        for (uvalue6 = uvalue6 & 3; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
          *cptr10 = *cptr5;
          cptr5 = cptr5 + 1;
          cptr10 = cptr10 + 1;
        }
        local_120 = operator_new(0x50);
        local_4 = 1;
        if (local_120 == (void *)0x0) {
          uptr4 = (uint32_t *)0x0;
        }
        else {
          uptr4 = Sprite_Load(local_120,DAT_0057c5c8,*(void **)(arg1 + 0x2bf44),local_10c,
                               &local_124,1,*(void **)(arg1 + 0x1c),0);
        }
        local_4 = 0xffffffff;
        *(uint32_t **)(local_128 + 0x37) = uptr4;
        if (local_124 != 0) {
          NoOp_Stub();
        }
      }
      else {
        local_128[0x37] = '\0';
        local_128[0x38] = '\0';
        local_128[0x39] = '\0';
        local_128[0x3a] = '\0';
      }
      Resource_Read(*(void **)(arg1 + 0x2bf44),(char *)&local_11c,4,(intptr_t)ptr3);
      if (local_11c == 1) {
        uvalue6 = 0xffffffff;
        cptr5 = local_128;
        do {
          cptr10 = cptr5;
          if (uvalue6 == 0) break;
          uvalue6 = uvalue6 - 1;
          cptr10 = cptr5 + 1;
          cVar2 = *cptr5;
          cptr5 = cptr10;
        } while (cVar2 != '\0');
        uvalue6 = ~uvalue6;
        cptr5 = cptr10 + -uvalue6;
        cptr10 = local_10c;
        for (uvalue7 = uvalue6 >> 2; uvalue7 != 0; uvalue7 = uvalue7 - 1) {
          *(uint32_t *)cptr10 = *(uint32_t *)cptr5;
          cptr5 = cptr5 + 4;
          cptr10 = cptr10 + 4;
        }
        for (uvalue6 = uvalue6 & 3; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
          *cptr10 = *cptr5;
          cptr5 = cptr5 + 1;
          cptr10 = cptr10 + 1;
        }
        Filename_ToUpperStripExt(local_10c);
        uvalue6 = 0xffffffff;
        cptr5 = &DAT_005718d0;
        do {
          cptr10 = cptr5;
          if (uvalue6 == 0) break;
          uvalue6 = uvalue6 - 1;
          cptr10 = cptr5 + 1;
          cVar2 = *cptr5;
          cptr5 = cptr10;
        } while (cVar2 != '\0');
        uvalue6 = ~uvalue6;
        value8 = -1;
        cptr5 = local_10c;
        do {
          cptr9 = cptr5;
          if (value8 == 0) break;
          value8 = value8 + -1;
          cptr9 = cptr5 + 1;
          cVar2 = *cptr5;
          cptr5 = cptr9;
        } while (cVar2 != '\0');
        cptr5 = cptr10 + -uvalue6;
        cptr10 = cptr9 + -1;
        for (uvalue7 = uvalue6 >> 2; uvalue7 != 0; uvalue7 = uvalue7 - 1) {
          *(uint32_t *)cptr10 = *(uint32_t *)cptr5;
          cptr5 = cptr5 + 4;
          cptr10 = cptr10 + 4;
        }
        for (uvalue6 = uvalue6 & 3; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
          *cptr10 = *cptr5;
          cptr5 = cptr5 + 1;
          cptr10 = cptr10 + 1;
        }
        local_120 = operator_new(0x50);
        local_4 = 2;
        if (local_120 == (void *)0x0) {
          uptr4 = (uint32_t *)0x0;
        }
        else {
          uptr4 = Sprite_Load(local_120,DAT_0057c5c8,*(void **)(arg1 + 0x2bf44),local_10c,
                               &local_124,1,*(void **)(arg1 + 0x1c),0);
        }
        local_4 = 0xffffffff;
        *(uint32_t **)(local_128 + 0x3b) = uptr4;
        if (local_124 != 0) {
          NoOp_Stub();
        }
      }
      else {
        local_128[0x3b] = '\0';
        local_128[0x3c] = '\0';
        local_128[0x3d] = '\0';
        local_128[0x3e] = '\0';
      }
      Resource_Read(*(void **)(arg1 + 0x2bf44),(char *)&local_11c,4,(intptr_t)ptr3);
      if (local_11c == 1) {
        uvalue6 = 0xffffffff;
        cptr5 = local_128;
        do {
          cptr10 = cptr5;
          if (uvalue6 == 0) break;
          uvalue6 = uvalue6 - 1;
          cptr10 = cptr5 + 1;
          cVar2 = *cptr5;
          cptr5 = cptr10;
        } while (cVar2 != '\0');
        uvalue6 = ~uvalue6;
        cptr5 = cptr10 + -uvalue6;
        cptr10 = local_10c;
        for (uvalue7 = uvalue6 >> 2; uvalue7 != 0; uvalue7 = uvalue7 - 1) {
          *(uint32_t *)cptr10 = *(uint32_t *)cptr5;
          cptr5 = cptr5 + 4;
          cptr10 = cptr10 + 4;
        }
        for (uvalue6 = uvalue6 & 3; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
          *cptr10 = *cptr5;
          cptr5 = cptr5 + 1;
          cptr10 = cptr10 + 1;
        }
        Filename_ToUpperStripExt(local_10c);
        uvalue6 = 0xffffffff;
        cptr5 = &DAT_005718c8;
        do {
          cptr10 = cptr5;
          if (uvalue6 == 0) break;
          uvalue6 = uvalue6 - 1;
          cptr10 = cptr5 + 1;
          cVar2 = *cptr5;
          cptr5 = cptr10;
        } while (cVar2 != '\0');
        uvalue6 = ~uvalue6;
        value8 = -1;
        cptr5 = local_10c;
        do {
          cptr9 = cptr5;
          if (value8 == 0) break;
          value8 = value8 + -1;
          cptr9 = cptr5 + 1;
          cVar2 = *cptr5;
          cptr5 = cptr9;
        } while (cVar2 != '\0');
        cptr5 = cptr10 + -uvalue6;
        cptr10 = cptr9 + -1;
        for (uvalue7 = uvalue6 >> 2; uvalue7 != 0; uvalue7 = uvalue7 - 1) {
          *(uint32_t *)cptr10 = *(uint32_t *)cptr5;
          cptr5 = cptr5 + 4;
          cptr10 = cptr10 + 4;
        }
        for (uvalue6 = uvalue6 & 3; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
          *cptr10 = *cptr5;
          cptr5 = cptr5 + 1;
          cptr10 = cptr10 + 1;
        }
        local_120 = operator_new(0x50);
        local_4 = 3;
        if (local_120 == (void *)0x0) {
          uptr4 = (uint32_t *)0x0;
        }
        else {
          uptr4 = Sprite_Load(local_120,DAT_0057c5c8,*(void **)(arg1 + 0x2bf44),local_10c,
                               &local_124,1,*(void **)(arg1 + 0x1c),0);
        }
        local_4 = 0xffffffff;
        *(uint32_t **)(local_128 + 0x3f) = uptr4;
        if (local_124 != 0) {
          NoOp_Stub();
        }
      }
      else {
        local_128[0x3f] = '\0';
        local_128[0x40] = '\0';
        local_128[0x41] = '\0';
        local_128[0x42] = '\0';
      }
      Resource_Read(*(void **)(arg1 + 0x2bf44),(char *)&local_118,4,(intptr_t)ptr3);
      if ((intptr_t)local_118 < 1) {
        local_128[0x43] = '\0';
        local_128[0x44] = '\0';
        local_128[0x45] = '\0';
        local_128[0x46] = '\0';
      }
      else {
        local_120 = operator_new(0x1c);
        local_4 = 4;
        if (local_120 == (void *)0x0) {
          uptr4 = (uint32_t *)0x0;
        }
        else {
          uptr4 = List_Construct(local_120,local_118);
        }
        *(uint32_t **)(local_128 + 0x43) = uptr4;
        local_4 = 0xffffffff;
        local_120 = (void *)0x0;
        if (0 < (intptr_t)local_118) {
          do {
            cptr5 = operator_new(0x4c);
            Resource_Read(*(void **)(arg1 + 0x2bf44),cptr5,1,(intptr_t)ptr3);
            Resource_Read(*(void **)(arg1 + 0x2bf44),cptr5 + 1,1,(intptr_t)ptr3);
            Resource_Read(*(void **)(arg1 + 0x2bf44),cptr5 + 2,1,(intptr_t)ptr3);
            Resource_Read(*(void **)(arg1 + 0x2bf44),cptr5 + 3,1,(intptr_t)ptr3);
            Resource_Read(*(void **)(arg1 + 0x2bf44),cptr5 + 4,0xf,(intptr_t)ptr3);
            Resource_Read(*(void **)(arg1 + 0x2bf44),cptr5 + 0x13,0x32,(intptr_t)ptr3);
            local_110 = operator_new(0x98);
            local_4 = 5;
            if (local_110 == (void *)0x0) {
              uptr4 = (uint32_t *)0x0;
            }
            else {
              uptr4 = Anim_Load(local_110,(intptr_t)DAT_0057c5c8,*(void **)(arg1 + 0x2bf44),
                                 cptr5 + 0x13,&local_124,1);
            }
            *(uint32_t **)(cptr5 + 0x48) = uptr4;
            local_4 = 0xffffffff;
            List_Add(*(void **)(local_128 + 0x43),cptr5);
            local_120 = (void *)((intptr_t)local_120 + 1);
          } while ((intptr_t)local_120 < (intptr_t)local_118);
        }
      }
      local_114 = local_114 + 1;
      local_128 = local_128 + 0x48;
    } while ((intptr_t)local_114 < *(int *)(arg1 + 0x20));
  }
  Resource_Close(*(void **)(arg1 + 0x2bf44),(intptr_t)ptr3);
  ExceptionList = local_c;
  return 1;
}
