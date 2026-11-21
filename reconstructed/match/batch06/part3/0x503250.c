/* UI_AppendCommandIfActive: stores the active command id and appends the
   command to the panel's list (0x503250).  Build: /O2 /TP. */
struct List {
    int Add(int command);
};

struct Panel {
    char pad[8];
    int commandId;
    char pad2[0x48 - 0xc];
    int activeId;
    char pad3[0x60 - 0x4c];
    unsigned char active;
    char pad4[0x68 - 0x61];
    List list;
    void AppendCommandIfActive(int id, int command);
};

void Panel::AppendCommandIfActive(int id, int command)
{
    if (!active)
        return;
    if (id != activeId)
        return;
    commandId = id;
    if (command == -1)
        return;
    list.Add(command);
}
