// Game_GetStatBandByIndex: ported from Pizza Connection 2 at 0x502430.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x502430
#include "pc2_port.h"

uint32_t __thiscall Game_GetStatBandByIndex(void *self,uint32_t arg1)

{
  char cVar1;
  uint8_t uvalue2;
  uint32_t extraout_var;
  uint32_t extraout_var_00;
  uint32_t extraout_var_01;
  uint32_t extraout_var_02;
  uint32_t extraout_var_03;
  uint32_t extraout_var_04;
  uint32_t uvalue3;
  uint64_t uvalue4;
  
  switch(arg1) {
  case 0:
    uvalue2 = Game_GetPlayerStaffBand();
    return CONCAT31(extraout_var,uvalue2);
  case 1:
    uvalue2 = Game_GetActivityVolumeBand();
    return CONCAT31(extraout_var_00,uvalue2);
  case 2:
    uvalue3 = Game_GetPlayerWealthBand();
    return uvalue3;
  case 3:
    uvalue3 = Stats_GetCityShareRank();
    return uvalue3;
  case 4:
    uvalue3 = Game_GetBestBuildingRatingBand();
    return uvalue3;
  case 5:
    uvalue3 = Game_GetBuildingQualityBand();
    return uvalue3;
  case 6:
    cVar1 = Game_GetPlayerSatisfactionBand();
    return CONCAT31(extraout_var_01,cVar1);
  case 7:
    uvalue2 = Stats_ComputeCategory7();
    return CONCAT31(extraout_var_02,uvalue2);
  case 8:
    uvalue2 = Stats_GetLevelFromFourCounters();
    return CONCAT31(extraout_var_03,uvalue2);
  case 9:
    uvalue4 = Game_GetGlobalStatsBand();
    return (uint32_t)uvalue4;
  case 10:
    uvalue3 = Game_GetMarketRank();
    return uvalue3;
  case 0xb:
    uvalue2 = Stats_GetLevelFromTenCounters();
    return CONCAT31(extraout_var_04,uvalue2);
  case 0xc:
    uvalue3 = Game_GetPlayerTierFromC20(self);
    return uvalue3;
  default:
    return arg1;
  }
}
