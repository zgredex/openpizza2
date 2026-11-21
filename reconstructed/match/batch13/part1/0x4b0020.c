/* StatisticsBackdrop_UpdateCompanyValues (0x4b0020). */
struct Window {
    void SetText(int id, char *text);
};
struct Game {
    void *GetPlayerBySlot(int slot);
};
struct Company {
    char pad0[0x11c];
    int value;              /* 0x11c */
};
extern Game *DAT_0057c670;
extern Company *DAT_0057d66c[6];
extern char STR_005686f4[];
extern void String_Format(char *buffer, char *format, int value);

void __cdecl StatisticsBackdrop_UpdateCompanyValues(Window *window)
{
    char text[64];
    int index = 0;
    int id = 0x403;
    Company **entry = DAT_0057d66c;

    do {
        void *player = DAT_0057c670->GetPlayerBySlot(index);

        if (player != 0) {
            String_Format(text, STR_005686f4, (*entry)->value);
            window->SetText(id, text);
        }
        entry++;
        index++;
        id += 3;
    } while ((int)entry < 0x57d684);
}
