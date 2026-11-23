// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x54f585.c:12:30: error: unknown type name 'FILETIME'
// ___timet_from_ft: ported from Pizza Connection 2 at 0x54f585.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54f585
#include "pc2_port.h"

struct pc2_obj_0x54f585_arg1 { intptr_t dwHighDateTime; intptr_t dwLowDateTime; };
/* Library Function - Single Match
    ___timet_from_ft
   
   Library: Visual Studio 2003 Release */

int __cdecl ___timet_from_ft(FILETIME *arg1)

{
  struct pc2_obj_0x54f585_arg1 *arg1;
  BOOL BVar1;
  int value2;
  _SYSTEMTIME local_1c;
  _FILETIME local_c;
  
  if ((arg1->dwLowDateTime != 0) || (arg1->dwHighDateTime != 0)) {
    BVar1 = FileTimeToLocalFileTime(arg1,&local_c);
    if (BVar1 != 0) {
      BVar1 = FileTimeToSystemTime(&local_c,&local_1c);
      if (BVar1 != 0) {
        value2 = CRT_LoctoTime64((uint32_t)local_1c.wYear,(uint32_t)local_1c.wMonth,(uint32_t)local_1c.wDay,
                                (uint32_t)local_1c.wHour,(uint32_t)local_1c.wMinute,(uint32_t)local_1c.wSecond,
                                -1);
        return value2;
      }
    }
  }
  return -1;
}
