// rea decompile_all
// name: UI_ShowLoadingOverlay
// address: 0x406910
// body: available
// range: 0x406910-0x406a57 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


longlong __cdecl UI_ShowLoadingOverlay(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  void *this;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  ushort *puVar6;
  longlong lVar7;
  byte bVar8;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* Darkens the screen and shows the loading overlay. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00557d3b;
  local_c = ExceptionList;
  puVar5 = (undefined4 *)0x0;
  ExceptionList = &local_c;
  if (param_1 != 0) {
    ExceptionList = &local_c;
    this = operator_new(0x11c);
    local_4 = 0;
    if (this != (void *)0x0) {
      puVar5 = FUN_00537230(this,800,600,2);
    }
    local_4 = 0xffffffff;
    FUN_00523de0(DAT_0057c5e0,puVar5);
    puVar6 = (ushort *)puVar5[6];
    iVar4 = 480000;
    do {
      if (*(char *)((int)DAT_0057c5c8 + 0x18) == '\0') {
        uVar1 = *puVar6;
        uVar3 = uVar1 >> 2 & 0xf8;
        uVar2 = uVar1 >> 7;
      }
      else {
        uVar1 = *puVar6;
        uVar3 = uVar1 >> 3 & 0xfc;
        uVar2 = uVar1 >> 8;
      }
      uVar3 = ((uVar2 & 0xf8) + ((uVar1 & 0x1f) * 8 + uVar3 * 2) * 3) / 10;
      bVar8 = (byte)uVar3;
      uVar3 = FUN_005397e0(DAT_0057c5c8,bVar8,bVar8,uVar3);
      *puVar6 = (ushort)uVar3;
      puVar6 = puVar6 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    FUN_00523900(DAT_0057c5e0,puVar5);
  }
  DAT_0057c5f4 = LoadingWindow_Create(&param_1);
  FUN_00523d60(DAT_0057c5e0,param_1);
  FUN_00526cf0(DAT_0057c5e0,DAT_0057c5f4);
  lVar7 = FUN_00525a10(DAT_0057c5e0,0);
  ExceptionList = local_c;
  return lVar7;
}

