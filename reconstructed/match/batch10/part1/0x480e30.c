/* MapObject_RestoreSignLogoAnimations: rebinds sign/logo animations on
   building objects after a load (0x480e30). */
struct IDMap {
    void *Lookup(int index, int *out);
};

struct Object {
    void SetSignAndLogoVariant(int variant, void *animation, int player);
};

struct Game {
    char pad[4];
    char map[0x2f0];
    int selected;

    int GetPlayerBySlot(int slot);
};

extern Game *DAT_0057c670;

struct MapObject {
    char pad[0x30];
    int owner;
    char pad2[0x16f0 - 0x34];
    int *animation;

    void RestoreSignLogoAnimations();
};

void MapObject::RestoreSignLogoAnimations()
{
    int *animation = this->animation;
    int player;

    if (animation == 0 || animation[1] != 0xf) {
        return;
    }
    {
        int slot = owner;
        player = DAT_0057c670->GetPlayerBySlot(slot);
    }
    if (player != 0) {
        void *object = ((struct IDMap *)DAT_0057c670->map)->Lookup(
            DAT_0057c670->selected, 0);

        ((struct Object *)object)->SetSignAndLogoVariant(1, animation, player);
    }
}
