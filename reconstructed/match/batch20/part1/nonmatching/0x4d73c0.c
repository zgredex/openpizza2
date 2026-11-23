/* City::~City (0x4d73c0). */
extern "C" void __fastcall List_Node_Reset(void *);
extern "C" void __fastcall List_Node_Destroy(void *);
void operator delete(void *);

struct VObj {
    virtual void v0(int);
};

struct IDMapHelper {
    int data[5];
    int count;
    int pad;
    ~IDMapHelper() { List_Node_Destroy(this); }
    void Reset() { List_Node_Reset(this); }
    void *Lookup(int key, int *index);
};

struct City {
    char pad[0xfa4];
    VObj *obj1;
    IDMapHelper map1;
    IDMapHelper map2;
    char pad2[0x10a8 - 0xfe4];
    VObj *obj2;
    virtual ~City();
};

City::~City()
{
    int i;
    int n;

    if (obj1 != 0) {
        obj1->v0(1);
    }
    for (i = 0; i < map1.count; i++) {
        VObj *p = (VObj *)map1.Lookup(i, 0);
        if (p != 0) {
            p->v0(1);
        }
    }
    map1.Reset();
    n = map2.count;
    for (i = 0; i < n; i++) {
        void *v = map2.Lookup(i, 0);
        operator delete(v);
    }
    map2.Reset();
    if (obj2 != 0) {
        obj2->v0(1);
    }
}
