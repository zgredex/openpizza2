// Renderer_Destroy: ported from Pizza Connection 2 at 0x538a80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x538a80
#include "pc2_port.h"

void __fastcall Renderer_Destroy(uint32_t *arg1)

{
  int *ptr1;
  int *ptr2;
  
  *arg1 = &PTR_Renderer_Delete_0055c818;
  *(uint8_t *)(arg1 + 0xc) = 0;
  ptr2 = (int *)arg1[0x14];
  while (ptr2 != (int *)0x0) {
    Object_ClearField54(*ptr2);
    ptr1 = (int *)ptr2[1];
    Mem_Free(ptr2);
    ptr2 = ptr1;
  }
  arg1[0x14] = 0;
  Renderer_ReleaseTargets(arg1);
  if ((void *)arg1[0x15] != (void *)0x0) {
    List_RemoveByValue((void *)arg1[0x15],(intptr_t)arg1);
  }
  Mem_Free((LPVOID)arg1[0x10]);
  arg1[0x10] = 0;
  return;
}
