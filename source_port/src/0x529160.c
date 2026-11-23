// UI_LayoutChildElements: ported from Pizza Connection 2 at 0x529160.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x529160
#include "pc2_port.h"

void __fastcall UI_LayoutChildElements(int arg1)

{
  int value1;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  *(int *)(arg1 + 100) = *(int *)(arg1 + 0x4f0) + *(int *)(arg1 + 0x38);
  *(int *)(arg1 + 0x68) = *(int *)(arg1 + 0x4f4) + *(int *)(arg1 + 0x3c);
  Sprite_GetSize(*(void **)(arg1 + 0x1ec),&local_4,&local_8);
  Sprite_GetSize(*(void **)(arg1 + 0x230),&local_c,&local_10);
  value1 = *(int *)(arg1 + 100);
  if (*(int *)(arg1 + 0xc0) == 0) {
    *(int *)(arg1 + 0x74) = local_4 + value1;
    *(int *)(arg1 + 0x78) = *(int *)(arg1 + 0x68);
    *(int *)(arg1 + 0x6c) = *(int *)(arg1 + 0xb4) + value1;
    *(int *)(arg1 + 0x70) = *(int *)(arg1 + 0x68) + local_10;
    Sprite_GetSize(*(void **)(arg1 + 0x274),&local_c,&local_10);
    *(int *)(arg1 + 0x7c) = (*(int *)(arg1 + 0xb4) - local_c) + *(int *)(arg1 + 100);
    *(uint32_t *)(arg1 + 0x80) = *(uint32_t *)(arg1 + 0x68);
    return;
  }
  *(int *)(arg1 + 0x74) = value1;
  *(int *)(arg1 + 0x78) = local_8 + *(int *)(arg1 + 0x68);
  *(int *)(arg1 + 0x6c) = value1 + local_c;
  *(int *)(arg1 + 0x70) = *(int *)(arg1 + 0xb4) + *(int *)(arg1 + 0x68);
  Sprite_GetSize(*(void **)(arg1 + 0x274),&local_c,&local_10);
  *(uint32_t *)(arg1 + 0x7c) = *(uint32_t *)(arg1 + 100);
  *(int *)(arg1 + 0x80) = (*(int *)(arg1 + 0xb4) - local_10) + *(int *)(arg1 + 0x68);
  return;
}
