// CityDefinition_ParseIni: ported from Pizza Connection 2 at 0x4db430.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4db430
#include "pc2_port.h"

uint32_t * __cdecl
CityDefinition_ParseIni
          (uint32_t arg1,uint32_t arg2,uint8_t *arg3,uint32_t arg4,int arg5,
          uint32_t arg6,uint8_t *arg7,uint32_t arg8,int arg9,uint32_t arg10,
          uint8_t *arg11,uint32_t arg12,int arg13,uint32_t arg14,char *arg15,
          uint32_t arg16,int arg17,uint32_t arg18,char *arg19,uint32_t arg20,
          int arg21,uint32_t arg22,char *arg23,uint32_t arg24,int arg25,
          uint32_t arg26,char *arg27,uint32_t arg28,int arg29,uint32_t arg30,
          char *arg31,uint32_t arg32,int arg33,uint32_t arg34,char *arg35,
          uint32_t arg36,int arg37,uint32_t arg38,char *arg39,uint32_t arg40,
          int arg41,uint32_t arg42,char *arg43,uint32_t arg44,int arg45,
          uint32_t arg46,char *arg47,uint32_t arg48,int arg49,uint32_t arg50,
          char *arg51,uint32_t arg52,int arg53,uint32_t arg54,char *arg55,
          uint32_t arg56,int arg57,uint32_t arg58,uint8_t *arg59,
          uint32_t arg60,int arg61,uint32_t arg62,char *arg63,uint32_t arg64,
          int arg65,uint32_t arg66,uint8_t *arg67,uint32_t arg68,int arg69,
          uint32_t arg70,char *arg71,uint32_t arg72,int arg73,uint32_t arg74,
          char *arg75,uint32_t arg76,int arg77,uint32_t arg78,char *arg79,
          uint32_t arg80,int arg81,uint32_t arg82,char *arg83,uint32_t arg84,
          int arg85,uint32_t arg86,char *arg87,uint32_t arg88,int arg89,
          uint32_t arg90,char *arg91,uint32_t arg92,int arg93,uint32_t arg94,
          char *arg95,uint32_t arg96,int arg97,uint32_t arg98,char *arg99,
          uint32_t arg100,int arg101,uint32_t arg102,char *arg103,
          uint32_t arg104,int arg105,uint32_t arg106,char *arg107,
          uint32_t arg108,int arg109,uint32_t arg110,char *arg111,
          uint32_t arg112,int arg113,uint32_t arg114,char *arg115,
          uint32_t arg116,int arg117,uint32_t arg118,char *arg119,
          uint32_t arg120,int arg121,uint32_t arg122,char *arg123,
          uint32_t arg124,int arg125)

