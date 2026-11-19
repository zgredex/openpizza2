// rea decompile_all
// name: FUN_004d1fe0
// address: 0x4d1fe0
// body: available
// range: 0x4d1fe0-0x4d21f4 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004d1fe0(void *this,void *param_1)

{
  int *piVar1;
  void *this_00;
  int iVar2;
  void *local_4;
  
  this_00 = param_1;
  local_4 = this;
  FUN_0054cc2b(param_1,(int)this + 4,4);
  FUN_0054cc2b(this_00,(int)this + 8,4);
  FUN_0054cc2b(this_00,(int)this + 0x4c,4);
  FUN_0054cc2b(this_00,(int)this + 0x50,4);
  FUN_0054cc2b(this_00,(int)this + 0x2c,4);
  FUN_0054cc2b(this_00,(int)this + 0x30,4);
  FUN_0054cc2b(this_00,(int)this + 0x34,4);
  FUN_0054cc2b(this_00,(int)this + 0x38,4);
  FUN_0054cc2b(this_00,(int)this + 0xc,4);
  FUN_0054cc2b(this_00,(int)this + 0x3c,4);
  FUN_0054cc2b(this_00,(int)this + 0x94,4);
  FUN_0054cc2b(this_00,(int)this + 0x10,0x10);
  FUN_0054cc2b(this_00,(int)this + 0x20,4);
  FUN_0054cc2b(this_00,(int)this + 0x24,4);
  FUN_0054cc2b(this_00,(int)this + 0x40,8);
  FUN_0054cc2b(this_00,(int)this + 0x48,4);
  FUN_0054cc2b(this_00,(int)this + 0x54,4);
  piVar1 = (int *)((int)this + 0x28);
  FUN_0054cc2b(this_00,piVar1,4);
  if (*piVar1 == -1) {
    FUN_0048e0a0();
  }
  iVar2 = FUN_004017f0((void *)(DAT_0057c670 + 4),*piVar1,(int *)0x0);
  param_1 = (void *)FUN_004eacb0(DAT_0057c5cc,*(int *)(iVar2 + 0xfa8));
  FUN_0054cc2b(this_00,&param_1,4);
  param_1 = *(void **)((int)this + 0x6c);
  FUN_0054cc2b(this_00,&param_1,4);
  iVar2 = 0;
  if (0 < *(int *)((int)this + 0x6c)) {
    do {
      param_1 = (void *)FUN_004017f0((void *)((int)this + 0x58),iVar2,(int *)0x0);
      FUN_0054cc2b(this_00,&param_1,4);
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)((int)this + 0x6c));
  }
  if (*(int *)((int)this + 0x74) == 0) {
    param_1 = (void *)0x0;
    FUN_0054cc2b(this_00,&param_1,4);
  }
  else {
    param_1 = (void *)0x1;
    FUN_0054cc2b(this_00,&param_1,4);
    BuildingValue_Save(*(void **)((int)this + 0x74),this_00);
  }
  param_1 = *(void **)((int)this + 0x8c);
  FUN_0054cc2b(this_00,&param_1,4);
  iVar2 = 0;
  if (0 < (int)param_1) {
    do {
      local_4 = (void *)FUN_004017f0((void *)((int)this + 0x78),iVar2,(int *)0x0);
      FUN_0054cc2b(this_00,&local_4,4);
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)param_1);
  }
  return;
}

