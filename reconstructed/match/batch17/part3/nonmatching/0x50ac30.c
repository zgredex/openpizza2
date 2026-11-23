struct IDMap {
    int unused;
    int Lookup(int index, int *out);
};

struct GameData {
    char pad[0x20];
    IDMap map;
};

struct Rating {
    int GetComposite();
};

struct UI {
    char pad0[0x50];
    int index;
    char pad1[0xc8 - 0x54];
    int *icon;
    void SetChildIconAndRatingHeight();
};

extern GameData *DAT_0057c670;
extern float DAT_0055c680;

void UI::SetChildIconAndRatingHeight()
{
    if (*(int *)((char *)this + 0xc8) != 0) {
        int record = ((IDMap *)((char *)DAT_0057c670 + 0x20))
                         ->Lookup(*(int *)((char *)this + 0x50), 0);
        int rating = ((Rating *)record)->GetComposite();
        switch (*(unsigned char *)(record + 0x824)) {
        case 0:
            *(short *)(*(int *)((char *)this + 0xc8) + 8) = 0x2c;
            break;
        case 1:
            *(short *)(*(int *)((char *)this + 0xc8) + 8) = 0x2e;
            break;
        case 2:
            *(short *)(*(int *)((char *)this + 0xc8) + 8) = 0x2d;
            break;
        case 3:
            *(short *)(*(int *)((char *)this + 0xc8) + 8) = 0x2b;
            break;
        }
        *(short *)(*(int *)((char *)this + 0xc8) + 10) =
            0x99 - (short)(rating * DAT_0055c680);
        if (*(short *)(*(int *)((char *)this + 0xc8) + 10) < 0x88)
            *(short *)(*(int *)((char *)this + 0xc8) + 10) = 0x88;
    }
}
