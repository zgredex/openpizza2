// rea decompile_all
// name: Person_SelectRouteStopForTimeSlot
// address: 0x507ee0
// body: available
// range: 0x507ee0-0x507fcb inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall Person_SelectRouteStopForTimeSlot(void *this,int param_1)

{
  int iVar1;
  undefined4 unaff_EDI;
  
                    /* Switches a person to a daily-route stop for the time slot. */
  if (((*(int *)((int)this + 0x38) != 0x1a) && (*(int *)((int)this + 0x108) != 10)) &&
     (param_1 != *(int *)((int)this + 0x3c))) {
    if (*(void **)(DAT_0057c670 + 0x21c) == this) {
      FUN_0054a660(DAT_0057c1e0,0,(byte *)s_Neue_Zeitzone__0057300c,unaff_EDI);
    }
    iVar1 = *(int *)((int)this + param_1 * 4 + 0xd4);
    if (iVar1 != *(int *)((int)this + *(int *)((int)this + 0x3c) * 4 + 0xd4)) {
      *(int *)((int)this + 0xd0) = iVar1;
      Object_SetDestinationAndTarget(this,6,*(int *)((int)this + param_1 * 4 + 0xd4));
      FUN_0050e890(this,2);
      *(int *)((int)this + 0x3c) = param_1;
      if (*(void **)(DAT_0057c670 + 0x21c) == this) {
        FUN_0054a660(DAT_0057c1e0,0,(byte *)s_Neues_Ziel___s_00572ffc,
                     *(undefined4 *)(&DAT_005840d4 + *(int *)(iVar1 + 4) * 4));
      }
      return 1;
    }
    if (*(void **)(DAT_0057c670 + 0x21c) == this) {
      FUN_0054a660(DAT_0057c1e0,0,(byte *)s_Person_bleibt__00572fec,unaff_EDI);
    }
    *(int *)((int)this + 0x3c) = param_1;
  }
  return 0;
}

