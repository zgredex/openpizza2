// CRT_SelectionSort: ported from Pizza Connection 2 at 0x54ebe3.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54ebe3
#include "pc2_port.h"

void __cdecl
CRT_SelectionSort(uint8_t *arg1,uint8_t *arg2,int arg3,uint8_t *arg4)

{
  int value1;
  uint8_t *uptr2;
  uint8_t *uptr3;
  
  for (; arg1 < arg2; arg2 = arg2 + -arg3) {
    uptr2 = arg1;
    uptr3 = arg1;
    while (uptr3 = uptr3 + arg3, uptr3 <= arg2) {
      value1 = (*(code *)arg4)(uptr3,uptr2);
      if (0 < value1) {
        uptr2 = uptr3;
      }
    }
    Mem_Swap(uptr2,arg2,arg3);
  }
  return;
}
