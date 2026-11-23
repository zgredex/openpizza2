// Glossary_ShowIngredientDetail: ported from Pizza Connection 2 at 0x4af2f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4af2f0
#include "pc2_port.h"

void __cdecl Glossary_ShowIngredientDetail(void *arg1)

{
  Window_GadgetNotify_Text_SetText
            (arg1,0x3fd,*(uint32_t *)(&DAT_00583910 + DAT_0057d654 * 0xc));
  Window_GadgetNotify_Text_SetText
            (arg1,0x3fe,*(uint32_t *)(&DAT_00583914 + DAT_0057d654 * 0xc));
  Window_GadgetNotify_Text_SetText
            (arg1,0x400,*(uint32_t *)(&DAT_00583918 + DAT_0057d654 * 0xc));
  UI_SetButtonRecordVariant(arg1,0x1f55,*(uint32_t *)(&DAT_00569f94 + DAT_0057d654 * 4));
  return;
}
