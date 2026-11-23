// Sprite_RealizeLazy: ported from Pizza Connection 2 at 0x53cea0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53cea0
#include "pc2_port.h"

void __fastcall Sprite_RealizeLazy(void *arg1)

{
  void *pvVar1;
  int *ptr2;
  
  if (*(char *)((intptr_t)arg1 + 0x38) != '\0') {
    CS_Enter(0x585520);
    if (*(char *)((intptr_t)arg1 + 0x39) == '\0') {
      pvVar1 = operator_new(*(uint32_t *)((intptr_t)arg1 + 0x44));
      *(void **)((intptr_t)arg1 + 0x2c) = pvVar1;
      ptr2 = Resource_Open(*(void **)((intptr_t)arg1 + 0x48),*(char **)((intptr_t)arg1 + 0x3c),0);
      if (ptr2 != (int *)0x0) {
        Stream_Seek(*(int *)((intptr_t)arg1 + 0x40),(intptr_t)ptr2,0);
        Resource_Read(*(void **)((intptr_t)arg1 + 0x48),*(char **)((intptr_t)arg1 + 0x2c),
                      *(uint32_t *)((intptr_t)arg1 + 0x44),(intptr_t)ptr2);
        Resource_Close(*(void **)((intptr_t)arg1 + 0x48),(intptr_t)ptr2);
      }
      if ((*(uint8_t *)((intptr_t)arg1 + 4) & 0x10) == 0) {
        Sprite_ConvertRGB555to565(arg1,DAT_0057c5c8);
      }
      *(uint8_t *)((intptr_t)arg1 + 0x39) = 1;
    }
    CS_Leave(0x585520);
  }
  return;
}
