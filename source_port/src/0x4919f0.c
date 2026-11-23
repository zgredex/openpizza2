// Chart_DrawRatingMatrix: ported from Pizza Connection 2 at 0x4919f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4919f0
#include "pc2_port.h"

void __cdecl
Chart_DrawRatingMatrix(char *arg1,int arg2,char *arg3,void *arg4,float arg5)

{
  uint32_t *uptr1;
  void *pvVar2;
  float fVar3;
  float fVar4;
  void *self;
  char *pvVar5;
  int value6;
  int *ptr7;
  uint32_t *uptr8;
  int value9;
  int64_t lvalue10;
  int64_t lvalue11;
  
  pvVar2 = *(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  self = (void *)UI_GetWindowObject(arg1,arg2);
  UI_RealizeSprite((intptr_t)self);
  if (*(short *)(*(int *)(DAT_0057c670 + 0x94) + 10) == 0) {
    UI_GetChildSize(self,(int *)&arg1,&arg2);
    pvVar5 = (void *)Object_GetActiveValue((intptr_t)self);
    pvVar2 = arg3;
    Text_SetMetrics(arg3,(intptr_t)arg1 / 2,arg2 / 2,2);
    Set_Field9B8(pvVar2,0);
    Font_DrawTextLine(pvVar2,pvVar5,DAT_00581444);
    UI_ClipChildRect((intptr_t)self);
    return;
  }
  value6 = Game_GetMaxMatrixValue(pvVar2,(intptr_t)arg4);
  arg3 = (void *)pc2_bits((double)(float)(intptr_t)(value6));
  UI_GetChildSize(self,(int *)&arg1,&arg2);
  arg1 = (void *)((intptr_t)arg1 + -3);
  arg2 = arg2 + -3;
  fVar3 = (float)(intptr_t)arg1;
  ptr7 = UI_CreateWindowFromRect(self,0,3);
  fVar4 = arg5;
  arg3 = (void *)0x0;
  do {
    pvVar5 = arg3;
    if (*(int *)((intptr_t)fVar4 + (intptr_t)arg3) != 0) {
      arg5 = 0.0;
      Game_SumPlayerMatrixValues(pvVar2,*(uint32_t *)((intptr_t)arg3 + 0x568638),8,arg4);
      value6 = 0;
      while( true ) {
        arg5 = arg5 + fVar3 * 0.125;
        Game_SumPlayerMatrixValues(pvVar2,*(uint32_t *)((intptr_t)pvVar5 + 0x568638),value6,arg4);
        lvalue10 = __ftol();
        value9 = arg2 - (intptr_t)lvalue10;
        lvalue10 = __ftol();
        uptr1 = (uint32_t *)((intptr_t)lvalue10 + 1);
        lvalue10 = __ftol();
        lvalue11 = __ftol();
        uptr8 = (uint32_t *)((intptr_t)lvalue11 + 1);
        UI_DrawChildSprite(self,uptr8,(intptr_t)lvalue10 + 2,uptr1,value9 + 2,0);
        UI_DrawChildSprite(self,uptr8,(intptr_t)lvalue10 + 1,uptr1,value9 + 1,
                           *(uint32_t *)((intptr_t)arg3 + 0x568668));
        value6 = value6 + 1;
        if (7 < value6) break;
        pvVar5 = arg3;
      }
    }
    arg3 = (void *)((intptr_t)arg3 + 4);
  } while ((intptr_t)arg3 < 0x10);
  UI_ClipChildRect((intptr_t)self);
  RefCounted_Free(ptr7);
  return;
}
