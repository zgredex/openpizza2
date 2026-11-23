// Game_UpdateMusicTheme: ported from Pizza Connection 2 at 0x4fccb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fccb0
#include "pc2_port.h"

void Game_UpdateMusicTheme(int arg1,int arg2)

{
  int value1;
  int value2;
  int *ptr3;
  int *ptr4;
  int value5;
  short *psVar6;
  int value7;
  int *ptr8;
  int value9;
  short *psVar10;
  int *ptr11;
  int local_44 [8];
  int local_24 [9];
  
  if (arg1 != 0) {
    value1 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(arg1 + 0x34),(int *)0x0);
    ptr3 = local_44;
    for (value5 = 8; value5 != 0; value5 = value5 + -1) {
      *ptr3 = 0;
      ptr3 = ptr3 + 1;
    }
    if (arg2 == 0) {
      value5 = *(int *)(arg1 + 0x34);
      value9 = 0;
      value7 = *(int *)(DAT_0057c670 + 0x50);
      if (0 < value7) {
        do {
          value2 = IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),value9,(int *)0x0);
          if ((((value2 != 0) && (*(int *)(value2 + 0x28) == value5)) &&
              (value2 = *(int *)(value2 + 0x34), -1 < value2)) && (value2 < 8)) {
            local_44[value2] = local_44[value2] + 1;
          }
          value9 = value9 + 1;
        } while (value9 < value7);
      }
    }
    else {
      psVar10 = (short *)(arg2 + 6);
      value5 = 8;
      do {
        ptr3 = local_44;
        value7 = 8;
        psVar6 = psVar10;
        do {
          *ptr3 = *ptr3 + (intptr_t)*psVar6;
          psVar6 = psVar6 + 1;
          ptr3 = ptr3 + 1;
          value7 = value7 + -1;
        } while (value7 != 0);
        psVar10 = psVar10 + 0x1a;
        value5 = value5 + -1;
      } while (value5 != 0);
    }
    value5 = 0;
    value9 = 8;
    ptr3 = local_24;
    for (value7 = 9; value7 != 0; value7 = value7 + -1) {
      *ptr3 = 0;
      ptr3 = ptr3 + 1;
    }
    ptr3 = local_44;
    do {
      value7 = *ptr3;
      ptr3 = ptr3 + 1;
      value5 = value5 + value7;
      value9 = value9 + -1;
    } while (value9 != 0);
    if (value5 == 0) {
      value5 = 8;
    }
    else {
      ptr11 = local_44;
      arg2 = 8;
      ptr3 = (int *)(value1 + 0xe0);
      do {
        value1 = *ptr11;
        ptr4 = local_24;
        value5 = 9;
        ptr8 = ptr3;
        do {
          value7 = *ptr8;
          ptr8 = ptr8 + 8;
          *ptr4 = *ptr4 + value7 * value1;
          ptr4 = ptr4 + 1;
          value5 = value5 + -1;
        } while (value5 != 0);
        ptr11 = ptr11 + 1;
        ptr3 = ptr3 + 1;
        arg2 = arg2 + -1;
      } while (arg2 != 0);
      value7 = 0;
      ptr3 = local_24;
      value1 = arg1;
      value5 = arg1;
      do {
        if ((value7 == 0) || (value1 < *ptr3)) {
          value1 = *ptr3;
          value5 = value7;
        }
        value7 = value7 + 1;
        ptr3 = ptr3 + 1;
      } while (value7 < 9);
    }
    if (*(int *)(arg1 + 0x14d8) != value5) {
      *(int *)(arg1 + 0x14d8) = value5;
      Sound_SelectCurrentTrack(DAT_0057ba0c);
    }
  }
  return;
}
