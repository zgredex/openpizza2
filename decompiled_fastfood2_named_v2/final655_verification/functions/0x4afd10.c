// rea decompile_all
// name: Glossary_UpdatePeoplePage
// address: 0x4afd10
// body: available
// range: 0x4afd10-0x4afe6d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl Glossary_UpdatePeoplePage(void *param_1)

{
  void *this;
  int iVar1;
  int local_c;
  int local_8;
  int local_4;
  
                    /* Refreshes the glossary people chapter. */
  this = param_1;
  FUN_005314a0(param_1,0x42e,&local_8,&local_4);
  FUN_005314a0(this,0x43f,&param_1,&local_c);
  DAT_0057d658 = (int)param_1 - local_8;
  FUN_005314a0(this,0x4b6,&param_1,&local_c);
  DAT_0057d65c = local_c - local_4;
  UI_Group_Create(this,0,4,0x3f9);
  FUN_0052ff50(this,0x3f9,1);
  FUN_0052fd00(this,0x3f6,0,0x11,0);
  FUN_0052fd70(this,0x3f6,DAT_0057d668,0);
  FUN_0052fce0(this,0x3f6,1);
  iVar1 = 0x42f;
  do {
    FUN_00531740(this,iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x43f);
  iVar1 = 0x1f5e;
  do {
    FUN_00531740(this,iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x1f6e);
  FUN_004af5c0(this,DAT_0057d668);
  GlossaryWeapons_FillWeaponPage(this);
  FUN_00531740(this,0x42e);
  FUN_00531740(this,0x43f);
  FUN_00531740(this,0x4b6);
  FUN_00531740(this,0x1f5d);
  FUN_00531740(this,0x1f6f);
  FUN_00531740(this,0x1f6e);
  return;
}

