// City_AssignPersonToBuilding: ported from Pizza Connection 2 at 0x4f7dd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f7dd0
#include "pc2_port.h"

int * City_AssignPersonToBuilding(void *arg1,uint32_t arg2)

{
  void *self;
  int *ptr1;
  int value2;
  int value3;
  int *ptr4;
  uint32_t local_78;
  int local_74 [29];
  
                    /* Assigns an idle person to a building. */
  self = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  Game_BuildTopRatedObjectList((intptr_t)arg1,&local_78,arg2);
  value3 = 0;
  ptr4 = local_74;
  do {
    if (((ptr4[1] != 0) &&
        (ptr1 = (int *)Game_LookupObjectByIndex(self,*ptr4), ptr1 != (int *)0x0)) &&
       (value2 = City_RemovePersonEntry(self,ptr1), value2 != 0)) goto LAB_004f7e5b;
    value3 = value3 + 1;
    ptr4 = ptr4 + 3;
  } while (value3 < 10);
  ptr1 = City_SpawnPerson(self,arg2);
  City_RemovePersonEntry(self,ptr1);
LAB_004f7e5b:
  Company_AssignEmployee(arg1,ptr1,arg2,0);
  return ptr1;
}
