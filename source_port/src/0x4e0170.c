// Stats_AppendPeriodReport: ported from Pizza Connection 2 at 0x4e0170.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e0170
#include "pc2_port.h"


void __fastcall Stats_AppendPeriodReport(int arg1)

{
  void *self;
  uint32_t *uptr1;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005593fb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  self = operator_new(0x35c);
  local_4 = 0;
  if (self == (void *)0x0) {
    uptr1 = (uint32_t *)0x0;
  }
  else {
    uptr1 = Stats_Report_Construct
                       (self,(uint32_t)*(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 10),
                        (uint32_t)*(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 4),arg1);
  }
  local_4 = 0xffffffff;
  List_Add((void *)(arg1 + 0x164),uptr1);
  ExceptionList = local_c;
  return;
}
