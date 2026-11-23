// Game_BuildPlayerRankingData: ported from Pizza Connection 2 at 0x48d530.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48d530
#include "pc2_port.h"

void __thiscall Game_BuildPlayerRankingData(void *self,int *arg1)

{
  int value1;
  uint32_t *uptr2;
  int value3;
  int value4;
  int value5;
  int value6;
  int value7;
  int value8;
  int value9;
  int value10;
  int value11;
  int *ptr12;
  
  value11 = 0;
  do {
    value1 = Game_GetPlayerBySlot(self,value11);
    if (value1 != 0) {
      uptr2 = operator_new(0x1a0);
      arg1[value11] = (intptr_t)uptr2;
      for (value3 = 0x68; value3 != 0; value3 = value3 + -1) {
        *uptr2 = 0;
        uptr2 = uptr2 + 1;
      }
      value3 = 0;
      if (0 < *(int *)(value1 + 0x1b0)) {
        do {
          uptr2 = (uint32_t *)IDMap_Lookup((void *)(value1 + 0x19c),value3,(int *)0x0);
          if ((intptr_t)((uint32_t *)arg1[value11])[0x48] < (intptr_t)uptr2[0x48]) {
            *(uint32_t *)arg1[value11] = *uptr2;
            *(uint32_t *)(arg1[value11] + 4) = uptr2[1];
            *(uint32_t *)(arg1[value11] + 0x120) = uptr2[0x48];
          }
          if (*(int *)(arg1[value11] + 0x124) < (intptr_t)uptr2[0x49]) {
            *(uint32_t *)(arg1[value11] + 8) = uptr2[2];
            *(uint32_t *)(arg1[value11] + 0xc) = uptr2[3];
            *(uint32_t *)(arg1[value11] + 0x124) = uptr2[0x49];
          }
          if (*(int *)(arg1[value11] + 0x128) < (intptr_t)uptr2[0x4a]) {
            *(uint32_t *)(arg1[value11] + 0x10) = uptr2[4];
            *(uint32_t *)(arg1[value11] + 0x14) = uptr2[5];
            *(uint32_t *)(arg1[value11] + 0x128) = uptr2[0x4a];
          }
          if (*(int *)(arg1[value11] + 300) < (intptr_t)uptr2[0x4b]) {
            *(uint32_t *)(arg1[value11] + 0x18) = uptr2[6];
            *(uint32_t *)(arg1[value11] + 0x1c) = uptr2[7];
            *(uint32_t *)(arg1[value11] + 300) = uptr2[0x4b];
          }
          if (*(int *)(arg1[value11] + 0x130) < (intptr_t)uptr2[0x4c]) {
            *(uint32_t *)(arg1[value11] + 0x20) = uptr2[8];
            *(uint32_t *)(arg1[value11] + 0x24) = uptr2[9];
            *(uint32_t *)(arg1[value11] + 0x130) = uptr2[0x4c];
          }
          if (*(int *)(arg1[value11] + 0x134) < (intptr_t)uptr2[0x4d]) {
            *(uint32_t *)(arg1[value11] + 0x28) = uptr2[10];
            *(uint32_t *)(arg1[value11] + 0x2c) = uptr2[0xb];
            *(uint32_t *)(arg1[value11] + 0x134) = uptr2[0x4d];
          }
          if (*(int *)(arg1[value11] + 0x138) < (intptr_t)uptr2[0x4e]) {
            *(uint32_t *)(arg1[value11] + 0x30) = uptr2[0xc];
            *(uint32_t *)(arg1[value11] + 0x34) = uptr2[0xd];
            *(uint32_t *)(arg1[value11] + 0x138) = uptr2[0x4e];
          }
          if (*(int *)(arg1[value11] + 0x13c) < (intptr_t)uptr2[0x4f]) {
            *(uint32_t *)(arg1[value11] + 0x38) = uptr2[0xe];
            *(uint32_t *)(arg1[value11] + 0x3c) = uptr2[0xf];
            *(uint32_t *)(arg1[value11] + 0x13c) = uptr2[0x4f];
          }
          if (*(int *)(arg1[value11] + 0x150) < (intptr_t)uptr2[0x54]) {
            *(uint32_t *)(arg1[value11] + 0xdc) = uptr2[0x37];
            *(uint32_t *)(arg1[value11] + 0xe0) = uptr2[0x38];
            *(uint32_t *)(arg1[value11] + 0x150) = uptr2[0x54];
          }
          if (*(int *)(arg1[value11] + 0x154) < (intptr_t)uptr2[0x55]) {
            *(uint32_t *)(arg1[value11] + 0xe4) = uptr2[0x39];
            *(uint32_t *)(arg1[value11] + 0xe8) = uptr2[0x3a];
            *(uint32_t *)(arg1[value11] + 0x154) = uptr2[0x55];
          }
          if (*(int *)(arg1[value11] + 0x158) < (intptr_t)uptr2[0x56]) {
            *(uint32_t *)(arg1[value11] + 0xec) = uptr2[0x3b];
            *(uint32_t *)(arg1[value11] + 0xf0) = uptr2[0x3c];
            *(uint32_t *)(arg1[value11] + 0x158) = uptr2[0x56];
          }
          if (*(int *)(arg1[value11] + 0x15c) < (intptr_t)uptr2[0x57]) {
            *(uint32_t *)(arg1[value11] + 0xf4) = uptr2[0x3d];
            *(uint32_t *)(arg1[value11] + 0xf8) = uptr2[0x3e];
            *(uint32_t *)(arg1[value11] + 0x15c) = uptr2[0x57];
          }
          if (*(int *)(arg1[value11] + 0x40) < (intptr_t)uptr2[0x10]) {
            *(uint32_t *)(arg1[value11] + 0x40) = uptr2[0x10];
          }
          if (*(int *)(arg1[value11] + 0x44) < (intptr_t)uptr2[0x11]) {
            *(uint32_t *)(arg1[value11] + 0x44) = uptr2[0x11];
          }
          if (*(int *)(arg1[value11] + 0x48) < (intptr_t)uptr2[0x12]) {
            *(uint32_t *)(arg1[value11] + 0x48) = uptr2[0x12];
          }
          if (*(int *)(arg1[value11] + 0x4c) < (intptr_t)uptr2[0x13]) {
            *(uint32_t *)(arg1[value11] + 0x4c) = uptr2[0x13];
          }
          if (*(int *)(arg1[value11] + 0x58) < (intptr_t)uptr2[0x16]) {
            *(uint32_t *)(arg1[value11] + 0x58) = uptr2[0x16];
          }
          if (*(int *)(arg1[value11] + 0x5c) < (intptr_t)uptr2[0x17]) {
            *(uint32_t *)(arg1[value11] + 0x5c) = uptr2[0x17];
          }
          if (*(int *)(arg1[value11] + 0x50) < (intptr_t)uptr2[0x14]) {
            *(uint32_t *)(arg1[value11] + 0x50) = uptr2[0x14];
          }
          if (*(int *)(arg1[value11] + 0x54) < (intptr_t)uptr2[0x15]) {
            *(uint32_t *)(arg1[value11] + 0x54) = uptr2[0x15];
          }
          if (*(int *)(arg1[value11] + 0x60) < (intptr_t)uptr2[0x18]) {
            *(uint32_t *)(arg1[value11] + 0x60) = uptr2[0x18];
          }
          if (*(int *)(arg1[value11] + 100) < (intptr_t)uptr2[0x19]) {
            *(uint32_t *)(arg1[value11] + 100) = uptr2[0x19];
          }
          if (*(int *)(arg1[value11] + 0x68) < (intptr_t)uptr2[0x1a]) {
            *(uint32_t *)(arg1[value11] + 0x68) = uptr2[0x1a];
          }
          if (*(int *)(arg1[value11] + 0x6c) < (intptr_t)uptr2[0x1b]) {
            *(uint32_t *)(arg1[value11] + 0x6c) = uptr2[0x1b];
          }
          if (*(int *)(arg1[value11] + 0x70) < (intptr_t)uptr2[0x1c]) {
            *(uint32_t *)(arg1[value11] + 0x70) = uptr2[0x1c];
          }
          if (*(int *)(arg1[value11] + 0x74) < (intptr_t)uptr2[0x1d]) {
            *(uint32_t *)(arg1[value11] + 0x74) = uptr2[0x1d];
          }
          if (*(int *)(arg1[value11] + 0x19c) < (intptr_t)uptr2[0x67]) {
            *(uint32_t *)(arg1[value11] + 0x19c) = uptr2[0x67];
            *(uint32_t *)(arg1[value11] + 0x78) = uptr2[0x1e];
          }
          if (*(int *)(arg1[value11] + 0x7c) < (intptr_t)uptr2[0x1f]) {
            *(uint32_t *)(arg1[value11] + 0x7c) = uptr2[0x1f];
          }
          if (*(int *)(arg1[value11] + 0x80) < (intptr_t)uptr2[0x20]) {
            *(uint32_t *)(arg1[value11] + 0x80) = uptr2[0x20];
          }
          if (*(int *)(arg1[value11] + 0x84) < (intptr_t)uptr2[0x21]) {
            *(uint32_t *)(arg1[value11] + 0x84) = uptr2[0x21];
          }
          if (*(int *)(arg1[value11] + 0x88) < (intptr_t)uptr2[0x22]) {
            *(uint32_t *)(arg1[value11] + 0x88) = uptr2[0x22];
          }
          if (*(int *)(arg1[value11] + 0x8c) < (intptr_t)uptr2[0x23]) {
            *(uint32_t *)(arg1[value11] + 0x8c) = uptr2[0x23];
          }
          if (*(int *)(arg1[value11] + 0x90) < (intptr_t)uptr2[0x24]) {
            *(uint32_t *)(arg1[value11] + 0x90) = uptr2[0x24];
          }
          if (*(int *)(arg1[value11] + 0x94) < (intptr_t)uptr2[0x25]) {
            *(uint32_t *)(arg1[value11] + 0x94) = uptr2[0x25];
          }
          if (*(int *)(arg1[value11] + 0x98) < (intptr_t)uptr2[0x26]) {
            *(uint32_t *)(arg1[value11] + 0x98) = uptr2[0x26];
          }
          if (*(int *)(arg1[value11] + 0x9c) < (intptr_t)uptr2[0x27]) {
            *(uint32_t *)(arg1[value11] + 0x9c) = uptr2[0x27];
          }
          if (*(int *)(arg1[value11] + 0xa0) < (intptr_t)uptr2[0x28]) {
            *(uint32_t *)(arg1[value11] + 0xa0) = uptr2[0x28];
          }
          if (*(int *)(arg1[value11] + 0x174) < (intptr_t)uptr2[0x5d]) {
            *(uint32_t *)(arg1[value11] + 0x174) = uptr2[0x5d];
            *(uint32_t *)(arg1[value11] + 0xa4) = uptr2[0x29];
            *(uint32_t *)(arg1[value11] + 0xa8) = uptr2[0x2a];
          }
          if (*(int *)(arg1[value11] + 0x178) < (intptr_t)uptr2[0x5e]) {
            *(uint32_t *)(arg1[value11] + 0x178) = uptr2[0x5e];
            *(uint32_t *)(arg1[value11] + 0xac) = uptr2[0x2b];
            *(uint32_t *)(arg1[value11] + 0xb0) = uptr2[0x2c];
          }
          if (*(int *)(arg1[value11] + 0x17c) < (intptr_t)uptr2[0x5f]) {
            *(uint32_t *)(arg1[value11] + 0x17c) = uptr2[0x5f];
            *(uint32_t *)(arg1[value11] + 0xb4) = uptr2[0x2d];
            *(uint32_t *)(arg1[value11] + 0xb8) = uptr2[0x2e];
          }
          if (*(int *)(arg1[value11] + 0xbc) < (intptr_t)uptr2[0x2f]) {
            *(uint32_t *)(arg1[value11] + 0xbc) = uptr2[0x2f];
          }
          if (*(int *)(arg1[value11] + 0xc0) < (intptr_t)uptr2[0x30]) {
            *(uint32_t *)(arg1[value11] + 0xc0) = uptr2[0x30];
          }
          if (*(int *)(arg1[value11] + 0xc4) < (intptr_t)uptr2[0x31]) {
            *(uint32_t *)(arg1[value11] + 0xc4) = uptr2[0x31];
          }
          if (*(int *)(arg1[value11] + 200) < (intptr_t)uptr2[0x32]) {
            *(uint32_t *)(arg1[value11] + 200) = uptr2[0x32];
          }
          if (*(int *)(arg1[value11] + 0xcc) < (intptr_t)uptr2[0x33]) {
            *(uint32_t *)(arg1[value11] + 0xcc) = uptr2[0x33];
          }
          if (*(int *)(arg1[value11] + 0xd0) < (intptr_t)uptr2[0x34]) {
            *(uint32_t *)(arg1[value11] + 0xd0) = uptr2[0x34];
          }
          if (*(int *)(arg1[value11] + 0xd4) < (intptr_t)uptr2[0x35]) {
            *(uint32_t *)(arg1[value11] + 0xd4) = uptr2[0x35];
          }
          if (*(int *)(arg1[value11] + 0xd8) < (intptr_t)uptr2[0x36]) {
            *(uint32_t *)(arg1[value11] + 0xd8) = uptr2[0x36];
          }
          value3 = value3 + 1;
        } while (value3 < *(int *)(value1 + 0x1b0));
      }
    }
    value11 = value11 + 1;
  } while (value11 < 6);
  value11 = 0;
  ptr12 = arg1;
  do {
    value1 = Game_GetPlayerBySlot(self,value11);
    if (value1 != 0) {
      value1 = *ptr12;
      value3 = Game_IsPlayerBestInStat(self,arg1,0x11,value11);
      *(int *)(value1 + 0x140) = *(int *)(value1 + 0x40) + value3 * 5000;
      value1 = *ptr12;
      value3 = Game_IsPlayerBestInStat(self,arg1,0x13,value11);
      *(int *)(value1 + 0x144) = *(int *)(value1 + 0x48) + value3 * 5000;
      value1 = *ptr12;
      value3 = Game_IsPlayerBestInStat(self,arg1,0x15,value11);
      *(int *)(value1 + 0x148) = *(int *)(value1 + 0x50) + value3 * 5000;
      value1 = *ptr12;
      value3 = Game_IsPlayerBestInStat(self,arg1,0x17,value11);
      *(int *)(value1 + 0x14c) = *(int *)(value1 + 0x58) + value3 * 5000;
      value1 = *ptr12;
      value3 = Game_IsPlayerBestInStat(self,arg1,0x19,value11);
      *(int *)(value1 + 400) = *(int *)(value1 + 0x60) / 100 + value3 * 5000;
      value1 = *ptr12;
      value3 = Game_IsPlayerBestInStat(self,arg1,0x1b,value11);
      *(int *)(value1 + 0x194) = *(int *)(value1 + 0x68) / 10 + value3 * 5000;
      value1 = *ptr12;
      value3 = Game_IsPlayerBestInStat(self,arg1,0x1d,value11);
      *(int *)(value1 + 0x198) = (*(int *)(value1 + 0x70) + value3 * 10) * 500;
      value1 = *ptr12;
      value3 = Game_IsPlayerBestInStat(self,arg1,0x20,value11);
      *(int *)(value1 + 0x160) = (*(int *)(value1 + 0x7c) << 1) / 5 + value3 * 5000;
      value1 = *ptr12;
      value3 = Game_IsPlayerBestInStat(self,arg1,0x22,value11);
      *(int *)(value1 + 0x164) = (*(int *)(value1 + 0x84) + value3 * 500) * 10;
      value1 = *ptr12;
      value3 = Game_IsPlayerBestInStat(self,arg1,0x24,value11);
      *(int *)(value1 + 0x168) = (*(int *)(value1 + 0x8c) + value3 * 500) * 10;
      value1 = *ptr12;
      value3 = Game_IsPlayerBestInStat(self,arg1,0x26,value11);
      *(int *)(value1 + 0x16c) = (*(int *)(value1 + 0x94) + value3 * 0x32) * 100;
      value1 = *ptr12;
      value3 = Game_IsPlayerBestInStat(self,arg1,0x30,value11);
      *(int *)(value1 + 0x180) = (*(int *)(value1 + 0xbc) + value3 * 0x32) * 100;
      value1 = *ptr12;
      value3 = Game_IsPlayerBestInStat(self,arg1,0x32,value11);
      *(int *)(value1 + 0x184) = (*(int *)(value1 + 0xc4) + value3 * 0x32) * 100;
      value1 = *ptr12;
      value3 = Game_IsPlayerBestInStat(self,arg1,0x34,value11);
      *(int *)(value1 + 0x188) = (*(int *)(value1 + 0xcc) + value3 * 0x32) * 100;
      *(int *)(*ptr12 + 0x18c) = *(int *)(*ptr12 + 0xd4) * 10000;
      value1 = *ptr12;
      value3 = Game_IsPlayerBestInStat(self,arg1,0x28,value11);
      *(int *)(value1 + 0x170) = value3 * *(int *)(value1 + 0x9c) * 500;
    }
    value11 = value11 + 1;
    ptr12 = ptr12 + 1;
  } while (value11 < 6);
  value11 = 0;
  do {
    value1 = Game_GetPlayerBySlot(self,value11);
    if (value1 != 0) {
      value1 = *arg1;
      value3 = *(int *)(value1 + 300) + *(int *)(value1 + 0x128) + *(int *)(value1 + 0x124) +
              *(int *)(value1 + 0x120);
      *(int *)(value1 + 0xfc) = value3;
      value1 = *arg1;
      value4 = *(int *)(value1 + 0x14c) + *(int *)(value1 + 0x148) + *(int *)(value1 + 0x144) +
              *(int *)(value1 + 0x140);
      *(int *)(value1 + 0x100) = value4;
      value1 = *arg1;
      value5 = *(int *)(value1 + 0x17c) + *(int *)(value1 + 0x178) + *(int *)(value1 + 0x174) +
              *(int *)(value1 + 0x170);
      *(int *)(value1 + 0x104) = value5;
      value1 = *arg1;
      value6 = *(int *)(value1 + 0x19c) + *(int *)(value1 + 0x198) + *(int *)(value1 + 0x194) +
              *(int *)(value1 + 400);
      *(int *)(value1 + 0x108) = value6;
      value1 = *arg1;
      value7 = *(int *)(value1 + 0x16c) + *(int *)(value1 + 0x168) + *(int *)(value1 + 0x164) +
              *(int *)(value1 + 0x160);
      *(int *)(value1 + 0x10c) = value7;
      value1 = *arg1;
      value8 = *(int *)(value1 + 0x15c) + *(int *)(value1 + 0x158) + *(int *)(value1 + 0x154) +
              *(int *)(value1 + 0x150);
      *(int *)(value1 + 0x110) = value8;
      value1 = *arg1;
      value9 = *(int *)(value1 + 0x13c) + *(int *)(value1 + 0x138) + *(int *)(value1 + 0x134) +
              *(int *)(value1 + 0x130);
      *(int *)(value1 + 0x114) = value9;
      value1 = *arg1;
      value10 = *(int *)(value1 + 0x18c) + *(int *)(value1 + 0x188) + *(int *)(value1 + 0x184) +
               *(int *)(value1 + 0x180);
      *(int *)(value1 + 0x118) = value10;
      *(int *)(*arg1 + 0x11c) = value10 + value3 + value4 + value5 + value6 + value7 + value8 + value9;
    }
    value11 = value11 + 1;
    arg1 = arg1 + 1;
  } while (value11 < 6);
  return;
}
