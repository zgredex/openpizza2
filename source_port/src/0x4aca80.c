// StatisticsBranchBalance_DrawColumn: ported from Pizza Connection 2 at 0x4aca80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4aca80
#include "pc2_port.h"

void __cdecl
StatisticsBranchBalance_DrawColumn
          (void *arg1,int *arg2,float arg3,int arg4,char arg5)

{
  int *ptr1;
  int value2;
  int local_54 [4];
  uint32_t local_44;
  uint8_t local_40 [64];
  
                    /* Draws one branch column of the balance comparison page. */
  local_54[0] = DAT_005826d8;
  local_54[1] = DAT_00582320;
  local_54[3] = DAT_00582858;
  local_54[2] = DAT_0058271c;
  local_44 = DAT_00582998;
  if (arg5 != '\0') {
    value2 = 0;
    ptr1 = arg2;
    do {
      Rating_UpdateBarByKey
                (arg1,(&DAT_00569520)[arg4] + value2,-1,*ptr1,
                 *(int *)((intptr_t)ptr1 + ((intptr_t)local_54 - (intptr_t)arg2)));
      value2 = value2 + 0x11;
      ptr1 = ptr1 + 1;
    } while (value2 < 0x55);
  }
  String_Format(local_40,&DAT_005686f4,arg2[5]);
  Window_GadgetNotify_Text_SetText(arg1,(&DAT_00569548)[arg4],local_40);
  String_Format(local_40,&DAT_005686f4,arg2[6]);
  Window_GadgetNotify_Text_SetText(arg1,(&DAT_00569548)[arg4] + 1,local_40);
  String_Format(local_40,(uint8_t *)s__0_2f_005685f4,SUB84((double)arg3,0));
  Window_GadgetNotify_Text_SetText(arg1,arg4 * 3 + 0x845,local_40);
  return;
}
