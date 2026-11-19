// rea decompile_all
// name: HeadquartersPage_FillCompetitorRows
// address: 0x4a3bc0
// body: available
// range: 0x4a3bc0-0x4a3d38 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl HeadquartersPage_FillCompetitorRows(void *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *local_88;
  int local_84;
  char local_80 [128];
  
                    /* Fills the headquarters competitor rows. */
  if (param_3 < 5) {
    param_2 = 0;
  }
  else {
    param_3 = 4;
  }
  iVar2 = 0;
  piVar3 = &DAT_00568f2c;
  do {
    FUN_00531740(param_1,*piVar3);
    FUN_00531740(param_1,iVar2 + 0x23f1);
    piVar3 = piVar3 + 4;
    iVar2 = iVar2 + 1;
  } while ((int)piVar3 < 0x568f6c);
  if (param_2 < 6) {
    local_88 = &DAT_0057d24c + param_2;
    iVar2 = 0x23f1;
    piVar3 = &DAT_00568f30;
    local_84 = param_2;
    do {
      if (iVar2 + -0x23f1 == param_3) {
        return;
      }
      iVar1 = FUN_00482820((int)DAT_0057c670);
      if ((local_84 != iVar1) && (*local_88 != 0)) {
        iVar1 = FUN_00488be0(DAT_0057c670,local_84);
        FUN_0052f910(param_1,*piVar3,*(undefined4 *)(iVar1 + 0x1dc));
        FUN_0052f080(param_1,*piVar3,&DAT_005630d0,iVar1 + 8);
        FUN_0052f080(param_1,piVar3[2],&DAT_005686f4,*local_88);
        FUN_0054dd83(local_80,(byte *)s_LOGOS__0_d_spr_00568eb8,*(int *)(iVar1 + 0x1e0) + 1);
        FUN_00531910(param_1,iVar2,local_80);
        UI_ShowChildByID(param_1,iVar2);
        UI_ShowChildByID(param_1,piVar3[-1]);
        FUN_0052ff50(param_1,piVar3[-1],(uint)(byte)(&DAT_0057d240)[local_84]);
        iVar2 = iVar2 + 1;
        piVar3 = piVar3 + 4;
      }
      local_84 = local_84 + 1;
      local_88 = local_88 + 1;
    } while ((int)local_88 < 0x57d264);
  }
  return;
}

