/* Game_MoveTypeBObjectsToStateList (0x50ad80). */

extern char *DAT_0057c670;

struct IDMap {
    void *Lookup(int key, int *out);
};

struct GameObject {
    char pad[0x3c];
    struct IDMap map;
};

struct List {
    void List_Node_Reset();
};

struct StateList {
    void Game_AddObjectToStateList(void *object);
};

struct Game {
    void MoveTypeBObjectsToStateList(void *stateList);
};

void Game::MoveTypeBObjectsToStateList(void *stateList)
{
    int i;

    if (*(int *)((char *)this + 0x128) > 0) {
        i = 0;
        while (i < *(int *)((char *)this + 0x128)) {
            void *local = ((struct IDMap *)((char *)this + 0x114))
                              ->Lookup(i, 0);
            char *base = DAT_0057c670;
            void *object = ((struct IDMap *)(base + 0x3c))
                               ->Lookup((int)local, 0);
            if (*(int *)((char *)object + 0x38) == 0xb) {
                ((struct StateList *)stateList)
                    ->Game_AddObjectToStateList(object);
            }
            i++;
        }
        ((struct List *)((char *)this + 0x114))->List_Node_Reset();
    }
}
