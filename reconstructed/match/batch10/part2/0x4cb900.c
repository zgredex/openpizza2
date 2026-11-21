/* FreePlaySetup_ShowMapPreview: format the map name and show its preview
   sprite (0x4cb900). */
extern "C" int DAT_0057de38;
extern "C" int DAT_0057bb40;
extern "C" int DAT_0057ba0c;
extern "C" char DAT_0056b330;

extern "C" char *NameMap_GetRecordString(void *map, int key);
extern "C" int String_Format(char *buffer, char *format, ...);

struct UI {
    void SetButtonSpriteByName(int id, char *name);
};

struct Sound {
    void PlayBuildingSpecialSfx(int id);
};

extern "C" void FreePlaySetup_ShowMapPreview(void *menu)
{
    char name[64];
    char *mapName = NameMap_GetRecordString(&DAT_0057de38, DAT_0057bb40);

    String_Format(name, &DAT_0056b330, mapName);
    ((struct UI *)menu)->SetButtonSpriteByName(0x4e4, name);
    ((struct Sound *)DAT_0057ba0c)->PlayBuildingSpecialSfx(DAT_0057bb40);
}
