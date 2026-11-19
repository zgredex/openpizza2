// rea decompile_all
// name: RecordList_TickFrameAtTimeAndGetPoints
// address: 0x534250
// body: available
// range: 0x534250-0x5342d4 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint __thiscall
RecordList_TickFrameAtTimeAndGetPoints
          (void *this,int param_1,uint param_2,undefined4 *param_3,undefined4 *param_4,
          undefined4 *param_5)

{
  int iVar1;
  uint in_EAX;
  int iVar2;
  
  if ((-1 < param_1) && (param_1 < *(int *)((int)this + 0x48))) {
    in_EAX = *(uint *)((int)this + 0x4c);
    iVar2 = param_1 * 0x48;
    if (*(int *)(in_EAX + iVar2) != -1) {
      CS_Enter(0x5842a0);
      iVar1 = *(int *)((int)this + 0x4c) + iVar2;
      Record_AdvanceFrameSequence
                (this,param_1,param_2,(double *)(iVar1 + 8),(double *)(iVar1 + 0x10),param_5);
      iVar1 = *(int *)((int)this + 0x4c);
      *param_3 = *(undefined4 *)(iVar1 + 8 + iVar2);
      param_3[1] = *(undefined4 *)(iVar1 + 0xc + iVar2);
      iVar1 = *(int *)((int)this + 0x4c);
      *param_4 = *(undefined4 *)(iVar1 + 0x10 + iVar2);
      param_4[1] = *(undefined4 *)(iVar1 + 0x14 + iVar2);
      in_EAX = CS_Leave(0x5842a0);
    }
  }
  return in_EAX & 0xffffff00;
}

