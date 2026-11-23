// Game_AcquireStateLock: ported from Pizza Connection 2 at 0x486be0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x486be0
#include "pc2_port.h"

void __thiscall Game_AcquireStateLock(void *self,int arg1)

{
  DWORD DVar1;
  int value2;
  
  DVar1 = GetCurrentThreadId();
  if (DVar1 == *(DWORD *)(*(int *)((intptr_t)self + 0x90) + 0x10)) {
    value2 = 0;
  }
  else {
    value2 = (DVar1 != *(DWORD *)(DAT_0057c5e0 + 0x830c)) + 1;
  }
  DebugConsole_Printf(DAT_0057c1e0,0x8000c0,(uint8_t *)s_Want_Lock__s___08x_00568174,
                      (&PTR_DAT_00567e88)[value2]);
  if (DVar1 != *(DWORD *)(*(int *)((intptr_t)self + 0x90) + 0x10)) {
    if (DVar1 != *(DWORD *)(DAT_0057c5e0 + 0x830c)) {
      *(uint32_t *)((intptr_t)self + 0x2d18) = 1;
      CS_Enter(*(int *)((intptr_t)self + 0x23c));
LAB_00486d75:
      value2 = *(int *)((intptr_t)self + 0x250);
      if (arg1 == 0) {
joined_r0x00486d94:
        if ((value2 == 0) && (*(int *)((intptr_t)self + 0x24c) == 0)) goto LAB_00486dd0;
      }
      else if (value2 == 0) {
        value2 = *(int *)(*(int *)((intptr_t)self + 0x90) + 0x38);
        goto joined_r0x00486d94;
      }
      if ((*(int *)((intptr_t)self + 0x2d10) != 0) || (*(int *)((intptr_t)self + 0x2d14) != 0)) {
        CS_Leave(*(int *)((intptr_t)self + 0x23c));
        Sleep(10);
        CS_Enter(*(int *)((intptr_t)self + 0x23c));
      }
      goto LAB_00486d75;
    }
    *(uint32_t *)((intptr_t)self + 0x2d14) = 1;
    CS_Enter(*(int *)((intptr_t)self + 0x23c));
    value2 = *(int *)((intptr_t)self + 0x254);
    while ((value2 != 0 && (Sleep(10), *(int *)((intptr_t)self + 0x2d18) == 0))) {
      value2 = *(int *)((intptr_t)self + 0x254);
    }
LAB_00486d00:
    value2 = *(int *)((intptr_t)self + 0x250);
    if (arg1 == 0) {
joined_r0x00486d1f:
      if (value2 == 0) goto LAB_00486d47;
    }
    else if (value2 == 0) {
      value2 = *(int *)(*(int *)((intptr_t)self + 0x90) + 0x38);
      goto joined_r0x00486d1f;
    }
    if (*(int *)((intptr_t)self + 0x2d10) != 0) {
      CS_Leave(*(int *)((intptr_t)self + 0x23c));
      Sleep(10);
      CS_Enter(*(int *)((intptr_t)self + 0x23c));
    }
    goto LAB_00486d00;
  }
  *(uint32_t *)((intptr_t)self + 0x2d10) = 1;
  CS_Enter(*(int *)((intptr_t)self + 0x23c));
  value2 = *(int *)((intptr_t)self + 0x24c);
  while ((value2 != 0 && (Sleep(10), *(int *)((intptr_t)self + 0x2d14) == 0))) {
    value2 = *(int *)((intptr_t)self + 0x24c);
  }
  value2 = *(int *)((intptr_t)self + 0x254);
  while ((value2 != 0 && (Sleep(10), *(int *)((intptr_t)self + 0x2d18) == 0))) {
    value2 = *(int *)((intptr_t)self + 0x254);
  }
  *(uint32_t *)((intptr_t)self + 0x2d10) = 0;
LAB_00486dde:
  DebugConsole_Printf(DAT_0057c1e0,0x8000c0,(uint8_t *)s_OK_Lock___08x_00568164,DVar1);
  return;
LAB_00486dd0:
  *(uint32_t *)((intptr_t)self + 0x2d18) = 0;
  goto LAB_00486dde;
LAB_00486d47:
  *(uint32_t *)((intptr_t)self + 0x2d14) = 0;
  goto LAB_00486dde;
}
