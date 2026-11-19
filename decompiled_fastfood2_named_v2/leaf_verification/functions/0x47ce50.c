// rea decompile_all
// name: FUN_0047ce50
// address: 0x47ce50
// body: available
// range: 0x47ce50-0x47cff1 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_0047ce50(void *this,int param_1)

{
  char cVar1;
  void *this_00;
  int iVar2;
  int iVar3;
  int iVar4;
  
  cVar1 = FUN_004e5df0(param_1);
  if (cVar1 != '\x01') {
    return 0;
  }
  this_00 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 0x74),*(int *)(param_1 + 4),(int *)0x0);
  iVar3 = *(int *)(param_1 + 0x18);
  iVar4 = *(int *)(param_1 + 0x1c);
  iVar2 = Game_FindGroupSlot(this_00,*(int *)(*(int *)(*(int *)(*(int *)((int)this + 0x14e0) + 0x4c)
                                                       + *(int *)(param_1 + 0x20) * 0xc + 8) + 0x10)
                             ,*(int *)(param_1 + 8));
  switch(iVar2) {
  case 0:
    iVar4 = iVar4 + 4;
    iVar2 = FUN_0047e130(this,iVar3,iVar4);
    if ((iVar2 != 0) && (0 < *(int *)(iVar2 + 0xc))) {
      return 1;
    }
    iVar2 = FUN_0047e130(this,iVar3 + 1,iVar4);
    if ((iVar2 != 0) && (0 < *(int *)(iVar2 + 0xc))) {
      return 1;
    }
    iVar3 = iVar3 + 2;
    break;
  case 1:
    iVar3 = iVar3 + 4;
    iVar2 = FUN_0047e130(this,iVar3,iVar4 + 2);
    if ((iVar2 != 0) && (0 < *(int *)(iVar2 + 0xc))) {
      return 1;
    }
    iVar2 = FUN_0047e130(this,iVar3,iVar4 + 1);
    if ((iVar2 != 0) && (0 < *(int *)(iVar2 + 0xc))) {
      return 1;
    }
    break;
  case 2:
    iVar4 = iVar4 + -2;
    iVar2 = FUN_0047e130(this,iVar3 + 2,iVar4);
    if ((iVar2 != 0) && (0 < *(int *)(iVar2 + 0xc))) {
      return 1;
    }
    iVar2 = FUN_0047e130(this,iVar3 + 1,iVar4);
    if ((iVar2 != 0) && (0 < *(int *)(iVar2 + 0xc))) {
      return 1;
    }
    break;
  case 3:
    iVar3 = iVar3 + -2;
    iVar2 = FUN_0047e130(this,iVar3,iVar4 + 2);
    if ((iVar2 != 0) && (0 < *(int *)(iVar2 + 0xc))) {
      return 1;
    }
    iVar2 = FUN_0047e130(this,iVar3,iVar4 + 1);
    if ((iVar2 != 0) && (0 < *(int *)(iVar2 + 0xc))) {
      return 1;
    }
    break;
  default:
    goto switchD_0047ceb0_default;
  }
  iVar3 = FUN_0047e130(this,iVar3,iVar4);
  if ((iVar3 != 0) && (0 < *(int *)(iVar3 + 0xc))) {
    return 1;
  }
switchD_0047ceb0_default:
  return 0;
}

