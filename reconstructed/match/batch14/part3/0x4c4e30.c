/* Window_UpdatePolicePage (0x4c4e30): stores the current player and shows the
   police page totals. */
struct IDMap {
    char pad[0x14];
    int count;
    void *Lookup(int key, int *result);
};

struct GameGlobal {
    char pad[4];
    IDMap recordMap;
    char pad2[0x200 - 0x1c];
    void *buildings[1];
    char pad3[0x2ec - 0x204];
    int currentBuilding;
    char pad4[0x2f4 - 0x2f0];
    int recordId;
};

extern GameGlobal *DAT_0057c670;
extern int DAT_0057dcf8;
extern int DAT_0057dcf4;
extern char STR_0056aef4[];
extern char STR_00568730[];

extern "C" {
void Gadget_SetTextf(void *window, int id, char *format, int value);
void PolicePage_FillContributionStats(void *window);
}

struct SoundApi {
    void ProcessEvent(int type, int first, int second);
};

extern SoundApi *DAT_0057ba0c;

extern "C" void Window_UpdatePolicePage(void *window)
{
    DAT_0057dcf8 = (int)DAT_0057c670->buildings[
        DAT_0057c670->currentBuilding];
    DAT_0057dcf4 = (int)DAT_0057c670->recordMap.Lookup(
        DAT_0057c670->recordId, 0);
    Gadget_SetTextf(window, 0x1fee, STR_0056aef4, 1000);
    Gadget_SetTextf(window, 0x1fef, STR_00568730, 1000);
    DAT_0057ba0c->ProcessEvent(0xd, 0, 1);
    PolicePage_FillContributionStats(window);
}
