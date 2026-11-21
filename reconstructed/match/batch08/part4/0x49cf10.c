/* CompanyRating_UpdateScoreText: updates the company rating score gadget
   (0x49cf10). */
extern void *DAT_0057c670;
extern int DAT_00582670;

struct IDMap {
    void *Lookup(int key, int *out);
};

extern "C" void __cdecl Gadget_SetTextf(void *gadget, int id,
                                        const char *format, int value,
                                        int extra);

void __cdecl CompanyRating_UpdateScoreText(void *gadget)
{
    void *record =
        ((IDMap *)((char *)DAT_0057c670 + 4))
            ->Lookup(*(int *)((char *)DAT_0057c670 + 0x2f4), 0);

    Gadget_SetTextf(gadget, 0x465, (const char *)0x568324,
                    *(int *)((char *)record + 0x114c), DAT_00582670);
}
