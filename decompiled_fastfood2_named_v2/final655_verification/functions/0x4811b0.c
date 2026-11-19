// rea decompile_all
// name: GameSession_Construct
// address: 0x4811b0
// body: available
// range: 0x4811b0-0x481797 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __fastcall GameSession_Construct(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  void *this;
  int iVar3;
  int local_18;
  undefined4 *local_14;
  undefined4 *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* Constructs the global game-session object and its subsystems. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005581a6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_14 = param_1;
  FUN_004013a0(param_1 + 1,0);
  local_4 = 0;
  FUN_004013a0(param_1 + 8,0);
  local_4._0_1_ = 1;
  FUN_004013a0(param_1 + 0xf,0);
  local_4._0_1_ = 2;
  FUN_004013a0(param_1 + 0x16,0);
  local_4._0_1_ = 3;
  FUN_004013a0(param_1 + 0x1d,0);
  local_4._0_1_ = 4;
  FUN_0054a880(param_1 + 0xc1);
  local_4._0_1_ = 5;
  TimerClass_Construct(param_1 + 0xb47);
  local_4._0_1_ = 6;
  *param_1 = &PTR_GameWorld_Delete_0055c44c;
  FUN_004e4930((int)param_1);
  FurnitureType_InitTable((int)param_1);
  FUN_004817c0((int)param_1);
  param_1[0xb44] = 0;
  param_1[0xb45] = 0;
  param_1[0xb46] = 0;
  param_1[0xb69] = 0xffffffff;
  param_1[0x543] = 0;
  param_1[0xb63] = 0xffffffff;
  param_1[0xb66] = 0;
  param_1[0xb6a] = 0;
  param_1[0xe1] = 0;
  param_1[0xb64] = 0xffffffff;
  param_1[0xb86] = DAT_0057ba04;
  local_10 = operator_new(0x58);
  local_4._0_1_ = 7;
  if (local_10 == (void *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = NamedLockable_Construct(local_10,&DAT_00568094);
  }
  local_4._0_1_ = 6;
  param_1[0x8f] = puVar1;
  local_10 = operator_new(0x58);
  local_4._0_1_ = 8;
  if (local_10 == (void *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = NamedLockable_Construct(local_10,s_IsoRedraw_00568088);
  }
  local_4._0_1_ = 6;
  param_1[0x90] = puVar1;
  local_10 = operator_new(0x58);
  local_4._0_1_ = 9;
  if (local_10 == (void *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = NamedLockable_Construct(local_10,s_PersonAnim_0056807c);
  }
  local_4._0_1_ = 6;
  param_1[0x91] = puVar1;
  local_10 = operator_new(0x58);
  local_4._0_1_ = 10;
  if (local_10 == (void *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = NamedLockable_Construct(local_10,s_MapAnim_00568074);
  }
  param_1[0x92] = puVar1;
  param_1[0xbf] = 0;
  param_1[0xc0] = 0;
  param_1[0x96] = 0;
  param_1[0x25] = 0;
  param_1[0x24] = 0;
  param_1[0x542] = 1;
  DAT_0057c664 = 0;
  DAT_0057c660 = 0;
  param_1[0xb68] = 0;
  local_4._0_1_ = 6;
  puVar1 = param_1 + 0xa6;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  if (DAT_0057bb20 == '\x01') {
    param_1[0xa7] = 1;
  }
  else {
    param_1[0xa7] = 4;
  }
  param_1[0xa8] = 10;
  param_1[0xa9] = 0xc;
  param_1[0xaa] = 1;
  param_1[0xab] = 1;
  param_1[0xac] = 3;
  iVar3 = FUN_004a1450();
  if (iVar3 == 0) {
    param_1[0xad] = 2;
  }
  else {
    param_1[0xad] = 1;
  }
  local_18 = 0;
  do {
    param_1[local_18 + 0xae] = param_1[local_18 + 0xa6];
    local_18 = local_18 + 1;
  } while (local_18 < 8);
  local_10 = operator_new(0x11c);
  local_4._0_1_ = 0xb;
  if (local_10 == (void *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_00535fc0(local_10,s_MASK_PCX_00568068,DAT_0057c5c8,DAT_0057c5d8,&local_18,
                          (undefined *)0x0);
  }
  param_1[0x28] = puVar1;
  local_4._0_1_ = 6;
  if (local_18 != 0) {
    FUN_0048e0a0();
  }
  local_10 = operator_new(0x98);
  local_4._0_1_ = 0xc;
  if (local_10 == (void *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = Anim_Load(local_10,(int)DAT_0057c5c8,DAT_0057c5d8,s_MINSYM_ani_00568048,&local_18,0);
  }
  param_1[0x29] = puVar1;
  local_4._0_1_ = 6;
  if (local_18 != 0) {
    FUN_0048e0a0();
  }
  FUN_004825c0((int)param_1);
  FUN_004817c0((int)param_1);
  param_1[0xa4] = 1;
  param_1[0xb7] = 1;
  param_1[0xb8] = 0;
  param_1[0xa0] = 0;
  *(bool *)(param_1 + 0xa5) = param_1[0xa4] == 1;
  param_1[0xba] = 0;
  param_1[0x97] = 0;
  param_1[0x98] = 0;
  param_1[0x99] = 0;
  param_1[0x9a] = 0;
  param_1[0x9b] = 0;
  param_1[0x9c] = 0;
  param_1[0x9d] = 0xffffffff;
  param_1[0x9e] = 0xffffffff;
  param_1[0x9f] = 0;
  param_1[0xa1] = 0;
  param_1[0xb6] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0xd0] = 0;
  param_1[0x93] = 0;
  param_1[0x94] = 0;
  param_1[0x95] = 0;
  param_1[0xbb] = 0;
  param_1[0xbc] = 0;
  param_1[0xbe] = 0;
  param_1[0xcf] = 0xffffffff;
  param_1[0xd2] = 0xffffffff;
  param_1[0xd3] = 0xffffffff;
  param_1[0xd4] = 0;
  param_1[0xd1] = 0xffffffff;
  param_1[0xd5] = 0;
  param_1[0xd9] = 0;
  param_1[0xda] = 0;
  param_1[0x86] = 0;
  param_1[0x87] = 0;
  param_1[0x88] = 0;
  param_1[0xd8] = 0xffffffff;
  param_1[0xd6] = 0;
  FUN_00485700(param_1,DAT_0057ba00);
  param_1[0xd7] = 0;
  local_18 = 0;
  do {
    param_1[local_18 + 0xdb] = 0xffffffff;
    local_18 = local_18 + 1;
  } while (local_18 < 6);
  DAT_0057c670 = param_1;
  local_10 = operator_new(0x28);
  local_4._0_1_ = 0xd;
  if (local_10 == (void *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_004dd270(local_10,(void *)0x0);
  }
  param_1[0x25] = puVar1;
  local_4._0_1_ = 6;
  local_18 = 0;
  do {
    param_1[local_18 + 0x80] = 0;
    param_1[local_18 + 0x89] = 0;
    local_18 = local_18 + 1;
  } while (local_18 < 6);
  param_1[0x27] = 0;
  param_1[0xbd] = 0;
  param_1[0xb9] = 0;
  local_10 = operator_new(0x8ac);
  local_4._0_1_ = 0xe;
  if (local_10 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_004f6d30(local_10);
  }
  param_1[0x24] = puVar1;
  local_4._0_1_ = 6;
  *(undefined4 *)(param_1[0x25] + 0x14) = 0xc35;
  *(undefined1 *)(param_1 + 0xb65) = 1;
  local_10 = operator_new(0x6a8);
  local_4._0_1_ = 0xf;
  if (local_10 == (void *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_0054bb30(local_10,DAT_0057c5e0,s_NUMBDNEW_00568018,s_NUMBDNEWRED_00568024);
  }
  local_4 = CONCAT31(local_4._1_3_,6);
  param_1[0xb67] = puVar1;
  uVar2 = FUN_00403ac0(param_1 + 0xb47,&LAB_00485120,0x53,0);
  param_1[0xb69] = uVar2;
  iVar3 = FUN_00523ad0(DAT_0057c5e0,0x27b,0x21,0x80,0x80,&LAB_00481840);
  param_1[0xb6b] = iVar3;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar3,(int *)0x0);
  UI_CreateBitmapGadget(this,99999,0,0,0x80,0x80,0x10);
  ExceptionList = local_c;
  return param_1;
}

