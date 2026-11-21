/* LookupTable_HasKey - 0x514220, 23 bytes */
struct Array
{
    int FindPair(int key);
    bool HasKey(int key);
};

bool Array::HasKey(int key)
{
    return FindPair(key) != -1;
}
