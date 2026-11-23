struct IDMap {
    int unused;
    void *Lookup(int index, int *out);
    void RemoveByKey(int key);
};

struct UI {
    void RemoveObject(int id);
};

struct Channel {
    char pad0[8];
    int field8;
    int fieldC;
    char pad1[4];
    int field14;
    char pad2[4];
    float field1C;
    float field20;
};

struct Sound {
    IDMap map;
    char pad0[0x18 - 0x8];
    int count;
    char pad1[0x28 - 0x1c];
    int delta;
    char pad2[0x34 - 0x2c];
    UI *ui;
    int GetChannelObject(int id, int force);
};

void __cdecl operator delete(void *);

int Sound::GetChannelObject(int id, int force)
{
    IDMap *map = (IDMap *)((char *)this + 4);
    Channel *channel = (Channel *)map->Lookup(id, 0);
    if (channel == 0)
        return 0;
    if (channel->field14 != 0 && force == 0)
        return 0;
    if (channel->field8 != -1) {
        ((UI *)*(void **)((char *)this + 0x34))->RemoveObject(channel->field8);
        int count = *(int *)((char *)this + 0x18);
        int old = channel->fieldC;
        int i = 0;
        if (0 < count) {
            do {
                Channel *other = (Channel *)map->Lookup(i, 0);
                if (other != 0 && other->fieldC > old) {
                    int value = other->fieldC - *(int *)((char *)this + 0x28);
                    other->fieldC = value;
                    other->field20 = -(other->field1C - (float)value);
                }
                i++;
            } while (i < count);
        }
    }
    ((IDMap *)((char *)this + 4))->RemoveByKey((int)channel);
    operator delete(channel);
    return 1;
}
