// Game_GetPlanName: ported from Pizza Connection 2 at 0x501580.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x501580
#include "pc2_port.h"

char * Game_GetPlanName(uint32_t arg1)

{
  switch(arg1) {
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
