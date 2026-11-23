/* City::SendPoliceToDistrict (0x4d9ef0). */
struct IDMapHelper {
    void *Lookup(int key, int *index);
};

struct VObj {
    virtual void v0(int);
};

struct Game {
    int ComputeCompanyValue(int *a, int *b, int *c);
};

struct City {
    void SendPoliceToDistrict(void *company);
    void *CollectBuildingsByType(int type, int a, int b);
    void SendPoliceUnits(int type, void *target, void *owner, int index);
};

void City::SendPoliceToDistrict(void *company)
{
    int *p;
    int i;
    int j = 0;
    int *list;
    int *record;
    void *target;
    int a;
    int b;
    int c;
    int value;

    for (i = 0; i < 5; i++) {
        p = (int *)((char *)this + 0x10d0 + i * 0x18);
        if (*(char *)((char *)p + 0x15) != 0 &&
            p[1] == *(int *)((char *)company + 0x3c)) {
            return;
        }
    }
    for (i = 0; i < 5; i++) {
        p = (int *)((char *)this + 0x10d0 + i * 0x18);
        if (*(char *)((char *)p + 0x15) != 0 && p[0] == -1) {
            break;
        }
    }
    if (i == 5) {
        return;
    }
    p = (int *)((char *)this + 0x10d0 + i * 0x18);
    p[0] = 1;
    p[1] = *(int *)((char *)company + 0x3c);
    value = ((Game *)this)->ComputeCompanyValue(&a, &b, &c);
    p[2] = value;
    *((char *)p + 0x14) = 0;
    *(int *)((char *)this + i * 0x18 + 0x10e0) = 0;
    p[3] = 0;

    list = (int *)CollectBuildingsByType(0x11, 0, 0);
    target = company;
    if (list[5] >= 1) {
        do {
            record = (int *)((IDMapHelper *)list)->Lookup(j, 0);
            target = record;
            if (record[3] == i) {
                break;
            }
            j++;
        } while (j < list[5]);
    }
    SendPoliceUnits(0x1b, target, *(void **)((char *)company + 0x16f0), i);
    if (list != 0) {
        ((VObj *)list)->v0(1);
    }
}
