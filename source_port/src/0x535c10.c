// Font_WrapText: ported from Pizza Connection 2 at 0x535c10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x535c10
#include "pc2_port.h"

void __thiscall Font_WrapText(void *self,char *arg1,int arg2)

{
  char *cptr1;
  char cVar2;
  uint8_t uvalue3;
  uint8_t uvalue4;
  char *in_EAX;
  uint32_t extraout_var;
  uint32_t extraout_var_00;
  uint32_t uvalue5;
  int value6;
  int value7;
  int value8;
  int local_4;
  
  if (*arg1 != '\0') {
    in_EAX = arg1;
    do {
      if (*in_EAX == '\n') {
        *in_EAX = ' ';
      }
      cptr1 = in_EAX + 1;
      in_EAX = in_EAX + 1;
    } while (*cptr1 != '\0');
  }
  cVar2 = *arg1;
  uvalue5 = CONCAT31((int3)((uint32_t)in_EAX >> 8),cVar2);
  value6 = 0;
  value7 = 0;
  value8 = -1;
  while (cVar2 != '\0') {
    cVar2 = arg1[value6];
    uvalue5 = CONCAT31((int3)(uvalue5 >> 8),cVar2);
    if (cVar2 == ' ') {
      value8 = value6;
      local_4 = value7;
    }
    if (cVar2 == '\r') {
      value7 = 0;
      value8 = -1;
    }
    else {
      uvalue3 = Font_GetCharWidth(self,uvalue5);
      uvalue5 = value7 + CONCAT31(extraout_var,uvalue3);
      if ((arg2 < (intptr_t)uvalue5) && (value8 != -1)) {
        arg1[value8] = '\n';
        uvalue4 = Font_GetCharWidth(self,0x20);
        uvalue5 = CONCAT31(extraout_var_00,uvalue4) + local_4;
        value7 = value7 - uvalue5;
        value8 = -1;
      }
      value7 = value7 + CONCAT31(extraout_var,uvalue3);
    }
    value6 = value6 + 1;
    cVar2 = arg1[value6];
  }
  return;
}
