// Text_MeasureStyledRun: ported from Pizza Connection 2 at 0x52cfb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52cfb0
#include "pc2_port.h"

int __thiscall
Text_MeasureStyledRun
          (char *self,char *arg1,char *arg2,int arg3,uint32_t *arg4,uint32_t *arg5,
          uint32_t *arg6)

{
  uint8_t flag1;
  char cVar2;
  uint32_t *uptr3;
  char *pvVar4;
  uint8_t uvalue5;
  uint32_t *uptr6;
  uint32_t *uptr7;
  uint32_t extraout_var;
  uint32_t extraout_var_00;
  int value8;
  uint32_t extraout_var_01;
  char *pvVar9;
  char *local_c;
  int local_8;
  uint32_t *local_4;
  
  pvVar4 = arg1;
  local_8 = -1;
  local_4 = (uint32_t *)0x0;
  local_c = (void *)0x0;
  uptr6 = (uint32_t *)0x0;
  if (*(int *)((intptr_t)self + 0x80) != 0) {
    uptr6 = *(uint32_t **)((intptr_t)self + 0x88);
    local_c = (void *)*uptr6;
  }
  uptr7 = (uint32_t *)CONCAT31((int3)((uint32_t)uptr6 >> 8),*(char *)((intptr_t)arg1 + arg3));
  if (*(char *)((intptr_t)arg1 + arg3) != '\0') {
    do {
      if ((uint8_t)uptr7 != 1) {
        if (0x1f < (uint8_t)uptr7) {
          uptr3 = *(uint32_t **)((intptr_t)arg2 + 0x9b0);
          uptr7 = uptr3;
          if ((intptr_t)local_4 < (intptr_t)uptr3) {
            *arg6 = arg2;
            uptr7 = arg6;
            local_4 = uptr3;
          }
        }
        cVar2 = *(char *)((intptr_t)pvVar4 + arg3);
        pvVar9 = (void *)CONCAT31((int3)((uint32_t)uptr7 >> 8),cVar2);
        if (cVar2 != '\n') {
          if (cVar2 == ' ') {
            arg1 = local_c;
            local_8 = arg3;
          }
          if (cVar2 == '\r') break;
          uvalue5 = Font_GetCharWidth(arg2,(uint32_t)pvVar9);
          value8 = CONCAT31(extraout_var_00,uvalue5);
          if (value8 == 0) {
            uvalue5 = Font_GetCharWidth(arg2,0x20);
            value8 = CONCAT31(extraout_var_01,uvalue5);
          }
          pvVar9 = (void *)(value8 + (intptr_t)local_c);
          if ((intptr_t)*(short *)((intptr_t)self + 100) < (intptr_t)pvVar9) {
            if (local_8 != -1) {
              local_c = arg1;
              arg3 = local_8;
            }
            break;
          }
          local_c = pvVar9;
        }
        arg3 = arg3 + 1;
        goto LAB_0052d168;
      }
      pvVar9 = (void *)(uint32_t)*(uint8_t *)((intptr_t)pvVar4 + arg3 + 2);
      switch((intptr_t)pvVar9) {
      case 0x0:
        flag1 = *(uint8_t *)((intptr_t)pvVar4 + arg3 + 3);
        if ((flag1 == 9 || flag1 < 9) &&
           (pvVar9 = *(void **)(*(int *)((intptr_t)self + 0x88) + 0xc + (uint32_t)flag1 * 4),
           pvVar9 != (void *)0x0)) {
          arg3 = arg3 + 2 + (uint32_t)*(uint8_t *)((intptr_t)pvVar4 + arg3 + 1);
          arg2 = pvVar9;
        }
        else {
          pvVar9 = *(void **)((intptr_t)self + 0x88);
          arg2 = *(void **)((intptr_t)pvVar9 + 0xc);
          arg3 = arg3 + 2 + (uint32_t)*(uint8_t *)((intptr_t)pvVar4 + arg3 + 1);
        }
        break;
      case 0x2:
      case 0x3:
        if (*(int *)((intptr_t)self + 0x80) != 0) goto switchD_0052d013_caseD_1;
        *(uint32_t *)((intptr_t)self + 0x80) = 1;
        if (*(char *)((intptr_t)pvVar4 + arg3 + 2) == '\x02') {
          *(uint32_t *)((intptr_t)self + 0x84) = 1;
          pvVar9 = (void *)((intptr_t)local_c + 0x14);
          arg3 = arg3 + 2 + (uint32_t)*(uint8_t *)((intptr_t)pvVar4 + arg3 + 1);
          local_c = pvVar9;
        }
        else {
          *(uint32_t *)((intptr_t)self + 0x84) = 0;
          pvVar9 = (void *)((intptr_t)local_c + 0x14);
          arg3 = arg3 + 2 + (uint32_t)*(uint8_t *)((intptr_t)pvVar4 + arg3 + 1);
          local_c = pvVar9;
        }
        break;
      case 0x4:
        *arg5 = (uint32_t)*(uint8_t *)((intptr_t)pvVar4 + arg3 + 3);
        arg3 = arg3 + 2 + (uint32_t)*(uint8_t *)((intptr_t)pvVar4 + arg3 + 1);
        break;
      case 0x5:
        uvalue5 = Font_GetCharWidth(arg2,0x2d);
        pvVar9 = (void *)(CONCAT31(extraout_var,uvalue5) + (intptr_t)local_c);
        if ((intptr_t)pvVar9 <= (intptr_t)*(short *)((intptr_t)self + 100)) {
          local_8 = arg3 + 3;
          arg1 = pvVar9;
        }
      default:
switchD_0052d013_caseD_1:
        arg3 = arg3 + 2 + (uint32_t)*(uint8_t *)((intptr_t)pvVar4 + arg3 + 1);
      }
LAB_0052d168:
      uptr7 = (uint32_t *)CONCAT31((int3)((uint32_t)pvVar9 >> 8),*(char *)((intptr_t)pvVar4 + arg3));
    } while (*(char *)((intptr_t)pvVar4 + arg3) != '\0');
  }
  *arg4 = (uint32_t)local_c;
  return arg3;
}
