// rea decompile_all
// name: FUN_004f8710
// address: 0x4f8710
// body: available
// range: 0x4f8710-0x4f88b2 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_004f8710(void *param_1)

{
  int iVar1;
  undefined4 *this;
  undefined4 *this_00;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  longlong lVar6;
  int *piVar7;
  uint local_20;
  void *local_1c;
  int local_18;
  int local_10;
  int local_c;
  
  local_c = 0;
  this = FUN_004d59c0(param_1,0,0,'\x01');
  this_00 = FUN_004d59c0(param_1,0x11,0,'\0');
  iVar1 = this[5];
  local_1c = (void *)0x0;
  local_10 = 0;
  do {
    local_18 = 0;
    if (0 < iVar1 >> 3) {
      local_20 = 8;
      do {
        piVar7 = (int *)0x0;
        uVar2 = Random_Range(local_18 * 8,local_20);
        iVar3 = IDMap_Lookup(this,uVar2,piVar7);
        if (iVar3 != 0) {
          uVar2 = _rand();
          param_1 = (void *)((uVar2 & 0x3f) + 4000);
          iVar5 = 0;
          if (0 < (int)this_00[5]) {
            do {
              iVar4 = IDMap_Lookup(this_00,iVar5,(int *)0x0);
              FUN_004d2320(iVar3);
              FUN_004d2320(iVar4);
              FUN_004d2360(iVar3);
              FUN_004d2360(iVar4);
              lVar6 = __ftol();
              if ((int)lVar6 < 1000) {
                param_1 = (void *)((int)param_1 + (int)lVar6 + -1000);
              }
              iVar5 = iVar5 + 1;
            } while (iVar5 < (int)this_00[5]);
          }
          if ((int)local_1c < (int)param_1) {
            local_1c = param_1;
            local_c = iVar3;
          }
        }
        local_18 = local_18 + 1;
        local_20 = local_20 + 8;
      } while (local_18 < iVar1 >> 3);
    }
  } while (((int)param_1 < 1) && (local_10 = local_10 + 1, local_10 < 10));
  if (this != (undefined4 *)0x0) {
    (**(code **)*this)(1);
  }
  if (this_00 != (undefined4 *)0x0) {
    (**(code **)*this_00)(1);
  }
  if ((int)local_1c < 1) {
    return 0;
  }
  return local_c;
}

