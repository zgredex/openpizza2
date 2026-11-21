/* Object_CanDetach (0x50abc0). */
struct Game {
    unsigned RemoveObjectFromList(void *object, int flag);
};
struct Object {
    char pad00[0x30];
    int type30;
    char pad34[0x4];
    int type38;
    char pad3c[0x38];
    int flag74;
    char pad78[0x7c];
    void *parentF4;
    char padF8[0x4];
    void *parentFC;
    char pad100[0x4];
    unsigned char flag104;
};

extern "C" int __fastcall Object_CanDetach(struct Object *object)
{
    if (object->type38 == 0x2e || object->type38 == 0x1f) {
        if (object->flag74 != 0) {
            ((struct Game *)object->parentF4)->RemoveObjectFromList(object, 0);
            return 1;
        }
        if (object->flag104 != 0) {
            if (object->parentFC != 0) {
                ((struct Game *)object->parentFC)->RemoveObjectFromList(object, 0);
            }
            return 1;
        }
    }
    if (object->type30 == 0x23 && object->flag104 != 0 && object->flag74 == 0) {
        return 1;
    }
    return 0;
}
