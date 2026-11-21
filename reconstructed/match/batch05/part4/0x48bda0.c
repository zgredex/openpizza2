/* Game_OnObjectListSelection: resolves and selects an object-list entry (0x48bda0). */
struct IDMap {
    void *Lookup(int key, int *out);
};

struct Game {
    char pad[0x288];
    int key;
    void SelectFoundObject(void *object);
    void OnObjectListSelection();
};

void Game::OnObjectListSelection()
{
    void *object = ((IDMap *)((char *)this + 0x3c))->Lookup(key, 0);

    if (object != 0)
        SelectFoundObject(object);
}
