// Personnel_UpdateEmployeeRows: ported from Pizza Connection 2 at 0x4b1e80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4b1e80
#include "pc2_port.h"

void __cdecl Personnel_UpdateEmployeeRows(void *arg1)

{
  void *self;
  int value1;
  int *ptr2;
  int value3;
  
                    /* Refreshes the personnel employee rows. */
  self = (void *)IDMap_Lookup((void *)(DAT_0057d68c + 0x148),DAT_0056a6d8,(int *)0x0);
  value1 = Game_CountObjectsByType(self,0xffffffff);
  if (7 < value1) {
    value1 = 7;
  }
  if (DAT_0056a6d4 != -1) {
    ptr2 = (int *)Array_GetRecordByKey(arg1,DAT_0056a6d4 + 0x57d);
    (**(code **)(*ptr2 + 0xc))(1,0,0);
  }
  value3 = 0;
  if (0 < value1) {
    do {
      if (DAT_0057d688 + value3 == DAT_0056a6d0) {
        DAT_0056a6d4 = value3;
        ptr2 = (int *)Array_GetRecordByKey(arg1,value3 + 0x57d);
        (**(code **)(*ptr2 + 0xc))(1,2,0);
      }
      ptr2 = (int *)IDMap_Lookup((void *)((intptr_t)self + 0x1500),DAT_0057d688 + value3,(int *)0x0);
      PersonnelPage_UpdateEmployeePanel(arg1,value3,ptr2);
      value3 = value3 + 1;
    } while (value3 < value1);
  }
  return;
}
