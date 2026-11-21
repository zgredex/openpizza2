/* Index_Map8To5: maps an eight-entry percentage array to five display
   buckets and clamps the result to 0..100 (0x513980). */
struct Index {
    char pad[0x2c4];
    int values[8];

    int Map8To5(int index);
};

int Index::Map8To5(int index)
{
    int sum = 0;
    int i;

    if (index == 8) {
        index = 5;
    }
    if (index == -1) {
        for (i = 0; i < 8; i++) {
            sum += values[i];
        }
        sum /= 8;
    } else {
        sum = values[index];
    }
    if (sum < 0) {
        return 0;
    }
    if (sum > 100) {
        sum = 100;
    }
    return sum;
}
