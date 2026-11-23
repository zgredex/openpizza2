// CRT_FlushAllStreams: ported from Pizza Connection 2 at 0x550717.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x550717
#include "pc2_port.h"

int __cdecl CRT_FlushAllStreams(int arg1)

{
  int *ptr1;
  int value2;
  int value3;
  int value4;
  int value5;
  
  value3 = 0;
  value5 = 0;
  CRT_Lock(2);
  value4 = 0;
  if (0 < DAT_00586c00) {
    do {
      value2 = *(int *)(DAT_00585bec + value4 * 4);
      if ((value2 != 0) && ((*(uint8_t *)(value2 + 0xc) & 0x83) != 0)) {
        CRT_LockFile2(value4,value2);
        ptr1 = *(int **)(DAT_00585bec + value4 * 4);
        if ((ptr1[3] & 0x83U) != 0) {
          if (arg1 == 1) {
            value2 = CRT_FflushLocked(ptr1);
            if (value2 != -1) {
              value3 = value3 + 1;
            }
          }
          else if ((arg1 == 0) && ((ptr1[3] & 2U) != 0)) {
            value2 = CRT_FflushLocked(ptr1);
            if (value2 == -1) {
              value5 = -1;
            }
          }
        }
        CRT_UnlockHandle(value4,*(int *)(DAT_00585bec + value4 * 4));
      }
      value4 = value4 + 1;
    } while (value4 < DAT_00586c00);
  }
  CS_LeaveIndexed(2);
  if (arg1 != 1) {
    value3 = value5;
  }
  return value3;
}
