// rea decompile_all
// name: Sound_QueryFormatFlags
// address: 0x5412e0
// body: available
// range: 0x5412e0-0x5414d6 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint __fastcall Sound_QueryFormatFlags(int param_1)

{
  undefined4 uVar1;
  
  if (*(int **)(param_1 + 0xac) == (int *)0x0) {
    return 0x80004003;
  }
  *(undefined4 *)(param_1 + 0xb0) = 0;
  uVar1 = Input_GetDeviceObjectInfo(*(int **)(param_1 + 0xac),2);
  if ((char)uVar1 != '\0') {
    *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) | 1;
  }
  uVar1 = Input_GetDeviceObjectInfo(*(int **)(param_1 + 0xac),3);
  if ((char)uVar1 != '\0') {
    *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) | 2;
  }
  uVar1 = Input_GetDeviceObjectInfo(*(int **)(param_1 + 0xac),4);
  if ((char)uVar1 != '\0') {
    *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) | 4;
  }
  uVar1 = Input_GetDeviceObjectInfo(*(int **)(param_1 + 0xac),5);
  if ((char)uVar1 != '\0') {
    *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) | 8;
  }
  uVar1 = Input_GetDeviceObjectInfo(*(int **)(param_1 + 0xac),6);
  if ((char)uVar1 != '\0') {
    *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) | 0x10;
  }
  uVar1 = Input_GetDeviceObjectInfo(*(int **)(param_1 + 0xac),7);
  if ((char)uVar1 != '\0') {
    *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) | 0x20;
  }
  uVar1 = Input_GetDeviceObjectInfo(*(int **)(param_1 + 0xac),8);
  if ((char)uVar1 != '\0') {
    *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) | 0x40;
  }
  uVar1 = Input_GetDeviceObjectInfo(*(int **)(param_1 + 0xac),9);
  if ((char)uVar1 != '\0') {
    *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) | 0x80;
  }
  uVar1 = Input_GetDeviceObjectInfo(*(int **)(param_1 + 0xac),10);
  if ((char)uVar1 != '\0') {
    *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) | 0x100;
  }
  uVar1 = Input_GetDeviceObjectInfo(*(int **)(param_1 + 0xac),0xb);
  if ((char)uVar1 != '\0') {
    *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) | 0x200;
  }
  uVar1 = Input_GetDeviceObjectInfo(*(int **)(param_1 + 0xac),0xc);
  if ((char)uVar1 != '\0') {
    *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) | 0x400;
  }
  uVar1 = Input_GetDeviceObjectInfo(*(int **)(param_1 + 0xac),0xd);
  if ((char)uVar1 != '\0') {
    *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) | 0x800;
  }
  uVar1 = Input_GetDeviceObjectInfo(*(int **)(param_1 + 0xac),0xe);
  if ((char)uVar1 != '\0') {
    *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) | 0x1000;
  }
  return (uint)(*(int *)(param_1 + 0xb0) != 0x1fff);
}

