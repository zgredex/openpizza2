// rea decompile_all
// name: UI_SliderUpdateFromPosition
// address: 0x52a260
// body: available
// range: 0x52a260-0x52a392 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __fastcall UI_SliderUpdateFromPosition(void *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  int local_8;
  int local_4;
  
                    /* Depth-3 proposal batch 4. */
  local_4 = *(int *)((int)param_1 + 100);
  local_8 = *(int *)((int)param_1 + 0x68);
  FUN_00531dd0(*(void **)((int)param_1 + 8),&local_4,&local_8);
  iVar1 = *(int *)((int)param_1 + 0x60);
  iVar4 = iVar1 + -1;
  if (iVar4 < 0) {
    iVar4 = 0;
  }
  iVar2 = *(int *)((int)param_1 + 0x94);
  lVar5 = __ftol();
  iVar2 = (int)lVar5 + iVar2;
  if (*(int *)((int)param_1 + 0x454) == 0) goto LAB_0052a33a;
  if (iVar4 == 0) {
    iVar3 = *(int *)((int)param_1 + 0x90);
    if (*(int *)((int)param_1 + 0x58) == 0) goto LAB_0052a32e;
joined_r0x0052a336:
    if (iVar2 <= iVar3) goto LAB_0052a33a;
  }
  else {
    iVar3 = *(int *)((int)param_1 + 0x8c);
    if (*(int *)((int)param_1 + 0x58) == 0) goto joined_r0x0052a336;
LAB_0052a32e:
    if (iVar3 <= iVar2) goto LAB_0052a33a;
  }
  iVar2 = iVar3;
LAB_0052a33a:
  if (iVar2 == *(int *)((int)param_1 + iVar4 * 4 + 0x8c)) {
    return iVar1;
  }
  FUN_0052a3a0(param_1,iVar2,iVar4);
  iVar4 = *(int *)((int)param_1 + iVar4 * 4 + 0x8c);
  FUN_005321f0(*(void **)((int)param_1 + 8),(int *)((int)param_1 + 0x28),1);
  if (*(int *)((int)param_1 + 0xc4) != 0) {
    FUN_005301c0(*(void **)((int)param_1 + 8),*(int *)((int)param_1 + 4),0x19,iVar4);
  }
  return *(int *)((int)param_1 + 0x60);
}

