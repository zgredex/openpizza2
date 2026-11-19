// rea decompile_all
// name: Branch_ApplyStyleSettings
// address: 0x4febb0
// body: available
// range: 0x4febb0-0x4feca0 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall Branch_ApplyStyleSettings(void *this,int param_1,void *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
                    /* Applies a branch's AI style adjustment percentages. */
  iVar1 = Game_GetPlayerFieldC20(*(int *)((int)this + param_1 * 0x168 + 0x70));
  if (2 < iVar1) {
    if ((*(int *)((int)param_2 + 0x14c4) == 0) &&
       (City_AssignPersonToBuilding(param_2,1), *(int *)((int)param_2 + 0x14c4) == 0)) {
      return 3;
    }
    switch(*(undefined4 *)((int)param_2 + 0x24)) {
    case 0:
    case 4:
      param_1 = 0x32;
      iVar1 = 0x1e;
      iVar2 = 0;
      iVar3 = -10;
      break;
    case 1:
      param_1 = 0x41;
      iVar1 = 0x2d;
      iVar2 = 10;
      iVar3 = 0;
      break;
    case 2:
      iVar2 = 10;
      param_1 = 0x46;
      iVar1 = 0x37;
      iVar3 = 10;
      break;
    case 3:
      iVar2 = 0x14;
      param_1 = 0x4b;
      iVar1 = 0x50;
      iVar3 = 0x14;
      break;
    default:
      iVar1 = param_1;
      iVar2 = param_1;
      iVar3 = param_1;
    }
    *(int *)((int)param_2 + 0x14c8) = iVar1;
    *(int *)((int)param_2 + 0x14cc) = param_1;
    *(int *)((int)param_2 + 0x14d0) = iVar2;
    Game_UpdateObjectRatingScales((int)param_2);
    *(int *)((int)param_2 + 0x14c0) = iVar3;
    *(undefined4 *)((int)param_2 + 0x14d4) = 0;
    Game_UpdateObjectRatingScales((int)param_2);
  }
  return 1;
}

