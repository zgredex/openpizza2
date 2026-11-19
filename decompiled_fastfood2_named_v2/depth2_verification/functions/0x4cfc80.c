// rea decompile_all
// name: FUN_004cfc80
// address: 0x4cfc80
// body: available
// range: 0x4cfc80-0x4d0038 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004cfc80(void *param_1)

{
  int iVar1;
  void *this;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = *(int *)(DAT_0057c670 + 0x298 + *(int *)(DAT_0057c670 + 0x290) * 4);
  iVar2 = FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  iVar3 = FUN_00482820(DAT_0057c670);
  iVar2 = *(int *)(iVar2 + 0xc20 + iVar3 * 4);
  iVar3 = *(int *)(*(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4) + 0x50);
  FUN_00532520((int)param_1);
  FUN_00532330(param_1,0,9,0x3f4);
  FUN_0052ff50(param_1,0x3f4,(uint)(iVar1 == 1));
  FUN_00531620(param_1,0x3f4,(uint)(iVar1 == 1));
  FUN_0052ff50(param_1,0x3fe,(uint)(iVar1 == 2));
  FUN_00531620(param_1,0x3fe,(uint)(iVar1 == 2));
  FUN_0052ff50(param_1,0x3ff,(uint)(iVar1 == 3));
  FUN_00531620(param_1,0x3ff,(uint)(iVar1 == 3));
  FUN_0052ff50(param_1,0x400,(uint)(iVar1 == 4));
  FUN_00531620(param_1,0x400,(uint)(iVar1 == 4));
  FUN_0052ff50(param_1,0x401,(uint)(iVar1 == 5));
  FUN_00531620(param_1,0x401,(uint)(iVar1 == 5));
  FUN_005316f0(param_1,0x401,(uint)(0 < iVar2));
  FUN_0052ff50(param_1,0x403,(uint)(iVar1 == 6));
  FUN_00531620(param_1,0x403,(uint)(iVar1 == 6));
  uVar4 = (uint)(0 < iVar3 + 1);
  FUN_005316f0(param_1,0x403,uVar4);
  FUN_0052ff50(param_1,0x404,(uint)(iVar1 == 7));
  FUN_00531620(param_1,0x404,(uint)(iVar1 == 7));
  FUN_005316f0(param_1,0x404,uVar4);
  FUN_0052ff50(param_1,0x405,(uint)(iVar1 == 8));
  FUN_00531620(param_1,0x405,(uint)(iVar1 == 8));
  FUN_005316f0(param_1,0x405,uVar4);
  uVar4 = (uint)(iVar1 == 10);
  FUN_0052ff50(param_1,0x402,uVar4);
  FUN_00531620(param_1,0x402,uVar4);
  FUN_005316f0(param_1,0x402,uVar4);
  this = *(void **)(DAT_0057c670 + 0x25c);
  if (iVar1 != 10) {
    iVar2 = FUN_004dde70(*(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4),
                         *(int *)(DAT_0057c670 + 0x98));
    if ((iVar2 == -1) && ((iVar1 < 6 || (8 < iVar1)))) {
      UI_QueueControlCommand(this,-0x18671,0x23,-1);
    }
  }
  if ((iVar1 == 2) || (iVar1 == 7)) {
    UI_SetChildLabelText(param_1,0x3f4,1,(char *)0x0);
    UI_SetChildLabelText(param_1,0x3fe,1,(char *)0x0);
    UI_SetChildLabelText(param_1,0x3ff,1,(char *)0x0);
    UI_SetChildLabelText(param_1,0x400,1,(char *)0x0);
    UI_SetChildLabelText(param_1,0x401,1,(char *)0x0);
    UI_SetChildLabelText(param_1,0x403,1,(char *)0x0);
    UI_SetChildLabelText(param_1,0x404,1,(char *)0x0);
    UI_SetChildLabelText(param_1,0x405,1,(char *)0x0);
    FUN_005316b0(this,0x42e);
    FUN_005316b0(this,0x42f);
    FUN_005316b0(this,0x430);
    FUN_00531470(this,0x43a,1);
    FUN_00531470(this,0x438,1);
    UI_SetChildLabelText(this,0x438,1,(char *)0x0);
    return;
  }
  UI_RemoveObjectByKey(this,0x42e);
  UI_RemoveObjectByKey(this,0x42f);
  UI_RemoveObjectByKey(this,0x430);
  FUN_00531470(this,0x43a,0);
  FUN_00531470(this,0x438,0);
  UI_SetChildLabelText(this,0x438,0,(char *)0x0);
  DAT_0057ca2c = 0;
  return;
}

