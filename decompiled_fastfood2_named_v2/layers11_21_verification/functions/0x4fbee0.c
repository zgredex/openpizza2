// rea decompile_all
// name: FUN_004fbee0
// address: 0x4fbee0
// body: available
// range: 0x4fbee0-0x4fc0aa inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_004fbee0(int *param_1,char param_2)

{
  int iVar1;
  void *this;
  void *this_00;
  int iVar2;
  int *piVar3;
  int iVar4;
  void *this_01;
  int iVar5;
  int iVar6;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a14b;
  local_c = ExceptionList;
  if ((param_1 != (int *)0x0) && (param_1[3] != 0)) {
    iVar1 = *(int *)(*param_1 + 0x24);
    ExceptionList = &local_c;
    FUN_0047c730(*param_1);
    this = (void *)param_1[3];
    iVar6 = 0;
    this_00 = *(void **)(*param_1 + 0x14e0);
    iVar2 = *(int *)((int)this + 0x14);
    if (0 < iVar2) {
      do {
        piVar3 = (int *)FUN_004017f0(this,iVar6,(int *)0x0);
        if ((param_2 != '\0') || (piVar3[7] != 0)) {
          iVar4 = FUN_004ef4b0(this_00,(int)(short)piVar3[5],(int)*(short *)((int)piVar3 + 0x16));
          FUN_004ed330(this_00,iVar4,*piVar3,*(byte *)(piVar3 + 6) - 1);
          if ((piVar3[8] != 0) && (piVar3[3] != -1)) {
            FUN_004017f0((void *)(DAT_0057c670 + 0x74),piVar3[3],(int *)0x0);
            this_01 = operator_new(0x24);
            local_4 = 0;
            if (this_01 == (void *)0x0) {
              iVar5 = 0;
            }
            else {
              iVar5 = FUN_004e5d60(this_01,piVar3[3],piVar3[4]);
            }
            *(int *)(iVar5 + 0x18) = (int)(short)piVar3[5];
            *(int *)(iVar5 + 0x1c) = (int)*(short *)((int)piVar3 + 0x16);
            local_4 = 0xffffffff;
            *(undefined4 *)(iVar5 + 0x20) = **(undefined4 **)(iVar4 + 8);
            FUN_004014b0((void *)(*param_1 + 0x16f8),iVar5);
          }
        }
        FUN_0054dd78(piVar3);
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar2);
    }
    FUN_00401440((int)this);
    if (param_1[7] == 0) {
      *(int *)(*param_1 + 0x19fc) = iVar1;
      *(int *)(*param_1 + 0x1a04) = iVar1;
      *(int *)(*param_1 + 0x1a00) = param_1[9];
      FUN_0047e5e0((void *)*param_1,iVar1);
      Branch_ApplyBuildingStyleVariant((void *)*param_1,*(int *)(*param_1 + 0x1a04));
    }
    FUN_004f96e0((int)param_1);
    FUN_004fc0b0((undefined4 *)param_1[3]);
    param_1[3] = 0;
    *(undefined4 *)(*param_1 + 0x1718) = 0;
  }
  ExceptionList = local_c;
  return;
}

