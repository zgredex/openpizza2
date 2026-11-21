/* UI_RenderDrawCommand (0x521dd0): dispatches a draw command either to a
   sprite draw or to a direct pixel write in the surface. */
struct Sprite {
    void GetSize(int *width, int *height);
    void Draw(void *surface, int x, int y);
};

struct Surface {
    char pad[0x20];
    int width;
    char pad2[0x28 - 0x24];
    short *pixels;
};

struct DrawCommand {
    int type;
    Sprite *sprite;
    short value;
};

struct UI {
    char pad[0x60];
    Sprite *sprite;
    char pad2[0x68 - 0x64];
    Surface *surface;

    void RenderDrawCommand(int x, int y, DrawCommand *command);
};

void UI::RenderDrawCommand(int x, int y, DrawCommand *command)
{
    switch (command->type) {
    case 0:
        if (-1 < x && -1 < y) {
            int px = x;
            int py = y;

            sprite->GetSize(&x, &y);
            if (px < x && py < y)
                surface->pixels[surface->width * py + px] = command->value;
        }
        break;
    case 1:
        command->sprite->Draw(surface, x, y);
        break;
    }
}
