// rea decompile_all
// name: FUN_004aeda0
// address: 0x4aeda0
// body: available
// range: 0x4aeda0-0x4aef82 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004aeda0(void *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_210;
  int local_20c;
  int local_208;
  int local_204;
  char local_200 [256];
  int local_100 [64];
  
  iVar1 = 0x3e9;
  do {
    FUN_0052ff50(param_1,iVar1,(uint)(iVar1 + -0x3e9 == DAT_0057d64c - DAT_0057d648));
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x3f6);
  FUN_0052f9b0(param_1,0x3fd,*(undefined4 *)(&DAT_0058404c + DAT_0057d64c * 4));
  FUN_0052f9b0(param_1,0x3fe,*(undefined4 *)(&DAT_00583db8 + DAT_0057d64c * 4));
  FUN_005314a0(param_1,0x42c,&local_20c,&local_208);
  FUN_005311a0(param_1,0x42c);
  FUN_0054dd83(local_200,(byte *)s__s_bik_00569bfc,s_stat_wohnhaus_b_00569c2c + DAT_0057d64c * 0x20)
  ;
  FUN_00531bb0(param_1,0x42c,local_20c,local_208,local_200,(undefined4 *)0x0);
  FUN_00531c40(param_1,0x42c,1);
  FUN_0054a2a0(DAT_0057ba0c,DAT_0057d64c);
  iVar1 = 50000;
  do {
    FUN_005311a0(param_1,iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0xc390);
  if (DAT_0057d64c < 0x11) {
    FUN_005314a0(param_1,0x42e,&local_20c,&local_208);
    FUN_004aecc0(local_100);
    local_210 = 0;
    local_204 = 50000;
    piVar3 = local_100;
    do {
      iVar2 = 0;
      iVar1 = local_204;
      local_204 = local_204 + 8;
      do {
        FUN_0054dd83(local_200,(byte *)s_BEWERTUNG___02d_spr_00569f68,(*piVar3 * 0x10 + 0x32) / 100)
        ;
        FUN_00531850(param_1,iVar1,DAT_0057d640 * iVar2 + local_20c,
                     DAT_0057d644 * local_210 + local_208,local_200);
        iVar1 = iVar1 + 1;
        iVar2 = iVar2 + 1;
        piVar3 = piVar3 + 1;
      } while (iVar2 < 8);
      local_210 = local_210 + 1;
    } while (local_210 < 8);
  }
  return;
}

