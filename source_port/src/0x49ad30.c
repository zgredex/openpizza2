// AdvertisingScreen_UpdateGroupPrices: ported from Pizza Connection 2 at 0x49ad30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49ad30
#include "pc2_port.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl AdvertisingScreen_UpdateGroupPrices(void *arg1)

{
  uint8_t local_28 [36];
  
  String_Format(local_28,(uint8_t *)s__0_2f__005688b8,
                SUB84((double)(_DAT_00568998 * *(float *)(&DAT_005689b8 + DAT_0057ca30 * 4)),0));
  Window_GadgetNotify_Text_SetText(arg1,0x502,local_28);
  String_Format(local_28,(uint8_t *)s__0_2f__005688b8,
                SUB84((double)(_DAT_0056899c * *(float *)(&DAT_005689b8 + DAT_0057ca30 * 4)),0));
  Window_GadgetNotify_Text_SetText(arg1,0x501,local_28);
  String_Format(local_28,(uint8_t *)s__0_2f__005688b8,
                SUB84((double)(_DAT_005689a0 * *(float *)(&DAT_005689b8 + DAT_0057ca30 * 4)),0));
  Window_GadgetNotify_Text_SetText(arg1,0x500,local_28);
  String_Format(local_28,(uint8_t *)s__0_2f__005688b8,
                SUB84((double)(_DAT_005689a4 * *(float *)(&DAT_005689b8 + DAT_0057ca30 * 4)),0));
  Window_GadgetNotify_Text_SetText(arg1,0x4fd,local_28);
  String_Format(local_28,(uint8_t *)s__0_2f__005688b8,
                SUB84((double)(_DAT_005689a8 * *(float *)(&DAT_005689b8 + DAT_0057ca30 * 4)),0));
  Window_GadgetNotify_Text_SetText(arg1,0x4fc,local_28);
  String_Format(local_28,(uint8_t *)s__0_2f__005688b8,
                SUB84((double)(_DAT_005689ac * *(float *)(&DAT_005689b8 + DAT_0057ca30 * 4)),0));
  Window_GadgetNotify_Text_SetText(arg1,0x4fb,local_28);
  String_Format(local_28,(uint8_t *)s__0_2f__005688b8,
                SUB84((double)(_DAT_005689b0 * *(float *)(&DAT_005689b8 + DAT_0057ca30 * 4)),0));
  Window_GadgetNotify_Text_SetText(arg1,0x4fa,local_28);
  String_Format(local_28,(uint8_t *)s__0_2f__005688b8,
                SUB84((double)(_DAT_005689b4 * *(float *)(&DAT_005689b8 + DAT_0057ca30 * 4)),0));
  Window_GadgetNotify_Text_SetText(arg1,0x506,local_28);
  return;
}
