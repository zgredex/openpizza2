// rea decompile_all
// name: FUN_004a81f0
// address: 0x4a81f0
// body: available
// range: 0x4a81f0-0x4a844b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004a81f0(void *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  longlong lVar5;
  undefined4 uVar6;
  undefined1 local_20 [32];
  
  FUN_004a8030(&DAT_0057d29c,&DAT_0057d404);
  IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),(int *)0x0);
  iVar1 = *(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  DAT_0057d56c = (void *)FUN_004e34e0(iVar1);
  bVar4 = *(int *)((int)DAT_0057d56c + 4) != 0;
  if (bVar4) {
    uVar6 = DAT_005820c8;
  }
  else {
    uVar6 = DAT_00580f1c;
  }
  DAT_0057d298 = !bVar4;
  FUN_0052f830(param_1,0x1f43,uVar6);
  FUN_0052f830(param_1,0x482,
               *(undefined4 *)
                (&DAT_00583504 + (&DAT_0057d404)[*(int *)((int)DAT_0057d56c + 0x10)] * 4));
  FUN_0052ff50(param_1,0x43a,*(uint *)((int)DAT_0057d56c + 0x14) & 8);
  FUN_0052ff50(param_1,0x43b,*(uint *)((int)DAT_0057d56c + 0x14) & 4);
  FUN_0052ff50(param_1,0x43c,*(uint *)((int)DAT_0057d56c + 0x14) & 2);
  FUN_0052ff50(param_1,0x43d,*(uint *)((int)DAT_0057d56c + 0x14) & 1);
  if (*(int *)((int)DAT_0057d56c + 0x18) == 0) {
    uVar6 = DAT_00580f68;
  }
  else {
    DAT_0057d570 = Personnel_GetTrainingLevel(*(int *)((int)DAT_0057d56c + 0x18));
    uVar6 = *(undefined4 *)(&DAT_00583540 + *(int *)((int)DAT_0057d56c + 0x18) * 4);
  }
  FUN_0052f830(param_1,0x48b,uVar6);
  if (*(int *)((int)DAT_0057d56c + 0x1c) == -1) {
    iVar2 = DAT_00582634;
  }
  else {
    iVar2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((int)DAT_0057d56c + 0x1c));
    iVar2 = iVar2 + 8;
  }
  FUN_0052f830(param_1,0x48e,iVar2);
  FUN_0052fd00(param_1,0x42c,0,10000,0);
  FUN_0052fd70(param_1,0x42c,*(undefined4 *)((int)DAT_0057d56c + 0x20),0);
  FUN_0052fce0(param_1,0x42c,1);
  FUN_0054dd83(local_20,&DAT_005683a4,*(undefined4 *)((int)DAT_0057d56c + 0x20));
  FUN_0052f9b0(param_1,0x490,local_20);
  iVar2 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670);
  lVar5 = FUN_0050fba0(DAT_0057d56c,iVar2);
  FUN_0054dd83(local_20,&DAT_005686f4,(int)lVar5);
  FUN_0052f9b0(param_1,0x491,local_20);
  iVar2 = 0;
  do {
    iVar3 = FUN_0050f870(DAT_0057d56c,*(int *)(iVar1 + 0x48),iVar2);
    iVar3 = Math_PiecewiseLinear(iVar3);
    FUN_004a80e0(param_1,0x519,iVar2,iVar3,DAT_00582858);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 8);
  return;
}

