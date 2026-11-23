// UI_Text_Construct: ported from Pizza Connection 2 at 0x52bc80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52bc80
#include "pc2_port.h"


uint32_t * __thiscall
UI_Text_Construct(void *self,uint32_t arg1,int arg2,int arg3,char *arg4,char *arg5,
                 int arg6,uint32_t *arg7)

{
  void *this_00;
  uint32_t uvalue1;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Constructs a UI text element and measures its text. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a8c8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  UI_Child_Construct(self,arg1,arg2,arg3,arg6);
  *(uint8_t ***)self = &PTR_UI_TextElement_Delete_0055c7cc;
  this_00 = *(void **)(arg6 + 0x134);
  *arg7 = 0;
  local_4 = 0;
  *(uint32_t *)((intptr_t)self + 0x40) = 3;
  *(uint32_t *)((intptr_t)self + 0x74) = 0;
  *(uint32_t *)((intptr_t)self + 0x78) = 0;
  *(uint32_t *)((intptr_t)self + 0x60) = 0;
  *(uint32_t *)((intptr_t)self + 0x88) = 0;
  uvalue1 = UI_LoadFontByName(this_00,arg4);
  *(uint32_t *)((intptr_t)self + 0x54) = uvalue1;
  if (uvalue1 == 0) {
    *arg7 = 1;
  }
  else {
    *(uint32_t *)((intptr_t)self + 0x88) = 0;
    *(uint32_t *)((intptr_t)self + 0x58) = 0xffffff;
    *(uint16_t *)((intptr_t)self + 100) = 0;
    *(uint16_t *)((intptr_t)self + 0x66) = 0xffff;
    *(uint32_t *)((intptr_t)self + 0x6c) = 0;
    *(uint32_t *)((intptr_t)self + 0x70) = 3;
    UI_RichText_SetMarkupText(self,arg5);
    UI_DrawTextControl(self);
    *(uint32_t *)((intptr_t)self + 0x14) = 0;
  }
  ExceptionList = local_c;
  return self;
}
