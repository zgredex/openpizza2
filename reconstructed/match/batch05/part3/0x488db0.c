/* Game_ShowBranchInteriorDefaultZoom: opens a branch with the default zoom (0x488db0). */
struct Game {
    char pad[0x384];
    int volumePreset;
    void SetVolumePreset(int preset);
    void ShowBranchScene(void *branch, int mode);
    void ShowBranchInteriorDefaultZoom(void *branch);
};

void Game::ShowBranchInteriorDefaultZoom(void *branch)
{
    SetVolumePreset(volumePreset);
    ShowBranchScene(branch, 0);
}
