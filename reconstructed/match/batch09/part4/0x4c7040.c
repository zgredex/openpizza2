/* CharacterSelect_SetPhotoSprite: formats a player-logo sprite name and
   assigns it to the character-select photo button (0x4c7040). */
extern "C" {
extern int DAT_0057dd44;
extern int DAT_0057ddb0;
extern char STR_0056b1d0[];
extern void String_Format(char *buffer, char *format, ...);
}

struct UI {
    void SetButtonSpriteByName(int id, char *name);
};

void CharacterSelect_SetPhotoSprite(void *window)
{
    char name[256];

    String_Format(name, STR_0056b1d0, DAT_0057ddb0 + 1, DAT_0057dd44 + 1);
    ((UI *)window)->SetButtonSpriteByName(0x43c, name);
}
