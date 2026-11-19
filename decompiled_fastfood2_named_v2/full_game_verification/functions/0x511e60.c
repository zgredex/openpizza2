// rea decompile_all
// name: Recipe_CollectCategoryCandidates
// address: 0x511e60
// body: available
// range: 0x511e60-0x511f98 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * Recipe_CollectCategoryCandidates(void *param_1,uint param_2,char param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *this;
  void *this_00;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 *local_2cc;
  int local_2c8;
  int local_2c4;
  uint local_2c0;
  int local_2bc [172];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a4be;
  local_c = ExceptionList;
  iVar5 = 0;
  ExceptionList = &local_c;
  this = Ingredient_CollectByCategory(DAT_0057c670,param_3);
  this_00 = operator_new(0x1c);
  local_4 = 0;
  if (this_00 == (void *)0x0) {
    local_2cc = (undefined4 *)0x0;
  }
  else {
    local_2cc = List_Construct(this_00,0);
  }
  local_4 = 0xffffffff;
  if (0 < (int)this[5]) {
    piVar4 = local_2bc + 1;
    do {
      iVar3 = IDMap_Lookup(this,iVar5,(int *)0x0);
      piVar4[-1] = iVar3;
      iVar3 = Market_ComputeValueAdjustment(param_1,'\x01',param_2,iVar3,&local_2c0,&local_2c4);
      *piVar4 = iVar3;
      iVar5 = iVar5 + 1;
      piVar4 = piVar4 + 2;
    } while (iVar5 < (int)this[5]);
  }
  for (iVar3 = iVar5 + -2; 0 < iVar3; iVar3 = iVar3 + -1) {
    piVar4 = local_2bc;
    local_2c8 = iVar3;
    do {
      if (piVar4[1] < piVar4[3]) {
        iVar1 = *piVar4;
        iVar2 = piVar4[1];
        *piVar4 = piVar4[2];
        piVar4[1] = piVar4[3];
        piVar4[2] = iVar1;
        piVar4[3] = iVar2;
      }
      piVar4 = piVar4 + 2;
      local_2c8 = local_2c8 + -1;
    } while (local_2c8 != 0);
  }
  if (0 < iVar5) {
    piVar4 = local_2bc;
    do {
      List_Add(local_2cc,*piVar4);
      piVar4 = piVar4 + 2;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  if (this != (undefined4 *)0x0) {
    (**(code **)*this)(1);
  }
  ExceptionList = local_c;
  return local_2cc;
}

