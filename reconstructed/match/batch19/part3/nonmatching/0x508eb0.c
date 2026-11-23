/* Game_UpdatePlayerObject (0x508eb0). */

extern char *DAT_0057c670;

struct Grid {
    int GetCell(int x, int y);
};

struct Array {
    void GetRecord28(int index, int value);
};

struct City {
    int IndexOfListValue(int a, int b, int c);
};

struct Game {
    int GetPlayerSubmapValue(int a, int b);
    int PickRandomUnownedAdjacentRecord(void *self, int a, int b);
};

struct PlayerObject {
    char pad0[0x84];
    int a84;                    /* 0x84 */
    int a88;                    /* 0x88 */
    int a8c;                    /* 0x8c */
    char pad1[0x34];
    Grid *grid;                 /* 0xc4 */
    char pad2[0x2c];
    char *state;                /* 0xf4 */

    void UpdatePlayerObject(int param);
};

void PlayerObject::UpdatePlayerObject(int param)
{
    char *state = this->state;
    void *map = (void *)((Game *)DAT_0057c670)
                    ->GetPlayerSubmapValue(*(int *)(state + 8),
                                           *(int *)(state + 0x2c));

    if (map == 0)
        return;
    int record = ((Game *)map)->PickRandomUnownedAdjacentRecord(this, 1, param);

    if (record == 0)
        return;
    int a = *(int *)(record + 0x1c);
    int b = *(int *)(record + 0x18);
    int cell = grid->GetCell(b, a);
    int index = ((City *)DAT_0057c670)
                    ->IndexOfListValue(*(int *)(*(int *)(cell + 8) + 0x10),
                                       *(int *)(record + 4),
                                       *(int *)(record + 8));

    a84 = index;
    a88 = **(int **)(cell + 8);
    switch (index) {
    case 0:
        b = b + 3;
        break;
    case 1:
        a = a - 3;
        break;
    case 2:
        a = a + 1;
        b = b - 2;
        break;
    case 3:
        a = a + 3;
        b = b + 1;
        break;
    default:
        goto done;
    }
    cell = grid->GetCell(b, a);
done:
    a8c = **(int **)(cell + 8);
    ((Array *)grid)->GetRecord28(
        1, (int)*(short *)(*(int *)(cell + 8) + 0x24));
}
