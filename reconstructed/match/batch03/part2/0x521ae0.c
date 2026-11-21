/* UI_GetChildSize - 0x521ae0, 21 bytes */
struct Sprite
{
    void GetSize(int *width, int *height);
};

struct UI
{
    char pad[0x60];
    Sprite *sprite;

    void GetChildSize(int *width, int *height);
};

void UI::GetChildSize(int *width, int *height)
{
    sprite->GetSize(width, height);
}
