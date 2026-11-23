// MapList_AddIniRecord: ported from Pizza Connection 2 at 0x4cd8e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4cd8e0
#include "pc2_port.h"

void __cdecl
MapList_AddIniRecord
          (void *arg1,uint32_t arg2,uint32_t arg3,uint8_t *arg4,uint32_t arg5
          ,int arg6,uint32_t arg7,char *arg8,uint32_t arg9,int arg10,
          uint32_t arg11,char *arg12,uint32_t arg13,int arg14,uint32_t arg15,
          char *arg16,uint32_t arg17,int arg18,uint32_t arg19,char *arg20,
          uint32_t arg21,int arg22,uint32_t arg23,char *arg24,uint32_t arg25,
          int arg26,uint32_t arg27,char *arg28,uint32_t arg29,int arg30,
          uint32_t arg31,char *arg32,uint32_t arg33,int arg34,uint32_t arg35,
          char *arg36,uint32_t arg37,int arg38,uint32_t arg39,char *arg40,
          uint32_t arg41,int arg42,uint32_t arg43,char *arg44,uint32_t arg45,
          int arg46,uint32_t arg47,char *arg48,uint32_t arg49,int arg50,
          uint32_t arg51,uint8_t *arg52,uint32_t arg53,int arg54,
          uint32_t arg55,char *arg56,uint32_t arg57,int arg58,uint32_t arg59,
          uint8_t *arg60,uint32_t arg61,int arg62,uint32_t arg63,char *arg64,
          uint32_t arg65,int arg66,uint32_t arg67,char *arg68,uint32_t arg69,
          int arg70,uint32_t arg71,char *arg72,uint32_t arg73,int arg74,
          uint32_t arg75,char *arg76,uint32_t arg77,int arg78,uint32_t arg79,
          char *arg80,uint32_t arg81,int arg82,uint32_t arg83,char *arg84,
          uint32_t arg85,int arg86,uint32_t arg87,char *arg88,uint32_t arg89,
          int arg90,uint32_t arg91,char *arg92,uint32_t arg93,int arg94,
          uint32_t arg95,char *arg96,uint32_t arg97,int arg98,uint32_t arg99,
          char *arg100,uint32_t arg101,int arg102,uint32_t arg103,char *arg104,
          uint32_t arg105,int arg106,uint32_t arg107,char *arg108,
          uint32_t arg109,int arg110,uint32_t arg111,char *arg112,
          uint32_t arg113,int arg114,uint32_t arg115,char *arg116,
          uint32_t arg117,int arg118)

{
  int value1;
  uint32_t *uptr2;
  int value3;
  uint32_t uvalue4;
  void *self;
  uint32_t unaff_EBX;
  int unaff_EBP;
  uint32_t unaff_ESI;
  int value5;
  uint8_t *unaff_EDI;
  uint8_t *unaff_retaddr;
  
  uptr2 = CityDefinition_ParseIni
                     (DAT_0057c5d8,arg2,unaff_EDI,unaff_ESI,unaff_EBP,unaff_EBX,unaff_retaddr,
                      arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,
                      arg10,arg11,arg12,arg13,arg14,arg15,arg16,arg17,
                      arg18,arg19,arg20,arg21,arg22,arg23,arg24,arg25,
                      arg26,arg27,arg28,arg29,arg30,arg31,arg32,arg33,
                      arg34,arg35,arg36,arg37,arg38,arg39,arg40,arg41,
                      arg42,arg43,arg44,arg45,arg46,arg47,arg48,arg49,
                      arg50,arg51,arg52,arg53,arg54,arg55,arg56,arg57,
                      arg58,arg59,arg60,arg61,arg62,arg63,arg64,arg65,
                      arg66,arg67,arg68,arg69,arg70,arg71,arg72,arg73,
                      arg74,arg75,arg76,arg77,arg78,arg79,arg80,arg81,
                      arg82,arg83,arg84,arg85,arg86,arg87,arg88,arg89,
                      arg90,arg91,arg92,arg93,arg94,arg95,arg96,arg97,
                      arg98,arg99,arg100,arg101,arg102,arg103,arg104,arg105,
                      arg106,arg107,arg108,arg109,arg110,arg111,arg112,
                      arg113,arg114,arg115,arg116,arg117,arg118);
  if (uptr2 != (uint32_t *)0x0) {
    value5 = 0;
    value1 = *(int *)((intptr_t)arg1 + 0x14);
    if (0 < value1) {
      do {
        value3 = IDMap_Lookup(arg1,value5,(int *)0x0);
        uvalue4 = FUN_005570c0(self,(uint8_t *)(value3 + 0x40),(uint8_t *)(uptr2 + 0x10));
        if (uvalue4 == 0) {
          Mem_Free(uptr2);
          return;
        }
        value5 = value5 + 1;
      } while (value5 < value1);
    }
    List_Add(arg1,uptr2);
  }
  return;
}
