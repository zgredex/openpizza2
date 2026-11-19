// rea decompile_all
// name: SaveGame_DeserializeRuntimeList
// address: 0x487a30
// body: available
// range: 0x487a30-0x487b4a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall SaveGame_DeserializeRuntimeList(void *this,void *param_1)

{
  void *this_00;
  int iVar1;
  int iVar2;
  int local_1c;
  void *local_18;
  void *local_14;
  int local_10;
  int local_c [2];
  
  this_00 = *(void **)(DAT_0057c5cc + 0x2c3d4);
  iVar2 = 0x2c41c;
  local_18 = this_00;
  local_14 = this;
  do {
    iVar1 = *(int *)(iVar2 + DAT_0057c5cc);
    if (((-1 < iVar1) && (iVar1 < *(int *)((int)this_00 + 0x48))) &&
       (*(char *)(*(int *)((int)this_00 + 0x4c) + 0x3e + iVar1 * 0x48) != '\0')) {
      Record_ClearFlags48(this_00,iVar1);
      *(undefined4 *)((int)local_14 + iVar2 + -0x2c0b0) = 0xffffffff;
    }
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x2c434);
  iVar2 = 0x2c41c;
  do {
    iVar1 = *(int *)(iVar2 + DAT_0057c5cc);
    CRT_Istream_Read(param_1,&local_1c,4);
    if (local_1c == 1) {
      CRT_Istream_Read(param_1,local_c,4);
      CRT_Istream_Read(param_1,&local_10,4);
      Record_SetRect48((int)local_18,iVar1,SUB84((double)local_c[0],0),
                       (int)((ulonglong)(double)local_c[0] >> 0x20),(double)local_10);
      CRT_Istream_Read(param_1,&local_1c,4);
      Record_SelectVariant(local_18,iVar1,local_1c);
      CRT_Istream_Read(param_1,&local_1c,4);
      *(int *)(iVar2 + -0x2c0b0 + (int)local_14) = local_1c;
    }
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x2c434);
  return;
}

