/* UI_SetChildScale: applies the percentage scale to the child list entry
   (0x509130). */
extern double DAT_0055c418;
extern double DAT_0055c678;

struct UI {
    void SetListEntryPosition(int value, double scale);
};

struct Child {
    char pad[0x58];
    UI *entry;                 /* 0x58 */
};

struct Object {
    void SetChildScale(double scale);
};

void Object::SetChildScale(double scale)
{
    Child *child = *(Child **)((char *)this + 0xc8);

    if (child != 0 && *(UI **)((char *)child + 0x58) != 0) {
        double *value = &scale;
        double scaled = *value;
        scaled = scaled * DAT_0055c418;
        *value = scaled + DAT_0055c678;
        (*(UI **)((char *)child + 0x58))->SetListEntryPosition(*(int *)child,
                                                              *value);
    }
}
