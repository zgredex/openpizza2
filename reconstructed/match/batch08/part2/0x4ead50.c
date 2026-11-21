/* Game_HideAllLinkedElements: hides the linked elements of every record
   (0x4ead50). */
struct IDMap {
    void *Lookup(int key, int *out);
};

void __fastcall Object_HideLinkedElements(void *object);

struct Game {
    char pad[0x2c3f8];
    int count;
    void HideAllLinkedElements();
};

void Game::HideAllLinkedElements()
{
    int index = 0;

    while (index < *(int *)((char *)this + 0x2c40c)) {
        void *record =
            ((struct IDMap *)((char *)this + 0x2c3f8))->Lookup(index, 0);

        Object_HideLinkedElements(record);
        index++;
    }
}
