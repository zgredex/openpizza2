// RecordList_EnsureLoaded: ported from Pizza Connection 2 at 0x533400.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x533400
#include "pc2_port.h"

void __fastcall RecordList_EnsureLoaded(int arg1)

{
  char *cptr1;
  int *ptr2;
  int value3;
  
  if (*(char *)(arg1 + 0x34) != '\0') {
    CS_Enter(0x584248);
    if (*(char *)(arg1 + 0x35) != '\0') {
      CS_Leave(0x584248);
      return;
    }
    cptr1 = operator_new(*(uint32_t *)(arg1 + 0x40));
    ptr2 = Resource_Open(*(void **)(arg1 + 0x44),*(char **)(arg1 + 0x38),0);
    if (ptr2 != (int *)0x0) {
      Stream_Seek(*(int *)(arg1 + 0x3c),(intptr_t)ptr2,0);
      Resource_Read(*(void **)(arg1 + 0x44),cptr1,*(uint32_t *)(arg1 + 0x40),(intptr_t)ptr2);
      Resource_Close(*(void **)(arg1 + 0x44),(intptr_t)ptr2);
    }
    value3 = 0;
    if (0 < *(int *)(arg1 + 0x68)) {
      do {
        if (*(int *)(*(int *)(arg1 + 0x30) + value3 * 4) == 0) {
          *(uint32_t *)(*(int *)(arg1 + 0x80) + value3 * 4) = 0;
        }
        else {
          *(char **)(*(int *)(arg1 + 0x80) + value3 * 4) = cptr1;
        }
        cptr1 = cptr1 + *(int *)(*(int *)(arg1 + 0x30) + value3 * 4);
        value3 = value3 + 1;
      } while (value3 < *(int *)(arg1 + 0x68));
    }
    *(uint8_t *)(arg1 + 0x35) = 1;
    CS_Leave(0x584248);
  }
  return;
}
