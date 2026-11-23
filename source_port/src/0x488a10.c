// Game_UpdateDateLabels: ported from Pizza Connection 2 at 0x488a10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x488a10
#include "pc2_port.h"

void __thiscall Game_UpdateDateLabels(void *self,void *arg1)

{
  char cVar1;
  int value2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  char *cptr5;
  char *cptr6;
  char local_40 [32];
  uint8_t local_20 [32];
  
  if ((arg1 != (void *)0x0) || (arg1 = *(void **)((intptr_t)self + 0x25c), arg1 != (void *)0x0))
  {
    if (*(int *)((intptr_t)self + 0x1508) == 0) {
      String_Format(local_40,(uint8_t *)s__02d__02d_005682f8,
                    (uint32_t)*(uint8_t *)(*(int *)((intptr_t)self + 0x94) + 7));
    }
    else {
      uvalue3 = 0xffffffff;
      cptr5 = DAT_00582a68;
      do {
        cptr6 = cptr5;
        if (uvalue3 == 0) break;
        uvalue3 = uvalue3 - 1;
        cptr6 = cptr5 + 1;
        cVar1 = *cptr5;
        cptr5 = cptr6;
      } while (cVar1 != '\0');
      uvalue3 = ~uvalue3;
      cptr5 = cptr6 + -uvalue3;
      cptr6 = local_40;
      for (uvalue4 = uvalue3 >> 2; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
        *(uint32_t *)cptr6 = *(uint32_t *)cptr5;
        cptr5 = cptr5 + 4;
        cptr6 = cptr6 + 4;
      }
      for (uvalue3 = uvalue3 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
        *cptr6 = *cptr5;
        cptr5 = cptr5 + 1;
        cptr6 = cptr6 + 1;
      }
    }
    String_Format(local_20,(uint8_t *)s__d__s__02d_005682ec,
                  *(uint8_t *)(*(int *)((intptr_t)self + 0x94) + 8) + 1);
    CS_Enter(*(int *)(DAT_0057c5e0 + 0x1c8));
    value2 = Array_GetRecordByKeyPtr(arg1,0x410);
    if (value2 != 0) {
      Window_GadgetNotify_Text_SetText(arg1,0x410,local_40);
    }
    value2 = Array_GetRecordByKeyPtr(arg1,0x1f41);
    if (value2 != 0) {
      Window_GadgetNotify_Text_SetText(arg1,0x1f41,local_20);
    }
    CS_Leave(*(int *)(DAT_0057c5e0 + 0x1c8));
  }
  return;
}
