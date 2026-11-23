/* Sound_LoadSpeechSet (0x5478c0). */

extern char DAT_00575090[];
extern char *DAT_00582530;
extern char *DAT_00575170[];
extern "C" void String_Format(char *buffer, char *format, ...);

struct Device {
    virtual void v0(...);
    virtual void v1(...);
    virtual void v2(...);
    virtual void v3(...);
    virtual void v4(...);
    virtual void v5(...);
    virtual void v6(...);
    virtual void v7(...);
    virtual void v8(...);
    virtual void v9(...);
    virtual void v10(...);
    virtual void v11(...);
    virtual void v12(...);
    virtual void v13(...);
    virtual void v14(...);
    virtual void v15(...);
    virtual void v16(...);
    virtual void v17(...);
    virtual void v18(...);
    virtual void v19(...);
    virtual void v20(...);
    virtual void v21(...);
    virtual void v22(...);
    virtual void v23(...);
    virtual void v24(...);
    virtual void v25(...);
    virtual void v26(...);
    virtual void v27(...);
    virtual void v28(...);
    virtual void v29(...);
    virtual void v30(...);
    virtual void v31(...);
    virtual void v32(...);
    virtual void v33(...);
    virtual void v34(...);
    virtual void v35(...);
    virtual void v36(...);
    virtual void v37(...);
    virtual void v38(...);
    virtual void v39(...);
};

struct SoundSet {
    int mode;                   /* 0x00 */
    char pad0[4];
    Device *device;             /* 0x08 */
    char pad1[0xe8];
    int format;                 /* 0xf4 */
    char pad2[4];
    char flag;                  /* 0xfc */
    char pad3[0x77];
    char name[0x100];           /* 0x174 */
    int slots[2];               /* 0x274 */
};

extern "C" void __fastcall Sound_LoadSpeechSet(SoundSet *self)
{
    char buffer[260];
    int length = 0;
    char *p = self->name;

    while (*p++ != 0)
        length++;
    if (length == 0)
        return;
    if (self->mode == 1) {
        if (DAT_00575090[1] != 0)
            return;
    } else if (self->mode == 2 && DAT_00575090[1] == 0) {
        return;
    }
    if (self->flag == 0)
        return;

    char *prefix;
    if (DAT_00575090[1] != 0) {
        self->mode = 1;
        prefix = DAT_00582530;
    } else {
        self->mode = 2;
        prefix = self->name;
    }
    char **table = DAT_00575170;
    int *slot = self->slots;
    do {
        int j = 2;
        do {
            if (*slot != 0) {
                self->device->v20(*slot);
                *slot = 0;
            }
            String_Format(buffer, (char *)0x5760d0, prefix, *table);
            self->device->v10(buffer, slot);
            self->device->v39(self->format, *slot);
            table++;
            slot++;
            j--;
        } while (j != 0);
    } while (table < DAT_00575170 + 8);
}
