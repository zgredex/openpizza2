class Get {
public:
    int Field24();
};
class UIChild {
public:
    char pad[4];
    int field4;
};
class UI {
public:
    char pad0[0x224];
    int field224;
    int field228;
    int field22c;
    char pad1[0x82c8 - 0x230];
    int field82c8;
    int field82cc;
    int field82d0;
    int field82d4;
    int field82d8;
    UIChild *field82dc;
    char pad2[0x833c - 0x82e0];
    int field833c;
    int field8340;
    int field8344;
    int field8348;
    void ClearDestroyedObjectReferences(int object);
    void RefreshChildRect();
    void QueueControlCommand(int value, int command, int param);
};
void UI::ClearDestroyedObjectReferences(int object)
{
    if (object == this->field82d4) {
        this->field82c8 = 0;
        this->field82d4 = 0;
    }
    if (object == this->field22c) {
        this->field224 = 0;
        this->field22c = 0;
    }
    if (object == (int)this->field82dc) {
        if (this->field82d0 != 0) {
            if (((Get *)this->field82dc)->Field24() != 0) {
                ((UI *)this->field82d0)->QueueControlCommand(
                    ((UIChild *)this->field82dc)->field4, 0xd, 0);
            }
        }
        this->RefreshChildRect();
        this->field82dc = 0;
        this->field82d0 = 0;
    }
    if (object == this->field833c) {
        this->field833c = 0;
        this->field8348 = 0;
    }
}
