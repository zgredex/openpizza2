// rea decompile_all
// name: FUN_004cbcd0
// address: 0x4cbcd0
// body: available
// range: 0x4cbcd0-0x4cc221 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004cbcd0(void *param_1)

{
  void *this;
  int iVar1;
  uint uVar2;
  int *piVar3;
  undefined *puVar4;
  void *this_00;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 auStack_f8 [42];
  undefined4 uStack_50;
  undefined4 uVar9;
  int local_24;
  undefined1 local_20 [32];
  
  this = param_1;
  FUN_004cc230(param_1);
  FUN_0052f9b0(param_1,0x429,DAT_00582e4c);
  DAT_0057de60 = param_1;
  UI_RemoveObjectByKey(param_1,0x44d);
  UI_RemoveObjectByKey(param_1,0x451);
  UI_RemoveObjectByKey(param_1,0x450);
  UI_RemoveObjectByKey(param_1,0x452);
  iVar7 = 0x44f;
  do {
    FUN_0052ff80(param_1,iVar7 + -1);
    FUN_0052ff80(param_1,iVar7);
    iVar7 = iVar7 + 8;
  } while (iVar7 < 0x47f);
  FUN_0052f9b0(param_1,0x43f,&DAT_0057bc58);
  FUN_0052f9b0(param_1,0x440,&DAT_0057bc98);
  puVar6 = (undefined4 *)&DAT_0057bc58;
  puVar5 = auStack_f8;
  for (iVar7 = 0x30; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar5 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar5 = puVar5 + 1;
  }
  FUN_004cb860(param_1);
  FUN_004cb8b0(param_1,DAT_0057bd0c,DAT_0057bd10,0x4e6);
  FUN_004cd960(&DAT_0057de38);
  DAT_0057bb3c._2_1_ = DAT_0057b964 == 1;
  DAT_0057bb3c._1_1_ = DAT_0057b968 == 1;
  DAT_0057bb34._0_1_ = DAT_0057b96c == 1;
  DAT_0057bb3c._0_1_ = DAT_0057b970 == 1;
  DAT_0057bb30 = DAT_0057b974;
  DAT_0057bb38 = DAT_0057b978;
  DAT_0057bb2c = DAT_0057b9cc;
  DAT_0057bb24 = DAT_0057b8b4;
  DAT_0057bb4c = DAT_0057b9d4;
  DAT_0057bb50 = DAT_0057b9d8;
  DAT_0057bb28 = DAT_0057b9c8;
  iVar7 = 0;
  DAT_0057bb48 = DAT_0057b9d0;
  DAT_0057bb40 = 0;
  if (0 < DAT_0057de4c) {
    do {
      iVar1 = FUN_004017f0(&DAT_0057de38,iVar7,(int *)0x0);
      uVar2 = FUN_005570c0(this_00,(byte *)(iVar1 + 0x40),(byte *)&DAT_0057b9c4);
      if (uVar2 == 0) {
        DAT_0057bb40 = iVar7;
        break;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < DAT_0057de4c);
  }
  FUN_004cbb10(param_1);
  puVar5 = &DAT_0057bcdc;
  puVar6 = &DAT_0057b994;
  do {
    puVar8 = puVar6 + 1;
    puVar5[-1] = puVar6[-6];
    *puVar5 = *puVar6;
    puVar5[0xe] = puVar6[6];
    puVar5 = puVar5 + 0x30;
    puVar6 = puVar8;
  } while ((int)puVar8 < 0x57b9ac);
  DAT_0057bcdc = 0;
  piVar3 = &DAT_0057b94c;
  do {
    iVar7 = *piVar3;
    piVar3 = piVar3 + 1;
    DAT_0057bcdc = DAT_0057bcdc - iVar7;
  } while ((int)piVar3 < 0x57b964);
  piVar3 = &DAT_0057bdcc;
  do {
    if (piVar3[1] == DAT_0057bd10) {
      piVar3[1] = DAT_0057c270;
    }
    if (*piVar3 == DAT_0057bd0c) {
      *piVar3 = DAT_0057b780;
    }
    piVar3 = piVar3 + 0x30;
  } while ((int)piVar3 < 0x57c18c);
  puVar6 = &DAT_0057bd18;
  param_1 = (void *)0x442;
  local_24 = 0;
  do {
    FUN_0052f9b0(this,(int)param_1 + -1,puVar6);
    FUN_0052f9b0(this,(int)param_1,puVar6 + 0x10);
    puVar5 = puVar6;
    puVar8 = auStack_f8;
    for (iVar7 = 0x30; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar8 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar8 = puVar8 + 1;
    }
    FUN_004cb860(this);
    FUN_004cb8b0(this,puVar6[0x2d],puVar6[0x2e],*(int *)(&DAT_0056b2c8 + local_24));
    param_1 = (void *)((int)param_1 + 2);
    local_24 = local_24 + 4;
    puVar6 = puVar6 + 0x30;
  } while ((int)param_1 < 0x44c);
  iVar7 = 0x49e;
  piVar3 = &DAT_0057bdd4;
  do {
    FUN_0052ff50(this,iVar7,*piVar3);
    piVar3 = piVar3 + 0x30;
    iVar7 = iVar7 + 1;
  } while ((int)piVar3 < 0x57c194);
  FUN_004cb480(this);
  FUN_0052ff50(this,0x4a3,(uint)(DAT_0057bb3c._2_1_ == '\x01'));
  FUN_0052ff50(this,0x4a4,(uint)(DAT_0057bb3c._1_1_ == '\x01'));
  FUN_0052ff50(this,0x4a5,(uint)((char)DAT_0057bb34 == '\x01'));
  FUN_0052ff50(this,0x4a6,(uint)((char)DAT_0057bb3c == '\x01'));
  FUN_0054dd83(local_20,&DAT_005686f4,DAT_0057bb30);
  FUN_0052f9b0(this,0x43e,local_20);
  FUN_0054dd83(local_20,&DAT_005686f4,DAT_0057bb38);
  FUN_0052f9b0(this,0x43d,local_20);
  FUN_0052fd00(this,0x437,100,500,0);
  FUN_0052fd70(this,0x437,DAT_0057bb28,0);
  FUN_0052fce0(this,0x437,1);
  FUN_0052fd00(this,0x434,10,0x6e,0);
  FUN_0052fd70(this,0x434,DAT_0057bb2c * 10,0);
  FUN_0052fce0(this,0x434,1);
  FUN_0052fd00(this,0x407,0,10,0);
  FUN_0052fd70(this,0x407,DAT_0057bb24,0);
  FUN_0052fce0(this,0x407,1);
  puVar4 = FUN_004cda30(&DAT_0057de38,DAT_0057bb40);
  FUN_0052f830(this,0x480,puVar4);
  if (DAT_0057bb48 < 0) {
    uVar9 = DAT_00582a98;
  }
  else {
    uVar9 = (&DAT_0058369c)[DAT_0057bb48];
  }
  FUN_0052f830(this,0x483,uVar9);
  if (DAT_0057bb4c < 0) {
    uVar9 = DAT_00582a98;
  }
  else {
    uVar9 = (&DAT_0058369c)[DAT_0057bb4c];
  }
  FUN_0052f830(this,0x486,uVar9);
  if (DAT_0057bb50 < 0) {
    uVar9 = DAT_00582a98;
  }
  else {
    uVar9 = (&DAT_0058369c)[DAT_0057bb50];
  }
  FUN_0052f830(this,0x489,uVar9);
  FUN_004cb6e0(this);
  FUN_004cb7a0(this);
  FUN_004cb7e0(this);
  FUN_004c7090(this,DAT_0057bb24);
  uStack_50 = 0x4cc217;
  FUN_004cb900(this);
  return;
}

