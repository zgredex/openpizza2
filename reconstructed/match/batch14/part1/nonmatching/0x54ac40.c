/* UI_AdvanceChildProgress (0x54ac40): advances a child element's progress
   value and clamps it to the configured maximum. */
extern float DAT_0055c2e4;

struct UI {
    char pad[0x24];
    int field24;
    void MoveChildToPosition(int position, int limit);
};

struct Progress {
    char pad[0xc];
    int maximum;               /* 0x0c */
    char pad2[0x1c - 0x10];
    float current;             /* 0x1c */
    float rate;                /* 0x20 */
};

struct ProgressOwner {
    char pad[0x24];
    int field24;               /* 0x24 */
    void AdvanceChildProgress(void *child, unsigned int elapsed,
                              Progress *progress);
};

void ProgressOwner::AdvanceChildProgress(void *child, unsigned int elapsed,
                                         Progress *progress)
{
    int value;
    int maximum;

    if (progress->rate != DAT_0055c2e4) {
        progress->current = (float)elapsed * progress->rate * 0.001f +
                            progress->current;
        value = (int)progress->current;
        maximum = progress->maximum;
        if (value < maximum) {
            progress->rate = 0;
            progress->current = (float)maximum;
            value = maximum;
        }
        ((UI *)child)->MoveChildToPosition(
            value, *(int *)((char *)this + 0x24));
    }
}
