// UI_AddBriefingEntry: ported from Pizza Connection 2 at 0x54aaa0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54aaa0
#include "pc2_port.h"

int __thiscall
UI_AddBriefingEntry(void *self,int arg1,int arg2,int arg3,int arg4,int arg5,
                   int arg6,char *arg7,char *arg8)

{
  char cVar1;
  int *ptr2;
  int value3;
  void *this_00;
  int value4;
  uint32_t uvalue5;
  uint32_t uvalue6;
  uint32_t uvalue7;
  int *ptr8;
  char *cptr9;
  int *ptr10;
  void *local_4;
  
  local_4 = self;
  Sound_SetState(DAT_0057ba0c,arg2);
  Sound_PlaySpeechStatement(DAT_0057ba0c,arg1);
  uvalue5 = 0xffffffff;
  cptr9 = arg8;
  do {
    if (uvalue5 == 0) break;
    uvalue5 = uvalue5 - 1;
    cVar1 = *cptr9;
    cptr9 = cptr9 + 1;
  } while (cVar1 != '\0');
  uvalue6 = 0xffffffff;
  cptr9 = arg8;
  do {
    if (uvalue6 == 0) break;
    uvalue6 = uvalue6 - 1;
    cVar1 = *cptr9;
    cptr9 = cptr9 + 1;
  } while (cVar1 != '\0');
  ptr2 = operator_new(~uvalue6 + 0x7b);
  uvalue6 = 0xffffffff;
  do {
    cptr9 = arg8;
    if (uvalue6 == 0) break;
    uvalue6 = uvalue6 - 1;
    cptr9 = arg8 + 1;
    cVar1 = *arg8;
    arg8 = cptr9;
  } while (cVar1 != '\0');
  uvalue6 = ~uvalue6;
  ptr8 = (int *)(cptr9 + -uvalue6);
  ptr10 = ptr2 + 0x1e;
  for (uvalue7 = uvalue6 >> 2; uvalue7 != 0; uvalue7 = uvalue7 - 1) {
    *ptr10 = *ptr8;
    ptr8 = ptr8 + 1;
    ptr10 = ptr10 + 1;
  }
  for (uvalue6 = uvalue6 & 3; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
    *(char *)ptr10 = (char)*ptr8;
    ptr8 = (int *)((intptr_t)ptr8 + 1);
    ptr10 = (int *)((intptr_t)ptr10 + 1);
  }
  _strncpy((char *)(ptr2 + 0xe),arg7,0x40);
  *ptr2 = ~uvalue5 + 0x7b;
  ptr2[1] = arg2;
  ptr2[5] = arg6;
  value3 = -1;
  ptr2[4] = 0;
  ptr2[2] = -1;
  ptr2[7] = -0x40800000;
  ptr2[6] = (intptr_t)self;
  ptr2[9] = arg3;
  ptr2[10] = arg4;
  if (arg5 != 0) {
    this_00 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),
                                   (int *)0x0);
    value3 = Array_FindIndexByPtr(this_00,arg5);
  }
  ptr2[0xc] = value3;
  ptr2[0xb] = arg1;
  ptr2[0xd] = 0;
  value3 = List_Add((void *)((intptr_t)self + 4),ptr2);
  if (*(int *)((intptr_t)self + 0x30) == 0) {
    do {
      if (*(int *)((intptr_t)self + 0x18) < 10) {
        return value3;
      }
      value4 = UI_FindFreeBriefing(self);
    } while (value4 != 0);
    return value3;
  }
  value4 = MessageList_FindFreeSlot(self,(int *)&local_4);
  while( true ) {
    if (value4 != -1) {
      UI_AddBriefingButton(self,(intptr_t)ptr2,value4,600);
      ptr2[3] = (intptr_t)local_4;
      ptr2[8] = (intptr_t)-((float)ptr2[7] - (float)(intptr_t)local_4);
      Array_GetRecordByKey(*(void **)((intptr_t)self + 0x34),value4);
      return value3;
    }
    value4 = UI_FindFreeBriefing(self);
    if (value4 == 0) break;
    value4 = MessageList_FindFreeSlot(self,(int *)&local_4);
  }
  return -1;
}
