// rea decompile_all
// name: PersonList_Save
// address: 0x5053d0
// body: available
// range: 0x5053d0-0x505904 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall PersonList_Save(void *this,void *param_1)

{
  void *this_00;
  void *this_01;
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int local_c;
  int local_8;
  undefined4 local_4;
  
                    /* Serializes the city's person list and removes stale map entries. */
  this_00 = param_1;
  this_01 = (void *)FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)((int)this + 0x28),(int *)0x0);
  FUN_0054cc2b(param_1,(int)this + 4,0x20);
  FUN_0054cc2b(param_1,(int)this + 0x24,4);
  FUN_0054cc2b(param_1,(int)this + 0x28,4);
  FUN_0054cc2b(param_1,(int)this + 0x30,4);
  FUN_0054cc2b(param_1,(int)this + 0x34,4);
  FUN_0054cc2b(param_1,(int)this + 0x38,4);
  FUN_0054cc2b(param_1,(int)this + 0x3c,4);
  FUN_0054cc2b(param_1,(int)this + 0x40,2);
  FUN_0054cc2b(param_1,(int)this + 0x44,4);
  FUN_0054cc2b(param_1,(int)this + 0x48,4);
  FUN_0054cc2b(param_1,(int)this + 0x4c,4);
  FUN_0054cc2b(param_1,(int)this + 0x50,4);
  FUN_0054cc2b(param_1,(int)this + 0x54,4);
  FUN_0054cc2b(param_1,(int)this + 0x58,4);
  FUN_0054cc2b(param_1,(int)this + 0x5c,0x18);
  FUN_0054cc2b(param_1,(int)this + 0x74,4);
  FUN_0054cc2b(param_1,(int)this + 0x78,4);
  FUN_0054cc2b(param_1,(int)this + 0x7c,4);
  FUN_0054cc2b(param_1,(int)this + 0x80,1);
  FUN_0054cc2b(param_1,(int)this + 0x81,1);
  FUN_0054cc2b(param_1,(int)this + 0x84,4);
  FUN_0054cc2b(param_1,(int)this + 0x88,4);
  FUN_0054cc2b(param_1,(int)this + 0x8c,4);
  FUN_0054cc2b(param_1,(int)this + 0x90,4);
  FUN_0054cc2b(param_1,(int)this + 0x10c,4);
  FUN_0054cc2b(param_1,(int)this + 0x94,4);
  FUN_0054cc2b(param_1,(int)this + 0x98,4);
  FUN_0054cc2b(param_1,(int)this + 0x9c,4);
  FUN_0054cc2b(param_1,(int)this + 0x14c,0x18);
  FUN_0054cc2b(param_1,(int)this + 0xa0,4);
  FUN_0054cc2b(param_1,(int)this + 0xa4,4);
  FUN_0054cc2b(param_1,(int)this + 0xa8,4);
  FUN_0054cc2b(param_1,(int)this + 0x110,4);
  FUN_0054cc2b(param_1,(int)this + 0x104,1);
  FUN_0054cc2b(param_1,(int)this + 0x108,4);
  FUN_0054cc2b(param_1,(int)this + 0xac,0x18);
  FUN_0054cc2b(param_1,(int)this + 0x2c,4);
  local_c = FUN_004eacb0(DAT_0057c5cc,*(int *)((int)this + 0xc4));
  FUN_0054cc2b(param_1,&local_c,4);
  FUN_005052e0(this,param_1);
  if (*(int *)((int)this + 0xcc) == 0) {
    local_c = 0;
  }
  else {
    local_c = 1;
    FUN_0054cc2b(param_1,&local_c,4);
    local_c = FUN_004d75b0(this_01,*(int *)((int)this + 0xcc));
  }
  FUN_0054cc2b(param_1,&local_c,4);
  if (*(int *)((int)this + 0xfc) == 0) {
    local_c = 0;
  }
  else {
    local_c = 1;
    FUN_0054cc2b(param_1,&local_c,4);
    local_c = FUN_004d75b0(this_01,*(int *)((int)this + 0xfc));
  }
  FUN_0054cc2b(param_1,&local_c,4);
  if (*(int *)((int)this + 0x100) == 0) {
    local_c = 0;
  }
  else {
    local_c = 1;
    FUN_0054cc2b(param_1,&local_c,4);
    local_c = FUN_004d75b0(this_01,*(int *)((int)this + 0x100));
  }
  FUN_0054cc2b(param_1,&local_c,4);
  if (*(int *)((int)this + 0xd0) == 0) {
    local_c = 0;
  }
  else {
    local_c = 1;
    FUN_0054cc2b(param_1,&local_c,4);
    local_c = FUN_004d75b0(this_01,*(int *)((int)this + 0xd0));
  }
  FUN_0054cc2b(param_1,&local_c,4);
  piVar2 = (int *)((int)this + 0xd4);
  param_1 = (void *)0x8;
  do {
    if (*piVar2 == 0) {
      local_c = 0;
    }
    else {
      local_c = 1;
      FUN_0054cc2b(this_00,&local_c,4);
      local_c = FUN_004d75b0(this_01,*piVar2);
    }
    FUN_0054cc2b(this_00,&local_c,4);
    piVar2 = piVar2 + 1;
    param_1 = (void *)((int)param_1 + -1);
  } while (param_1 != (void *)0x0);
  if (*(int *)((int)this + 0xf4) == 0) {
    local_c = 0;
  }
  else {
    local_c = 1;
    FUN_0054cc2b(this_00,&local_c,4);
    local_c = FUN_004d75b0(this_01,*(int *)((int)this + 0xf4));
  }
  FUN_0054cc2b(this_00,&local_c,4);
  if (*(int *)((int)this + 0xf8) == 0) {
    piVar2 = &local_c;
    uVar3 = 4;
    local_c = 0;
  }
  else {
    local_c = 1;
    FUN_0054cc2b(this_00,&local_c,4);
    uVar3 = 2;
    piVar2 = (int *)(*(int *)((int)this + 0xf8) + 2);
  }
  FUN_0054cc2b(this_00,piVar2,uVar3);
  local_8 = *(int *)((int)this + 0x128);
  FUN_0054cc2b(this_00,&local_8,4);
  local_c = 0;
  if (0 < local_8) {
    do {
      local_4 = FUN_004017f0((void *)((int)this + 0x114),local_c,(int *)0x0);
      FUN_0054cc2b(this_00,&local_4,4);
      local_c = local_c + 1;
    } while (local_c < local_8);
  }
  local_8 = *(int *)((int)this + 0x144);
  FUN_0054cc2b(this_00,&local_8,4);
  local_c = 0;
  if (0 < local_8) {
    do {
      iVar1 = FUN_004017f0((void *)((int)this + 0x130),local_c,(int *)0x0);
      local_4 = FUN_004d75b0(this_01,iVar1);
      FUN_0054cc2b(this_00,&local_4,4);
      local_c = local_c + 1;
    } while (local_c < local_8);
  }
  return;
}

