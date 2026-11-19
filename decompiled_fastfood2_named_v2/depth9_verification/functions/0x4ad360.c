// rea decompile_all
// name: FUN_004ad360
// address: 0x4ad360
// body: available
// range: 0x4ad360-0x4ad4c5 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004ad360(void *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  undefined1 local_40 [64];
  
  piVar2 = &DAT_005695d0;
  do {
    FUN_00531740(param_1,*piVar2);
    piVar2 = piVar2 + 1;
  } while ((int)piVar2 < 0x5695f4);
  switch(DAT_0057d62c) {
  case 0:
  case 1:
  case 3:
  case 4:
    iVar3 = 0;
    do {
      FUN_0054dd83(local_40,&DAT_005630d0,*(undefined4 *)((int)&DAT_005834d4 + iVar3));
      FUN_0052f9b0(param_1,*(int *)((int)&DAT_005695ac + iVar3),local_40);
      FUN_005316b0(param_1,*(int *)((int)&DAT_005695d0 + iVar3));
      iVar3 = iVar3 + 4;
    } while (iVar3 < 0x24);
    if ((DAT_0057d62c == 0) || (DAT_0057d62c == 3)) {
      uVar1 = DAT_00582394;
      break;
    }
    uVar1 = DAT_00581718;
    goto LAB_004ad4ab;
  case 2:
    iVar3 = 0;
    do {
      FUN_0052f9b0(param_1,*(int *)((int)&DAT_005695ac + iVar3),
                   *(undefined4 *)((int)&DAT_00583298 + iVar3));
      FUN_005316b0(param_1,*(int *)((int)&DAT_005695d0 + iVar3));
      iVar3 = iVar3 + 4;
    } while (iVar3 < 0x10);
    piVar2 = &DAT_005695bc;
    do {
      FUN_0052f9b0(param_1,*piVar2,DAT_00582e4c);
      piVar2 = piVar2 + 1;
    } while ((int)piVar2 < 0x5695d0);
    uVar1 = DAT_0058192c;
    break;
  case 5:
    iVar3 = 0;
    do {
      FUN_0052f9b0(param_1,*(int *)((int)&DAT_005695ac + iVar3),
                   *(undefined4 *)((int)&DAT_005832b8 + iVar3));
      FUN_005316b0(param_1,*(int *)((int)&DAT_005695d0 + iVar3));
      iVar3 = iVar3 + 4;
    } while (iVar3 < 0x1c);
    piVar2 = &DAT_005695c8;
    do {
      FUN_0052f9b0(param_1,*piVar2,DAT_00582e4c);
      piVar2 = piVar2 + 1;
    } while ((int)piVar2 < 0x5695d0);
    uVar1 = DAT_005828bc;
    break;
  default:
    goto switchD_004ad391_default;
  }
LAB_004ad4ab:
  FUN_0052f9b0(param_1,0x862,uVar1);
switchD_004ad391_default:
  FUN_004ad4e0(param_1);
  return;
}

