// AI_ImproveSecurity: ported from Pizza Connection 2 at 0x4ffad0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ffad0
#include "pc2_port.h"

uint32_t __thiscall AI_ImproveSecurity(void *self,int arg1)

{
  void *this_00;
  int value1;
  void *this_01;
  int value2;
  void *pvVar3;
  uint32_t uvalue4;
  int64_t lvalue5;
  int local_14;
  void *local_10;
  int local_c;
  uint32_t local_8;
  uint32_t uStack_4;
  
                    /* Buys or builds additional security buildings. */
  local_10 = self;
  this_01 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),
                                 (int *)0x0);
  value2 = Game_CountRecordsByOwner(this_01,0x11);
  if (value2 < 5) {
    this_00 = *(void **)((intptr_t)self + arg1 * 0x168 + 0x70);
    value1 = *(int *)((intptr_t)self + arg1 * 0x168 + 0x40);
    uStack_4 = *(uint32_t *)((intptr_t)this_00 + 0x10c);
    local_8 = *(uint32_t *)((intptr_t)this_00 + 0x108);
    if ((intptr_t)*(short *)((intptr_t)self + arg1 * 0x168 + 0x128) * (value2 + 1) <
        (intptr_t)*(short *)((intptr_t)self + arg1 * 0x168 + 0x130)) {
      pvVar3 = (void *)AI_FindBranchPlotNearOwn(local_10,arg1,this_01);
      if (pvVar3 != (void *)0x0) {
        Game_ComputeTradeOffers(this_01,(intptr_t)pvVar3,2,&local_c,&local_14,value1,(int *)0x0);
        value2 = (value2 * 3 + 1) * local_14;
        lvalue5 = __ftol();
        if ((intptr_t)lvalue5 < value2) {
          uvalue4 = Game_CanAffordWithCurrency(this_00,2,(float)local_14,'\x01',0xffffffff);
          if ((char)uvalue4 != '\0') {
            *(int *)((intptr_t)pvVar3 + 0x3c) = local_14;
            MapObject_SpawnByKind(this_01,pvVar3,2,value1,(void *)0xffffffff,-1);
          }
        }
      }
    }
  }
  return 1;
}
