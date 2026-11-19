// rea decompile_all
// name: FUN_004b5110
// address: 0x4b5110
// body: available
// range: 0x4b5110-0x4b5405 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004b5110(void *param_1)

{
  undefined8 uVar1;
  int iVar2;
  undefined4 uVar3;
  bool bVar4;
  
  FUN_00531470(param_1,0x411,0);
  FUN_00531470(param_1,0x412,0);
  FUN_00531470(param_1,0x413,0);
  FUN_00531470(param_1,0x414,0);
  FUN_00531470(param_1,0x415,0);
  FUN_00532310(param_1,&LAB_004b50f0,0);
  FUN_00532a30(param_1,0x3f5,0x131);
  FUN_00532a30(param_1,0x3f6,0x133);
  if (*(int *)(*(int *)(*(int *)((int)DAT_0057c670 + 0x224) + 0xac) + 0xd0) == 0) {
    FUN_00482f40(DAT_0057c670,'\x01');
  }
  DAT_0057d6ac = *(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  if (DAT_0056a800 != -1) {
    UI_Group_RemoveAt(param_1,DAT_0056a800);
  }
  iVar2 = FUN_00486e20(DAT_0057c670,*(int *)((int)DAT_0057c670 + 0x2f4),-1);
  if (iVar2 == 0) {
    DAT_0056a800 = FUN_00532330(param_1,0,4,0x3fd);
    FUN_0052ff50(param_1,0x3fb,0);
    FUN_005316f0(param_1,0x3fb,0);
  }
  else {
    DAT_0056a800 = FUN_00532330(param_1,0,5,0x3fd);
    if ((*(int *)((int)DAT_0057c670 + 0x9c) == 0) &&
       (iVar2 = *(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200),
       *(int *)(iVar2 + 0x15c) != 0)) {
      uVar3 = FUN_004017f0((void *)(iVar2 + 0x148),0,(int *)0x0);
      *(undefined4 *)((int)DAT_0057c670 + 0x9c) = uVar3;
      FUN_00547e70(DAT_0057ba0c);
    }
  }
  FUN_00488a10(DAT_0057c670,param_1);
  FUN_004a66d0(param_1,0x1f46,
               *(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200));
  iVar2 = *(int *)((int)DAT_0057c670 + 0x9c);
  if (iVar2 == 0) {
    if (*(int *)(DAT_0057d6ac + 0x15c) < 1) {
      FUN_0052f9b0(param_1,0x40f,DAT_00581328);
      DAT_0057d6a8 = 0xffffffff;
      goto LAB_004b5342;
    }
    DAT_0057d6a8 = 0;
    iVar2 = FUN_004017f0((void *)(DAT_0057d6ac + 0x148),0,(int *)0x0);
  }
  else {
    DAT_0057d6a8 = *(undefined4 *)(iVar2 + 0x3c);
  }
  FUN_0052f9b0(param_1,0x40f,iVar2 + 4);
LAB_004b5342:
  bVar4 = *(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x290) * 4 + 0x298) != 5;
  if (bVar4) {
    FUN_005316b0(param_1,0x3f5);
    FUN_005316b0(param_1,0x3f6);
  }
  else {
    FUN_0052f9b0(param_1,0x40f,DAT_005819dc);
    FUN_00531740(param_1,0x3f5);
    FUN_00531740(param_1,0x3f6);
  }
  FUN_00531470(param_1,0x40c,(uint)bVar4);
  FUN_0054bcc0(*(void **)((int)DAT_0057c670 + 0x2d9c),param_1,0x1f42);
  uVar1 = *(undefined8 *)
           (*(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200) + 0x108);
  FUN_0054bf50(*(void **)((int)DAT_0057c670 + 0x2d9c),(int)uVar1,(int)((ulonglong)uVar1 >> 0x20),0);
  iVar2 = 0x1f47;
  do {
    FUN_00531740(param_1,iVar2);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x1fa6);
  return;
}

