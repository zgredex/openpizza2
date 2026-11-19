// rea decompile_all
// name: Player_Save
// address: 0x50ea90
// body: available
// range: 0x50ea90-0x50ec99 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Player_Save(void *this,void *param_1)

{
  void *this_00;
  void *this_01;
  void *pvVar1;
  void *local_4;
  
                    /* Serializes a player, its character, events, AI state, and mission state. */
  this_00 = param_1;
  local_4 = this;
  FUN_0054cc2b(param_1,(int)this + 0x84,4);
  FUN_0054cc2b(this_00,(int)this + 0x88,4);
  FUN_0054cc2b(this_00,(int)this + 8,4);
  FUN_0054cc2b(this_00,(int)this + 0xc,0x20);
  FUN_0054cc2b(this_00,(int)this + 0x2c,4);
  FUN_0054cc2b(this_00,(int)this + 0x30,4);
  FUN_0054cc2b(this_00,(int)this + 0x3c,4);
  FUN_0054cc2b(this_00,(int)this + 0x40,4);
  FUN_0054cc2b(this_00,(int)this + 0x44,4);
  FUN_0054cc2b(this_00,(int)this + 0x48,4);
  FUN_0054cc2b(this_00,(int)this + 0x4c,4);
  FUN_0054cc2b(this_00,(int)this + 0x50,4);
  FUN_0054cc2b(this_00,(int)this + 0x54,4);
  FUN_0054cc2b(this_00,(int)this + 0x58,4);
  FUN_0054cc2b(this_00,(int)this + 0x5c,4);
  FUN_0054cc2b(this_00,(int)this + 0x60,4);
  FUN_0054cc2b(this_00,(int)this + 100,4);
  FUN_0054cc2b(this_00,(int)this + 0x68,4);
  FUN_0054cc2b(this_00,(int)this + 0x6c,0x18);
  FUN_0054cc2b(this_00,(int)this + 0x34,4);
  FUN_0054cc2b(this_00,(int)this + 0x38,4);
  FUN_004d3ba0(*(void **)((int)this + 4),this_00);
  local_4 = *(void **)((int)this + 0xa0);
  FUN_0054cc2b(this_00,&local_4,4);
  param_1 = (void *)0x0;
  if (0 < (int)local_4) {
    do {
      pvVar1 = this_00;
      this_01 = (void *)FUN_004017f0((void *)((int)this + 0x8c),(int)param_1,(int *)0x0);
      FUN_00501a40(this_01,pvVar1);
      param_1 = (void *)((int)param_1 + 1);
    } while ((int)param_1 < (int)local_4);
  }
  if (*(int *)((int)this + 0xa8) == 0) {
    param_1 = (void *)0x0;
    FUN_0054cc2b(this_00,&param_1,4);
  }
  else {
    param_1 = (void *)0x1;
    FUN_0054cc2b(this_00,&param_1,4);
    FUN_00501cb0(*(void **)((int)this + 0xa8),this_00);
  }
  if (*(int *)((int)this + 0xac) == 0) {
    param_1 = (void *)0x0;
    FUN_0054cc2b(this_00,&param_1,4);
    return;
  }
  param_1 = (void *)0x1;
  FUN_0054cc2b(this_00,&param_1,4);
  FUN_004f5ee0(*(void **)((int)this + 0xac),this_00);
  return;
}

