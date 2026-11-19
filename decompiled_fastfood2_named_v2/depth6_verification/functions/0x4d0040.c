// rea decompile_all
// name: FUN_004d0040
// address: 0x4d0040
// body: available
// range: 0x4d0040-0x4d01b1 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004d0040(void *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(DAT_0057c670 + 0x298 + *(int *)(DAT_0057c670 + 0x290) * 4);
  iVar2 = FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  iVar3 = FUN_00482820(DAT_0057c670);
  iVar2 = *(int *)(iVar2 + 0xc20 + iVar3 * 4);
  FUN_00532520((int)param_1);
  FUN_00532330(param_1,0,6,0x3ec);
  FUN_0052ff50(param_1,0x3ec,(uint)(iVar1 == 5));
  FUN_00531620(param_1,0x3ec,(uint)(iVar1 == 5));
  FUN_005316f0(param_1,0x3ec,(uint)(0 < iVar2));
  FUN_0052ff50(param_1,0x3e9,(uint)(iVar1 == 2));
  FUN_00531620(param_1,0x3e9,(uint)(iVar1 == 2));
  FUN_0052ff50(param_1,1000,(uint)(iVar1 == 1));
  FUN_00531620(param_1,1000,(uint)(iVar1 == 1));
  FUN_0052ff50(param_1,0x3ea,(uint)(iVar1 == 3));
  FUN_00531620(param_1,0x3ea,(uint)(iVar1 == 3));
  FUN_0052ff50(param_1,0x3eb,(uint)(iVar1 == 4));
  FUN_00531620(param_1,0x3eb,(uint)(iVar1 == 4));
  FUN_0052ff50(param_1,0x3ed,(uint)(iVar1 == 6));
  FUN_00531620(param_1,0x3ed,(uint)(iVar1 == 6));
  FUN_005301c0(*(void **)(DAT_0057c670 + 0x25c),-0x18647,0x23,0);
  return;
}

