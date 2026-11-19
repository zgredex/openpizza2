// rea decompile_all
// name: FUN_004f8bf0
// address: 0x4f8bf0
// body: available
// range: 0x4f8bf0-0x4f8d32 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_004f8bf0(void *this,int param_1)

{
  void *pvVar1;
  void *this_00;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int local_20;
  int local_1c;
  int local_18;
  void *local_14;
  int local_10 [4];
  
  local_18 = *(int *)((int)this + param_1 * 0x168 + 0x40);
  pvVar1 = (void *)((int)this + param_1 * 0x168);
  local_14 = pvVar1;
  this_00 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),
                                 (int *)0x0);
  iVar5 = 0;
  local_20 = 0;
  iVar7 = *(int *)(*(int *)((int)pvVar1 + 0x70) + 0x15c);
  if (0 < iVar7) {
    do {
      iVar2 = FUN_00500e80(this,param_1,iVar5,1);
      if ((iVar2 != 0) && (iVar2 = FUN_004f7b90(iVar2,&local_1c,local_10,4), 0 < iVar2)) {
        local_20 = local_20 + local_1c / iVar2;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar7);
    if (0 < local_20) {
      iVar7 = (local_20 * 0x11) / 100;
      goto LAB_004f8ca6;
    }
  }
  iVar7 = 0;
LAB_004f8ca6:
  iVar2 = local_18;
  iVar5 = *(int *)((int)this_00 + local_18 * 4 + 0xdac);
  if (iVar7 < iVar5) {
    FUN_004da200(this_00,local_18,0);
    *(undefined4 *)((int)this_00 + iVar2 * 4 + 0xcc8) = 0;
  }
  else {
    iVar3 = FUN_004d8090((int)this_00);
    if (iVar3 == iVar2) {
      return 1;
    }
    uVar6 = iVar5 + 5000;
    if (((int)uVar6 <= iVar7) &&
       (uVar4 = FUN_004e0b60(*(void **)((int)local_14 + 0x70),0x14,5000.0,'\x01',0xffffffff),
       (char)uVar4 != '\0')) {
      FUN_004da200(this_00,iVar2,uVar6);
      return 1;
    }
  }
  return 0;
}

