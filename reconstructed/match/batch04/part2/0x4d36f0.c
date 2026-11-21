/* Character_StreamConstruct: installs the vtable and loads the character (0x4d36f0). */
extern void *DAT_0055c4fc[];

struct Character {
    void *vtable;
    void Load(void *stream);
    Character *ConstructFromStream(void *stream);
};

Character *Character::ConstructFromStream(void *stream)
{
    vtable = (void *)DAT_0055c4fc;
    Load(stream);
    return this;
}
