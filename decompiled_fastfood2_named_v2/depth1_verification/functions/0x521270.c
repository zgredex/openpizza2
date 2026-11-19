// rea decompile_all
// name: FUN_00521270
// address: 0x521270
// body: available
// range: 0x521270-0x521378 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00521270(void *this,void *param_1,int param_2,int param_3)

{
  char cVar1;
  void *this_00;
  void *this_01;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  undefined3 extraout_var;
  
  if (*(code **)((int)this + 0x70) != (code *)0x0) {
    iVar3 = (**(code **)((int)this + 0x70))(this,*(undefined4 *)((int)this + 0x74));
    if (iVar3 == 0) {
      FUN_00521b90((int)this);
    }
  }
  iVar3 = *(int *)(*(int *)((int)this + 0x68) + 0x28);
  iVar4 = FUN_0053d480(*(void **)((int)this + 0x60));
  if (iVar3 == iVar4) {
    cVar1 = *(char *)(*(int *)((int)this + 0x60) + 5);
    uVar2 = FUN_0053d420(*(int *)((int)this + 0x60));
    if ((CONCAT31(extraout_var,uVar2) != 0) || (cVar1 != '\x10')) {
      FUN_0053d570(*(void **)((int)this + 0x60),(int)param_1,
                   (uint *)(*(int *)((int)this + 0x38) + param_2),
                   *(int *)((int)this + 0x3c) + param_3);
      return;
    }
  }
  else {
    this_00 = *(void **)((int)this + 100);
    if (*(char *)((int)this_00 + 5) != '\x10') {
      FUN_0053d570(this_00,(int)param_1,(uint *)(*(int *)((int)this + 0x38) + param_2),
                   *(int *)((int)this + 0x3c) + param_3);
      return;
    }
    this_01 = *(void **)((int)this + 0x68);
    if (*(char *)((int)this_00 + 0x39) == '\0') {
      FUN_0053cea0(this_00);
    }
    Surface_Configure(this_01,*(undefined4 *)((int)this_00 + 0x2c),
                      (ushort)((int)*(short *)((int)this_00 + 6) >> 1),*(ushort *)((int)this_00 + 8)
                      ,(int)*(short *)((int)this_00 + 6));
  }
  FUN_005396e0(*(int *)((int)this + 0x68));
  iVar3 = *(int *)((int)this + 0x68);
  FUN_00539380(param_1,*(int *)((int)this + 0x38) + param_2,*(int *)((int)this + 0x3c) + param_3,
               (uint)*(ushort *)(iVar3 + 0x1a),(uint)*(ushort *)(iVar3 + 0x1c),iVar3,0,0);
  return;
}

