/* UI_DecrementRowCounter: decrements the row counter of a named string
   record (0x5277d0). */
struct StringList {
    int Find(char *name, int *index);
};

struct UI {
    char pad[0x82f8];
    char *records;
    void DecrementRowCounter(char *name);
};

void UI::DecrementRowCounter(char *name)
{
    if (((StringList *)this)->Find(name, (int *)&name) != 0) {
        int *counter = (int *)&records[(int)name * 0x48 + 0x44];

        *counter = *counter - 1;
    }
}
