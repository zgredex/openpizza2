// rea decompile_all
// name: FUN_004c9610
// address: 0x4c9610
// body: available
// range: 0x4c9610-0x4c98c9 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004c9610(void *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  FUN_0052f9b0(param_1,0x4d1,DAT_00581258);
  FUN_0052f9b0(param_1,0x4d2,DAT_00581c10);
  FUN_0052f9b0(param_1,0x4d3,DAT_005816dc);
  FUN_0052f9b0(param_1,0x4d4,DAT_00582d74);
  FUN_0052f9b0(param_1,0x4d5,DAT_00580d00);
  iVar3 = 0;
  piVar2 = &DAT_0057de18;
  iVar4 = 0x4fa;
  do {
    iVar1 = FUN_00488be0(DAT_0057c670,iVar3);
    if (iVar1 != 0) {
      FUN_0052f9b0(param_1,iVar4 + -0x24,DAT_00581660);
      FUN_0052f9b0(param_1,iVar4,DAT_00582bdc);
      FUN_0052f9b0(param_1,iVar4 + 0x24,DAT_00582e74);
      FUN_0052f9b0(param_1,iVar4 + 0x48,DAT_00582924);
      FUN_0052f080(param_1,iVar4 + -0x1f,&DAT_005686f4,*(undefined4 *)(*piVar2 + 0x20));
      if (*(int *)(*piVar2 + 0x28) < 1) {
        uVar5 = DAT_005817a4;
      }
      else {
        uVar5 = DAT_00582a0c;
      }
      FUN_0052f9b0(param_1,iVar4 + 5,uVar5);
      FUN_0052f080(param_1,iVar4 + 0x29,&DAT_005686f4,*(undefined4 *)(*piVar2 + 0x30));
      if (*(int *)(*piVar2 + 0x38) == 0) {
        uVar5 = DAT_005817a4;
      }
      else {
        uVar5 = DAT_00582a0c;
      }
      FUN_0052f9b0(param_1,iVar4 + 0x4d,uVar5);
      FUN_0052f9b0(param_1,iVar4 + -0x23,DAT_00582920);
      FUN_0052f9b0(param_1,iVar4 + 1,DAT_005824cc);
      FUN_0052f9b0(param_1,iVar4 + 0x25,DAT_00582a84);
      FUN_0052f9b0(param_1,iVar4 + 0x49,DAT_00582914);
      FUN_0052f080(param_1,iVar4 + -0x20,&DAT_005686f4,*(undefined4 *)(*piVar2 + 0x24));
      FUN_0052f080(param_1,iVar4 + 4,&DAT_005683a4,*(undefined4 *)(*piVar2 + 0x2c));
      FUN_0052f080(param_1,iVar4 + 0x28,&DAT_005686f4,*(undefined4 *)(*piVar2 + 0x34));
      if (*(int *)(*piVar2 + 0x38) == 0) {
        uVar5 = DAT_005817a4;
      }
      else {
        uVar5 = DAT_00582a0c;
      }
      FUN_0052f9b0(param_1,iVar4 + 0x4c,uVar5);
      FUN_0052f9b0(param_1,iVar4 + -0x22,DAT_00581c74);
      FUN_0052f9b0(param_1,iVar4 + 2,DAT_00581c74);
      FUN_0052f9b0(param_1,iVar4 + 0x26,DAT_00581c74);
      FUN_0052f9b0(param_1,iVar4 + 0x4a,DAT_00581c74);
      FUN_0052f080(param_1,iVar4 + -0x21,&DAT_005686f4,*(undefined4 *)(*piVar2 + 0x130));
      FUN_0052f080(param_1,iVar4 + 3,&DAT_005686f4,*(undefined4 *)(*piVar2 + 0x134));
      FUN_0052f080(param_1,iVar4 + 0x27,&DAT_005686f4,*(undefined4 *)(*piVar2 + 0x138));
      FUN_0052f080(param_1,iVar4 + 0x4b,&DAT_005686f4,*(undefined4 *)(*piVar2 + 0x13c));
    }
    piVar2 = piVar2 + 1;
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + 6;
  } while ((int)piVar2 < 0x57de30);
  return;
}

