// CRT_NMsgWrite: ported from Pizza Connection 2 at 0x55423c.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55423c
#include "pc2_port.h"

void __cdecl CRT_NMsgWrite(DWORD arg1)

{
  uint32_t *uptr1;
  DWORD *pDVar2;
  DWORD DVar3;
  size_t svalue4;
  HANDLE hFile;
  int value5;
  uint32_t *_Dest;
  uint8_t auStackY_1e3 [7];
  LPCVOID lpBuffer;
  LPOVERLAPPED lpOverlapped;
  uint32_t local_1a8 [65];
  uint32_t local_a4 [40];
  
  value5 = 0;
  pDVar2 = &DAT_005770d8;
  do {
    if (arg1 == *pDVar2) break;
    pDVar2 = pDVar2 + 2;
    value5 = value5 + 1;
  } while ((intptr_t)pDVar2 < 0x577168);
  if (arg1 == (&DAT_005770d8)[value5 * 2]) {
    if ((DAT_0058565c == 1) || ((DAT_0058565c == 0 && (DAT_00576744 == 1)))) {
      pDVar2 = &arg1;
      uptr1 = (uint32_t *)(value5 * 8 + 0x5770dc);
      lpOverlapped = (LPOVERLAPPED)0x0;
      svalue4 = _strlen((char *)*uptr1);
      lpBuffer = (LPCVOID)*uptr1;
      hFile = GetStdHandle(0xfffffff4);
      WriteFile(hFile,lpBuffer,svalue4,pDVar2,lpOverlapped);
    }
    else if (arg1 != 0xfc) {
      DVar3 = GetModuleFileNameA((HMODULE)0x0,(LPSTR)local_1a8,0x104);
      if (DVar3 == 0) {
        _strcpy(local_1a8,(uint32_t *)"<program name unknown>");
      }
      _Dest = local_1a8;
      svalue4 = _strlen((char *)local_1a8);
      if (0x3c < svalue4 + 1) {
        svalue4 = _strlen((char *)local_1a8);
        _Dest = (uint32_t *)(auStackY_1e3 + svalue4);
        _strncpy((char *)_Dest,"...",3);
      }
      _strcpy(local_a4,(uint32_t *)"Runtime Error!\n\nProgram: ");
      CRT_Strcat(local_a4,_Dest);
      CRT_Strcat(local_a4,(uint32_t *)&DAT_0055d160);
      CRT_Strcat(local_a4,*(uint32_t **)(value5 * 8 + 0x5770dc));
      *(intptr_t *)auStackY_1e3 = ((intptr_t)(auStackY_1e3) & ~(0xffffffu << 32)) | ((((intptr_t)(0x554360)) & 0xffffffu) << 32);
      FUN_00556995(local_a4,"Microsoft Visual C++ Runtime Library",0x12010);
    }
  }
  return;
}
