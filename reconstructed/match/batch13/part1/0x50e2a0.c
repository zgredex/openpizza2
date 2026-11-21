/* Person_SetAtWork (0x50e2a0). */
struct IDMap {
    char pad[0x14];
    void *Lookup(int key, int *out);
};
struct Rating {
    char pad0[0xc];
    int value;              /* 0x0c */
};
struct Game {
    char pad0[0x20];
    IDMap map;              /* 0x20 */
};
struct Person {
    char pad0[0xc];
    int value;              /* 0x0c */
    char pad0b[0x20];       /* to 0x30 */
    int type;               /* 0x30 */
    char pad1[0x1c];        /* to 0x50 */
    int key;                /* 0x50 */
    char pad2[0x2c];        /* to 0x80 */
    char atWork;            /* 0x80 */

    void SetMotivation(int value);
};
extern Game *DAT_0057c670;

extern int __fastcall Game_GetContextCompanyRating(int paramA, int paramB,
                                                   int type);

void __fastcall Person_SetAtWork(Person *person, int paramB, int paramC,
                                 char atWork)
{
    if (person->atWork != atWork) {
        person->atWork = atWork;
        if (paramC != 0 &&
            (person->type == 0x11 || person->type == 0x13 ||
             person->type == 0x14)) {
            int rating = Game_GetContextCompanyRating(paramC, paramB,
                                                      person->type);
            int key = person->key;
            Person *target = (Person *)DAT_0057c670->map.Lookup(key, 0);

            if (target != 0) {
                int value = target->value - rating;

                if (value < 0)
                    value = 0;
                target->SetMotivation(value);
            }
        }
    }
}
