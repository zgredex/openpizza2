// rea decompile_all
// name: FUN_0048c860
// address: 0x48c860
// body: available
// range: 0x48c860-0x48c91a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_0048c860(void *this,void *param_1)

{
  int iVar1;
  undefined4 unaff_EDI;
  char *pcVar2;
  
  if (*(void **)((int)this + 0x21c) == param_1) {
    FUN_005301c0(*(void **)((int)this + 0x25c),-0x18624,0x23,0);
    *(undefined4 *)((int)this + 0x21c) = 0;
    *(undefined4 *)((int)this + 0x2da8) = 1;
  }
  iVar1 = *(int *)((int)param_1 + 0x30);
  if (iVar1 == 0xd) {
    pcVar2 = s_Polizei_tot_00568330;
  }
  else if (iVar1 == 0x17) {
    pcVar2 = s_Wache_tot_0056833c;
  }
  else {
    if (iVar1 != 0x1d) goto LAB_0048c8e8;
    pcVar2 = s_Gangster_tot_00568348;
  }
  FUN_0054a660(DAT_0057c1e0,0xff,(byte *)pcVar2,unaff_EDI);
LAB_0048c8e8:
  FUN_005086e0((int)param_1);
  *(undefined4 *)((int)param_1 + 0x30) = 0x23;
  FUN_0050e890(param_1,2);
  FUN_0050e710(param_1,1);
  *(undefined4 *)((int)param_1 + 0x74) = 0;
  UI_DestroyChildObject((int)param_1);
  return;
}

