/* RecordList_BlitIndexedRLE (0x5346a0). */

extern "C" void __fastcall CS_Enter(int lock);
extern "C" void __fastcall CS_Leave(int lock);

struct Record {
    int id;                     /* 0x00 */
    char pad0[0x2e];
    short sprite;               /* 0x32 */
    char pad1[0x14];
};

struct RecordList {
    char pad0[6];
    short x;                    /* 0x06 */
    short y;                    /* 0x08 */
    short w;                    /* 0x0a */
    short h;                    /* 0x0c */
    char pad1[0x12];
    short *tableX;              /* 0x20 */
    short *tableY;              /* 0x24 */
    short *tableW;              /* 0x28 */
    short *tableH;              /* 0x2c */
    char pad2[5];
    char loaded;                /* 0x35 */
    char pad3[0x12];
    int count;                  /* 0x48 */
    Record *records;            /* 0x4c */
    char *anim;                 /* 0x50 */
    char pad4[0x2c];
    int *sprites;               /* 0x80 */

    void EnsureLoaded();
    void BlitIndexedRLE(int a, unsigned *b, int index, double d1, double d2);
};

struct Surface {
    void BlitRLESkipToRGB(int a, unsigned *b, int sprite, int p5, int p6);
};

void RecordList::BlitIndexedRLE(int a, unsigned *b, int index, double d1,
                                double d2)
{
    if (index < 0 || index >= this->count)
        return;
    CS_Enter(0x5842a0);
    if (this->records[index].id == -1) {
        CS_Leave(0x5842a0);
        return;
    }
    if (this->loaded == 0)
        this->EnsureLoaded();

    this->x = this->tableX[this->records[index].sprite];
    this->y = this->tableY[this->records[index].sprite];
    this->w = this->tableW[this->records[index].sprite];
    this->h = this->tableH[this->records[index].sprite];

    char *entry = this->anim + this->records[index].id * 0x98;

    ((Surface *)this)->BlitRLESkipToRGB(
        a, b, this->sprites[this->records[index].sprite],
        (int)(d1 + *(double *)(entry + 0x70)),
        (int)(d2 + *(double *)(entry + 0x78)));
    CS_Leave(0x5842a0);
}
