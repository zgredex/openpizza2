// rea decompile_all
// name: FUN_0047c2b0
// address: 0x47c2b0
// body: available
// range: 0x47c2b0-0x47c360 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_0047c2b0(void *this,int param_1)

{
  void *this_00;
  undefined4 *this_01;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00557f8b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(int *)((int)this + 0x16f0) = param_1;
  *(undefined4 *)(param_1 + 0x94) = 0;
  this_01 = *(undefined4 **)(*(int *)((int)this + 0x16f0) + 0x74);
  if (this_01 == (undefined4 *)0x0) {
    this_00 = operator_new(0x20);
    local_4 = 0;
    if (this_00 == (void *)0x0) {
      this_01 = (undefined4 *)0x0;
    }
    else {
      this_01 = BuildingValue_Construct
                          (this_00,*(undefined4 *)((int)this + 0x38),
                           *(undefined4 *)((int)this + 0x30));
    }
    local_4 = 0xffffffff;
    *(undefined4 **)(*(int *)((int)this + 0x16f0) + 0x74) = this_01;
  }
  else {
    FUN_004e43a0(this_01,*(undefined4 *)((int)this + 0x38));
    FUN_004e4760(this_01,*(undefined4 *)((int)this + 0x30));
  }
  this_01[6] = 0;
  this_01[4] = 0;
  this_01[5] = 0;
  FUN_004810e0((int)this);
  ExceptionList = local_c;
  return;
}

