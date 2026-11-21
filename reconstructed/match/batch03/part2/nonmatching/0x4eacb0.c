/* Superseded first attempt for 0x4eacb0 (Game_RemoveIDMapEntry).
 * The bytes matched, but the helper class name IDMap made the undefined
 * symbol ?LookupLinear@IDMap@@QAEXH@Z, which --auto-symbols cannot map to
 * the shipped name Map_LookupLinear (0x401930); strict failed on the
 * unresolved relocation. Renaming the helper to Map fixes it.
 */
struct IDMap
{
    void LookupLinear(int key);
};

struct Game
{
    char pad[0x2c3f8];
    IDMap map;

    void RemoveIDMapEntry(int key);
};

void Game::RemoveIDMapEntry(int key)
{
    map.LookupLinear(key);
}
