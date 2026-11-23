// GameSession_Construct: ported from Pizza Connection 2 at 0x4811b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4811b0
#include "pc2_port.h"

uint32_t * __fastcall GameSession_Construct(uint32_t *arg1)

{
  uint32_t *uptr1;
  uint32_t uvalue2;
  void *self;
  int value3;
  int local_18;
  uint32_t *local_14;
  uint32_t *local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Constructs the global game-session object and its subsystems. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005581a6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_14 = arg1;
  List_Construct(arg1 + 1,0);
  local_4 = 0;
  List_Construct(arg1 + 8,0);
  local_4 = (local_4 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
  List_Construct(arg1 + 0xf,0);
  local_4 = (local_4 & ~(0x0u << 8)) | (((2) & 0x0u) << 8);
  List_Construct(arg1 + 0x16,0);
  local_4 = (local_4 & ~(0x0u << 8)) | (((3) & 0x0u) << 8);
  List_Construct(arg1 + 0x1d,0);
  local_4 = (local_4 & ~(0x0u << 8)) | (((4) & 0x0u) << 8);
  UI_BriefingList_Construct(arg1 + 0xc1);
  local_4 = (local_4 & ~(0x0u << 8)) | (((5) & 0x0u) << 8);
  TimerClass_Construct(arg1 + 0xb47);
  local_4 = (local_4 & ~(0x0u << 8)) | (((6) & 0x0u) << 8);
  *arg1 = &PTR_GameWorld_Delete_0055c44c;
  Ingredient_LoadMarketTable((intptr_t)arg1);
  FurnitureType_InitTable((intptr_t)arg1);
  System_QueryMemoryInfo((intptr_t)arg1);
  arg1[0xb44] = 0;
  arg1[0xb45] = 0;
  arg1[0xb46] = 0;
  arg1[0xb69] = 0xffffffff;
  arg1[0x543] = 0;
  arg1[0xb63] = 0xffffffff;
  arg1[0xb66] = 0;
  arg1[0xb6a] = 0;
  arg1[0xe1] = 0;
  arg1[0xb64] = 0xffffffff;
  arg1[0xb86] = DAT_0057ba04;
  local_10 = operator_new(0x58);
  local_4 = (local_4 & ~(0x0u << 8)) | (((7) & 0x0u) << 8);
  if (local_10 == (void *)0x0) {
    uptr1 = (uint32_t *)0x0;
  }
  else {
    uptr1 = NamedLockable_Construct(local_10,&DAT_00568094);
  }
  local_4 = (local_4 & ~(0x0u << 8)) | (((6) & 0x0u) << 8);
  arg1[0x8f] = uptr1;
  local_10 = operator_new(0x58);
  local_4 = (local_4 & ~(0x0u << 8)) | (((8) & 0x0u) << 8);
  if (local_10 == (void *)0x0) {
    uptr1 = (uint32_t *)0x0;
  }
  else {
    uptr1 = NamedLockable_Construct(local_10,s_IsoRedraw_00568088);
  }
  local_4 = (local_4 & ~(0x0u << 8)) | (((6) & 0x0u) << 8);
  arg1[0x90] = uptr1;
  local_10 = operator_new(0x58);
  local_4 = (local_4 & ~(0x0u << 8)) | (((9) & 0x0u) << 8);
  if (local_10 == (void *)0x0) {
    uptr1 = (uint32_t *)0x0;
  }
  else {
    uptr1 = NamedLockable_Construct(local_10,s_PersonAnim_0056807c);
  }
  local_4 = (local_4 & ~(0x0u << 8)) | (((6) & 0x0u) << 8);
  arg1[0x91] = uptr1;
  local_10 = operator_new(0x58);
  local_4 = (local_4 & ~(0x0u << 8)) | (((10) & 0x0u) << 8);
  if (local_10 == (void *)0x0) {
    uptr1 = (uint32_t *)0x0;
  }
  else {
    uptr1 = NamedLockable_Construct(local_10,s_MapAnim_00568074);
  }
  arg1[0x92] = uptr1;
  arg1[0xbf] = 0;
  arg1[0xc0] = 0;
  arg1[0x96] = 0;
  arg1[0x25] = 0;
  arg1[0x24] = 0;
  arg1[0x542] = 1;
  DAT_0057c664 = 0;
  DAT_0057c660 = 0;
  arg1[0xb68] = 0;
  local_4 = (local_4 & ~(0x0u << 8)) | (((6) & 0x0u) << 8);
  uptr1 = arg1 + 0xa6;
  for (value3 = 8; value3 != 0; value3 = value3 + -1) {
    *uptr1 = 0;
    uptr1 = uptr1 + 1;
  }
  if (DAT_0057bb20 == '\x01') {
    arg1[0xa7] = 1;
  }
  else {
    arg1[0xa7] = 4;
  }
  arg1[0xa8] = 10;
  arg1[0xa9] = 0xc;
  arg1[0xaa] = 1;
  arg1[0xab] = 1;
  arg1[0xac] = 3;
  value3 = SaveGame_AnyExist();
  if (value3 == 0) {
    arg1[0xad] = 2;
  }
  else {
    arg1[0xad] = 1;
  }
  local_18 = 0;
  do {
    arg1[local_18 + 0xae] = arg1[local_18 + 0xa6];
    local_18 = local_18 + 1;
  } while (local_18 < 8);
  local_10 = operator_new(0x11c);
  local_4 = (local_4 & ~(0x0u << 8)) | (((0xb) & 0x0u) << 8);
  if (local_10 == (void *)0x0) {
    uptr1 = (uint32_t *)0x0;
  }
  else {
    uptr1 = FullscreenImage_Load
                       (local_10,s_MASK_PCX_00568068,DAT_0057c5c8,DAT_0057c5d8,&local_18,
                        (uint8_t *)0x0);
  }
  arg1[0x28] = uptr1;
  local_4 = (local_4 & ~(0x0u << 8)) | (((6) & 0x0u) << 8);
  if (local_18 != 0) {
    NoOp_Stub();
  }
  local_10 = operator_new(0x98);
  local_4 = (local_4 & ~(0x0u << 8)) | (((0xc) & 0x0u) << 8);
  if (local_10 == (void *)0x0) {
    uptr1 = (uint32_t *)0x0;
  }
  else {
    uptr1 = Anim_Load(local_10,(intptr_t)DAT_0057c5c8,DAT_0057c5d8,s_MINSYM_ani_00568048,&local_18,0);
  }
  arg1[0x29] = uptr1;
  local_4 = (local_4 & ~(0x0u << 8)) | (((6) & 0x0u) << 8);
  if (local_18 != 0) {
    NoOp_Stub();
  }
  Map_BuildPixelCoordIndex((intptr_t)arg1);
  System_QueryMemoryInfo((intptr_t)arg1);
  arg1[0xa4] = 1;
  arg1[0xb7] = 1;
  arg1[0xb8] = 0;
  arg1[0xa0] = 0;
  *(bool *)(arg1 + 0xa5) = arg1[0xa4] == 1;
  arg1[0xba] = 0;
  arg1[0x97] = 0;
  arg1[0x98] = 0;
  arg1[0x99] = 0;
  arg1[0x9a] = 0;
  arg1[0x9b] = 0;
  arg1[0x9c] = 0;
  arg1[0x9d] = 0xffffffff;
  arg1[0x9e] = 0xffffffff;
  arg1[0x9f] = 0;
  arg1[0xa1] = 0;
  arg1[0xb6] = 0;
  arg1[0x26] = 0;
  arg1[0x27] = 0;
  arg1[0xd0] = 0;
  arg1[0x93] = 0;
  arg1[0x94] = 0;
  arg1[0x95] = 0;
  arg1[0xbb] = 0;
  arg1[0xbc] = 0;
  arg1[0xbe] = 0;
  arg1[0xcf] = 0xffffffff;
  arg1[0xd2] = 0xffffffff;
  arg1[0xd3] = 0xffffffff;
  arg1[0xd4] = 0;
  arg1[0xd1] = 0xffffffff;
  arg1[0xd5] = 0;
  arg1[0xd9] = 0;
  arg1[0xda] = 0;
  arg1[0x86] = 0;
  arg1[0x87] = 0;
  arg1[0x88] = 0;
  arg1[0xd8] = 0xffffffff;
  arg1[0xd6] = 0;
  Game_RefreshDaylightCurve(arg1,DAT_0057ba00);
  arg1[0xd7] = 0;
  local_18 = 0;
  do {
    arg1[local_18 + 0xdb] = 0xffffffff;
    local_18 = local_18 + 1;
  } while (local_18 < 6);
  DAT_0057c670 = arg1;
  local_10 = operator_new(0x28);
  local_4 = (local_4 & ~(0x0u << 8)) | (((0xd) & 0x0u) << 8);
  if (local_10 == (void *)0x0) {
    uptr1 = (uint32_t *)0x0;
  }
  else {
    uptr1 = GameClock_Construct(local_10,(void *)0x0);
  }
  arg1[0x25] = uptr1;
  local_4 = (local_4 & ~(0x0u << 8)) | (((6) & 0x0u) << 8);
  local_18 = 0;
  do {
    arg1[local_18 + 0x80] = 0;
    arg1[local_18 + 0x89] = 0;
    local_18 = local_18 + 1;
  } while (local_18 < 6);
  arg1[0x27] = 0;
  arg1[0xbd] = 0;
  arg1[0xb9] = 0;
  local_10 = operator_new(0x8ac);
  local_4 = (local_4 & ~(0x0u << 8)) | (((0xe) & 0x0u) << 8);
  if (local_10 == (uint32_t *)0x0) {
    uptr1 = (uint32_t *)0x0;
  }
  else {
    uptr1 = Game_CompanyManager_Construct(local_10);
  }
  arg1[0x24] = uptr1;
  local_4 = (local_4 & ~(0x0u << 8)) | (((6) & 0x0u) << 8);
  *(uint32_t *)(arg1[0x25] + 0x14) = 0xc35;
  *(uint8_t *)(arg1 + 0xb65) = 1;
  local_10 = operator_new(0x6a8);
  local_4 = (local_4 & ~(0x0u << 8)) | (((0xf) & 0x0u) << 8);
  if (local_10 == (void *)0x0) {
    uptr1 = (uint32_t *)0x0;
  }
  else {
    uptr1 = MapBadgeAnim_Construct
                       (local_10,DAT_0057c5e0,s_NUMBDNEW_00568018,s_NUMBDNEWRED_00568024);
  }
  local_4 = CONCAT31(((uint8_t)((local_4) >> 24)),6);
  arg1[0xb67] = uptr1;
  uvalue2 = Timer_AddEntry(arg1 + 0xb47,&LAB_00485120,0x53,0);
  arg1[0xb69] = uvalue2;
  value3 = Window_CreateSimpleWindow(DAT_0057c5e0,0x27b,0x21,0x80,0x80,&LAB_00481840);
  arg1[0xb6b] = value3;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value3,(int *)0x0);
  UI_CreateBitmapGadget(self,99999,0,0,0x80,0x80,0x10);
  ExceptionList = local_c;
  return arg1;
}
