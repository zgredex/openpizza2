// rea decompile_all
// name: FUN_004c9dd0
// address: 0x4c9dd0
// body: available
// range: 0x4c9dd0-0x4ca064 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004c9dd0(void *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  FUN_0052f9b0(param_1,0x4d1,DAT_00580ba8);
  FUN_0052f9b0(param_1,0x4d2,DAT_005811ac);
  FUN_0052f9b0(param_1,0x4d3,DAT_00581c9c);
  FUN_0052f9b0(param_1,0x4d4,DAT_00580eb0);
  FUN_0052f9b0(param_1,0x4d5,DAT_0058226c);
  iVar3 = 0;
  piVar2 = &DAT_0057de18;
  iVar4 = 0x4fa;
  do {
    iVar1 = FUN_00488be0(DAT_0057c670,iVar3);
    if (iVar1 != 0) {
      FUN_0052f9b0(param_1,iVar4 + -0x24,DAT_00581cfc);
      FUN_0052f9b0(param_1,iVar4,DAT_00581cfc);
      FUN_0052f9b0(param_1,iVar4 + 0x24,DAT_00581cfc);
      FUN_0052f9b0(param_1,iVar4 + 0x48,DAT_00581cfc);
      FUN_0052f080(param_1,iVar4 + -0x1f,&DAT_005686f4,*(undefined4 *)(*piVar2 + 0x7c));
      FUN_0052f080(param_1,iVar4 + 5,&DAT_005686f4,*(undefined4 *)(*piVar2 + 0x84));
      FUN_0052f080(param_1,iVar4 + 0x29,&DAT_005686f4,*(undefined4 *)(*piVar2 + 0x8c));
      FUN_0052f080(param_1,iVar4 + 0x4d,&DAT_005686f4,*(undefined4 *)(*piVar2 + 0x94));
      FUN_0052f9b0(param_1,iVar4 + -0x23,DAT_00582f7c);
      FUN_0052f9b0(param_1,iVar4 + 1,DAT_00582f7c);
      FUN_0052f9b0(param_1,iVar4 + 0x25,DAT_00582f7c);
      FUN_0052f9b0(param_1,iVar4 + 0x49,DAT_00582f7c);
      FUN_0052f080(param_1,iVar4 + -0x20,&DAT_005686f4,*(undefined4 *)(*piVar2 + 0x80));
      FUN_0052f080(param_1,iVar4 + 4,&DAT_005686f4,*(undefined4 *)(*piVar2 + 0x88));
      FUN_0052f080(param_1,iVar4 + 0x28,&DAT_005686f4,*(undefined4 *)(*piVar2 + 0x90));
      FUN_0052f080(param_1,iVar4 + 0x4c,&DAT_005686f4,*(undefined4 *)(*piVar2 + 0x98));
      FUN_0052f9b0(param_1,iVar4 + -0x22,DAT_00581c74);
      FUN_0052f9b0(param_1,iVar4 + 2,DAT_00581c74);
      FUN_0052f9b0(param_1,iVar4 + 0x26,DAT_00581c74);
      FUN_0052f9b0(param_1,iVar4 + 0x4a,DAT_00581c74);
      FUN_0052f080(param_1,iVar4 + -0x21,&DAT_005686f4,*(undefined4 *)(*piVar2 + 0x160));
      FUN_0052f080(param_1,iVar4 + 3,&DAT_005686f4,*(undefined4 *)(*piVar2 + 0x164));
      FUN_0052f080(param_1,iVar4 + 0x27,&DAT_005686f4,*(undefined4 *)(*piVar2 + 0x168));
      FUN_0052f080(param_1,iVar4 + 0x4b,&DAT_005686f4,*(undefined4 *)(*piVar2 + 0x16c));
    }
    piVar2 = piVar2 + 1;
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + 6;
  } while ((int)piVar2 < 0x57de30);
  return;
}

