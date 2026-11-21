/* City_RemovePersonEntry - 0x4d6c00, 15 bytes */
struct City
{
    void RemovePersonEntry(int *person);
    void RemovePersonAndMaintainPopulation(int person);
};

void City::RemovePersonEntry(int *person)
{
    RemovePersonAndMaintainPopulation(*person);
}
