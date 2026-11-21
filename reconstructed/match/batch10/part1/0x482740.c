/* City_Register: registers a city in the game's object lists and initialises
   its buildings and population (0x482740). */
struct List {
    int Add(void *item);
};

struct Map {
    int FindIndex(void *item);
    void BuildOccupiedCellList();
};

struct City {
    char pad[0xc1c];
    int index;

    void InitBuildings();
    void InitOfferSlots();
    void InitPopulation(int first, int second);
};

struct Game {
    char pad[4];

    void Register(struct City *city, int first, int second);
};

void Game::Register(struct City *city, int first, int second)
{
    struct List *list = (struct List *)((char *)this + 4);

    list->Add(city);
    city->index = ((struct Map *)list)->FindIndex(city);
    city->InitBuildings();
    city->InitOfferSlots();
    city->InitPopulation(first, second);
    ((struct Map *)city)->BuildOccupiedCellList();
}
