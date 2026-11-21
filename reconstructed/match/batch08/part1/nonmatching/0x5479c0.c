/* Closest candidate for Sound_SetEnabledFlag (0x5479c0): the original hoists
   the global byte load and uses `test al,al; je`, but VC6 emits `jbe` for the
   only source shape that also keeps the parameter in AL and the global in DL.
   First difference: +0x0c, original 0x74 (je), candidate 0x76 (jbe). */
extern char DAT_00575091;

struct SoundManager {
    char pad[0xfe];
    unsigned char dirty;
    void SetEnabledFlag(unsigned char enable);
};

void SoundManager::SetEnabledFlag(unsigned char enable)
{
    if (enable > 0) {
        if (DAT_00575091 == 0) {
            DAT_00575091 = enable;
            dirty = 1;
        }
    } else {
        if (DAT_00575091 != 0) {
            DAT_00575091 = enable;
            dirty = 1;
        }
    }
}
