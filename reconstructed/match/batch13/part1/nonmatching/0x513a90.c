/* Company_GenerateNameFromTopProduct (0x513a90). */
extern char *DAT_0057c670;
extern void String_Format(char *buffer, char *format);
extern void Company_GenerateUniqueName(int company, void *object, char *name);

struct Company {
    char pad0[0x64];
    int products[0x56];     /* 0x64 */

    void GenerateNameFromTopProduct(int company);
};

void Company::GenerateNameFromTopProduct(int company)
{
    char name[80];
    int best = 0;
    int bestIndex = company;
    int index;

    for (index = 0; index < 0x56; index++) {
        int value = products[index];

        if (index != 0 && value > 0 && best < value) {
            best = value;
            bestIndex = index;
        }
    }
    String_Format(name,
                  (char *)(*(int *)(DAT_0057c670 + 0xa8 + bestIndex * 4) + 0x88));
    Company_GenerateUniqueName(company, this, name);
}
