// GammaOptions_Init: ported from Pizza Connection 2 at 0x4a0680.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a0680
#include "pc2_port.h"


/* WARNING: Removing unreachable block (ram,0x004a07e3) */

void __cdecl GammaOptions_Init(void *arg1)

{
  int *ptr1;
  void *pvVar2;
  char *cptr3;
  int value4;
  int value5;
  uint32_t uvalue6;
  int64_t lvalue7;
  uint32_t uvalue8;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005587f6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  ptr1 = Resource_Open(DAT_0057c5d8,s_gamma_bin_00568c7c,0);
  if (ptr1 != (int *)0x0) {
    pvVar2 = operator_new(0x50);
    local_4 = 0;
    if (pvVar2 == (void *)0x0) {
      DAT_0057cda4 = (uint32_t *)0x0;
    }
    else {
      DAT_0057cda4 = Sprite_CreateRaw(pvVar2,0x1fe,0xaa,0,8,0);
    }
    local_4 = 0xffffffff;
    pvVar2 = operator_new(0x50);
    local_4 = 1;
    if (pvVar2 == (void *)0x0) {
      DAT_0057cda8 = (uint32_t *)0x0;
    }
    else {
      DAT_0057cda8 = Sprite_CreateRaw(pvVar2,0x1fe,0xaa,0,8,0);
    }
    local_4 = 0xffffffff;
    cptr3 = (char *)Sprite_GetPixelBuffer(DAT_0057cda8);
    Resource_Read(DAT_0057c5d8,cptr3,0x152ac,(intptr_t)ptr1);
    Resource_Close(DAT_0057c5d8,(intptr_t)ptr1);
    if (*(char *)(DAT_0057c5c8 + 0x18) == '\0') {
      value4 = 0;
      do {
        value5 = value4 + 3;
        *(uint16_t *)(cptr3 + value4) =
             *(uint16_t *)(cptr3 + value4) >> 1 & 0x7fe0 | *(uint16_t *)(cptr3 + value4) & 0x1f;
        value4 = value5;
      } while (value5 < 0x152ac);
    }
  }
  Window_GadgetNotify_Slider_SetRange(arg1,0x1f53,0,0x32,0);
  Window_GadgetNotify_Slider_SetChangeNotify(arg1,0x1f53,1);
  uvalue8 = 0;
  lvalue7 = __ftol();
  Window_GadgetNotify_Slider_SetValue(arg1,0x1f53,(intptr_t)lvalue7,uvalue8);
  uvalue6 = (uint32_t)*(uint8_t *)(DAT_0057c5cc + 0x2bf48);
  if (3 < *(uint8_t *)(DAT_0057c5cc + 0x2bf48)) {
    uvalue6 = 3;
  }
  Window_GadgetNotify_Slider_SetRange(arg1,0x1f5e,0,3,0);
  Window_GadgetNotify_Slider_SetValue(arg1,0x1f5e,uvalue6,0);
  Window_GadgetNotify_Text_SetText(arg1,0x1f60,(&DAT_00583878)[uvalue6]);
  GammaOptions_DrawPreview(arg1);
  ExceptionList = local_c;
  return;
}
