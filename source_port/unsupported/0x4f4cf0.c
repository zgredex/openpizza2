// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x4f4cf0.c:39:80: error: invalid operands to binary expression ('int' and 'intptr_t *' (aka 'int *'))
// Map_UpdateObjectVisibility: ported from Pizza Connection 2 at 0x4f4cf0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f4cf0
#include "pc2_port.h"

void __fastcall Map_UpdateObjectVisibility(void *arg1)

{
  int value1;
  int *ptr2;
  void *pvVar3;
  int value4;
  int value5;
  int *ptr6;
  int *ptr7;
  int local_3c;
  int local_38;
  int local_34;
  uint32_t local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  tagRECT local_10;
  
  if (*(int *)((intptr_t)arg1 + 0x40) != 0) {
    value4 = *(int *)((intptr_t)arg1 + 0x70);
    if (value4 == 0) {
      Sprite_GetSize(*(void **)((intptr_t)arg1 + 0x74),&local_28,&local_2c);
    }
    else {
      local_28 = *(int *)(value4 + 4);
      local_2c = *(int *)(value4 + 8);
    }
    value4 = *(int *)((intptr_t)arg1 + 0x30) + local_2c;
    value1 = *(int *)((intptr_t)arg1 + 0x30) - *(int *)((intptr_t)arg1 + 0x10) * DAT_00571964;
    SetRect(&local_10,*(int *)((intptr_t)arg1 + 0x2c) - *(int *)((intptr_t)arg1 + 0xc) * DAT_00571960,
            value1,*(int *)((intptr_t)arg1 + 0x2c) + local_28,value4);
    Map_ComputeVisibleTileRange
              (arg1,&local_10.left,&local_38,&local_3c,&local_34,&local_24,&local_30);
    value5 = *(int *)((intptr_t)arg1 + 0x10) >> 1;
    local_20 = (value4 - value1) / value5 + 3 + *(int *)((intptr_t)arg1 + 0xe4) / value5;
    if (0 < local_20) {
      value4 = local_34;
      value1 = local_38;
      do {
        value5 = local_3c;
        if (value1 <= value4) {
          while( true ) {
            ptr2 = (int *)Grid_GetCell(arg1,value1,value5);
            local_1c = value5 + -1;
            if ((ptr2 != (int *)0x0) && (value4 = *(int *)(ptr2[2] + 0x10), -1 < value4)) {
              ptr7 = &local_18;
              ptr6 = &local_14;
              pvVar3 = (void *)SparseMap_Lookup48(*(void **)((intptr_t)arg1 + 4),value4);
              UI_AlignSpriteToRect(arg1,ptr2,pvVar3,ptr6,ptr7);
              pvVar3 = *(void **)(*(int *)((intptr_t)arg1 + 4) + 0x60 + value4 * 0x48);
              if (pvVar3 != (void *)0x0) {
                Sprite_BlitRLEMasked(arg1,pvVar3,local_14,local_18);
              }
            }
            value1 = value1 + 1;
            if (local_34 < value1) break;
            value5 = local_1c;
          }
          value4 = local_34;
          value1 = local_38;
        }
        if (local_30 == 0) {
          value1 = value1 + 1;
          value4 = value4 + 1;
          local_38 = value1;
          local_34 = value4;
        }
        else {
          local_3c = local_3c + 1;
          local_24 = local_24 + 1;
        }
        local_30 = (uint32_t)(local_30 == 0);
        local_20 = local_20 + -1;
      } while (local_20 != 0);
    }
  }
  return;
}
