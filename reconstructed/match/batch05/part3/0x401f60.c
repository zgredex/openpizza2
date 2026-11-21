/* ResourceIterator_Init: resets an iterator and advances to the first entry (0x401f60). */
struct ResourceIterator {
    void Next(char *state);
    void Init(char *state);
};

void ResourceIterator::Init(char *state)
{
    *(int *)(state + 0x114) = 0;
    *(int *)(state + 0x118) = -1;
    Next(state);
}
