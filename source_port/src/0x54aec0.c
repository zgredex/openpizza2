// UI_AddBriefingButton: ported from Pizza Connection 2 at 0x54aec0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54aec0
#include "pc2_port.h"


void __thiscall UI_AddBriefingButton(void *self,int arg1,int arg2,int arg3)

{
  char cVar1;
  void *pvVar2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  char *cptr5;
  char *cptr6;
  char local_800 [2048];
  
  UI_AddImage(*(void **)((intptr_t)self + 0x34),arg2,arg3,*(int *)((intptr_t)self + 0x24),
              (&PTR_s_BRIEFBUTTONS_ALLGEM_00_005763a4)
              [(uint32_t)(*(int *)(arg1 + 0x10) == 0) + *(int *)(arg1 + 4) * 2],0,0);
  UI_SetChildLabelText(*(void **)((intptr_t)self + 0x34),arg2,1,(char *)0x0);
  uvalue3 = 0xffffffff;
  cptr5 = (char *)(arg1 + 0x38);
  do {
    cptr6 = cptr5;
    if (uvalue3 == 0) break;
    uvalue3 = uvalue3 - 1;
    cptr6 = cptr5 + 1;
    cVar1 = *cptr5;
    cptr5 = cptr6;
  } while (cVar1 != '\0');
  uvalue3 = ~uvalue3;
  cptr5 = cptr6 + -uvalue3;
  cptr6 = local_800;
  for (uvalue4 = uvalue3 >> 2; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
    *(uint32_t *)cptr6 = *(uint32_t *)cptr5;
    cptr5 = cptr5 + 4;
    cptr6 = cptr6 + 4;
  }
  for (uvalue3 = uvalue3 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
    *cptr6 = *cptr5;
    cptr5 = cptr5 + 1;
    cptr6 = cptr6 + 1;
  }
  pvVar2 = (void *)UI_GetTextObject(DAT_0057c5e0);
  Font_WrapText(pvVar2,local_800,300);
  UI_SetObjectTextByKey(*(void **)((intptr_t)self + 0x34),arg2,local_800);
  *(int *)(arg1 + 8) = arg2;
  *(float *)(arg1 + 0x1c) = (float)arg3;
  pvVar2 = (void *)Array_GetRecordByKey(*(void **)((intptr_t)self + 0x34),arg2);
  if (pvVar2 != (void *)0x0) {
    UI_Text_BeginScrollAnimation(pvVar2,&LAB_0054a960,arg1);
  }
  return;
}
