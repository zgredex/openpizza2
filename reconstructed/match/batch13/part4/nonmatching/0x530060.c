/* UI_HitTestExcludingChild (0x530060). */
struct UI {
    char pad00[0x18];
    int field18;
    int field1c;
    char pad20[0xcc];
    int *arrayEc;
    int countF0;

    int IsValidSize(int x, int y);
    int HitTestChild(int x, int y);
    int HitTestExcludingChild(int *point, void *exclude);
};

int UI::HitTestExcludingChild(int *point, void *exclude)
{
    if (exclude != 0) {
        int index = countF0;
        void *child;
        do {
            index = index - 1;
            if (index < 0) {
                return ((struct UI *)exclude)
                    ->HitTestChild(point[0] - field18, point[1] - field1c);
            }
            child = (void *)arrayEc[index * 2];
            if (child == exclude) {
                return ((struct UI *)exclude)
                    ->HitTestChild(point[0] - field18, point[1] - field1c);
            }
        } while (child == 0 ||
                 ((struct UI *)child)
                         ->IsValidSize(point[0] - field18, point[1] - field1c) ==
                     0);
    }
    return 0;
}
