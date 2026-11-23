// SpriteFile_Destruct: ported from Pizza Connection 2 at 0x5335f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5335f0
#include "pc2_port.h"


void __fastcall SpriteFile_Destruct(uint32_t *arg1)

{
  uint32_t *uptr1;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Destroys a multi-frame sprite file and its frame data. */
  puStack_8 = &LAB_0055aca8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *arg1 = &PTR_Animation_ScalarDeletingDestructor_0055c80c;
  local_4 = 0;
  if (arg1[0x22] != 0) {
    Mem_Free((LPVOID)arg1[0xc]);
    arg1[0xc] = 0;
  }
  if ((LPVOID)arg1[0x14] != (LPVOID)0x0) {
    Mem_Free((LPVOID)arg1[0x14]);
  }
  if ((LPVOID)arg1[0x13] != (LPVOID)0x0) {
    Mem_Free((LPVOID)arg1[0x13]);
  }
  if (((*(char *)(arg1 + 0xd) != '\0') && (*(LPVOID *)arg1[0x20] != (LPVOID)0x0)) &&
     (*(char *)((intptr_t)arg1 + 0x35) != '\0')) {
    Mem_Free(*(LPVOID *)arg1[0x20]);
  }
  if ((LPVOID)arg1[0xe] != (LPVOID)0x0) {
    Mem_Free((LPVOID)arg1[0xe]);
  }
  if ((LPVOID)arg1[0x20] != (LPVOID)0x0) {
    Mem_Free((LPVOID)arg1[0x20]);
  }
  if ((LPVOID)arg1[8] != (LPVOID)0x0) {
    Mem_Free((LPVOID)arg1[8]);
  }
  uptr1 = (uint32_t *)arg1[0x1e];
  if (uptr1 != (uint32_t *)0x0) {
    Palette_Free(uptr1);
    Mem_Free(uptr1);
  }
  local_4 = 0xffffffff;
  SpriteBase_Destructor(arg1);
  ExceptionList = local_c;
  return;
}
