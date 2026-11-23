// UI_CustomControl_Destructor: ported from Pizza Connection 2 at 0x5211a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5211a0
#include "pc2_port.h"


void __fastcall UI_CustomControl_Destructor(uint32_t *arg1)

{
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Destroys the sprite-backed custom control and its children. */
  puStack_8 = &LAB_0055a5d6;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *arg1 = &PTR_UI_Viewport_Delete_0055c73c;
  local_4 = 1;
  UI_DetachObject((intptr_t)arg1);
  if ((uint32_t *)arg1[0x20] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0x20])(1);
  }
  if ((uint32_t *)arg1[0x18] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0x18])(1);
  }
  if ((uint32_t *)arg1[0x19] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0x19])(1);
  }
  if ((uint32_t *)arg1[0x1a] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0x1a])(1);
  }
  if ((uint32_t *)arg1[0x1b] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0x1b])(1);
  }
  if (arg1[0x1f] != 0) {
    UI_SetObjectRangeByKey((void *)arg1[2],*(int *)(arg1[0x1f] + 4),arg1[0xe],arg1[0xf])
    ;
    UI_SetChildVisibleByID((void *)arg1[2],*(int *)(arg1[0x1f] + 4),1);
  }
  local_4 = local_4 & 0xffffff00;
  Array_Destroy(arg1 + 0x21);
  local_4 = 0xffffffff;
  UI_Child_Destroy(arg1);
  ExceptionList = pvStack_c;
  return;
}
