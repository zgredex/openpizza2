/* UI_EnsureBackBufferWindow (0x51fa80): creates the back buffer window on
   demand and configures it from the owning surface. */
struct Window {
    char data[0x11c];
    Window(int width, int height, int flags);
    void ConfigureFromOwner(void *surface);
};

struct Surface {
    char pad[0x20];
    int width;
    int height;
    char pad2[0x34 - 0x28];
    Window *backBuffer;

    void EnsureBackBufferWindow(void *surface);
};

void Surface::EnsureBackBufferWindow(void *surface)
{
    if (backBuffer == 0)
        backBuffer = new Window(width, height, 0x10);
    backBuffer->ConfigureFromOwner(surface);
}
