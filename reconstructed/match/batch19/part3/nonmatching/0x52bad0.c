/* Movie_UpdateFrame (0x52bad0). */

extern int DAT_0057c5c8;
extern int (__stdcall *DAT_0055c2ac)(void *bink);

struct UI {
    void ClipRect(int *rect, int flag);
    void QueueControlCommand(int command, int a, int b);
};

struct RecordList {
    void TickFrame(int index);
};

struct MovieWindow {
    void AdvanceFrame(int value, void *bink);
};

struct Movie {
    char pad0[4];
    int command;                /* 0x04 */
    UI *ui;                     /* 0x08 */
    char pad1[0x1c];
    int rect[1];                /* 0x28 */
    char pad2[0x28];
    RecordList *records;        /* 0x54 */
    char pad3[0x40];
    int frame;                  /* 0x98 */
    char pad4[8];
    int state;                  /* 0xa4 */
    char pad5[8];
    int played;                 /* 0xb0 */
    int total;                  /* 0xb4 */
    int *bink;                  /* 0xb8 */

    void UpdateFrame(int delta);
};

void Movie::UpdateFrame(int delta)
{
    if (state == 3) {
        if (bink[3] == 0 && DAT_0055c2ac((void *)*bink) == 0) {
            ((MovieWindow *)this)->AdvanceFrame(DAT_0057c5c8,
                                                (void *)*bink);
            ui->ClipRect(rect, 1);
            return;
        }
    } else {
        total = total + delta;
        if (total > 100) {
            while (total > 100)
                total = total - 100;
            int frame = this->frame;
            RecordList *records = this->records;

            this->total = total;
            if (frame >= 0 && frame < *(int *)((char *)records + 0x48)) {
                int flag = *(unsigned char *)(*(int *)((char *)records + 0x4c) +
                                              0x3e + frame * 0x48);

                if (flag != 0) {
                    records->TickFrame(frame);
                    ui->ClipRect(rect, 1);
                    return;
                }
            }
            if (played == 0) {
                played = 1;
                ui->QueueControlCommand(command, 0, 0);
            }
        }
    }
}
