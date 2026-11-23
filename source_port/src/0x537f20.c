// DirectDraw_Init: ported from Pizza Connection 2 at 0x537f20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x537f20
#include "pc2_port.h"

void __fastcall DirectDraw_Init(int arg1)

{
  uint32_t uvalue1;
  int *ptr2;
  int value3;
  HWND pHVar4;
  HDC hdc;
  uint32_t *uptr5;
  uint32_t *puStack_b0;
  uint32_t uStack_ac;
  int *piStack_a8;
  uint32_t *puStack_a4;
  uint32_t *puStack_a0;
  uint8_t auStack_8a [2];
  uint32_t auStack_88 [2];
  int *piStack_40;
  int *piStack_34;
  int *piStack_24;
  int *piStack_14;
  uint32_t *puStack_8;
  
  auStack_88[1] = 0;
  uvalue1 = *(uint32_t *)(arg1 + 0x40);
  value3 = DirectDrawCreate_Thunk();
  if (value3 != 0) {
    *puStack_8 = 200;
    return;
  }
  if (*(int *)(arg1 + 0x4c) != 0) {
    pHVar4 = GetDesktopWindow();
    hdc = GetDC(pHVar4);
    puStack_a0 = (uint32_t *)0x53844b;
    GetDeviceCaps(hdc,8);
    puStack_a0 = (uint32_t *)0x538454;
    GetDeviceCaps(hdc,10);
    puStack_a0 = (uint32_t *)0x53845d;
    value3 = GetDeviceCaps(hdc,0xc);
    pHVar4 = GetDesktopWindow();
    puStack_a0 = (uint32_t *)0x538469;
    ReleaseDC(pHVar4,hdc);
    if (value3 != 0x10) {
      (**(code **)(*(int *)**(uint32_t **)(arg1 + 0x40) + 0x50))();
      piStack_a8 = (int *)**(uint32_t **)(arg1 + 0x40);
      puStack_a0 = (uint32_t *)0x0;
      uStack_ac = 0x538498;
      puStack_a4 = (uint32_t *)uvalue1;
      (**(code **)(*piStack_a8 + 0x54))();
    }
    (**(code **)(*(int *)**(uint32_t **)(arg1 + 0x40) + 0x50))();
    uptr5 = auStack_88;
    for (value3 = 0x1b; uptr5 = uptr5 + 1, value3 != 0; value3 = value3 + -1) {
      *uptr5 = 0;
    }
    auStack_88[1] = 0x6c;
    piStack_a8 = (int *)**(uint32_t **)(arg1 + 0x40);
    puStack_a0 = *(uint32_t **)(arg1 + 0x40) + 1;
    puStack_a4 = auStack_88 + 1;
    uStack_ac = 0x5384e8;
    value3 = (**(code **)(*piStack_a8 + 0x18))();
    if (value3 == 0) {
      *(uint32_t *)(*(int *)(arg1 + 0x40) + 0x10) =
           *(uint32_t *)(*(int *)(arg1 + 0x40) + 4);
      *(uint32_t *)(*(int *)(arg1 + 0x40) + 0xc) =
           *(uint32_t *)(*(int *)(arg1 + 0x40) + 4);
      return;
    }
    if (value3 < -0x7789ff1e) {
      if (value3 == -0x7789ff1f) {
        *piStack_24 = 0x104;
        return;
      }
      if (value3 < -0x7789ff7d) {
        if (value3 == -0x7789ff7e) {
          *piStack_24 = 0xfd;
          return;
        }
        if (value3 < -0x7789ffa0) {
          if (value3 == -0x7789ffa1) {
            *piStack_24 = 0xfb;
            return;
          }
          if (value3 == -0x7ff8fff2) {
            *piStack_24 = 0x108;
            return;
          }
          if (value3 == -0x7ff8ffa9) {
            *piStack_24 = 0xfe;
            return;
          }
        }
        else if (value3 == -0x7789ff9c) {
          *piStack_24 = 0xfc;
          return;
        }
      }
      else {
        if (value3 == -0x7789ff6f) {
          *piStack_24 = 0xff;
          return;
        }
        if (value3 == -0x7789ff4c) {
          *piStack_24 = 0x100;
          return;
        }
        if (value3 == -0x7789ff2c) {
          *piStack_24 = 0x101;
          return;
        }
      }
    }
    else if (value3 < -0x7789fdcb) {
      if (value3 == -0x7789fdcc) {
        *piStack_24 = 0x10a;
        return;
      }
      if (value3 < -0x7789fe83) {
        if (value3 == -0x7789fe84) {
          *piStack_24 = 0x109;
          return;
        }
        if (value3 == -0x7789ff1a) {
          *piStack_24 = 0x105;
          return;
        }
        if (value3 == -0x7789feac) {
          *piStack_24 = 0x107;
          return;
        }
      }
      else if (value3 == -0x7789fdcd) {
        *piStack_24 = 0x102;
        return;
      }
    }
    else if (value3 == -0x7789fdcb) {
      value3 = 9;
    }
    else {
      if (value3 == -0x7789fdb2) {
        *piStack_24 = 0x10b;
        return;
      }
      if (value3 == -0x7789fdb1) {
        *piStack_24 = 0x106;
        return;
      }
    }
    *piStack_24 = value3 + 0xfa;
    return;
  }
  value3 = (**(code **)(*(int *)**(uint32_t **)(arg1 + 0x40) + 0x50))();
  if (value3 == 0) {
    piStack_a8 = (int *)**(uint32_t **)(arg1 + 0x40);
    puStack_a0 = (uint32_t *)DAT_00574738;
    puStack_a4 = (uint32_t *)DAT_00574734;
    uStack_ac = 0x538062;
    value3 = (**(code **)(*piStack_a8 + 0x54))();
    if (value3 != 0) {
      *piStack_24 = *piStack_24 + 0xd2;
      return;
    }
    uStack_ac = 0;
    uptr5 = (uint32_t *)(auStack_8a + -10);
    for (value3 = 0x1b; value3 != 0; value3 = value3 + -1) {
      *uptr5 = 0;
      uptr5 = uptr5 + 1;
    }
    ptr2 = (int *)**(uint32_t **)(arg1 + 0x40);
    puStack_b0 = *(uint32_t **)(arg1 + 0x40) + 1;
    value3 = (**(code **)(*ptr2 + 0x18))(ptr2,auStack_8a + -10);
    if (value3 == 0) {
      puStack_b0 = (uint32_t *)0x4;
      ptr2 = *(int **)(*(int *)(arg1 + 0x40) + 4);
      value3 = (**(code **)(*ptr2 + 0x30))(ptr2,&puStack_b0,*(int *)(arg1 + 0x40) + 8);
      if (value3 == 0) {
        *(uint32_t *)(arg1 + 0x98) = 1;
        *(uint32_t *)(*(int *)(arg1 + 0x40) + 0x10) =
             *(uint32_t *)(*(int *)(arg1 + 0x40) + 4);
        *(uint32_t *)(*(int *)(arg1 + 0x40) + 0xc) =
             *(uint32_t *)(*(int *)(arg1 + 0x40) + 8);
        return;
      }
      if (value3 < -0x7789ff7d) {
        if (value3 == -0x7789ff7e) {
          *piStack_40 = 0xdd;
          return;
        }
        if (value3 == -0x7ff8ffa9) {
          *piStack_40 = 0xde;
          return;
        }
        if (value3 == -0x7789ff9c) {
          *piStack_40 = 0xe1;
          return;
        }
      }
      else if (value3 == -0x7789ff01) {
        value3 = 3;
      }
      else if (value3 == -0x7789fe3e) {
        *piStack_40 = 0xe0;
        return;
      }
      *piStack_40 = value3 + 0xdc;
      return;
    }
    if (value3 < -0x7789ff1e) {
      if (value3 == -0x7789ff1f) {
        *piStack_34 = 0xdc;
        return;
      }
      if (value3 < -0x7789ff7d) {
        if (value3 == -0x7789ff7e) {
          *piStack_34 = 0xd5;
          return;
        }
        if (value3 < -0x7789ffa0) {
          if (value3 == -0x7789ffa1) {
            *piStack_34 = 0xd3;
            return;
          }
          if (value3 == -0x7ff8fff2) {
            *piStack_34 = 0xe0;
            return;
          }
          if (value3 == -0x7ff8ffa9) {
            *piStack_34 = 0xd6;
            return;
          }
        }
        else if (value3 == -0x7789ff9c) {
          *piStack_34 = 0xd4;
          return;
        }
      }
      else {
        if (value3 == -0x7789ff6f) {
          *piStack_34 = 0xd7;
          return;
        }
        if (value3 == -0x7789ff4c) {
          *piStack_34 = 0xd8;
          return;
        }
        if (value3 == -0x7789ff2c) {
          *piStack_34 = 0xd9;
          return;
        }
      }
    }
    else if (value3 < -0x7789fdcb) {
      if (value3 == -0x7789fdcc) {
        *piStack_34 = 0xe2;
        return;
      }
      if (value3 < -0x7789fe83) {
        if (value3 == -0x7789fe84) {
          *piStack_34 = 0xe1;
          return;
        }
        if (value3 == -0x7789ff1a) {
          *piStack_34 = 0xdd;
          return;
        }
        if (value3 == -0x7789feac) {
          *piStack_34 = 0xdf;
          return;
        }
      }
      else if (value3 == -0x7789fdcd) {
        *piStack_34 = 0xda;
        return;
      }
    }
    else if (value3 == -0x7789fdcb) {
      value3 = 9;
    }
    else {
      if (value3 == -0x7789fdb2) {
        *piStack_34 = 0xe3;
        return;
      }
      if (value3 == -0x7789fdb1) {
        *piStack_34 = 0xde;
        return;
      }
    }
    *piStack_34 = value3 + 0xd2;
    return;
  }
  if (value3 < -0x7789fdc5) {
    if (value3 == -0x7789fdc6) {
      *piStack_14 = 0xcb;
      return;
    }
    if (value3 == -0x7ff8fff2) {
      *piStack_14 = 0xce;
      return;
    }
    if (value3 == -0x7ff8ffa9) {
      *piStack_14 = 0xcd;
      return;
    }
    if (value3 == -0x7789ff7e) {
      *piStack_14 = 0xcc;
      return;
    }
  }
  else if (value3 == -0x7789fdc5) {
    value3 = 2;
  }
  else if (value3 == -0x7789fdbb) {
    *piStack_14 = 0xc9;
    return;
  }
  *piStack_14 = value3 + 200;
  return;
}
