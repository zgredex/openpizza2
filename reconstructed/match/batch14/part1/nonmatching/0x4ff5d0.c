/* AI_HireCourier (0x4ff5d0): hires a free staff member as a courier and
   sends it to a target. */
extern int DAT_0057c670;

struct IDMap {
    int Lookup(int key, int *out);
};

struct Game {
    char pad[0x3c];
    IDMap couriers;            /* 0x3c */
    int FindFreeStaffRecord(int role);
    int CanAffordWithCurrency(int item, float price, char flag, int arg);
};

struct Thug {
    void StartRestaurantRampage(int target, int mode);
};

int __stdcall AI_HireCourier(void *param_1, int param_2)
{
    int *record;
    Thug *courier;
    int target;

    record = (int *)((Game *)param_1)->FindFreeStaffRecord(0x1e);
    if (record != 0) {
        return 0;
    }
    courier = (Thug *)((Game *)DAT_0057c670)
                  ->couriers.Lookup(*record, 0);
    if (courier == 0) {
        return 0;
    }
    if ((char)((Game *)param_1)
            ->CanAffordWithCurrency(0x17, 5000.0f, 1, -1) == '\0') {
        return 0;
    }
    target = param_2;
    courier->StartRestaurantRampage(target, 0xf);
    *(int *)((char *)param_1 + 0x74) = *(int *)((char *)param_1 + 0x74) + 1;
    return 1;
}
