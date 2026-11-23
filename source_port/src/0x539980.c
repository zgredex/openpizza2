// Gfx_BlitClipped16: ported from Pizza Connection 2 at 0x539980.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x539980
#include "pc2_port.h"

struct pc2_obj_0x539980_local_2c_bmiHeader;
struct pc2_obj_0x539980_local_2c_bmiHeader { intptr_t biCompression; intptr_t biSizeImage; intptr_t biXPelsPerMeter; intptr_t biYPelsPerMeter; intptr_t biSize; intptr_t biClrUsed; intptr_t biClrImportant; intptr_t biPlanes; intptr_t biBitCount; intptr_t biWidth; intptr_t biHeight; };
struct pc2_obj_0x539980_local_2c { struct pc2_obj_0x539980_local_2c_bmiHeader *bmiHeader; };
void __thiscall
Gfx_BlitClipped16(char *self,HWND arg1,int arg2,uint32_t arg3,HDC arg4,int arg5,
                 int arg6,int arg7,uint16_t *arg8,HDC arg9,int arg10,uint16_t *arg11)

{
  HDC hdcSrc;
  int value1;
  HBITMAP h;
  HGDIOBJ h_00;
  uint16_t *uptr2;
  uint32_t uvalue3;
  uint16_t *uptr4;
  int value5;
  uint32_t cx;
  int value6;
  char *local_58;
  char *local_54;
  HDC local_50;
  uint32_t local_4c;
  HDC local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  struct pc2_obj_0x539980_local_2c *local_2c;
  
  if (arg10 == -1) {
    arg10 = arg3;
  }
  if (arg11 == (uint16_t *)0xffffffff) {
    arg11 = (uint16_t *)arg4;
  }
  local_44 = arg5 + arg10;
  local_40 = (intptr_t)&((struct pc2_hdc *)arg11)->unused + arg6;
  value6 = *(int *)((intptr_t)self + 0x58);
  local_3c = (arg3 - *(int *)((intptr_t)self + 0x5c)) * value6;
  local_38 = ((intptr_t)arg4 - *(int *)((intptr_t)self + 0x60)) * value6;
  value5 = value6 * arg5 + local_3c;
  uptr4 = (uint16_t *)(value6 * arg6 + local_38);
  local_4c = arg10;
  if (arg10 < 0) {
    local_4c = 0;
    local_3c = local_3c - value6 * arg10;
  }
  value1 = local_3c;
  local_48 = (HDC)arg11;
  if ((intptr_t)arg11 < 0) {
    local_48 = (HDC)0x0;
    local_38 = local_38 - value6 * (intptr_t)arg11;
  }
  if (arg7 < local_44) {
    value5 = value5 - (local_44 - arg7) * value6;
  }
  if ((intptr_t)arg8 < local_40) {
    uptr4 = (uint16_t *)((intptr_t)uptr4 - (local_40 - (intptr_t)arg8) * value6);
  }
  if (local_3c < 0) {
    local_3c = 0;
    local_4c = local_4c - value1 / value6;
  }
  if (local_38 < 0) {
    value1 = local_38 / value6;
    local_38 = 0;
    local_48 = (HDC)((intptr_t)local_48 - value1);
  }
  value1 = value6 * (arg3 - arg10) + arg7;
  if (value1 < value5) {
    value5 = value1;
  }
  uptr2 = (uint16_t *)(value6 * ((intptr_t)arg4 - (intptr_t)arg11) + (intptr_t)arg8);
  if ((intptr_t)uptr2 < (intptr_t)uptr4) {
    uptr4 = uptr2;
  }
  cx = value5 - local_3c;
  value5 = (intptr_t)uptr4 - local_38;
  if ((0 < (intptr_t)cx) && (0 < value5)) {
    value1 = value6 * (intptr_t)local_48;
    value6 = value6 * local_4c;
    local_54 = self;
    if (arg9 == (HDC)0x0) {
      arg4 = GetDC(arg1);
      if (arg4 == (HDC)0x0) {
        NoOp_Stub();
      }
    }
    else {
      arg4 = arg9;
    }
    local_2c->bmiHeader->biCompression = 0;
    local_2c->bmiHeader->biSizeImage = 0;
    local_2c->bmiHeader->biXPelsPerMeter = 0;
    local_2c->bmiHeader->biYPelsPerMeter = 0;
    local_2c->bmiHeader->biSize = 0x28;
    local_2c->bmiHeader->biClrUsed = 0x7fff;
    local_2c->bmiHeader->biClrImportant = 0x7fff;
    local_2c->bmiHeader->biPlanes = 1;
    local_2c->bmiHeader->biBitCount = 0x10;
    local_2c->bmiHeader->biWidth = cx;
    local_2c->bmiHeader->biHeight = value5;
    local_50 = CreateCompatibleDC(arg4);
    h = CreateDIBSection(local_50,&local_2c,0,&local_58,(HANDLE)0x0,0);
    hdcSrc = local_50;
    arg3 = cx;
    if ((cx & 1) != 0) {
      arg3 = cx + 1;
    }
    arg10 = 0;
    arg8 = (uint16_t *)((intptr_t)local_58 + (value5 + -1) * arg3 * 2);
    uptr4 = (uint16_t *)
             (arg2 +
             ((value1 / *(int *)((intptr_t)local_54 + 0x58)) * arg7 +
             value6 / *(int *)((intptr_t)local_54 + 0x58)) * 2);
    arg11 = uptr4;
    if (*(char *)(DAT_0057c5c8 + 0x18) == '\0') {
      if (0 < value5) {
        arg5 = value5;
        do {
          value6 = 0;
          if (0 < (intptr_t)cx) {
            uvalue3 = cx;
            uptr2 = arg8;
            do {
              value6 = value6 + 1;
              *uptr2 = *uptr4;
              if (*(int *)((intptr_t)local_54 + 0x58) <= value6) {
                value6 = 0;
                uptr4 = uptr4 + 1;
              }
              uptr2 = uptr2 + 1;
              uvalue3 = uvalue3 - 1;
            } while (uvalue3 != 0);
            uptr4 = arg11;
          }
          arg8 = arg8 + -arg3;
          arg10 = arg10 + 1;
          if (*(int *)((intptr_t)local_54 + 0x58) <= arg10) {
            arg10 = 0;
            uptr4 = uptr4 + arg7;
            arg11 = uptr4;
          }
          arg5 = arg5 + -1;
        } while (arg5 != 0);
      }
    }
    else if (0 < value5) {
      arg2 = value5;
      do {
        value6 = 0;
        if (0 < (intptr_t)cx) {
          uvalue3 = cx;
          uptr2 = arg8;
          do {
            value6 = value6 + 1;
            *uptr2 = *uptr4 >> 1 & 0x7fe0 | *uptr4 & 0x1f;
            if (*(int *)((intptr_t)local_54 + 0x58) <= value6) {
              value6 = 0;
              uptr4 = uptr4 + 1;
            }
            uptr2 = uptr2 + 1;
            uvalue3 = uvalue3 - 1;
          } while (uvalue3 != 0);
          uptr4 = arg11;
        }
        arg8 = arg8 + -arg3;
        arg10 = arg10 + 1;
        if (*(int *)((intptr_t)local_54 + 0x58) <= arg10) {
          arg10 = 0;
          uptr4 = uptr4 + arg7;
          arg11 = uptr4;
        }
        arg2 = arg2 + -1;
      } while (arg2 != 0);
    }
    h_00 = SelectObject(local_50,h);
    if (h_00 == (HGDIOBJ)0x0) {
      NoOp_Stub();
    }
    BitBlt(arg4,local_3c,local_38,cx,value5,hdcSrc,0,0,0xcc0020);
    SelectObject(hdcSrc,h_00);
    DeleteObject(h);
    DeleteDC(hdcSrc);
    if (arg9 == (HDC)0x0) {
      ReleaseDC(arg1,arg4);
    }
  }
  return;
}
