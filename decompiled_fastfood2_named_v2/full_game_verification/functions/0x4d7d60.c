// rea decompile_all
// name: Game_CountNearbyObjectTypes
// address: 0x4d7d60
// body: available
// range: 0x4d7d60-0x4d7e8c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall Game_CountNearbyObjectTypes(void *this,int param_1,undefined4 *param_2)

{
  void *this_00;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  undefined4 *puVar9;
  int local_18;
  int local_14;
  
  puVar9 = param_2;
  for (iVar7 = 0x40; iVar1 = DAT_0057c670, iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  iVar7 = *(int *)((int)this + 0xfc0);
  this_00 = (void *)(DAT_0057c670 + 0x3c);
  local_14 = 0;
  local_18 = 0;
  iVar2 = 0;
  if (0 < iVar7) {
    do {
      iVar2 = IDMap_Lookup((void *)((int)this + 0xfac),local_18,(int *)0x0);
      iVar3 = Game_GetObjectCenterY(iVar2);
      iVar4 = Game_GetObjectCenterY(param_1);
      iVar5 = Game_GetObjectBottom(iVar2);
      iVar6 = Game_GetObjectBottom(param_1);
      if (((iVar4 - iVar3) * (iVar4 - iVar3) + (iVar6 - iVar5) * (iVar6 - iVar5) * 4 < 160000) &&
         (iVar3 = 0, 0 < *(int *)(iVar1 + 0x50))) {
        do {
          iVar4 = IDMap_Lookup(this_00,iVar3,(int *)0x0);
          if ((*(int *)(iVar4 + 0x28) == *(int *)((int)this + 0xc1c)) &&
             (*(int *)(iVar4 + 0x30) < 8)) {
            iVar5 = 0;
            piVar8 = (int *)(iVar4 + 0xd4);
            do {
              if (iVar2 == *piVar8) {
                param_2[iVar5 + *(int *)(iVar4 + 0x34) * 8] =
                     param_2[iVar5 + *(int *)(iVar4 + 0x34) * 8] + 1;
                local_14 = local_14 + 1;
              }
              iVar5 = iVar5 + 1;
              piVar8 = piVar8 + 1;
            } while (iVar5 < 8);
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < *(int *)(iVar1 + 0x50));
      }
      local_18 = local_18 + 1;
    } while (local_18 < iVar7);
    iVar2 = local_14;
  }
  return iVar2;
}

