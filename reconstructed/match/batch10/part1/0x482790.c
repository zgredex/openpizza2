/* Game_AddObjectToRegistry: registers a map object and activates it unless
   its type is one of the passive kinds (0x482790). */
struct List {
    int Add(void *item);
};

struct Object {
    char pad[0x30];
    int type;
    char pad2[0xcc - 0x34];
    void *activation;
    char pad3[0x164 - 0xd0];
    int registryIndex;

    void Activate(void *data);
};

struct Game {
    char pad[0x3c];

    int AddObjectToRegistry(struct Object *object);
};

int Game::AddObjectToRegistry(struct Object *object)
{
    int index = ((struct List *)((char *)this + 0x3c))->Add(object);

    object->registryIndex = index;
    switch (object->type) {
    case 0xe:
    case 0x1a:
    case 0x1b:
    case 0x1c:
    case 0x22:
    case 0x2b:
    case 0x2c:
    case 0x2d:
    case 0x2e:
    case 0x2f:
        break;
    default:
        object->Activate(object->activation);
    }
    return index;
}
