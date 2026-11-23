extern char *DAT_0057c670;
extern char *DAT_0057c5e0;
extern char DAT_0057ca2c;
extern char *DAT_0057cac8;
extern int DAT_0057cacc;
extern int DAT_0057cabc;
extern int DAT_0057cac0;

extern "C" void String_Format(char *buffer, char *format, int arg1, int arg2);

/* RecipeEditor_ShowIngredientCursorSprite: shows the ingredient cursor sprite
   preview (0x49d970). */
struct IDMap {
    void *Lookup(int index, int *unused);
};

struct Sprite {
    void GetRenderSize(int *width, int *height);
};

struct Game {
    void SetObjectInfoWindowVisible(int visible);
};

struct UI {
    void ReleasePendingSprite();
    void *LoadChildSprite(char *name);
    void RefreshChildSprite(int visible, int x, int y);
    int ResetInputHelper();
    void ApplyChildSpriteTint(int helper, int tint);
};

extern "C" void __cdecl RecipeEditor_ShowIngredientCursorSprite(int index)
{
    char name[64];
    int height;
    void *sprite;

    if (index < 0) {
        ((UI *)DAT_0057c5e0)->ReleasePendingSprite();
        DAT_0057ca2c = 0;
        return;
    }
    {
        int record = (int)((IDMap *)DAT_0057cac8)->Lookup(index, 0);

        String_Format(name, (char *)0x568948, *(int *)(record + 0xd0), DAT_0057cacc);
        sprite = ((UI *)DAT_0057c5e0)->LoadChildSprite(name);
        ((Game *)DAT_0057c670)->SetObjectInfoWindowVisible(0);
        if (sprite != 0) {
            int width;
            int helper;

            ((Sprite *)sprite)->GetRenderSize(&index, &height);
            DAT_0057cabc = -(index / 2);
            DAT_0057cac0 = -(height / 2);
            ((UI *)DAT_0057c5e0)->RefreshChildSprite(1, DAT_0057cabc, DAT_0057cac0);
            DAT_0057ca2c = 1;
            helper = ((UI *)DAT_0057c5e0)->ResetInputHelper();
            ((UI *)DAT_0057c5e0)->ApplyChildSpriteTint(helper, 1);
        }
    }
}
