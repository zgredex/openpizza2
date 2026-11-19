// rea decompile_all
// name: BuildingValue_Compute
// address: 0x4e2410
// body: available
// range: 0x4e2410-0x4e2567 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


float10 __thiscall BuildingValue_Compute(int param_1,void *param_2,int param_3)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float local_2c;
  undefined4 local_28 [5];
  int local_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005594f8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  List_Construct(local_28,0);
  local_4 = 0;
  local_2c = 1.5;
  if (param_3 != 0) {
    local_2c = *(float *)(param_3 + 0xc);
    iVar2 = Array_FindIndexStride60(param_2,param_3);
    Game_CollectAllOwnedObjects(local_28,iVar2);
    local_2c = ((float)local_14 * *(float *)(param_3 + 8) + 1.0) * local_2c;
    iVar3 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
    if (*(int *)(param_1 + 0x48) == iVar3) {
      iVar3 = *(int *)(*(int *)(DAT_0057c670 + 0x224) + 0xa8);
      if (*(int *)(iVar3 + 0x114) / 100000 + -1 == iVar2) {
        local_2c = local_2c * 0.5;
      }
      if (*(int *)(iVar3 + 0x1f8) / 100000 + -1 == iVar2) {
        local_2c = local_2c * 1.5;
      }
    }
  }
  fVar1 = *(float *)((int)param_2 + 0x94);
  iVar3 = Game_GetPlayerCity(param_1);
  iVar2 = *(int *)(iVar3 + 0x54);
  iVar3 = *(int *)(iVar3 + 0x3c);
  local_4 = 0xffffffff;
  List_Node_Destroy(local_28);
  ExceptionList = local_c;
  return (float10)(fVar1 * local_2c * (1.0 - (float)(iVar2 + iVar3) * 0.03));
}

