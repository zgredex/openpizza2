/* ShutdownScreens: releases the two global screen managers exactly once
   (0x404760). */
extern "C" {
extern char DAT_0057c5f8;
extern int DAT_0057c5cc;
extern int DAT_0057c5c8;
}

struct Screen {
    virtual void Destroy(int flag);
};

void ShutdownScreens()
{
    if (DAT_0057c5f8 != 1) {
        DAT_0057c5f8 = 1;
        if (DAT_0057c5cc != 0) {
            ((Screen *)DAT_0057c5cc)->Destroy(1);
            DAT_0057c5cc = 0;
        }
        if (DAT_0057c5c8 != 0) {
            ((Screen *)DAT_0057c5c8)->Destroy(1);
            DAT_0057c5c8 = 0;
        }
    }
}
