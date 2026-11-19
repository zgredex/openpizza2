// rea decompile_all
// name: FUN_0054e9a7
// address: 0x54e9a7
// body: available
// range: 0x54e9a7-0x54ea8e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint __cdecl FUN_0054e9a7(char *param_1,uint param_2,uint param_3,int *param_4)

{
  int *piVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  
  piVar1 = param_4;
  pcVar6 = (char *)(param_2 * param_3);
  if (pcVar6 == (char *)0x0) {
    return 0;
  }
  pcVar5 = param_1;
  param_1 = pcVar6;
  if ((*(ushort *)(param_4 + 3) & 0x10c) == 0) {
    param_4 = (int *)0x1000;
  }
  else {
    param_4 = (int *)param_4[6];
  }
  do {
    if (((*(ushort *)(piVar1 + 3) & 0x10c) == 0) ||
       (pcVar2 = (char *)piVar1[1], pcVar2 == (char *)0x0)) {
      if (param_1 < param_4) {
        uVar4 = FUN_00552b98(piVar1);
        if (uVar4 == 0xffffffff) goto LAB_0054ea83;
        *pcVar5 = (char)uVar4;
        param_4 = (int *)piVar1[6];
        pcVar5 = pcVar5 + 1;
        param_1 = param_1 + -1;
      }
      else {
        pcVar2 = param_1;
        if (param_4 != (int *)0x0) {
          pcVar2 = param_1 + -((uint)param_1 % (uint)param_4);
        }
        iVar3 = CRT_Read(piVar1[4],pcVar5,pcVar2);
        if (iVar3 == 0) {
          piVar1[3] = piVar1[3] | 0x10;
LAB_0054ea83:
          return (uint)((int)pcVar6 - (int)param_1) / param_2;
        }
        if (iVar3 == -1) {
          piVar1[3] = piVar1[3] | 0x20;
          goto LAB_0054ea83;
        }
        param_1 = param_1 + -iVar3;
        pcVar5 = pcVar5 + iVar3;
      }
    }
    else {
      pcVar7 = param_1;
      if (pcVar2 <= param_1) {
        pcVar7 = pcVar2;
      }
      FUN_00550cd0((undefined4 *)pcVar5,(undefined4 *)*piVar1,(uint)pcVar7);
      param_1 = param_1 + -(int)pcVar7;
      piVar1[1] = piVar1[1] - (int)pcVar7;
      *piVar1 = (int)(pcVar7 + *piVar1);
      pcVar5 = pcVar5 + (int)pcVar7;
    }
    if (param_1 == (char *)0x0) {
      return param_3;
    }
  } while( true );
}

