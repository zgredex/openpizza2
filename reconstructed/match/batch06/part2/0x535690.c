/* UI_GetFirstEnabledIndex: returns the first enabled child index (0x535690). */
struct UI {
    char pad0[0x1c0];
    unsigned char indices[0xe0];
    char pad1[0x460 - 0x2a0];
    int enabled[0xe0];
    int GetFirstEnabledIndex();
};

int UI::GetFirstEnabledIndex()
{
    int index;

    for (index = 0; index < 0xe0; index++) {
        if (enabled[index] != 0) {
            return *(unsigned char *)((char *)this + 0x1c0 + index);
        }
    }
    return 0;
}
