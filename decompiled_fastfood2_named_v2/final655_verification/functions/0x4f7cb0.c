// rea decompile_all
// name: FUN_004f7cb0
// address: 0x4f7cb0
// body: available
// range: 0x4f7cb0-0x4f7dce inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_004f7cb0(int param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  undefined4 *puVar2;
  void *this;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_8;
  int local_4;
  
  puVar2 = param_2;
  for (iVar6 = 0x1e; iVar6 != 0; iVar6 = iVar6 + -1) {
    *param_2 = 0;
    param_2 = param_2 + 1;
  }
  iVar6 = *(int *)(param_1 + 0x30);
  iVar1 = *(int *)(param_1 + 0x34);
  this = (void *)FUN_004017f0((void *)(DAT_0057c670 + 4),iVar1,(int *)0x0);
  if ((iVar6 != -1) && (this != (void *)0x0)) {
    local_4 = FUN_004d6ba0(this,0xffffffff);
    param_2 = (undefined4 *)0x0;
    if (0 < local_4) {
      do {
        piVar3 = (int *)FUN_004d8120(this,(int)param_2,&local_8);
        iVar6 = *piVar3;
        if ((((iVar6 != 0) && (*(byte *)(iVar6 + 0x824) == param_3)) &&
            (iVar4 = FUN_004d3910(iVar6), *(int *)(iVar4 + 0x108) != 0xc)) &&
           (iVar4 = FUN_004d3910(iVar6), *(int *)(iVar4 + 0x74) == 0)) {
          iVar6 = FUN_004d4000(iVar6);
          iVar4 = 9;
          if ((int)puVar2[0x1d] < iVar6) {
            piVar3 = puVar2 + 0x1d;
            do {
              if (iVar6 <= *piVar3) break;
              iVar4 = iVar4 + -1;
              piVar3 = piVar3 + -3;
            } while (-1 < iVar4);
            iVar5 = iVar4 + 1;
            piVar3 = puVar2 + iVar5 * 3;
            FUN_0054e230(puVar2 + iVar4 + 4 + iVar5 * 2,piVar3,iVar5 * -0xc + 0x6c);
            piVar3[2] = iVar6;
            piVar3[1] = local_8;
            *piVar3 = iVar1;
          }
        }
        param_2 = (undefined4 *)((int)param_2 + 1);
      } while ((int)param_2 < local_4);
    }
  }
  return;
}

