// rea decompile_all
// name: FUN_0047c5e0
// address: 0x47c5e0
// body: available
// range: 0x47c5e0-0x47c72d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_0047c5e0(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *this_00;
  undefined4 *puVar3;
  float local_8;
  int iStack_4;
  
  iVar1 = FUN_00488be0(DAT_0057c670,*(int *)((int)this + 0x30));
  iVar2 = FUN_004ddcc0(iVar1);
  local_8 = 0.0;
  FUN_0047c730((int)this);
  iVar1 = *(int *)((int)this + 0x170c);
  while (0 < iVar1) {
    this_00 = (undefined4 *)FUN_004017f0((void *)((int)this + 0x16f8),0,(int *)0x0);
    puVar3 = FUN_004f2b60(*(void **)((int)this + 0x14e0),(int)this_00);
    FUN_004f2fc0(*(void **)((int)this + 0x14e0),0,puVar3);
    if (puVar3 != (undefined4 *)0x0) {
      (**(code **)*puVar3)(1);
    }
    iVar1 = *(int *)(*(int *)((int)this + 0x14e0) + 0x4c) + this_00[8] * 0xc;
    FUN_004f5db0(iVar1);
    FUN_004ed330(*(void **)((int)this + 0x14e0),iVar1,-1,1);
    FUN_0047c5b0(this,(int)this_00);
    FUN_004e5f40(this_00,iVar2,&iStack_4);
    local_8 = (float)iStack_4 + local_8;
    if (this_00 != (undefined4 *)0x0) {
      (**(code **)*this_00)(1);
    }
    iVar1 = *(int *)((int)this + 0x170c);
  }
  FUN_004f2e50(*(void **)((int)this + 0x14e0),(int)this);
  if (param_1 == 0) {
    FUN_00477c80(this,0x15,local_8,-1);
  }
  FUN_0047f5f0(this);
  *(undefined4 *)((int)this + 0x1718) = 0;
  if (*(int *)((int)DAT_0057c670 + 0x2fc) == *(int *)((int)this + 0x14e0)) {
    *(undefined4 *)(*(int *)((int)this + 0x14e0) + 0xf4) = 1;
  }
  if (param_1 == 0) {
    *(uint *)((int)this + 0x28) = *(uint *)((int)this + 0x28) | 4;
    Game_CheckObjectUpgrade(this);
  }
  return;
}

