// rea decompile_all
// name: FUN_004a3490
// address: 0x4a3490
// body: available
// range: 0x4a3490-0x4a36c3 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004a3490(void *param_1)

{
  void *this;
  int iVar1;
  int iVar2;
  undefined *puVar3;
  
  this = *(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  iVar2 = FUN_004e3820((int)this);
  if (iVar2 == -1) {
    FUN_00531740(param_1,0x1f84);
    FUN_00531740(param_1,0x1f85);
    FUN_00531740(param_1,0x1f86);
  }
  else {
    iVar1 = *(int *)(*(int *)(DAT_0057c670 + 0x224) + 0xa8);
    if (*(int *)(iVar1 + 0xa0) == 0) {
      if (*(int *)(iVar1 + 0x184) != 0) {
        iVar2 = (iVar2 * 0xf) / 10;
      }
    }
    else {
      iVar2 = 0;
    }
    Gadget_SetTextf(param_1,0x1f84,(byte *)s__s__d_00568964,DAT_00581180);
    Gadget_SetTextf(param_1,0x1f85,&DAT_005683a4,iVar2);
  }
  iVar2 = FUN_004e3890((int)this);
  if (iVar2 == -1) {
    FUN_00531740(param_1,0x1f72);
    FUN_00531740(param_1,0x1f73);
    FUN_00531740(param_1,0x1f74);
  }
  else {
    iVar1 = *(int *)(*(int *)(DAT_0057c670 + 0x224) + 0xa8);
    if (*(int *)(iVar1 + 0xa4) == 0) {
      if (*(int *)(iVar1 + 0x188) != 0) {
        iVar2 = (iVar2 * 0xf) / 10;
      }
    }
    else {
      iVar2 = 0;
    }
    Gadget_SetTextf(param_1,0x1f72,(byte *)s__s__d_00568964,DAT_00581a0c);
    Gadget_SetTextf(param_1,0x1f73,&DAT_005683a4,iVar2);
  }
  puVar3 = FUN_004e25b0(this,0x1e,0);
  Gadget_SetTextf(param_1,0x1f77,&DAT_005686f4,puVar3);
  puVar3 = FUN_004e25b0(this,0x1e,1);
  Gadget_SetTextf(param_1,0x1f76,&DAT_005686f4,puVar3);
  puVar3 = FUN_004e25b0(this,0x1e,2);
  Gadget_SetTextf(param_1,0x1f78,&DAT_005686f4,puVar3);
  puVar3 = FUN_004e25b0(this,0x1d,0);
  Gadget_SetTextf(param_1,0x1f7d,&DAT_005686f4,puVar3);
  puVar3 = FUN_004e25b0(this,0x1d,1);
  Gadget_SetTextf(param_1,0x1f7c,&DAT_005686f4,puVar3);
  puVar3 = FUN_004e25b0(this,0x1d,2);
  Gadget_SetTextf(param_1,0x1f7e,&DAT_005686f4,puVar3);
  SyndicateMenu_FillStaffCounts(param_1);
  FUN_004a3230(param_1);
  return;
}

