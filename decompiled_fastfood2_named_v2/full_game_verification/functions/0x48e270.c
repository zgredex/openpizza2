// rea decompile_all
// name: HighScore_UpdatePlayerEntry
// address: 0x48e270
// body: available
// range: 0x48e270-0x48e662 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall HighScore_UpdatePlayerEntry(void *param_1)

{
  int iVar1;
  undefined4 *this;
  uint uVar2;
  int iVar3;
  undefined4 *this_00;
  BYTE *pBVar4;
  char *pcVar5;
  int local_240;
  void *local_23c;
  BYTE local_238 [64];
  int local_1f8;
  undefined1 local_1f4 [64];
  int local_1b4;
  undefined1 local_1b0 [64];
  int local_170;
  undefined1 local_16c [64];
  int local_12c;
  char local_128 [64];
  int local_e8 [6];
  undefined1 local_d0 [64];
  int local_90;
  CHAR local_8c [64];
  char local_4c [64];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055840e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  Game_BuildPlayerRankingData(param_1,local_e8);
  iVar3 = *(int *)(local_e8[*(int *)(*(int *)(DAT_0057c670 + 0x200 +
                                             *(int *)(DAT_0057c670 + 0x2ec) * 4) + 0x48)] + 0x11c);
  iVar1 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  String_Format(local_8c,(byte *)s__s_hi_00568368,iVar1 + 0x44);
  iVar1 = HighScore_ReadRegistryBlob(local_8c,local_238);
  if (iVar1 == 0) {
    iVar1 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
    String_Format(local_4c,(byte *)s_names__s_txt_00568358,iVar1 + 0x44);
    local_23c = operator_new(0x18);
    local_4 = 0;
    if (local_23c == (void *)0x0) {
      this = (undefined4 *)0x0;
    }
    else {
      this = FileObject_Open(local_23c,DAT_0057c5d8,local_4c,&local_240);
    }
    local_4 = 0xffffffff;
    if (local_240 != 0) {
      this = (undefined4 *)0x0;
    }
    pBVar4 = local_238;
    for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
      pBVar4[0] = '\0';
      pBVar4[1] = '\0';
      pBVar4[2] = '\0';
      pBVar4[3] = '\0';
      pBVar4 = pBVar4 + 4;
    }
    local_1f8 = iVar3;
    iVar1 = Game_GetPlayerCity(*(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4));
    String_Format(local_238,&DAT_005630d0,iVar1 + 0xc);
    local_1b4 = iVar3 / 5;
    local_170 = iVar3 / 10;
    if (this == (undefined4 *)0x0) {
      pcVar5 = local_128;
      uVar2 = Random_RangeFast(0,1);
      this_00 = DAT_0057ba10;
    }
    else {
      pcVar5 = local_128;
      uVar2 = Random_RangeFast(0,1);
      this_00 = this;
    }
    IDMap_GetRandomName(this_00,uVar2,pcVar5);
    String_Format(local_1f4,&DAT_005630d0,local_128);
    if (this == (undefined4 *)0x0) {
      pcVar5 = local_128;
      uVar2 = Random_RangeFast(0,1);
      this = DAT_0057ba10;
    }
    else {
      pcVar5 = local_128;
      uVar2 = Random_RangeFast(0,1);
    }
    IDMap_GetRandomName(this,uVar2,pcVar5);
    String_Format(local_1b0,&DAT_005630d0,local_128);
  }
  if (local_1f8 < iVar3) {
    local_12c = local_1f8;
    String_Format(local_16c,&DAT_005630d0,local_238);
    local_90 = local_1b4;
    String_Format(local_d0,&DAT_005630d0,local_1f4);
    local_1f8 = iVar3;
    iVar3 = Game_GetPlayerCity(*(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4));
    String_Format(local_238,&DAT_005630d0,iVar3 + 0xc);
    local_1b4 = local_12c;
    String_Format(local_1f4,&DAT_005630d0,local_16c);
    local_170 = local_90;
    String_Format(local_1b0,&DAT_005630d0,local_d0);
  }
  else if (local_1b4 < iVar3) {
    local_12c = local_1b4;
    String_Format(local_16c,&DAT_005630d0,local_1f4);
    local_1b4 = iVar3;
    iVar3 = Game_GetPlayerCity(*(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4));
    String_Format(local_1f4,&DAT_005630d0,iVar3 + 0xc);
    local_170 = local_12c;
    String_Format(local_1b0,&DAT_005630d0,local_12c);
  }
  else if (local_170 < iVar3) {
    local_170 = iVar3;
    iVar3 = Game_GetPlayerCity(*(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4));
    String_Format(local_1b0,&DAT_005630d0,iVar3 + 0xc);
  }
  Config_WriteRegistryBlock(local_8c,local_238);
  ExceptionList = local_c;
  return;
}

