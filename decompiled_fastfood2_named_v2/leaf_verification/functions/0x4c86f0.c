// rea decompile_all
// name: FUN_004c86f0
// address: 0x4c86f0
// body: available
// range: 0x4c86f0-0x4c8985 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004c86f0(void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *local_108;
  char local_100 [256];
  
  FUN_0048d530(DAT_0057c670,&DAT_0057de00);
  iVar4 = 0x4be;
  local_108 = &DAT_0057de00;
  iVar3 = 0x58f;
  do {
    iVar1 = Game_GetPlayerBySlot(DAT_0057c670,iVar3 + -0x58f);
    if (iVar1 == 0) {
      FUN_0052f9b0(param_1,iVar4,DAT_00582e4c);
      FUN_0052f9b0(param_1,iVar4 + 2,DAT_00582e4c);
      FUN_00531740(param_1,iVar3);
      FUN_00531740(param_1,iVar4 + 1);
      FUN_00531740(param_1,iVar3 + -0xd7);
      *local_108 = 0;
    }
    else {
      FUN_0052f9b0(param_1,iVar4,iVar1 + 8);
      FUN_0052f080(param_1,iVar4 + 2,&DAT_005686f4,*(undefined4 *)(*local_108 + 0x11c));
      FUN_0054dd83(local_100,(byte *)s_LOGOS__0_d_spr_00568eb8,*(int *)(iVar1 + 0x1e0) + 1);
      FUN_00531910(param_1,iVar3,local_100);
      FUN_0052ff50(param_1,iVar3 + -0xd7,(uint)(byte)s__s__s_d_0056acc0[iVar3 + 1]);
      FUN_0052f910(param_1,iVar4,*(undefined4 *)(iVar1 + 0x1dc));
      FUN_0052f910(param_1,iVar4 + 1,*(undefined4 *)(iVar1 + 0x1dc));
      FUN_0052f910(param_1,iVar4 + 2,*(undefined4 *)(iVar1 + 0x1dc));
    }
    iVar4 = iVar4 + 3;
    local_108 = local_108 + 1;
    iVar1 = iVar3 + -0x58e;
    iVar3 = iVar3 + 1;
  } while (iVar1 < 6);
  FUN_004c89b0(param_1);
  FUN_0052f9b0(param_1,0x429,DAT_00582e4c);
  FUN_0052f800(param_1,0x599,1);
  FUN_00531470(param_1,0x599,0);
  switch(DAT_0057c5c0) {
  case 1:
    FUN_0052f830(param_1,0x597,DAT_00581838);
    uVar2 = DAT_00581010;
    break;
  case 2:
    FUN_0052f830(param_1,0x597,DAT_00581bfc);
    uVar2 = DAT_00582848;
    break;
  default:
    goto switchD_004c8892_caseD_3;
  case 4:
    FUN_0052f830(param_1,0x597,DAT_00582ea4);
    uVar2 = DAT_00581010;
    break;
  case 5:
    FUN_0052f830(param_1,0x597,DAT_00582ea4);
    uVar2 = DAT_00581010;
    goto LAB_004c893c;
  case 6:
    FUN_0052f830(param_1,0x597,DAT_00581838);
    uVar2 = DAT_00581010;
    break;
  case 7:
    FUN_0052f830(param_1,0x597,DAT_00581990);
    uVar2 = DAT_00581074;
LAB_004c893c:
  }
  FUN_0052f830(param_1,0x598,uVar2);
switchD_004c8892_caseD_3:
  FUN_004c86a0(param_1);
  FUN_0052f080(param_1,0x583,(byte *)s__d__d_00568ef8,
               (uint)*(byte *)(*(int *)((int)DAT_0057c670 + 0x94) + 8));
  return;
}

