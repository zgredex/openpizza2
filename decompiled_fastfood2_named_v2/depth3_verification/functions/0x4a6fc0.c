// rea decompile_all
// name: FUN_004a6fc0
// address: 0x4a6fc0
// body: available
// range: 0x4a6fc0-0x4a714d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004a6fc0(void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int local_28;
  int local_24;
  undefined1 local_20 [32];
  
  if (DAT_0057d27c != 0) {
    switch(*(undefined4 *)(DAT_0057d27c + 4)) {
    default:
      DAT_0057d294 = 0;
      uVar2 = DAT_00582020;
      break;
    case 0x15:
    case 0x1e:
      DAT_0057d294 = 1;
      uVar2 = DAT_00582008;
      break;
    case 0x16:
    case 0x1f:
      DAT_0057d294 = 2;
      uVar2 = DAT_00582f40;
    }
    FUN_0054dd83(local_20,&DAT_005630d0,uVar2);
    if (DAT_0057d280 == 0) {
      iVar3 = 1;
      FUN_0052f9b0(param_1,0x4f6,local_20);
      FUN_0052f9b0(param_1,0x1f41,DAT_00582e4c);
      uVar2 = DAT_005816bc;
    }
    else {
      iVar3 = 3;
      FUN_0052f9b0(param_1,0x4f6,DAT_00582e4c);
      FUN_0052f9b0(param_1,0x1f41,local_20);
      uVar2 = DAT_005816b0;
    }
    FUN_0052f9b0(param_1,0x1f4d,uVar2);
    piVar4 = (int *)0x0;
    iVar1 = FUN_00482820(DAT_0057c670);
    Game_ComputeTradeOffers(DAT_0057d290,DAT_0057d27c,iVar3,&local_28,&local_24,iVar1,piVar4);
    FUN_0054dd83(local_20,&DAT_005683a4,local_28);
    FUN_0052f9b0(param_1,0x4f9,local_20);
    *(int *)(DAT_0057c670 + 0x218) = DAT_0057d27c;
    FUN_004d23b0(DAT_0057d27c);
    FUN_004bf120(param_1,*(int *)(DAT_0057d27c + 0x20),1,0x1f57,-1,DAT_0057d27c);
  }
  return;
}

