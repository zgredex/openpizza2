/* Ingredient_CollectByCategory: builds a list of ingredients in a category
   (0x488b30). */
struct List_Construct {
    char pad[0x1c];

    List_Construct(int param);
};

struct List {
    void Add(void *value);
};

struct Ingredient {
    char pad[0xa8];
    void *records[0x56];

    List *CollectByCategory(char category);
};

List *Ingredient::CollectByCategory(char category)
{
    List *list = (List *)new List_Construct(0);
    int i;

    for (i = 0; i < 0x56; i++) {
        void *record = records[i];

        if (*(char *)((char *)record + 0xa8) == category) {
            list->Add(record);
        }
    }
    return list;
}
