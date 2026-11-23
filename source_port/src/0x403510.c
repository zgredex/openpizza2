// Debug_WarningMessageBox: ported from Pizza Connection 2 at 0x403510.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x403510
#include "pc2_port.h"

void Debug_WarningMessageBox(void)

{
  uint8_t local_res0;
  uint8_t *in_stack_00001004;
  uint32_t auStack_7ffffffc [536870904];
  
  __chkstk(local_res0);
  CRT_Vsprintf(&local_res0,in_stack_00001004,(uint32_t *)((intptr_t)register0x00000010 + 0x1008));
  MessageBoxA(DAT_0057c5d0,&local_res0,s_Achtung_00563774,0);
  if (DAT_0057c5d0 != (HWND)0x0) {
    SetWindowPos(DAT_0057c5d0,(HWND)0x0,0,0,0,0,3);
  }
  return;
}
