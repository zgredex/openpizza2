// rea decompile_all
// name: Game_UpdatePlayerObject
// address: 0x508eb0
// body: available
// range: 0x508eb0-0x508f9e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Game_UpdatePlayerObject(void *this,int *param_1)

{
  void *this_00;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  this_00 = (void *)Game_GetPlayerSubmapValue
                              (DAT_0057c670,*(int *)(*(int *)((int)this + 0xf4) + 8),
                               *(int *)(*(int *)((int)this + 0xf4) + 0x2c));
  if (this_00 == (void *)0x0) {
    return;
  }
  iVar1 = Game_PickRandomUnownedAdjacentRecord(this_00,(int)this,1,param_1);
  if (iVar1 == 0) {
    return;
  }
  iVar3 = *(int *)(iVar1 + 0x1c);
  iVar4 = *(int *)(iVar1 + 0x18);
  iVar2 = Grid_GetCell(*(void **)((int)this + 0xc4),iVar4,iVar3);
  iVar1 = City_IndexOfListValue
                    (DAT_0057c670,*(int *)(*(int *)(iVar2 + 8) + 0x10),*(int *)(iVar1 + 4),
                     *(int *)(iVar1 + 8));
  *(int *)((int)this + 0x84) = iVar1;
  *(undefined4 *)((int)this + 0x88) = **(undefined4 **)(iVar2 + 8);
  switch(iVar1) {
  case 0:
    iVar4 = iVar4 + 3;
    break;
  case 1:
    iVar3 = iVar3 + -3;
    break;
  case 2:
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + -2;
    break;
  case 3:
    iVar3 = iVar3 + 3;
    iVar4 = iVar4 + 1;
    break;
  default:
    goto switchD_00508f3b_default;
  }
  iVar2 = Grid_GetCell(*(void **)((int)this + 0xc4),iVar4,iVar3);
switchD_00508f3b_default:
  *(undefined4 *)((int)this + 0x8c) = **(undefined4 **)(iVar2 + 8);
  Array_GetRecord28(*(void **)((int)this + 0xc4),1,(int)*(short *)(*(int *)(iVar2 + 8) + 0x24));
  return;
}

