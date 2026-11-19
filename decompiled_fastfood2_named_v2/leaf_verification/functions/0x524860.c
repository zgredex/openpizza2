// rea decompile_all
// name: FUN_00524860
// address: 0x524860
// body: available
// range: 0x524860-0x524960 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00524860(void *this,undefined4 param_1,int param_2,int param_3)

{
  void *this_00;
  uint uVar1;
  LONG LVar2;
  LONG LVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  tagPOINT local_8;
  
  piVar5 = (int *)0x0;
  if (*(int *)((int)this + 0x22c) == 0) {
    uVar1 = (uint)param_2 >> 0x10;
    local_8.x = (LONG)(short)param_3;
    local_8.y = (LONG)(short)((uint)param_3 >> 0x10);
    ScreenToClient(*(HWND *)((int)this + 0x8320),&local_8);
    LVar3 = local_8.y;
    LVar2 = local_8.x;
    _DAT_005841d8 = local_8.x;
    _DAT_005841dc = local_8.y;
    _DAT_005841e8 = 0;
    _DAT_005841ec = 0;
    iVar6 = *(int *)((int)this + 0x23c) + -1;
    if (-1 < iVar6) {
      puVar7 = (undefined4 *)((int)this + iVar6 * 4 + 0x14);
      do {
        this_00 = (void *)*puVar7;
        if (((((this_00 != (void *)0x0) && (*(int *)((int)this_00 + 0x4c) != 0)) &&
             ((*(void **)((int)this + 0x228) == (void *)0x0 ||
              (*(void **)((int)this + 0x228) == this_00)))) &&
            (piVar4 = UI_FindNearestWindow(this_00,LVar2,LVar3,&param_2), piVar4 != (int *)0x0)) &&
           ((piVar5 == (int *)0x0 || (param_2 < param_3)))) {
          piVar5 = piVar4;
          param_3 = param_2;
        }
        iVar6 = iVar6 + -1;
        puVar7 = puVar7 + -1;
      } while (-1 < iVar6);
      if (piVar5 != (int *)0x0) {
        (**(code **)(*piVar5 + 0xc))(0x2f,0 < (short)uVar1,0);
      }
    }
  }
  return;
}

