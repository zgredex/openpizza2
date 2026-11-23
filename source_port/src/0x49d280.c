// UI_RemoveAllObjects: ported from Pizza Connection 2 at 0x49d280.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49d280
#include "pc2_port.h"

void __cdecl UI_RemoveAllObjects(void *arg1)

{
  int value1;
  int value2;
  
  value2 = 100000;
  value1 = Array_GetRecordByKeyPtr(arg1,100000);
  while (value1 != 0) {
    UI_RemoveObject(arg1,value2);
    value2 = value2 + 1;
    value1 = Array_GetRecordByKeyPtr(arg1,value2);
  }
  return;
}
