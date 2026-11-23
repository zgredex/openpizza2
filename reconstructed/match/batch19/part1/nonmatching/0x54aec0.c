// UI_AddBriefingButton: creates a briefing button row.

extern "C" {
char *strcpy(char *dst, const char *src);
extern char DAT_005763a4[];
extern void *g_UIRootWindow;
}

struct Font {
    void WrapText(char *text, int width);
};

struct BriefingItem {
    char pad0[4];
    int row;
    int id;
    char padC[4];
    int state;
    char pad14[8];
    float position;
    char pad20[0x18];
    char text[0x100];
};

struct Array {
    char *GetRecordByKey(int key);
};

struct UI_Text {
    void BeginScrollAnimation(void *item, void *callback);
};

struct UI {
    char pad0[0x24];
    int imageHandle;
    char pad28[12];
    UI *child;
    void AddImage(int x, int y, int image, void *sprite, int a, int b);
    void SetChildLabelText(int id, int flag, char *text);
    Font *GetTextObject();
    void SetObjectTextByKey(int id, char *text);
    void AddBriefingButton(BriefingItem *item, int x, int y);
};

void UI::AddBriefingButton(BriefingItem *item, int x, int y)
{
    char text[2048];
    void *record;

    child->AddImage(x, y, imageHandle,
                    ((char **)DAT_005763a4)[(item->state == 0) + item->row * 2],
                    0, 0);
    child->SetChildLabelText(x, 1, 0);
    strcpy(text, item->text);
    ((UI *)g_UIRootWindow)->GetTextObject()->WrapText(text, 300);
    child->SetObjectTextByKey(x, text);
    item->id = x;
    item->position = (float)y;
    record = ((Array *)child)->GetRecordByKey(x);
    if (record != 0)
        ((UI_Text *)record)->BeginScrollAnimation(item, (void *)0x54a960);
}
