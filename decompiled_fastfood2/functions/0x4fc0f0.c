// rea decompile_all
// name: FUN_004fc0f0
// address: 0x4fc0f0
// body: available
// range: 0x4fc0f0-0x4fc28f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_004fc0f0(void *this,int param_1,void *param_2)

{
  void *this_00;
  void *pvVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  byte *pbVar6;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a176;
  local_c = ExceptionList;
  pbVar6 = (byte *)0x0;
  this_00 = *(void **)((int)this + param_1 * 0x168 + 0x70);
  if (*(int *)((int)param_2 + 0x14dc) == 0) {
    ExceptionList = &local_c;
    FUN_004fc7a0(this,1);
    pvVar1 = operator_new(0x330);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      pbVar6 = FUN_00510c90(pvVar1,*(int *)((int)param_2 + 0x30),5,2,*(float *)((int)param_2 + 0x34)
                            ,-1);
    }
    local_4 = 0xffffffff;
    iVar2 = FUN_00488bc0(DAT_0057c670,(int)this_00);
    FUN_00513a90(pbVar6,iVar2);
    pbVar6[0x308] = 5;
    pbVar6[0x309] = 0;
    pbVar6[0x30a] = 0;
    pbVar6[0x30b] = 0;
    FUN_004fc7a0(this,0);
    FUN_004014b0((void *)((int)this_00 + 0x110),pbVar6);
    FUN_00477bd0(param_2,pbVar6);
LAB_004fc276:
    uVar5 = 4;
  }
  else {
    ExceptionList = &local_c;
    uVar3 = FUN_004e0e90(this_00,2);
    if (uVar3 != 0xffffffff) {
      iVar2 = *(int *)((int)this_00 + 0x15c) + 0x10;
      if (0x14 < iVar2) {
        iVar2 = 0x14;
      }
      iVar4 = FUN_004ddde0((int)this_00);
      if (iVar4 < iVar2) {
        FUN_004fc7a0(this,1);
        pvVar1 = operator_new(0x330);
        local_4 = 1;
        if (pvVar1 == (void *)0x0) {
          pbVar6 = (byte *)0x0;
        }
        else {
          pbVar6 = FUN_00510c90(pvVar1,*(int *)((int)param_2 + 0x30),uVar3,2,
                                *(float *)((int)param_2 + 0x34),-1);
        }
        local_4 = 0xffffffff;
        iVar2 = FUN_00488bc0(DAT_0057c670,(int)this_00);
        FUN_00513a90(pbVar6,iVar2);
        *(uint *)(pbVar6 + 0x308) = uVar3;
        FUN_004fc7a0(this,0);
        FUN_004014b0((void *)((int)this_00 + 0x110),pbVar6);
        FUN_004e3460(this_00,(int)pbVar6,1);
        goto LAB_004fc276;
      }
    }
    *(uint *)((int)param_2 + 0x28) = *(uint *)((int)param_2 + 0x28) & 0xef;
    uVar5 = 1;
  }
  ExceptionList = local_c;
  return uVar5;
}

