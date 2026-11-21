/* MapObject_SettlePendingAmount (0x47c7d0): best genuine C++ attempt.  It
   reproduces the two float comparisons and the three member calls; the
   compiler only differs in whether the pending float is reloaded from the
   object (original) or spilled once to a frame slot. */
extern float DAT_0055c2e4;

struct Game {
    void CanAfford(int type, float amount, char flag, int reason);
};

struct Stats {
    void AddRecordValue(int type, float amount, int reason);
};

struct Object {
    void SetIndex171C(int value);
};

struct MapObject {
    char pad[0x171c];
    float pending;

    void SettlePendingAmount();
};

void MapObject::SettlePendingAmount()
{
    if (pending < DAT_0055c2e4) {
        ((struct Game *)this)->CanAfford(4, pending, 0, -1);
    }
    if (pending > DAT_0055c2e4) {
        ((struct Stats *)this)->AddRecordValue(0x15, pending, -1);
    }
    ((struct Object *)this)->SetIndex171C(0);
}
