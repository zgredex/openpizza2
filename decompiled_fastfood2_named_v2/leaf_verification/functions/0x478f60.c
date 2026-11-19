// rea decompile_all
// name: FUN_00478f60
// address: 0x478f60
// body: available
// range: 0x478f60-0x47911b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_00478f60(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int aiStack_e0 [8];
  int local_c0 [8];
  int local_a0 [8];
  int local_80 [8];
  int aiStack_60 [8];
  int local_40 [8];
  int local_20 [8];
  
  iVar5 = 0;
  iVar6 = 0;
  do {
    if (*(int *)(param_1 + 0x1850) < *(int *)((int)&DAT_00567838 + iVar6)) {
      *(int *)((int)local_a0 + iVar6) =
           (*(int *)(param_1 + 0x1850) - *(int *)((int)&DAT_00567838 + iVar6)) * 3 + 100;
      Clamp_0_100((int *)((int)local_a0 + iVar6));
    }
    else {
      *(undefined4 *)((int)local_a0 + iVar6) = 100;
    }
    if (*(int *)(param_1 + 0x1854) < *(int *)((int)&DAT_00567858 + iVar6)) {
      *(int *)((int)local_c0 + iVar6) =
           (*(int *)(param_1 + 0x1854) - *(int *)((int)&DAT_00567858 + iVar6)) * 3 + 100;
      Clamp_0_100((int *)((int)local_c0 + iVar6));
    }
    else {
      *(undefined4 *)((int)local_c0 + iVar6) = 100;
    }
    if (*(int *)(param_1 + 0x185c) < *(int *)((int)&DAT_00567878 + iVar6)) {
      *(int *)((int)local_80 + iVar6) =
           (*(int *)(param_1 + 0x185c) - *(int *)((int)&DAT_00567878 + iVar6)) * 3 + 100;
      Clamp_0_100((int *)((int)local_80 + iVar6));
    }
    else {
      *(undefined4 *)((int)local_80 + iVar6) = 100;
    }
    if (*(int *)(param_1 + 0x1868) < *(int *)((int)&DAT_00567898 + iVar6)) {
      *(int *)((int)local_40 + iVar6) =
           (*(int *)(param_1 + 0x1868) - *(int *)((int)&DAT_00567898 + iVar6)) * 3 + 100;
      Clamp_0_100((int *)((int)local_40 + iVar6));
    }
    else {
      *(undefined4 *)((int)local_40 + iVar6) = 100;
    }
    uVar3 = *(int *)((int)&DAT_005678d8 + iVar6) - *(int *)(param_1 + 0x1858);
    uVar4 = (int)uVar3 >> 0x1f;
    *(int *)((int)local_20 + iVar6) = ((uVar3 ^ uVar4) - uVar4) * -6 + 100;
    Clamp_0_100((int *)((int)local_20 + iVar6));
    if (*(int *)(param_1 + 0x1860) < *(int *)((int)&DAT_005678f8 + iVar6)) {
      *(undefined4 *)((int)aiStack_60 + iVar6) = 0;
    }
    else {
      *(undefined4 *)((int)aiStack_60 + iVar6) = 100;
    }
    iVar1 = *(int *)(param_1 + 0x1864);
    iVar2 = *(int *)((int)&DAT_00567918 + iVar6);
    *(undefined4 *)((int)aiStack_e0 + iVar6) = 100;
    if (iVar2 < iVar1) {
      *(int *)((int)aiStack_e0 + iVar6) = ((iVar2 - iVar1) + 2) * 0x32;
    }
    else {
      *(undefined4 *)((int)aiStack_e0 + iVar6) = 100;
    }
    iVar6 = iVar6 + 4;
  } while (iVar6 < 0x20);
  piVar7 = (int *)(param_1 + 0x17fc);
  do {
    iVar6 = *(int *)((int)local_40 + iVar5) + *(int *)((int)local_80 + iVar5) +
            *(int *)((int)local_c0 + iVar5) + *(int *)((int)local_a0 + iVar5);
    *piVar7 = ((*(int *)((int)aiStack_e0 + iVar5) + *(int *)((int)aiStack_60 + iVar5) +
               *(int *)((int)local_20 + iVar5)) / 3 + ((int)(iVar6 + (iVar6 >> 0x1f & 3U)) >> 2)) /
              2;
    Clamp_0_100(piVar7);
    iVar5 = iVar5 + 4;
    piVar7 = piVar7 + 1;
  } while (iVar5 < 0x20);
  return;
}

