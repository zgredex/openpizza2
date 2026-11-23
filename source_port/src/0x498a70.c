// SaveGame_ScanSaveFileList: ported from Pizza Connection 2 at 0x498a70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x498a70
#include "pc2_port.h"


uint32_t SaveGame_ScanSaveFileList(void)

{
  char cVar1;
  void *pvVar2;
  HANDLE pvVar3;
  char *cptr4;
  int value5;
  uint32_t uvalue6;
  uint32_t uvalue7;
  char *cptr8;
  char *cptr9;
  uint32_t local_324 [5];
  uint8_t local_310 [260];
  char local_20c [512];
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Scans and builds the save-game file list. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005585fc;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar2 = operator_new(0x1c);
  local_4 = 0;
  if (pvVar2 == (void *)0x0) {
    DAT_0057ca04 = (uint32_t *)0x0;
  }
  else {
    DAT_0057ca04 = List_Construct(pvVar2,0);
  }
  local_4 = 0xffffffff;
  pvVar3 = CRT_FindFirst(s_save_piz___piz_005688d0,local_324);
  if (pvVar3 == (HANDLE)0xffffffff) {
    ExceptionList = local_c;
    return 0;
  }
  do {
    String_Format(local_20c,&DAT_005630d0,local_310);
    cptr4 = _strchr(local_20c,0x2e);
    uvalue6 = 0xffffffff;
    cptr8 = &DAT_0057ca0c;
    do {
      cptr9 = cptr8;
      if (uvalue6 == 0) break;
      uvalue6 = uvalue6 - 1;
      cptr9 = cptr8 + 1;
      cVar1 = *cptr8;
      cptr8 = cptr9;
    } while (cVar1 != '\0');
    uvalue6 = ~uvalue6;
    cptr8 = cptr9 + -uvalue6;
    for (uvalue7 = uvalue6 >> 2; uvalue7 != 0; uvalue7 = uvalue7 - 1) {
      *(uint32_t *)cptr4 = *(uint32_t *)cptr8;
      cptr8 = cptr8 + 4;
      cptr4 = cptr4 + 4;
    }
    for (uvalue6 = uvalue6 & 3; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
      *cptr4 = *cptr8;
      cptr8 = cptr8 + 1;
      cptr4 = cptr4 + 1;
    }
    pvVar2 = operator_new(0x58);
    local_4 = 1;
    if (pvVar2 == (void *)0x0) {
      cptr4 = (char *)0x0;
    }
    else {
      cptr4 = UI_ListEntry_Construct(pvVar2,local_20c,0);
    }
    local_4 = 0xffffffff;
    List_Add(DAT_0057ca04,cptr4);
    value5 = CRT_FindNext(pvVar3,local_324);
    if (value5 == -1) {
      CRT_FindClose(pvVar3);
      ExceptionList = local_c;
      return 1;
    }
  } while( true );
}
