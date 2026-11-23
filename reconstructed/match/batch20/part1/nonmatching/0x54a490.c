/* Sound::PlayStatisticPageSfx (0x54a490). */
struct Sound {
    char pad[0xfc];
    char enabled;
    void PlaySfxByIndex(int id, int variant);
    void PlayStatisticPageSfx(int page);
};

void Sound::PlayStatisticPageSfx(int page)
{
    if (enabled != 0) {
        switch (page) {
        case 0:
            PlaySfxByIndex(0x14, 0);
            return;
        case 1:
            PlaySfxByIndex(0x15, 0);
            return;
        case 2:
            PlaySfxByIndex(0x16, 0);
            return;
        case 3:
            PlaySfxByIndex(0x1d, 0);
            return;
        case 4:
            PlaySfxByIndex(0x1e, 0);
            return;
        case 5:
            PlaySfxByIndex(0x1f, 0);
            return;
        case 6:
            PlaySfxByIndex(0x1c, 1);
            return;
        case 7:
            PlaySfxByIndex(0x1c, 2);
            return;
        case 8:
            PlaySfxByIndex(0x1c, 3);
            return;
        case 9:
            PlaySfxByIndex(0x1c, 4);
            return;
        case 10:
            PlaySfxByIndex(0x1c, 5);
            return;
        case 11:
            PlaySfxByIndex(0x1c, 6);
            return;
        case 12:
            PlaySfxByIndex(0x11, 0);
        }
    }
}
