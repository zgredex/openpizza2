// rea decompile_all
// name: FUN_0049af20
// address: 0x49af20
// body: available
// range: 0x49af20-0x49b0a9 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_0049af20(void *param_1)

{
  void *this;
  int iVar1;
  int iVar2;
  uint uVar3;
  
  DAT_0057ca34 = *(undefined4 *)(DAT_0057c670 + 0x2f4);
  uVar3 = (uint)*(ushort *)
                 (*(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4) + 0x5c);
  FUN_00532330(param_1,0,3,0x436);
  Window_GadgetNotify_Button_SetState(param_1,DAT_0057ca30 + 0x436,1);
  FUN_00532330(param_1,1,8,0x45b);
  AdvertisingScreen_UpdateGroupPrices(param_1);
  Window_GadgetNotify_Button_SetState(param_1,0x434,uVar3 & 0x10);
  Window_GadgetNotify_Button_SetState(param_1,0x435,uVar3 & 0x20);
  iVar1 = FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  iVar2 = FUN_00482820(DAT_0057c670);
  if (*(int *)(iVar1 + 0xc20 + iVar2 * 4) < 3) {
    FUN_005316f0(param_1,0x434,0);
    FUN_005316f0(param_1,0x435,0);
    FUN_005316f0(param_1,0x43d,0);
    FUN_005316f0(param_1,0x43e,0);
    FUN_005316f0(param_1,0x43f,0);
  }
  this = *(void **)(DAT_0057c670 + 0x98);
  if (this == (void *)0x0) {
    iVar1 = 0;
    do {
      FUN_004a80e0(param_1,0x4e9,iVar1,0,0);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 8);
    return;
  }
  iVar1 = 0;
  do {
    iVar2 = FUN_005104d0(this,iVar1);
    FUN_004a80e0(param_1,0x4e9,iVar1,iVar2,DAT_0058155c);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 8);
  return;
}

