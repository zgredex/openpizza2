// rea decompile_all
// name: Game_GetPlanName
// address: 0x501580
// body: available
// range: 0x501580-0x50165b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


char * Game_GetPlanName(undefined4 param_1)

{
  switch(param_1) {
  case 0:
    return s_keinen_Plan_0057266c;
  case 1:
    return s_schlafen_0057263c;
  default:
    return s_Unknown_Plan_005724bc;
  case 3:
    return s_komplette_KI_0057265c;
  case 4:
    return s__Filiale__00572630;
  case 5:
    return s_neue_Filiale_kaufen_0057261c;
  case 6:
    return s_Filiale_optimieren_00572608;
  case 7:
    return s_Personal_optimieren_005725f4;
  case 8:
    return s_Einrichtung_optimieren_005725dc;
  case 9:
    return s_Manager_005725c0;
  case 10:
    return s_Rezepte_verbessern_005725ac;
  case 0xb:
    return &DAT_005725c8;
  case 0xc:
    return &DAT_00572598;
  case 0xd:
    return &DAT_00572584;
  case 0xe:
    return &DAT_00572570;
  case 0xf:
    return s_Syndikat_00572564;
  case 0x10:
    return &DAT_0057255c;
  case 0x11:
    return s_Gangster_verwalten_00572548;
  case 0x12:
    return s_Umfeld_anpassen_00572538;
  case 0x13:
    return s_Werbung_schalten_00572524;
  case 0x14:
    return s_Sicherheit_verbessern_0057250c;
  case 0x15:
    return &DAT_005724f4;
  case 0x16:
    return &DAT_005724e4;
  case 0x17:
    return &DAT_005724cc;
  case 0x18:
    return s_Spieler_abwickeln_00572648;
  }
}