{
  char cVar1;
  uint8_t flag2;
  int *ptr3;
  uint8_t *bptr4;
  int value5;
  uint32_t *uptr6;
  int value7;
  uint32_t uvalue8;
  uint32_t uvalue9;
  float *fptr10;
  int *ptr11;
  uint8_t *bptr12;
  char *cptr13;
  uint32_t *uptr14;
  uint8_t **pptr15;
  char *cptr16;
  uint32_t *uptr17;
  bool flag18;
  uint8_t local_res0;
  uint8_t in_stack_0000035c;
  char in_stack_0000035d;
  int in_stack_000006fc;
  void *in_stack_000017b8;
  char *in_stack_000017bc;
  uint8_t abStack_7ffffffe [2];
  __chkstk(local_res0);
  arg5 = (intptr_t)register0x00000010 + 0x39c;
  arg9 = (intptr_t)register0x00000010 + 0x3dc;
  arg13 = (intptr_t)register0x00000010 + 0x3bc;
  arg17 = (intptr_t)register0x00000010 + 0x424;
  arg21 = (intptr_t)register0x00000010 + 0x428;
  arg25 = (intptr_t)register0x00000010 + 0x42c;
  arg29 = (intptr_t)register0x00000010 + 0x430;
  arg33 = (intptr_t)register0x00000010 + 0x434;
  arg37 = (intptr_t)register0x00000010 + 0x438;
  arg41 = (intptr_t)register0x00000010 + 0x43c;
  arg45 = (intptr_t)register0x00000010 + 0x3e0;
  arg49 = (intptr_t)register0x00000010 + 0x44c;
  arg53 = (intptr_t)register0x00000010 + 0x450;
  arg57 = (intptr_t)register0x00000010 + 0x454;
  arg3 = &DAT_0056d034;
  arg4 = 0;
  arg6 = 1;
  arg7 = s_SHORT_0056d02c;
  arg8 = 0;
  arg10 = 1;
  arg11 = &DAT_0056d024;
  arg12 = 0;
  arg14 = 1;
  arg15 = s_MIETEN_0056d01c;
  arg16 = 1;
  arg18 = 1;
  arg19 = s_GEDULT_0056d014;
  arg20 = 1;
  arg22 = 1;
  arg23 = s_KAUFPREIS_0056d008;
  arg24 = 1;
  arg26 = 1;
  arg27 = s_EINKOMMEN_0056cffc;
  arg28 = 1;
  arg30 = 1;
  arg31 = s_QUALITAET_0056cff0;
  arg32 = 1;
  arg34 = 1;
  arg35 = s_KOMFORT_0056cfe8;
  arg36 = 1;
  arg38 = 1;
  arg39 = s_KLIMA_0056cfe0;
  arg40 = 2;
  arg42 = 4;
  arg43 = s_BEVOELKERUNG_0056cfd0;
  arg44 = 2;
  arg46 = 1;
  arg47 = s_RATTE_0056cfc8;
  arg48 = 2;
  arg50 = 1;
  arg51 = s_KAKERLAKE_0056cfbc;
  arg52 = 2;
  arg54 = 1;
  arg55 = s_STINKBOMBE_0056cfb0;
  arg56 = 2;
  arg58 = 1;
  arg59 = &DAT_0056cfa8;
  arg60 = 2;
  arg61 = (intptr_t)register0x00000010 + 0x458;
  arg69 = (intptr_t)register0x00000010 + 0x3e4;
  arg73 = (intptr_t)register0x00000010 + 0x404;
  arg81 = (intptr_t)register0x00000010 + 0x6d8;
  arg89 = (intptr_t)register0x00000010 + 0x6e0;
  arg97 = (intptr_t)register0x00000010 + 0x6e8;
  arg101 = (intptr_t)register0x00000010 + 0x6f4;
  arg105 = (intptr_t)register0x00000010 + 0x6f8;
  arg77 = (intptr_t)register0x00000010 + 0x460;
  arg109 = (intptr_t)register0x00000010 + 0x7a0;
  arg85 = (intptr_t)register0x00000010 + 0x6dc;
  arg113 = (intptr_t)register0x00000010 + 0x7a4;
  arg65 = (intptr_t)register0x00000010 + 0x45c;
  arg93 = (intptr_t)register0x00000010 + 0x6e4;
  arg117 = (intptr_t)register0x00000010 + 0x7ac;
  arg121 = (intptr_t)register0x00000010 + 0x7b0;
  arg62 = 1;
  arg63 = s_GRAFFITI_0056cf9c;
  arg64 = 2;
  arg66 = 1;
  arg67 = &DAT_0056cf94;
  arg68 = 2;
  arg70 = 8;
  arg71 = s_BESUCHER_0056cf88;
  arg72 = 2;
  arg74 = 8;
  arg75 = s_GESCHMACK_0056cf7c;
  arg76 = 2;
  arg78 = 6;
  arg79 = s_BESONDERHEIT_0056cf6c;
  arg80 = 2;
  arg82 = 1;
  arg83 = s_SCHWIERIGKEITGRAD_0056cf58;
  arg84 = 2;
  arg86 = 1;
  arg87 = s_POLIZEIANZAHL_0056cf48;
  arg88 = 2;
  arg90 = 1;
  arg91 = s_SPIELZEIT_0056cf3c;
  arg92 = 2;
  arg94 = 1;
  arg95 = s_ZIELE_0056cf34;
  arg96 = 2;
  arg98 = 3;
  arg99 = s_STARTHQ_0056cf2c;
  arg100 = 2;
  arg102 = 1;
  arg103 = s_MAXHQ_0056cf24;
  arg104 = 2;
  arg106 = 1;
  arg107 = s_STARTGELD_0056cf18;
  arg108 = 2;
  arg110 = 1;
  arg111 = s_GEGNERANZAHL_0056cf08;
  arg112 = 2;
  arg114 = 1;
  arg115 = s_GEGNER_STARTHQ_0056cef8;
  arg116 = 2;
  arg118 = 1;
  arg119 = s_GEGNER_MAXHQ_0056cee8;
  arg120 = 2;
  arg122 = 1;
  arg123 = s_SCHLAGER_0056cedc;
  arg125 = (intptr_t)register0x00000010 + 0x478;
  arg124 = 2;
  ptr3 = Resource_Open(in_stack_000017b8,in_stack_000017bc,0);
  if (ptr3 == (int *)0x0) {
    return (uint32_t *)0x0;
  }
  uptr14 = (uint32_t *)((intptr_t)register0x00000010 + 0x39c);
  for (value7 = 0x306; value7 != 0; value7 = value7 + -1) {
    *uptr14 = 0;
    uptr14 = uptr14 + 1;
  }
  value7 = Resource_ReadLine(in_stack_000017b8,(uint8_t *)((intptr_t)register0x00000010 + 0xfb4),0x400,
                            (intptr_t)ptr3);
  do {
    if (value7 == -1) {
      Resource_Close(in_stack_000017b8,(intptr_t)ptr3);
      uptr6 = operator_new(0xc18);
      uptr14 = (uint32_t *)((intptr_t)register0x00000010 + 0x39c);
      uptr17 = uptr6;
      for (value7 = 0x306; value7 != 0; value7 = value7 + -1) {
        *uptr17 = *uptr14;
        uptr14 = uptr14 + 1;
        uptr17 = uptr17 + 1;
      }
      uptr6[0xd0] = (uptr6[0xd0] * 0xb) / 100;
      return uptr6;
    }
    Parse_ReadDelimitedToken
              ((intptr_t)register0x00000010 + 0xfb4,(int *)&local_res0,
               (uint32_t *)((intptr_t)register0x00000010 + 0x35c),0x40);
    if ((in_stack_0000035c != 0x5c) && (in_stack_0000035d != '/')) {
      value7 = -1;
      cptr13 = (char *)((intptr_t)register0x00000010 + 0x35c);
      do {
        if (value7 == 0) break;
        value7 = value7 + -1;
        cVar1 = *cptr13;
        cptr13 = cptr13 + 1;
      } while (cVar1 != '\0');
      if (value7 != -2) {
        CRT_Strupr((uint32_t *)((intptr_t)register0x00000010 + 0x35c));
        value7 = 0;
        bptr12 = &DAT_0056d034;
        pptr15 = &arg3;
        do {
          bptr4 = (uint8_t *)((intptr_t)register0x00000010 + 0x35c);
          do {
            flag2 = *bptr4;
            flag18 = flag2 < *bptr12;
            if (flag2 != *bptr12) {
LAB_004dbd1c:
              value5 = (1 - (uint32_t)flag18) - (uint32_t)(flag18 != 0);
              goto LAB_004dbd21;
            }
            if (flag2 == 0) break;
            flag2 = bptr4[1];
            flag18 = flag2 < bptr12[1];
            if (flag2 != bptr12[1]) goto LAB_004dbd1c;
            bptr4 = bptr4 + 2;
            bptr12 = bptr12 + 2;
          } while (flag2 != 0);
          value5 = 0;
LAB_004dbd21:
          if (value5 == 0) break;
          bptr12 = pptr15[4];
          pptr15 = pptr15 + 4;
          value7 = value7 + 1;
        } while (bptr12 != (uint8_t *)0x0);
        if ((&arg3)[value7 * 4] == (uint8_t *)0x0) {
          Debug_WarningMessageBox();
        }
        else {
          switch((&arg4)[value7 * 4]) {
          case 0:
            Parse_ReadDelimitedToken
                      ((intptr_t)register0x00000010 + 0xfb4,(int *)&local_res0,
                       (uint32_t *)((intptr_t)register0x00000010 + 0x13b4),0x400);
            uvalue8 = 0xffffffff;
            cptr13 = (char *)((intptr_t)register0x00000010 + 0x13b4);
            do {
              cptr16 = cptr13;
              if (uvalue8 == 0) break;
              uvalue8 = uvalue8 - 1;
              cptr16 = cptr13 + 1;
              cVar1 = *cptr13;
              cptr13 = cptr16;
            } while (cVar1 != '\0');
            uvalue8 = ~uvalue8;
            cptr13 = cptr16 + -uvalue8;
            cptr16 = (char *)(&arg5)[value7 * 4];
            for (uvalue9 = uvalue8 >> 2; uvalue9 != 0; uvalue9 = uvalue9 - 1) {
              *(uint32_t *)cptr16 = *(uint32_t *)cptr13;
              cptr13 = cptr13 + 4;
              cptr16 = cptr16 + 4;
            }
            for (uvalue8 = uvalue8 & 3; uvalue8 != 0; uvalue8 = uvalue8 - 1) {
              *cptr16 = *cptr13;
              cptr13 = cptr13 + 1;
              cptr16 = cptr16 + 1;
            }
            break;
          case 1:
            value5 = (&arg6)[value7 * 4];
            if (0 < value5) {
              fptr10 = (float *)(&arg5)[value7 * 4];
              do {
                value7 = Parse_ReadIntToken((intptr_t)register0x00000010 + 0xfb4,(int *)&local_res0);
                value5 = value5 + -1;
                *fptr10 = (float)(intptr_t)(value7) * 0.02;
                fptr10 = fptr10 + 1;
              } while (value5 != 0);
            }
            break;
          case 2:
            value5 = (&arg6)[value7 * 4];
            ptr11 = (int *)(&arg5)[value7 * 4];
            if (0 < value5) {
              do {
                value7 = Parse_ReadIntToken((intptr_t)register0x00000010 + 0xfb4,(int *)&local_res0);
                *ptr11 = value7;
                ptr11 = ptr11 + 1;
                value5 = value5 + -1;
              } while (value5 != 0);
            }
            break;
          case 3:
            value5 = in_stack_000006fc * 0x10;
            value7 = Parse_ReadIntToken((intptr_t)register0x00000010 + 0xfb4,(int *)&local_res0);
            *(int *)((intptr_t)register0x00000010 + value5 + 0x700) = value7;
            value7 = Parse_ReadIntToken((intptr_t)register0x00000010 + 0xfb4,(int *)&local_res0);
            *(int *)((intptr_t)register0x00000010 + value5 + 0x704) = value7;
            value7 = Parse_ReadIntToken((intptr_t)register0x00000010 + 0xfb4,(int *)&local_res0);
            *(int *)((intptr_t)register0x00000010 + value5 + 0x708) = value7;
            value7 = Parse_ReadIntToken((intptr_t)register0x00000010 + 0xfb4,(int *)&local_res0);
            *(uint32_t *)((intptr_t)register0x00000010 + value5 + 0x70c) = (uint32_t)(value7 == 1);
            in_stack_000006fc = in_stack_000006fc + 1;
          }
        }
      }
    }
    value7 = Resource_ReadLine(in_stack_000017b8,(uint8_t *)((intptr_t)register0x00000010 + 0xfb4),
                              0x400,(intptr_t)ptr3);
  } while( true );
}
