// rea decompile_all
// name: Object_RebuildVisualAtDestination
// address: 0x508d90
// body: available
// range: 0x508d90-0x508ead inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Object_RebuildVisualAtDestination(void *this,int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
                    /* Rebuilds an object's visual after a deferred type change. */
  CS_Enter(*(int *)(DAT_0057c670 + 0x240));
  CS_Enter(*(int *)(DAT_0057c670 + 0x244));
  if (*(int *)((int)this + 200) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(*(int *)((int)this + 200) + 0x20);
  }
  UI_SetChildState(this,0xffff);
  Object_ApplyPendingType(this,param_2);
  UI_DestroyChildObject((int)this);
  if (*(int *)((int)this + 0x30) == 0x10) {
    iVar1 = IDMap_Lookup((void *)(DAT_0057c670 + 0x20),*(int *)((int)this + 0x50),(int *)0x0);
  }
  else {
    iVar1 = param_2;
  }
  if (param_1 == 0) {
    if (*(int *)((int)this + 0x30) == 0x10) {
      uVar4 = (uint)*(byte *)(iVar1 + 0x824);
    }
    else {
      uVar4 = 0xffffffff;
    }
    MapObject_InitRenderRecord(this,0,-1,uVar4);
    uVar3 = 0;
  }
  else {
    if (param_1 != 1) goto LAB_00508e68;
    if (*(int *)((int)this + 0x30) == 0x10) {
      MapObject_InitRenderRecord(this,1,-1,(uint)*(byte *)(iVar1 + 0x824));
      uVar3 = 1;
    }
    else {
      MapObject_InitRenderRecord(this,1,-1,-1);
      uVar3 = 1;
    }
  }
  UI_SetChildTracking(this,uVar3,iVar2);
LAB_00508e68:
  Object_ApplyDeferredType(this,param_2);
  Object_SetDestinationAndTarget(this,3,*(int *)((int)this + 0xcc));
  *(undefined4 *)((int)this + 0x78) = 0;
  CS_Leave(*(int *)(DAT_0057c670 + 0x244));
  CS_Leave(*(int *)(DAT_0057c670 + 0x240));
  return;
}

