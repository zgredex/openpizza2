// rea decompile_all
// name: FUN_004c4bd0
// address: 0x4c4bd0
// body: available
// range: 0x4c4bd0-0x4c4e27 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004c4bd0(void *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  longlong lVar6;
  int local_c [3];
  
  iVar3 = 0;
  local_c[0] = 0;
  local_c[1] = 0;
  local_c[2] = 0;
  iVar4 = 0;
  iVar1 = FUN_004dbf50(DAT_0057dcf4,*(int *)(DAT_0057dcf8 + 0x48));
  FUN_0052fd70(param_1,0x1fe5,iVar1,0);
  iVar1 = FUN_004da760(DAT_0057dcf4,*(int *)(DAT_0057dcf8 + 0x48));
  FUN_0052f080(param_1,0x1fe9,(byte *)s__d____00568834,iVar1);
  FUN_0052f080(param_1,0x1fb8,&DAT_005686f4,*(undefined4 *)((int)DAT_0057dcf4 + 0x10ac));
  FUN_0052f080(param_1,0x1fb9,&DAT_005686f4,*(undefined4 *)((int)DAT_0057dcf4 + 0x10b0));
  FUN_0052f080(param_1,0x1ff4,&DAT_005686f4,*(undefined4 *)((int)DAT_0057dcf4 + 0x10b4));
  FUN_0052f080(param_1,0x1ff5,&DAT_005686f4,*(undefined4 *)((int)DAT_0057dcf4 + 0x10b8));
  iVar1 = 0;
  do {
    iVar2 = Game_GetPlayerBySlot(DAT_0057c670,iVar1);
    if (iVar2 != 0) {
      iVar4 = iVar4 + *(int *)((int)DAT_0057dcf4 + *(int *)(iVar2 + 0x48) * 4 + 0xcb0);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 6);
  FUN_0052f080(param_1,0x1fed,&DAT_005683a4,
               *(undefined4 *)((int)DAT_0057dcf4 + *(int *)(DAT_0057dcf8 + 0x48) * 4 + 0xcb0));
  FUN_0052f080(param_1,0x1ff1,&DAT_005683a4,iVar4);
  piVar5 = &DAT_0056aeb8;
  iVar1 = *(int *)((int)DAT_0057dcf4 + 0x10c4);
  do {
    FUN_00531740(param_1,*piVar5);
    FUN_00531740(param_1,*piVar5 + -1);
    if (iVar3 < iVar1) {
      iVar4 = iVar4 + -1000;
      if (iVar4 < 0) {
        iVar2 = *piVar5;
      }
      else {
        iVar2 = *piVar5 + -1;
      }
      FUN_005316b0(param_1,iVar2);
    }
    piVar5 = piVar5 + 1;
    iVar3 = iVar3 + 1;
  } while ((int)piVar5 < 0x56aecc);
  iVar1 = FUN_004db030(DAT_0057dcf4,local_c,local_c + 1,local_c + 2);
  iVar3 = 0;
  piVar5 = &DAT_0056aecc;
  do {
    if (iVar3 < iVar1) {
      FUN_005316b0(param_1,*piVar5);
    }
    else {
      FUN_00531740(param_1,*piVar5);
    }
    piVar5 = piVar5 + 1;
    iVar3 = iVar3 + 1;
  } while ((int)piVar5 < 0x56aef4);
  lVar6 = __ftol();
  FUN_0052f080(param_1,0x1fcf,(byte *)s__d____00568834,(int)lVar6);
  lVar6 = __ftol();
  FUN_0052f080(param_1,0x1fd1,(byte *)s__d____00568834,(int)lVar6);
  lVar6 = __ftol();
  FUN_0052f080(param_1,0x1fd0,(byte *)s__d____00568834,(int)lVar6);
  return;
}

