// rea decompile_all
// name: AI_FindCheapestShop
// address: 0x4f88c0
// body: available
// range: 0x4f88c0-0x4f89c5 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int AI_FindCheapestShop(int param_1,void *param_2,int param_3)

{
  int iVar1;
  undefined4 *this;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  this = City_CollectBuildingsByType(param_2,-1,0,'\x01');
  iVar1 = this[5];
  local_14 = 0;
  do {
    iVar6 = 0;
    if (local_14 == 8) {
      param_3 = 0;
    }
    iVar5 = 0;
    local_10 = 0;
    if (0 < iVar1 >> 3) {
      uVar4 = 8;
      do {
        piVar7 = (int *)0x0;
        uVar2 = Random_RangeFast(iVar6 * 8,uVar4);
        iVar3 = IDMap_Lookup(this,uVar2,piVar7);
        if (((iVar3 != 0) &&
            (((Game_ComputeTradeOffers(param_2,iVar3,1,&local_4,&local_8,param_1,&local_c),
              param_3 == 0 || (local_c != 0)) && (local_8 != 0)))) &&
           ((iVar5 == 0 || (local_8 < iVar5)))) {
          iVar5 = local_8;
          local_10 = iVar3;
        }
        iVar6 = iVar6 + 1;
        uVar4 = uVar4 + 8;
      } while (iVar6 < iVar1 >> 3);
      if (iVar5 != 0) break;
    }
    local_14 = local_14 + 1;
  } while (local_14 < 10);
  if (this != (undefined4 *)0x0) {
    (**(code **)*this)(1);
  }
  if (iVar5 == 0) {
    return 0;
  }
  return local_10;
}

