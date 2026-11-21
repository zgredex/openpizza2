/* Game_EnterBranchInterior: centers the view on the branch and enters its
   interior scene (0x488de0). */
struct Game {
    void CenterViewOnObject();
    void ShowBranchScene(void *branch, int flag);
    void EnterBranchInterior(void *branch);
};

struct Map {
    void DrawMinimap();
};

struct Sound {
    void SetVolumePreset(int preset);
};

void Game::EnterBranchInterior(void *branch)
{
    void *view = *(void **)((char *)branch + 0x16f0);
    void *interior = *(void **)((char *)branch + 0x14e0);

    if (view != 0) {
        ((Game *)view)->CenterViewOnObject();
        ((Map *)this)->DrawMinimap();
    }
    ShowBranchScene(interior, 1);
    ((Sound *)this)->SetVolumePreset(0);
}
