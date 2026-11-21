/* UI_RemoveListEntryAt (0x500fd0). */
extern void _memmove(void *dst, void *src, unsigned int size);

struct UI {
    void RemoveListEntryAt(int list, int index);
};

void UI::RemoveListEntryAt(int list, int index)
{
    if (index >= 0 && index < 10) {
        if (index < 9) {
            _memmove((char *)this + list * 0x168 + index * 0x10 + 0x74,
                     (char *)this + list * 0x168 + index * 0x10 + 0x84,
                     0x90 - index * 0x10);
        }
        *(int *)((char *)this + list * 0x168 + 0x110) = 0;
        *(int *)((char *)this + list * 0x168 + 0x104) = -1;
    }
}
