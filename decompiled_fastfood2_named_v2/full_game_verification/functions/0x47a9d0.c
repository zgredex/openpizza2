// rea decompile_all
// name: Branch_RemoveStaffMember
// address: 0x47a9d0
// body: available
// range: 0x47a9d0-0x47aabc inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Branch_RemoveStaffMember(void *this,int *param_1,int param_2)

{
  void *this_00;
  void *pvVar1;
  int iVar2;
  undefined4 *puVar3;
  void *this_01;
  
                    /* Removes one employee from a branch, releases their job, and refreshes staff
                       UI. */
  if (*param_1 == *(int *)((int)this + 0x14c4)) {
    *(undefined4 *)((int)this + 0x14c4) = 0;
  }
  this_00 = (void *)((int)this + 0x1500);
  iVar2 = Map_LookupLinear(this_00,(int)param_1);
  if (iVar2 != -1) {
    puVar3 = (undefined4 *)IDMap_Lookup(this_00,iVar2,(int *)0x0);
    pvVar1 = (void *)*puVar3;
    this_01 = (void *)Game_GetRecordByField814((int)pvVar1);
    if (*(int *)((int)this_01 + 0x108) != 1) {
      Person_ReleaseFromBranch(pvVar1);
    }
    *(undefined4 *)((int)this_01 + 0x7c) = 0xff;
    if ((*(char *)((int)pvVar1 + 0x824) == '\x03') && (*(int *)((int)this_01 + 0xa4) == 4)) {
      Object_ClearAssignedRecord(this_01,this);
    }
    IDMap_RemoveRecursive(this_00,iVar2);
    if (((param_2 == 0) && (*(void **)(DAT_0057c670 + 0x21c) == this_01)) &&
       (*(void **)(DAT_0057c670 + 0x25c) != (void *)0x0)) {
      UI_QueueControlCommand(*(void **)(DAT_0057c670 + 0x25c),-0x18629,0x23,0);
    }
    Object_SetFieldA4Locked(this_01,0xffffffff);
    *(undefined4 *)((int)this_01 + 0x88) = 0xffffffff;
    Stats_ResetAverages(this);
  }
  Game_ToggleObjectFlag2(this);
  return;
}

