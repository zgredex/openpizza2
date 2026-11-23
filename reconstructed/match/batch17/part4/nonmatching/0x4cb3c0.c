struct UI {
    void SetChildVisibleByID(int id, int visible);
};

extern int DAT_0056b2dc[];
extern int DAT_0056b2f0[];
extern int DAT_0056b304[];

extern "C" void FreePlaySetup_SetOpponentSlotEnabled(void *ui, int slot,
                                                     unsigned enabled)
{
    int index = slot - 1;
    unsigned visible = enabled & 0xff;
    ((UI *)ui)->SetChildVisibleByID(index * 2 + 0x441, visible);
    ((UI *)ui)->SetChildVisibleByID(index * 2 + 0x442, visible);
    int id = index * 8 + 0x454;
    int count = 8;
    do {
        ((UI *)ui)->SetChildVisibleByID(id, visible);
        id++;
        count--;
    } while (count != 0);
    ((UI *)ui)->SetChildVisibleByID(index * 4 + 0x4c0, visible);
    ((UI *)ui)->SetChildVisibleByID(index * 4 + 0x4c2, visible);
    ((UI *)ui)->SetChildVisibleByID(slot + 0x4db, visible);
    ((UI *)ui)->SetChildVisibleByID(DAT_0056b2dc[index], visible);
    ((UI *)ui)->SetChildVisibleByID(DAT_0056b2f0[index], visible);
    ((UI *)ui)->SetChildVisibleByID(DAT_0056b304[index], visible);
}
