// CompanyProfileWindow_InitCategoryLayout: ported from Pizza Connection 2 at 0x4949a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4949a0
#include "pc2_port.h"

void __cdecl CompanyProfileWindow_InitCategoryLayout(void *arg1)

{
  int value1;
  
                    /* Shows the company-profile row groups for the active category. */
  value1 = 0x46a;
  if (DAT_0057c6d8 != 4) {
    do {
      UI_ShowChildByID(arg1,value1);
      value1 = value1 + 1;
    } while (value1 < 0x46e);
    value1 = 0x488;
    do {
      UI_ShowChildByID(arg1,value1);
      value1 = value1 + 1;
    } while (value1 < 0x48c);
    value1 = 0x5c9;
    do {
      UI_ShowChildByID(arg1,value1);
      value1 = value1 + 1;
    } while (value1 < 0x5cd);
    value1 = 0x1f48;
    do {
      UI_ShowChildByID(arg1,value1);
      value1 = value1 + 1;
    } while (value1 < 0x1f52);
    value1 = 0x1f53;
    do {
      UI_ShowChildByID(arg1,value1);
      value1 = value1 + 1;
    } while (value1 < 0x1f57);
    UI_ShowChildByID(arg1,0x465);
    UI_ShowChildByID(arg1,0x466);
    UI_ShowChildByID(arg1,0x468);
    UI_ShowChildByID(arg1,0x469);
    UI_ShowChildByID(arg1,0x48e);
    UI_ShowChildByID(arg1,0x5c0);
    UI_ShowChildByID(arg1,0x5c3);
    UI_ShowChildByID(arg1,0x5c5);
    UI_ShowChildByID(arg1,0x5c7);
    UI_ShowChildByID(arg1,0x1f43);
    value1 = 0x1f67;
    do {
      UI_RemoveObjectByKey(arg1,value1);
      value1 = value1 + 1;
    } while (value1 < 0x1f73);
    UI_RemoveObjectByKey(arg1,0x1f63);
    UI_RemoveObjectByKey(arg1,0x1f64);
    return;
  }
  do {
    UI_RemoveObjectByKey(arg1,value1);
    value1 = value1 + 1;
  } while (value1 < 0x46e);
  value1 = 0x488;
  do {
    UI_RemoveObjectByKey(arg1,value1);
    value1 = value1 + 1;
  } while (value1 < 0x48c);
  value1 = 0x5c9;
  do {
    UI_RemoveObjectByKey(arg1,value1);
    value1 = value1 + 1;
  } while (value1 < 0x5cd);
  value1 = 0x1f48;
  do {
    UI_RemoveObjectByKey(arg1,value1);
    value1 = value1 + 1;
  } while (value1 < 0x1f52);
  value1 = 0x1f53;
  do {
    UI_RemoveObjectByKey(arg1,value1);
    value1 = value1 + 1;
  } while (value1 < 0x1f57);
  UI_RemoveObjectByKey(arg1,0x465);
  UI_RemoveObjectByKey(arg1,0x466);
  UI_RemoveObjectByKey(arg1,0x468);
  UI_RemoveObjectByKey(arg1,0x469);
  UI_RemoveObjectByKey(arg1,0x48e);
  UI_RemoveObjectByKey(arg1,0x5c0);
  UI_RemoveObjectByKey(arg1,0x5c3);
  UI_RemoveObjectByKey(arg1,0x5c5);
  UI_RemoveObjectByKey(arg1,0x5c7);
  UI_RemoveObjectByKey(arg1,0x1f43);
  value1 = 0x1f53;
  do {
    UI_RemoveObjectByKey(arg1,value1);
    value1 = value1 + 1;
  } while (value1 < 0x1f57);
  value1 = 0x1f5b;
  do {
    UI_RemoveObjectByKey(arg1,value1);
    value1 = value1 + 1;
  } while (value1 < 0x1f63);
  value1 = 0x1f67;
  do {
    UI_ShowChildByID(arg1,value1);
    value1 = value1 + 1;
  } while (value1 < 0x1f73);
  UI_ShowChildByID(arg1,0x1f63);
  UI_ShowChildByID(arg1,0x1f64);
  return;
}
