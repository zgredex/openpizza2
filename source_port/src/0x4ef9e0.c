// IsoMap_RenderFrame: ported from Pizza Connection 2 at 0x4ef9e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ef9e0
#include "pc2_port.h"

struct pc2_obj_0x4ef9e0_local_10 { intptr_t top; intptr_t left; intptr_t right; intptr_t bottom; };
struct pc2_obj_0x4ef9e0_local_20 { intptr_t left; };
void __thiscall IsoMap_RenderFrame(char *self,HWND arg1,int *arg2,uint32_t arg3,int *arg4)

{
  int *ptr1;
  char *pvVar2;
  int value3;
  uint32_t *uptr4;
  int value5;
  int value6;
  uint32_t yBottom;
  int value7;
  uint32_t local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  void *local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  struct pc2_obj_0x4ef9e0_local_20 *local_20;
  struct pc2_obj_0x4ef9e0_local_10 *local_10;
  
  if (0 < *(int *)((intptr_t)self + 0x154)) {
    do {
      ptr1 = (int *)IDMap_Lookup((void *)((intptr_t)self + 0x140),0,(int *)0x0);
      IsoMap_RenderViewport(self,*(void **)((intptr_t)self + 8),ptr1);
      Mem_Free(ptr1);
      IDMap_RemoveRecursive((void *)((intptr_t)self + 0x140),0);
    } while (0 < *(int *)((intptr_t)self + 0x154));
  }
  if ((*(int *)((intptr_t)self + 0x44) != 0) || (*(int *)((intptr_t)self + 0x48) != 0)) {
    *(uint32_t *)((intptr_t)self + 0xf4) = 1;
  }
  if ((*(int *)((intptr_t)self + 0x24) != *(int *)((intptr_t)self + 0xe8)) ||
     (*(int *)((intptr_t)self + 0x28) != *(int *)((intptr_t)self + 0xec))) {
    *(int *)((intptr_t)self + 0x24) = *(int *)((intptr_t)self + 0xe8);
    *(uint32_t *)((intptr_t)self + 0xf4) = 1;
    *(uint32_t *)((intptr_t)self + 0x28) = *(uint32_t *)((intptr_t)self + 0xec);
  }
  *(uint32_t *)((intptr_t)self + 8) = *(uint32_t *)(*(int *)((intptr_t)self + 4) + 0x2f87c);
  Map_RenderVisibleObjects(self);
  ptr1 = arg2;
  if (arg2 == (int *)0x0) {
    if (arg4 == (int *)0x0) {
      GetClientRect(arg1,&local_10);
      local_2c = local_10->top;
      local_30 = local_10->left;
      local_28 = local_10->right;
      local_24 = local_10->bottom;
    }
    else {
      local_2c = arg4[1];
      local_30 = *arg4;
      local_28 = arg4[2];
      local_24 = arg4[3];
    }
  }
  else {
    if (arg3 == 0) {
      pvVar2 = Game_GetLinkedObjectExtent(self,(uint32_t)arg2,(uint32_t *)&arg2,&arg3);
    }
    else {
      pvVar2 = Game_GetLinkedObjectExtent
                         (self,*(int *)((intptr_t)self + 0x54) + *(int *)((intptr_t)self + 0x5c) * 0xc,
                          (uint32_t *)&arg2,&arg3);
      ptr1 = (int *)(*(int *)((intptr_t)self + 0x54) + *(int *)((intptr_t)self + 0x5c) * 0xc);
    }
    UI_AlignSpriteToRect(self,ptr1,pvVar2,&local_38,&local_3c);
    local_30 = local_38;
    if (local_38 < 0) {
      local_30 = 0;
      arg2 = (int *)((intptr_t)arg2 - local_38);
    }
    local_2c = local_3c;
    if (local_3c < 0) {
      arg3 = arg3 - local_3c;
      local_2c = 0;
    }
    local_28 = (intptr_t)arg2 + local_30;
    local_24 = arg3 + local_2c;
  }
  value7 = local_2c;
  Surface_SetBounds(*(void **)((intptr_t)self + 8),local_30,local_2c,local_28,local_24);
  if (*(int *)((intptr_t)self + 0x3c) != 0) {
    local_34 = (void *)(*(int *)((intptr_t)self + 0x24) - *(int *)((intptr_t)self + 0xd8));
    value6 = *(int *)((intptr_t)self + 0x28) - *(int *)((intptr_t)self + 0xe0);
    arg1 = (HWND)(*(int *)((intptr_t)self + 0xdc) + *(int *)((intptr_t)self + 0x24) + DAT_00571950);
    yBottom = *(int *)((intptr_t)self + 0xe4) + *(int *)((intptr_t)self + 0x28) + DAT_00571954;
    arg3 = yBottom;
    SetRect(&local_20,(intptr_t)local_34,value6,(intptr_t)arg1,yBottom);
    if ((*(void **)((intptr_t)self + 0x70) != (void *)0x0) || (*(int *)((intptr_t)self + 0x74) != 0)) {
      if (*(int *)((intptr_t)self + 0xc) == 0x10) {
        uptr4 = (uint32_t *)(((*(int *)((intptr_t)self + 0x2c) + DAT_00571960 * -0x10) - local_30) -
                         *(int *)((intptr_t)self + 0x24));
        value7 = ((*(int *)((intptr_t)self + 0x30) - *(int *)((intptr_t)self + 0x10) * DAT_00571964) -
                *(int *)((intptr_t)self + 0x28)) - local_2c;
        Sprite_BlitWithDefaultAlpha
                  (*(void **)((intptr_t)self + 0x74),*(uint32_t **)((intptr_t)self + 8),DAT_0058072c,uptr4,value7,
                   -1);
        if (*(void **)((intptr_t)self + 0x78) != (void *)0x0) {
          Sprite_BlitWithDefaultAlpha
                    (*(void **)((intptr_t)self + 0x78),*(uint32_t **)((intptr_t)self + 8),DAT_0058072c,uptr4,
                     value7,-1);
        }
        yBottom = arg3;
      }
      else {
        Sprite_Blit24BitClipped
                  (*(void **)((intptr_t)self + 0x70),*(int *)((intptr_t)self + 8),DAT_0058072c,
                   (*(int *)((intptr_t)self + 0xc) * DAT_00571960 - *(int *)((intptr_t)self + 0x2c)) +
                   local_30 + -0x100 + *(int *)((intptr_t)self + 0x24),
                   (*(int *)((intptr_t)self + 0x10) * DAT_00571964 - *(int *)((intptr_t)self + 0x30)) +
                   *(int *)((intptr_t)self + 0x28) + -0x80 + value7,0,0);
      }
    }
    if ((*(int *)((intptr_t)self + 0x70) == 0) && (*(int *)((intptr_t)self + 0x74) == 0)) {
      Map_ComputeVisibleTileRange
                (self,&local_20->left,&local_48,&local_4c,&local_44,&local_40,&local_50);
      ptr1 = (int *)((intptr_t)(yBottom - value6) / (*(int *)((intptr_t)self + 0x10) >> 1) + 3);
      arg2 = ptr1;
      if (0 < (intptr_t)ptr1) {
        value7 = local_44;
        value6 = local_48;
        do {
          value5 = local_4c;
          if (value6 <= value7) {
            do {
              uptr4 = (uint32_t *)Grid_GetCell(self,value6,value5);
              value5 = value5 + -1;
              if (uptr4 != (uint32_t *)0x0) {
                Map_DrawObject(self,3,uptr4,0);
              }
              value6 = value6 + 1;
            } while (value6 <= local_44);
            value7 = local_44;
            value6 = local_48;
          }
          if (local_50 == 0) {
            value6 = value6 + 1;
            value7 = value7 + 1;
            local_48 = value6;
            local_44 = value7;
          }
          else {
            local_4c = local_4c + 1;
            local_40 = local_40 + 1;
          }
          local_50 = (uint32_t)(local_50 == 0);
          ptr1 = (int *)((intptr_t)ptr1 + -1);
        } while (ptr1 != (int *)0x0);
      }
    }
  }
  Game_UpdateAllPlayers(DAT_0057c670,*(uint32_t *)((intptr_t)self + 8),self);
  if (*(int *)((intptr_t)self + 0x40) != 0) {
    value5 = *(int *)((intptr_t)self + 0x28) - *(int *)((intptr_t)self + 0xe0);
    value6 = *(int *)((intptr_t)self + 0x28) + DAT_00571954 + *(int *)((intptr_t)self + 0xe4);
    SetRect(&local_20,*(int *)((intptr_t)self + 0x24) - *(int *)((intptr_t)self + 0xd8),value5,
            *(int *)((intptr_t)self + 0xdc) + *(int *)((intptr_t)self + 0x24) + DAT_00571950,value6);
    Map_ComputeVisibleTileRange
              (self,&local_20->left,&local_48,&local_4c,&local_44,&local_40,&local_50);
    arg4 = (int *)0x0;
    value7 = *(int *)((intptr_t)self + 0x10) >> 1;
    arg2 = (int *)((value6 - value5) / value7 + 3 + *(int *)((intptr_t)self + 0xe4) / value7);
    if (0 < (intptr_t)arg2) {
      value7 = local_48;
      value6 = local_44;
      do {
        value5 = local_4c;
        if (value7 <= value6) {
          do {
            uptr4 = (uint32_t *)Grid_GetCell(self,value7,value5);
            value5 = value5 + -1;
            if ((uptr4 != (uint32_t *)0x0) && (uptr4[2] != 0)) {
              if (-1 < *(int *)(uptr4[2] + 0x10)) {
                if (*(int *)((intptr_t)self + 0xc) == 0x10) {
                  value6 = 3;
                }
                else {
                  value6 = 1;
                }
                Map_DrawObject(self,value6,uptr4,1);
              }
              if (*(int *)((intptr_t)self + 0xc) == 0x10) {
                Map_RenderObjectList(self,0,(intptr_t)uptr4,-1,0);
                if (*(int *)(uptr4[2] + 0x1c) != -1) {
                  Map_RenderObject(self,uptr4,0);
                }
                Map_UpdateObjectState(self,(int *)uptr4);
              }
              else {
                Map_RenderObjectList(self,0,(intptr_t)uptr4,0,0);
                Map_DrawObject(self,2,uptr4,1);
                if (0 < *(int *)(uptr4[2] + 0x1c)) {
                  Map_RenderObject(self,uptr4,0);
                }
              }
              if ((((DAT_00580a4c != 0) && (*(char *)((intptr_t)self + 0xb8) == '\0')) &&
                  (*(int *)((intptr_t)self + 0x60) != 0)) &&
                 ((*(int *)((intptr_t)self + 100) != 0 &&
                  (*(int *)uptr4[2] == **(int **)(*(int *)((intptr_t)self + 100) + 8))))) {
                if (*(char *)((intptr_t)*(void **)((intptr_t)self + 4) +
                             *(int *)((intptr_t)self + 0x68) * 0x48 + 0x24) == '\x01') {
                  pvVar2 = (void *)SparseMap_Lookup48(*(void **)((intptr_t)self + 4),
                                                      *(int *)((intptr_t)self + 0x68));
                  if (pvVar2 == (void *)0x0) {
                    return;
                  }
                  UI_DrawObjectSprite(self,uptr4,pvVar2);
                }
              }
            }
            value7 = value7 + 1;
          } while (value7 <= local_44);
          value7 = local_48;
          value6 = local_44;
        }
        if (local_50 == 0) {
          value7 = value7 + 1;
          value6 = value6 + 1;
          local_48 = value7;
          local_44 = value6;
        }
        else {
          local_4c = local_4c + 1;
          local_40 = local_40 + 1;
        }
        local_50 = (uint32_t)(local_50 == 0);
        arg4 = (int *)((intptr_t)arg4 + 1);
      } while ((intptr_t)arg4 < (intptr_t)arg2);
    }
  }
  if (*(int *)((intptr_t)self + 0xc) != 0x10) {
    Map_ComputeVisibleTileRange
              (self,&local_20->left,&local_48,&local_4c,&local_44,&local_40,&local_50);
    if (0 < (intptr_t)arg2) {
      value7 = local_44;
      ptr1 = arg2;
      value6 = local_48;
      do {
        value5 = local_4c;
        if (value6 <= value7) {
          do {
            value7 = Grid_GetCell(self,value6,value5);
            value5 = value5 + -1;
            if (value7 != 0) {
              Map_RenderObjectList(self,0,value7,1,0);
            }
            value6 = value6 + 1;
          } while (value6 <= local_44);
          value7 = local_44;
          value6 = local_48;
        }
        if (local_50 == 0) {
          value6 = value6 + 1;
          value7 = value7 + 1;
          local_48 = value6;
          local_44 = value7;
        }
        else {
          local_4c = local_4c + 1;
          local_40 = local_40 + 1;
        }
        local_50 = (uint32_t)(local_50 == 0);
        ptr1 = (int *)((intptr_t)ptr1 + -1);
      } while (ptr1 != (int *)0x0);
    }
    SetRect(&local_20,(intptr_t)local_34,arg3,(intptr_t)arg1,arg3);
    Map_ComputeVisibleTileRange
              (self,&local_20->left,&local_48,&local_4c,&local_44,&local_40,&local_50);
    local_50 = (uint32_t)(local_50 == 0);
    if (0 < (intptr_t)arg2) {
      value7 = local_44;
      ptr1 = arg2;
      value6 = local_48;
      do {
        value5 = local_4c;
        if (value6 <= value7) {
          do {
            value7 = Grid_GetCell(self,value6,value5);
            value5 = value5 + -1;
            if (value7 != 0) {
              Map_RenderObjectList(self,0,value7,2,1);
            }
            value6 = value6 + 1;
          } while (value6 <= local_44);
          value7 = local_44;
          value6 = local_48;
        }
        if (local_50 == 0) {
          value6 = value6 + -1;
          value7 = value7 + -1;
          local_48 = value6;
          local_44 = value7;
        }
        else {
          local_4c = local_4c + -1;
          local_40 = local_40 + -1;
        }
        local_50 = (uint32_t)(local_50 == 0);
        ptr1 = (int *)((intptr_t)ptr1 + -1);
      } while (ptr1 != (int *)0x0);
    }
  }
  if (*(int *)((intptr_t)self + 0x44) != 0) {
    Map_DrawRecordLinkOverlay(self,1);
  }
  if (*(int *)((intptr_t)self + 0x48) != 0) {
    Map_DrawRecordLinkOverlay(self,0);
  }
  if (*(int *)((intptr_t)self + 0xc) == 0x40) {
    arg2 = (int *)0x224;
    pvVar2 = *(void **)(*(int *)((intptr_t)self + 4) + 0x2c3d4);
    local_34 = pvVar2;
    do {
      if (((*(int *)((intptr_t)arg2 + (intptr_t)DAT_0057c670) != 0) &&
          (value7 = *(int *)((intptr_t)arg2 + *(int *)((intptr_t)self + 4) + 0x2c1f8), -1 < value7)) &&
         ((value7 < *(int *)((intptr_t)pvVar2 + 0x48) &&
          ((*(char *)(*(int *)((intptr_t)pvVar2 + 0x4c) + 0x3e + value7 * 0x48) != '\0' &&
           (value6 = Game_GetPlayerBySlot
                              (DAT_0057c670,*(int *)(*(int *)((intptr_t)arg2 + (intptr_t)DAT_0057c670) + 8)
                              ), value6 != 0)))))) {
        Record_GetTwoFloats48(pvVar2,value7,&local_38,&local_3c);
        arg3 = local_38 - *(int *)((intptr_t)self + 0x24);
        Record_DrawSprite48(pvVar2,*(uint32_t **)((intptr_t)self + 8),DAT_0058072c,value7);
        value7 = Record_GetTypeIndex48(pvVar2,value7);
        switch((intptr_t)value7) {
        case 0:
          value7 = 3;
          break;
        case 2:
          value7 = 0;
          break;
        case 4:
          value7 = 1;
          break;
        case 6:
          value7 = 2;
        }
        value5 = Player_GetFirstRecordType1(value6);
        if ((value5 != 0) && (*(int *)(value5 + 4) != 0)) {
          value3 = Game_FindCityIndex(value6);
          value5 = *(int *)(value6 + 0x1e0);
          value6 = (intptr_t)arg2 + value7 + -0x224;
          pvVar2 = *(void **)(*(int *)((intptr_t)self + 4) + 0x2c3e8 + value7 * 4);
          arg4 = *(int **)(*(int *)((intptr_t)self + 4) + 0x2c494 + value6 * 4);
          Record_SetIndex48(pvVar2,(intptr_t)arg4,value3);
          arg3 = local_38 - *(int *)((intptr_t)self + 0x24);
          Record_DrawSprite48(pvVar2,*(uint32_t **)((intptr_t)self + 8),DAT_0058072c,(intptr_t)arg4);
          pvVar2 = *(void **)(*(int *)((intptr_t)self + 4) + 0x2c3d8 + value7 * 4);
          value7 = *(int *)(*(int *)((intptr_t)self + 4) + 0x2c434 + value6 * 4);
          Record_SetIndex48(pvVar2,value7,value5);
          arg3 = local_38 - *(int *)((intptr_t)self + 0x24);
          Record_DrawSprite48(pvVar2,*(uint32_t **)((intptr_t)self + 8),DAT_0058072c,value7);
          pvVar2 = local_34;
        }
      }
      arg2 = arg2 + 1;
    } while ((intptr_t)arg2 < 0x23c);
  }
  Game_BlitScaledObjectSprite(*(int *)((intptr_t)self + 4));
  *(uint32_t *)((intptr_t)self + 8) = 0;
  Surface_FillFF((intptr_t)DAT_0058072c);
  return;
}
