// Object_GetPlayerValue: maps a logical value selector to a child field.

extern void *DAT_0057c670;

struct GameObj {
    void *GetPlayerBySlot(int slot);
};

struct ChildObject {
    void SetChildField2C(int value);
};

struct WorldObject {
    void GetPlayerValue(int value);
};

void WorldObject::GetPlayerValue(int value)
{
    int player = 0;
    int type = *(int *)((char *)this + 0x30);

    if (type != 0xd) {
        if (*(int *)((char *)this + 0x110) == -1)
            return;
        player = (int)((GameObj *)DAT_0057c670)->GetPlayerBySlot(
            *(int *)((char *)this + 0x110));
    }
    type = *(int *)((char *)this + 0x30);
    {
        int selected;
        switch (type) {
        case 0xd:
            selected = value;
            break;
        case 0x17:
            selected = *(int *)(player + 100);
            break;
        case 0x1d:
            selected = *(int *)(player + 0x6c);
            break;
        default:
            selected = value;
        }
        switch (selected) {
    case 1:
        if (type == 0x1d || type == 0x17 || type == 0xd)
            ((ChildObject *)this)->SetChildField2C(0);
        break;
    case 2:
        if (type == 0x1d) {
            ((ChildObject *)this)->SetChildField2C(0x10);
            return;
        }
        if (type == 0x17) {
            ((ChildObject *)this)->SetChildField2C(0x10);
            return;
        }
        if (type == 0xd) {
            ((ChildObject *)this)->SetChildField2C(0x10);
            return;
        }
        break;
    case 3:
        if (type == 0x1d) {
            ((ChildObject *)this)->SetChildField2C(8);
            return;
        }
        if (type == 0x17) {
            ((ChildObject *)this)->SetChildField2C(8);
            return;
        }
        if (type == 0xd) {
            ((ChildObject *)this)->SetChildField2C(8);
            return;
        }
        break;
        }
    }
}
