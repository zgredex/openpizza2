// rea decompile_all
// name: FUN_00507b90
// address: 0x507b90
// body: available
// range: 0x507b90-0x507c85 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_00507b90(int param_1,int param_2)

{
  void *this;
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  short *psVar6;
  int *piVar7;
  undefined4 local_28 [5];
  int local_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a2d8;
  local_c = ExceptionList;
  iVar5 = 0;
  ExceptionList = &local_c;
  FUN_004013a0(local_28,0);
  local_4 = 0;
  iVar1 = FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  this = *(void **)(iVar1 + 0xfa8);
  iVar1 = param_1;
  if (0 < param_2) {
    do {
      iVar4 = param_1;
      List_Node_Reset((int)local_28);
      psVar6 = (short *)(iVar4 + 0x14);
      param_1 = 8;
      do {
        if (*psVar6 != -1) {
          iVar2 = FUN_004f0cc0(this,1,(int)*psVar6);
          if (iVar2 != iVar1) {
            FUN_004014b0(local_28,iVar2);
          }
        }
        psVar6 = psVar6 + 1;
        param_1 = param_1 + -1;
      } while (param_1 != 0);
      param_1 = iVar4;
      if (local_14 < 1) break;
      piVar7 = (int *)0x0;
      uVar3 = FUN_004034d0(0,local_14 - 1);
      param_1 = FUN_004017f0(local_28,uVar3,piVar7);
      iVar5 = iVar5 + 1;
      iVar1 = iVar4;
    } while (iVar5 < param_2);
  }
  local_4 = 0xffffffff;
  FUN_00401480(local_28);
  ExceptionList = local_c;
  return param_1;
}

