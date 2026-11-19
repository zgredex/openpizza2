// rea decompile_all
// name: FUN_00492b20
// address: 0x492b20
// body: available
// range: 0x492b20-0x492d88 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_00492b20(void *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  longlong lVar4;
  undefined1 local_20 [32];
  
  DAT_0057c6cc = *(int *)(DAT_0057c670 + 0x9c);
  FUN_0052fd00(param_1,0x43a,0,100,0);
  if (*(int *)(DAT_0057c6cc + 0x14c4) == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = *(undefined4 *)(DAT_0057c6cc + 0x14c8);
  }
  FUN_0052fd70(param_1,0x43a,uVar2,0);
  FUN_0052fd00(param_1,3000,0,100,0);
  if (*(int *)(DAT_0057c6cc + 0x14c4) == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = *(undefined4 *)(DAT_0057c6cc + 0x14cc);
  }
  FUN_0052fd70(param_1,3000,uVar2,0);
  FUN_0052fd00(param_1,0x43b,-0x32,0x32,0);
  if (*(int *)(DAT_0057c6cc + 0x14c4) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(DAT_0057c6cc + 0x14d0);
  }
  FUN_0052fd70(param_1,0x43b,uVar2,0);
  FUN_0052fce0(param_1,0x43b,1);
  FUN_0052fd00(param_1,0x43c,0,0x32,0);
  FUN_0052fd70(param_1,0x43c,*(undefined4 *)(DAT_0057c6cc + 0x14d4),0);
  FUN_0052fce0(param_1,0x43c,1);
  FUN_0052fd00(param_1,0x43d,-0x32,0x32,0);
  if (*(int *)(DAT_0057c6cc + 0x14c4) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(DAT_0057c6cc + 0x14c0);
  }
  FUN_0052fd70(param_1,0x43d,uVar2,0);
  FUN_0052fce0(param_1,0x43d,1);
  FUN_0047ac10(DAT_0057c6cc);
  lVar4 = __ftol();
  FUN_0054dd83(local_20,&DAT_005686f8,(int)lVar4);
  FUN_0052f9b0(param_1,0x4f9,local_20);
  iVar3 = Rating_ComputePenalty(DAT_0057c6cc);
  FUN_0054dd83(local_20,&DAT_005686f4,iVar3);
  FUN_0052f9b0(param_1,0x4fa,local_20);
  FUN_0047ab20(DAT_0057c6cc);
  lVar4 = __ftol();
  FUN_0054dd83(local_20,&DAT_005686f8,(int)lVar4);
  FUN_0052f9b0(param_1,0x1f43,local_20);
  iVar3 = FUN_0047aba0(DAT_0057c6cc);
  FUN_0054dd83(local_20,(byte *)s___02d_005686ec,iVar3);
  FUN_0052f9b0(param_1,0x4f8,local_20);
  uVar1 = *(uint *)(DAT_0057c6cc + 0x1894);
  FUN_0052ff50(param_1,0x436,uVar1 & 2);
  FUN_0052ff50(param_1,0x438,uVar1 & 0x20);
  FUN_00492ae0(param_1);
  return;
}

