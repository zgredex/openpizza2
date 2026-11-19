// rea decompile_all
// name: FUN_0049f3b0
// address: 0x49f3b0
// body: available
// range: 0x49f3b0-0x49f4f8 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __cdecl FUN_0049f3b0(void *param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char local_100 [256];
  
  iVar4 = FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  if (*(int *)(iVar4 + 0x1154) == 0) {
    iVar4 = 100;
  }
  else {
    iVar4 = 100 - (*(int *)(iVar4 + 0x114c) * 100) / *(int *)(iVar4 + 0x1154);
  }
  if (*(int *)(*(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4) + 0x1d4) ==
      param_2) {
    iVar4 = 100;
  }
  FUN_0049d280(param_1);
  iVar4 = *(int *)(param_2 + 0x5c) * iVar4;
  iVar5 = iVar4 * 0x51eb851f;
  iVar4 = iVar4 / 100;
  iVar6 = 0;
  if (0 < iVar4) {
    do {
      iVar5 = FUN_004017f0((void *)(param_2 + 0x48),iVar6,(int *)0x0);
      if (*(char *)(iVar5 + 0x11) == '\0') {
        bVar1 = *(byte *)(iVar5 + 0x10);
        iVar2 = *(int *)(iVar5 + 0xc);
        iVar3 = *(int *)(iVar5 + 8);
        FUN_0054dd83(local_100,(byte *)s_zutaten_ZA_02dA__02d_spr_00568948,*(byte *)(iVar5 + 4) + 1)
        ;
        FUN_00531850(param_1,iVar6 + 100000,iVar3,iVar2,local_100);
        iVar5 = FUN_00531960(param_1,iVar6 + 100000,(uint)bVar1);
        *(undefined4 *)((int)param_1 + 0xe0) = 1;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar4);
  }
  *(undefined4 *)((int)param_1 + 0xe0) = 1;
  return iVar5;
}

