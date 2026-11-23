// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x5524cd.c:28:37: error: use of undeclared identifier 'LPTIME_ZONE_INFORMATION'
// CRT_Tzset: ported from Pizza Connection 2 at 0x5524cd.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5524cd
#include "pc2_port.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CRT_Tzset(void)

{
  char cVar1;
  char cVar2;
  uint32_t *_Str1;
  DWORD DVar3;
  int value4;
  size_t svalue5;
  void *self;
  uint32_t *_Source;
  int local_8;
  
  CRT_Lock(0xc);
  DAT_00576ad8 = 0xffffffff;
  DAT_00576ac8 = 0xffffffff;
  DAT_00585670 = 0;
  _Str1 = (uint32_t *)FUN_00555d5c("TZ");
  if (_Str1 == (uint32_t *)0x0) {
    CS_LeaveIndexed(0xc);
    DVar3 = GetTimeZoneInformation((LPTIME_ZONE_INFORMATION)&DAT_00585678);
    if (DVar3 == 0xffffffff) {
      return;
    }
    DAT_00576a30 = (void *)(DAT_00585678 * 0x3c);
    DAT_00585670 = 1;
    if (DAT_005856be != 0) {
      DAT_00576a30 = (void *)((intptr_t)DAT_00576a30 + DAT_005856cc * 0x3c);
    }
    if ((DAT_00585712 == 0) || (DAT_00585720 == 0)) {
      DAT_00576a34 = 0;
      _DAT_00576a38 = 0;
    }
    else {
      DAT_00576a34 = 1;
      _DAT_00576a38 = (DAT_00585720 - DAT_005856cc) * 0x3c;
    }
    value4 = WideCharToMultiByte(DAT_005857dc,0x220,(LPCWSTR)&DAT_0058567c,-1,PTR_DAT_00576abc,0x3f,
                                (LPCSTR)0x0,&local_8);
    if ((value4 == 0) || (local_8 != 0)) {
      *PTR_DAT_00576abc = 0;
    }
    else {
      PTR_DAT_00576abc[0x3f] = 0;
    }
    value4 = WideCharToMultiByte(DAT_005857dc,0x220,(LPCWSTR)&DAT_005856d0,-1,PTR_DAT_00576ac0,0x3f,
                                (LPCSTR)0x0,&local_8);
    if ((value4 != 0) && (local_8 == 0)) {
      PTR_DAT_00576ac0[0x3f] = 0;
      return;
    }
LAB_0055273e:
    *PTR_DAT_00576ac0 = 0;
  }
  else {
    if (((char)*_Str1 != '\0') &&
       ((DAT_00585724 == (uint32_t *)0x0 ||
        (value4 = _strcmp((char *)_Str1,(char *)DAT_00585724), value4 != 0)))) {
      CRT_FreeInternal(DAT_00585724);
      svalue5 = _strlen((char *)_Str1);
      DAT_00585724 = _malloc(svalue5 + 1);
      if (DAT_00585724 != (uint32_t *)0x0) {
        _strcpy(DAT_00585724,_Str1);
        CS_LeaveIndexed(0xc);
        _strncpy(PTR_DAT_00576abc,(char *)_Str1,3);
        _Source = (uint32_t *)((intptr_t)_Str1 + 3);
        PTR_DAT_00576abc[3] = 0;
        cVar1 = *(char *)_Source;
        if (cVar1 == '-') {
          _Source = _Str1 + 1;
        }
        value4 = CRT_Atoi(self,(uint8_t *)_Source);
        DAT_00576a30 = (void *)(value4 * 0xe10);
        for (; (cVar2 = (char)*_Source, cVar2 == '+' || (('/' < cVar2 && (cVar2 < ':'))));
            _Source = (uint32_t *)((intptr_t)_Source + 1)) {
        }
        if ((char)*_Source == ':') {
          _Source = (uint32_t *)((intptr_t)_Source + 1);
          value4 = CRT_Atoi(DAT_00576a30,(uint8_t *)_Source);
          DAT_00576a30 = (void *)((intptr_t)DAT_00576a30 + value4 * 0x3c);
          for (; ('/' < (char)*_Source && ((char)*_Source < ':'));
              _Source = (uint32_t *)((intptr_t)_Source + 1)) {
          }
          if ((char)*_Source == ':') {
            _Source = (uint32_t *)((intptr_t)_Source + 1);
            value4 = CRT_Atoi(DAT_00576a30,(uint8_t *)_Source);
            DAT_00576a30 = (void *)((intptr_t)DAT_00576a30 + value4);
            for (; ('/' < (char)*_Source && ((char)*_Source < ':'));
                _Source = (uint32_t *)((intptr_t)_Source + 1)) {
            }
          }
        }
        if (cVar1 == '-') {
          DAT_00576a30 = (void *)-(intptr_t)DAT_00576a30;
        }
        DAT_00576a34 = (intptr_t)(char)*_Source;
        if (DAT_00576a34 != 0) {
          _strncpy(PTR_DAT_00576ac0,(char *)_Source,3);
          PTR_DAT_00576ac0[3] = 0;
          return;
        }
        goto LAB_0055273e;
      }
    }
    CS_LeaveIndexed(0xc);
  }
  return;
}
