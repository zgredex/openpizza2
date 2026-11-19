// rea decompile_all
// name: FUN_004997a0
// address: 0x4997a0
// body: available
// range: 0x4997a0-0x499881 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004997a0(void *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_44;
  char local_40 [64];
  
  local_44 = *(int *)((int)DAT_0057ca20 + 0x14);
  if (local_44 < 0xd) {
    param_2 = 0;
  }
  else {
    local_44 = 0xc;
  }
  if (0 < local_44) {
    iVar2 = param_2 * 3;
    iVar3 = 0x4ed;
    do {
      Window_GadgetNotify_Button_SetState(param_1,iVar3,(uint)(iVar2 == DAT_00568914));
      if (iVar2 < *(int *)((int)DAT_0057ca20 + 0x14)) {
        FUN_005316f0(param_1,iVar3 + 0x1c,1);
        FUN_005316f0(param_1,iVar3,1);
        iVar1 = FUN_004017f0(DAT_0057ca20,iVar2,(int *)0x0);
        FUN_0054dd83(local_40,(byte *)s_zmi__02d_spr_00568938,*(undefined4 *)(iVar1 + 0xd0));
        UI_SetButtonSpriteByName(param_1,iVar3 + 0x1c,local_40);
      }
      else {
        FUN_005316f0(param_1,iVar3 + 0x1c,0);
        FUN_005316f0(param_1,iVar3,0);
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar3 + -0x4ec;
      iVar3 = iVar3 + 1;
    } while (iVar1 < local_44);
  }
  return;
}

