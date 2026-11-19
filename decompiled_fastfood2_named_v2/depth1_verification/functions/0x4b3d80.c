// rea decompile_all
// name: FUN_004b3d80
// address: 0x4b3d80
// body: available
// range: 0x4b3d80-0x4b3fa2 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004b3d80(void *param_1,int param_2)

{
  void *this;
  void *this_00;
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  float10 fVar5;
  undefined1 *puVar6;
  int *local_40;
  int local_3c;
  int local_38;
  int local_34;
  undefined1 local_28 [36];
  
  local_34 = 0;
  uVar3 = (uint)*(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 10);
  local_38 = *(int *)((int)DAT_0057d6a4 + 0x14);
  this = *(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  if (DAT_0056a7d4 != -1) {
    local_34 = FUN_004017f0((void *)((int)this + 0x148),DAT_0056a7d4,(int *)0x0);
  }
  if (local_38 < 9) {
    param_2 = 0;
  }
  else {
    local_38 = 8;
  }
  if (0 < local_38) {
    local_3c = param_2 << 2;
    local_40 = &DAT_0056a740;
    iVar4 = 0x40d;
    do {
      iVar1 = *(int *)(local_3c + DAT_0057d6a0);
      FUN_0052ff50(param_1,iVar4 + 0x1b34,(uint)(*(int *)(&DAT_0056a760 + iVar1 * 4) != 0));
      this_00 = (void *)FUN_004017f0(DAT_0057d6a4,iVar1,(int *)0x0);
      FUN_0052f9b0(param_1,iVar4,(int)this_00 + 4);
      if (((DAT_0056a7d4 == -1) || (local_34 == 0)) || (*(void **)(local_34 + 0x14dc) != this_00)) {
        iVar1 = Game_GetActiveCompanyOrdinal(this,(int)this_00);
      }
      else {
        iVar1 = 0x14;
      }
      uVar2 = FUN_00482710(iVar1);
      FUN_0052f910(param_1,iVar4,uVar2);
      if (uVar3 == 0) {
        iVar1 = *local_40;
        puVar6 = DAT_00582e4c;
      }
      else {
        if (DAT_0057d69c == 0) {
          iVar1 = AI_CountPlanSteps(this_00,uVar3 - 1,0x56a734,DAT_0056a7d4);
          FUN_0054dd83(local_28,&DAT_005686f4,iVar1);
        }
        else if (DAT_0057d69c == 1) {
          fVar5 = Stats_SumMaskedMapFloats((int)this_00,uVar3 - 1,0x56a734,DAT_0056a7d4);
          FUN_0054dd83(local_28,(byte *)s__0_2f__005688b8,SUB84((double)fVar5,0));
        }
        else if (DAT_0057d69c == 2) {
          fVar5 = FUN_005104f0(this_00,0x56a734);
          FUN_0054dd83(local_28,(byte *)s__0_2f_005685f4,SUB84((double)fVar5,0));
        }
        FUN_0052f910(param_1,*local_40,0);
        iVar1 = *local_40;
        puVar6 = local_28;
      }
      FUN_0052f9b0(param_1,iVar1,puVar6);
      local_3c = local_3c + 4;
      local_40 = local_40 + 1;
      iVar1 = iVar4 + -0x40c;
      iVar4 = iVar4 + 1;
    } while (iVar1 < local_38);
  }
  return;
}

