// Dialog_WriteChildRecord: ported from Pizza Connection 2 at 0x520e80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x520e80
#include "pc2_port.h"

void __fastcall Dialog_WriteChildRecord(int *arg1)

{
  int value1;
  uint32_t unaff_ESI;
  int *ptr2;
  int *unaff_retaddr;
  char local_458 [4];
  int local_454 [4];
  int local_444;
  int local_440;
  int local_43c;
  uint32_t local_434;
  uint32_t local_32c;
  int local_14;
  
  ptr2 = local_454;
  for (value1 = 0x115; value1 != 0; value1 = value1 + -1) {
    *ptr2 = 0;
    ptr2 = ptr2 + 1;
  }
  local_444 = arg1[0xf];
  local_458[0] = 'T';
  local_458[1] = '\x04';
  local_458[2] = '\0';
  local_458[3] = '\0';
  local_454[0] = 0x454;
  local_454[3] = arg1[0xe];
  local_440 = arg1[0xc] - arg1[10];
  local_43c = arg1[0xd] - arg1[0xb];
  local_434 = 0xd;
  local_32c = 0xd;
  local_14 = arg1[1];
  local_454[1] = 0;
  (**(code **)(*arg1 + 8))(local_454);
  CRT_FwriteLocked(local_458 + -4,1,4,unaff_retaddr);
  CRT_FwriteLocked(local_458,1,unaff_ESI,unaff_retaddr);
  return;
}
