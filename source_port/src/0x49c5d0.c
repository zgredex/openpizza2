// CompanyRanking_SelectLastCompanyButton: ported from Pizza Connection 2 at 0x49c5d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49c5d0
#include "pc2_port.h"

void __cdecl CompanyRanking_SelectLastCompanyButton(void *arg1,int arg2)

{
  void *self;
  int value1;
  int *ptr2;
  
  ptr2 = &DAT_00568a14;
  do {
    Window_GadgetNotify_Button_SetState(arg1,*ptr2,0);
    ptr2 = ptr2 + 1;
  } while ((intptr_t)ptr2 < 0x568a34);
  Window_GadgetNotify_Button_SetState(arg1,arg2,1);
  DAT_0057ca90 = *(int *)(DAT_0057ca94 + 0x1c + DAT_0057ca40 * 4);
  value1 = Game_GetActiveCompanyById
                    (*(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4),
                     DAT_0057ca90);
  *(int *)(DAT_0057c670 + 0x98) = value1;
  self = *(void **)(DAT_0057c670 + 0x25c);
  value1 = Game_FindCompanyIndex
                    (*(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4),
                     *(int *)(DAT_0057c670 + 0x98));
  UI_QueueControlCommand(self,-0x18671,0x23,value1);
  return;
}
