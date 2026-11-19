// rea decompile_all
// name: FUN_004d74c0
// address: 0x4d74c0
// body: available
// range: 0x4d74c0-0x4d75a7 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_004d74c0(void *this,int param_1,int param_2,char param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int local_400 [256];
  
  if (param_1 == 7) {
    param_1 = 0;
  }
  iVar4 = 0;
  iVar6 = 0;
  if (0 < *(int *)((int)this + 0xfc0)) {
    piVar5 = local_400;
    do {
      iVar1 = FUN_004017f0((void *)((int)this + 0xfac),iVar6,(int *)0x0);
      if ((((*(int *)(iVar1 + 4) == param_1) && (*(int *)(iVar1 + 0x48) != -1)) &&
          ((param_3 == '\0' || (iVar2 = Game_CanShowObject(iVar1), iVar2 != 0)))) &&
         (iVar1 != param_2)) {
        *piVar5 = iVar1;
        iVar4 = iVar4 + 1;
        piVar5 = piVar5 + 1;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)((int)this + 0xfc0));
    if (iVar4 != 0) {
      uVar3 = FUN_004034d0(0,iVar4 - 1);
      return local_400[uVar3];
    }
  }
  FUN_0054a660(DAT_0057c1e0,0xff,(byte *)s_GetRandomBuilding___s_nicht_gefu_0056cd74,
               *(undefined4 *)(&DAT_005840d4 + param_1 * 4));
  return 0;
}

