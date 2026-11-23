// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x406d70.c:15:25: error: use of undeclared identifier '_local_res0'
// UI_ShowModalMessageBox: ported from Pizza Connection 2 at 0x406d70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x406d70
#include "pc2_port.h"

void __cdecl UI_ShowModalMessageBox(uint8_t arg1)

{
  DWORD DVar1;
  uint8_t local_res0;
  uint32_t in_stack_00001008;
  uint8_t *in_stack_0000100c;
  uint32_t auStack_7ffffffc [536870905];
  
  local_res0 = (uint8_t)_local_res0;
                    /* Shows a formatted message in a modal box and pumps the UI. */
  __chkstk(local_res0);
  CRT_Vsprintf(&arg1,in_stack_0000100c,(uint32_t *)((intptr_t)register0x00000010 + 0x1010));
  DAT_0057c5f4 = LoadingScreen_Create((int *)&local_res0);
  Gadget_SetText(DAT_0057c5f4,0x3f8,in_stack_00001008);
  Window_GadgetNotify_Text_SetText(DAT_0057c5f4,0x3e9,&arg1);
  UI_RemoveObjectByKey(DAT_0057c5f4,0x3f9);
  UI_RemoveObjectByKey(DAT_0057c5f4,0x3fa);
  DAT_0057de70 = 0;
  Window_ShowWindowById(DAT_0057c5e0,_local_res0);
  Set_Field228(DAT_0057c5e0,DAT_0057c5f4);
  while ((DAT_0057de70 == 0 && (DVar1 = WaitForSingleObject(DAT_0057c0d8,0), DVar1 != 0))) {
    Window_ProcessMessageQueue(DAT_0057c5e0,0);
    Sleep(10);
  }
  Clear_Field228((intptr_t)DAT_0057c5e0);
  Window_DestroyChild(DAT_0057c5e0,DAT_0057c5f4);
  DAT_0057c5f4 = (uint32_t *)0x0;
  return;
}
