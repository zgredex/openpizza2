// rea decompile_all
// name: Storage_DistributeCostToShops
// address: 0x514100
// body: available
// range: 0x514100-0x5141b4 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Storage_DistributeCostToShops(void *this,float param_1,char param_2)

{
  void *this_00;
  void *this_01;
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
                    /* Distributes a storage cost across active served shops or charges the company.
                        */
  iVar3 = 0;
  this_00 = (void *)FUN_00488be0(DAT_0057c670,*(int *)((int)this + 0x24));
  piVar4 = (int *)((int)this + 0x60);
  iVar1 = 0x14;
  iVar2 = (-(uint)(param_2 != '\0') & 0xfffffff2) + 0xe;
  do {
    if (*piVar4 != 0) {
      iVar3 = iVar3 + 1;
    }
    piVar4 = piVar4 + 3;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if (iVar3 == 0) {
    FUN_004e0b60(this_00,iVar2,param_1,'\0',0xffffffff);
    return;
  }
  piVar4 = (int *)((int)this + 100);
  _param_2 = 0x14;
  do {
    if (piVar4[-1] != 0) {
      this_01 = (void *)FUN_004017f0((void *)((int)this_00 + 0x148),*piVar4,(int *)0x0);
      FUN_00477e40(this_01,iVar2,param_1 / (float)iVar3,'\0',-1);
    }
    piVar4 = piVar4 + 3;
    _param_2 = _param_2 + -1;
  } while (_param_2 != 0);
  return;
}

