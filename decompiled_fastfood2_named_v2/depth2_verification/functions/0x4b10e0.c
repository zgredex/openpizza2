// rea decompile_all
// name: FUN_004b10e0
// address: 0x4b10e0
// body: available
// range: 0x4b10e0-0x4b1a2e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004b10e0(void *param_1,undefined4 param_2,int *param_3)

{
  bool bVar1;
  int iVar2;
  undefined1 *puVar3;
  int local_204;
  undefined1 local_200 [64];
  undefined1 local_1c0 [64];
  undefined1 local_180 [64];
  undefined1 local_140 [64];
  undefined1 local_100 [64];
  undefined1 local_c0 [64];
  undefined1 local_80 [64];
  undefined1 local_40 [64];
  
  bVar1 = false;
  local_204 = 0;
  if (param_3 == (int *)0x0) {
    puVar3 = local_200;
    iVar2 = 8;
    do {
      FUN_0054dd83(puVar3,&DAT_005630d0,DAT_00582e4c);
      puVar3 = puVar3 + 0x40;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  else {
    FUN_0054dd83(local_1c0,&DAT_005630d0,DAT_00582e04);
    FUN_0054dd83(local_100,&DAT_005630d0,DAT_005824d4);
    FUN_0054dd83(local_80,&DAT_005630d0,DAT_00580c78);
    iVar2 = Game_GetRecordField814Value(*param_3);
    FUN_0054dd83(local_200,&DAT_005630d0,iVar2);
    FUN_0054dd83(local_180,&DAT_005686f4,*(undefined4 *)(*param_3 + 0x38));
    FUN_0054dd83(local_140,&DAT_005630d0,
                 *(undefined4 *)(&DAT_005832a8 + (uint)*(byte *)(*param_3 + 0x824) * 4));
    iVar2 = FUN_004d4000(*param_3);
    FUN_0054dd83(local_c0,&DAT_005686f4,iVar2);
    FUN_0054dd83(local_40,&DAT_005686f4,*(undefined4 *)(*param_3 + 0x3c));
    if (*param_3 != 0) {
      bVar1 = true;
      local_204 = 1;
    }
  }
  switch(param_2) {
  case 0:
    FUN_005316f0(param_1,0x1f54,local_204);
    if (bVar1) {
      FUN_0054bb00(param_1,0x1f54,*param_3);
      FUN_00531470(param_1,0x1f54,1);
    }
    else {
      UI_RemoveObjectByKey(param_1,0x52f);
      UI_RemoveObjectByKey(param_1,0x58b);
      UI_RemoveObjectByKey(param_1,0x58c);
    }
    FUN_0052f9b0(param_1,0x534,local_200);
    FUN_0052f9b0(param_1,0x535,local_1c0);
    FUN_0052f9b0(param_1,0x537,local_180);
    FUN_0052f9b0(param_1,0x536,local_140);
    FUN_0052f9b0(param_1,0x530,local_100);
    FUN_0052f9b0(param_1,0x533,local_c0);
    FUN_0052f9b0(param_1,0x531,local_80);
    FUN_0052f9b0(param_1,0x532,local_40);
    FUN_004b0d80(param_1,param_3,0x584,1.98844e-42,1.98984e-42);
    return;
  case 1:
    FUN_005316f0(param_1,0x1f55,local_204);
    if (bVar1) {
      FUN_0054bb00(param_1,0x1f55,*param_3);
      FUN_00531470(param_1,0x1f55,1);
    }
    else {
      UI_RemoveObjectByKey(param_1,0x538);
      UI_RemoveObjectByKey(param_1,0x58d);
      UI_RemoveObjectByKey(param_1,0x58e);
    }
    FUN_0052f9b0(param_1,0x53d,local_200);
    FUN_0052f9b0(param_1,0x53e,local_1c0);
    FUN_0052f9b0(param_1,0x540,local_180);
    FUN_0052f9b0(param_1,0x53f,local_140);
    FUN_0052f9b0(param_1,0x539,local_100);
    FUN_0052f9b0(param_1,0x53c,local_c0);
    FUN_0052f9b0(param_1,0x53a,local_80);
    FUN_0052f9b0(param_1,0x53b,local_40);
    FUN_004b0d80(param_1,param_3,0x585,1.99125e-42,1.99265e-42);
    return;
  case 2:
    FUN_005316f0(param_1,0x1f57,local_204);
    if (bVar1) {
      FUN_0054bb00(param_1,0x1f57,*param_3);
      FUN_00531470(param_1,0x1f57,1);
    }
    else {
      UI_RemoveObjectByKey(param_1,0x541);
      UI_RemoveObjectByKey(param_1,0x58f);
      UI_RemoveObjectByKey(param_1,0x591);
    }
    FUN_0052f9b0(param_1,0x546,local_200);
    FUN_0052f9b0(param_1,0x547,local_1c0);
    FUN_0052f9b0(param_1,0x549,local_180);
    FUN_0052f9b0(param_1,0x548,local_140);
    FUN_0052f9b0(param_1,0x542,local_100);
    FUN_0052f9b0(param_1,0x545,local_c0);
    FUN_0052f9b0(param_1,0x543,local_80);
    FUN_0052f9b0(param_1,0x544,local_40);
    FUN_004b0d80(param_1,param_3,0x587,1.99405e-42,1.99685e-42);
    return;
  case 3:
    FUN_005316f0(param_1,0x1f56,local_204);
    if (bVar1) {
      FUN_0054bb00(param_1,0x1f56,*param_3);
      FUN_00531470(param_1,0x1f56,1);
    }
    else {
      UI_RemoveObjectByKey(param_1,0x54a);
      UI_RemoveObjectByKey(param_1,0x590);
      UI_RemoveObjectByKey(param_1,0x592);
    }
    FUN_0052f9b0(param_1,0x54f,local_200);
    FUN_0052f9b0(param_1,0x550,local_1c0);
    FUN_0052f9b0(param_1,0x552,local_180);
    FUN_0052f9b0(param_1,0x551,local_140);
    FUN_0052f9b0(param_1,0x54b,local_100);
    FUN_0052f9b0(param_1,0x54e,local_c0);
    FUN_0052f9b0(param_1,0x54c,local_80);
    FUN_0052f9b0(param_1,0x54d,local_40);
    FUN_004b0d80(param_1,param_3,0x586,1.99545e-42,1.99825e-42);
    return;
  case 4:
    FUN_005316f0(param_1,0x1f59,local_204);
    if (bVar1) {
      FUN_0054bb00(param_1,0x1f59,*param_3);
      FUN_00531470(param_1,0x1f59,1);
    }
    else {
      UI_RemoveObjectByKey(param_1,0x553);
      UI_RemoveObjectByKey(param_1,0x593);
      UI_RemoveObjectByKey(param_1,0x595);
    }
    FUN_0052f9b0(param_1,0x558,local_200);
    FUN_0052f9b0(param_1,0x559,local_1c0);
    FUN_0052f9b0(param_1,0x55b,local_180);
    FUN_0052f9b0(param_1,0x55a,local_140);
    FUN_0052f9b0(param_1,0x554,local_100);
    FUN_0052f9b0(param_1,0x557,local_c0);
    FUN_0052f9b0(param_1,0x555,local_80);
    FUN_0052f9b0(param_1,0x556,local_40);
    FUN_004b0d80(param_1,param_3,0x58a,1.99965e-42,2.00246e-42);
    return;
  case 5:
    FUN_005316f0(param_1,0x1f58,local_204);
    if (bVar1) {
      FUN_0054bb00(param_1,0x1f58,*param_3);
      FUN_00531470(param_1,0x1f58,1);
    }
    else {
      UI_RemoveObjectByKey(param_1,0x55c);
      UI_RemoveObjectByKey(param_1,0x594);
      UI_RemoveObjectByKey(param_1,0x596);
    }
    FUN_0052f9b0(param_1,0x561,local_200);
    FUN_0052f9b0(param_1,0x562,local_1c0);
    FUN_0052f9b0(param_1,0x564,local_180);
    FUN_0052f9b0(param_1,0x563,local_140);
    FUN_0052f9b0(param_1,0x55d,local_100);
    FUN_0052f9b0(param_1,0x560,local_c0);
    FUN_0052f9b0(param_1,0x55e,local_80);
    FUN_0052f9b0(param_1,0x55f,local_40);
    FUN_004b0d80(param_1,param_3,0x589,2.00105e-42,2.00386e-42);
    return;
  case 6:
    FUN_005316f0(param_1,0x1f5a,local_204);
    if (bVar1) {
      FUN_0054bb00(param_1,0x1f5a,*param_3);
      FUN_00531470(param_1,0x1f5a,1);
    }
    else {
      UI_RemoveObjectByKey(param_1,0x565);
      UI_RemoveObjectByKey(param_1,0x597);
      UI_RemoveObjectByKey(param_1,0x598);
    }
    FUN_0052f9b0(param_1,0x56a,local_200);
    FUN_0052f9b0(param_1,0x56b,local_1c0);
    FUN_0052f9b0(param_1,0x56d,local_180);
    FUN_0052f9b0(param_1,0x56c,local_140);
    FUN_0052f9b0(param_1,0x566,local_100);
    FUN_0052f9b0(param_1,0x569,local_c0);
    FUN_0052f9b0(param_1,0x567,local_80);
    FUN_0052f9b0(param_1,0x568,local_40);
    FUN_004b0d80(param_1,param_3,0x588,2.00526e-42,2.00666e-42);
  }
  return;
}

