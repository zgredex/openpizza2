// rea decompile_all
// name: FUN_004dce70
// address: 0x4dce70
// body: available
// range: 0x4dce70-0x4dd045 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_004dce70(int param_1)

{
  int iVar1;
  int iVar2;
  void *this;
  void *this_00;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  int local_110;
  byte local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055924e;
  local_c = ExceptionList;
  iVar5 = 0;
  local_110 = 0;
  iVar4 = 0;
  ExceptionList = &local_c;
  do {
    iVar1 = Game_GetPlayerBySlot(DAT_0057c670,iVar5);
    if ((iVar1 != 0) &&
       ((*(int *)(iVar1 + 0x50) == 0 ||
        (iVar1 == *(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200)))))
    {
      if (*(void **)(iVar1 + 0x1d4) == (void *)0x0) {
        iVar2 = 0;
      }
      else {
        FUN_00512620(*(void **)(iVar1 + 0x1d4),*(int *)(iVar1 + 0x48));
        iVar2 = FUN_005104d0(*(void **)(iVar1 + 0x1d4),*(int *)(param_1 + 0x1148));
      }
      if (local_110 < iVar2) {
        iVar4 = *(int *)(iVar1 + 0x48);
        local_110 = iVar2;
      }
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 6);
  this = (void *)Game_GetPlayerBySlot(DAT_0057c670,iVar4);
  *(int *)((int)this + 0x54) = *(int *)((int)this + 0x54) + 1;
  FUN_004e0c40(this,0x18,(float)*(int *)(param_1 + 0x1150),0xffffffff,'\0');
  iVar4 = Game_GetPlayerCity((int)this);
  if (this == *(void **)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200)) {
    FUN_00503250(*(void **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8),0x13,-1);
    FUN_00502f10(*(void **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8),0x13,-1,-1);
  }
  this_00 = operator_new(0xc);
  local_4 = 0;
  if (this_00 == (void *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = FUN_005019d0(this_00,(void *)0x0);
  }
  local_4 = 0xffffffff;
  puVar3[1] = 0;
  FUN_004014b0((void *)(iVar4 + 0x8c),puVar3);
  pbVar6 = local_10c;
  FUN_0054dd83(pbVar6,DAT_005828b0,(int)this + 8);
  FUN_0048bf90((int)DAT_0057c670,-1,3,1,2,0,DAT_00581744,local_10c,pbVar6);
  *(undefined4 *)(param_1 + 0x1148) = 0;
  *(undefined4 *)(param_1 + 0x114c) = 0;
  *(undefined4 *)(param_1 + 0x1150) = 0;
  *(undefined4 *)(param_1 + 0x1154) = 0;
  iVar4 = 0;
  do {
    iVar5 = Game_GetPlayerBySlot(DAT_0057c670,iVar4);
    if (iVar5 != 0) {
      *(undefined4 *)(iVar5 + 0x50) = 0xffffffff;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 6);
  ExceptionList = local_c;
  return;
}

