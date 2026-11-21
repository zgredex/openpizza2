/* BuildingInfoMenu_Init: initialises the building-info submenu page
   (0x491ea0). */
struct UI {
    void SetPosition(int position, int flags);
    void ReleaseRefCount(void *object);
    void *LoadFontByName(char *name);
};

extern UI *DAT_0057c5e0;
extern void *DAT_0057c6b0;
extern char DAT_00491990[];
extern char DAT_00563ec8[];

__cdecl void BranchStats_UpdateRatingPage(void *page);

void __cdecl BuildingInfoMenu_Init(void *page)
{
    ((struct UI *)page)->SetPosition((int)DAT_00491990, 0);
    if (DAT_0057c6b0 != 0) {
        DAT_0057c5e0->ReleaseRefCount(DAT_0057c6b0);
    }
    DAT_0057c6b0 = DAT_0057c5e0->LoadFontByName(DAT_00563ec8);
    BranchStats_UpdateRatingPage(page);
}
