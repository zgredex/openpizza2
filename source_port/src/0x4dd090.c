// Game_RebuildLocalRecordOwners: ported from Pizza Connection 2 at 0x4dd090.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dd090
#include "pc2_port.h"

void __fastcall Game_RebuildLocalRecordOwners(int arg1)

{
  int value1;
  int value2;
  void *self;
  void *this_00;
  int value3;
  
  value1 = *(int *)(arg1 + 0xfc0);
  value3 = 0;
  if (0 < value1) {
    do {
      self = (void *)IDMap_Lookup((void *)(arg1 + 0xfac),value3,(int *)0x0);
      value2 = *(int *)((intptr_t)self + 0x8c);
      while (value2 = value2 + -1, -1 < value2) {
        this_00 = (void *)Game_MapRecordToGlobal(self,value2);
        if (this_00 == (void *)0x0) {
          Game_RemoveLocalEntryRecursive(self,value2);
        }
        else {
          Set_Field168(this_00,self);
        }
      }
      value3 = value3 + 1;
    } while (value3 < value1);
  }
  return;
}
