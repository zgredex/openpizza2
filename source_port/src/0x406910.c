// UI_ShowLoadingOverlay: ported from Pizza Connection 2 at 0x406910.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x406910
#include "pc2_port.h"


int64_t __cdecl UI_ShowLoadingOverlay(int arg1)

{
  uint16_t uvalue1;
  uint16_t uvalue2;
  void *self;
  uint32_t uvalue3;
  int value4;
  uint32_t *uptr5;
  uint16_t *uptr6;
  int64_t lvalue7;
  uint8_t flag8;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Darkens the screen and shows the loading overlay. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00557d3b;
  local_c = ExceptionList;
  uptr5 = (uint32_t *)0x0;
  ExceptionList = &local_c;
  if (arg1 != 0) {
    ExceptionList = &local_c;
    self = operator_new(0x11c);
    local_4 = 0;
    if (self != (void *)0x0) {
      uptr5 = Window_Construct(self,800,600,2);
    }
    local_4 = 0xffffffff;
    UI_RefreshAndCenter(DAT_0057c5e0,uptr5);
    uptr6 = (uint16_t *)uptr5[6];
    value4 = 480000;
    do {
      if (*(char *)((intptr_t)DAT_0057c5c8 + 0x18) == '\0') {
        uvalue1 = *uptr6;
        uvalue3 = uvalue1 >> 2 & 0xf8;
        uvalue2 = uvalue1 >> 7;
      }
      else {
        uvalue1 = *uptr6;
        uvalue3 = uvalue1 >> 3 & 0xfc;
        uvalue2 = uvalue1 >> 8;
      }
      uvalue3 = ((uvalue2 & 0xf8) + ((uvalue1 & 0x1f) * 8 + uvalue3 * 2) * 3) / 10;
      flag8 = (uint8_t)uvalue3;
      uvalue3 = Color_RGBTo16(DAT_0057c5c8,flag8,flag8,uvalue3);
      *uptr6 = (uint16_t)uvalue3;
      uptr6 = uptr6 + 1;
      value4 = value4 + -1;
    } while (value4 != 0);
    UI_ReplaceActiveObject(DAT_0057c5e0,uptr5);
  }
  DAT_0057c5f4 = LoadingWindow_Create(&arg1);
  Window_ShowWindowById(DAT_0057c5e0,arg1);
  Set_Field228(DAT_0057c5e0,DAT_0057c5f4);
  lvalue7 = Window_ProcessMessageQueue(DAT_0057c5e0,0);
  ExceptionList = local_c;
  return lvalue7;
}
