/* Superseded first attempt for 0x514220 (LookupTable_HasKey).
 * The bytes matched, but the helper class name LookupTable made the
 * undefined symbol ?FindPair@LookupTable@@QAEHH@Z, which --auto-symbols
 * cannot map to the shipped name Array_FindPair (0x5140b0); strict failed
 * on the unresolved relocation. Renaming the helper to Array fixes it.
 */
struct LookupTable
{
    int FindPair(int key);
    bool HasKey(int key);
};

bool LookupTable::HasKey(int key)
{
    return FindPair(key) != -1;
}
