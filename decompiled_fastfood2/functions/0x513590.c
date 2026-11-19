// rea decompile_all
// name: FUN_00513590
// address: 0x513590
// body: available
// range: 0x513590-0x5136bd inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_00513590(void *param_1,int param_2)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int extraout_EDX;
  int *piVar5;
  int local_1c [4];
  int local_c;
  int local_8;
  int local_4;
  
  piVar2 = local_1c;
  for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar2 = 0;
    piVar2 = piVar2 + 1;
  }
  if (DAT_00573264 != -1) {
    piVar2 = &DAT_00573264;
    iVar3 = 0;
    piVar5 = &DAT_0057326c;
    do {
      iVar3 = FUN_00512700(param_1,CONCAT31((int3)((uint)param_2 >> 8),(char)*piVar2),
                           CONCAT31((int3)((uint)iVar3 >> 8),(char)piVar5[-1]));
      param_2 = extraout_EDX;
      if (iVar3 != 0) {
        bVar1 = *(byte *)(*(int *)(DAT_0057c670 + 0xa8 + piVar5[-2] * 4) + 0xa8);
        local_1c[bVar1] = local_1c[bVar1] + *piVar5;
        bVar1 = *(byte *)(*(int *)(DAT_0057c670 + 0xa8 + piVar5[-1] * 4) + 0xa8);
        param_2 = local_1c[bVar1] + *piVar5;
        local_1c[bVar1] = param_2;
      }
      iVar3 = piVar5[1];
      piVar2 = piVar5 + 1;
      piVar5 = piVar5 + 3;
    } while (iVar3 != -1);
  }
  iVar3 = local_1c[3] + local_c;
  iVar4 = local_1c[2] + local_4;
  piVar2 = (int *)((int)param_1 + 0x2a4);
  *piVar2 = iVar3 + iVar4 * 3;
  *(int *)((int)param_1 + 0x2a8) = iVar3 + iVar4 * 2;
  *(int *)((int)param_1 + 0x2ac) = local_8 + local_1c[1] * 2 + iVar4;
  *(int *)((int)param_1 + 0x2b0) = iVar3 * 4;
  *(int *)((int)param_1 + 0x2b4) = (local_8 + local_1c[1] * 2) * 2;
  *(int *)((int)param_1 + 0x2b8) = (local_1c[1] + local_8 * 2) * 2;
  *(int *)((int)param_1 + 700) = iVar3 * 3;
  *(int *)((int)param_1 + 0x2c0) = local_8 + local_1c[1] + iVar4 + iVar3;
  iVar3 = 8;
  do {
    if (0x14 < *piVar2) {
      *piVar2 = 0x28 - *piVar2;
    }
    piVar2 = piVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

