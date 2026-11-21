/* Person_WanderToRandomTile: sends a person to a random tile in the city
   (0x507b40). */
extern "C" void NoOp_Stub(void *param);

struct Map {
    int ApplyRandomTileVariant();
};

struct Person {
    void PathToTileAndStep(int target, int tile);
    void WanderToRandomTile();
};

void Person::WanderToRandomTile()
{
    char *self = (char *)this;
    int target;
    int tile;

    if (*(int *)(self + 0xd0) == 0)
        NoOp_Stub((void *)0x572fbc);
    if (*(int *)(self + 0xc8) != 0)
        target = *(int *)(*(int *)(self + 0xc8) + 0x20);
    else
        target = 0;
    tile = ((Map *)*(int *)(self + 0xd0))->ApplyRandomTileVariant();
    PathToTileAndStep(target, tile);
}
