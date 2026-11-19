// rea decompile_all
// name: FUN_0050b7c0
// address: 0x50b7c0
// body: available
// range: 0x50b7c0-0x50b92a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_0050b7c0(void *this,void *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *this_00;
  void *this_01;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_14;
  int local_10;
  int local_c;
  
  local_c = 0;
  iVar5 = 99999999;
  iVar1 = FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  iVar2 = FUN_004f0cc0(*(void **)(iVar1 + 0xfa8),1,*(int *)(*(int *)((int)this + 0xfc) + 0x54));
  iVar1 = FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)((int)this + 0x28),(int *)0x0);
  this_00 = FUN_004d5ab0(iVar1);
  local_10 = 0;
  iVar1 = 0;
  if (0 < (int)this_00[5]) {
    do {
      this_01 = (void *)FUN_004017f0(this_00,local_10,(int *)0x0);
      if (this_01 != (void *)0x0) {
        iVar1 = FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
        iVar1 = FUN_004f0cc0(*(void **)(iVar1 + 0xfa8),1,*(int *)((int)this_01 + 0x54));
        local_14 = 0;
        if (0 < *(int *)((int)this_01 + 0x8c)) {
          do {
            iVar3 = Game_MapRecordToGlobal(this_01,local_14);
            if (((iVar3 != 0) && (*(int *)(iVar3 + 0x38) == 0x1a)) &&
               (iVar4 = FUN_00478320(param_1,*(int *)(iVar3 + 0x34)),
               *(int *)(iVar3 + 0x2c) <= iVar4)) {
              iVar4 = FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),
                                   (int *)0x0);
              iVar4 = FUN_004ed500(*(void **)(iVar4 + 0xfa8),iVar2,iVar1);
              if (iVar4 < iVar5) {
                iVar5 = iVar4;
                local_c = iVar3;
              }
            }
            local_14 = local_14 + 1;
          } while (local_14 < *(int *)((int)this_01 + 0x8c));
        }
      }
      local_10 = local_10 + 1;
    } while (local_10 < (int)this_00[5]);
    iVar1 = local_c;
  }
  if (this_00 != (undefined4 *)0x0) {
    (**(code **)*this_00)(1);
  }
  return iVar1;
}

