// rea decompile_all
// name: FUN_004aca80
// address: 0x4aca80
// body: available
// range: 0x4aca80-0x4acb8e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004aca80(void *param_1,int *param_2,float param_3,int param_4,char param_5)

{
  int *piVar1;
  int iVar2;
  int local_54 [4];
  undefined4 local_44;
  undefined1 local_40 [64];
  
  local_54[0] = DAT_005826d8;
  local_54[1] = DAT_00582320;
  local_54[3] = DAT_00582858;
  local_54[2] = DAT_0058271c;
  local_44 = DAT_00582998;
  if (param_5 != '\0') {
    iVar2 = 0;
    piVar1 = param_2;
    do {
      FUN_004a80e0(param_1,(&DAT_00569520)[param_4] + iVar2,-1,*piVar1,
                   *(int *)((int)piVar1 + ((int)local_54 - (int)param_2)));
      iVar2 = iVar2 + 0x11;
      piVar1 = piVar1 + 1;
    } while (iVar2 < 0x55);
  }
  FUN_0054dd83(local_40,&DAT_005686f4,param_2[5]);
  FUN_0052f9b0(param_1,(&DAT_00569548)[param_4],local_40);
  FUN_0054dd83(local_40,&DAT_005686f4,param_2[6]);
  FUN_0052f9b0(param_1,(&DAT_00569548)[param_4] + 1,local_40);
  FUN_0054dd83(local_40,(byte *)s__0_2f_005685f4,SUB84((double)param_3,0));
  FUN_0052f9b0(param_1,param_4 * 3 + 0x845,local_40);
  return;
}

