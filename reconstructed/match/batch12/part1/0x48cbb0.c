/* Sound_RefreshMusicSelection: switches music when the current player's
   company changes (0x48cbb0). */
extern void *DAT_0057c670;
extern void *DAT_0057ba0c;

struct IDMap {
    void *Lookup(int key, int *out);
};

struct SoundMgr {
    void SelectCurrentTrack();
};

struct Game {
    int GetCurrentPlayerCompanyName();
};

extern "C" void __fastcall Sound_RefreshMusicSelection(void *sound)
{
    void *player = *(void **)(
        (char *)sound + 0x200 + *(int *)((char *)sound + 0x2ec) * 4);

    if (player != 0 && *(int *)((char *)player + 0x15c) > 0) {
        if (*(int *)((char *)sound + 0x9c) != 0) {
            int company = *(int *)(*(int *)((char *)sound + 0x9c) + 0x30);

            if (company == ((Game *)sound)->GetCurrentPlayerCompanyName()) {
                return;
            }
        }
        *(void **)((char *)sound + 0x9c) =
            ((IDMap *)((char *)player + 0x148))->Lookup(0, 0);
        ((SoundMgr *)DAT_0057ba0c)->SelectCurrentTrack();
    }
}
