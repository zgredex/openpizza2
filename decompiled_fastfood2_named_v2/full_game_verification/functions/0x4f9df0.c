// rea decompile_all
// name: MapObject_CreateFromTile
// address: 0x4f9df0
// body: available
// range: 0x4f9df0-0x4f9edb inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void MapObject_CreateFromTile
               (int *param_1,int param_2,undefined2 param_3,undefined2 param_4,undefined1 param_5,
               int param_6,int param_7)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  longlong lVar5;
  
  iVar1 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(*param_1 + 0x30));
  iVar2 = Game_GetPlayerCity(iVar1);
  piVar3 = operator_new(0x24);
  *(undefined2 *)((int)piVar3 + 0x16) = param_4;
  *(undefined2 *)(piVar3 + 5) = param_3;
  piVar3[7] = param_7;
  *(undefined1 *)(piVar3 + 6) = param_5;
  piVar3[8] = (uint)(param_6 == 1);
  *piVar3 = param_2;
  piVar3[1] = 0;
  City_FindListContainingValue(param_2,piVar3 + 3,piVar3 + 4);
  iVar1 = piVar3[3];
  if (iVar1 < 1) goto LAB_004f9ecc;
  iVar1 = IDMap_Lookup((void *)((int)DAT_0057c670 + 0x74),iVar1,(int *)0x0);
  if (*(int *)(iVar1 + 0xc) == 5) {
    piVar3[2] = param_1[6];
LAB_004f9eb1:
    piVar3[7] = 1;
  }
  else {
    iVar4 = Building_GetLevelFromType(iVar1);
    piVar3[2] = iVar4;
    if (iVar4 == -1) {
      piVar3[2] = param_1[5];
    }
    if (*(int *)(iVar1 + 0xc) == 6) goto LAB_004f9eb1;
  }
  Game_ComputePrice(iVar1,iVar2);
  lVar5 = __ftol();
  piVar3[1] = (int)lVar5;
LAB_004f9ecc:
  List_Add((void *)param_1[3],piVar3);
  return;
}

