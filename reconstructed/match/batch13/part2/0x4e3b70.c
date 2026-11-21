/* Player_RestorePlanTargetAnimations (0x4e3b70). */
struct IDMap {
    char pad[0x14];
    void *Lookup(int key, int *out);
};
struct PlanEntry {
    char pad0[4];
    int active;             /* 0x04 */
    int type;               /* 0x08 */
    char pad1[0x20];        /* to 0x2c */
    int key;                /* 0x2c */
};
struct Player {
    char pad0[0x12c];
    IDMap map;              /* 0x12c */
    int count;              /* 0x140 */

    void RestorePlanTargetAnimations();
};
struct Game {
    char pad0[4];
    IDMap map;              /* 0x04 */
    char pad1[0x2f4 - 0x18];
    int key;                /* 0x2f4 */

    void *FindRecordByField24(int key);
    void SetFacadeAndLogoVariant(int value, void *record, void *player);
};
extern Game *DAT_0057c670;

void Player::RestorePlanTargetAnimations()
{
    int total = count;
    Game *game = (Game *)((char *)DAT_0057c670 + 0);
    void *target = DAT_0057c670->map.Lookup(DAT_0057c670->key, 0);
    int index = 0;

    if (total > 0) {
        do {
            PlanEntry *entry = (PlanEntry *)map.Lookup(index, 0);

            if (entry->active != 0 && entry->type == 3) {
                int key = entry->key;
                void *record = ((Game *)target)->FindRecordByField24(key);

                if (record != 0)
                    ((Game *)target)->SetFacadeAndLogoVariant(1, record, this);
            }
            index++;
        } while (index < total);
    }
    (void)game;
    (void)target;
}
