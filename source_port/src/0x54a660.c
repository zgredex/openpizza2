// DebugConsole_Printf: ported from Pizza Connection 2 at 0x54a660.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54a660
#include "pc2_port.h"

void __cdecl DebugConsole_Printf(int arg1,uint32_t arg2,uint8_t *arg3,uint32_t arg4)

{
  char cVar1;
  HWND pHVar2;
  uint32_t uvalue3;
  int value4;
  uint32_t uvalue5;
  char *cptr6;
  char *cptr7;
  char *cptr8;
  uint32_t *uptr9;
  UINT UVar10;
  WPARAM WVar11;
  uint32_t local_844;
  uint32_t local_840;
  uint32_t local_83c [5];
  uint32_t local_828;
  char local_800 [2048];
  
  if (*(int *)(arg1 + 4) != 0) {
    CRT_Vsprintf(local_800,arg3,&arg4);
    uvalue3 = 0xffffffff;
    cptr6 = &DAT_0056832c;
    do {
      cptr8 = cptr6;
      if (uvalue3 == 0) break;
      uvalue3 = uvalue3 - 1;
      cptr8 = cptr6 + 1;
      cVar1 = *cptr6;
      cptr6 = cptr8;
    } while (cVar1 != '\0');
    uvalue3 = ~uvalue3;
    value4 = -1;
    cptr6 = local_800;
    do {
      cptr7 = cptr6;
      if (value4 == 0) break;
      value4 = value4 + -1;
      cptr7 = cptr6 + 1;
      cVar1 = *cptr6;
      cptr6 = cptr7;
    } while (cVar1 != '\0');
    cptr6 = cptr8 + -uvalue3;
    cptr8 = cptr7 + -1;
    for (uvalue5 = uvalue3 >> 2; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
      *(uint32_t *)cptr8 = *(uint32_t *)cptr6;
      cptr6 = cptr6 + 4;
      cptr8 = cptr8 + 4;
    }
    pHVar2 = *(HWND *)(arg1 + 4);
    for (uvalue3 = uvalue3 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
      *cptr8 = *cptr6;
      cptr6 = cptr6 + 1;
      cptr8 = cptr8 + 1;
    }
    uptr9 = local_83c;
    for (value4 = 0xf; value4 != 0; value4 = value4 + -1) {
      *uptr9 = 0;
      uptr9 = uptr9 + 1;
    }
    uptr9 = &local_844;
    local_828 = arg2;
    WVar11 = 0;
    UVar10 = 0x437;
    local_83c[0] = 0x3c;
    local_83c[1] = 0x40000000;
    local_83c[2] = 0;
    local_844 = 0x100000;
    local_840 = 0x100000;
    pHVar2 = GetDlgItem(pHVar2,0x3ef);
    SendMessageA(pHVar2,UVar10,WVar11,(LPARAM)uptr9);
    uptr9 = local_83c;
    WVar11 = 1;
    UVar10 = 0x444;
    pHVar2 = GetDlgItem(*(HWND *)(arg1 + 4),0x3ef);
    SendMessageA(pHVar2,UVar10,WVar11,(LPARAM)uptr9);
    cptr6 = local_800;
    WVar11 = 0;
    UVar10 = 0xc2;
    pHVar2 = GetDlgItem(*(HWND *)(arg1 + 4),0x3ef);
    SendMessageA(pHVar2,UVar10,WVar11,(LPARAM)cptr6);
  }
  return;
}
