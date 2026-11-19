// rea decompile_all
// name: Game_GetRecordActionState
// address: 0x483d10
// body: available
// range: 0x483d10-0x483e5d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall Game_GetRecordActionState(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  void *this_00;
  int *piVar3;
  int iVar4;
  
                    /* Depth-2 proposal batch 2/4. */
  switch(*(undefined4 *)(param_1 + 0x30)) {
  default:
    return 0xf;
  case 10:
    return 0x10;
  case 0x10:
    break;
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
    iVar1 = FUN_004017f0((void *)((int)this + 0x20),*(int *)(param_1 + 0x50),(int *)0x0);
    iVar1 = *(int *)(iVar1 + 0x81c);
    if (iVar1 == -1) {
      return 0xe;
    }
    iVar2 = FUN_00482820((int)this);
    return (-(uint)(iVar1 != iVar2) & 0xfffffffa) + 0x1d;
  case 0x16:
    return 2;
  case 0x17:
    iVar1 = *(int *)(param_1 + 0x110);
    if (iVar1 == -1) {
      return 0xc;
    }
    iVar2 = FUN_00482820((int)this);
    return (-(uint)(iVar1 != iVar2) & 0xfffffffa) + 0x13;
  case 0x18:
    return 6;
  case 0x1a:
  case 0x1b:
  case 0x1c:
    return 0x18;
  case 0x1d:
  case 0x1e:
  case 0x1f:
    iVar1 = *(int *)(param_1 + 0x110);
    iVar2 = FUN_00482820((int)this);
    return (-(uint)(iVar1 != iVar2) & 0xfffffff1) + 0x11;
  }
  iVar1 = FUN_004017f0((void *)((int)this + 0x20),*(int *)(param_1 + 0x50),(int *)0x0);
  this_00 = (void *)FUN_004017f0((void *)((int)this + 4),*(int *)((int)this + 0x2f4),(int *)0x0);
  piVar3 = FUN_004d6a90(this_00,iVar1);
  if (piVar3 != (int *)0x0) {
    return 0xe;
  }
  iVar2 = *(int *)(iVar1 + 0x81c);
  iVar4 = FUN_00482820((int)this);
  if (iVar2 == iVar4) {
    return 0x1d;
  }
  return (-(uint)(*(int *)(iVar1 + 0x81c) != -1) & 9) + 0xe;
}

