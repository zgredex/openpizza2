/* IDMap_Update: translates a large record value into its array index
   (0x4018c0). */
struct IDMap {
    char pad[8];
    int *values;
    int count;
    void Update(int *value);
};

void IDMap::Update(int *value)
{
    int index;

    if (*value < 100000)
        return;
    for (index = 0; index < count; index++) {
        if (values[index] == *value)
            *value = index;
    }
}
