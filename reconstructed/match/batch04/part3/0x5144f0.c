/* Storage_GetFillPercent: used capacity as a percentage of total capacity (0x5144f0). */
struct Storage {
    char pad[0x58];
    int used;
    int GetCapacity();
    int GetFillPercent();
};

int Storage::GetFillPercent()
{
    int used = this->used;
    int capacity = GetCapacity();

    return (used * 100) / capacity;
}
