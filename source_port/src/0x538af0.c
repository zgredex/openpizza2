// Surface_CreateDesc: ported from Pizza Connection 2 at 0x538af0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x538af0
#include "pc2_port.h"

uint32_t __thiscall
Surface_CreateDesc(void *self,uint32_t arg1,uint32_t arg2,int *arg3,int arg4,
                  uint32_t arg5)

{
  int value1;
  uint32_t *uptr2;
  uint32_t local_6c [26];
  uint32_t local_4;
  
  *arg3 = 0;
  uptr2 = local_6c;
  for (value1 = 0x1b; value1 != 0; value1 = value1 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  local_6c[3] = arg1;
  local_6c[0] = 0x6c;
  local_6c[2] = arg2;
  local_6c[1] = 7;
  if (arg4 == 0) {
    local_4 = arg5 | 0x40;
  }
  else {
    local_4 = arg5 | 0x4000;
  }
  value1 = (**(code **)(*(int *)**(uint32_t **)((intptr_t)self + 0x40) + 0x18))
                    ((int *)**(uint32_t **)((intptr_t)self + 0x40),local_6c,&arg5,0);
  if (value1 == 0) {
    return arg1;
  }
  if (value1 < -0x7789ff1e) {
    if (value1 == -0x7789ff1f) {
      *arg3 = 0x136;
      return 0;
    }
    if (value1 < -0x7789ff7d) {
      if (value1 == -0x7789ff7e) {
        *arg3 = 0x12f;
        return 0;
      }
      if (value1 < -0x7789ffa0) {
        if (value1 == -0x7789ffa1) {
          *arg3 = 0x12d;
          return 0;
        }
        if (value1 == -0x7ff8fff2) {
          *arg3 = 0x13a;
          return 0;
        }
        if (value1 == -0x7ff8ffa9) {
          *arg3 = 0x130;
          return 0;
        }
      }
      else if (value1 == -0x7789ff9c) {
        *arg3 = 0x12e;
        return 0;
      }
    }
    else {
      if (value1 == -0x7789ff6f) {
        *arg3 = 0x131;
        return 0;
      }
      if (value1 == -0x7789ff4c) {
        *arg3 = 0x132;
        return 0;
      }
      if (value1 == -0x7789ff2c) {
        *arg3 = 0x133;
        return 0;
      }
    }
  }
  else if (value1 < -0x7789fdcb) {
    if (value1 == -0x7789fdcc) {
      *arg3 = 0x13c;
      return 0;
    }
    if (value1 < -0x7789fe83) {
      if (value1 == -0x7789fe84) {
        *arg3 = 0x13b;
        return 0;
      }
      if (value1 == -0x7789ff1a) {
        *arg3 = 0x137;
        return 0;
      }
      if (value1 == -0x7789feac) {
        *arg3 = 0x139;
        return 0;
      }
    }
    else if (value1 == -0x7789fdcd) {
      *arg3 = 0x134;
      return 0;
    }
  }
  else if (value1 == -0x7789fdcb) {
    value1 = 9;
  }
  else {
    if (value1 == -0x7789fdb2) {
      *arg3 = 0x13d;
      return 0;
    }
    if (value1 == -0x7789fdb1) {
      *arg3 = 0x138;
      return 0;
    }
  }
  *arg3 = value1 + 300;
  return 0;
}
