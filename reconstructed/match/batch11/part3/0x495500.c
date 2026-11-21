/* Game_RebuildObjectTypeLists: frees the four object type lists and collects
   them again from the map (0x495500). */
struct List {
    virtual void Destroy(int flag);
    void Reset();
};

struct Game {
    void *CollectObjectsByType(int type);
};

struct IDMap {
    void *Lookup(int index, int *out);
};

struct World {
    char pad[4];
    char map[0x14];
    char pad2[0x2dc];
    int index;
};

extern int DAT_0057c670;
extern char DAT_0057c6e0[];
extern char DAT_00568760[];

void Game_RebuildObjectTypeLists(void)
{
    int i;

    for (i = 0; i < 0x10; i += 4) {
        if (*(void **)(DAT_0057c6e0 + i) != 0) {
            ((struct List *)*(void **)(DAT_0057c6e0 + i))->Reset();
            if (*(void **)(DAT_0057c6e0 + i) != 0) {
                ((struct List *)*(void **)(DAT_0057c6e0 + i))->Destroy(1);
            }
        }
        struct World *world = (struct World *)DAT_0057c670;
        struct Game *game = (struct Game *)
            ((struct IDMap *)((char *)world + 4))->Lookup(world->index, 0);
        *(void **)(DAT_0057c6e0 + i) =
            game->CollectObjectsByType(*(int *)(DAT_00568760 + i));
    }
}
