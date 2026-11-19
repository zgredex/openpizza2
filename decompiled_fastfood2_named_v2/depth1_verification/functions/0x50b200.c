// rea decompile_all
// name: FUN_0050b200
// address: 0x50b200
// body: available
// range: 0x50b200-0x50b36a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_0050b200(void *this,undefined4 param_1,uint *param_2,void *param_3)

{
  void *this_00;
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  void *this_01;
  int local_18;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  if (*(int *)((int)this + 200) != 0) {
    if (param_3 != (void *)0x0) {
      List_Node_Reset((int)param_3);
    }
    this_00 = *(void **)((int)this + 0xf4);
    Record_GetTwoFloats48
              ((void *)(*(int **)((int)this + 200))[0x16],**(int **)((int)this + 200),&local_c,
               &local_4);
    local_18 = 0;
    if (0 < *(int *)((int)this_00 + 0x8c)) {
      do {
        iVar2 = Game_MapRecordToGlobal(this_00,local_18);
        iVar3 = FUN_00509fa0(iVar2);
        if ((iVar3 != 0) && (*(int *)(iVar2 + 0x38) != 0x1f)) {
          piVar1 = *(int **)(iVar2 + 200);
          if (piVar1 == (int *)0x0) {
            iVar3 = -1;
            this_01 = (void *)0x0;
          }
          else {
            iVar3 = *piVar1;
            this_01 = (void *)piVar1[0x16];
          }
          Record_GetTwoFloats48(this_01,iVar3,&local_10,&local_8);
          if ((local_10 - local_c) * (local_10 - local_c) +
              (local_8 - local_4) * (local_8 - local_4) * 4 < 0xe10) {
            uVar4 = FUN_0050b100(this,(float)(*(int *)(*(int *)((int)this + 0xc4) + 0xf8) + local_10
                                             ),*(int *)(*(int *)((int)this + 0xc4) + 0xfc) + local_8
                                );
            *param_2 = uVar4;
            if (param_3 == (void *)0x0) {
              return iVar2;
            }
            FUN_004014b0(param_3,iVar2);
          }
        }
        local_18 = local_18 + 1;
      } while (local_18 < *(int *)((int)this_00 + 0x8c));
    }
    if (param_3 != (void *)0x0) {
      iVar2 = FUN_004017f0(param_3,0,(int *)0x0);
      return iVar2;
    }
  }
  return 0;
}

