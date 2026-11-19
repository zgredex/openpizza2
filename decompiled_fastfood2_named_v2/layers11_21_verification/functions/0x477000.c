// rea decompile_all
// name: Branch_ConstructFromStream
// address: 0x477000
// body: available
// range: 0x477000-0x4770f6 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall Branch_ConstructFromStream(void *this,void *param_1,undefined4 *param_2)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* Constructs a branch and loads its state from a save stream. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00557eee;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004013a0((void *)((int)this + 0x14e4),0);
  local_4 = 0;
  FUN_004013a0((void *)((int)this + 0x1500),0);
  local_4._0_1_ = 1;
  FUN_004013a0((void *)((int)this + 0x16f8),0);
  local_4._0_1_ = 2;
  FUN_004013a0((void *)((int)this + 0x1728),0);
  local_4._0_1_ = 3;
  FUN_004013a0((void *)((int)this + 0x1744),0);
  local_4._0_1_ = 4;
  FUN_004013a0((void *)((int)this + 0x1760),0);
  local_4._0_1_ = 5;
  FUN_004013a0((void *)((int)this + 0x1998),0);
  local_4._0_1_ = 6;
  FUN_004013a0((void *)((int)this + 0x19c4),0);
  local_4._0_1_ = 7;
  FUN_004013a0((void *)((int)this + 0x19e0),0);
  local_4 = CONCAT31(local_4._1_3_,8);
  *(undefined ***)this = &PTR_FUN_0055c30c;
  *(undefined4 *)((int)this + 0x1a28) = 0;
  Branch_Load(this,param_1,param_2);
  ExceptionList = local_c;
  return this;
}

