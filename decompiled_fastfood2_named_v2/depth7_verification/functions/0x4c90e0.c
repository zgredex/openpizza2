// rea decompile_all
// name: FUN_004c90e0
// address: 0x4c90e0
// body: available
// range: 0x4c90e0-0x4c9387 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004c90e0(void *param_1)

{
  undefined4 uVar1;
  void *this;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  this = param_1;
  FUN_0052f9b0(param_1,0x4d1,DAT_00581a58);
  FUN_0052f9b0(param_1,0x4d2,DAT_00581b6c);
  FUN_0052f9b0(param_1,0x4d3,DAT_0058100c);
  FUN_0052f9b0(param_1,0x4d4,DAT_00581930);
  FUN_0052f9b0(param_1,0x4d5,DAT_00581d60);
  param_1 = (void *)0x0;
  piVar3 = &DAT_0057de18;
  iVar4 = 0x4db;
  do {
    iVar2 = FUN_00488be0(DAT_0057c670,(int)param_1);
    if (iVar2 != 0) {
      uVar1 = *(undefined4 *)(*piVar3 + 0x11c);
      FUN_0052f9b0(this,iVar4 + -5,DAT_005818d8);
      FUN_0052f080(this,iVar4,&DAT_005686f4,*(undefined4 *)(*piVar3 + 0xfc));
      FUN_0052f9b0(this,iVar4 + 0x1f,DAT_00581648);
      FUN_0052f080(this,iVar4 + 0x24,&DAT_005686f4,*(undefined4 *)(*piVar3 + 0x108));
      FUN_0052f9b0(this,iVar4 + 0x43,DAT_00580fe0);
      FUN_0052f080(this,iVar4 + 0x48,&DAT_005686f4,*(undefined4 *)(*piVar3 + 0x114));
      FUN_0052f9b0(this,iVar4 + 0x67,DAT_00582be4);
      FUN_0052f080(this,iVar4 + 0x6c,&DAT_005686f4,uVar1);
      FUN_0052f9b0(this,iVar4 + -4,DAT_00582710);
      FUN_0052f080(this,iVar4 + -1,&DAT_005686f4,*(undefined4 *)(*piVar3 + 0x100));
      FUN_0052f9b0(this,iVar4 + 0x20,DAT_00580c88);
      FUN_0052f080(this,iVar4 + 0x23,&DAT_005686f4,*(undefined4 *)(*piVar3 + 0x10c));
      FUN_0052f9b0(this,iVar4 + 0x44,DAT_00581a5c);
      FUN_0052f080(this,iVar4 + 0x47,&DAT_005686f4,*(undefined4 *)(*piVar3 + 0x118));
      FUN_0052f9b0(this,iVar4 + 0x68,DAT_00582e4c);
      FUN_0052f9b0(this,iVar4 + 0x6b,DAT_00582e4c);
      FUN_0052f9b0(this,iVar4 + -3,DAT_00582350);
      FUN_0052f080(this,iVar4 + -2,&DAT_005686f4,*(undefined4 *)(*piVar3 + 0x104));
      FUN_0052f9b0(this,iVar4 + 0x21,DAT_00580c04);
      FUN_0052f080(this,iVar4 + 0x22,&DAT_005686f4,*(undefined4 *)(*piVar3 + 0x110));
      FUN_0052f9b0(this,iVar4 + 0x45,DAT_00582e4c);
      FUN_0052f9b0(this,iVar4 + 0x46,DAT_00582e4c);
      FUN_0052f9b0(this,iVar4 + 0x69,DAT_00582e4c);
      FUN_0052f9b0(this,iVar4 + 0x6a,DAT_00582e4c);
    }
    piVar3 = piVar3 + 1;
    param_1 = (void *)((int)param_1 + 1);
    iVar4 = iVar4 + 6;
  } while ((int)piVar3 < 0x57de30);
  return;
}

