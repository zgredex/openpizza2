// rea decompile_all
// name: CompanyBranches_InitBranchRows
// address: 0x4b98e0
// body: available
// range: 0x4b98e0-0x4b9a32 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl CompanyBranches_InitBranchRows(void *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  int local_38;
  int local_34;
  int local_2c;
  undefined1 local_28 [36];
  
                    /* Fills branch rows with names and computed recipe prices. */
  iVar1 = Game_CountActiveCompanies((int)DAT_0057d6cc);
  local_34 = 0;
  local_2c = 0;
  iVar2 = 0;
  if (0 < iVar1 + 1) {
    iVar2 = 0x511;
    do {
      if ((local_2c == 0) && (param_2 == 0)) {
        local_38 = *(int *)(*(int *)(DAT_0057c670 + 0x9c) + 0x14dc);
      }
      else {
        local_38 = Game_GetActiveCompanyById(DAT_0057d6cc,local_2c + -1 + param_2);
      }
      if (local_38 != 0) {
        UI_ShowChildByID(param_1,iVar2);
        UI_ShowChildByID(param_1,iVar2 + 9);
        UI_ShowChildByID(param_1,iVar2 + -0xb);
        Window_GadgetNotify_Text_SetText(param_1,iVar2,local_38 + 4);
        fVar3 = Branch_ComputeRecipePrice(local_38,*(int *)(DAT_0057c670 + 0x9c),-999);
        String_Format(local_28,(byte *)s__0_2f_005685f4,SUB84((double)fVar3,0));
        Window_GadgetNotify_Text_SetText(param_1,iVar2 + 9,local_28);
        local_34 = local_34 + 1;
        iVar2 = iVar2 + 1;
        if (iVar2 == 0x51a) break;
      }
      local_2c = local_2c + 1;
    } while (local_2c < iVar1 + 1);
    iVar2 = local_34;
    if (8 < local_34) {
      return;
    }
  }
  iVar2 = iVar2 + 0x51a;
  do {
    UI_RemoveObjectByKey(param_1,iVar2 + -9);
    UI_RemoveObjectByKey(param_1,iVar2);
    UI_RemoveObjectByKey(param_1,iVar2 + -0x14);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x523);
  return;
}

