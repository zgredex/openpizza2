// rea decompile_all
// name: Game_ComputeAverageProductQuality
// address: 0x47c8a0
// body: available
// range: 0x47c8a0-0x47c99f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


ulonglong __fastcall Game_ComputeAverageProductQuality(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  int *piVar6;
  ulonglong uVar7;
  float local_30 [6];
  int local_18 [6];
  
  iVar3 = 0;
  pfVar5 = local_30;
                    /* Depth-2 proposal batch 3. */
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *pfVar5 = 0.0;
    pfVar5 = pfVar5 + 1;
  }
  piVar6 = local_18;
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar6 = 0;
    piVar6 = piVar6 + 1;
  }
  iVar2 = *(int *)(param_1 + 0x170c);
  iVar4 = 0;
  if (0 < iVar2) {
    do {
      iVar2 = FUN_004017f0((void *)(param_1 + 0x16f8),iVar4,(int *)0x0);
      if (iVar2 != 0) {
        iVar1 = FUN_004017f0((void *)(DAT_0057c670 + 0x74),*(int *)(iVar2 + 4),(int *)0x0);
        iVar2 = *(int *)(iVar1 + 8);
        if (((0 < iVar2) && (iVar2 < 5)) && ((iVar2 != 3 || (*(char *)(iVar1 + 0x14) != '\0')))) {
          local_30[iVar2] = (float)*(byte *)(iVar1 + 0x14) + local_30[iVar2];
          iVar3 = iVar3 + 1;
          local_18[iVar2] = local_18[iVar2] + 1;
        }
      }
      iVar2 = *(int *)(param_1 + 0x170c);
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar2);
    param_2 = 0;
    if (0 < iVar3) {
      iVar2 = 0;
      do {
        iVar3 = *(int *)((int)local_18 + iVar2 + 4);
        if (iVar3 < 1) {
          *(undefined4 *)((int)local_30 + iVar2 + 4) = 0;
        }
        else {
          *(float *)((int)local_30 + iVar2 + 4) =
               *(float *)((int)local_30 + iVar2 + 4) / (float)iVar3;
        }
        iVar2 = iVar2 + 4;
      } while (iVar2 < 0xd);
      uVar7 = FUN_00403850((local_30[4] + local_30[3] + local_30[2] + local_30[1]) * 12.5);
      return uVar7;
    }
  }
  return CONCAT44(param_2,iVar2) & 0xffffffffffffff00;
}

