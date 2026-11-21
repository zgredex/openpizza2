struct IDMap { void *Lookup(int key, int *out); };
struct Game { int GetNestedArrayEntry(int index, int sub); int GetRecordChild14(int index); };
int Game::GetNestedArrayEntry(int index, int sub)
{
    if (index < 0)
        return 0;
    if (*(int *)((char *)this + index * 0x48 + 0x68) == 0)
        return 0;
    if (sub >= GetRecordChild14(index))
        return 0;
    return (int)((IDMap *)*(void **)((char *)this + index * 0x48 + 0x68))->Lookup(sub, 0);
}
