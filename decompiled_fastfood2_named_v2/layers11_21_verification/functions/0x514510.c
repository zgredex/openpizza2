// rea decompile_all
// name: Storage_OrderDelivery
// address: 0x514510
// body: available
// range: 0x514510-0x51457e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall Storage_OrderDelivery(int param_1)

{
  int iVar1;
  void *this;
  void *pvVar2;
  
                    /* Orders a supply pickup when storage is below the threshold. */
  iVar1 = FUN_005144f0(param_1);
  if (iVar1 < 0x22) {
    iVar1 = FUN_0048a130(DAT_0057c670,0x18,0xc,*(int *)(param_1 + 0x34),-1);
    if (((iVar1 < 1) && (*(int *)(*(int *)(param_1 + 0x34) + 0x38) == 0)) &&
       (*(int *)(param_1 + 0x30) != -1)) {
      this = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 4),*(int *)(param_1 + 0x28),
                                  (int *)0x0);
      iVar1 = FUN_004da630(this,*(int *)(param_1 + 0x30));
      pvVar2 = (void *)FUN_004d7600(this,*(int *)(iVar1 + 0x10));
      City_SpawnDeliveryVehicles(this,param_1,pvVar2);
    }
  }
  return;
}

