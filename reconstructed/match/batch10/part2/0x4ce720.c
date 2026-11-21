/* Movie_PlayGameOverMovie: stop the current sound and play the lost-game
   movie (0x4ce720). */
extern "C" volatile int DAT_0056b40c;
extern "C" int DAT_0057ba0c;
extern "C" char DAT_0056b3d0;

struct SoundBuffer {
    void Release(void);
};

struct Sound {
    void StopCurrentBuffer(void);
};

struct Movie {
    void CreatePlayer(int x, int y, int width, char *name, int flags);
};

struct UI {
    void StartButtonMovie(int id, int flag);
};

extern "C" void Movie_PlayGameOverMovie(void *menu)
{
    struct Movie *movie;

    DAT_0056b40c = 1;
    ((struct SoundBuffer *)DAT_0057ba0c)->Release();
    ((struct Sound *)DAT_0057ba0c)->StopCurrentBuffer();
    movie = (struct Movie *)menu;
    movie->CreatePlayer(100, 0, 100, &DAT_0056b3d0, 1);
    ((struct UI *)movie)->StartButtonMovie(100, 0);
}
