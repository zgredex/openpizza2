/* Movie_ReleasePlayer: releases the movie player under its critical
   section (0x5238c0). */
struct CS {
    void Enter(void);
    void Leave(void);
};

struct MoviePlayer {
    virtual void Release(int flags);
};

void __fastcall Movie_ReleasePlayer(int movie)
{
    if (*(int *)(movie + 0x1c4) != 0) {
        ((struct CS *)*(int *)(movie + 0x1c8))->Enter();
        if (*(struct MoviePlayer **)(movie + 0x1c4) != 0)
            (*(struct MoviePlayer **)(movie + 0x1c4))->Release(1);
        *(int *)(movie + 0x1c4) = 0;
        ((struct CS *)*(int *)(movie + 0x1c8))->Leave();
    }
}
