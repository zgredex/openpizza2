/* Ingredient_Construct: builds the default ingredient descriptor
   (0x4e4770). */
struct GameHelper {
    void SetBuildingDesc(char *name, int a, int b, int c, int d, int e,
                         double ratio, int f, int g, int h, int i, int j,
                         int k);
};

struct Ingredient {
    char pad[0xa8];
    unsigned char fielda8;
    char pad2[0x27];
    int fieldd0;

    Ingredient *Construct(int id);
};

Ingredient *Ingredient::Construct(int id)
{
    *(void ***)this = (void **)0x55c5b8;
    ((GameHelper *)this)
        ->SetBuildingDesc((char *)0x570c48, 1, 1000, 250, 20, 10, 1.99,
                          0, 0, 0, 0, 0, 0);
    fielda8 = 0;
    fieldd0 = id;
    return this;
}
