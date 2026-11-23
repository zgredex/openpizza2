// Movie_Play: ported from Pizza Connection 2 at 0x4ce9d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ce9d0
#include "pc2_port.h"


void __cdecl Movie_Play(int arg1,char *arg2)

{
  void *self;
  uint32_t *uptr1;
  int value2;
  uint32_t *this_00;
  int value3;
  DWORD DVar4;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558ceb;
  local_c = ExceptionList;
  DAT_0056b40c = 1;
  ExceptionList = &local_c;
  self = operator_new(0x11c);
  local_4 = 0;
  if (self == (void *)0x0) {
    uptr1 = (uint32_t *)0x0;
  }
  else {
    uptr1 = Window_Construct(self,800,600,0x10);
  }
  local_4 = 0xffffffff;
  Surface_Clear((intptr_t)uptr1);
  value2 = UI_CreateWindow(DAT_0057c5e0,0,100,s_clipsprite_spr_0056b410,&LAB_004ce950);
  this_00 = (uint32_t *)UI_FindWindowByID(DAT_0057c5e0,value2,(int *)0x0);
  DAT_0057df90 = this_00;
  Movie_CreatePlayer(this_00,100,0,0,arg2,(uint32_t *)0x1);
  UI_StartButtonMovie(DAT_0057df90,100,0);
  if (arg1 != 0) {
    value3 = Object_GetId(arg1);
    Window_HideWindowById(DAT_0057c5e0,value3);
  }
  UI_ReplaceActiveObject(DAT_0057c5e0,uptr1);
  Window_ProcessMessageQueue(DAT_0057c5e0,0);
  Movie_ReleasePlayer((intptr_t)DAT_0057c5e0);
  SoundBuffer_Release((intptr_t)DAT_0057ba0c);
  Window_ShowWindowById(DAT_0057c5e0,value2);
  do {
    if (DAT_0056b40c == 0) break;
    Window_ProcessMessageQueue(DAT_0057c5e0,0);
    Sleep(1);
    DVar4 = WaitForSingleObject(DAT_0057c0d8,0);
  } while (DVar4 != 0);
  DAT_0057df90 = (uint32_t *)0x0;
  Window_DestroyChild(DAT_0057c5e0,this_00);
  if (arg1 != 0) {
    value2 = Object_GetId(arg1);
    Window_ShowWindowById(DAT_0057c5e0,value2);
  }
  Sound_SelectCurrentTrack(DAT_0057ba0c);
  ExceptionList = local_c;
  return;
}
