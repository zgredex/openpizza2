// Company_Destroy: ported from Pizza Connection 2 at 0x4e1990.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e1990
#include "pc2_port.h"

void __fastcall Company_Destroy(uint32_t *arg1)

{
  int value1;
  uint32_t *uptr2;
  LPVOID pvVar3;
  int value4;
  void *pvStack_c;
  uint8_t *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_005594c2;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *arg1 = &PTR_Company_Delete_0055c568;
  value1 = arg1[0x57];
  value4 = 0;
  local_4 = 6;
  if (0 < value1) {
    do {
      uptr2 = (uint32_t *)IDMap_Lookup(arg1 + 0x52,value4,(int *)0x0);
      if (uptr2 != (uint32_t *)0x0) {
        (**(code **)*uptr2)(1);
      }
      value4 = value4 + 1;
    } while (value4 < value1);
  }
  List_Node_Reset((intptr_t)(arg1 + 0x52));
  value1 = arg1[0x5e];
  value4 = 0;
  if (0 < value1) {
    do {
      uptr2 = (uint32_t *)IDMap_Lookup(arg1 + 0x59,value4,(int *)0x0);
      if (uptr2 != (uint32_t *)0x0) {
        (**(code **)*uptr2)(1);
      }
      value4 = value4 + 1;
    } while (value4 < value1);
  }
  List_Node_Reset((intptr_t)(arg1 + 0x59));
  value1 = arg1[0x49];
  value4 = 0;
  if (0 < value1) {
    do {
      uptr2 = (uint32_t *)IDMap_Lookup(arg1 + 0x44,value4,(int *)0x0);
      if (uptr2 != (uint32_t *)0x0) {
        (**(code **)*uptr2)(1);
      }
      value4 = value4 + 1;
    } while (value4 < value1);
  }
  value1 = arg1[0x65];
  value4 = 0;
  if (0 < value1) {
    do {
      uptr2 = (uint32_t *)IDMap_Lookup(arg1 + 0x60,value4,(int *)0x0);
      if (uptr2 != (uint32_t *)0x0) {
        (**(code **)*uptr2)(1);
      }
      value4 = value4 + 1;
    } while (value4 < value1);
  }
  value1 = arg1[0x73];
  value4 = 0;
  if (0 < value1) {
    do {
      pvVar3 = (LPVOID)IDMap_Lookup(arg1 + 0x6e,value4,(int *)0x0);
      Mem_Free(pvVar3);
      value4 = value4 + 1;
    } while (value4 < value1);
  }
  value1 = arg1[0x6c];
  value4 = 0;
  if (0 < value1) {
    do {
      pvVar3 = (LPVOID)IDMap_Lookup(arg1 + 0x67,value4,(int *)0x0);
      Mem_Free(pvVar3);
      value4 = value4 + 1;
    } while (value4 < value1);
  }
  if ((uint32_t *)arg1[0x75] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0x75])(1);
  }
  local_4 = (local_4 & ~(0x0u << 8)) | (((5) & 0x0u) << 8);
  List_Node_Destroy(arg1 + 0x6e);
  local_4 = (local_4 & ~(0x0u << 8)) | (((4) & 0x0u) << 8);
  List_Node_Destroy(arg1 + 0x67);
  local_4 = (local_4 & ~(0x0u << 8)) | (((3) & 0x0u) << 8);
  List_Node_Destroy(arg1 + 0x60);
  local_4 = (local_4 & ~(0x0u << 8)) | (((2) & 0x0u) << 8);
  List_Node_Destroy(arg1 + 0x59);
  local_4 = (local_4 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
  List_Node_Destroy(arg1 + 0x52);
  local_4 = (uint32_t)((uint8_t)((local_4) >> 24)) << 8;
  List_Node_Destroy(arg1 + 0x4b);
  local_4 = 0xffffffff;
  List_Node_Destroy(arg1 + 0x44);
  ExceptionList = pvStack_c;
  return;
}
