/* Game_QueueObjectTask: appends an object's task record to the list at 0x1760
   (0x47d250). */
struct List {
    void Add(void *item);
};

struct Game {
    char pad[0x1760];
    List tasks;
    void QueueObjectTask(void *object);
};

void Game::QueueObjectTask(void *object)
{
    tasks.Add(*(void **)((char *)object + 0x164));
}
