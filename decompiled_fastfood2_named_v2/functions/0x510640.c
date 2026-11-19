// rea decompile_all
// name: FUN_00510640
// address: 0x510640
// body: available
// range: 0x510640-0x5108d3 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00510640(void *this,void *param_1,char param_2)

{
  void *this_00;
  void *this_01;
  int iVar1;
  void *pvVar2;
  void *local_4;
  
  this_00 = param_1;
  local_4 = this;
  FUN_0054cc2b(param_1,(int)this + 4,0x40);
  FUN_0054cc2b(this_00,(int)this + 0x44,4);
  local_4 = *(void **)((int)this + 0x5c);
  FUN_0054cc2b(this_00,&local_4,4);
  param_1 = (void *)0x0;
  if (0 < (int)local_4) {
    do {
      pvVar2 = this_00;
      this_01 = (void *)IDMap_Lookup((void *)((int)this + 0x48),(int)param_1,(int *)0x0);
      FUN_004d1ba0(this_01,pvVar2);
      param_1 = (void *)((int)param_1 + 1);
    } while ((int)param_1 < (int)local_4);
  }
  FUN_0054cc2b(this_00,(int)this + 100,0x158);
  FUN_0054cc2b(this_00,(int)this + 0x1bc,0x1c);
  FUN_0054cc2b(this_00,(int)this + 0x1d8,4);
  FUN_0054cc2b(this_00,(int)this + 0x1dc,1);
  FUN_0054cc2b(this_00,(int)this + 0x1e0,0x60);
  FUN_0054cc2b(this_00,(int)this + 0x240,4);
  FUN_0054cc2b(this_00,(int)this + 0x244,4);
  FUN_0054cc2b(this_00,(int)this + 0x248,4);
  FUN_0054cc2b(this_00,(int)this + 0x24c,4);
  FUN_0054cc2b(this_00,(int)this + 0x250,4);
  FUN_0054cc2b(this_00,(int)this + 0x254,4);
  FUN_0054cc2b(this_00,(int)this + 600,4);
  FUN_0054cc2b(this_00,(int)this + 0x264,0x20);
  FUN_0054cc2b(this_00,(int)this + 0x284,0x20);
  FUN_0054cc2b(this_00,(int)this + 0x2a4,0x20);
  FUN_0054cc2b(this_00,(int)this + 0x2c4,0x20);
  if (*(int *)((int)this + 0x304) == 0) {
    param_1 = (void *)0x0;
    FUN_0054cc2b(this_00,&param_1,4);
  }
  else if (param_2 == '\0') {
    param_1 = (void *)0x0;
    FUN_0054cc2b(this_00,&param_1,4);
  }
  else {
    param_1 = (void *)0x1;
    FUN_0054cc2b(this_00,&param_1,4);
    local_4 = *(void **)(*(int *)((int)this + 0x304) + 0x14);
    FUN_0054cc2b(this_00,&local_4,4);
    param_1 = (void *)0x0;
    if (0 < (int)local_4) {
      do {
        iVar1 = IDMap_Lookup(*(void **)((int)this + 0x304),(int)param_1,(int *)0x0);
        FUN_0054cc2b(this_00,iVar1,4);
        FUN_0054cc2b(this_00,iVar1 + 4,4);
        FUN_0054cc2b(this_00,iVar1 + 8,4);
        FUN_0054cc2b(this_00,iVar1 + 0xc,4);
        FUN_0054cc2b(this_00,iVar1 + 0x10,4);
        FUN_0054cc2b(this_00,iVar1 + 0x14,4);
        FUN_0054cc2b(this_00,iVar1 + 0x18,4);
        param_1 = (void *)((int)param_1 + 1);
      } while ((int)param_1 < (int)local_4);
    }
  }
  FUN_0054cc2b(this_00,(int)this + 0x308,4);
  FUN_0054cc2b(this_00,(int)this + 0x30c,4);
  return;
}

