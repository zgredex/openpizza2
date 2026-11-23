extern "C" char *strcpy(char *, const char *);
#pragma intrinsic(strcpy)
extern "C" int String_Format(char *buffer, char *format, ...);

extern int DAT_0057c5e0;
extern char *DAT_00582a68;
extern char *DAT_00582ce0;
extern char DAT_005682f8[];
extern char DAT_005682ec[];

struct Array {
    void *GetRecordByKeyPtr(int key);
};

struct Window {
    void GadgetNotify_Text_SetText(int id, char *text);
};

extern "C" int __fastcall CS_Enter(int lock);
extern "C" int __fastcall CS_Leave(int lock);

struct Game {
    char pad[0x94];
    int *clock;
    char pad2[0x25c - 0x94 - 4];
    Window *window;
    char pad3[0x1508 - 0x25c - 4];
    int flag;
    void UpdateDateLabels(Window *target);
};

void Game::UpdateDateLabels(Window *target)
{
    char timeText[32];
    char dateText[32];

    if (target == 0) {
        target = window;
        if (target == 0)
            return;
    }
    if (flag != 0) {
        strcpy(timeText, DAT_00582a68);
    } else {
        String_Format(timeText, DAT_005682f8,
                      ((unsigned char *)clock)[7],
                      (unsigned char)(((unsigned char *)clock)[6] * 5));
    }
    String_Format(dateText, DAT_005682ec,
                  ((unsigned char *)clock)[8] + 1, DAT_00582ce0,
                  ((unsigned short *)clock)[2] % 100);
    CS_Enter(*(int *)(DAT_0057c5e0 + 0x1c8));
    if (((Array *)target)->GetRecordByKeyPtr(0x410) != 0)
        target->GadgetNotify_Text_SetText(0x410, timeText);
    if (((Array *)target)->GetRecordByKeyPtr(0x1f41) != 0)
        target->GadgetNotify_Text_SetText(0x1f41, dateText);
    CS_Leave(*(int *)(DAT_0057c5e0 + 0x1c8));
}
