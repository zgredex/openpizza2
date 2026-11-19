// rea decompile_all
// name: FUN_004f5310
// address: 0x4f5310
// body: available
// range: 0x4f5310-0x4f55de inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall
FUN_004f5310(void *this,int param_1,void *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int *piVar1;
  byte bVar2;
  void *this_00;
  int iVar3;
  int iVar4;
  undefined4 *this_01;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int local_834;
  int local_830;
  int local_82c;
  int local_828;
  int local_824;
  int local_820;
  int local_81c;
  undefined4 local_818 [5];
  int local_804;
  undefined4 local_7fc [508];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a08b;
  pvStack_c = ExceptionList;
  iVar7 = 0;
  ExceptionList = &pvStack_c;
  FUN_004013a0(local_818,0);
  local_4 = 0;
  local_830 = 0;
  local_7fc[0] = 2;
  piVar1 = *(int **)(param_1 + 200);
  local_7fc[1] = 3;
  local_7fc[2] = 0;
  local_7fc[3] = 1;
  local_7fc[4] = 6;
  local_7fc[5] = 7;
  local_7fc[6] = 4;
  local_7fc[7] = 5;
  local_834 = 200000;
  if (piVar1 == (int *)0x0) {
    iVar6 = -1;
    this_00 = (void *)0x0;
  }
  else {
    iVar6 = *piVar1;
    this_00 = (void *)piVar1[0x16];
  }
  FUN_00534370(this_00,iVar6,&local_82c,&local_828);
  local_828 = local_828 + *(int *)((int)this + 0xfc);
  local_82c = local_82c + *(int *)((int)this + 0xf8);
  if (0 < *(int *)((int)param_2 + 0x170c)) {
    do {
      iVar6 = IDMap_Lookup((void *)((int)param_2 + 0x16f8),iVar7,(int *)0x0);
      if ((((iVar6 != 0) && (bVar2 = FUN_004e5df0(iVar6), bVar2 != 0)) && (bVar2 < 7)) &&
         (0 < *(int *)(iVar6 + 0xc))) {
        UI_ComputeCenteredRect
                  (this,(int *)(*(int *)((int)this + 0x4c) + *(int *)(iVar6 + 0x20) * 0xc),
                   &local_81c,&local_820);
        iVar3 = Distance_Manhattan3(local_82c,local_828,local_81c,local_820);
        if ((iVar3 < local_834) && (iVar4 = FUN_00480d20(param_2,iVar6,param_1), iVar4 == 0)) {
          local_834 = iVar3;
          local_830 = iVar6;
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < *(int *)((int)param_2 + 0x170c));
    if (local_830 != 0) {
      *param_3 = *(undefined4 *)(local_830 + 0x20);
      FUN_00401440((int)local_818);
      this_01 = FUN_004f2b60(this,local_830);
      local_830 = 0;
      if (0 < (int)this_01[5]) {
        do {
          iVar7 = IDMap_Lookup(this_01,local_830,(int *)0x0);
          iVar6 = 0;
          puVar8 = local_7fc;
          do {
            iVar3 = FUN_004f3e10(this,iVar7,iVar6);
            if ((*(int *)(*(int *)(iVar3 + 8) + 0x28) != 0) &&
               (*(short *)(*(int *)(iVar3 + 8) + 0x24) != -1)) {
              local_824 = FUN_004014b0(local_818,iVar3);
              IDMap_Update(local_818,&local_824);
              local_7fc[local_824 + 8] = *puVar8;
            }
            iVar6 = iVar6 + 1;
            puVar8 = puVar8 + 1;
          } while (iVar6 < 8);
          local_830 = local_830 + 1;
        } while (local_830 < (int)this_01[5]);
      }
      if (this_01 != (undefined4 *)0x0) {
        (**(code **)*this_01)(1);
      }
      if (0 < local_804) {
        uVar5 = FUN_004034d0(0,local_804 - 1);
        iVar7 = IDMap_Lookup(local_818,uVar5,(int *)0x0);
        iVar7 = Array_GetRecord28(this,1,(int)*(short *)(*(int *)(iVar7 + 8) + 0x24));
        local_4 = 0xffffffff;
        *param_4 = local_7fc[uVar5 + 8];
        FUN_00401480(local_818);
        ExceptionList = pvStack_c;
        return iVar7;
      }
    }
  }
  local_4 = 0xffffffff;
  FUN_00401480(local_818);
  ExceptionList = pvStack_c;
  return 0;
}

