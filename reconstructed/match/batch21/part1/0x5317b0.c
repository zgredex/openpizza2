/* UI::CreateMovieWindow (0x5317b0). */
extern "C" void *operator_new(unsigned int size);

struct MovieParams {
    char name[0x40];
    int value;
};

struct MovieWindow {
    char data[0xbc];
    MovieWindow(int a, int b, int c, int d, void *params, char *name, int e, void *owner);
    ~MovieWindow();
};

struct UI {
    void EnsureObjectArray(void *object, int count);
    int CreateMovieWindow(int a, int b, int c, int d, int e);
};

int UI::CreateMovieWindow(int a, int b, int c, int d, int e)
{
    MovieParams params;

    params.value = d;
    params.name[0] = 0;
    MovieWindow *window = new MovieWindow(a, b, c, 0, &params, 0, e, this);
    EnsureObjectArray(window, a);
    return 1;
}
