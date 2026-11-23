// Language_LoadLDF: ported from Pizza Connection 2 at 0x5145a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5145a0
#include "pc2_port.h"

void Language_LoadLDF(void)

{
  int value1;
  int *ptr2;
  uint32_t uvalue3;
  int value4;
  int *ptr5;
  
  ptr2 = Resource_Open(DAT_0057c5d8,s_language_ldf_00573b2c,1);
  uvalue3 = Resource_GetSize((intptr_t)ptr2);
  DAT_00580ad8 = operator_new(uvalue3);
  Resource_Read(DAT_0057c5d8,(char *)DAT_00580ad8,uvalue3,(intptr_t)ptr2);
  Resource_Close(DAT_0057c5d8,(intptr_t)ptr2);
  DAT_00580ad0 = *DAT_00580ad8;
  DAT_00580ad4 = operator_new(DAT_00580ad0 * 4);
  ptr2 = DAT_00580ad8 + 1;
  value4 = 0;
  if (0 < DAT_00580ad0) {
    do {
      uvalue3 = 0xffffffff;
      *(int **)((intptr_t)DAT_00580ad4 + value4 * 4) = ptr2;
      ptr5 = ptr2;
      do {
        if (uvalue3 == 0) break;
        uvalue3 = uvalue3 - 1;
        value1 = *ptr5;
        ptr5 = (int *)((intptr_t)ptr5 + 1);
      } while ((char)value1 != '\0');
      value4 = value4 + 1;
      ptr2 = (int *)((intptr_t)ptr2 + ~uvalue3);
    } while (value4 < DAT_00580ad0);
  }
  Language_MapStrings();
  UI_LoadStringTable();
  CRT_Onexit(0x514580);
  return;
}
