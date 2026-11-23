// ResourceManager_Init: ported from Pizza Connection 2 at 0x404500.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x404500
#include "pc2_port.h"


void ResourceManager_Init(void)

{
  uint32_t *uptr1;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00557c56;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uptr1 = operator_new(0x1ac4);
  local_4 = 0;
  if (uptr1 == (uint32_t *)0x0) {
    DAT_0057c5d8 = (uint32_t *)0x0;
  }
  else {
    DAT_0057c5d8 = ResourceManager_Construct(uptr1);
  }
  DAT_0057c5d8[0x6ae] = 0;
  local_4 = 0xffffffff;
  ResourceManager_RegisterExtensionAlias(DAT_0057c5d8,s_sprites__00563b44,&DAT_00563b50);
  ResourceManager_RegisterExtensionAlias(DAT_0057c5d8,s_sprites__00563b44,&DAT_00563b40);
  ResourceManager_RegisterExtensionAlias(DAT_0057c5d8,s_fonts__00563b34,&DAT_00563b3c);
  ResourceManager_RegisterExtensionAlias(DAT_0057c5d8,s_pictures__00563b24,&DAT_00563b30);
  ResourceManager_RegisterExtensionAlias(DAT_0057c5d8,s_pictures__00563b24,&DAT_00563b20);
  ResourceManager_RegisterExtensionAlias(DAT_0057c5d8,s_daten__00563b14,&DAT_00563b1c);
  ResourceManager_RegisterExtensionAlias(DAT_0057c5d8,s_daten__00563b14,&DAT_00563b10);
  ResourceManager_RegisterExtensionAlias(DAT_0057c5d8,s_daten__00563b14,&DAT_00563b0c);
  ResourceManager_RegisterExtensionAlias(DAT_0057c5d8,s_movies__00563b00,&DAT_00563b08);
  ResourceManager_RegisterExtensionAlias(DAT_0057c5d8,s_update__00563af4,&DAT_00563afc);
  ResourceManager_OpenArchivePath(DAT_0057c5d8);
  ResourceManager_OpenArchivePath(DAT_0057c5d8);
  ResourceManager_OpenArchivePath(DAT_0057c5d8);
  Pak_OpenEmbedded(DAT_0057c5d8,s_SpriteResource_00563ac0);
  uptr1 = operator_new(0x1ac4);
  local_4 = 1;
  if (uptr1 == (uint32_t *)0x0) {
    DAT_0057c5dc = (uint32_t *)0x0;
  }
  else {
    DAT_0057c5dc = ResourceManager_Construct(uptr1);
  }
  DAT_0057c5dc[0x6ae] = 0;
  local_4 = 0xffffffff;
  ResourceManager_RegisterExtensionAlias(DAT_0057c5dc,s_Isodaten_Sprites__00563aac,&DAT_00563b50);
  ResourceManager_RegisterExtensionAlias(DAT_0057c5dc,s_Isodaten_Anims__00563a9c,&DAT_00563b40);
  ResourceManager_RegisterExtensionAlias(DAT_0057c5dc,s_Backgrounds__00563a8c,&DAT_00563b20);
  ResourceManager_RegisterExtensionAlias(DAT_0057c5dc,s_Backgrounds__00563a8c,&DAT_00563b30);
  ResourceManager_RegisterExtensionAlias(DAT_0057c5dc,s_Isokarten__00563a7c,&DAT_00563a88);
  ResourceManager_RegisterExtensionAlias(DAT_0057c5dc,s_Isodaten__00563a6c,&DAT_00563a78);
  ResourceManager_RegisterExtensionAlias(DAT_0057c5dc,s_Isodaten__00563a6c,&DAT_00563a68);
  ResourceManager_OpenArchivePath(DAT_0057c5dc);
  ExceptionList = local_c;
  return;
}
