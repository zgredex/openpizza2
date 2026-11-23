// FUN_00555d5c: ported from Pizza Connection 2 at 0x555d5c.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x555d5c
#include "pc2_port.h"

int __cdecl FUN_00555d5c(uint8_t *arg1)

{
  int value1;
  size_t _MaxCount;
  size_t svalue2;
  int *ptr3;
  
  if (((DAT_00586d28 != 0) &&
      ((DAT_00585630 != (int *)0x0 ||
       (((DAT_00585638 != 0 && (value1 = FUN_00557050(), value1 == 0)) && (DAT_00585630 != (int *)0x0)
        ))))) && (ptr3 = DAT_00585630, arg1 != (uint8_t *)0x0)) {
    _MaxCount = _strlen((char *)arg1);
    for (; (char *)*ptr3 != (char *)0x0; ptr3 = ptr3 + 1) {
      svalue2 = _strlen((char *)*ptr3);
      if (((_MaxCount < svalue2) && (((uint8_t *)*ptr3)[_MaxCount] == '=')) &&
         (value1 = __mbsnbicoll((uint8_t *)*ptr3,arg1,_MaxCount), value1 == 0)) {
        return *ptr3 + 1 + _MaxCount;
      }
    }
  }
  return 0;
}
