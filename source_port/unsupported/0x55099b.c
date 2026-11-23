// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x55099b.c:18:3: error: unknown type name '_SECURITY_ATTRIBUTES'; did you mean 'LPSECURITY_ATTRIBUTES'?
// CRT_Sopen: ported from Pizza Connection 2 at 0x55099b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55099b
#include "pc2_port.h"

uint32_t __cdecl CRT_Sopen(LPCSTR arg1,uint32_t arg2,uint32_t arg3,uint32_t arg4)

{
  uint8_t *bptr1;
  uint32_t uvalue2;
  uint32_t uvalue3;
  DWORD *pDVar4;
  HANDLE hFile;
  DWORD DVar5;
  int value6;
  int value7;
  bool flag8;
  _SECURITY_ATTRIBUTES local_20;
  DWORD local_14;
  DWORD local_10;
  DWORD local_c;
  uint8_t local_5;
  
  flag8 = (arg2 & 0x80) == 0;
  local_20.nLength = 0xc;
  local_20.lpSecurityDescriptor = (LPVOID)0x0;
  if (flag8) {
    local_5 = 0;
  }
  else {
    local_5 = 0x10;
  }
  local_20.bInheritHandle = (BOOL)flag8;
  if (((arg2 & 0x8000) == 0) && (((arg2 & 0x4000) != 0 || (DAT_005858f0 != 0x8000)))) {
    local_5 = local_5 | 0x80;
  }
  uvalue2 = arg2 & 3;
  if (uvalue2 == 0) {
    local_10 = 0x80000000;
  }
  else if (uvalue2 == 1) {
    local_10 = 0x40000000;
  }
  else {
    if (uvalue2 != 2) goto LAB_00550a9f;
    local_10 = 0xc0000000;
  }
  if (arg3 == 0x10) {
    local_14 = 0;
  }
  else if (arg3 == 0x20) {
    local_14 = 1;
  }
  else if (arg3 == 0x30) {
    local_14 = 2;
  }
  else {
    if (arg3 != 0x40) goto LAB_00550a9f;
    local_14 = 3;
  }
  uvalue2 = arg2 & 0x700;
  if (uvalue2 < 0x401) {
    if ((uvalue2 == 0x400) || (uvalue2 == 0)) {
      local_c = 3;
    }
    else if (uvalue2 == 0x100) {
      local_c = 4;
    }
    else {
      if (uvalue2 == 0x200) goto LAB_00550ab9;
      if (uvalue2 != 0x300) goto LAB_00550a9f;
      local_c = 2;
    }
  }
  else {
    if (uvalue2 != 0x500) {
      if (uvalue2 == 0x600) {
LAB_00550ab9:
        local_c = 5;
        goto LAB_00550ac9;
      }
      if (uvalue2 != 0x700) {
LAB_00550a9f:
        pDVar4 = CRT_GetErrnoPtr();
        *pDVar4 = 0x16;
        pDVar4 = CRT_GetDosErrnoPtr();
        *pDVar4 = 0;
        return 0xffffffff;
      }
    }
    local_c = 1;
  }
LAB_00550ac9:
  uvalue2 = 0x80;
  if (((arg2 & 0x100) != 0) && ((~DAT_00585610 & arg4 & 0x80) == 0)) {
    uvalue2 = 1;
  }
  if ((arg2 & 0x40) != 0) {
    uvalue2 = uvalue2 | 0x4000000;
    local_10 = CONCAT13(((uint64_t)((local_10) >> 8)),0x10000);
  }
  if ((arg2 & 0x1000) != 0) {
    uvalue2 = uvalue2 | 0x100;
  }
  if ((arg2 & 0x20) == 0) {
    if ((arg2 & 0x10) != 0) {
      uvalue2 = uvalue2 | 0x10000000;
    }
  }
  else {
    uvalue2 = uvalue2 | 0x8000000;
  }
  uvalue3 = CRT_AllocOsfHandle();
  if (uvalue3 == 0xffffffff) {
    pDVar4 = CRT_GetErrnoPtr();
    *pDVar4 = 0x18;
    pDVar4 = CRT_GetDosErrnoPtr();
    *pDVar4 = 0;
    return 0xffffffff;
  }
  hFile = CreateFileA(arg1,local_10,local_14,&local_20,local_c,uvalue2,(HANDLE)0x0);
  if (hFile != (HANDLE)0xffffffff) {
    DVar5 = GetFileType(hFile);
    if (DVar5 != 0) {
      if (DVar5 == 2) {
        local_5 = local_5 | 0x40;
      }
      else if (DVar5 == 3) {
        local_5 = local_5 | 8;
      }
      CRT_SetOsfHandle(uvalue3,hFile);
      value7 = (uvalue3 & 0x1f) * 0x24;
      arg1 = (arg1 & ~(0xffffffu << 8)) | (((local_5 & 0x48) & 0xffffffu) << 8);
      *(uint8_t *)((&DAT_00586c20)[(intptr_t)uvalue3 >> 5] + 4 + value7) = local_5 | 1;
      if ((((local_5 & 0x48) == 0) && ((local_5 & 0x80) != 0)) && ((arg2 & 2) != 0)) {
        local_14 = CRT_LseekLocked(uvalue3,-1,2);
        if (local_14 == 0xffffffff) {
          pDVar4 = CRT_GetDosErrnoPtr();
          if (*pDVar4 == 0x83) goto LAB_00550c43;
        }
        else {
          arg3 = arg3 & 0xffffff;
          value6 = CRT_ReadCore(uvalue3,(char *)((intptr_t)&arg3 + 3),(char *)0x1);
          if ((((value6 != 0) || (((uint64_t)((arg3) >> 8)) != '\x1a')) ||
              (value6 = CRT_Chsize(uvalue3,local_14), value6 != -1)) &&
             (DVar5 = CRT_LseekLocked(uvalue3,0,0), DVar5 != 0xffffffff)) goto LAB_00550c43;
        }
        CRT_Close(uvalue3);
        uvalue2 = 0xffffffff;
      }
      else {
LAB_00550c43:
        if ((arg1 = (arg1 & ~(0xffffffu << 8)) | (((= 0) && ((arg2 & 8) != 0)) {
          bptr1 = (uint8_t *)((&DAT_00586c20)[(intptr_t)uvalue3 >> 5] + 4 + value7)) & 0xffffffu) << 8);
          *bptr1 = *bptr1 | 0x20;
        }
        uvalue2 = uvalue3;
      }
      goto LAB_00550c5c;
    }
    CloseHandle(hFile);
  }
  DVar5 = GetLastError();
  CRT_MapWin32Error(DVar5);
  uvalue2 = 0xffffffff;
LAB_00550c5c:
  CS_LeaveSlot(uvalue3);
  return uvalue2;
}
