// Game_ReleaseConstructionSpriteLists @ 0x4e9d90 (157 bytes)
// Releases both construction sprite-list arrays and the seven trailing
// construction lists.

struct List {
    void ReleaseSharedBuffers();
};

class Game {
public:
    char pad00[0x2c254];
    List *listsA[0x29];     // 0x2c254
    char pad2c2f8[0x1c];
    List *listsB[0x29];     // 0x2c314
    char pad2c3b8[4];
    List *list3bc;          // 0x2c3bc
    List *list3c0;          // 0x2c3c0
    List *list3c4;          // 0x2c3c4
    List *list3c8;          // 0x2c3c8
    List *list3cc;          // 0x2c3cc
    List *list3d0;          // 0x2c3d0
    List *list3d4;          // 0x2c3d4

    void ReleaseConstructionSpriteLists();
};

void Game::ReleaseConstructionSpriteLists()
{
    for (int i = 0; i < 0x29; i++) {
        if (listsA[i] != 0)
            listsA[i]->ReleaseSharedBuffers();
        if (listsB[i] != 0)
            listsB[i]->ReleaseSharedBuffers();
    }
    if (list3c0 != 0)
        list3c0->ReleaseSharedBuffers();
    if (list3bc != 0)
        list3bc->ReleaseSharedBuffers();
    if (list3c4 != 0)
        list3c4->ReleaseSharedBuffers();
    if (list3c8 != 0)
        list3c8->ReleaseSharedBuffers();
    if (list3cc != 0)
        list3cc->ReleaseSharedBuffers();
    if (list3d0 != 0)
        list3d0->ReleaseSharedBuffers();
    if (list3d4 != 0)
        list3d4->ReleaseSharedBuffers();
}
