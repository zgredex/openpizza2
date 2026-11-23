// ResourceCache_FreeEntryMaps: ported from Pizza Connection 2 at 0x54c630.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54c630
#include "pc2_port.h"

void __fastcall ResourceCache_FreeEntryMaps(int arg1)

{
  LPVOID pvVar1;
  void *pvVar2;
  int value3;
  
  pvVar2 = *(void **)(arg1 + 4);
  if (pvVar2 != (void *)0x0) {
    value3 = 0;
    if (0 < *(int *)((intptr_t)pvVar2 + 0x14)) {
      do {
        pvVar1 = (LPVOID)IDMap_Lookup(pvVar2,value3,(int *)0x0);
        CRT_FreeBufferNode(pvVar1);
        pvVar2 = *(void **)(arg1 + 4);
        value3 = value3 + 1;
      } while (value3 < *(int *)((intptr_t)pvVar2 + 0x14));
    }
    List_Node_Reset(*(int *)(arg1 + 4));
  }
  pvVar2 = *(void **)(arg1 + 0xc);
  if (pvVar2 != (void *)0x0) {
    value3 = 0;
    if (0 < *(int *)((intptr_t)pvVar2 + 0x14)) {
      do {
        pvVar1 = (LPVOID)IDMap_Lookup(pvVar2,value3,(int *)0x0);
        Mem_Free(pvVar1);
        pvVar2 = *(void **)(arg1 + 0xc);
        value3 = value3 + 1;
      } while (value3 < *(int *)((intptr_t)pvVar2 + 0x14));
    }
    List_Node_Reset(*(int *)(arg1 + 0xc));
  }
  pvVar2 = *(void **)(arg1 + 0x10);
  if (pvVar2 != (void *)0x0) {
    value3 = 0;
    if (0 < *(int *)((intptr_t)pvVar2 + 0x14)) {
      do {
        pvVar1 = (LPVOID)IDMap_Lookup(pvVar2,value3,(int *)0x0);
        Mem_Free(pvVar1);
        pvVar2 = *(void **)(arg1 + 0x10);
        value3 = value3 + 1;
      } while (value3 < *(int *)((intptr_t)pvVar2 + 0x14));
    }
    List_Node_Reset(*(int *)(arg1 + 0x10));
  }
  pvVar2 = *(void **)(arg1 + 0x14);
  if (pvVar2 != (void *)0x0) {
    value3 = 0;
    if (0 < *(int *)((intptr_t)pvVar2 + 0x14)) {
      do {
        pvVar1 = (LPVOID)IDMap_Lookup(pvVar2,value3,(int *)0x0);
        if (*(LPVOID *)((intptr_t)pvVar1 + 0xc) != (LPVOID)0x0) {
          Mem_Free(*(LPVOID *)((intptr_t)pvVar1 + 0xc));
        }
        if (*(LPVOID *)((intptr_t)pvVar1 + 0x10) != (LPVOID)0x0) {
          Mem_Free(*(LPVOID *)((intptr_t)pvVar1 + 0x10));
        }
        Mem_Free(pvVar1);
        pvVar2 = *(void **)(arg1 + 0x14);
        value3 = value3 + 1;
      } while (value3 < *(int *)((intptr_t)pvVar2 + 0x14));
    }
    List_Node_Reset(*(int *)(arg1 + 0x14));
  }
  pvVar2 = *(void **)(arg1 + 8);
  if (pvVar2 != (void *)0x0) {
    value3 = 0;
    if (0 < *(int *)((intptr_t)pvVar2 + 0x14)) {
      do {
        pvVar1 = (LPVOID)IDMap_Lookup(pvVar2,value3,(int *)0x0);
        if (pvVar1 != (LPVOID)0x0) {
          Memory_FreeField4((intptr_t)pvVar1);
          Mem_Free(pvVar1);
        }
        pvVar2 = *(void **)(arg1 + 8);
        value3 = value3 + 1;
      } while (value3 < *(int *)((intptr_t)pvVar2 + 0x14));
    }
    List_Node_Reset(*(int *)(arg1 + 8));
  }
  pvVar2 = *(void **)(arg1 + 0x28);
  if (pvVar2 != (void *)0x0) {
    value3 = 0;
    if (0 < *(int *)((intptr_t)pvVar2 + 0x14)) {
      do {
        pvVar1 = (LPVOID)IDMap_Lookup(pvVar2,value3,(int *)0x0);
        Mem_Free(pvVar1);
        pvVar2 = *(void **)(arg1 + 0x28);
        value3 = value3 + 1;
      } while (value3 < *(int *)((intptr_t)pvVar2 + 0x14));
    }
    List_Node_Reset(*(int *)(arg1 + 0x28));
  }
  pvVar2 = *(void **)(arg1 + 0x2c);
  if (pvVar2 != (void *)0x0) {
    value3 = 0;
    if (0 < *(int *)((intptr_t)pvVar2 + 0x14)) {
      do {
        pvVar1 = (LPVOID)IDMap_Lookup(pvVar2,value3,(int *)0x0);
        Mem_Free(pvVar1);
        pvVar2 = *(void **)(arg1 + 0x2c);
        value3 = value3 + 1;
      } while (value3 < *(int *)((intptr_t)pvVar2 + 0x14));
    }
    List_Node_Reset(*(int *)(arg1 + 0x2c));
  }
  return;
}
