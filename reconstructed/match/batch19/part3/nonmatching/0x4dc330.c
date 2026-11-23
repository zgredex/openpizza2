/* City_ResetPoliceDistrictSlot (0x4dc330). */

struct IDMapHelper {
    char pad[0x14];

    void *Lookup(int key, int *out);
};

struct Player {
    char pad0[0x148];
    IDMapHelper map;            /* 0x148 */
    int units;                  /* 0x15c */
};

struct Game {
    Player *GetPlayerBySlot(int slot);
};

extern Game *DAT_0057c670;

extern "C" int Random_RangeFast(int min, int max);

struct DistrictSlot {
    int a;                      /* 0x00 */
    int b;                      /* 0x04 */
    int c;                      /* 0x08 */
    int d;                      /* 0x0c */
    int e;                      /* 0x10 */
    char f;                     /* 0x14 */
    char pad[3];
};

struct City {
    char pad0[0xc98];
    int ratings[6];             /* 0xc98 */
    char pad1[0x10d0 - 0xc98 - 0x18];
    DistrictSlot slots[1];      /* 0x10d0 */

    void SendPoliceToDistrict(void *record);
    void ResetPoliceDistrictSlot(int mode, int slot);
};

void City::ResetPoliceDistrictSlot(int mode, int slot)
{
    int i = 0;
    int best = 999;

    slots[slot].a = -1;
    slots[slot].b = -1;
    slots[slot].c = -1;
    slots[slot].f = 0;
    *(int *)((char *)this + (slot * 3 + 0x21c) * 8) = 0;
    slots[slot].d = 0;
    if (mode == 2) {
        int *rating = ratings;
        int candidate = slot;

        do {
            if (DAT_0057c670->GetPlayerBySlot(i) != 0 && *rating < best) {
                if (DAT_0057c670->GetPlayerBySlot(i)->units > 0) {
                    best = *rating;
                    candidate = i;
                }
            }
            i++;
            rating++;
        } while (i < 6);
        if (i != 6) {
            int units = DAT_0057c670->GetPlayerBySlot(candidate)->units;
            int index = Random_RangeFast(0, units - 1);
            Player *player = DAT_0057c670->GetPlayerBySlot(candidate);
            void *record = player->map.Lookup(index, 0);

            SendPoliceToDistrict(record);
        }
    }
}
