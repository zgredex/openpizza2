// rea decompile_all
// name: FUN_004da110
// address: 0x4da110
// body: available
// range: 0x4da110-0x4da1f1 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_004da110(void *param_1)

{
  uint uVar1;
  void *this;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int local_fa0 [1000];
  
  iVar4 = 0;
  do {
    uVar1 = FUN_004034d0(0,2);
    this = (void *)FUN_0048b960(DAT_0057c670,uVar1);
    if (this != (void *)0x0) {
      iVar4 = 0;
      uVar3 = 0;
      do {
        iVar2 = FUN_00488be0(DAT_0057c670,iVar4);
        uVar5 = uVar3;
        if (iVar2 != 0) {
          iVar2 = FUN_004da700(param_1,iVar4);
          uVar5 = iVar2 + uVar3;
          if ((int)uVar3 < (int)uVar5) {
            piVar6 = local_fa0 + uVar3;
            for (iVar2 = uVar5 - uVar3; iVar2 != 0; iVar2 = iVar2 + -1) {
              *piVar6 = iVar4;
              piVar6 = piVar6 + 1;
            }
          }
        }
        iVar4 = iVar4 + 1;
        uVar3 = uVar5;
      } while (iVar4 < 6);
      uVar3 = FUN_004034d0(0,uVar5);
      iVar4 = FUN_00488be0(DAT_0057c670,local_fa0[uVar3]);
      if ((iVar4 != 0) && (0 < *(int *)(iVar4 + 0x15c))) {
        uVar3 = FUN_004034d0(0,*(int *)(iVar4 + 0x15c) - 1);
        iVar4 = FUN_004017f0((void *)(iVar4 + 0x148),uVar3,(int *)0x0);
        if (iVar4 != 0) {
          FUN_0050b5e0(this,iVar4,uVar1,0xffffffff,'\0');
        }
      }
      return;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 4);
  return;
}

