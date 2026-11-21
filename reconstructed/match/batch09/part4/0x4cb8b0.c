/* UI_SetPlayerLogoSprite: formats a player-logo sprite name and assigns it to
   a UI button (0x4cb8b0). */
extern "C" {
extern char STR_0056b318[];
extern void String_Format(char *buffer, char *format, ...);
}

struct UI {
    void SetButtonSpriteByName(int id, char *name);
};

void UI_SetPlayerLogoSprite(void *window, int first, int second, int button)
{
    char name[256];

    String_Format(name, STR_0056b318, first + 1, second + 1);
    ((UI *)window)->SetButtonSpriteByName(button, name);
}
