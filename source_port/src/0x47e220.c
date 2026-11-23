// Branch_Destroy: ported from Pizza Connection 2 at 0x47e220.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47e220
#include "pc2_port.h"

void __fastcall Branch_Destroy(uint32_t *arg1)

{
  uint32_t *uptr1;
  LPVOID pvVar2;
  int value3;
  int value4;
  void *pvStack_c;
  uint8_t *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0055805e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *arg1 = &PTR_Branch_Delete_0055c30c;
  value3 = 0;
  local_4 = 8;
  *(uint32_t *)(arg1[0x5bc] + 0x94) = 0;
  uptr1 = *(uint32_t **)(arg1[0x5bc] + 0x74);
  if (uptr1 != (uint32_t *)0x0) {
    *(uint32_t *)(arg1[0x5bc] + 0x74) = 0;
    (**(code **)*uptr1)(1);
  }
  IDMap_FreeValuesAndReset(arg1 + 0x540);
  if ((uint32_t *)arg1[0x538] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0x538])(1);
  }
  value4 = arg1[0x5c3];
  if (0 < value4) {
    do {
      uptr1 = (uint32_t *)IDMap_Lookup(arg1 + 0x5be,value3,(int *)0x0);
      if (uptr1 != (uint32_t *)0x0) {
        (**(code **)*uptr1)(1);
      }
      value3 = value3 + 1;
    } while (value3 < value4);
  }
  value3 = arg1[0x53e];
  value4 = 0;
  if (0 < value3) {
    do {
      uptr1 = (uint32_t *)IDMap_Lookup(arg1 + 0x539,value4,(int *)0x0);
      if (uptr1 != (uint32_t *)0x0) {
        (**(code **)*uptr1)(1);
      }
      value4 = value4 + 1;
    } while (value4 < value3);
  }
  value3 = arg1[0x676];
  value4 = 0;
  if (0 < value3) {
    do {
      pvVar2 = (LPVOID)IDMap_Lookup(arg1 + 0x671,value4,(int *)0x0);
      Mem_Free(pvVar2);
      value4 = value4 + 1;
    } while (value4 < value3);
  }
  value3 = arg1[0x66b];
  value4 = 0;
  if (0 < value3) {
    do {
      pvVar2 = (LPVOID)IDMap_Lookup(arg1 + 0x666,value4,(int *)0x0);
      Mem_Free(pvVar2);
      value4 = value4 + 1;
    } while (value4 < value3);
  }
  Game_RemoveObjectFromUI(arg1[0x5bc]);
  Game_FreeSubmapObjects((intptr_t)arg1);
  local_4 = (local_4 & ~(0x0u << 8)) | (((7) & 0x0u) << 8);
  List_Node_Destroy(arg1 + 0x678);
  local_4 = (local_4 & ~(0x0u << 8)) | (((6) & 0x0u) << 8);
  List_Node_Destroy(arg1 + 0x671);
  local_4 = (local_4 & ~(0x0u << 8)) | (((5) & 0x0u) << 8);
  List_Node_Destroy(arg1 + 0x666);
  local_4 = (local_4 & ~(0x0u << 8)) | (((4) & 0x0u) << 8);
  List_Node_Destroy(arg1 + 0x5d8);
  local_4 = (local_4 & ~(0x0u << 8)) | (((3) & 0x0u) << 8);
  List_Node_Destroy(arg1 + 0x5d1);
  local_4 = (local_4 & ~(0x0u << 8)) | (((2) & 0x0u) << 8);
  List_Node_Destroy(arg1 + 0x5ca);
  local_4 = (local_4 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
  List_Node_Destroy(arg1 + 0x5be);
  local_4 = (uint32_t)((uint8_t)((local_4) >> 24)) << 8;
  List_Node_Destroy(arg1 + 0x540);
  local_4 = 0xffffffff;
  List_Node_Destroy(arg1 + 0x539);
  ExceptionList = pvStack_c;
  return;
}
