/* Screen_MissionBriefing_Populate - 0x4cdac0, 482 bytes */
struct City
{
    char pad[0x418];
};

struct Font
{
    char pad[0x9b0];
    int lineHeight;
};

struct Gadget
{
    void SetText(int key, const char *text);
};

struct Window_GadgetNotify_Text
{
    void SetText(int key, const char *text);
    int GetLineCount(int key);
    int GetHeight(int key);
    Font *GetFont(int key);
    void ResetScroll(int key, int flag);
};

struct Window_GadgetNotify_Slider
{
    void SetRange(int key, int min, int max, int notify);
    void SetValue(int key, int value, int flag);
    void SetChangeNotify(int key, int flag);
};

struct UI
{
    void ShowChildByID(int id);
    void RemoveObjectByKey(int key);
    void SetChildLabelText(int id, int flag, const char *text);
};

struct Sprite
{
    void AddSprite(int id, int x, int y, const char *name);
};

struct Sound
{
    void PlayMissionSpeech(int id, char flag);
};

struct Array
{
    void GetPairByKey(int key, int *first, int *second);
};

struct IDMap
{
    void *Lookup(int key, int *fallback);
};

extern int DAT_0057c5c0;
extern char *DAT_0058280c;
extern char *DAT_00581bfc;
extern int DAT_0057c590[];
extern int DAT_0057bb40;
extern int DAT_0057c5d8;
extern char STR_0056b380[];
extern char STR_0056b330[];
extern int DAT_00582e4c;
extern int DAT_0057ba0c;

extern "C" City *__cdecl CityDefinition_ParseIni(int config, char *name);
extern "C" void __cdecl String_Format(char *dest, const char *format, ...);

void __cdecl Screen_MissionBriefing_Populate(void *page)
{
    char name[64];
    int pair1;
    int pair2;
    void *value;
    City *city;
    int lines;
    int height;
    Font *font;
    int perPage;

    if (DAT_0057c5c0 != 0)
        ((Gadget *)page)->SetText(0x433, DAT_0058280c);
    if (DAT_0057c5c0 == 7)
        ((Gadget *)page)->SetText(0x433, DAT_00581bfc);

    value = ((IDMap *)DAT_0057c590)->Lookup(DAT_0057bb40, 0);
    String_Format(name, STR_0056b380, value);
    city = CityDefinition_ParseIni(DAT_0057c5d8, name);
    ((Window_GadgetNotify_Text *)page)->SetText(0x42c, (char *)city + 0x418);
    ((Window_GadgetNotify_Text *)page)->SetText(0x42d, (char *)city);
    String_Format(name, STR_0056b330, (char *)city + 0x40);
    ((Array *)page)->GetPairByKey(0x435, &pair1, &pair2);
    ((Sprite *)page)->AddSprite(200000, pair1, pair2, name);
    lines = ((Window_GadgetNotify_Text *)page)->GetLineCount(0x42c);
    height = ((Window_GadgetNotify_Text *)page)->GetHeight(0x42c);
    font = ((Window_GadgetNotify_Text *)page)->GetFont(0x42c);
    perPage = height / font->lineHeight;
    if (perPage < lines)
    {
        ((UI *)page)->ShowChildByID(0x42e);
        ((Window_GadgetNotify_Slider *)page)->SetRange(0x42e, 0, (lines - perPage) * 100, 1);
        ((Window_GadgetNotify_Slider *)page)->SetValue(0x42e, 0, 0);
        ((Window_GadgetNotify_Slider *)page)->SetChangeNotify(0x42e, 1);
    }
    else
    {
        ((UI *)page)->RemoveObjectByKey(0x42e);
        ((Window_GadgetNotify_Text *)page)->ResetScroll(0x42c, 0);
    }
    ((UI *)page)->SetChildLabelText(200000, 1, 0);
    ((UI *)page)->SetChildLabelText(0x42e, 1, 0);
    ((UI *)page)->SetChildLabelText(0x433, 1, 0);
    ((UI *)page)->SetChildLabelText(0x434, 1, 0);
    ((Window_GadgetNotify_Text *)page)->SetText(0x429, (const char *)DAT_00582e4c);
    ((Sound *)DAT_0057ba0c)->PlayMissionSpeech(DAT_0057bb40, 0);
}
