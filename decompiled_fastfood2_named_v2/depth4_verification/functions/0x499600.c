// rea decompile_all
// name: FUN_00499600
// address: 0x499600
// body: available
// range: 0x499600-0x499784 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_00499600(void *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  undefined1 local_40 [64];
  
  iVar3 = 0;
  iVar4 = 1;
  iVar1 = DAT_00568914;
  if (((DAT_00568914 < 0) && (iVar1 = param_2, param_2 < 0)) ||
     (iVar3 = FUN_004017f0(DAT_0057ca20,iVar1,(int *)0x0), iVar3 == 0)) {
    iVar4 = 0;
  }
  FUN_005316f0(param_1,0x4fa,iVar4);
  FUN_005316f0(param_1,0x4f9,iVar4);
  FUN_005316f0(param_1,0x4e9,iVar4);
  FUN_005316f0(param_1,0x4ea,iVar4);
  FUN_005316f0(param_1,0x449,iVar4);
  FUN_005316f0(param_1,0x44c,iVar4);
  if (iVar3 == 0) {
    return;
  }
  iVar1 = *(int *)(iVar3 + 0xac + DAT_0057ca28 * 4);
  FUN_0052f9b0(param_1,0x4fa,iVar3 + 0x88);
  FUN_0054dd83(local_40,(byte *)s__0_2f___005688b0,
               SUB84(*(double *)(iVar3 + 0xc0) * (double)iVar1 * 0.001,0));
  FUN_0052f9b0(param_1,0x4e9,local_40);
  lVar5 = __ftol();
  FUN_0054dd83(local_40,&DAT_00568930,(int)lVar5);
  FUN_0052f9b0(param_1,0x4ea,local_40);
  switch(DAT_0057ca28) {
  case 0:
    uVar2 = DAT_00582094;
    goto LAB_0049975a;
  case 1:
    uVar2 = DAT_0058175c;
    break;
  case 2:
    uVar2 = DAT_00582004;
    break;
  case 3:
    uVar2 = DAT_00582568;
LAB_0049975a:
    break;
  default:
    goto switchD_00499721_default;
  }
  FUN_0054dd83(local_40,&DAT_005630d0,uVar2);
switchD_00499721_default:
  FUN_0052f9b0(param_1,0x4f9,local_40);
  return;
}

