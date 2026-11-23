// UI_Manager_Construct: ported from Pizza Connection 2 at 0x523100.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x523100
#include "pc2_port.h"

uint32_t * __thiscall
UI_Manager_Construct
          (void *self,void *arg1,void *arg2,uint32_t arg3,uint32_t arg4,
          uint32_t arg5,uint32_t arg6)

{
  DWORD DVar1;
  uint32_t *uptr2;
  uint32_t uvalue3;
  HANDLE pvVar4;
  int value5;
  uint32_t unaff_EDI;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Constructs the global UI manager and its tables and locks. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a688;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  NamedLockable_Construct((void *)((intptr_t)self + 0x1cc),(char *)0x0);
  local_4 = 0;
  Array_Construct((void *)((intptr_t)self + 0x8324),0);
  *(uint8_t ***)self = &PTR_UI_Manager_ScalarDeletingDestructor_0055c778;
  *(uint32_t *)((intptr_t)self + 0x83e0) = 4000;
  *(uint32_t *)((intptr_t)self + 0x83a8) = 0;
  *(uint32_t *)((intptr_t)self + 0x83a4) = 0xffffd8f1;
  *(uint32_t *)((intptr_t)self + 0x83a0) = 0xffffd8f1;
  *(uint32_t *)((intptr_t)self + 0x839c) = 0;
  *(uint32_t *)((intptr_t)self + 0x284) = 0;
  local_4 = (local_4 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
  *(uint32_t *)((intptr_t)self + 0x8318) = 0;
  DVar1 = GetCurrentThreadId();
  *(DWORD *)((intptr_t)self + 0x830c) = DVar1;
  *(uint32_t *)((intptr_t)self + 0x1c8) = 0;
  *(uint32_t *)((intptr_t)self + 0x1b8) = 0;
  *(uint32_t *)((intptr_t)self + 0x1c4) = 0;
  *(uint32_t *)((intptr_t)self + 0x1bc) = 0;
  *(uint32_t *)((intptr_t)self + 0x224) = 0;
  *(uint32_t *)((intptr_t)self + 0x22c) = 0;
  *(uint32_t *)((intptr_t)self + 0x230) = 0;
  *(uint32_t *)((intptr_t)self + 0x234) = 1;
  *(uint32_t *)((intptr_t)self + 0x238) = 1;
  *(uint32_t *)((intptr_t)self + 0x240) = 0;
  *(void **)((intptr_t)self + 0x8320) = arg2;
  *(uint32_t *)((intptr_t)self + 0x278) = 0;
  *(uint32_t *)((intptr_t)self + 0x32b4) = 0;
  *(uint32_t *)((intptr_t)self + 0x32b8) = 0;
  *(uint32_t *)((intptr_t)self + 0x82bc) = 0;
  *(uint32_t *)((intptr_t)self + 0x82c0) = 0;
  *(uint32_t *)((intptr_t)self + 0x228) = 0;
  *(uint32_t *)((intptr_t)self + 0x270) = arg4;
  *(uint32_t *)((intptr_t)self + 0x274) = arg5;
  *(uint32_t *)((intptr_t)self + 0x82c4) = 0;
  *(uint32_t *)((intptr_t)self + 0x82c8) = 0;
  *(uint32_t *)((intptr_t)self + 0x82cc) = 0;
  *(uint32_t *)((intptr_t)self + 0x82d4) = 0;
  *(uint32_t *)((intptr_t)self + 0x82d8) = 0;
  *(uint32_t *)((intptr_t)self + 0x82e0) = 0;
  *(uint32_t *)((intptr_t)self + 0x82e4) = 0;
  *(uint32_t *)((intptr_t)self + 0x82e8) = 0x18;
  *(uint32_t *)((intptr_t)self + 0x82dc) = 0;
  *(uint32_t *)((intptr_t)self + 0x82d0) = 0;
  *(uint32_t *)((intptr_t)self + 0x82ec) = 1;
  *(uint32_t *)((intptr_t)self + 0x82f4) = 500;
  *(uint32_t *)((intptr_t)self + 0x82f8) = 0;
  *(uint32_t *)((intptr_t)self + 0x82fc) = 0;
  *(uint32_t *)((intptr_t)self + 0x8300) = 0;
  *(uint32_t *)((intptr_t)self + 0x8304) = 0;
  *(uint32_t *)((intptr_t)self + 0x8308) = 0;
  *(uint32_t *)((intptr_t)self + 0x248) = 0;
  *(uint32_t *)((intptr_t)self + 0x24c) = 0;
  *(uint32_t *)((intptr_t)self + 0x831c) = 0;
  *(uint32_t *)((intptr_t)self + 0x8338) = 0;
  *(uint32_t *)((intptr_t)self + 0x833c) = 0;
  *(uint32_t *)((intptr_t)self + 0x8348) = 0;
  *(uint32_t *)((intptr_t)self + 0x8340) = 500;
  *(uint32_t *)((intptr_t)self + 0x8344) = 0x32;
  *(uint32_t *)((intptr_t)self + 0x8350) = 0;
  *(uint32_t *)((intptr_t)self + 0x834c) = 0;
  *(uint32_t *)((intptr_t)self + 0x1c0) = 0;
  *(uint32_t *)((intptr_t)self + 0x8358) = arg6;
  *(uint32_t *)((intptr_t)self + 0x83ac) = 0;
  *(uint32_t *)((intptr_t)self + 0x83b8) = 0;
  *(uint32_t *)((intptr_t)self + 0x1a4) = 0xfffffc19;
  *(uint32_t *)((intptr_t)self + 0x83e4) = 0;
  QueryPerformanceFrequency((LARGE_INTEGER *)((intptr_t)self + 0x83b0));
  uptr2 = (uint32_t *)((intptr_t)self + 0x250);
  for (value5 = 8; value5 != 0; value5 = value5 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  SetWindowLongA(*(HWND *)((intptr_t)self + 0x8320),-0x15,(LONG)self);
  uptr2 = (uint32_t *)((intptr_t)self + 0x14);
  for (value5 = 100; value5 != 0; value5 = value5 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  uptr2 = (uint32_t *)((intptr_t)self + 0x250);
  for (value5 = 8; value5 != 0; value5 = value5 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  *(uint32_t *)((intptr_t)self + 0x10) = arg3;
  uptr2 = Renderer_CreateChild(arg1);
  *(uint32_t **)((intptr_t)self + 0xc) = uptr2;
  *(uint32_t *)((intptr_t)self + 0x1b4) = 1;
  if (*(int *)((intptr_t)arg1 + 0x98) == 0) {
    *(uint32_t *)((intptr_t)self + 0x1b4) = 0;
    if (*(int *)((intptr_t)self + 0x8358) == 0) {
      value5 = Object_GetRootType((intptr_t)arg1);
      if (value5 == 2) {
        if (*(int *)((intptr_t)arg1 + 0x40) == 0) {
          *(uint32_t *)((intptr_t)self + 0x1c0) = 0;
        }
        else {
          *(uint32_t *)((intptr_t)self + 0x1c0) = *(uint32_t *)(*(int *)((intptr_t)arg1 + 0x40) + 8);
        }
      }
      else {
        uvalue3 = Surface_CreateDesc(arg1,*(uint32_t *)((intptr_t)self + 0x270),
                                   *(uint32_t *)((intptr_t)self + 0x274),(int *)&arg2,0,0x2800);
        *(uint32_t *)((intptr_t)self + 0x1c0) = uvalue3;
        if (arg2 != (void *)0x0) {
          NoOp_Stub();
        }
      }
      Renderer_InitForWindow(arg1,*(HWND *)((intptr_t)self + 0x8320));
      Sprite_ClearBuffers(*(int **)((intptr_t)self + 0x1c0));
    }
    else {
      arg2 = operator_new(0x11c);
      local_4 = (local_4 & ~(0x0u << 8)) | (((2) & 0x0u) << 8);
      if (arg2 == (void *)0x0) {
        uptr2 = (uint32_t *)0x0;
      }
      else {
        uptr2 = Window_Construct(arg2,*(int *)((intptr_t)self + 0x270),*(int *)((intptr_t)self + 0x274),2)
        ;
      }
      local_4 = (local_4 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
      *(uint32_t **)((intptr_t)self + 0x1bc) = uptr2;
      Surface_Clear((intptr_t)uptr2);
    }
  }
  arg2 = operator_new(0x58);
  local_4 = (local_4 & ~(0x0u << 8)) | (((3) & 0x0u) << 8);
  if (arg2 == (void *)0x0) {
    uptr2 = (uint32_t *)0x0;
  }
  else {
    uptr2 = NamedLockable_Construct(arg2,s_MenuCriticalSection_00574050);
  }
  local_4 = (local_4 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
  *(uint32_t **)((intptr_t)self + 0x1c8) = uptr2;
  *(uint32_t *)((intptr_t)self + 0x8314) = 0;
  arg2 = operator_new(0x28);
  local_4 = (local_4 & ~(0x0u << 8)) | (((4) & 0x0u) << 8);
  if (arg2 == (void *)0x0) {
    uvalue3 = 0;
  }
  else {
    uvalue3 = UI_InitInputHelper(arg2,self);
  }
  *(uint32_t *)((intptr_t)self + 0x8310) = uvalue3;
  *(uint32_t *)((intptr_t)self + 0x23c) = 0;
  *(uint32_t *)((intptr_t)self + 0x288) = 0;
  *(uint32_t *)((intptr_t)self + 0x298) = 0xffffff;
  *(uint32_t *)((intptr_t)self + 0x29c) = 0;
  *(uint32_t *)((intptr_t)self + 0x2a0) = 0xff000000;
  *(uint32_t *)((intptr_t)self + 0x2a4) = 0xff000000;
  *(uint32_t *)((intptr_t)self + 0x2a8) = 0xff000000;
  *(uint32_t *)((intptr_t)self + 0x28c) = 0xc0c0c0;
  *(uint32_t *)((intptr_t)self + 0x290) = 0xffffff;
  *(uint32_t *)((intptr_t)self + 0x294) = 0xff0000;
  *(char **)((intptr_t)self + 0x2ac) = s_cancel_00574048;
  *(uint8_t **)((intptr_t)self + 0x2b0) = &DAT_00574044;
  local_4 = (local_4 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
  DebugConsole_Printf(DAT_0057c1e0,0xff0000,(uint8_t *)s_menu_ready_00574038,unaff_EDI);
  *(uint32_t *)((intptr_t)self + 8) = 0;
  *(uint32_t *)((intptr_t)self + 0x1a4) = 0xfffffc19;
  *(uint32_t *)((intptr_t)self + 0x284) = 1;
  arg2 = operator_new(0x50);
  local_4 = (local_4 & ~(0x0u << 8)) | (((5) & 0x0u) << 8);
  if (arg2 == (void *)0x0) {
    uptr2 = (uint32_t *)0x0;
  }
  else {
    uptr2 = Tooltip_Construct(arg2,arg1,self);
  }
  local_4 = CONCAT31(((uint8_t)((local_4) >> 24)),1);
  *(uint32_t **)((intptr_t)self + 0x244) = uptr2;
  UI_LoadSpriteSet(self,s_REQUEST_OUTL_00574028);
  pvVar4 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,1,s_MouseSetEvent_00574018);
  *(HANDLE *)((intptr_t)self + 0x8354) = pvVar4;
  ExceptionList = local_c;
  return self;
}
