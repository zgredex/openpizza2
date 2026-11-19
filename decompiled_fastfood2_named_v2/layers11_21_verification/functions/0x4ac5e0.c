// rea decompile_all
// name: StatisticsBranchBalance_UpdateBranchProfits
// address: 0x4ac5e0
// body: available
// range: 0x4ac5e0-0x4ac7fa inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl StatisticsBranchBalance_UpdateBranchProfits(void *param_1,int param_2)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  float10 fVar8;
  float10 fVar9;
  float10 fVar10;
  float10 fVar11;
  int iVar12;
  undefined4 uVar13;
  float *local_3c;
  float *local_38;
  undefined1 local_28 [36];
  
                    /* Computes and prints total and per-branch balances. */
  iVar12 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  iVar7 = *(int *)(iVar12 + 0x15c);
  uVar4 = (uint)*(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 4);
  uVar3 = (uint)*(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 10);
  puVar6 = &DAT_0057d5d8;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  fVar8 = FUN_004e0df0(iVar12,uVar4,uVar3);
  local_3c = (float *)0x0;
  DAT_0057d5d8 = (float)fVar8;
  if (0 < iVar7) {
    local_38 = (float *)&DAT_0057d5dc;
    do {
      iVar2 = FUN_004017f0((void *)(iVar12 + 0x148),(int)local_3c,(int *)0x0);
      fVar8 = FUN_00477fe0(iVar2,-1,uVar4,uVar3);
      fVar9 = FUN_00478090(iVar2,-1,uVar4,uVar3);
      fVar10 = FUN_00477fe0(iVar2,-1,uVar4,uVar3);
      fVar11 = FUN_00478090(iVar2,-1,uVar4,uVar3);
      local_3c = (float *)((int)local_3c + 1);
      DAT_0057d5d8 = (float)((float10)DAT_0057d5d8 + ((float10)(float)fVar10 - fVar11));
      *local_38 = (float)fVar8 - (float)fVar9;
      local_38 = local_38 + 1;
    } while ((int)local_3c < iVar7);
  }
  fVar1 = DAT_0057d5d8;
  if (iVar7 < 6) {
    param_2 = 0;
  }
  else {
    iVar7 = 5;
  }
  FUN_0054dd83(local_28,(byte *)s__0_2f___005688b0,SUB84((double)DAT_0057d5d8,0));
  if (0.0 <= fVar1) {
    uVar13 = 0;
  }
  else {
    uVar13 = 0xff;
  }
  Window_GadgetNotify_Text_SetTextColor(param_1,0x3fb,uVar13);
  Window_GadgetNotify_Text_SetText(param_1,0x3fb,local_28);
  if (0 < iVar7) {
    piVar5 = &DAT_00569598;
    local_3c = (float *)(&DAT_0057d5dc + param_2);
    do {
      fVar1 = *local_3c;
      FUN_0054dd83(local_28,(byte *)s__0_2f___005688b0,SUB84((double)fVar1,0));
      if (0.0 <= fVar1) {
        iVar12 = *piVar5;
        uVar13 = 0;
      }
      else {
        iVar12 = *piVar5;
        uVar13 = 0xff;
      }
      Window_GadgetNotify_Text_SetTextColor(param_1,iVar12,uVar13);
      Window_GadgetNotify_Text_SetText(param_1,*piVar5,local_28);
      piVar5 = piVar5 + 1;
      local_3c = local_3c + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  return;
}

