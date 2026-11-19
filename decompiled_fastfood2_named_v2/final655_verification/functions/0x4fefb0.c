// rea decompile_all
// name: AI_Annoy_SendGangsterGroup
// address: 0x4fefb0
// body: available
// range: 0x4fefb0-0x4ff07f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall AI_Annoy_SendGangsterGroup(void *this,void *param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined3 extraout_var;
  uint uVar4;
  int iVar5;
  uint local_4;
  
                    /* Sends a group of gangsters to harass a branch. */
  local_4 = 0;
  FUN_00488be0(DAT_0057c670,*(int *)(param_2 + 0x30));
  uVar2 = FUN_004e1ee0(param_1,0x1e);
  if (uVar2 != 0) {
    iVar3 = AI_OpenBranchesInCity(this,param_1,param_2);
    if (iVar3 != 0) {
      if ((int)uVar2 < 4) {
        uVar2 = 3;
      }
      uVar2 = FUN_004034d0(1,uVar2);
      bVar1 = FUN_004ff650();
      if (CONCAT31(extraout_var,bVar1) == 0) {
        return 2;
      }
      if (0 < (int)uVar2) {
        do {
          uVar4 = AI_HireCourier(param_1,param_2);
          local_4 = local_4 | uVar4;
          uVar2 = uVar2 - 1;
        } while (uVar2 != 0);
        if (local_4 != 0) {
          iVar3 = *(int *)(param_2 + 0x30);
          iVar5 = FUN_00482820((int)DAT_0057c670);
          if (iVar3 == iVar5) {
            FUN_00548d70(DAT_0057ba0c);
          }
        }
      }
    }
  }
  return 1;
}

